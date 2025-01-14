// Copyright (c) 2013-2022 CIYAM Developers
//
// Distributed under the MIT/X11 software license, please refer to the file license.txt
// in the root project directory or http://www.opensource.org/licenses/mit-license.php.

#ifndef CIYAM_FILES_H
#  define CIYAM_FILES_H

#  ifndef HAS_PRECOMPILED_STD_HEADERS
#     include <iosfwd>
#     include <deque>
#     include <string>
#     include <vector>
#  endif

#  include "ptypes.h"
#  include "ciyam_common.h"

#  ifdef CIYAM_BASE_IMPL
#     define CIYAM_BASE_DECL_SPEC DYNAMIC_EXPORT
#  else
#     define CIYAM_BASE_DECL_SPEC DYNAMIC_IMPORT
#  endif

struct progress;

class date_time;
class tcp_socket;

void CIYAM_BASE_DECL_SPEC list_mutex_lock_ids_for_ciyam_files( std::ostream& outs );

size_t CIYAM_BASE_DECL_SPEC get_total_files( );
int64_t CIYAM_BASE_DECL_SPEC get_total_bytes( );

std::string CIYAM_BASE_DECL_SPEC get_file_stats( );

void CIYAM_BASE_DECL_SPEC init_files_area( progress* p_progress = 0, bool remove_invalid_tags = false );

void CIYAM_BASE_DECL_SPEC resync_files_area( progress* p_progress = 0, bool remove_invalid_tags = false );

void CIYAM_BASE_DECL_SPEC term_files_area( );

std::string CIYAM_BASE_DECL_SPEC current_time_stamp_tag( bool truncated = false, size_t days_ahead = 0 );

bool CIYAM_BASE_DECL_SPEC has_tag( const std::string& name, file_type type = e_file_type_any );

bool CIYAM_BASE_DECL_SPEC has_file( const std::string& hash, bool check_is_hash = true );

bool CIYAM_BASE_DECL_SPEC is_list_file( const std::string& hash );

int64_t CIYAM_BASE_DECL_SPEC file_bytes( const std::string& hash, bool blobs_for_lists = false );

enum file_expansion
{
   e_file_expansion_none,
   e_file_expansion_content,
   e_file_expansion_recursive,
   e_file_expansion_recursive_hashes
};

std::string CIYAM_BASE_DECL_SPEC file_type_info(
 const std::string& tag_or_hash,
 file_expansion expansion = e_file_expansion_none, int max_depth = 0,
 int indent = 0, bool add_size = false, const char* p_prefix = 0,
 bool allow_all_after = true, bool output_total_blob_size = false,
 progress* p_progress = 0, date_time* p_dtm = 0, size_t* p_total = 0 );

std::string CIYAM_BASE_DECL_SPEC create_raw_file(
 const std::string& data, bool compress = true, const char* p_tag = 0,
 bool* p_is_existing = 0, const char* p_hash = 0, bool allow_uncompress = true );

std::string CIYAM_BASE_DECL_SPEC create_raw_file_with_extras( const std::string& data,
 std::vector< std::pair< std::string, std::string > >& extras, bool compress = true, const char* p_tag = 0 );

std::string CIYAM_BASE_DECL_SPEC create_list_file( const std::string& add_tags, const std::string& del_items,
 bool sort_items, const std::string& tag_or_hash, const std::string& new_tag, const std::string& old_tag );

std::string CIYAM_BASE_DECL_SPEC create_list_tree( const std::string& add_tags, const std::string& del_items,
 bool sort_items, const std::string& tag_and_branches, const std::string& new_tag, const std::string& old_tag );

void CIYAM_BASE_DECL_SPEC tag_del(
 const std::string& name, bool unlink = false, bool auto_tag_with_time = true );

void CIYAM_BASE_DECL_SPEC tag_file( const std::string& name,
 const std::string& hash, bool skip_tag_del = false, bool is_external = false );

std::string CIYAM_BASE_DECL_SPEC get_hash_tags( const std::string& hash );

std::string CIYAM_BASE_DECL_SPEC tag_file_hash( const std::string& name, bool* p_rc = 0 );

std::string CIYAM_BASE_DECL_SPEC extract_tags_from_lists(
 const std::string& tag_or_hash, const std::string& prefix,
 int depth = 1, int level = 0, progress* p_progress = 0, date_time* p_dtm = 0, size_t* p_total = 0 );

std::string CIYAM_BASE_DECL_SPEC list_file_tags(
 const std::string& pat, const char* p_excludes = 0,
 size_t max_tags = 0, int64_t max_bytes = 0, int64_t* p_min_bytes = 0,
 std::deque< std::string >* p_hashes = 0, bool include_multiples = true,
 progress* p_progress = 0, date_time* p_dtm = 0 );

void CIYAM_BASE_DECL_SPEC remove_file_tags( const std::string& hash, const std::string& pat );

std::string CIYAM_BASE_DECL_SPEC hash_with_nonce( const std::string& hash, const std::string& nonce );

enum crypt_target
{
   e_crypt_target_all,
   e_crypt_target_blobs_only,
   e_crypt_target_blobs_only_repo
};

void CIYAM_BASE_DECL_SPEC crypt_file( const std::string& tag_or_hash,
 const std::string& password, bool recurse = false, crypt_target target = e_crypt_target_all,
 progress* p_progress = 0, date_time* p_dtm = 0, size_t* p_total = 0, bool recrypt = false );

void CIYAM_BASE_DECL_SPEC fetch_file( const std::string& hash, tcp_socket& socket, progress* p_progress = 0 );

bool CIYAM_BASE_DECL_SPEC store_file( const std::string& hash,
 tcp_socket& socket, const char* p_tag = 0, progress* p_progress = 0,
 bool allow_core_file = true, size_t max_bytes = 0, bool allow_missing_items = false, std::string* p_file_data = 0 );

void CIYAM_BASE_DECL_SPEC delete_file( const std::string& hash, bool even_if_tagged = true, bool ignore_not_found = false );

void CIYAM_BASE_DECL_SPEC delete_file_tree( const std::string& hash, progress* p_progress = 0 );

void CIYAM_BASE_DECL_SPEC delete_files_for_tags( const std::string& pat, progress* p_progress = 0 );

void CIYAM_BASE_DECL_SPEC copy_raw_file( const std::string& hash, const std::string& dest_file_name );

void CIYAM_BASE_DECL_SPEC fetch_temp_file(
 const std::string& name, tcp_socket& socket, progress* p_progress = 0 );

void CIYAM_BASE_DECL_SPEC store_temp_file(
 const std::string& name, tcp_socket& socket, progress* p_progress = 0, bool is_existing = false );

bool CIYAM_BASE_DECL_SPEC temp_file_is_identical( const std::string& temp_name, const std::string& hash );

std::string CIYAM_BASE_DECL_SPEC extract_file( const std::string& hash,
 const std::string& dest_file_name, unsigned char check_file_type_and_extra = '\0',
 bool* p_is_list = 0, unsigned char* p_type_and_extra = 0, bool* p_is_encrypted = 0, bool set_is_encrypted = false );

void CIYAM_BASE_DECL_SPEC add_file_archive(
 const std::string& name, const std::string& path, int64_t size_limit );

void CIYAM_BASE_DECL_SPEC remove_file_archive( const std::string& name, bool destroy_files = false );
void CIYAM_BASE_DECL_SPEC repair_file_archive( const std::string& name );

void CIYAM_BASE_DECL_SPEC archives_status_update( const std::string& name );

bool CIYAM_BASE_DECL_SPEC file_has_been_blacklisted( const std::string& hash );

std::string CIYAM_BASE_DECL_SPEC list_file_archives( bool minimal = false,
 std::vector< std::string >* p_paths = 0, int64_t min_avail = 0, bool stop_after_first = false );

std::string CIYAM_BASE_DECL_SPEC relegate_time_stamped_files( const std::string& hash,
 const std::string& archive, uint32_t max_files, int64_t max_bytes, bool delete_files_always = false );

bool CIYAM_BASE_DECL_SPEC has_file_been_archived( const std::string& hash );

std::string CIYAM_BASE_DECL_SPEC retrieve_file_from_archive(
 const std::string& hash, const std::string& tag, size_t days_ahead = 0 );

void CIYAM_BASE_DECL_SPEC delete_file_from_archive(
 const std::string& hash, const std::string& archive, bool add_to_blacklist = false );

#endif

