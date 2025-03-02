// Copyright (c) 2013-2022 CIYAM Developers
//
// Distributed under the MIT/X11 software license, please refer to the file license.txt
// in the root project directory or http://www.opensource.org/licenses/mit-license.php.

#ifndef CIYAM_CONSTANTS_H
#  define CIYAM_CONSTANTS_H

const int c_tx_id_module = 1;
const int c_tx_id_initial = 2;
const int c_tx_id_standard = 5;

const size_t c_bc_identity_length = 9;

const char* const c_none = "none";
const char* const c_okay = "okay";

const char* const c_true = "true";
const char* const c_false = "false";

const char* const c_dummy = "dummy";

const char* const c_ciyam_tag = "ciyam";

const char* const c_log_file_ext = ".log";
const char* const c_txs_file_ext = ".txs";

const char* const c_ciyam_script = "ciyam_script";
const char* const c_ciyam_server = "ciyam_server";

const char* const c_variables_branch = "Variables";
const char* const c_web_files_branch = "Web_Files";

const char* const c_meta_model_name = "Meta";

const char* const c_meta_class_name_class = "Class";
const char* const c_meta_class_name_model = "Model";
const char* const c_meta_class_name_application = "Application";

const char* const c_ignore_field = "@ignore";

const char* const c_local_ip_addr = "127.0.0.1";
const char* const c_local_ip_addr_for_ipv6 = "::1";

const char* const c_timezones_file = "timezones.sio";
const char* const c_autoscript_file = "autoscript.sio";
const char* const c_manuscript_file = "manuscript.sio";

const char* const c_file_zero_length = "*";

const char* const c_file_archives_folder = "arch";
const char* const c_file_blacklist_folder = "blst";
const char* const c_file_repository_folder = "repo";
const char* const c_system_variables_folder = "vars";

const char* const c_file_repository_meta_data_line_prefix = "md:";
const char* const c_file_repository_public_key_line_prefix = "pk:";
const char* const c_file_repository_source_hash_line_prefix = "sh:";
const char* const c_file_repository_target_hash_line_prefix = "th:";

const char* const c_file_repository_meta_data_info_type_raw = "raw";

const char* const c_file_repository_local_hash_attribute = "local_hash";

const char* const c_storage_identity_tx_id = "[0]";

const char* const c_block_prefix = "block";
const char* const c_files_directory = "files";

const char* const c_file_copy_command = "file_copy";
const char* const c_file_kill_command = "file_kill";

const char* const c_application_script_prefix = "app_script:";

const size_t c_file_transfer_line_timeout = 5000; // i.e. 5 secs
const size_t c_file_transfer_initial_timeout = 20000; // i.e. 20 secs

const size_t c_file_transfer_max_line_size = 100000; // i.e. 100K

const size_t c_files_area_item_max_num_default = 100000; // i.e. 100K
const size_t c_files_area_item_max_size_default = 1000000; // i.e. 1MB

const int c_file_type_val_blob = 0x01;
const int c_file_type_val_list = 0x02;

const int c_file_type_val_mask = 0x03;

const int c_file_type_val_encrypted = 0x04;
const int c_file_type_val_compressed = 0x08;

const int c_file_type_val_extra_core = 0x10;
const int c_file_type_val_extra_mime = 0x20;

const int c_file_type_val_extra_mask = 0x30;

const int c_file_type_val_no_encrypt = 0x40;
const int c_file_type_val_no_compress = 0x80;

const char c_file_type_char_blob = '\x01';
const char c_file_type_char_list = '\x02';

const char c_file_type_char_core_blob = '\x11';
const char c_file_type_char_core_list = '\x12';

const char c_file_type_char_mime_blob = '\x21';

const char c_file_type_char_encrypted = '\x04';
const char c_file_type_char_compressed = '\x08';

const char c_file_type_char_blob_compressed = '\x09';
const char c_file_type_char_list_compressed = '\x0a';

const char c_file_type_char_blob_no_compress = '\x81';

const char c_file_type_char_core_blob_compressed = '\x19';
const char c_file_type_char_core_list_compressed = '\x1a';

const char c_file_type_char_mime_blob_compressed = '\x29';

const char* const c_file_type_str_blob = "\x01";
const char* const c_file_type_str_list = "\x02";

const char* const c_file_type_str_core_blob = "\x11";
const char* const c_file_type_str_core_list = "\x12";

const char* const c_file_type_str_blob_encrypted = "\x05";
const char* const c_file_type_str_blob_no_compress = "\x81";

const char* const c_file_type_core_data_object = "dat";
const char* const c_file_type_core_block_object = "blk";
const char* const c_file_type_core_rewind_object = "rwd";
const char* const c_file_type_core_account_object = "acc";
const char* const c_file_type_core_checkpoint_object = "chk";
const char* const c_file_type_core_transaction_object = "txn";
const char* const c_file_type_core_blockchain_info_object = "bci";
const char* const c_file_type_core_blockchain_meta_object = "bcm";
const char* const c_file_type_core_checkpoint_info_object = "cpi";
const char* const c_file_type_core_checkpoint_prune_object = "cpr";
const char* const c_file_type_core_checkpoint_blocks_object = "cbk";
const char* const c_file_type_core_transactions_info_object = "txi";
const char* const c_file_type_core_checkpoint_transactions_object = "ctx";

const char* const c_file_type_core_data_header_height_prefix = "h=";
const char* const c_file_type_core_data_header_identity_prefix = "i=";

const char* const c_file_type_core_data_detail_last_hash_prefix = "l:";
const char* const c_file_type_core_data_detail_pubkey_hash_prefix = "p:";
const char* const c_file_type_core_data_detail_tree_root_hash_prefix = "t:";
const char* const c_file_type_core_data_detail_unix_time_stamp_prefix = "u:";

const char* const c_file_type_core_block_header_height_prefix = "h=";
const char* const c_file_type_core_block_header_weight_prefix = "w=";
const char* const c_file_type_core_block_header_account_prefix = "a=";
const char* const c_file_type_core_block_header_chain_meta_prefix = "cm=";
const char* const c_file_type_core_block_header_public_key_prefix = "pk=";
const char* const c_file_type_core_block_header_account_hash_prefix = "ah=";
const char* const c_file_type_core_block_header_account_lock_prefix = "al=";
const char* const c_file_type_core_block_header_total_weight_prefix = "tw=";
const char* const c_file_type_core_block_header_previous_block_prefix = "pb=";

const char* const c_file_type_core_block_detail_account_prefix = "a:";
const char* const c_file_type_core_block_detail_signature_prefix = "s:";
const char* const c_file_type_core_block_detail_transaction_prefix = "t:";
const char* const c_file_type_core_block_detail_proof_of_work_prefix = "w:";

const char* const c_file_type_core_block_header_chain_meta_requisite_prefix = "r:";

const char* const c_file_type_core_block_detail_account_exp_prefix = "e=";
const char* const c_file_type_core_block_detail_account_hash_prefix = "h=";
const char* const c_file_type_core_block_detail_account_lock_prefix = "l=";
const char* const c_file_type_core_block_detail_account_msg_key_prefix = "mk=";
const char* const c_file_type_core_block_detail_account_tx_hash_prefix = "th=";
const char* const c_file_type_core_block_detail_account_tx_lock_prefix = "tl=";

const char* const c_file_type_core_lamport_header_height_prefix = "h=";
const char* const c_file_type_core_lamport_header_identity_prefix = "i=";

const char* const c_file_type_core_lamport_detail_last_hash_prefix = "l:";
const char* const c_file_type_core_lamport_detail_pubkey_hash_prefix = "p:";
const char* const c_file_type_core_lamport_detail_primary_pubkey_prefix = "p:";
const char* const c_file_type_core_lamport_detail_secondary_pubkey_prefix = "s:";
const char* const c_file_type_core_lamport_detail_signature_file_hash_prefix = "s:";
const char* const c_file_type_core_lamport_detail_unix_block_time_stamp_prefix = "u:";

const char* const c_file_type_core_transaction_header_account_prefix = "a=";
const char* const c_file_type_core_transaction_header_sequence_prefix = "s=";
const char* const c_file_type_core_transaction_header_public_key_prefix = "pk=";
const char* const c_file_type_core_transaction_header_application_prefix = "ap=";
const char* const c_file_type_core_transaction_header_previous_tchain_prefix = "pt=";
const char* const c_file_type_core_transaction_header_transaction_hash_prefix = "th=";
const char* const c_file_type_core_transaction_header_transaction_lock_prefix = "tl=";

const char* const c_file_type_core_transaction_detail_log_prefix = "l:";
const char* const c_file_type_core_transaction_detail_signature_prefix = "s:";

const char* const c_file_type_core_transaction_special_file_extract_prefix = "fe ";
const char* const c_file_type_core_transaction_special_file_extract_command = "fe";
const char* const c_file_type_core_transaction_special_perform_create_command = "pc";
const char* const c_file_type_core_transaction_special_perform_update_command = "pu";
const char* const c_file_type_core_transaction_special_perform_destroy_command = "pd";
const char* const c_file_type_core_transaction_special_perform_execute_command = "pe";

const char* const c_file_type_core_blockchain_info_header_chain_prefix = "c=";
const char* const c_file_type_core_blockchain_info_header_height_prefix = "h=";

const char* const c_file_type_core_checkpoint_info_header_chain_prefix = "c=";
const char* const c_file_type_core_checkpoint_info_header_height_prefix = "h=";
const char* const c_file_type_core_checkpoint_info_header_checkpoint_prefix = "cp=";

const char* const c_file_type_core_transactions_info_header_chain_prefix = "c=";

const char* const c_sys = "sys";
const char* const c_auto = "auto";
const char* const c_init = "init";
const char* const c_admin = "admin";

const char* const c_both = "both";
const char* const c_create = "create";
const char* const c_update = "update";

const char* const c_anyone = "anyone";
const char* const c_admin_only = "admin_only";
const char* const c_owner_only = "owner_only";
const char* const c_admin_owner = "admin_owner";
const char* const c_denied_always = "denied_always";

const char* const c_user_class_suffix = "_user_class";

const char* const c_response_okay = "(okay)";
const char* const c_response_okay_more = "(okay more)";
const char* const c_response_okay_skip = "(okay skip)";

const char* const c_response_not_found = "(not found)";

const char* const c_response_error_prefix = "(error)";
const char* const c_response_message_prefix = "(message)";

#endif

