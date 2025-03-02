// Copyright (c) 2010-2012 CIYAM Pty. Ltd. ACN 093 704 539
// Copyright (c) 2012-2022 CIYAM Developers
//
// Distributed under the MIT/X11 software license, please refer to the file license.txt
// in the root project directory or http://www.opensource.org/licenses/mit-license.php.

#ifndef CRYPT_STREAM_H
#  define CRYPT_STREAM_H

#  ifndef HAS_PRECOMPILED_STD_HEADERS
#     include <iosfwd>
#     include <string>
#  endif

#  include "config.h"
#  include "ptypes.h"

void crypt_stream( std::iostream& io, const char* p_key, size_t key_length );

inline void crypt_stream( std::iostream& io, const std::string& key )
{
   crypt_stream( io, key.c_str( ), key.length( ) );
}

#  ifdef SSL_SUPPORT
enum crypt_op
{
   e_crypt_op_encrypt,
   e_crypt_op_decrypt
};

void aes_crypt( std::string& o, const std::string& s,
 const char* p_key, size_t key_length, crypt_op op, bool use_256 = true );

inline std::string aes_crypt( const std::string& s,
 const char* p_key, size_t key_length, crypt_op op, bool use_256 = true )
{
   std::string o;
   aes_crypt( o, s, p_key, key_length, op, use_256 );

   return o;
}
#  endif

std::string get_totp( const std::string& base32_encoded_secret, int freq = 30 );

std::string get_totp_secret( const std::string& user_unique, const std::string& system_unique );

void data_decrypt( std::string& s, const std::string& dat, const std::string& key, bool use_ssl = true );

inline std::string data_decrypt( const std::string& dat, const std::string& key, bool use_ssl = true )
{
   std::string s;
   data_decrypt( s, dat, key, use_ssl );

   return s;
}

void data_encrypt( std::string& s, const std::string& dat,
 const std::string& key, bool use_ssl = true, bool add_salt = true );

inline std::string data_encrypt( const std::string& dat,
 const std::string& key, bool use_ssl = true, bool add_salt = true )
{
   std::string s;
   data_encrypt( s, dat, key, use_ssl, add_salt );

   return s;
}

void harden_key_with_salt( std::string& s, const std::string& key, const std::string& salt );

inline std::string harden_key_with_salt( const std::string& key, const std::string& salt )
{
   std::string s;
   harden_key_with_salt( s, key, salt );

   return s;
}

enum nonce_difficulty
{
   e_nonce_difficulty_none,
   e_nonce_difficulty_easy,
   e_nonce_difficulty_hard,
   e_nonce_difficulty_most
};

std::string check_for_proof_of_work(
 const std::string& data, uint32_t start, uint32_t range = 1,
 nonce_difficulty difficulty = e_nonce_difficulty_easy, bool pause_between_passes = true );

#endif

