// Copyright (c) 2003-2012 CIYAM Pty. Ltd. ACN 093 704 539
// Copyright (c) 2012-2022 CIYAM Developers
//
// Distributed under the MIT/X11 software license, please refer to the file license.txt
// in the root project directory or http://www.opensource.org/licenses/mit-license.php.

#ifndef CONSOLE_H
#  define CONSOLE_H

#  ifndef HAS_PRECOMPILED_STD_HEADERS
#     include <string>
#  endif

bool is_stdout_console( );

char get_char( const char* p_prompt = 0, bool flush_input = true );

inline char get_char( const std::string& prompt, bool flush_input = true )
{
   return get_char( prompt.c_str( ), flush_input );
}

void get_line( std::string& s, const char* p_prompt = 0, bool use_cin = true );

inline std::string get_line( const char* p_prompt = 0, bool use_cin = true )
{
   std::string s;
   get_line( s, p_prompt, use_cin );

   return s;
}

std::string get_password( const char* p_prompt = 0, char* p_buf = 0, size_t buflen = 0 );

inline std::string get_password( const std::string& prompt, char* p_buf = 0, size_t buflen = 0 )
{
   return get_password( prompt.c_str( ) );
}

void put_line( const char* p_chars, size_t len );

inline void put_line( const std::string& str )
{
   put_line( &str[ 0 ], str.length( ) );
}

#endif

