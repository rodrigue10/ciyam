// Copyright (c) 2011
//
// CIYAM Pty. Ltd.
// ACN 093 704 539
//
// ALL RIGHTS RESERVED
//
// Permission to use this software for non-commercial purposes is hereby granted. Permission to
// distribute this software privately is granted provided that the source code is unaltered and
// complete or that any alterations and omissions have been first approved by CIYAM. Commercial
// usage of this software is not permitted without first obtaining a license for such a purpose
// from CIYAM. This software may not be publicly distributed unless written permission to do so
// has been obtained from CIYAM.

#ifdef __BORLANDC__
#  include "precompile.h"
#endif
#pragma hdrstop

#ifndef HAS_PRECOMPILED_STD_HEADERS
#  include <string>
#  include <vector>
#  include <fstream>
#  include <iostream>
#  include <stdexcept>
#endif

#include "utilities.h"

using namespace std;

const char* const c_section_prefix = "### ";
const char* const c_outline_extension = ".outline";

int main( int argc, char* argv[ ] )
{
   if( argc < 2 || argc > 4 )
   {
      cout << "Usage: construct [@<package.lst>] <target>" << endl;
      return 0;
   }

   try
   {
      int arg_num = 1;
      vector< string > packages;
      map< string, vector< string > > package_details;

      if( argc > 2 )
         buffer_file_lines( string( argv[ arg_num++ ] ).substr( 1 ), packages );

      string outline_filename( argv[ arg_num ] );
      outline_filename += c_outline_extension;

      ifstream inpf( outline_filename.c_str( ) );
      if( !inpf )
         throw runtime_error( "unable to open '" + outline_filename + "' for input" );

      string target_filename( argv[ arg_num ] );
      for( size_t i = 0; i < packages.size( ); i++ )
      {
         string package_filename( packages[ i ] + "." + target_filename );
         if( file_exists( package_filename ) )
         {
            vector< string > details;
            buffer_file_lines( package_filename, details );

            package_details.insert( make_pair( packages[ i ], details ) );
         }
      }

      ofstream outf( target_filename.c_str( ) );
      if( !outf )
         throw runtime_error( "unable to open '" + target_filename + "' for output" );

      string next;
      while( getline( inpf, next ) )
      {
         if( !next.empty( ) && !packages.empty( ) )
         {
            string::size_type pos = next.find( c_section_prefix );
            if( pos == 0 )
            {
               for( size_t i = 0; i < packages.size( ); i++ )
               {
                  if( package_details.count( packages[ i ] ) )
                  {
                     bool found_matching = false;
                     for( size_t j = 0; j < package_details[ packages[ i ] ].size( ); j++ )
                     {
                        pos = package_details[ packages[ i ] ][ j ].find( c_section_prefix );
                        if( pos == 0 )
                        {
                           if( package_details[ packages[ i ] ][ j ] == next )
                              found_matching = true;
                           else
                              found_matching = false;
                        }
                        else if( found_matching )
                           outf << package_details[ packages[ i ] ][ j ] << '\n';
                     }
                  }
               }

               continue;
            }
         }

         outf << next << '\n';
      }

      if( !inpf.eof( ) )
         throw runtime_error( "unexpected error occurred whilst reading '" + outline_filename + "'" );

      outf.flush( );
      if( !outf.good( ) )
         throw runtime_error( "unexpected error occurred whilst writing '" + target_filename + "'" );

      cout << "Constructed: " << target_filename << endl;
   }
   catch( exception& x )
   {
      cerr << "error: " << x.what( ) << endl;
      return 1;
   }
   catch( ... )
   {
      cerr << "unexpected exception occurred..." << endl;
      return 2;
   }
}
