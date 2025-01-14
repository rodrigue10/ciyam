// Copyright (c) 2014-2022 CIYAM Developers
//
// Distributed under the MIT/X11 software license, please refer to the file license.txt
// in the root project directory or http://www.opensource.org/licenses/mit-license.php.

#ifdef PRECOMPILE_H
#  include "precompile.h"
#endif
#pragma hdrstop

#ifndef HAS_PRECOMPILED_STD_HEADERS
#  include <cstring>
#  include <csignal>
#  include <cstdlib>
#  include <deque>
#  include <memory>
#  include <sstream>
#  include <iostream>
#  include <algorithm>
#  include <stdexcept>
#endif

#define CIYAM_BASE_IMPL

#include "peer_session.h"

#include "base64.h"
#include "config.h"
#include "sha256.h"
#include "threads.h"
#include "utilities.h"
#include "date_time.h"
#include "ciyam_base.h"
#include "ciyam_files.h"
#ifdef SSL_SUPPORT
#  include "crypto_keys.h"
#endif
#include "crypt_stream.h"
#include "ciyam_session.h"
#include "ciyam_strings.h"
#include "command_parser.h"
#include "ciyam_constants.h"
#include "ciyam_variables.h"
#include "command_handler.h"
#include "ciyam_core_files.h"
#include "command_processor.h"

//#define USE_THROTTLING
//#define DEBUG_PEER_HANDSHAKE

using namespace std;

extern size_t g_active_sessions;
extern size_t g_active_listeners;

extern volatile sig_atomic_t g_server_shutdown;

namespace
{

#include "ciyam_constants.h"

#include "peer_session.cmh"

#include "trace_progress.cpp"

mutex g_mutex;

const char c_blob_separator = '&';

const char c_reprocess_prefix = '*';
const char c_repository_suffix = '!';

const char* const c_hello = "hello";
const char* const c_bc_prefix = "bc.";
const char* const c_blk_suffix = ".blk";
const char* const c_dat_suffix = ".dat";
const char* const c_key_suffix = ".key";
const char* const c_pub_suffix = ".pub";
const char* const c_sig_suffix = ".sig";
const char* const c_zenith_suffix = ".zenith";
const char* const c_supporters_suffix = ".supporters";

const char* const c_dummy_peer_tag = "peer";
const char* const c_dummy_support_tag = "support";

const int c_accept_timeout = 250;
const int c_max_line_length = 500;

const int c_max_num_for_support = 10;
const int c_min_block_wait_passes = 8;

const size_t c_max_greeting_size = 256;
const size_t c_max_put_blob_size = 256;

const size_t c_peer_sleep_time = 5000;

const size_t c_initial_timeout = 60000;
const size_t c_request_timeout = 20000;
const size_t c_support_timeout = 60000;

const size_t c_main_session_sleep_time = 200;
const size_t c_support_session_sleep_time = 100;
const size_t c_support_session_sleep_repeats = 10;

#ifdef USE_THROTTLING
const size_t c_request_throttle_sleep_time = 250;
#endif

enum op
{
   e_op_chk,
   e_op_pip,
   e_op_init
};

enum peer_state
{
   e_peer_state_invalid,
   e_peer_state_initiator,
   e_peer_state_responder,
   e_peer_state_waiting_for_get,
   e_peer_state_waiting_for_put,
   e_peer_state_waiting_for_get_or_put
};

enum peer_trust_level
{
   e_peer_trust_level_none,
   e_peer_trust_level_normal
};

set< string > g_blockchain_release;

map< string, set< string > > g_blockchain_passwords;

set< string > g_good_peers;
map< string, deque< string > > g_peers_to_retry;

size_t g_num_peers = 0;

bool has_max_peers( )
{
   guard g( g_mutex );

   return g_num_peers >= get_max_peers( );
}

inline void issue_error( const string& message, bool possibly_expected = false )
{
   TRACE_LOG( ( possibly_expected ? TRACE_SESSIONS : TRACE_ANYTHING ), string( "peer session error: " ) + message );
}

inline void issue_warning( const string& message )
{
   TRACE_LOG( TRACE_SESSIONS, string( "peer session warning: " ) + message );
}

void increment_active_listeners( )
{
   guard g( g_mutex );
   ++g_active_listeners;
}

void decrement_active_listeners( )
{
   guard g( g_mutex );
   --g_active_listeners;
}

string get_hello_data( string& hello_hash )
{
   string data( c_file_type_str_blob );
   data += string( c_hello );

   hello_hash = sha256( data ).get_digest_as_string( );

   return data;
}

void add_good_peer( const string& ip_addr, const string& blockchain )
{
   guard g( g_mutex );

   g_good_peers.insert( ip_addr + '=' + blockchain );
}

bool was_good_peer( const string& ip_addr, const string& blockchain )
{
   guard g( g_mutex );

   return g_good_peers.count( ip_addr + '=' + blockchain );
}

void add_peer_to_retry( const string& ip_addr, const string& blockchain )
{
   guard g( g_mutex );

   g_peers_to_retry[ blockchain ].push_back( ip_addr );
}

string get_peer_to_retry( const string& blockchain )
{
   guard g( g_mutex );

   string retval;

   while( !g_peers_to_retry[ blockchain ].empty( ) )
   {
      retval = g_peers_to_retry[ blockchain ].front( );
      g_peers_to_retry[ blockchain ].pop_front( );

      if( get_is_accepted_peer_ip_addr( retval.substr( 0, retval.find( '!' ) ) ) )
         break;
      else
         retval.erase( );
   }

   return retval;
}

bool was_released( const string& blockchain )
{
   guard g( get_core_files_trace_mutex( ) );

   bool retval = false;

   if( g_blockchain_release.count( blockchain ) )
   {
      retval = true;
      g_blockchain_release.erase( blockchain );
   }

   return retval;
}

string process_txs( const string& blockchain, const string& tx_hash )
{
   string hash;

   system_variable_lock blockchain_lock( blockchain );

   if( !tx_hash.empty( ) || file_exists( blockchain + ".txs" ) )
   {
      vector< string > applications;
      uint64_t block_height = construct_transaction_scripts_for_blockchain( blockchain, tx_hash, applications );

      if( !tx_hash.empty( ) )
         set_session_variable( get_special_var_name( e_special_var_rewind_height ), "" );

      set_session_variable( get_special_var_name( e_special_var_block_height ), to_string( block_height ) );

      for( size_t i = 0; i < applications.size( ); i++ )
      {
         string application( applications[ i ] );

         if( file_exists( application + ".log" ) )
         {
            set_session_variable( get_special_var_name( e_special_var_application ), application );
            run_script( "app_blk_txs", false );
         }

         file_remove( applications[ i ] + ".txs.cin" );
      }
   }

   hash = construct_blockchain_info_file( blockchain );

   return hash;
}

string mint_new_block( const string& blockchain,
 new_block_info& new_block, string& password_hash, bool is_for_store )
{
   guard g( get_core_files_trace_mutex( ), "mint_new_block" );

   string data;

   set< string >& passwords( g_blockchain_passwords[ blockchain ] );

   if( !passwords.empty( ) )
   {
      string next_data;
      new_block_info next_block;

      bool is_reminting = !password_hash.empty( );

      for( set< string >::iterator i = passwords.begin( ); i != passwords.end( ); ++i )
      {
         string next_password( *i );

         if( is_reminting && sha256( next_password ).get_digest_as_string( ) != password_hash )
            continue;

         next_data = construct_new_block( blockchain, next_password, &next_block, is_for_store );

         // NOTE: If no valid "nonce" was found then don't proceed.
         if( next_block.num_txs < 0 )
            break;

         if( i == passwords.begin( ) || is_reminting || next_block.weight < new_block.weight )
         {
            data = next_data;
            new_block = next_block;

            if( is_reminting )
               break;

            password_hash = sha256( next_password ).get_digest_as_string( );
         }
      }
   }

   return data;
}

string store_new_block( const string& blockchain, const string& password_hash )
{
   guard g( g_mutex );

   if( password_hash.empty( ) )
      return string( );

   string hash( password_hash );

   // NOTE: Before storing now re-mint the block just in case further txs can be added to it.
   new_block_info new_block;
   string data( mint_new_block( blockchain, new_block, hash, true ) );

   if( data.empty( ) )
      return string( );

   vector< pair< string, string > > extras;

   temporary_session_variable tmp_session_locally_minted_block(
    get_special_var_name( e_special_var_locally_minted_block ), "1" );

   verify_core_file( data, true, &extras );
   create_raw_file_with_extras( "", extras );

   return process_txs( blockchain, "" );
}

void process_core_file( const string& hash, const string& blockchain )
{
   guard g( g_mutex );

   TRACE_LOG( TRACE_PEER_OPS, "(process_core_file) hash: " + hash );

   string::size_type pos = hash.find( ':' );

   string file_info( file_type_info( hash.substr( 0, pos ) ) );

   vector< string > info_parts;
   split( file_info, info_parts, ' ' );

   string last_blockchain_info(
    get_raw_session_variable( get_special_var_name( e_special_var_blockchain_info_hash ) ) );

   // NOTE: A core file will return three parts in the form of: <type> <hash> <core_type>
   // (as non-core files don't have a "core type" only two parts will be found for them).
   // If the hash is the same as the "blockchain info" file that was previously processed
   // then just delete the file and if the file has any tags then it is assumed that this
   // file was already processed by another peer session.
   if( hash.substr( 0, pos ) == last_blockchain_info )
      delete_file( hash.substr( 0, pos ), false );
   else if( info_parts.size( ) == 3 && get_hash_tags( hash.substr( 0, pos ) ).empty( ) )
   {
      string core_type( info_parts[ 2 ] );

      if( is_block( core_type ) )
      {
         try
         {
            vector< pair< string, string > > extras;

            string block_content;

            if( pos != string::npos )
            {
               block_content = construct_blob_for_block_content(
                extract_file( hash.substr( 0, pos ), "" ), hash.substr( pos + 1 ) );

               verify_core_file( block_content, true, &extras );
            }
            else
            {
               block_content = construct_blob_for_block_content( extract_file( hash, "" ) );

               verify_core_file( block_content, false, &extras );
            }

            if( !extras.empty( ) )
               create_raw_file_with_extras( "", extras );

            string block_height( get_session_variable(
             get_special_var_name( e_special_var_blockchain_height ) ) );

            string primary_pubkey_hash( get_session_variable(
             get_special_var_name( e_special_var_blockchain_primary_pubkey_hash ) ) );

            if( !primary_pubkey_hash.empty( ) )
            {
               if( block_height == "0"
                && primary_pubkey_hash.find( blockchain.substr( strlen( c_bc_prefix ) ) ) != 0 )
                  throw runtime_error( "invalid genesis primary public key hash '"
                   + primary_pubkey_hash + "' for blockchain '" + blockchain + "'" );

               if( !has_file( primary_pubkey_hash ) )
                  add_peer_file_hash_for_get( primary_pubkey_hash );

               string file_tag( blockchain + '.' + block_height + c_blk_suffix );

               tag_file( file_tag, hash );
            }

            set_session_variable(
             get_special_var_name( e_special_var_blockchain_height ), "" );

            string secondary_pubkey_hash( get_session_variable(
             get_special_var_name( e_special_var_blockchain_secondary_pubkey_hash ) ) );

            if( !secondary_pubkey_hash.empty( ) && !has_file( secondary_pubkey_hash ) )
               add_peer_file_hash_for_get( secondary_pubkey_hash );

            string signature_file_hash( get_session_variable(
             get_special_var_name( e_special_var_blockchain_signature_file_hash ) ) );

            if( !signature_file_hash.empty( ) && !has_file( signature_file_hash ) )
               add_peer_file_hash_for_get( signature_file_hash );

            if( primary_pubkey_hash.empty( ) )
               process_txs( blockchain, "" );
         }
         catch( ... )
         {
            delete_file( hash.substr( 0, pos ), false );
            throw;
         }
      }
      else if( is_transaction( core_type ) )
      {
         if( pos != string::npos )
         {
            try
            {
               vector< pair< string, string > > extras;

               string transaction_content( construct_blob_for_transaction_content(
                extract_file( hash.substr( 0, pos ), "" ), hash.substr( pos + 1 ) ) );

               verify_core_file( transaction_content, true, &extras );

               create_raw_file_with_extras( "", extras );

               if( !has_any_session_variable(
                get_special_var_name( e_special_var_peer_is_synchronising ), blockchain ) )
                  process_txs( blockchain, hash.substr( 0, pos ) );
            }
            catch( ... )
            {
               delete_file( hash.substr( 0, pos ), false );
               throw;
            }
         }
      }
      else if( is_checkpoint_info( core_type ) )
      {
         try
         {
            string content( extract_file( hash.substr( 0, pos ), "" ) );

            checkpoint_info cp_info;
            get_checkpoint_info( blockchain, content, cp_info );

            if( !has_file( cp_info.checkpoint_hash ) )
            {
               // NOTE: Fetch any blobs that have not already been stored locally.
               for( size_t i = 0; i < cp_info.blob_hashes_with_sigs.size( ); i++ )
               {
                  string hash_with_sig( cp_info.blob_hashes_with_sigs[ i ] );

                  string::size_type pos = hash_with_sig.find( ':' );

                  if( !has_file( hash_with_sig.substr( 0, pos ) ) )
                     add_peer_file_hash_for_get( hash_with_sig );
               }

               // NOTE: Because the checkpoint won't be created locally until blocks
               // after its height have been processed the checkpoint itself must be
               // stored to avoid the peer simply getting stuck at the height of the
               // checkpoint.
               add_peer_file_hash_for_get( cp_info.checkpoint_hash );
            }

            delete_file( hash.substr( 0, pos ), false );
         }
         catch( ... )
         {
            delete_file( hash.substr( 0, pos ), false );
            throw;
         }
      }
      else if( is_blockchain_info( core_type ) )
      {
         try
         {
            string content( extract_file( hash.substr( 0, pos ), "" ) );

            blockchain_info bc_info;
            get_blockchain_info( content, bc_info );

            bool needs_checkpoint = false;

            for( size_t i = 0; i < bc_info.checkpoint_info.size( ); i++ )
            {
               string next_info( bc_info.checkpoint_info[ i ] );

               string::size_type pos = next_info.find( '.' );
               if( pos == string::npos )
                  throw runtime_error( "invalid checkpoint information: " + next_info );

               if( !has_file( next_info.substr( 0, pos ) ) )
               {
                  add_peer_file_hash_for_get( next_info.substr( pos + 1 ) );
                  needs_checkpoint = true;
                  break;
               }
            }

            if( needs_checkpoint )
               set_session_variable(
                get_special_var_name( e_special_var_peer_is_synchronising ), blockchain );
            else
            {
               string blockchain_head_hash( get_session_variable(
                get_special_var_name( e_special_var_blockchain_head_hash ) ) );

               if( !blockchain_head_hash.empty( ) && !has_file( blockchain_head_hash ) )
                  set_session_variable(
                   get_special_var_name( e_special_var_peer_is_synchronising ), blockchain );
               else
               {
                  set_session_variable(
                   get_special_var_name( e_special_var_blockchain_head_hash ), "" );

                  set_session_variable(
                   get_special_var_name( e_special_var_peer_is_synchronising ), "" );
               }

               set_session_variable(
                get_special_var_name( e_special_var_blockchain_info_hash ), hash.substr( 0, pos ) );

               // NOTE: Fetch any blobs that have not already been stored locally.
               for( size_t i = 0; i < bc_info.blob_hashes_with_sigs.size( ); i++ )
               {
                  string hash_with_sig( bc_info.blob_hashes_with_sigs[ i ] );

                  string::size_type pos = hash_with_sig.find( ':' );

                  if( !has_file( hash_with_sig.substr( 0, pos ) ) )
                     add_peer_file_hash_for_get( hash_with_sig );
               }
            }

            delete_file( hash.substr( 0, pos ), false );
         }
         catch( ... )
         {
            delete_file( hash.substr( 0, pos ), false );
            throw;
         }
      }
      else
      {
         delete_file( hash.substr( 0, pos ), false );
         throw runtime_error( "unexpected core file type '" + core_type + "' found in process_core_file" );
      }
   }
}

#ifdef SSL_SUPPORT
void process_repository_file( const string& blockchain, const string& hash_info, bool is_test_session )
{
   guard g( g_mutex );

   TRACE_LOG( TRACE_PEER_OPS, "(process_repository_file) hash_info: " + hash_info );

   string::size_type pos = hash_info.find( ':' );

   if( pos == string::npos )
      throw runtime_error( "unexpected missing public key for process_repository_file with: " + hash_info );

   string src_hash( hash_info.substr( 0, pos ) );
   string extra_info( hash_info.substr( pos + 1 ) );

   unsigned char type_and_extra = '\0';

   string file_data( extract_file( src_hash, "", 0, 0, &type_and_extra, 0, true ) );

   pos = extra_info.find( ';' );

   if( pos != string::npos )
   {
      string hex_master;

      string hex_pub_key( extra_info.substr( 0, pos ) );
      string target_hash( extra_info.substr( pos + 1 ) );

      set_session_variable( target_hash, "" );

      pos = hex_pub_key.find( '-' );

      if( pos != string::npos )
      {
         hex_master = hex_pub_key.substr( pos + 1 );
         hex_pub_key.erase( pos );
      }

      // NOTE: If this file is the result of a repository pull request
      // then when testing tag it with both the target hash and public
      // key (in hex) so it can be then detected by a standard session
      // to be decrypted. If not testing then if is not the owner will
      // store the repository entry otherwise will decrypt the initial
      // file content.
      if( is_test_session )
      {
         tag_file( '~' + hex_pub_key, src_hash );
         tag_file( '@' + target_hash, src_hash );
      }
      else
      {
         string dummy;

         bool is_blockchain_owner = !get_session_variable(
          get_special_var_name( e_special_var_blockchain_is_owner ) ).empty( );

         if( !is_blockchain_owner )
         {
            if( !fetch_repository_entry_record( target_hash, dummy, dummy, dummy, false ) )
               store_repository_entry_record( target_hash, src_hash, hex_pub_key, hex_master );
         }
         else
         {
            string password;
            get_identity( password, true, false, true );

            decrypt_pulled_peer_file( target_hash, src_hash, password, hex_pub_key );

            string repo_hash( create_peer_repository_entry_push_info( target_hash, password ) );

            clear_key( password );

            if( !fetch_repository_entry_record( target_hash, dummy, dummy, dummy, false ) )
               store_repository_entry_record( target_hash, "", hex_master, hex_master );

            delete_file( src_hash );
            delete_file( repo_hash );
         }
      }
   }
   else
   {
      string dummy;

      if( fetch_repository_entry_record( src_hash, dummy, dummy, dummy, false ) )
         delete_file( src_hash );
      else
      {
         public_key pub_key( extra_info );

         auto_ptr< private_key > ap_priv_key;

         if( !is_test_session )
         {
            string password;
            get_identity( password, true, false, true );

            // NOTE: The first nibble is zeroed out to ensure that the hash value is always valid to use
            // as a Bitcoin address "secret" (as the range of its EC is smaller than the full 256 bits).
            ap_priv_key.reset( new private_key( "0"
             + sha256( src_hash + password ).get_digest_as_string( ).substr( 1 ) ) );

            clear_key( password );
         }
         else
            ap_priv_key.reset( new private_key( sha256( c_dummy ).get_digest_as_string( ) ) );

         stringstream ss( file_data );
         crypt_stream( ss, ap_priv_key->construct_shared( pub_key ) );

         file_data = ( char )type_and_extra + ss.str( );

         delete_file( src_hash );

         string local_hash( create_raw_file( file_data ) );

         store_repository_entry_record( src_hash, local_hash, ap_priv_key->get_public( ), pub_key.get_public( ) );
      }
   }
}

string get_file_hash_from_put_data( const string& encoded_master,
 const string& encoded_pubkey, const string& encoded_source_hash, const string& encoded_target_hash )
{
   string retval;

   try
   {
      if( !encoded_master.empty( ) )
         base64::validate( encoded_master );

      base64::validate( encoded_pubkey );
      base64::validate( encoded_source_hash );

      // NOTE: Construct a public key object for the purpose of validation.
      public_key pubkey( encoded_pubkey, true );

      string extra( hex_encode( base64::decode( encoded_pubkey ) ) );

      if( !encoded_master.empty( ) )
      {
         public_key pubkey( encoded_master, true );
         extra += '-' + hex_encode( base64::decode( encoded_master ) );
      }

      if( !encoded_target_hash.empty( ) )
      {
         base64::validate( encoded_target_hash );
         extra += ';' + hex_encode( base64::decode( encoded_target_hash ) );
      }

      retval = hex_encode( base64::decode( encoded_source_hash ) ) + ':' + extra + c_repository_suffix;
   }
   catch( ... )
   {
      // FUTURE: Perhaps add a trace here so specific errors aren't being completely ignored.
   }

   return retval;
}
#endif

void process_put_file( const string& blockchain, const string& file_data, bool is_test_session )
{
   vector< string > blobs;
   split( file_data, blobs, c_blob_separator );

   for( size_t i = 0; i < blobs.size( ); i++ )
   {
      string next_blob( blobs[ i ] );

      vector< string > lines;
      split( next_blob, lines, '\n' );

      bool okay = false;

      if( lines.size( ) >= 3 )
      {
         string::size_type pos = lines[ 0 ].find( c_file_repository_meta_data_line_prefix );

         if( pos == 0 )
         {
            string meta_data_info(
             lines[ 0 ].substr( strlen( c_file_repository_meta_data_line_prefix ) ) );

            if( meta_data_info == c_file_repository_meta_data_info_type_raw )
            {
               if( lines[ 1 ].find( c_file_repository_public_key_line_prefix ) == 0 )
               {
                  string master_key;

                  string public_key(
                   lines[ 1 ].substr( strlen( c_file_repository_public_key_line_prefix ) ) );

                  pos = public_key.find( '-' );

                  if( pos != string::npos )
                  {
                     master_key = public_key.substr( pos + 1 );
                     public_key.erase( pos );
                  }

                  if( lines[ 2 ].find( c_file_repository_source_hash_line_prefix ) == 0 )
                  {
                     string source_hash(
                      lines[ 2 ].substr( strlen( c_file_repository_source_hash_line_prefix ) ) );

                     string target_hash;

                     if( lines.size( ) > 3 && lines[ 3 ].find( c_file_repository_target_hash_line_prefix ) == 0 )
                        target_hash = lines[ 3 ].substr( strlen( c_file_repository_target_hash_line_prefix ) );

#ifndef SSL_SUPPORT
                     okay = true;
#else
                     string hash_info( get_file_hash_from_put_data( master_key, public_key, source_hash, target_hash ) );

                     if( !hash_info.empty( ) )
                     {
                        okay = true;
                        pos = hash_info.find( ':' );

                        if( !has_file( hash_info.substr( 0, pos ) ) )
                        {
                           add_peer_file_hash_for_get( hash_info );

                           if( !target_hash.empty( ) )
                           {
                              target_hash = hex_encode( base64::decode( target_hash ) );
                              set_session_variable( target_hash, hash_info.substr( 0, pos ) );
                           }
                        }
                        else
                           process_repository_file( blockchain,
                            hash_info.substr( 0, hash_info.length( ) - 1 ), is_test_session );
                     }
#endif
                  }
               }
            }
         }

         if( !okay )
            throw runtime_error( "invalid file content for put" );
      }
   }
}

void process_list_items( const string& hash, bool recurse, bool check_for_supporters )
{
   string all_list_items( extract_file( hash, "" ) );

   vector< string > list_items;
   split( all_list_items, list_items, '\n' );

   string file_data( c_file_type_str_blob );

   size_t max_blob_file_data = get_files_area_item_max_size( ) - c_max_put_blob_size;

   for( size_t i = 0; i < list_items.size( ); i++ )
   {
      if( file_data.size( ) >= max_blob_file_data )
      {
         string file_hash( create_raw_file( file_data ) );

         set_session_variable( file_hash, c_true );
         add_peer_file_hash_for_put( file_hash, check_for_supporters );

         file_data = string( c_file_type_str_blob );
      }

      string next_item( list_items[ i ] );

      if( !next_item.empty( ) )
      {
         string next_hash( next_item.substr( 0, next_item.find( ' ' ) ) );

         string local_hash, local_public_key, master_public_key;

         if( !has_file( next_hash ) )
         {
            if( !fetch_repository_entry_record( next_hash,
             local_hash, local_public_key, master_public_key, false ) )
               add_peer_file_hash_for_get( next_hash, check_for_supporters );
            else if( local_public_key != master_public_key )
            {
               if( get_session_variable( get_special_var_name( e_special_var_blockchain_is_fetching ) ).empty( )
                && get_session_variable( get_special_var_name( e_special_var_blockchain_both_are_owners ) ).empty( ) )
               {
                  if( file_data.size( ) > 1 )
                     file_data += c_blob_separator;

                  file_data += create_peer_repository_entry_pull_info(
                   next_hash, local_hash, local_public_key, master_public_key, false );
               }
            }
         }
         else if( recurse && is_list_file( next_hash ) )
            process_list_items( next_hash, recurse, check_for_supporters );
         else if( recurse )
         {
            bool has_repository_entry = false;
            bool put_info_and_store_repository_entry = false;

            if( fetch_repository_entry_record( next_hash,
             local_hash, local_public_key, master_public_key, false ) )
            {
               has_repository_entry = true;

               if( local_public_key == master_public_key )
                  put_info_and_store_repository_entry = true;
            }
            else if( !get_session_variable( get_special_var_name( e_special_var_blockchain_is_owner ) ).empty( ) )
               put_info_and_store_repository_entry = true;

            if( put_info_and_store_repository_entry )
            {
               if( get_session_variable( get_special_var_name( e_special_var_blockchain_is_fetching ) ).empty( )
                && get_session_variable( get_special_var_name( e_special_var_blockchain_both_are_owners ) ).empty( ) )
               {
                  if( local_hash.empty( ) || !has_file( local_hash ) )
                  {
                     string password;
                     get_identity( password, true, false, true );

                     if( file_data.size( ) > 1 )
                        file_data += c_blob_separator;

                     if( local_hash.empty( ) )
                        create_peer_repository_entry_push_info( next_hash, password );

                     file_data += create_peer_repository_entry_push_info( next_hash, password, &master_public_key, false );

                     clear_key( password );
                  }

                  if( !has_repository_entry )
                     store_repository_entry_record( next_hash, local_hash, master_public_key, master_public_key );
               }
            }
         }
      }
   }

   if( file_data.size( ) > 1 )
   {
      string file_hash( create_raw_file( file_data ) );

      set_session_variable( file_hash, c_true );
      add_peer_file_hash_for_put( file_hash, check_for_supporters );
   }
}

void process_data_file( const string& blockchain, const string& hash, size_t height )
{
   guard g( g_mutex );

   TRACE_LOG( TRACE_PEER_OPS, "(process_data_file) hash: " + hash + " height: " + to_string( height ) );

   try
   {
      string block_tag( blockchain + '.' + to_string( height ) + c_blk_suffix );

      string block_hash( tag_file_hash( block_tag ) );

      string block_content(
       construct_blob_for_block_content( extract_file( block_hash, "" ) ) );

      verify_core_file( block_content, false );

      string data_tag( blockchain + '.' );

      data_tag += to_string( height );

      data_tag += c_dat_suffix;

      tag_file( data_tag, hash );

      bool tag_new_zenith = false;
      bool wait_to_tag_zenith = false;

      bool is_blockchain_owner = !get_session_variable(
       get_special_var_name( e_special_var_blockchain_is_owner ) ).empty( );

      string tree_root_hash( get_session_variable(
       get_special_var_name( e_special_var_blockchain_tree_root_hash ) ) );

      string blockchain_height_processed( get_session_variable(
       get_special_var_name( e_special_var_blockchain_height_processed ) ) );

      if( blockchain_height_processed.empty( )
       || from_string< size_t >( blockchain_height_processed ) < height )
      {
         if( !tree_root_hash.empty( ) )
         {
            if( !has_file( tree_root_hash ) )
            {
               wait_to_tag_zenith = true;
               add_peer_file_hash_for_get( tree_root_hash );
            }
            else
            {
               if( is_blockchain_owner )
                  tag_file( c_ciyam_tag, tree_root_hash );

               bool check_for_supporters = false;

               if( !get_system_variable( blockchain + c_supporters_suffix ).empty( ) )
                  check_for_supporters = true;

               process_list_items( tree_root_hash, true, check_for_supporters );

               if( top_next_peer_file_hash_to_get( ).empty( ) )
                  tag_new_zenith = true;
               else
                  wait_to_tag_zenith = true;

               set_session_variable(
                get_special_var_name( e_special_var_blockchain_tree_root_hash ), "" );
            }
         }
         else
            tag_new_zenith = true;

         if( tag_new_zenith )
         {
            string zenith_height( get_session_variable(
             get_special_var_name( e_special_var_blockchain_zenith_height ) ) );

            if( zenith_height.empty( )
             || ( height > from_string< size_t >( zenith_height ) ) )
            {
               tag_file( blockchain + c_zenith_suffix, block_hash );

               TRACE_LOG( TRACE_PEER_OPS, "--- new zenith hash: "
                + block_hash + " height: " + to_string( height ) );

               set_session_variable(
                get_special_var_name( e_special_var_blockchain_zenith_height ), to_string( height ) );
            }
         }
         else if( wait_to_tag_zenith )
            set_session_variable(
             get_special_var_name( e_special_var_blockchain_zenith_hash ), block_hash );

         set_session_variable(
          get_special_var_name( e_special_var_blockchain_height_processed ), to_string( height ) );
      }

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_height ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_data_file_hash ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_primary_pubkey_hash ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_signature_file_hash ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_secondary_pubkey_hash ), "" );
   }
   catch( ... )
   {
      delete_file( hash );
      throw;
   }
}

void process_signature_file( const string& blockchain, const string& hash, size_t height )
{
   guard g( g_mutex );

   TRACE_LOG( TRACE_PEER_OPS, "(process_signature_file) hash: " + hash + " height: " + to_string( height ) );

   if( !height )
      throw runtime_error( "invalid zero height for process_signature_file" );

   try
   {
      string block_tag( blockchain + '.' + to_string( height ) + c_blk_suffix );

      string block_content(
       construct_blob_for_block_content( extract_file( tag_file_hash( block_tag ), "" ) ) );

      verify_core_file( block_content, true );

      string block_height( get_session_variable(
       get_special_var_name( e_special_var_blockchain_height ) ) );

      if( !block_height.empty( ) && ( block_height != to_string( height ) ) )
         throw runtime_error( "specified height does not match that found in the block itself (sig)" );

      string signature_tag( blockchain + '.' );

      signature_tag += to_string( height - 1 );

      signature_tag += c_sig_suffix;

      tag_file( signature_tag, hash );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_height ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_primary_pubkey_hash ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_signature_file_hash ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_secondary_pubkey_hash ), "" );
   }
   catch( ... )
   {
      delete_file( hash );
      throw;
   }
}

void process_public_key_file( const string& blockchain, const string& hash, size_t height, bool is_primary = true )
{
   guard g( g_mutex );

   string pubkey_tag( blockchain );

   if( is_primary )
      pubkey_tag += ".p";
   else
      pubkey_tag += ".s";

   pubkey_tag += to_string( height );

   pubkey_tag += c_pub_suffix;

   tag_file( pubkey_tag, hash );

   if( !height && !is_primary )
   {
      string block_hash( tag_file_hash(
       blockchain + '.' + to_string( height ) + c_blk_suffix ) );

      tag_file( blockchain + c_zenith_suffix, block_hash );

      TRACE_LOG( TRACE_PEER_OPS, "::: new zenith hash: "
       + block_hash + " height: " + to_string( height ) );
   }

   if( is_primary )
      set_session_variable(
       get_special_var_name( e_special_var_blockchain_primary_pubkey_hash ), "" );
   else
      set_session_variable(
       get_special_var_name( e_special_var_blockchain_secondary_pubkey_hash ), "" );
}

bool process_block_for_height( const string& blockchain, const string& hash, size_t height )
{
   bool retval = false;

   TRACE_LOG( TRACE_PEER_OPS, "(process_block_for_height) hash: " + hash + " height: " + to_string( height ) );

   string block_content(
    construct_blob_for_block_content( extract_file( hash, "" ) ) );

   verify_core_file( block_content, false );

   string block_height( get_session_variable(
    get_special_var_name( e_special_var_blockchain_height ) ) );

   if( !block_height.empty( ) && ( block_height != to_string( height ) ) )
      throw runtime_error( "specified height does not match that found in the block itself (blk)" );
   else
   {
      string primary_pubkey_hash( get_session_variable(
       get_special_var_name( e_special_var_blockchain_primary_pubkey_hash ) ) );

      if( !primary_pubkey_hash.empty( ) )
      {
         if( !height
          && primary_pubkey_hash.find( blockchain.substr( strlen( c_bc_prefix ) ) ) != 0 )
            throw runtime_error( "invalid primary public key hash '"
             + primary_pubkey_hash + "' for blockchain '" + blockchain + "'" );

         if( !has_file( primary_pubkey_hash ) )
            add_peer_file_hash_for_get( primary_pubkey_hash );
         else
            process_public_key_file( blockchain, primary_pubkey_hash, height );
      }

      string secondary_pubkey_hash( get_session_variable(
       get_special_var_name( e_special_var_blockchain_secondary_pubkey_hash ) ) );

      if( !secondary_pubkey_hash.empty( ) )
      {
         if( !has_file( secondary_pubkey_hash ) )
            add_peer_file_hash_for_get( secondary_pubkey_hash );
         else
            process_public_key_file( blockchain, secondary_pubkey_hash, height, false );
      }

      string signature_file_hash( get_session_variable(
       get_special_var_name( e_special_var_blockchain_signature_file_hash ) ) );

      if( !signature_file_hash.empty( ) )
      {
         if( !has_file( signature_file_hash ) )
            add_peer_file_hash_for_get( signature_file_hash );
         else
            process_signature_file( blockchain, signature_file_hash, height );
      }

      string data_file_hash( get_session_variable(
       get_special_var_name( e_special_var_blockchain_data_file_hash ) ) );

      if( !data_file_hash.empty( ) )
      {
         if( !has_file( data_file_hash ) )
            add_peer_file_hash_for_get( data_file_hash );
         else
         {
            retval = true;
            process_data_file( blockchain, data_file_hash, height );
         }
      }
   }

   return retval;
}

bool get_block_height_from_tags( const string& blockchain, const string& hash, size_t& block_height )
{
   guard g( g_mutex );

   string all_tags( get_hash_tags( hash ) );

   vector< string > tags;

   if( !all_tags.empty( ) )
      split( all_tags, tags, '\n' );

   bool found = false;

   for( size_t i = 0; i < tags.size( ); i++ )
   {
      string next_tag( tags[ i ] );

      string::size_type pos = next_tag.find( blockchain );
      string::size_type spos = next_tag.find( c_blk_suffix );

      // NOTE: Determine the block height from its block tag.
      if( pos == 0 && spos != string::npos )
      {
         found = true;

         next_tag.erase( spos );

         block_height = from_string< size_t >( next_tag.substr( blockchain.length( ) + 1 ) );

         break;
      }
   }

   return found;
}

class socket_command_handler : public command_handler
{
   public:
#ifdef SSL_SUPPORT
   socket_command_handler( ssl_socket& socket, peer_state session_state,
    bool is_local, bool is_owner, const string& blockchain, bool is_for_support = false )
#else
   socket_command_handler( tcp_socket& socket, peer_state session_state,
    bool is_local, bool is_owner, const string& blockchain, bool is_for_support = false )
#endif
    :
    socket( socket ),
    is_local( is_local ),
    is_owner( is_owner ),
    blockchain( blockchain ),
    blockchain_height( 0 ),
    blockchain_height_pending( 0 ),
    is_for_support( is_for_support ),
    session_state( session_state ),
    session_op_state( session_state ),
    session_trust_level( e_peer_trust_level_none )
   {
      had_usage = false;

      needs_blockchain_info = ( !blockchain.empty( ) && ( blockchain.find( c_bc_prefix ) != 0 ) );

      is_responder = ( session_state == e_peer_state_responder );

      if( get_is_test_session( ) )
         want_to_do_op( e_op_init );

      last_issued_was_put = !is_responder;
   }

   ~socket_command_handler( )
   {
      if( !blockchain_info.second.empty( ) )
         file_remove( blockchain_info.second );
   }

#ifdef SSL_SUPPORT
   ssl_socket& get_socket( ) { return socket; }
#else
   tcp_socket& get_socket( ) { return socket; }
#endif

   const string& get_last_command( ) { return last_command; }
   const string& get_next_command( ) { return next_command; }

   bool get_is_local( ) const { return is_local; }
   bool get_is_owner( ) const { return is_owner; }

   bool get_is_responder( ) const { return is_responder; }
   bool get_is_for_support( ) const { return is_for_support; }

   bool get_last_issued_was_put( ) const { return last_issued_was_put; }
   void set_last_issued_was_put( bool val ) { last_issued_was_put = val; }

   bool get_needs_blockchain_info( ) const { return needs_blockchain_info; }
   void set_needs_blockchain_info( bool val ) { needs_blockchain_info = val; }

   const string& get_blockchain( ) const { return blockchain; }

   size_t get_blockchain_height( ) const { return blockchain_height; }

   void set_blockchain_height( size_t new_height )
   {
      blockchain_height_pending = blockchain_height = new_height;
   }

   bool get_is_test_session( ) const { return is_local && is_responder && blockchain.empty( ); }

   pair< string, string >& get_blockchain_info( ) { return blockchain_info; }

   string& prior_put( ) { return prior_put_hash; }

   void get_hello( );
   void put_hello( );

   void get_file( const string& hash );
   void put_file( const string& hash );

   void pip_peer( const string& ip_address );

   void chk_file( const string& hash, string* p_response = 0 );

   bool want_to_do_op( op o ) const;

   void issue_cmd_for_peer( bool check_for_supporters );

   peer_state& state( ) { return session_state; }
   peer_state& op_state( ) { return session_op_state; }

   peer_trust_level& trust_level( ) { return session_trust_level; }

   void kill_session( )
   {
      if( !is_captured_session( ) )
         set_finished( );
      else if( !is_condemned_session( ) )
         condemn_this_session( );
   }

   private:
   void preprocess_command_and_args( string& str, const string& cmd_and_args );

   void postprocess_command_and_args( const string& cmd_and_args );

   void handle_unknown_command( const string& command, const string& cmd_and_args )
   {
      ( void )cmd_and_args;

      socket.write_line( string( c_response_error_prefix ) + "unknown command '" + command + "'", c_request_timeout );
      kill_session( );
   }

   void handle_invalid_command( const command_parser& parser, const string& cmd_and_args )
   {
      socket.write_line( string( c_response_error_prefix ) + "invalid command usage '" + cmd_and_args + "'", c_request_timeout );
      kill_session( );
   }

   void handle_command_response( const string& response, bool is_special );

#ifdef SSL_SUPPORT
   ssl_socket& socket;
#else
   tcp_socket& socket;
#endif

   bool is_local;
   bool is_owner;
   bool had_usage;

   bool is_responder;
   bool is_for_support;

   bool last_issued_was_put;

   bool needs_blockchain_info;

   string blockchain;
   pair< string, string > blockchain_info;

   size_t blockchain_height;
   size_t blockchain_height_pending;

   string last_command;
   string next_command;

   string prior_put_hash;

   peer_state session_state;
   peer_state session_op_state;
   peer_trust_level session_trust_level;
};

void socket_command_handler::get_hello( )
{
   last_issued_was_put = false;

   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   string data, hello_hash;
   data = get_hello_data( hello_hash );

   if( !has_file( hello_hash ) )
      create_raw_file( data, false );

   string temp_file_name( "~" + uuid( ).as_string( ) );

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   socket.set_delay( );
   socket.write_line( string( c_cmd_peer_session_get ) + " " + hello_hash, timeout, p_progress );

   try
   {
      store_temp_file( temp_file_name, socket, p_progress );

      if( !temp_file_is_identical( temp_file_name, hello_hash ) )
      {
         file_remove( temp_file_name );
         throw runtime_error( "invalid get_hello" );
      }

      increment_peer_files_downloaded( file_bytes( hello_hash ) );

      file_remove( temp_file_name );
   }
   catch( ... )
   {
      file_remove( temp_file_name );
      throw;
   }
}

void socket_command_handler::put_hello( )
{
   last_issued_was_put = true;

   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   string data, hello_hash;
   data = get_hello_data( hello_hash );

   if( !has_file( hello_hash ) )
      create_raw_file( data, false );

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   socket.set_delay( );
   socket.write_line( string( c_cmd_peer_session_put ) + " " + hello_hash, timeout, p_progress );

   fetch_file( hello_hash, socket, p_progress );

   increment_peer_files_uploaded( file_bytes( hello_hash ) );
}

void socket_command_handler::get_file( const string& hash )
{
   last_issued_was_put = false;

   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   string::size_type pos = hash.find( ':' );

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   socket.set_delay( );
   socket.write_line( string( c_cmd_peer_session_get )
    + " " + hash.substr( 0, pos ), timeout, p_progress );

   store_file( hash.substr( 0, pos ), socket, 0, p_progress, true, 0, true );

   // NOTE: If the file is a list then also need to get all of its items.
   if( is_list_file( hash.substr( 0, pos ) ) )
   {
      string tree_root_hash( get_session_variable(
       get_special_var_name( e_special_var_blockchain_tree_root_hash ) ) );

      if( is_owner && !tree_root_hash.empty( ) )
         tag_file( c_ciyam_tag, tree_root_hash );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_tree_root_hash ), "" );

      bool check_for_supporters = false;

      if( !get_system_variable( blockchain + c_supporters_suffix ).empty( ) )
         check_for_supporters = true;

      process_list_items( hash.substr( 0, pos ), false, check_for_supporters );
   }

   increment_peer_files_downloaded( file_bytes( hash.substr( 0, pos ) ) );
}

void socket_command_handler::put_file( const string& hash )
{
   last_issued_was_put = true;

   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   socket.set_delay( );
   socket.write_line( string( c_cmd_peer_session_put ) + " " + hash, timeout, p_progress );

   fetch_file( hash, socket, p_progress );

   increment_peer_files_uploaded( file_bytes( hash ) );
}

void socket_command_handler::pip_peer( const string& ip_address )
{
   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   socket.set_no_delay( );
   socket.write_line( string( c_cmd_peer_session_pip ) + " " + ip_address, timeout, p_progress );

   string response;
   if( socket.read_line( response, timeout, 0, p_progress ) <= 0 )
   {
      string error;
      if( socket.had_timeout( ) )
         error = "timeout occurred getting peer response";
      else
         error = "peer has terminated this connection";

      socket.close( );
      throw runtime_error( error );
   }
}

void socket_command_handler::chk_file( const string& hash_or_tag, string* p_response )
{
   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   string expected;

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   socket.set_no_delay( );

   if( p_response )
      socket.write_line(
       string( c_cmd_peer_session_chk ) + " " + hash_or_tag, timeout, p_progress );
   else
   {
      string nonce( uuid( ).as_string( ) );

      expected = hash_with_nonce( hash_or_tag, nonce );

      socket.write_line( string( c_cmd_peer_session_chk )
       + " " + hash_or_tag + " " + nonce, timeout, p_progress );
   }

   string response;
   if( socket.read_line( response, timeout, 0, p_progress ) <= 0 )
   {
      string error;
      if( socket.had_timeout( ) )
         error = "timeout occurred getting peer response";
      else
         error = "peer has terminated this connection";

      socket.close( );
      throw runtime_error( error );
   }

   if( response == string( c_response_not_found ) )
      response.erase( );

   if( p_response )
      *p_response = response;
   else if( response != expected )
      throw runtime_error( "unexpected invalid chk response: " + response );
}

bool socket_command_handler::want_to_do_op( op o ) const
{
   // NOTE: These statics are only to provide consistent behaviour for a
   // single interactive test session (and are not used by normal peers).
   static unsigned int chk_count = 0;
   static unsigned int pip_count = 0;

   bool retval = false;

   if( get_is_test_session( ) )
   {
      if( o == e_op_init )
         chk_count = pip_count = 0;
      else if( o == e_op_pip )
         retval = ( ++pip_count % 3 == 0 );
      else
         retval = ( ++chk_count % 5 == 0 );
   }
   else
   {
      string hash_to_get( top_next_peer_file_hash_to_get( ) );
      string hash_to_put( top_next_peer_file_hash_to_put( ) );

      if( o == e_op_chk
       && hash_to_get.empty( ) && hash_to_put.empty( ) )
         retval = true;
      else
      {
         if( o == e_op_pip
          && hash_to_get.empty( ) && hash_to_put.empty( ) )
            retval = true;
         else if( o != e_op_chk )
         {
            // KLUDGE: For now just randomly decide (this should instead
            // be based upon the actual needs of the peer).
            retval = ( rand( ) % 10 == 0 );
         }
      }
   }

   return retval;
}

void socket_command_handler::issue_cmd_for_peer( bool check_for_supporters )
{
   // NOTE: If a prior put no longer exists locally then it is to be expected
   // it would not exist in the peer either.
   if( !prior_put( ).empty( ) && !has_file( prior_put( ) ) )
      prior_put( ).erase( );

   bool any_supporter_has_top_get = false;
   bool any_supporter_has_top_put = false;

   string next_hash_to_get, next_hash_to_put;

   // NOTE: If a support session is not given a file hash to get/put then sleep for a while.
   for( size_t i = 0; i < c_support_session_sleep_repeats; i++ )
   {
      next_hash_to_get = top_next_peer_file_hash_to_get(
       ( i == 0 && check_for_supporters ) ? &any_supporter_has_top_get : 0 );

      next_hash_to_put = top_next_peer_file_hash_to_put(
       ( i == 0 && check_for_supporters ) ? &any_supporter_has_top_put : 0 );

      if( is_for_support
       && next_hash_to_get.empty( ) && next_hash_to_put.empty( ) )
         msleep( c_support_session_sleep_time );

      if( !is_for_support || !next_hash_to_get.empty( ) || !next_hash_to_put.empty( ) )
         break;
   }

   bool set_new_zenith = false;

   string zenith_hash( get_session_variable(
    get_special_var_name( e_special_var_blockchain_zenith_hash ) ) );

   if( !zenith_hash.empty( ) && next_hash_to_get.empty( )
    && !any_supporter_has_top_get && !any_supporter_has_top_put )
      set_new_zenith = true;

   // NOTE: If main session has nothing to do while support sessions
   // are still processing get/put file hashes then will sleep here.
   if( !is_for_support
    && next_hash_to_get.empty( ) && next_hash_to_put.empty( )
    && ( any_supporter_has_top_get || any_supporter_has_top_put ) )
      msleep( c_main_session_sleep_time );

   if( get_needs_blockchain_info( ) )
   {
      string blockchain_info_hash;
      chk_file( "c" + blockchain + ".info", &blockchain_info_hash );

      if( !blockchain_info_hash.empty( ) )
      {
         set_needs_blockchain_info( false );

         string last_blockchain_info(
          get_raw_session_variable( get_special_var_name( e_special_var_blockchain_info_hash ) ) );

         if( !has_file( blockchain_info_hash ) && blockchain_info_hash != last_blockchain_info )
            add_peer_file_hash_for_get( blockchain_info_hash );
         else
         {
            set_session_variable(
             get_special_var_name( e_special_var_blockchain_head_hash ), "" );

            set_session_variable(
             get_special_var_name( e_special_var_peer_is_synchronising ), "" );
         }
      }
   }
   else if(
    !any_supporter_has_top_get && !any_supporter_has_top_put
    && !prior_put( ).empty( ) && want_to_do_op( e_op_chk ) )
   {
      bool has_issued_chk = false;

      if( !is_for_support && blockchain.find( c_bc_prefix ) == 0 )
      {
         string genesis_block_tag( blockchain + ".0" + string( c_blk_suffix ) );

         // NOTE: If the genesis block is not present then check if it now exists.
         if( !has_tag( genesis_block_tag ) )
         {
            string genesis_block_hash;
            chk_file( genesis_block_tag, &genesis_block_hash );

            has_issued_chk = true;

            if( !genesis_block_hash.empty( ) )
               add_peer_file_hash_for_get( genesis_block_hash );
         }
         else
         {
            // NOTE: Check whether a new block has been created either locally or remotely.
            string next_block_tag( blockchain
             + '.' + to_string( blockchain_height + 1 ) + c_blk_suffix );

            if( has_tag( next_block_tag ) )
            {
               // NOTE: Use "blockchain_height_pending" here to ensure that only
               // one "process_block_for_height" call will occur for each block.
               // If all of the block related files were found locally then must
               // simply increase the height.
               if( blockchain_height == blockchain_height_pending )
               {
                  string next_block_hash( tag_file_hash( next_block_tag ) );

                  set_session_variable(
                   get_special_var_name( e_special_var_blockchain_is_fetching ), "" );

                  if( process_block_for_height( blockchain, next_block_hash, blockchain_height + 1 ) )
                     blockchain_height = ++blockchain_height_pending;
                  else
                     blockchain_height_pending = blockchain_height + 1;
               }
            }
            else
            {
               string next_block_hash;
               chk_file( next_block_tag, &next_block_hash );

               has_issued_chk = true;

               if( !next_block_hash.empty( ) && !has_file( next_block_hash ) )
               {
                  if( !zenith_hash.empty( ) )
                     set_new_zenith = true;

                  add_peer_file_hash_for_get( next_block_hash );
                  blockchain_height_pending = blockchain_height + 1;

                  set_session_variable(
                   get_special_var_name( e_special_var_blockchain_is_fetching ), c_true );
               }
            }
         }
      }

      if( !has_issued_chk )
         chk_file( prior_put( ) );
   }
   else if( want_to_do_op( e_op_pip ) )
      pip_peer( get_random_same_port_peer_ip_addr( c_local_ip_addr ) );
   else if( next_hash_to_put.empty( ) )
   {
      string next_hash( next_hash_to_get );

      if( !next_hash.empty( ) && next_hash[ 0 ] == c_reprocess_prefix )
      {
         process_core_file( next_hash.substr( 1 ), blockchain );
         next_hash.erase( );
      }

      if( !next_hash.empty( ) && 
       ( next_hash.find( ':' ) == string::npos )
       && !get_session_variable( next_hash ).empty( ) )
      {
         pop_next_peer_file_hash_to_get( );
         next_hash = top_next_peer_file_hash_to_get( );
      }

      while( !next_hash.empty( ) && has_file( next_hash.substr( 0, next_hash.find( ':' ) ) ) )
      {
         pop_next_peer_file_hash_to_get( );
         next_hash = top_next_peer_file_hash_to_get( );
      }

      if( !next_hash.empty( ) )
      {
         get_file( next_hash );
         pop_next_peer_file_hash_to_get( );

         string data_file_hash( get_session_variable(
          get_special_var_name( e_special_var_blockchain_data_file_hash ) ) );

         string primary_pubkey_hash( get_session_variable(
          get_special_var_name( e_special_var_blockchain_primary_pubkey_hash ) ) );

         string signature_file_hash( get_session_variable(
          get_special_var_name( e_special_var_blockchain_signature_file_hash ) ) );

         string secondary_pubkey_hash( get_session_variable(
          get_special_var_name( e_special_var_blockchain_secondary_pubkey_hash ) ) );

         if( next_hash == data_file_hash )
         {
            process_data_file( blockchain, data_file_hash, blockchain_height_pending );

            blockchain_height = blockchain_height_pending;

            set_session_variable(
             get_special_var_name( e_special_var_blockchain_data_file_hash ), "" );
         }
         else if( next_hash == primary_pubkey_hash )
            process_public_key_file( blockchain, primary_pubkey_hash, blockchain_height_pending );
         else if( next_hash == signature_file_hash )
         {
            if( blockchain_height != blockchain_height_pending )
            {
               process_signature_file( blockchain, signature_file_hash, blockchain_height_pending );

               string data_file_hash( get_session_variable(
                get_special_var_name( e_special_var_blockchain_data_file_hash ) ) );

               if( !data_file_hash.empty( ) && !has_file( data_file_hash ) )
                  add_peer_file_hash_for_get( data_file_hash );
            }

            set_session_variable(
             get_special_var_name( e_special_var_blockchain_signature_file_hash ), "" );
         }
         else if( next_hash == secondary_pubkey_hash )
            process_public_key_file( blockchain, secondary_pubkey_hash, blockchain_height_pending, false );
         else if( next_hash[ next_hash.length( ) - 1 ] != c_repository_suffix )
            process_core_file( next_hash, blockchain );
#ifdef SSL_SUPPORT
         else if( get_session_variable( 
          get_special_var_name( e_special_var_blockchain_both_are_owners ) ).empty( ) )
            process_repository_file( blockchain, next_hash.substr( 0, next_hash.length( ) - 1 ), get_is_test_session( ) );
#endif

         if( !blockchain.empty( )
          && ( blockchain.find( c_bc_prefix ) != 0 )
          && top_next_peer_file_hash_to_get( ).empty( ) )
            set_needs_blockchain_info( true );
      }
      else
      {
         get_hello( );

         if( !blockchain.empty( )
          && ( blockchain.find( c_bc_prefix ) != 0 ) )
            set_needs_blockchain_info( true );
      }
   }
   else
   {
      string next_hash( next_hash_to_put );

      bool had_hash = !next_hash.empty( );

      if( next_hash.empty( ) || !has_file( next_hash ) )
         put_hello( );
      else
         put_file( next_hash );

      if( had_hash )
      {
         pop_next_peer_file_hash_to_put( );

         if( !get_session_variable( next_hash ).empty( ) )
         {
            delete_file( next_hash );
            set_session_variable( next_hash, "" );
         }
      }
   }

   if( set_new_zenith )
   {
      tag_file( blockchain + c_zenith_suffix, zenith_hash );

      TRACE_LOG( TRACE_PEER_OPS, "=== new zenith hash: "
       + zenith_hash + " height: " + to_string( blockchain_height ) );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_zenith_hash ), "" );

      set_session_variable(
       get_special_var_name( e_special_var_blockchain_zenith_height ), to_string( blockchain_height ) );
   }
}

void socket_command_handler::preprocess_command_and_args( string& str, const string& cmd_and_args )
{
   str = cmd_and_args;

   if( session_state == e_peer_state_invalid )
      str = c_cmd_peer_session_bye;

   if( !str.empty( ) )
   {
      TRACE_LOG( TRACE_COMMANDS, cmd_and_args );

      if( str[ 0 ] == '?' || str.find( "help" ) == 0 )
      {
         if( !had_usage )
         {
            had_usage = true;

            string::size_type pos = str.find( ' ' );

            string wildcard_match_expr;
            if( pos != string::npos )
               wildcard_match_expr = str.substr( pos + 1 );

            if( get_command_processor( ) )
               get_command_processor( )->output_command_usage( wildcard_match_expr );

            str.erase( );
         }
         else
            str = c_cmd_peer_session_bye;
      }
   }

   if( !str.empty( ) )
      next_command = str;
}

void socket_command_handler::postprocess_command_and_args( const string& cmd_and_args )
{
   string::size_type pos = cmd_and_args.find( ' ' );
   last_command = cmd_and_args.substr( 0, pos );

   if( has_finished( ) )
      TRACE_LOG( TRACE_SESSIONS, get_blockchain( ).empty( )
       ? "finished peer session" : "finished peer session for blockchain " + get_blockchain( ) );
}

void socket_command_handler::handle_command_response( const string& response, bool is_special )
{
   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

   if( !response.empty( ) )
   {
      if( !is_special && is_responder )
         socket.set_delay( );
      else
         socket.set_no_delay( );

      socket.write_line( response, timeout, p_progress );
   }

   if( !is_special && is_responder )
   {
      socket.set_no_delay( );
      socket.write_line( c_response_okay, timeout, p_progress );
   }
}

class peer_session_command_functor : public command_functor
{
   public:
   peer_session_command_functor( command_handler& handler )
    : command_functor( handler ),
    socket_handler( dynamic_cast< socket_command_handler& >( handler ) )
   {
   }

   void operator ( )( const string& command, const parameter_info& parameters );

   socket_command_handler& socket_handler;
};

command_functor* peer_session_command_functor_factory( const string& /*name*/, command_handler& handler )
{
   return new peer_session_command_functor( handler );
}

void peer_session_command_functor::operator ( )( const string& command, const parameter_info& parameters )
{
   string response;

   bool send_okay_response = true;
   bool possibly_expected_error = ( socket_handler.state( ) >= e_peer_state_waiting_for_get );

#ifdef SSL_SUPPORT
   ssl_socket& socket( socket_handler.get_socket( ) );
#else
   tcp_socket& socket( socket_handler.get_socket( ) );
#endif

   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;

   if( command != c_cmd_peer_session_bye )
      socket.set_delay( );

   string hello_data, hello_hash;
   hello_data = get_hello_data( hello_hash );

   set_last_session_cmd_and_hash( command, socket_handler.get_next_command( ) );

   string blockchain( socket_handler.get_blockchain( ) );

   size_t blockchain_height = socket_handler.get_blockchain_height( );

   bool check_for_supporters = false;

   if( !get_system_variable( blockchain + c_supporters_suffix ).empty( ) )
      check_for_supporters = true;

   try
   {
      ostringstream osstr;

      if( command == c_cmd_peer_session_chk )
      {
         string tag_or_hash( get_parm_val( parameters, c_cmd_peer_session_chk_tag_or_hash ) );
         string nonce( get_parm_val( parameters, c_cmd_peer_session_chk_nonce ) );

         if( socket_handler.state( ) != e_peer_state_responder
          && socket_handler.state( ) != e_peer_state_waiting_for_get
          && socket_handler.state( ) != e_peer_state_waiting_for_put
          && socket_handler.state( ) != e_peer_state_waiting_for_get_or_put )
            throw runtime_error( "invalid state for chk" );

         // NOTE: Create the dummy "hello" blob as it will be required.
         if( !has_file( hello_hash ) )
            create_raw_file( hello_data, false );

         string hash( tag_or_hash );

         if( hash == hello_hash )
            response = hello_hash;

         if( has_tag( tag_or_hash ) )
            response = hash = tag_file_hash( tag_or_hash );

         // NOTE: Unless doing interactive testing any peer "chk tag" request must start
         // with the blockchain tag prefix (otherwise a peer might be able to find files
         // that are not intended for their discovery).
         if( !blockchain.empty( )
          && ( tag_or_hash.find( blockchain ) != 0 )
          && ( tag_or_hash.find( "c" + blockchain ) != 0 )
          && ( tag_or_hash.length( ) != ( c_sha256_digest_size * 2 ) ) )
            throw runtime_error( "invalid non-blockchain prefixed tag" );

         if( tag_or_hash.find( c_key_suffix ) != string::npos )
            throw runtime_error( "invalid suspiciouus tag '" + tag_or_hash + "'" );

         bool has = has_file( hash, false );
         bool was_initial_state = ( socket_handler.state( ) == e_peer_state_responder );

         if( !has )
         {
            response = c_response_not_found;

            if( was_initial_state )
            {
               if( !blockchain.empty( ) )
               {
                  if( tag_or_hash.find( c_bc_prefix ) != 0 )
                     socket_handler.state( ) = e_peer_state_invalid;
                  else
                  {
                     socket_handler.op_state( ) = e_peer_state_waiting_for_get;
                     socket_handler.state( ) = e_peer_state_waiting_for_get_or_put;

                     socket_handler.trust_level( ) = e_peer_trust_level_normal;

                     if( !nonce.empty( ) )
                        add_peer_file_hash_for_get( nonce );
                  }
               }
               else
               {
                  handler.issue_command_response( response, true );

                  handler.issue_command_response( "put " + hello_hash, true );

                  socket.set_delay( );
                  fetch_file( hello_hash, socket, p_progress );

                  string temp_file_name( "~" + uuid( ).as_string( ) );

                  try
                  {
                     store_temp_file( temp_file_name, socket, p_progress );

                     response.erase( );

                     if( !temp_file_is_identical( temp_file_name, hello_hash ) )
                        socket_handler.state( ) = e_peer_state_invalid;
                     else
                     {
                        socket_handler.state( ) = e_peer_state_waiting_for_put;
                        socket_handler.op_state( ) = e_peer_state_waiting_for_put;

                        socket_handler.trust_level( ) = e_peer_trust_level_normal;
                     }

                     increment_peer_files_uploaded( hello_data.length( ) );
                     increment_peer_files_downloaded( hello_data.length( ) );

                     file_remove( temp_file_name );
                  }
                  catch( ... )
                  {
                     file_remove( temp_file_name );
                     throw;
                  }
               }
            }
            else if( blockchain.empty( ) )
            {
               string local_hash, local_public_key, master_public_key;

               if( fetch_repository_entry_record( hash,
                local_hash, local_public_key, master_public_key, false ) )
               {
                  string pull_hash(
                   create_peer_repository_entry_pull_info( hash, local_hash, local_public_key, "" ) );

                  add_peer_file_hash_for_put( pull_hash );

                  set_session_variable( pull_hash, c_true );
               }
            }
         }
         else
         {
            if( was_initial_state
             && tag_or_hash.find( c_bc_prefix ) == 0 )
               nonce.erase( );

            if( !nonce.empty( ) )
               response = hash_with_nonce( hash, nonce );

            if( was_initial_state )
            {
               socket_handler.op_state( ) = e_peer_state_waiting_for_get;

               if( blockchain.empty( ) )
                  socket_handler.state( ) = e_peer_state_waiting_for_get;
               else
               {
                  socket_handler.state( ) = e_peer_state_waiting_for_get_or_put;

                  if( tag_or_hash.find( c_bc_prefix ) == 0 )
                  {
                     if( get_block_height_from_tags( blockchain, hash, blockchain_height ) )
                        process_block_for_height( blockchain, hash, blockchain_height );
                  }
                  else if( !socket_handler.get_is_for_support( ) )
                  {
                     string all_tags( get_hash_tags( hash ) );

                     set< string > tags;
                     split( all_tags, tags, '\n' );

                     string tag( "c" + blockchain + ".head" );

                     if( !tags.count( tag ) )
                        throw runtime_error( "blockchain " + blockchain + " was not found" );
                  }
               }
            }
            else if( !socket_handler.get_is_for_support( ) && ( tag_or_hash.find( c_bc_prefix ) == 0 ) )
            {
               if( get_block_height_from_tags( blockchain, hash, blockchain_height ) )
               {
                  if( socket_handler.get_is_responder( )
                   && blockchain_height != socket_handler.get_blockchain_height( ) )
                  {
                     socket_handler.set_blockchain_height( blockchain_height );
                     process_block_for_height( blockchain, hash, blockchain_height );
                  }
                  else
                  {
                     // NOTE: If is blockchain owner and not currently fetching then provided that the other peer is not
                     // also the owner then need to process the block to fetch/store any required repository entries for
                     // which information about will need to be "put".
                     if( !get_session_variable( get_special_var_name( e_special_var_blockchain_is_owner ) ).empty( )
                      && get_session_variable( get_special_var_name( e_special_var_blockchain_is_fetching ) ).empty( )
                      && get_session_variable( get_special_var_name( e_special_var_blockchain_both_are_owners ) ).empty( ) )
                        process_block_for_height( blockchain, hash, blockchain_height );
                  }
               }
            }
         }

         if( has && !blockchain.empty( ) && ( tag_or_hash == "c" + blockchain + ".info" ) )
         {
            if( !socket_handler.get_blockchain_info( ).second.empty( ) )
               file_remove( socket_handler.get_blockchain_info( ).second );

            socket_handler.get_blockchain_info( ).first = hash;
            socket_handler.get_blockchain_info( ).second = "~" + uuid( ).as_string( );

            copy_raw_file( hash, socket_handler.get_blockchain_info( ).second );
         }

         if( !was_initial_state && socket_handler.get_is_responder( ) )
         {
            handler.issue_command_response( response, true );
            response.erase( );

            socket_handler.issue_cmd_for_peer( check_for_supporters );
         }
      }
      else if( command == c_cmd_peer_session_get )
      {
         string tag_or_hash( get_parm_val( parameters, c_cmd_peer_session_get_tag_or_hash ) );

         if( socket_handler.state( ) != e_peer_state_waiting_for_get
          && socket_handler.state( ) != e_peer_state_waiting_for_get_or_put )
         {
            if( !socket_handler.get_is_responder( ) )
               throw runtime_error( "invalid state for get (initiator)" );
            else
               throw runtime_error( "invalid state for get (responder)" );
         }

         string hash( tag_or_hash );

         if( has_tag( tag_or_hash ) )
            hash = tag_file_hash( tag_or_hash );

         socket.set_delay( );

         if( hash != socket_handler.get_blockchain_info( ).first )
         {
            fetch_file( hash, socket, p_progress );
            increment_peer_files_uploaded( file_bytes( hash ) );
         }
         else
         {
            socket_handler.get_blockchain_info( ).first.erase( );

            fetch_temp_file( socket_handler.get_blockchain_info( ).second, socket, p_progress );
            increment_peer_files_uploaded( file_size( socket_handler.get_blockchain_info( ).second ) );

            file_remove( socket_handler.get_blockchain_info( ).second );

            socket_handler.get_blockchain_info( ).second.erase( );
         }

         socket_handler.op_state( ) = e_peer_state_waiting_for_put;

         if( blockchain.empty( ) )
            socket_handler.state( ) = e_peer_state_waiting_for_put;
         else
            socket_handler.state( ) = e_peer_state_waiting_for_get_or_put;

         if( socket_handler.get_is_responder( ) )
         {
            handler.issue_command_response( response, true );
            response.erase( );

            if( blockchain.empty( ) && top_next_peer_file_hash_to_put( ).empty( ) )
               add_peer_file_hash_for_put( hello_hash );

            socket_handler.issue_cmd_for_peer( check_for_supporters );
         }
      }
      else if( command == c_cmd_peer_session_put )
      {
         string hash( get_parm_val( parameters, c_cmd_peer_session_put_hash ) );

         if( socket_handler.state( ) < e_peer_state_waiting_for_put )
         {
            if( !socket_handler.get_is_responder( ) )
               throw runtime_error( "invalid state for put (initiator)" );
            else
               throw runtime_error( "invalid state for put (responder)" );
         }

         socket.set_delay( );

         int64_t bytes = 0;

         if( !has_file( hash ) )
         {
            string file_data;

            store_file( hash, socket, 0, p_progress, false, 0, false, &file_data );

            bytes = file_data.length( );

            if( hash != hello_hash )
               process_put_file( blockchain, file_data.substr( 1 ), socket_handler.get_is_test_session( ) );
         }
         else
         {
            bytes = file_bytes( hash );

            store_temp_file( "", socket, p_progress, true );
         }

         increment_peer_files_downloaded( bytes );

         if( has_file( hash ) )
         {
            if( socket_handler.prior_put( ).empty( ) )
               socket_handler.prior_put( ) = hash;
         }

         socket_handler.op_state( ) = e_peer_state_waiting_for_get;

         if( blockchain.empty( ) )
            socket_handler.state( ) = e_peer_state_waiting_for_get;
         else
            socket_handler.state( ) = e_peer_state_waiting_for_get_or_put;

         if( socket_handler.get_is_responder( ) )
         {
            handler.issue_command_response( response, true );
            response.erase( );

            socket_handler.issue_cmd_for_peer( check_for_supporters );
         }
      }
      else if( command == c_cmd_peer_session_pip )
      {
         string addr( get_parm_val( parameters, c_cmd_peer_session_pip_addr ) );

         response = get_random_same_port_peer_ip_addr( c_local_ip_addr );

         if( socket_handler.state( ) != e_peer_state_waiting_for_get
          && socket_handler.state( ) != e_peer_state_waiting_for_put
          && socket_handler.state( ) != e_peer_state_waiting_for_get_or_put )
            throw runtime_error( "invalid state for pip" );

         if( socket_handler.get_is_responder( ) )
         {
            handler.issue_command_response( response, true );
            response.erase( );

            socket_handler.issue_cmd_for_peer( check_for_supporters );
         }
      }
      else if( command == c_cmd_peer_session_tls )
      {
         if( socket_handler.state( ) != e_peer_state_responder )
            throw runtime_error( "invalid state for tls" );

#ifdef SSL_SUPPORT
         if( socket.is_secure( ) )
            throw runtime_error( "TLS is already active" );

         if( !get_using_ssl( ) )
            throw runtime_error( "SSL has not been initialised" );

         socket.ssl_accept( );
#else
         throw runtime_error( "SSL support not available" );
#endif

         socket_handler.state( ) = e_peer_state_waiting_for_get;
         socket_handler.op_state( ) = e_peer_state_waiting_for_get;
      }
      else if( command == c_cmd_peer_session_bye )
      {
         if( !is_captured_session( ) )
            handler.set_finished( );
         else if( !is_condemned_session( ) )
            condemn_this_session( );

         return;
      }
   }
   catch( exception& x )
   {
      TRACE_LOG( ( possibly_expected_error ? TRACE_SESSIONS : 0 ), string( "peer session error: " ) + x.what( ) );

      send_okay_response = false;
      response = string( c_response_error_prefix ) + x.what( );

      socket_handler.state( ) = e_peer_state_invalid;
   }
   catch( ... )
   {
      TRACE_LOG( TRACE_ANYTHING, "peer session error: unexpected unknown exception caught" );

      send_okay_response = false;
      response = string( c_response_error_prefix ) + "unexpected unknown exception caught";

      socket_handler.state( ) = e_peer_state_invalid;
   }

   handler.issue_command_response( response, !send_okay_response );

   if( !send_okay_response || is_condemned_session( ) )
   {
      socket_handler.state( ) = e_peer_state_invalid;

      if( !is_captured_session( ) )
      {
         if( is_condemned_session( ) && socket_handler.get_is_responder( ) )
            socket.write_line( c_cmd_peer_session_bye, c_request_timeout, p_progress );

         handler.set_finished( );
      }
      else if( !is_condemned_session( ) )
         condemn_this_session( );
   }
   else if( !socket_handler.get_is_responder( ) && !g_server_shutdown
    && ( socket_handler.op_state( ) == e_peer_state_waiting_for_get ) )
   {
      string response;

      size_t timeout = socket_handler.get_is_for_support( ) ? c_support_timeout : c_request_timeout;

      if( socket.read_line( response, timeout, 0, p_progress ) <= 0 )
      {
         string error;
         if( socket.had_timeout( ) )
            error = "timeout occurred getting peer response";
         else
            error = "peer has terminated this connection";

         socket.close( );

         if( !is_captured_session( ) )
            handler.set_finished( );
         else if( !is_condemned_session( ) )
            condemn_this_session( );

         throw runtime_error( error );
      }

      if( response != string( c_response_okay ) )
      {
         socket.close( );

         if( !is_captured_session( ) )
            handler.set_finished( );
         else if( !is_condemned_session( ) )
            condemn_this_session( );

         throw runtime_error( "unexpected non-okay response from peer" );
      }

      socket_handler.issue_cmd_for_peer( check_for_supporters );
   }
}

class socket_command_processor : public command_processor
{
   public:
   socket_command_processor( tcp_socket& socket,
    command_handler& handler, bool is_local, bool is_owner, bool is_responder )
    : command_processor( handler ),
    socket( socket ),
    handler( handler ),
    new_block_wait( 0 ),
    is_local( is_local ),
    is_owner( is_owner ),
    is_responder( is_responder ),
    needs_blockchain_info( false )
   {
      peer_special_variable = get_special_var_name( e_special_var_peer );

      initiator_special_variable = get_special_var_name( e_special_var_peer_initiator );
      responder_special_variable = get_special_var_name( e_special_var_peer_responder );

      string value( c_true );

      socket_command_handler& socket_handler = dynamic_cast< socket_command_handler& >( handler );

      if( !socket_handler.get_blockchain( ).empty( ) )
      {
         needs_blockchain_info = true;
         value = socket_handler.get_blockchain( );
      }

      set_session_variable( peer_special_variable, value );

      if( !is_responder )
         set_session_variable( initiator_special_variable, value );
      else
         set_session_variable( responder_special_variable, value );
   }

   private:
   tcp_socket& socket;
   command_handler& handler;

   string peer_special_variable;
   string initiator_special_variable;
   string responder_special_variable;

   int new_block_wait;
   new_block_info new_block;
   string new_block_pwd_hash;

   bool is_local;
   bool is_owner;

   bool is_responder;

   bool needs_blockchain_info;

   bool is_still_processing( ) { return is_captured_session( ) || socket.okay( ); }

   void get_cmd_and_args( string& cmd_and_args );

   void output_command_usage( const string& wildcard_match_expr ) const;
};

void socket_command_processor::get_cmd_and_args( string& cmd_and_args )
{
   socket_command_handler& socket_handler = dynamic_cast< socket_command_handler& >( handler );

   string blockchain( socket_handler.get_blockchain( ) );

   bool check_for_supporters = false;

   while( true )
   {
      progress* p_progress = 0;
      trace_progress progress( TRACE_SOCK_OPS );

      if( get_trace_flags( ) & TRACE_SOCK_OPS )
         p_progress = &progress;

      if( !g_server_shutdown && !is_condemned_session( ) )
      {
         if( !blockchain.empty( ) && ( blockchain.find( c_bc_prefix ) != 0 ) )
         {
            string new_acct( new_block.acct );

            // NOTE: If either a better block at the newly minted block's height or a better previous block than
            // the one it is currently linked to has been processed then will need to mint another new block. If
            // a minting account was released then also mint another new block. Also if the same account that is
            // minting had created the better block (i.e. from a Sybil peer) then will need to stop this account
            // from minting (to minimise wasting any further resources).
            if( !new_block_pwd_hash.empty( )
             && ( has_better_block( blockchain, new_block.height, new_block.weight, &new_acct )
             || was_released( blockchain )
             || ( new_block.height > 1
             && has_better_block( blockchain, new_block.height - 1, new_block.previous_block_weight ) ) ) )
            {
               if( new_acct.empty( ) )
                  use_peer_account( blockchain, new_block_pwd_hash, true, true );

               new_block_pwd_hash.erase( );
            }

            if( !new_block_pwd_hash.empty( ) )
            {
               if( new_block.num_txs < 0 )
                  new_block_pwd_hash.erase( );
               else
               {
                  if( new_block_wait > 0 )
                     --new_block_wait;
                  else
                  {
                     string tmp_new_block_pwd_hash( new_block_pwd_hash );

                     new_block_pwd_hash.erase( );

                     if( !has_any_session_variable(
                      get_special_var_name( e_special_var_peer_is_synchronising ), blockchain ) )
                        store_new_block( blockchain, tmp_new_block_pwd_hash );
                  }
               }
            }
            else if( is_first_using_session_variable( peer_special_variable, blockchain )
             && !has_any_session_variable(
             get_special_var_name( e_special_var_peer_is_synchronising ), blockchain ) )
            {
               mint_new_block( blockchain, new_block, new_block_pwd_hash, false );
               new_block_wait = ( c_min_block_wait_passes * ( int )new_block.range );
            }
         }
      }

      if( !check_for_supporters && !socket_handler.get_is_for_support( )
       && !get_system_variable( blockchain + c_supporters_suffix ).empty( ) )
         check_for_supporters = true;

      size_t timeout = socket_handler.get_is_for_support( ) ? c_support_timeout : c_request_timeout;

      if( !is_responder && !g_server_shutdown && !is_condemned_session( ) )
      {
         if( socket_handler.op_state( ) == e_peer_state_waiting_for_put )
         {
            string response;
            if( socket.read_line( response, timeout, 0, p_progress ) <= 0 )
            {
               cmd_and_args = "bye";
               break;
            }

            if( response != string( c_response_okay ) )
            {
               cmd_and_args = "bye";
               break;
            }

            if( blockchain.empty( ) )
               socket_handler.state( ) = e_peer_state_waiting_for_get;
            else
               socket_handler.state( ) = e_peer_state_waiting_for_get_or_put;

            socket_handler.issue_cmd_for_peer( check_for_supporters );
         }
      }

      if( socket.read_line( cmd_and_args, timeout, c_max_line_length, p_progress ) <= 0 )
      {
         if( !is_captured_session( )
          && ( is_condemned_session( ) || g_server_shutdown || !socket.had_timeout( ) ) )
         {
            if( is_condemned_session( ) && !socket_handler.get_is_for_support( ) )
               condemn_matching_sessions( );

            // NOTE: If the session is not captured and it has either been condemned or
            // the server is shutting down, or its socket has died then force a "bye".
            cmd_and_args = "bye";
            break;
         }

         // NOTE: If the socket is dead then the "read_line" will return instantly so for
         // a "captured" session manually perform a timeout sleep so CPU is not overused.
         if( is_captured_session( ) && !socket.had_timeout( ) )
         {
            msleep( c_request_timeout );
            continue;
         }

         if( !is_local || !socket.had_timeout( ) )
         {
            // NOTE: Don't allow zombies to hang around unless they are local.
            cmd_and_args = "bye";
            break;
         }
      }
      else
      {
         if( is_condemned_session( ) && !socket_handler.get_is_for_support( ) )
            condemn_matching_sessions( );

#ifdef USE_THROTTLING
         if( cmd_and_args != "bye" )
            msleep( c_request_throttle_sleep_time );
#endif
         if( cmd_and_args == c_response_okay || cmd_and_args == c_response_okay_more )
            cmd_and_args = "bye";

         break;
      }
   }
}

void socket_command_processor::output_command_usage( const string& wildcard_match_expr ) const
{
   socket.set_delay( );

   string cmds( "commands:" );
   if( !wildcard_match_expr.empty( ) )
      cmds += ' ' + wildcard_match_expr;

   socket.write_line( cmds, c_request_timeout );
   socket.write_line( "=========", c_request_timeout );

   socket.write_line( get_usage_for_commands( wildcard_match_expr ), c_request_timeout );

   socket.set_no_delay( );
   socket.write_line( c_response_okay, c_request_timeout );
}

#ifdef SSL_SUPPORT
peer_session* construct_session( bool is_responder,
 auto_ptr< ssl_socket >& ap_socket, const string& ip_addr, bool is_for_support = false )
#else
peer_session* construct_session( bool is_responder,
 auto_ptr< tcp_socket >& ap_socket, const string& ip_addr, bool is_for_support = false )
#endif
{
   peer_session* p_session = 0;

   string::size_type pos = ip_addr.find( '=' );

   if( is_for_support
    || ip_addr.substr( 0, pos ) == c_local_ip_addr
    || ip_addr.substr( 0, pos ) == c_local_ip_addr_for_ipv6
    || !has_session_with_ip_addr( ip_addr.substr( 0, pos ) ) )
      p_session = new peer_session( is_responder, ap_socket, ip_addr, is_for_support );

   return p_session;
}

}

#ifdef SSL_SUPPORT
peer_session::peer_session( bool is_responder,
 auto_ptr< ssl_socket >& ap_socket, const string& ip_addr, bool is_for_support )
#else
peer_session::peer_session( bool is_responder,
 auto_ptr< tcp_socket >& ap_socket, const string& ip_addr, bool is_for_support )
#endif
 :
 is_local( false ),
 is_owner( false ),
 ip_addr( ip_addr ),
 ap_socket( ap_socket ),
 is_responder( is_responder ),
 is_for_support( is_for_support ),
 has_found_both_are_owners( false )
{
   if( !( *this->ap_socket ) )
      throw runtime_error( "unexpected invalid socket in peer_session::peer_session" );

   string::size_type pos = ip_addr.find( '=' );
   if( pos != string::npos )
   {
      blockchain = ip_addr.substr( pos + 1 );
      this->ip_addr.erase( pos );
   }

   pos = blockchain.find( ':' );
   if( pos != string::npos )
   {
      port = blockchain.substr( pos + 1 );
      blockchain.erase( pos );
   }

   if( !blockchain.empty( ) && ( blockchain.find( c_bc_prefix ) != 0 ) && !has_tag( "c" + blockchain ) )
      throw runtime_error( "no blockchain metadata file tag 'c" + blockchain + "' was found" );

   if( port.empty( ) )
   {
      if( blockchain.empty( ) )
         port = get_test_peer_port( );
      else
         port = to_string( get_blockchain_port( blockchain ) );
   }

   if( this->ip_addr == c_local_ip_addr || this->ip_addr == c_local_ip_addr_for_ipv6 )
      is_local = true;

   if( !blockchain.empty( ) && ( blockchain.find( c_bc_prefix ) == 0 )
    && !list_file_tags( blockchain + string( ".p*" ) + c_key_suffix ).empty( ) )
      is_owner = true;

   progress* p_progress = 0;
   trace_progress progress( TRACE_SOCK_OPS );

#ifdef DEBUG_PEER_HANDSHAKE
   if( get_trace_flags( ) & TRACE_SOCK_OPS )
      p_progress = &progress;
#endif

   // NOTE: A dummy PID is being written/read here so that the standard general
   // purpose client can be used to connect as a peer (for interactive testing).
   string pid( c_dummy_peer_tag );

   if( !is_responder )
   {
      if( is_for_support )
         pid = string( c_dummy_support_tag );
      else if( is_owner )
         pid += '!';

      this->ap_socket->set_no_delay( );
      this->ap_socket->write_line( pid, c_request_timeout, p_progress );
   }
   else
   {
      pid.erase( );

      this->ap_socket->read_line( pid, c_request_timeout, c_max_greeting_size, p_progress );

      string::size_type pos = pid.find( '!' );

      if( pos != string::npos )
      {
         pid.erase( pos );

         if( is_owner )
            has_found_both_are_owners = true;
      }

      if( pid == string( c_dummy_support_tag ) )
         this->is_for_support = true;
      else if( pid == string( c_dummy_peer_tag ) )
         this->is_for_support = false;
      else if( blockchain.empty( ) )
         this->is_for_support = false;
      else
         throw runtime_error( "unexpected peer handshake" );
   }

   // NOTE: This check is necessary because listener created sessions set "is_for_support" true but
   //  whether it is actually a support session is only knowable after the first line has been read.
   if( !this->is_for_support && has_session_with_ip_addr( this->ip_addr ) )
      throw runtime_error( "cannot create a non-support peer when has an existing non-support peer session" );

   increment_session_count( );
}

peer_session::~peer_session( )
{
   decrement_session_count( );
}

void peer_session::on_start( )
{
   bool okay = false;
   bool has_terminated = false;
   bool was_initialised = false;

   try
   {
      socket_command_handler cmd_handler( *ap_socket,
       is_responder ? e_peer_state_responder : e_peer_state_initiator, is_local, is_owner, blockchain, is_for_support );

      cmd_handler.add_commands( 0,
       peer_session_command_functor_factory, ARRAY_PTR_AND_SIZE( peer_session_command_definitions ) );

      size_t timeout = is_for_support ? c_support_timeout : c_request_timeout;

      progress* p_progress = 0;
      trace_progress progress( TRACE_SOCK_OPS );

#ifdef DEBUG_PEER_HANDSHAKE
      if( get_trace_flags( ) & TRACE_SOCK_OPS )
         p_progress = &progress;
#endif

      if( is_responder )
      {
         string extra( to_string( get_files_area_item_max_size( ) ) );

         if( is_owner )
            extra += '!';

         ap_socket->write_line( string( c_protocol_version )
          + ':' + extra + '\n' + string( c_response_okay ), timeout, p_progress );
      }
      else
      {
         string greeting;

         if( ap_socket->read_line( greeting, timeout, c_max_greeting_size, p_progress ) <= 0 )
         {
            string error;
            if( ap_socket->had_timeout( ) )
               error = "timeout occurred trying to connect to peer";
            else
               error = "peer has terminated this connection";

            ap_socket->close( );
            throw runtime_error( error );
         }

         version_info ver_info;
         if( get_version_info( greeting, ver_info ) != string( c_response_okay ) )
         {
            ap_socket->close( );

            throw runtime_error( greeting );
         }

         if( !check_version_info( ver_info, c_protocol_major_version, c_protocol_minor_version ) )
         {
            ap_socket->close( );

            throw runtime_error( "incompatible protocol version "
             + ver_info.ver + " (expecting " + string( c_protocol_version ) + ")" );
         }

         if( !ver_info.extra.empty( ) )
         {
            string::size_type pos = ver_info.extra.find( '!' );

            if( pos != string::npos )
            {
               ver_info.extra.erase( pos );

               if( is_owner )
                  has_found_both_are_owners = true;
            }

            if( from_string< size_t >( ver_info.extra ) != get_files_area_item_max_size( ) )
            {
               ap_socket->close( );

               throw runtime_error( "unexpected files area item max size mismatch" );
            }
         }
      }

      init_session( cmd_handler, true, &ip_addr, &blockchain, from_string< int >( port ), is_for_support );

      if( is_owner )
         set_session_variable( get_special_var_name( e_special_var_blockchain_is_owner ), c_true );

      if( has_found_both_are_owners )
         set_session_variable( get_special_var_name( e_special_var_blockchain_both_are_owners ), c_true );

      okay = true;
      was_initialised = true;

      bool has_zenith = false;
      size_t blockchain_height = 0;

      string hello_data, hello_hash;
      hello_data = get_hello_data( hello_hash );

      // NOTE: Create the dummy "hello" blob as it will be required.
      if( !has_file( hello_hash ) )
         create_raw_file( hello_data, false );

      cmd_handler.prior_put( ) = hello_hash;

      if( blockchain.find( c_bc_prefix ) == 0 )
      {
         if( has_tag( blockchain + c_zenith_suffix ) )
         {
            string zenith_hash( tag_file_hash( blockchain + c_zenith_suffix ) );

            if( get_block_height_from_tags( blockchain, zenith_hash, blockchain_height ) )
            {
               has_zenith = true;
               cmd_handler.set_blockchain_height( blockchain_height );

               set_session_variable( get_special_var_name(
                e_special_var_blockchain_zenith_height ), to_string( blockchain_height ) );
            }
         }
      }

      if( !is_responder )
      {
         string hash_or_tag;

         if( !is_for_support && !blockchain.empty( ) )
         {
            if( blockchain.find( c_bc_prefix ) == 0 )
            {
               size_t height_for_chk = blockchain_height;

               if( has_zenith )
                  ++height_for_chk;

               hash_or_tag = blockchain + '.' + to_string( height_for_chk ) + string( c_blk_suffix );

               // NOTE: In case the responder does not have the genesis block include
               // its hash as a dummy "nonce" (to be used by the responder for "get").
               string genesis_block_tag( blockchain + ".0" + string( c_blk_suffix ) );

               if( has_tag( genesis_block_tag ) )
                  hash_or_tag += ' ' + tag_file_hash( genesis_block_tag );
            }
            else
               hash_or_tag = string( "c" + blockchain + ".head" );
         }

         if( hash_or_tag.empty( ) )
            hash_or_tag = hello_hash;

         ap_socket->write_line( string( c_cmd_peer_session_chk ) + " " + hash_or_tag, timeout, p_progress );

         cmd_handler.state( ) = e_peer_state_waiting_for_put;
         cmd_handler.op_state( ) = e_peer_state_waiting_for_put;

         if( !blockchain.empty( ) )
         {
            if( blockchain.find( c_bc_prefix ) == 0 )
            {
               string block_hash;

               if( ap_socket->read_line( block_hash, timeout, c_max_line_length, p_progress ) <= 0 )
                  okay = false;
               else if( !is_for_support && ( block_hash != string( c_response_not_found ) ) )
                  add_peer_file_hash_for_get( block_hash );
            }
            else
            {
               string blockchain_head_hash;

               if( ap_socket->read_line( blockchain_head_hash, timeout, c_max_line_length, p_progress ) <= 0 )
                  okay = false;

               set_session_variable(
                get_special_var_name( e_special_var_blockchain_head_hash ), blockchain_head_hash );
            }
         }
      }

      if( okay )
      {
         TRACE_LOG( TRACE_SESSIONS,
          string( "started peer session " )
          + ( !is_responder ? "(as initiator)" : "(as responder)" )
          + ( blockchain.empty( ) ? "" : " for blockchain " + blockchain )
          + ( !is_owner ? "" : " owner" )
          + ( !is_for_support ? "" : " support" )
          + " (tid = " + to_string( current_thread_id( ) ) + ")" );

         socket_command_processor processor( *ap_socket, cmd_handler, is_local, is_owner, is_responder );
         processor.process_commands( );
      }

      ap_socket->close( );

      if( was_initialised )
      {
         term_session( );
         has_terminated = true;
      }
   }
   catch( exception& x )
   {
      issue_error( x.what( ), true );

      ap_socket->write_line( string( c_response_error_prefix ) + x.what( ), c_request_timeout );
      ap_socket->close( );

      if( was_initialised )
      {
         term_session( );
         has_terminated = true;
      }
   }
   catch( ... )
   {
      issue_error( "unexpected unknown exception occurred" );

      ap_socket->write_line( string( c_response_error_prefix ) + "unexpected exception occurred", c_request_timeout );
      ap_socket->close( );

      if( was_initialised )
      {
         term_session( );
         has_terminated = true;
      }
   }

   if( has_terminated && !is_for_support && !blockchain.empty( ) )
      set_system_variable( blockchain + c_supporters_suffix, "" );

   if( !is_responder && !blockchain.empty( ) && !g_server_shutdown )
   {
      string addr( ip_addr );
      if( !port.empty( ) )
         addr += '!' + port;

      if( okay )
         add_good_peer( addr, blockchain );
      else if( was_good_peer( addr, blockchain ) )
         okay = true;

      if( okay )
         add_peer_to_retry( addr, blockchain );
   }

   delete this;
}

void peer_session::increment_session_count( )
{
   guard g( g_mutex );

   ++g_num_peers;
   ciyam_session::increment_session_count( );
}

void peer_session::decrement_session_count( )
{
   guard g( g_mutex );

   --g_num_peers;
   ciyam_session::decrement_session_count( );
}

void peer_listener::on_start( )
{
   try
   {
      increment_active_listeners( );

      tcp_socket s;
      bool okay = s.open( );

      ip_address address( port );

      if( okay )
      {
         s.set_reuse_addr( );

         string listener_name( "peer" );

         if( !blockchain.empty( ) )
            listener_name += " (" + blockchain + ")";

         listener_registration registration( port, listener_name );

         okay = s.bind( address );

         if( okay )
            okay = s.listen( );

         if( okay )
         {
            TRACE_LOG( TRACE_ANYTHING,
             "peer listener started on port " + to_string( port )
             + ( blockchain.empty( ) ? "" : " for blockchain " + blockchain ) );

            while( s && !g_server_shutdown )
            {
               // NOTE: Check for accepts and create new sessions.
#ifdef SSL_SUPPORT
               auto_ptr< ssl_socket > ap_socket( new ssl_socket( s.accept( address, c_accept_timeout ) ) );
#else
               auto_ptr< tcp_socket > ap_socket( new tcp_socket( s.accept( address, c_accept_timeout ) ) );
#endif
               if( !g_server_shutdown && *ap_socket
                && !has_max_peers( ) && get_is_accepted_peer_ip_addr( address.get_addr_string( ) ) )
               {
                  peer_session* p_session = 0;

                  // NOTE: Need to assume it is a support session initially (the first read will
                  // determine if it actually is or not).
                  try
                  {
                     p_session = construct_session(
                      true, ap_socket, address.get_addr_string( ) + '=' + blockchain, true );
                  }
                  catch( exception& x )
                  {
                     issue_error( x.what( ) );
                  }
                  catch( ... )
                  {
                     issue_error( "unexpected unknown exception occurred constructing session" );
                  }

                  if( p_session )
                     p_session->start( );
               }

               // NOTE: If a previously good peer has become disconnected then will
               // try and re-connect to it here.
               if( !g_server_shutdown && !blockchain.empty( ) && !has_max_peers( ) )
               {
                  string peer_info( get_peer_to_retry( blockchain ) );

                  int peer_port( port );
                  string peer_ip_addr( peer_info );

                  string::size_type pos = peer_info.find( '!' );
                  if( pos != string::npos )
                  {
                     peer_ip_addr = peer_info.substr( 0, pos );
                     peer_port = atoi( peer_info.substr( pos + 1 ).c_str( ) );
                  }

                  if( !peer_info.empty( ) )
                  {
#ifdef SSL_SUPPORT
                     auto_ptr< ssl_socket > ap_socket( new ssl_socket );
#else
                     auto_ptr< tcp_socket > ap_socket( new tcp_socket );
#endif

                     bool started = false;
                     if( ap_socket->open( ) )
                     {
                        ip_address address( peer_ip_addr.c_str( ), peer_port );

                        if( ap_socket->connect( address, c_initial_timeout ) )
                        {
                           peer_session* p_session = construct_session(
                            false, ap_socket, peer_ip_addr + "=" + blockchain + ":" + to_string( peer_port ) );

                           if( p_session )
                           {
                              started = true;
                              p_session->start( );
                           }
                        }
                     }

                     if( !started )
                        add_peer_to_retry( peer_info, blockchain );
                  }
               }
            }

            s.close( );
         }
         else
         {
            s.close( );
            issue_error( "unexpected socket error" );
         }
      }
   }
   catch( exception& x )
   {
      issue_error( x.what( ) );
   }
   catch( ... )
   {
      issue_error( "unexpected unknown exception occurred" );
   }

   TRACE_LOG( TRACE_ANYTHING,
    "peer listener finished (port " + to_string( port ) + ")"
    + ( blockchain.empty( ) ? "" : " for blockchain " + blockchain ) );

   decrement_active_listeners( );

   delete this;
}

void list_mutex_lock_ids_for_peer_session( std::ostream& outs )
{
   outs << "peer_session::g_mutex = " << g_mutex.get_lock_id( ) << '\n';
}

string use_peer_account( const string& blockchain, const string& password, bool release, bool is_pwd_hash )
{
   guard g( get_core_files_trace_mutex( ), "use_peer_account" );

   string retval;

   if( password.empty( ) )
   {
      if( g_blockchain_passwords.count( blockchain ) )
      {
         set< string >& passwords( g_blockchain_passwords[ blockchain ] );

         if( !release )
         {
            set< string > account_ids;

            for( set< string >::iterator i = passwords.begin( ); i != passwords.end( ); ++i )
               account_ids.insert( check_account( blockchain, *i ) );

            for( set< string >::iterator i = account_ids.begin( ); i != account_ids.end( ); ++i )
            {
               if( !retval.empty( ) )
                  retval += '\n';

               retval += *i;
            }
         }
         else
         {
            for( set< string >::iterator i = passwords.begin( ); i != passwords.end( ); ++i )
               set_crypt_key_for_blockchain_account( blockchain, check_account( blockchain, *i ), "" );

            g_blockchain_release.insert( blockchain );
            g_blockchain_passwords.erase( blockchain );
         }
      }
   }
   else
   {
      if( release )
      {
         if( g_blockchain_passwords.count( blockchain ) )
         {
            string tmp_password( password );

            if( is_pwd_hash )
            {
               set< string >& passwords( g_blockchain_passwords[ blockchain ] );

               for( set< string >::iterator i = passwords.begin( ); i != passwords.end( ); ++i )
               {
                  if( sha256( *i ).get_digest_as_string( ) == password )
                  {
                     tmp_password = *i;
                     break;
                  }
               }
            }

            set_crypt_key_for_blockchain_account( blockchain, check_account( blockchain, tmp_password ), "" );

            g_blockchain_release.insert( blockchain );
            g_blockchain_passwords[ blockchain ].erase( tmp_password );
         }
      }
      else
      {
         retval = check_account( blockchain, password );
         g_blockchain_passwords[ blockchain ].insert( password );

         set_crypt_key_for_blockchain_account( blockchain,
          retval, sha256( password ).get_digest_as_string( ) );
      }
   }

   return retval;
}

string get_account_password( const string& blockchain, const string& account )
{
   guard g( get_core_files_trace_mutex( ), "get_account_password" );

   if( !g_blockchain_passwords.count( blockchain ) )
      throw runtime_error( "blockchain " + blockchain + " has not been unlocked" );

   string password;
   set< string >& passwords = g_blockchain_passwords[ blockchain ];

   string test_account( account == string( c_admin ) ? blockchain : account );

   for( set< string >::iterator i = passwords.begin( ); i != passwords.end( ); ++i )
   {
      if( check_account( blockchain, *i ) == test_account )
      {
         password = *i;
         break;
      }
   }

   if( password.empty( ) )
      throw runtime_error( "invalid or non-minting account " + account + " for blockchain " + blockchain );

   return password;
}

void lock_blockchain_transaction( auto_ptr< guard >& ap_guard )
{
   ap_guard.reset( new guard( get_core_files_trace_mutex( ), "lock_blockchain_transaction" ) );
}

string create_blockchain_transaction( const string& blockchain,
 const string& application, const string& log_command, const vector< string >* p_file_info )
{
   guard g( get_core_files_trace_mutex( ), "create_blockchain_transaction" );

   if( !g_blockchain_passwords.count( blockchain ) )
      throw runtime_error( "blockchain " + blockchain + " has not been unlocked" );

   string::size_type pos = log_command.find( ' ' );
   if( pos == string::npos )
      throw runtime_error( "invalid log command format: " + log_command );

   string cmd( log_command.substr( 0, pos ) );
   string remaining( log_command.substr( pos + 1 ) );

   pos = remaining.find( ' ' );
   if( pos == string::npos )
      throw runtime_error( "invalid log command format: " + log_command );

   string account = remaining.substr( 0, pos );
   remaining.erase( 0, pos );

   string password( get_account_password( blockchain, account ) );

   string tx_hash;

   string tx_data( construct_new_transaction( blockchain,
    password, account, application, cmd + remaining, true, &tx_hash, p_file_info ) );

   vector< pair< string, string > > extras;

   verify_core_file( tx_data, true, &extras );
   create_raw_file_with_extras( "", extras );

   construct_blockchain_info_file( blockchain );

   return tx_hash;
}

void create_peer_listener( int port, const string& blockchain )
{
   if( !has_registered_listener( port ) )
   {
#ifdef __GNUG__
      if( port < 1025 )
         throw runtime_error( "invalid attempt to use port number less than 1025" );
#endif
      if( !blockchain.empty( ) )
         register_blockchain( port, blockchain );

      peer_listener* p_peer_listener = new peer_listener( port, blockchain );
      p_peer_listener->start( );
   }
}

void create_peer_initiator( int port, const string& ip_addr,
 const string& blockchain, bool force, size_t num_for_support )
{
   if( !force && !blockchain.empty( ) )
      register_blockchain( port, blockchain );

   if( g_server_shutdown || has_max_peers( ) )
      throw runtime_error( "server is shutting down or has reached its maximum peer limit" );

   if( num_for_support > c_max_num_for_support )
      throw runtime_error( "cannot create " + to_string( num_for_support )
       + " sessions for support (max is " + to_string( c_max_num_for_support ) + ")" );

   size_t total_to_create = 1 + num_for_support;

   peer_session* p_main_session = 0;
   size_t num_supporters_created = 0;

   for( size_t i = 0; i < total_to_create; i++ )
   {
#ifdef SSL_SUPPORT
      auto_ptr< ssl_socket > ap_socket( new ssl_socket );
#else
      auto_ptr< tcp_socket > ap_socket( new tcp_socket );
#endif

      if( ap_socket->open( ) )
      {
         ip_address address( ip_addr.c_str( ), port );

         if( force )
            remove_peer_ip_addr_from_rejection( address.get_addr_string( ) );
         else if( !get_is_accepted_peer_ip_addr( address.get_addr_string( ) ) )
            throw runtime_error( "ip address " + ip_addr + " is not permitted" );

         if( ap_socket->connect( address, c_initial_timeout ) )
         {
            peer_session* p_session = construct_session( false, ap_socket, address.get_addr_string( )
             + "=" + ( !blockchain.empty( ) ? blockchain : get_blockchain_for_port( port ) ) + ":" + to_string( port ), i > 0 );

            if( !p_session )
               break;
            else
            {
               if( !p_main_session )
                  p_main_session = p_session;

               p_session->start( );

               if( i > 0 )
                  ++num_supporters_created;
            }
         }
      }
   }

   if( !blockchain.empty( ) && p_main_session && num_supporters_created )
      set_system_variable( blockchain + c_supporters_suffix, c_true );
}

void create_initial_peer_sessions( )
{
   map< string, string > initial_ips;
   get_initial_peer_ips( initial_ips );

   for( map< string, string >::iterator i = initial_ips.begin( ); i!= initial_ips.end( ); ++i )
   {
      string ip_addr( i->first );

      string blockchain( i->second );

      int port = 0;

      // NOTE: A specific port can be provided if an initial peer
      // is not using the standard port for that blockchain.
      string::size_type pos = blockchain.find( ':' );
      if( pos != string::npos )
      {
         port = atoi( blockchain.substr( pos + 1 ).c_str( ) );
         blockchain.erase( pos );
      }
      else
         port = get_blockchain_port( blockchain );

      if( !get_is_accepted_peer_ip_addr( ip_addr ) )
         continue;

      if( g_server_shutdown || has_max_peers( ) )
         break;

#ifdef SSL_SUPPORT
      auto_ptr< ssl_socket > ap_socket( new ssl_socket );
#else
      auto_ptr< tcp_socket > ap_socket( new tcp_socket );
#endif

      if( ap_socket->open( ) )
      {
         ip_address address( ip_addr.c_str( ), port );

         if( ap_socket->connect( address ) )
         {
            peer_session* p_session = construct_session( false,
             ap_socket, address.get_addr_string( ) + "=" + blockchain + ":" + to_string( port ) );

            if( p_session )
               p_session->start( );
         }
      }
   }
}

void init_peer_sessions( int start_listeners )
{
   if( start_listeners )
   {
      int test_peer_port = get_test_peer_port( );

      if( test_peer_port > 0 )
         create_peer_listener( test_peer_port, "" );

      map< int, string > blockchains;
      get_blockchains( blockchains );

      for( map< int, string >::iterator i = blockchains.begin( ); i != blockchains.end( ); ++i )
         create_peer_listener( i->first, i->second );
   }

   create_initial_peer_sessions( );
}
