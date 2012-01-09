// Copyright (c) 2008
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
#  include <cstring>
#  include <fstream>
#  include <iostream>
#  include <algorithm>
#  include <stdexcept>
#endif

#define CAT_BASE_LIB
#define MODULE_META_IMPL

// [<start macros>]
// [<finish macros>]

#include "Meta_Specification.h"

#include "Meta_List_Field.h"
#include "Meta_View_Field.h"
#include "Meta_Class.h"
#include "Meta_Relationship.h"
#include "Meta_Specification_Type.h"
#include "Meta_Enum.h"
#include "Meta_Enum_Item.h"
#include "Meta_Field.h"
#include "Meta_Model.h"
#include "Meta_Modifier.h"
#include "Meta_Procedure.h"
#include "Meta_Specification.h"
#include "Meta_Specification_Copy_Child_Links.h"
#include "Meta_Permission.h"
#include "Meta_Procedure_Arg.h"

#include "cat_base.h"
#include "class_domains.h"
#include "module_strings.h"
#include "class_utilities.h"
#include "command_handler.h"
#include "module_interface.h"

// [(start copy_child_links_from_fk)]
#include "Meta_Specification_Type.h"
// [(finish copy_child_links_from_fk)]

// [<start includes>]
// [<finish includes>]

using namespace std;

// [<start namespaces>]
// [<finish namespaces>]

template< > inline string to_string( const Meta_Class& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Relationship& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Specification_Type& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Enum& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Enum_Item& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Field& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Model& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Modifier& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Procedure& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Specification& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Specification_Copy_Child_Links& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Permission& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

template< > inline string to_string( const Meta_Procedure_Arg& c )
{
   return ::to_string( static_cast< const class_base& >( c ) );
}

inline void from_string( Meta_Class& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Relationship& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Specification_Type& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Enum& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Enum_Item& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Field& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Model& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Modifier& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Procedure& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Specification& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Specification_Copy_Child_Links& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Permission& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline void from_string( Meta_Procedure_Arg& c, const string& s )
{
   ::from_string( static_cast< class_base& >( c ), s );
}

inline int system( const string& cmd ) { return exec_system( cmd ); }

namespace
{

#include "Meta_Specification.cmh"

const int32_t c_version = 1;

const char* const c_okay = "okay";

const char* const c_field_id_Actions = "115108";
const char* const c_field_id_All_Strings = "115124";
const char* const c_field_id_All_Vars = "115123";
const char* const c_field_id_Child_Rel_Child_Class = "301491";
const char* const c_field_id_Child_Rel_Field_Key = "115121";
const char* const c_field_id_Child_Relationship = "301475";
const char* const c_field_id_Child_Specification_Type = "301406";
const char* const c_field_id_Class = "301420";
const char* const c_field_id_Comments = "115112";
const char* const c_field_id_Enum = "301460";
const char* const c_field_id_Enum_Item = "301470";
const char* const c_field_id_Enum_Item_2 = "301471";
const char* const c_field_id_Enum_Item_3 = "301472";
const char* const c_field_id_Enum_Item_4 = "301473";
const char* const c_field_id_Enum_Item_5 = "301474";
const char* const c_field_id_Field = "301430";
const char* const c_field_id_Field_Class = "301492";
const char* const c_field_id_Field_Pairs = "115120";
const char* const c_field_id_Field_Values = "115113";
const char* const c_field_id_Fields = "115126";
const char* const c_field_id_Id = "115117";
const char* const c_field_id_Is_Required_For_UI_Gen = "115128";
const char* const c_field_id_Model = "301400";
const char* const c_field_id_Modifier = "301440";
const char* const c_field_id_Name = "115101";
const char* const c_field_id_Options = "115104";
const char* const c_field_id_Order = "115105";
const char* const c_field_id_Other_Class = "301421";
const char* const c_field_id_Other_Field = "301435";
const char* const c_field_id_Other_Field_2 = "301436";
const char* const c_field_id_Other_Procedure = "301451";
const char* const c_field_id_Other_Procedure_2 = "301452";
const char* const c_field_id_Parent_Specification = "301405";
const char* const c_field_id_Parent_Specification_Copy_Child_Links = "302550";
const char* const c_field_id_Permission = "301499";
const char* const c_field_id_Procedure = "301450";
const char* const c_field_id_Procedure_Arg = "301498";
const char* const c_field_id_Procedure_Arg_2 = "301477";
const char* const c_field_id_Procedure_Arg_3 = "301478";
const char* const c_field_id_Protect_Child_Rel = "115122";
const char* const c_field_id_Protect_Procedure = "115115";
const char* const c_field_id_Protect_Source_Parent = "115111";
const char* const c_field_id_Restrict_Values = "115118";
const char* const c_field_id_Source_Child = "301495";
const char* const c_field_id_Source_Child_2 = "301496";
const char* const c_field_id_Source_Child_Class = "301489";
const char* const c_field_id_Source_Class = "301494";
const char* const c_field_id_Source_Field = "301481";
const char* const c_field_id_Source_Field_Class = "301482";
const char* const c_field_id_Source_Grandchild = "301476";
const char* const c_field_id_Source_Parent = "301480";
const char* const c_field_id_Source_Parent_Class = "301490";
const char* const c_field_id_Specification_Type = "301410";
const char* const c_field_id_Strings = "115119";
const char* const c_field_id_Test_Child = "301488";
const char* const c_field_id_Test_Field = "301485";
const char* const c_field_id_Test_Field_Class = "301493";
const char* const c_field_id_Test_Parent = "301486";
const char* const c_field_id_Test_Parent_Class = "301487";
const char* const c_field_id_Test_Value = "115103";
const char* const c_field_id_Use_Source_Parent = "115107";
const char* const c_field_id_Use_Test_Parent_Child = "115110";
const char* const c_field_id_Value = "115102";
const char* const c_field_id_Value_Left_Part = "115129";
const char* const c_field_id_Value_Literal = "115116";
const char* const c_field_id_Value_Numeric_String = "115127";
const char* const c_field_id_Value_Right_Part = "115130";
const char* const c_field_id_Value_String = "115125";
const char* const c_field_id_Vars = "115114";

const char* const c_field_name_Actions = "Actions";
const char* const c_field_name_All_Strings = "All_Strings";
const char* const c_field_name_All_Vars = "All_Vars";
const char* const c_field_name_Child_Rel_Child_Class = "Child_Rel_Child_Class";
const char* const c_field_name_Child_Rel_Field_Key = "Child_Rel_Field_Key";
const char* const c_field_name_Child_Relationship = "Child_Relationship";
const char* const c_field_name_Child_Specification_Type = "Child_Specification_Type";
const char* const c_field_name_Class = "Class";
const char* const c_field_name_Comments = "Comments";
const char* const c_field_name_Enum = "Enum";
const char* const c_field_name_Enum_Item = "Enum_Item";
const char* const c_field_name_Enum_Item_2 = "Enum_Item_2";
const char* const c_field_name_Enum_Item_3 = "Enum_Item_3";
const char* const c_field_name_Enum_Item_4 = "Enum_Item_4";
const char* const c_field_name_Enum_Item_5 = "Enum_Item_5";
const char* const c_field_name_Field = "Field";
const char* const c_field_name_Field_Class = "Field_Class";
const char* const c_field_name_Field_Pairs = "Field_Pairs";
const char* const c_field_name_Field_Values = "Field_Values";
const char* const c_field_name_Fields = "Fields";
const char* const c_field_name_Id = "Id";
const char* const c_field_name_Is_Required_For_UI_Gen = "Is_Required_For_UI_Gen";
const char* const c_field_name_Model = "Model";
const char* const c_field_name_Modifier = "Modifier";
const char* const c_field_name_Name = "Name";
const char* const c_field_name_Options = "Options";
const char* const c_field_name_Order = "Order";
const char* const c_field_name_Other_Class = "Other_Class";
const char* const c_field_name_Other_Field = "Other_Field";
const char* const c_field_name_Other_Field_2 = "Other_Field_2";
const char* const c_field_name_Other_Procedure = "Other_Procedure";
const char* const c_field_name_Other_Procedure_2 = "Other_Procedure_2";
const char* const c_field_name_Parent_Specification = "Parent_Specification";
const char* const c_field_name_Parent_Specification_Copy_Child_Links = "Parent_Specification_Copy_Child_Links";
const char* const c_field_name_Permission = "Permission";
const char* const c_field_name_Procedure = "Procedure";
const char* const c_field_name_Procedure_Arg = "Procedure_Arg";
const char* const c_field_name_Procedure_Arg_2 = "Procedure_Arg_2";
const char* const c_field_name_Procedure_Arg_3 = "Procedure_Arg_3";
const char* const c_field_name_Protect_Child_Rel = "Protect_Child_Rel";
const char* const c_field_name_Protect_Procedure = "Protect_Procedure";
const char* const c_field_name_Protect_Source_Parent = "Protect_Source_Parent";
const char* const c_field_name_Restrict_Values = "Restrict_Values";
const char* const c_field_name_Source_Child = "Source_Child";
const char* const c_field_name_Source_Child_2 = "Source_Child_2";
const char* const c_field_name_Source_Child_Class = "Source_Child_Class";
const char* const c_field_name_Source_Class = "Source_Class";
const char* const c_field_name_Source_Field = "Source_Field";
const char* const c_field_name_Source_Field_Class = "Source_Field_Class";
const char* const c_field_name_Source_Grandchild = "Source_Grandchild";
const char* const c_field_name_Source_Parent = "Source_Parent";
const char* const c_field_name_Source_Parent_Class = "Source_Parent_Class";
const char* const c_field_name_Specification_Type = "Specification_Type";
const char* const c_field_name_Strings = "Strings";
const char* const c_field_name_Test_Child = "Test_Child";
const char* const c_field_name_Test_Field = "Test_Field";
const char* const c_field_name_Test_Field_Class = "Test_Field_Class";
const char* const c_field_name_Test_Parent = "Test_Parent";
const char* const c_field_name_Test_Parent_Class = "Test_Parent_Class";
const char* const c_field_name_Test_Value = "Test_Value";
const char* const c_field_name_Use_Source_Parent = "Use_Source_Parent";
const char* const c_field_name_Use_Test_Parent_Child = "Use_Test_Parent_Child";
const char* const c_field_name_Value = "Value";
const char* const c_field_name_Value_Left_Part = "Value_Left_Part";
const char* const c_field_name_Value_Literal = "Value_Literal";
const char* const c_field_name_Value_Numeric_String = "Value_Numeric_String";
const char* const c_field_name_Value_Right_Part = "Value_Right_Part";
const char* const c_field_name_Value_String = "Value_String";
const char* const c_field_name_Vars = "Vars";

const char* const c_field_display_name_Actions = "field_specification_actions";
const char* const c_field_display_name_All_Strings = "field_specification_all_strings";
const char* const c_field_display_name_All_Vars = "field_specification_all_vars";
const char* const c_field_display_name_Child_Rel_Child_Class = "field_specification_child_rel_child_class";
const char* const c_field_display_name_Child_Rel_Field_Key = "field_specification_child_rel_field_key";
const char* const c_field_display_name_Child_Relationship = "field_specification_child_relationship";
const char* const c_field_display_name_Child_Specification_Type = "field_specification_child_specification_type";
const char* const c_field_display_name_Class = "field_specification_class";
const char* const c_field_display_name_Comments = "field_specification_comments";
const char* const c_field_display_name_Enum = "field_specification_enum";
const char* const c_field_display_name_Enum_Item = "field_specification_enum_item";
const char* const c_field_display_name_Enum_Item_2 = "field_specification_enum_item_2";
const char* const c_field_display_name_Enum_Item_3 = "field_specification_enum_item_3";
const char* const c_field_display_name_Enum_Item_4 = "field_specification_enum_item_4";
const char* const c_field_display_name_Enum_Item_5 = "field_specification_enum_item_5";
const char* const c_field_display_name_Field = "field_specification_field";
const char* const c_field_display_name_Field_Class = "field_specification_field_class";
const char* const c_field_display_name_Field_Pairs = "field_specification_field_pairs";
const char* const c_field_display_name_Field_Values = "field_specification_field_values";
const char* const c_field_display_name_Fields = "field_specification_fields";
const char* const c_field_display_name_Id = "field_specification_id";
const char* const c_field_display_name_Is_Required_For_UI_Gen = "field_specification_is_required_for_ui_gen";
const char* const c_field_display_name_Model = "field_specification_model";
const char* const c_field_display_name_Modifier = "field_specification_modifier";
const char* const c_field_display_name_Name = "field_specification_name";
const char* const c_field_display_name_Options = "field_specification_options";
const char* const c_field_display_name_Order = "field_specification_order";
const char* const c_field_display_name_Other_Class = "field_specification_other_class";
const char* const c_field_display_name_Other_Field = "field_specification_other_field";
const char* const c_field_display_name_Other_Field_2 = "field_specification_other_field_2";
const char* const c_field_display_name_Other_Procedure = "field_specification_other_procedure";
const char* const c_field_display_name_Other_Procedure_2 = "field_specification_other_procedure_2";
const char* const c_field_display_name_Parent_Specification = "field_specification_parent_specification";
const char* const c_field_display_name_Parent_Specification_Copy_Child_Links = "field_specification_parent_specification_copy_child_links";
const char* const c_field_display_name_Permission = "field_specification_permission";
const char* const c_field_display_name_Procedure = "field_specification_procedure";
const char* const c_field_display_name_Procedure_Arg = "field_specification_procedure_arg";
const char* const c_field_display_name_Procedure_Arg_2 = "field_specification_procedure_arg_2";
const char* const c_field_display_name_Procedure_Arg_3 = "field_specification_procedure_arg_3";
const char* const c_field_display_name_Protect_Child_Rel = "field_specification_protect_child_rel";
const char* const c_field_display_name_Protect_Procedure = "field_specification_protect_procedure";
const char* const c_field_display_name_Protect_Source_Parent = "field_specification_protect_source_parent";
const char* const c_field_display_name_Restrict_Values = "field_specification_restrict_values";
const char* const c_field_display_name_Source_Child = "field_specification_source_child";
const char* const c_field_display_name_Source_Child_2 = "field_specification_source_child_2";
const char* const c_field_display_name_Source_Child_Class = "field_specification_source_child_class";
const char* const c_field_display_name_Source_Class = "field_specification_source_class";
const char* const c_field_display_name_Source_Field = "field_specification_source_field";
const char* const c_field_display_name_Source_Field_Class = "field_specification_source_field_class";
const char* const c_field_display_name_Source_Grandchild = "field_specification_source_grandchild";
const char* const c_field_display_name_Source_Parent = "field_specification_source_parent";
const char* const c_field_display_name_Source_Parent_Class = "field_specification_source_parent_class";
const char* const c_field_display_name_Specification_Type = "field_specification_specification_type";
const char* const c_field_display_name_Strings = "field_specification_strings";
const char* const c_field_display_name_Test_Child = "field_specification_test_child";
const char* const c_field_display_name_Test_Field = "field_specification_test_field";
const char* const c_field_display_name_Test_Field_Class = "field_specification_test_field_class";
const char* const c_field_display_name_Test_Parent = "field_specification_test_parent";
const char* const c_field_display_name_Test_Parent_Class = "field_specification_test_parent_class";
const char* const c_field_display_name_Test_Value = "field_specification_test_value";
const char* const c_field_display_name_Use_Source_Parent = "field_specification_use_source_parent";
const char* const c_field_display_name_Use_Test_Parent_Child = "field_specification_use_test_parent_child";
const char* const c_field_display_name_Value = "field_specification_value";
const char* const c_field_display_name_Value_Left_Part = "field_specification_value_left_part";
const char* const c_field_display_name_Value_Literal = "field_specification_value_literal";
const char* const c_field_display_name_Value_Numeric_String = "field_specification_value_numeric_string";
const char* const c_field_display_name_Value_Right_Part = "field_specification_value_right_part";
const char* const c_field_display_name_Value_String = "field_specification_value_string";
const char* const c_field_display_name_Vars = "field_specification_vars";

const int c_num_fields = 69;

const char* const c_all_sorted_field_ids[ ] =
{
   "115101",
   "115102",
   "115103",
   "115104",
   "115105",
   "115107",
   "115108",
   "115110",
   "115111",
   "115112",
   "115113",
   "115114",
   "115115",
   "115116",
   "115117",
   "115118",
   "115119",
   "115120",
   "115121",
   "115122",
   "115123",
   "115124",
   "115125",
   "115126",
   "115127",
   "115128",
   "115129",
   "115130",
   "301400",
   "301405",
   "301406",
   "301410",
   "301420",
   "301421",
   "301430",
   "301435",
   "301436",
   "301440",
   "301450",
   "301451",
   "301452",
   "301460",
   "301470",
   "301471",
   "301472",
   "301473",
   "301474",
   "301475",
   "301476",
   "301477",
   "301478",
   "301480",
   "301481",
   "301482",
   "301485",
   "301486",
   "301487",
   "301488",
   "301489",
   "301490",
   "301491",
   "301492",
   "301493",
   "301494",
   "301495",
   "301496",
   "301498",
   "301499",
   "302550"
};

const char* const c_all_sorted_field_names[ ] =
{
   "Actions",
   "All_Strings",
   "All_Vars",
   "Child_Rel_Child_Class",
   "Child_Rel_Field_Key",
   "Child_Relationship",
   "Child_Specification_Type",
   "Class",
   "Comments",
   "Enum",
   "Enum_Item",
   "Enum_Item_2",
   "Enum_Item_3",
   "Enum_Item_4",
   "Enum_Item_5",
   "Field",
   "Field_Class",
   "Field_Pairs",
   "Field_Values",
   "Fields",
   "Id",
   "Is_Required_For_UI_Gen",
   "Model",
   "Modifier",
   "Name",
   "Options",
   "Order",
   "Other_Class",
   "Other_Field",
   "Other_Field_2",
   "Other_Procedure",
   "Other_Procedure_2",
   "Parent_Specification",
   "Parent_Specification_Copy_Child_Links",
   "Permission",
   "Procedure",
   "Procedure_Arg",
   "Procedure_Arg_2",
   "Procedure_Arg_3",
   "Protect_Child_Rel",
   "Protect_Procedure",
   "Protect_Source_Parent",
   "Restrict_Values",
   "Source_Child",
   "Source_Child_2",
   "Source_Child_Class",
   "Source_Class",
   "Source_Field",
   "Source_Field_Class",
   "Source_Grandchild",
   "Source_Parent",
   "Source_Parent_Class",
   "Specification_Type",
   "Strings",
   "Test_Child",
   "Test_Field",
   "Test_Field_Class",
   "Test_Parent",
   "Test_Parent_Class",
   "Test_Value",
   "Use_Source_Parent",
   "Use_Test_Parent_Child",
   "Value",
   "Value_Left_Part",
   "Value_Literal",
   "Value_Numeric_String",
   "Value_Right_Part",
   "Value_String",
   "Vars"
};

inline bool compare( const char* p_s1, const char* p_s2 ) { return strcmp( p_s1, p_s2 ) < 0; }

inline bool has_field( const string& field )
{
   return binary_search( c_all_sorted_field_ids, c_all_sorted_field_ids + c_num_fields, field.c_str( ), compare )
    || binary_search( c_all_sorted_field_names, c_all_sorted_field_names + c_num_fields, field.c_str( ), compare );
}

const int c_num_transient_fields = 4;

const char* const c_transient_sorted_field_ids[ ] =
{
   "115114",
   "115119",
   "115123",
   "115124"
};

const char* const c_transient_sorted_field_names[ ] =
{
   "All_Strings",
   "All_Vars",
   "Strings",
   "Vars"
};

inline bool transient_compare( const char* p_s1, const char* p_s2 ) { return strcmp( p_s1, p_s2 ) < 0; }

inline bool is_transient_field( const string& field )
{
   return binary_search( c_transient_sorted_field_ids,
    c_transient_sorted_field_ids + c_num_transient_fields, field.c_str( ), transient_compare )
    || binary_search( c_transient_sorted_field_names,
    c_transient_sorted_field_names + c_num_transient_fields, field.c_str( ), transient_compare );
}

const char* const c_procedure_id_Add_Arg_1 = "115439";
const char* const c_procedure_id_Add_Arg_2 = "115440";
const char* const c_procedure_id_Add_Child_Info = "115432";
const char* const c_procedure_id_Add_Extra_Info = "115443";
const char* const c_procedure_id_Add_Field = "115430";
const char* const c_procedure_id_Add_Field_Pair = "115431";
const char* const c_procedure_id_Add_Grandchild_Info = "115438";
const char* const c_procedure_id_Add_Info = "115441";
const char* const c_procedure_id_Add_Next = "115444";
const char* const c_procedure_id_Add_Opt_Info = "115442";
const char* const c_procedure_id_Add_Other_Info = "115445";
const char* const c_procedure_id_Add_Secondary = "115433";
const char* const c_procedure_id_Add_Source_Info = "115437";
const char* const c_procedure_id_Add_Stats_1 = "115434";
const char* const c_procedure_id_Add_Stats_2 = "115435";
const char* const c_procedure_id_Add_Stats_Info = "115436";
const char* const c_procedure_id_Generate_All_Strings = "115510";
const char* const c_procedure_id_Generate_All_Vars = "115500";
const char* const c_procedure_id_Move_Down = "115420";
const char* const c_procedure_id_Move_Up = "115410";

const uint64_t c_modifier_Hide_Child_Relationship = UINT64_C( 0x100 );
const uint64_t c_modifier_Hide_Enum = UINT64_C( 0x200 );
const uint64_t c_modifier_Hide_Enum_Item = UINT64_C( 0x400 );
const uint64_t c_modifier_Hide_Enum_Item_2 = UINT64_C( 0x800 );
const uint64_t c_modifier_Hide_Enum_Item_3 = UINT64_C( 0x1000 );
const uint64_t c_modifier_Hide_Enum_Item_4 = UINT64_C( 0x2000 );
const uint64_t c_modifier_Hide_Enum_Item_5 = UINT64_C( 0x4000 );
const uint64_t c_modifier_Hide_Field = UINT64_C( 0x8000 );
const uint64_t c_modifier_Hide_Modifier = UINT64_C( 0x10000 );
const uint64_t c_modifier_Hide_Options = UINT64_C( 0x20000 );
const uint64_t c_modifier_Hide_Other_Class = UINT64_C( 0x40000 );
const uint64_t c_modifier_Hide_Other_Field = UINT64_C( 0x80000 );
const uint64_t c_modifier_Hide_Other_Field_2 = UINT64_C( 0x100000 );
const uint64_t c_modifier_Hide_Other_Procedure = UINT64_C( 0x200000 );
const uint64_t c_modifier_Hide_Other_Procedure_2 = UINT64_C( 0x400000 );
const uint64_t c_modifier_Hide_Permission = UINT64_C( 0x800000 );
const uint64_t c_modifier_Hide_Procedure = UINT64_C( 0x1000000 );
const uint64_t c_modifier_Hide_Procedure_Arg = UINT64_C( 0x2000000 );
const uint64_t c_modifier_Hide_Procedure_Arg_2 = UINT64_C( 0x4000000 );
const uint64_t c_modifier_Hide_Procedure_Arg_3 = UINT64_C( 0x8000000 );
const uint64_t c_modifier_Hide_Source_Child = UINT64_C( 0x10000000 );
const uint64_t c_modifier_Hide_Source_Child_2 = UINT64_C( 0x20000000 );
const uint64_t c_modifier_Hide_Source_Class = UINT64_C( 0x40000000 );
const uint64_t c_modifier_Hide_Source_Field = UINT64_C( 0x80000000 );
const uint64_t c_modifier_Hide_Source_Grandchild = UINT64_C( 0x100000000 );
const uint64_t c_modifier_Hide_Source_Parent = UINT64_C( 0x200000000 );
const uint64_t c_modifier_Hide_Test_Child = UINT64_C( 0x400000000 );
const uint64_t c_modifier_Hide_Test_Field = UINT64_C( 0x800000000 );
const uint64_t c_modifier_Hide_Test_Parent = UINT64_C( 0x1000000000 );
const uint64_t c_modifier_Hide_Test_Value = UINT64_C( 0x2000000000 );
const uint64_t c_modifier_Hide_Use_Source_Parent = UINT64_C( 0x4000000000 );
const uint64_t c_modifier_Hide_Use_Test_Parent_Child = UINT64_C( 0x8000000000 );
const uint64_t c_modifier_Hide_Value = UINT64_C( 0x10000000000 );
const uint64_t c_modifier_Protect_Child_Relationship = UINT64_C( 0x20000000000 );
const uint64_t c_modifier_Protect_Class = UINT64_C( 0x40000000000 );
const uint64_t c_modifier_Protect_Enum = UINT64_C( 0x80000000000 );
const uint64_t c_modifier_Protect_Procedure = UINT64_C( 0x100000000000 );
const uint64_t c_modifier_Protect_Source_Parent = UINT64_C( 0x200000000000 );

domain_string_max_size< 100 > g_Comments_domain;
aggregate_domain< string,
 domain_string_identifier_format,
 domain_string_max_size< 30 > > g_Id_domain;
domain_string_max_size< 150 > g_Name_domain;
domain_string_max_size< 100 > g_Options_domain;
domain_string_max_size< 100 > g_Test_Value_domain;
domain_string_max_size< 100 > g_Value_domain;

set< string > g_derivations;

typedef map< string, Meta_Specification* > external_aliases_container;
typedef external_aliases_container::const_iterator external_aliases_const_iterator;
typedef external_aliases_container::value_type external_aliases_value_type;

typedef map< size_t, Meta_Specification* > external_aliases_lookup_container;
typedef external_aliases_lookup_container::const_iterator external_aliases_lookup_const_iterator;

external_aliases_container g_external_aliases;
external_aliases_lookup_container g_external_aliases_lookup;

string gv_default_Actions = string( );
string gv_default_All_Strings = string( );
string gv_default_All_Vars = string( );
string gv_default_Child_Rel_Field_Key = string( );
string gv_default_Comments = string( );
string gv_default_Field_Pairs = string( );
string gv_default_Field_Values = string( );
string gv_default_Fields = string( );
string gv_default_Id = string( );
bool gv_default_Is_Required_For_UI_Gen = bool( 0 );
string gv_default_Name = string( );
string gv_default_Options = string( );
string gv_default_Order = string( );
bool gv_default_Protect_Child_Rel = bool( 0 );
bool gv_default_Protect_Procedure = bool( 0 );
bool gv_default_Protect_Source_Parent = bool( 0 );
string gv_default_Restrict_Values = string( );
string gv_default_Strings = string( );
string gv_default_Test_Value = string( );
bool gv_default_Use_Source_Parent = bool( 0 );
bool gv_default_Use_Test_Parent_Child = bool( 0 );
string gv_default_Value = string( );
string gv_default_Value_Left_Part = string( );
string gv_default_Value_Literal = string( );
string gv_default_Value_Numeric_String = string( );
string gv_default_Value_Right_Part = string( );
string gv_default_Value_String = string( );
string gv_default_Vars = string( );

// [<start anonymous>]
// [<finish anonymous>]

}

registration< Meta_Specification > Specification_registration( get_class_registry( ), "115100" );

class Meta_Specification_command_functor;

class Meta_Specification_command_handler : public command_handler
{
   friend class Meta_Specification_command_functor;

   public:
   Meta_Specification_command_handler( ) : p_Meta_Specification( 0 ) { }

   void set_Meta_Specification( Meta_Specification* p_new_Meta_Specification ) { p_Meta_Specification = p_new_Meta_Specification; }

   void handle_unknown_command( const string& command )
   {
      throw runtime_error( "unknown command '" + command + "'" );
   }

   void handle_invalid_command( const command_parser& parser, const string& cmd_and_args )
   {
      throw runtime_error( "invalid command usage '" + cmd_and_args + "'" );
   }

   private:
   Meta_Specification* p_Meta_Specification;

   protected:
   string retval;
};

class Meta_Specification_command_functor : public command_functor
{
   public:
   Meta_Specification_command_functor( Meta_Specification_command_handler& handler )
    : command_functor( handler ),
    cmd_handler( handler )
   {
   }

   void operator ( )( const string& command, const parameter_info& parameters );

   private:
   Meta_Specification_command_handler& cmd_handler;
};

command_functor* Meta_Specification_command_functor_factory( const string& /*name*/, command_handler& handler )
{
   return new Meta_Specification_command_functor( dynamic_cast< Meta_Specification_command_handler& >( handler ) );
}

void Meta_Specification_command_functor::operator ( )( const string& command, const parameter_info& parameters )
{
   if( command == c_cmd_Meta_Specification_key )
   {
      bool want_fixed( has_parm_val( parameters, c_cmd_parm_Meta_Specification_key_fixed ) );

      if( !want_fixed )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->get_key( );
      else
         cmd_handler.retval = cmd_handler.p_Meta_Specification->get_fixed_key( );
   }
   else if( command == c_cmd_Meta_Specification_ver )
   {
      string ver_rev( to_string( cmd_handler.p_Meta_Specification->get_version( ) ) );
      ver_rev += "." + to_string( cmd_handler.p_Meta_Specification->get_revision( ) );

      cmd_handler.retval = ver_rev;
   }
   else if( command == c_cmd_Meta_Specification_get )
   {
      string field_name( get_parm_val( parameters, c_cmd_parm_Meta_Specification_get_field_name ) );

      if( field_name.empty( ) )
         throw runtime_error( "field name must not be empty for getter call" );
      else if( field_name == c_field_id_Actions || field_name == c_field_name_Actions )
         string_getter< string >( cmd_handler.p_Meta_Specification->Actions( ), cmd_handler.retval );
      else if( field_name == c_field_id_All_Strings || field_name == c_field_name_All_Strings )
         string_getter< string >( cmd_handler.p_Meta_Specification->All_Strings( ), cmd_handler.retval );
      else if( field_name == c_field_id_All_Vars || field_name == c_field_name_All_Vars )
         string_getter< string >( cmd_handler.p_Meta_Specification->All_Vars( ), cmd_handler.retval );
      else if( field_name == c_field_id_Child_Rel_Child_Class || field_name == c_field_name_Child_Rel_Child_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Child_Rel_Child_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Child_Rel_Field_Key || field_name == c_field_name_Child_Rel_Field_Key )
         string_getter< string >( cmd_handler.p_Meta_Specification->Child_Rel_Field_Key( ), cmd_handler.retval );
      else if( field_name == c_field_id_Child_Relationship || field_name == c_field_name_Child_Relationship )
         string_getter< Meta_Relationship >( cmd_handler.p_Meta_Specification->Child_Relationship( ), cmd_handler.retval );
      else if( field_name == c_field_id_Child_Specification_Type || field_name == c_field_name_Child_Specification_Type )
         string_getter< Meta_Specification_Type >( cmd_handler.p_Meta_Specification->Child_Specification_Type( ), cmd_handler.retval );
      else if( field_name == c_field_id_Class || field_name == c_field_name_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Comments || field_name == c_field_name_Comments )
         string_getter< string >( cmd_handler.p_Meta_Specification->Comments( ), cmd_handler.retval );
      else if( field_name == c_field_id_Enum || field_name == c_field_name_Enum )
         string_getter< Meta_Enum >( cmd_handler.p_Meta_Specification->Enum( ), cmd_handler.retval );
      else if( field_name == c_field_id_Enum_Item || field_name == c_field_name_Enum_Item )
         string_getter< Meta_Enum_Item >( cmd_handler.p_Meta_Specification->Enum_Item( ), cmd_handler.retval );
      else if( field_name == c_field_id_Enum_Item_2 || field_name == c_field_name_Enum_Item_2 )
         string_getter< Meta_Enum_Item >( cmd_handler.p_Meta_Specification->Enum_Item_2( ), cmd_handler.retval );
      else if( field_name == c_field_id_Enum_Item_3 || field_name == c_field_name_Enum_Item_3 )
         string_getter< Meta_Enum_Item >( cmd_handler.p_Meta_Specification->Enum_Item_3( ), cmd_handler.retval );
      else if( field_name == c_field_id_Enum_Item_4 || field_name == c_field_name_Enum_Item_4 )
         string_getter< Meta_Enum_Item >( cmd_handler.p_Meta_Specification->Enum_Item_4( ), cmd_handler.retval );
      else if( field_name == c_field_id_Enum_Item_5 || field_name == c_field_name_Enum_Item_5 )
         string_getter< Meta_Enum_Item >( cmd_handler.p_Meta_Specification->Enum_Item_5( ), cmd_handler.retval );
      else if( field_name == c_field_id_Field || field_name == c_field_name_Field )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Field( ), cmd_handler.retval );
      else if( field_name == c_field_id_Field_Class || field_name == c_field_name_Field_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Field_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Field_Pairs || field_name == c_field_name_Field_Pairs )
         string_getter< string >( cmd_handler.p_Meta_Specification->Field_Pairs( ), cmd_handler.retval );
      else if( field_name == c_field_id_Field_Values || field_name == c_field_name_Field_Values )
         string_getter< string >( cmd_handler.p_Meta_Specification->Field_Values( ), cmd_handler.retval );
      else if( field_name == c_field_id_Fields || field_name == c_field_name_Fields )
         string_getter< string >( cmd_handler.p_Meta_Specification->Fields( ), cmd_handler.retval );
      else if( field_name == c_field_id_Id || field_name == c_field_name_Id )
         string_getter< string >( cmd_handler.p_Meta_Specification->Id( ), cmd_handler.retval );
      else if( field_name == c_field_id_Is_Required_For_UI_Gen || field_name == c_field_name_Is_Required_For_UI_Gen )
         string_getter< bool >( cmd_handler.p_Meta_Specification->Is_Required_For_UI_Gen( ), cmd_handler.retval );
      else if( field_name == c_field_id_Model || field_name == c_field_name_Model )
         string_getter< Meta_Model >( cmd_handler.p_Meta_Specification->Model( ), cmd_handler.retval );
      else if( field_name == c_field_id_Modifier || field_name == c_field_name_Modifier )
         string_getter< Meta_Modifier >( cmd_handler.p_Meta_Specification->Modifier( ), cmd_handler.retval );
      else if( field_name == c_field_id_Name || field_name == c_field_name_Name )
         string_getter< string >( cmd_handler.p_Meta_Specification->Name( ), cmd_handler.retval );
      else if( field_name == c_field_id_Options || field_name == c_field_name_Options )
         string_getter< string >( cmd_handler.p_Meta_Specification->Options( ), cmd_handler.retval );
      else if( field_name == c_field_id_Order || field_name == c_field_name_Order )
         string_getter< string >( cmd_handler.p_Meta_Specification->Order( ), cmd_handler.retval );
      else if( field_name == c_field_id_Other_Class || field_name == c_field_name_Other_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Other_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Other_Field || field_name == c_field_name_Other_Field )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Other_Field( ), cmd_handler.retval );
      else if( field_name == c_field_id_Other_Field_2 || field_name == c_field_name_Other_Field_2 )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Other_Field_2( ), cmd_handler.retval );
      else if( field_name == c_field_id_Other_Procedure || field_name == c_field_name_Other_Procedure )
         string_getter< Meta_Procedure >( cmd_handler.p_Meta_Specification->Other_Procedure( ), cmd_handler.retval );
      else if( field_name == c_field_id_Other_Procedure_2 || field_name == c_field_name_Other_Procedure_2 )
         string_getter< Meta_Procedure >( cmd_handler.p_Meta_Specification->Other_Procedure_2( ), cmd_handler.retval );
      else if( field_name == c_field_id_Parent_Specification || field_name == c_field_name_Parent_Specification )
         string_getter< Meta_Specification >( cmd_handler.p_Meta_Specification->Parent_Specification( ), cmd_handler.retval );
      else if( field_name == c_field_id_Parent_Specification_Copy_Child_Links || field_name == c_field_name_Parent_Specification_Copy_Child_Links )
         string_getter< Meta_Specification_Copy_Child_Links >( cmd_handler.p_Meta_Specification->Parent_Specification_Copy_Child_Links( ), cmd_handler.retval );
      else if( field_name == c_field_id_Permission || field_name == c_field_name_Permission )
         string_getter< Meta_Permission >( cmd_handler.p_Meta_Specification->Permission( ), cmd_handler.retval );
      else if( field_name == c_field_id_Procedure || field_name == c_field_name_Procedure )
         string_getter< Meta_Procedure >( cmd_handler.p_Meta_Specification->Procedure( ), cmd_handler.retval );
      else if( field_name == c_field_id_Procedure_Arg || field_name == c_field_name_Procedure_Arg )
         string_getter< Meta_Procedure_Arg >( cmd_handler.p_Meta_Specification->Procedure_Arg( ), cmd_handler.retval );
      else if( field_name == c_field_id_Procedure_Arg_2 || field_name == c_field_name_Procedure_Arg_2 )
         string_getter< Meta_Procedure_Arg >( cmd_handler.p_Meta_Specification->Procedure_Arg_2( ), cmd_handler.retval );
      else if( field_name == c_field_id_Procedure_Arg_3 || field_name == c_field_name_Procedure_Arg_3 )
         string_getter< Meta_Procedure_Arg >( cmd_handler.p_Meta_Specification->Procedure_Arg_3( ), cmd_handler.retval );
      else if( field_name == c_field_id_Protect_Child_Rel || field_name == c_field_name_Protect_Child_Rel )
         string_getter< bool >( cmd_handler.p_Meta_Specification->Protect_Child_Rel( ), cmd_handler.retval );
      else if( field_name == c_field_id_Protect_Procedure || field_name == c_field_name_Protect_Procedure )
         string_getter< bool >( cmd_handler.p_Meta_Specification->Protect_Procedure( ), cmd_handler.retval );
      else if( field_name == c_field_id_Protect_Source_Parent || field_name == c_field_name_Protect_Source_Parent )
         string_getter< bool >( cmd_handler.p_Meta_Specification->Protect_Source_Parent( ), cmd_handler.retval );
      else if( field_name == c_field_id_Restrict_Values || field_name == c_field_name_Restrict_Values )
         string_getter< string >( cmd_handler.p_Meta_Specification->Restrict_Values( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Child || field_name == c_field_name_Source_Child )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Source_Child( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Child_2 || field_name == c_field_name_Source_Child_2 )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Source_Child_2( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Child_Class || field_name == c_field_name_Source_Child_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Source_Child_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Class || field_name == c_field_name_Source_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Source_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Field || field_name == c_field_name_Source_Field )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Source_Field( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Field_Class || field_name == c_field_name_Source_Field_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Source_Field_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Grandchild || field_name == c_field_name_Source_Grandchild )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Source_Grandchild( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Parent || field_name == c_field_name_Source_Parent )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Source_Parent( ), cmd_handler.retval );
      else if( field_name == c_field_id_Source_Parent_Class || field_name == c_field_name_Source_Parent_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Source_Parent_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Specification_Type || field_name == c_field_name_Specification_Type )
         string_getter< Meta_Specification_Type >( cmd_handler.p_Meta_Specification->Specification_Type( ), cmd_handler.retval );
      else if( field_name == c_field_id_Strings || field_name == c_field_name_Strings )
         string_getter< string >( cmd_handler.p_Meta_Specification->Strings( ), cmd_handler.retval );
      else if( field_name == c_field_id_Test_Child || field_name == c_field_name_Test_Child )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Test_Child( ), cmd_handler.retval );
      else if( field_name == c_field_id_Test_Field || field_name == c_field_name_Test_Field )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Test_Field( ), cmd_handler.retval );
      else if( field_name == c_field_id_Test_Field_Class || field_name == c_field_name_Test_Field_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Test_Field_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Test_Parent || field_name == c_field_name_Test_Parent )
         string_getter< Meta_Field >( cmd_handler.p_Meta_Specification->Test_Parent( ), cmd_handler.retval );
      else if( field_name == c_field_id_Test_Parent_Class || field_name == c_field_name_Test_Parent_Class )
         string_getter< Meta_Class >( cmd_handler.p_Meta_Specification->Test_Parent_Class( ), cmd_handler.retval );
      else if( field_name == c_field_id_Test_Value || field_name == c_field_name_Test_Value )
         string_getter< string >( cmd_handler.p_Meta_Specification->Test_Value( ), cmd_handler.retval );
      else if( field_name == c_field_id_Use_Source_Parent || field_name == c_field_name_Use_Source_Parent )
         string_getter< bool >( cmd_handler.p_Meta_Specification->Use_Source_Parent( ), cmd_handler.retval );
      else if( field_name == c_field_id_Use_Test_Parent_Child || field_name == c_field_name_Use_Test_Parent_Child )
         string_getter< bool >( cmd_handler.p_Meta_Specification->Use_Test_Parent_Child( ), cmd_handler.retval );
      else if( field_name == c_field_id_Value || field_name == c_field_name_Value )
         string_getter< string >( cmd_handler.p_Meta_Specification->Value( ), cmd_handler.retval );
      else if( field_name == c_field_id_Value_Left_Part || field_name == c_field_name_Value_Left_Part )
         string_getter< string >( cmd_handler.p_Meta_Specification->Value_Left_Part( ), cmd_handler.retval );
      else if( field_name == c_field_id_Value_Literal || field_name == c_field_name_Value_Literal )
         string_getter< string >( cmd_handler.p_Meta_Specification->Value_Literal( ), cmd_handler.retval );
      else if( field_name == c_field_id_Value_Numeric_String || field_name == c_field_name_Value_Numeric_String )
         string_getter< string >( cmd_handler.p_Meta_Specification->Value_Numeric_String( ), cmd_handler.retval );
      else if( field_name == c_field_id_Value_Right_Part || field_name == c_field_name_Value_Right_Part )
         string_getter< string >( cmd_handler.p_Meta_Specification->Value_Right_Part( ), cmd_handler.retval );
      else if( field_name == c_field_id_Value_String || field_name == c_field_name_Value_String )
         string_getter< string >( cmd_handler.p_Meta_Specification->Value_String( ), cmd_handler.retval );
      else if( field_name == c_field_id_Vars || field_name == c_field_name_Vars )
         string_getter< string >( cmd_handler.p_Meta_Specification->Vars( ), cmd_handler.retval );
      else
         throw runtime_error( "unknown field name '" + field_name + "' for getter call" );
   }
   else if( command == c_cmd_Meta_Specification_set )
   {
      string field_name( get_parm_val( parameters, c_cmd_parm_Meta_Specification_set_field_name ) );
      string field_value( get_parm_val( parameters, c_cmd_parm_Meta_Specification_set_field_value ) );

      if( field_name.empty( ) )
         throw runtime_error( "field name must not be empty for setter call" );
      else if( field_name == c_field_id_Actions || field_name == c_field_name_Actions )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Actions, field_value );
      else if( field_name == c_field_id_All_Strings || field_name == c_field_name_All_Strings )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::All_Strings, field_value );
      else if( field_name == c_field_id_All_Vars || field_name == c_field_name_All_Vars )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::All_Vars, field_value );
      else if( field_name == c_field_id_Child_Rel_Child_Class || field_name == c_field_name_Child_Rel_Child_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Child_Rel_Child_Class, field_value );
      else if( field_name == c_field_id_Child_Rel_Field_Key || field_name == c_field_name_Child_Rel_Field_Key )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Child_Rel_Field_Key, field_value );
      else if( field_name == c_field_id_Child_Relationship || field_name == c_field_name_Child_Relationship )
         func_string_setter< Meta_Specification, Meta_Relationship >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Child_Relationship, field_value );
      else if( field_name == c_field_id_Child_Specification_Type || field_name == c_field_name_Child_Specification_Type )
         func_string_setter< Meta_Specification, Meta_Specification_Type >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Child_Specification_Type, field_value );
      else if( field_name == c_field_id_Class || field_name == c_field_name_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Class, field_value );
      else if( field_name == c_field_id_Comments || field_name == c_field_name_Comments )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Comments, field_value );
      else if( field_name == c_field_id_Enum || field_name == c_field_name_Enum )
         func_string_setter< Meta_Specification, Meta_Enum >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Enum, field_value );
      else if( field_name == c_field_id_Enum_Item || field_name == c_field_name_Enum_Item )
         func_string_setter< Meta_Specification, Meta_Enum_Item >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Enum_Item, field_value );
      else if( field_name == c_field_id_Enum_Item_2 || field_name == c_field_name_Enum_Item_2 )
         func_string_setter< Meta_Specification, Meta_Enum_Item >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Enum_Item_2, field_value );
      else if( field_name == c_field_id_Enum_Item_3 || field_name == c_field_name_Enum_Item_3 )
         func_string_setter< Meta_Specification, Meta_Enum_Item >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Enum_Item_3, field_value );
      else if( field_name == c_field_id_Enum_Item_4 || field_name == c_field_name_Enum_Item_4 )
         func_string_setter< Meta_Specification, Meta_Enum_Item >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Enum_Item_4, field_value );
      else if( field_name == c_field_id_Enum_Item_5 || field_name == c_field_name_Enum_Item_5 )
         func_string_setter< Meta_Specification, Meta_Enum_Item >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Enum_Item_5, field_value );
      else if( field_name == c_field_id_Field || field_name == c_field_name_Field )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Field, field_value );
      else if( field_name == c_field_id_Field_Class || field_name == c_field_name_Field_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Field_Class, field_value );
      else if( field_name == c_field_id_Field_Pairs || field_name == c_field_name_Field_Pairs )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Field_Pairs, field_value );
      else if( field_name == c_field_id_Field_Values || field_name == c_field_name_Field_Values )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Field_Values, field_value );
      else if( field_name == c_field_id_Fields || field_name == c_field_name_Fields )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Fields, field_value );
      else if( field_name == c_field_id_Id || field_name == c_field_name_Id )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Id, field_value );
      else if( field_name == c_field_id_Is_Required_For_UI_Gen || field_name == c_field_name_Is_Required_For_UI_Gen )
         func_string_setter< Meta_Specification, bool >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Is_Required_For_UI_Gen, field_value );
      else if( field_name == c_field_id_Model || field_name == c_field_name_Model )
         func_string_setter< Meta_Specification, Meta_Model >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Model, field_value );
      else if( field_name == c_field_id_Modifier || field_name == c_field_name_Modifier )
         func_string_setter< Meta_Specification, Meta_Modifier >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Modifier, field_value );
      else if( field_name == c_field_id_Name || field_name == c_field_name_Name )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Name, field_value );
      else if( field_name == c_field_id_Options || field_name == c_field_name_Options )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Options, field_value );
      else if( field_name == c_field_id_Order || field_name == c_field_name_Order )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Order, field_value );
      else if( field_name == c_field_id_Other_Class || field_name == c_field_name_Other_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Other_Class, field_value );
      else if( field_name == c_field_id_Other_Field || field_name == c_field_name_Other_Field )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Other_Field, field_value );
      else if( field_name == c_field_id_Other_Field_2 || field_name == c_field_name_Other_Field_2 )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Other_Field_2, field_value );
      else if( field_name == c_field_id_Other_Procedure || field_name == c_field_name_Other_Procedure )
         func_string_setter< Meta_Specification, Meta_Procedure >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Other_Procedure, field_value );
      else if( field_name == c_field_id_Other_Procedure_2 || field_name == c_field_name_Other_Procedure_2 )
         func_string_setter< Meta_Specification, Meta_Procedure >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Other_Procedure_2, field_value );
      else if( field_name == c_field_id_Parent_Specification || field_name == c_field_name_Parent_Specification )
         func_string_setter< Meta_Specification, Meta_Specification >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Parent_Specification, field_value );
      else if( field_name == c_field_id_Parent_Specification_Copy_Child_Links || field_name == c_field_name_Parent_Specification_Copy_Child_Links )
         func_string_setter< Meta_Specification, Meta_Specification_Copy_Child_Links >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Parent_Specification_Copy_Child_Links, field_value );
      else if( field_name == c_field_id_Permission || field_name == c_field_name_Permission )
         func_string_setter< Meta_Specification, Meta_Permission >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Permission, field_value );
      else if( field_name == c_field_id_Procedure || field_name == c_field_name_Procedure )
         func_string_setter< Meta_Specification, Meta_Procedure >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Procedure, field_value );
      else if( field_name == c_field_id_Procedure_Arg || field_name == c_field_name_Procedure_Arg )
         func_string_setter< Meta_Specification, Meta_Procedure_Arg >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Procedure_Arg, field_value );
      else if( field_name == c_field_id_Procedure_Arg_2 || field_name == c_field_name_Procedure_Arg_2 )
         func_string_setter< Meta_Specification, Meta_Procedure_Arg >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Procedure_Arg_2, field_value );
      else if( field_name == c_field_id_Procedure_Arg_3 || field_name == c_field_name_Procedure_Arg_3 )
         func_string_setter< Meta_Specification, Meta_Procedure_Arg >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Procedure_Arg_3, field_value );
      else if( field_name == c_field_id_Protect_Child_Rel || field_name == c_field_name_Protect_Child_Rel )
         func_string_setter< Meta_Specification, bool >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Protect_Child_Rel, field_value );
      else if( field_name == c_field_id_Protect_Procedure || field_name == c_field_name_Protect_Procedure )
         func_string_setter< Meta_Specification, bool >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Protect_Procedure, field_value );
      else if( field_name == c_field_id_Protect_Source_Parent || field_name == c_field_name_Protect_Source_Parent )
         func_string_setter< Meta_Specification, bool >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Protect_Source_Parent, field_value );
      else if( field_name == c_field_id_Restrict_Values || field_name == c_field_name_Restrict_Values )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Restrict_Values, field_value );
      else if( field_name == c_field_id_Source_Child || field_name == c_field_name_Source_Child )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Child, field_value );
      else if( field_name == c_field_id_Source_Child_2 || field_name == c_field_name_Source_Child_2 )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Child_2, field_value );
      else if( field_name == c_field_id_Source_Child_Class || field_name == c_field_name_Source_Child_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Child_Class, field_value );
      else if( field_name == c_field_id_Source_Class || field_name == c_field_name_Source_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Class, field_value );
      else if( field_name == c_field_id_Source_Field || field_name == c_field_name_Source_Field )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Field, field_value );
      else if( field_name == c_field_id_Source_Field_Class || field_name == c_field_name_Source_Field_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Field_Class, field_value );
      else if( field_name == c_field_id_Source_Grandchild || field_name == c_field_name_Source_Grandchild )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Grandchild, field_value );
      else if( field_name == c_field_id_Source_Parent || field_name == c_field_name_Source_Parent )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Parent, field_value );
      else if( field_name == c_field_id_Source_Parent_Class || field_name == c_field_name_Source_Parent_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Source_Parent_Class, field_value );
      else if( field_name == c_field_id_Specification_Type || field_name == c_field_name_Specification_Type )
         func_string_setter< Meta_Specification, Meta_Specification_Type >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Specification_Type, field_value );
      else if( field_name == c_field_id_Strings || field_name == c_field_name_Strings )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Strings, field_value );
      else if( field_name == c_field_id_Test_Child || field_name == c_field_name_Test_Child )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Test_Child, field_value );
      else if( field_name == c_field_id_Test_Field || field_name == c_field_name_Test_Field )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Test_Field, field_value );
      else if( field_name == c_field_id_Test_Field_Class || field_name == c_field_name_Test_Field_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Test_Field_Class, field_value );
      else if( field_name == c_field_id_Test_Parent || field_name == c_field_name_Test_Parent )
         func_string_setter< Meta_Specification, Meta_Field >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Test_Parent, field_value );
      else if( field_name == c_field_id_Test_Parent_Class || field_name == c_field_name_Test_Parent_Class )
         func_string_setter< Meta_Specification, Meta_Class >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Test_Parent_Class, field_value );
      else if( field_name == c_field_id_Test_Value || field_name == c_field_name_Test_Value )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Test_Value, field_value );
      else if( field_name == c_field_id_Use_Source_Parent || field_name == c_field_name_Use_Source_Parent )
         func_string_setter< Meta_Specification, bool >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Use_Source_Parent, field_value );
      else if( field_name == c_field_id_Use_Test_Parent_Child || field_name == c_field_name_Use_Test_Parent_Child )
         func_string_setter< Meta_Specification, bool >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Use_Test_Parent_Child, field_value );
      else if( field_name == c_field_id_Value || field_name == c_field_name_Value )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Value, field_value );
      else if( field_name == c_field_id_Value_Left_Part || field_name == c_field_name_Value_Left_Part )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Value_Left_Part, field_value );
      else if( field_name == c_field_id_Value_Literal || field_name == c_field_name_Value_Literal )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Value_Literal, field_value );
      else if( field_name == c_field_id_Value_Numeric_String || field_name == c_field_name_Value_Numeric_String )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Value_Numeric_String, field_value );
      else if( field_name == c_field_id_Value_Right_Part || field_name == c_field_name_Value_Right_Part )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Value_Right_Part, field_value );
      else if( field_name == c_field_id_Value_String || field_name == c_field_name_Value_String )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Value_String, field_value );
      else if( field_name == c_field_id_Vars || field_name == c_field_name_Vars )
         func_string_setter< Meta_Specification, string >(
          *cmd_handler.p_Meta_Specification, &Meta_Specification::Vars, field_value );
      else
         throw runtime_error( "unknown field name '" + field_name + "' for setter call" );

      cmd_handler.retval = c_okay;
   }
   else if( command == c_cmd_Meta_Specification_cmd )
   {
      string field_name( get_parm_val( parameters, c_cmd_parm_Meta_Specification_cmd_field_name ) );
      string cmd_and_args( get_parm_val( parameters, c_cmd_parm_Meta_Specification_cmd_cmd_and_args ) );

      cmd_handler.retval.erase( );

      if( field_name.empty( ) )
         throw runtime_error( "field name must not be empty for command call" );
      else if( field_name == c_field_id_Child_Rel_Child_Class || field_name == c_field_name_Child_Rel_Child_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Child_Rel_Child_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Child_Relationship || field_name == c_field_name_Child_Relationship )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Child_Relationship( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Child_Specification_Type || field_name == c_field_name_Child_Specification_Type )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Child_Specification_Type( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Class || field_name == c_field_name_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Enum || field_name == c_field_name_Enum )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Enum( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Enum_Item || field_name == c_field_name_Enum_Item )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Enum_Item( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Enum_Item_2 || field_name == c_field_name_Enum_Item_2 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Enum_Item_2( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Enum_Item_3 || field_name == c_field_name_Enum_Item_3 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Enum_Item_3( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Enum_Item_4 || field_name == c_field_name_Enum_Item_4 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Enum_Item_4( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Enum_Item_5 || field_name == c_field_name_Enum_Item_5 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Enum_Item_5( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Field || field_name == c_field_name_Field )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Field( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Field_Class || field_name == c_field_name_Field_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Field_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Model || field_name == c_field_name_Model )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Model( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Modifier || field_name == c_field_name_Modifier )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Modifier( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Other_Class || field_name == c_field_name_Other_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Other_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Other_Field || field_name == c_field_name_Other_Field )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Other_Field( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Other_Field_2 || field_name == c_field_name_Other_Field_2 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Other_Field_2( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Other_Procedure || field_name == c_field_name_Other_Procedure )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Other_Procedure( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Other_Procedure_2 || field_name == c_field_name_Other_Procedure_2 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Other_Procedure_2( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Parent_Specification || field_name == c_field_name_Parent_Specification )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Parent_Specification( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Parent_Specification_Copy_Child_Links || field_name == c_field_name_Parent_Specification_Copy_Child_Links )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Parent_Specification_Copy_Child_Links( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Permission || field_name == c_field_name_Permission )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Permission( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Procedure || field_name == c_field_name_Procedure )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Procedure( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Procedure_Arg || field_name == c_field_name_Procedure_Arg )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Procedure_Arg( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Procedure_Arg_2 || field_name == c_field_name_Procedure_Arg_2 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Procedure_Arg_2( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Procedure_Arg_3 || field_name == c_field_name_Procedure_Arg_3 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Procedure_Arg_3( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Child || field_name == c_field_name_Source_Child )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Child( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Child_2 || field_name == c_field_name_Source_Child_2 )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Child_2( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Child_Class || field_name == c_field_name_Source_Child_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Child_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Class || field_name == c_field_name_Source_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Field || field_name == c_field_name_Source_Field )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Field( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Field_Class || field_name == c_field_name_Source_Field_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Field_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Grandchild || field_name == c_field_name_Source_Grandchild )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Grandchild( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Parent || field_name == c_field_name_Source_Parent )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Parent( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Source_Parent_Class || field_name == c_field_name_Source_Parent_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Source_Parent_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Specification_Type || field_name == c_field_name_Specification_Type )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Specification_Type( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Test_Child || field_name == c_field_name_Test_Child )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Test_Child( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Test_Field || field_name == c_field_name_Test_Field )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Test_Field( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Test_Field_Class || field_name == c_field_name_Test_Field_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Test_Field_Class( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Test_Parent || field_name == c_field_name_Test_Parent )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Test_Parent( ).execute( cmd_and_args );
      else if( field_name == c_field_id_Test_Parent_Class || field_name == c_field_name_Test_Parent_Class )
         cmd_handler.retval = cmd_handler.p_Meta_Specification->Test_Parent_Class( ).execute( cmd_and_args );
      else
         throw runtime_error( "unknown field name '" + field_name + "' for command call" );
   }
   else if( command == c_cmd_Meta_Specification_Add_Arg_1 )
   {
      cmd_handler.p_Meta_Specification->Add_Arg_1( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Arg_2 )
   {
      cmd_handler.p_Meta_Specification->Add_Arg_2( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Child_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Child_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Extra_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Extra_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Field )
   {
      cmd_handler.p_Meta_Specification->Add_Field( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Field_Pair )
   {
      cmd_handler.p_Meta_Specification->Add_Field_Pair( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Grandchild_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Grandchild_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Next )
   {
      cmd_handler.p_Meta_Specification->Add_Next( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Opt_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Opt_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Other_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Other_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Secondary )
   {
      cmd_handler.p_Meta_Specification->Add_Secondary( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Source_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Source_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Stats_1 )
   {
      cmd_handler.p_Meta_Specification->Add_Stats_1( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Stats_2 )
   {
      cmd_handler.p_Meta_Specification->Add_Stats_2( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Add_Stats_Info )
   {
      cmd_handler.p_Meta_Specification->Add_Stats_Info( );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Generate_All_Strings )
   {
      string Parent_Prefix( get_parm_val_from_string< string >( parameters, c_cmd_parm_Meta_Specification_Generate_All_Strings_Parent_Prefix ) );
      string All_Strings;
      cmd_handler.p_Meta_Specification->Generate_All_Strings( All_Strings, Parent_Prefix );

      cmd_handler.retval.erase( );
      append_value( cmd_handler.retval, All_Strings );
   }
   else if( command == c_cmd_Meta_Specification_Generate_All_Vars )
   {
      string Parent_Prefix( get_parm_val_from_string< string >( parameters, c_cmd_parm_Meta_Specification_Generate_All_Vars_Parent_Prefix ) );
      string All_Vars;
      cmd_handler.p_Meta_Specification->Generate_All_Vars( All_Vars, Parent_Prefix );

      cmd_handler.retval.erase( );
      append_value( cmd_handler.retval, All_Vars );
   }
   else if( command == c_cmd_Meta_Specification_Move_Down )
   {
      string Restrict_Fields( get_parm_val_from_string< string >( parameters, c_cmd_parm_Meta_Specification_Move_Down_Restrict_Fields ) );
      string Restrict_Values( get_parm_val_from_string< string >( parameters, c_cmd_parm_Meta_Specification_Move_Down_Restrict_Values ) );
      cmd_handler.p_Meta_Specification->Move_Down( Restrict_Fields, Restrict_Values );

      cmd_handler.retval.erase( );
   }
   else if( command == c_cmd_Meta_Specification_Move_Up )
   {
      string Restrict_Fields( get_parm_val_from_string< string >( parameters, c_cmd_parm_Meta_Specification_Move_Up_Restrict_Fields ) );
      string Restrict_Values( get_parm_val_from_string< string >( parameters, c_cmd_parm_Meta_Specification_Move_Up_Restrict_Values ) );
      cmd_handler.p_Meta_Specification->Move_Up( Restrict_Fields, Restrict_Values );

      cmd_handler.retval.erase( );
   }
}

struct Meta_Specification::impl : public Meta_Specification_command_handler
{
   impl( Meta_Specification& o )
    :
    cp_obj( &o ),
    total_child_relationships( 0 )
   {
      p_obj = &o;
      set_Meta_Specification( &o );

      add_commands( 0, Meta_Specification_command_functor_factory,
       ARRAY_PTR_AND_SIZE( Meta_Specification_command_definitions ) );
   }

   Meta_Specification& get_obj( ) const
   {
      return *cp_obj;
   }

   const string& impl_Actions( ) const { return lazy_fetch( p_obj ), v_Actions; }
   void impl_Actions( const string& Actions ) { v_Actions = Actions; }

   const string& impl_All_Strings( ) const { return lazy_fetch( p_obj ), v_All_Strings; }
   void impl_All_Strings( const string& All_Strings ) { v_All_Strings = All_Strings; }

   const string& impl_All_Vars( ) const { return lazy_fetch( p_obj ), v_All_Vars; }
   void impl_All_Vars( const string& All_Vars ) { v_All_Vars = All_Vars; }

   const string& impl_Child_Rel_Field_Key( ) const { return lazy_fetch( p_obj ), v_Child_Rel_Field_Key; }
   void impl_Child_Rel_Field_Key( const string& Child_Rel_Field_Key ) { v_Child_Rel_Field_Key = Child_Rel_Field_Key; }

   const string& impl_Comments( ) const { return lazy_fetch( p_obj ), v_Comments; }
   void impl_Comments( const string& Comments ) { v_Comments = Comments; }

   const string& impl_Field_Pairs( ) const { return lazy_fetch( p_obj ), v_Field_Pairs; }
   void impl_Field_Pairs( const string& Field_Pairs ) { v_Field_Pairs = Field_Pairs; }

   const string& impl_Field_Values( ) const { return lazy_fetch( p_obj ), v_Field_Values; }
   void impl_Field_Values( const string& Field_Values ) { v_Field_Values = Field_Values; }

   const string& impl_Fields( ) const { return lazy_fetch( p_obj ), v_Fields; }
   void impl_Fields( const string& Fields ) { v_Fields = Fields; }

   const string& impl_Id( ) const { return lazy_fetch( p_obj ), v_Id; }
   void impl_Id( const string& Id ) { v_Id = Id; }

   bool impl_Is_Required_For_UI_Gen( ) const { return lazy_fetch( p_obj ), v_Is_Required_For_UI_Gen; }
   void impl_Is_Required_For_UI_Gen( bool Is_Required_For_UI_Gen ) { v_Is_Required_For_UI_Gen = Is_Required_For_UI_Gen; }

   const string& impl_Name( ) const { return lazy_fetch( p_obj ), v_Name; }
   void impl_Name( const string& Name ) { v_Name = Name; }

   const string& impl_Options( ) const { return lazy_fetch( p_obj ), v_Options; }
   void impl_Options( const string& Options ) { v_Options = Options; }

   const string& impl_Order( ) const { return lazy_fetch( p_obj ), v_Order; }
   void impl_Order( const string& Order ) { v_Order = Order; }

   bool impl_Protect_Child_Rel( ) const { return lazy_fetch( p_obj ), v_Protect_Child_Rel; }
   void impl_Protect_Child_Rel( bool Protect_Child_Rel ) { v_Protect_Child_Rel = Protect_Child_Rel; }

   bool impl_Protect_Procedure( ) const { return lazy_fetch( p_obj ), v_Protect_Procedure; }
   void impl_Protect_Procedure( bool Protect_Procedure ) { v_Protect_Procedure = Protect_Procedure; }

   bool impl_Protect_Source_Parent( ) const { return lazy_fetch( p_obj ), v_Protect_Source_Parent; }
   void impl_Protect_Source_Parent( bool Protect_Source_Parent ) { v_Protect_Source_Parent = Protect_Source_Parent; }

   const string& impl_Restrict_Values( ) const { return lazy_fetch( p_obj ), v_Restrict_Values; }
   void impl_Restrict_Values( const string& Restrict_Values ) { v_Restrict_Values = Restrict_Values; }

   const string& impl_Strings( ) const { return lazy_fetch( p_obj ), v_Strings; }
   void impl_Strings( const string& Strings ) { v_Strings = Strings; }

   const string& impl_Test_Value( ) const { return lazy_fetch( p_obj ), v_Test_Value; }
   void impl_Test_Value( const string& Test_Value ) { v_Test_Value = Test_Value; }

   bool impl_Use_Source_Parent( ) const { return lazy_fetch( p_obj ), v_Use_Source_Parent; }
   void impl_Use_Source_Parent( bool Use_Source_Parent ) { v_Use_Source_Parent = Use_Source_Parent; }

   bool impl_Use_Test_Parent_Child( ) const { return lazy_fetch( p_obj ), v_Use_Test_Parent_Child; }
   void impl_Use_Test_Parent_Child( bool Use_Test_Parent_Child ) { v_Use_Test_Parent_Child = Use_Test_Parent_Child; }

   const string& impl_Value( ) const { return lazy_fetch( p_obj ), v_Value; }
   void impl_Value( const string& Value ) { v_Value = Value; }

   const string& impl_Value_Left_Part( ) const { return lazy_fetch( p_obj ), v_Value_Left_Part; }
   void impl_Value_Left_Part( const string& Value_Left_Part ) { v_Value_Left_Part = Value_Left_Part; }

   const string& impl_Value_Literal( ) const { return lazy_fetch( p_obj ), v_Value_Literal; }
   void impl_Value_Literal( const string& Value_Literal ) { v_Value_Literal = Value_Literal; }

   const string& impl_Value_Numeric_String( ) const { return lazy_fetch( p_obj ), v_Value_Numeric_String; }
   void impl_Value_Numeric_String( const string& Value_Numeric_String ) { v_Value_Numeric_String = Value_Numeric_String; }

   const string& impl_Value_Right_Part( ) const { return lazy_fetch( p_obj ), v_Value_Right_Part; }
   void impl_Value_Right_Part( const string& Value_Right_Part ) { v_Value_Right_Part = Value_Right_Part; }

   const string& impl_Value_String( ) const { return lazy_fetch( p_obj ), v_Value_String; }
   void impl_Value_String( const string& Value_String ) { v_Value_String = Value_String; }

   const string& impl_Vars( ) const { return lazy_fetch( p_obj ), v_Vars; }
   void impl_Vars( const string& Vars ) { v_Vars = Vars; }

   Meta_Class& impl_Child_Rel_Child_Class( )
   {
      if( !cp_Child_Rel_Child_Class )
      {
         cp_Child_Rel_Child_Class.init( );

         p_obj->setup_graph_parent( *cp_Child_Rel_Child_Class, c_field_id_Child_Rel_Child_Class, v_Child_Rel_Child_Class );
      }
      return *cp_Child_Rel_Child_Class;
   }

   const Meta_Class& impl_Child_Rel_Child_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Child_Rel_Child_Class )
      {
         cp_Child_Rel_Child_Class.init( );

         p_obj->setup_graph_parent( *cp_Child_Rel_Child_Class, c_field_id_Child_Rel_Child_Class, v_Child_Rel_Child_Class );
      }
      return *cp_Child_Rel_Child_Class;
   }

   void impl_Child_Rel_Child_Class( const string& key )
   {
      class_base_accessor cba( impl_Child_Rel_Child_Class( ) );
      cba.set_key( key );
   }

   Meta_Relationship& impl_Child_Relationship( )
   {
      if( !cp_Child_Relationship )
      {
         cp_Child_Relationship.init( );

         p_obj->setup_graph_parent( *cp_Child_Relationship, c_field_id_Child_Relationship, v_Child_Relationship );
      }
      return *cp_Child_Relationship;
   }

   const Meta_Relationship& impl_Child_Relationship( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Child_Relationship )
      {
         cp_Child_Relationship.init( );

         p_obj->setup_graph_parent( *cp_Child_Relationship, c_field_id_Child_Relationship, v_Child_Relationship );
      }
      return *cp_Child_Relationship;
   }

   void impl_Child_Relationship( const string& key )
   {
      class_base_accessor cba( impl_Child_Relationship( ) );
      cba.set_key( key );
   }

   Meta_Specification_Type& impl_Child_Specification_Type( )
   {
      if( !cp_Child_Specification_Type )
      {
         cp_Child_Specification_Type.init( );

         p_obj->setup_graph_parent( *cp_Child_Specification_Type, c_field_id_Child_Specification_Type, v_Child_Specification_Type );
      }
      return *cp_Child_Specification_Type;
   }

   const Meta_Specification_Type& impl_Child_Specification_Type( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Child_Specification_Type )
      {
         cp_Child_Specification_Type.init( );

         p_obj->setup_graph_parent( *cp_Child_Specification_Type, c_field_id_Child_Specification_Type, v_Child_Specification_Type );
      }
      return *cp_Child_Specification_Type;
   }

   void impl_Child_Specification_Type( const string& key )
   {
      class_base_accessor cba( impl_Child_Specification_Type( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Class( )
   {
      if( !cp_Class )
      {
         cp_Class.init( );

         p_obj->setup_graph_parent( *cp_Class, c_field_id_Class, v_Class );
      }
      return *cp_Class;
   }

   const Meta_Class& impl_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Class )
      {
         cp_Class.init( );

         p_obj->setup_graph_parent( *cp_Class, c_field_id_Class, v_Class );
      }
      return *cp_Class;
   }

   void impl_Class( const string& key )
   {
      class_base_accessor cba( impl_Class( ) );
      cba.set_key( key );
   }

   Meta_Enum& impl_Enum( )
   {
      if( !cp_Enum )
      {
         cp_Enum.init( );

         p_obj->setup_graph_parent( *cp_Enum, c_field_id_Enum, v_Enum );
      }
      return *cp_Enum;
   }

   const Meta_Enum& impl_Enum( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Enum )
      {
         cp_Enum.init( );

         p_obj->setup_graph_parent( *cp_Enum, c_field_id_Enum, v_Enum );
      }
      return *cp_Enum;
   }

   void impl_Enum( const string& key )
   {
      class_base_accessor cba( impl_Enum( ) );
      cba.set_key( key );
   }

   Meta_Enum_Item& impl_Enum_Item( )
   {
      if( !cp_Enum_Item )
      {
         cp_Enum_Item.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item, c_field_id_Enum_Item, v_Enum_Item );
      }
      return *cp_Enum_Item;
   }

   const Meta_Enum_Item& impl_Enum_Item( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Enum_Item )
      {
         cp_Enum_Item.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item, c_field_id_Enum_Item, v_Enum_Item );
      }
      return *cp_Enum_Item;
   }

   void impl_Enum_Item( const string& key )
   {
      class_base_accessor cba( impl_Enum_Item( ) );
      cba.set_key( key );
   }

   Meta_Enum_Item& impl_Enum_Item_2( )
   {
      if( !cp_Enum_Item_2 )
      {
         cp_Enum_Item_2.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_2, c_field_id_Enum_Item_2, v_Enum_Item_2 );
      }
      return *cp_Enum_Item_2;
   }

   const Meta_Enum_Item& impl_Enum_Item_2( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Enum_Item_2 )
      {
         cp_Enum_Item_2.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_2, c_field_id_Enum_Item_2, v_Enum_Item_2 );
      }
      return *cp_Enum_Item_2;
   }

   void impl_Enum_Item_2( const string& key )
   {
      class_base_accessor cba( impl_Enum_Item_2( ) );
      cba.set_key( key );
   }

   Meta_Enum_Item& impl_Enum_Item_3( )
   {
      if( !cp_Enum_Item_3 )
      {
         cp_Enum_Item_3.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_3, c_field_id_Enum_Item_3, v_Enum_Item_3 );
      }
      return *cp_Enum_Item_3;
   }

   const Meta_Enum_Item& impl_Enum_Item_3( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Enum_Item_3 )
      {
         cp_Enum_Item_3.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_3, c_field_id_Enum_Item_3, v_Enum_Item_3 );
      }
      return *cp_Enum_Item_3;
   }

   void impl_Enum_Item_3( const string& key )
   {
      class_base_accessor cba( impl_Enum_Item_3( ) );
      cba.set_key( key );
   }

   Meta_Enum_Item& impl_Enum_Item_4( )
   {
      if( !cp_Enum_Item_4 )
      {
         cp_Enum_Item_4.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_4, c_field_id_Enum_Item_4, v_Enum_Item_4 );
      }
      return *cp_Enum_Item_4;
   }

   const Meta_Enum_Item& impl_Enum_Item_4( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Enum_Item_4 )
      {
         cp_Enum_Item_4.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_4, c_field_id_Enum_Item_4, v_Enum_Item_4 );
      }
      return *cp_Enum_Item_4;
   }

   void impl_Enum_Item_4( const string& key )
   {
      class_base_accessor cba( impl_Enum_Item_4( ) );
      cba.set_key( key );
   }

   Meta_Enum_Item& impl_Enum_Item_5( )
   {
      if( !cp_Enum_Item_5 )
      {
         cp_Enum_Item_5.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_5, c_field_id_Enum_Item_5, v_Enum_Item_5 );
      }
      return *cp_Enum_Item_5;
   }

   const Meta_Enum_Item& impl_Enum_Item_5( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Enum_Item_5 )
      {
         cp_Enum_Item_5.init( );

         p_obj->setup_graph_parent( *cp_Enum_Item_5, c_field_id_Enum_Item_5, v_Enum_Item_5 );
      }
      return *cp_Enum_Item_5;
   }

   void impl_Enum_Item_5( const string& key )
   {
      class_base_accessor cba( impl_Enum_Item_5( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Field( )
   {
      if( !cp_Field )
      {
         cp_Field.init( );

         p_obj->setup_graph_parent( *cp_Field, c_field_id_Field, v_Field );
      }
      return *cp_Field;
   }

   const Meta_Field& impl_Field( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Field )
      {
         cp_Field.init( );

         p_obj->setup_graph_parent( *cp_Field, c_field_id_Field, v_Field );
      }
      return *cp_Field;
   }

   void impl_Field( const string& key )
   {
      class_base_accessor cba( impl_Field( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Field_Class( )
   {
      if( !cp_Field_Class )
      {
         cp_Field_Class.init( );

         p_obj->setup_graph_parent( *cp_Field_Class, c_field_id_Field_Class, v_Field_Class );
      }
      return *cp_Field_Class;
   }

   const Meta_Class& impl_Field_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Field_Class )
      {
         cp_Field_Class.init( );

         p_obj->setup_graph_parent( *cp_Field_Class, c_field_id_Field_Class, v_Field_Class );
      }
      return *cp_Field_Class;
   }

   void impl_Field_Class( const string& key )
   {
      class_base_accessor cba( impl_Field_Class( ) );
      cba.set_key( key );
   }

   Meta_Model& impl_Model( )
   {
      if( !cp_Model )
      {
         cp_Model.init( );

         p_obj->setup_graph_parent( *cp_Model, c_field_id_Model, v_Model );
      }
      return *cp_Model;
   }

   const Meta_Model& impl_Model( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Model )
      {
         cp_Model.init( );

         p_obj->setup_graph_parent( *cp_Model, c_field_id_Model, v_Model );
      }
      return *cp_Model;
   }

   void impl_Model( const string& key )
   {
      class_base_accessor cba( impl_Model( ) );
      cba.set_key( key );
   }

   Meta_Modifier& impl_Modifier( )
   {
      if( !cp_Modifier )
      {
         cp_Modifier.init( );

         p_obj->setup_graph_parent( *cp_Modifier, c_field_id_Modifier, v_Modifier );
      }
      return *cp_Modifier;
   }

   const Meta_Modifier& impl_Modifier( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Modifier )
      {
         cp_Modifier.init( );

         p_obj->setup_graph_parent( *cp_Modifier, c_field_id_Modifier, v_Modifier );
      }
      return *cp_Modifier;
   }

   void impl_Modifier( const string& key )
   {
      class_base_accessor cba( impl_Modifier( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Other_Class( )
   {
      if( !cp_Other_Class )
      {
         cp_Other_Class.init( );

         p_obj->setup_graph_parent( *cp_Other_Class, c_field_id_Other_Class, v_Other_Class );
      }
      return *cp_Other_Class;
   }

   const Meta_Class& impl_Other_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Other_Class )
      {
         cp_Other_Class.init( );

         p_obj->setup_graph_parent( *cp_Other_Class, c_field_id_Other_Class, v_Other_Class );
      }
      return *cp_Other_Class;
   }

   void impl_Other_Class( const string& key )
   {
      class_base_accessor cba( impl_Other_Class( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Other_Field( )
   {
      if( !cp_Other_Field )
      {
         cp_Other_Field.init( );

         p_obj->setup_graph_parent( *cp_Other_Field, c_field_id_Other_Field, v_Other_Field );
      }
      return *cp_Other_Field;
   }

   const Meta_Field& impl_Other_Field( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Other_Field )
      {
         cp_Other_Field.init( );

         p_obj->setup_graph_parent( *cp_Other_Field, c_field_id_Other_Field, v_Other_Field );
      }
      return *cp_Other_Field;
   }

   void impl_Other_Field( const string& key )
   {
      class_base_accessor cba( impl_Other_Field( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Other_Field_2( )
   {
      if( !cp_Other_Field_2 )
      {
         cp_Other_Field_2.init( );

         p_obj->setup_graph_parent( *cp_Other_Field_2, c_field_id_Other_Field_2, v_Other_Field_2 );
      }
      return *cp_Other_Field_2;
   }

   const Meta_Field& impl_Other_Field_2( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Other_Field_2 )
      {
         cp_Other_Field_2.init( );

         p_obj->setup_graph_parent( *cp_Other_Field_2, c_field_id_Other_Field_2, v_Other_Field_2 );
      }
      return *cp_Other_Field_2;
   }

   void impl_Other_Field_2( const string& key )
   {
      class_base_accessor cba( impl_Other_Field_2( ) );
      cba.set_key( key );
   }

   Meta_Procedure& impl_Other_Procedure( )
   {
      if( !cp_Other_Procedure )
      {
         cp_Other_Procedure.init( );

         p_obj->setup_graph_parent( *cp_Other_Procedure, c_field_id_Other_Procedure, v_Other_Procedure );
      }
      return *cp_Other_Procedure;
   }

   const Meta_Procedure& impl_Other_Procedure( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Other_Procedure )
      {
         cp_Other_Procedure.init( );

         p_obj->setup_graph_parent( *cp_Other_Procedure, c_field_id_Other_Procedure, v_Other_Procedure );
      }
      return *cp_Other_Procedure;
   }

   void impl_Other_Procedure( const string& key )
   {
      class_base_accessor cba( impl_Other_Procedure( ) );
      cba.set_key( key );
   }

   Meta_Procedure& impl_Other_Procedure_2( )
   {
      if( !cp_Other_Procedure_2 )
      {
         cp_Other_Procedure_2.init( );

         p_obj->setup_graph_parent( *cp_Other_Procedure_2, c_field_id_Other_Procedure_2, v_Other_Procedure_2 );
      }
      return *cp_Other_Procedure_2;
   }

   const Meta_Procedure& impl_Other_Procedure_2( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Other_Procedure_2 )
      {
         cp_Other_Procedure_2.init( );

         p_obj->setup_graph_parent( *cp_Other_Procedure_2, c_field_id_Other_Procedure_2, v_Other_Procedure_2 );
      }
      return *cp_Other_Procedure_2;
   }

   void impl_Other_Procedure_2( const string& key )
   {
      class_base_accessor cba( impl_Other_Procedure_2( ) );
      cba.set_key( key );
   }

   Meta_Specification& impl_Parent_Specification( )
   {
      if( !cp_Parent_Specification )
      {
         cp_Parent_Specification.init( );

         p_obj->setup_graph_parent( *cp_Parent_Specification, c_field_id_Parent_Specification, v_Parent_Specification );
      }
      return *cp_Parent_Specification;
   }

   const Meta_Specification& impl_Parent_Specification( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Parent_Specification )
      {
         cp_Parent_Specification.init( );

         p_obj->setup_graph_parent( *cp_Parent_Specification, c_field_id_Parent_Specification, v_Parent_Specification );
      }
      return *cp_Parent_Specification;
   }

   void impl_Parent_Specification( const string& key )
   {
      class_base_accessor cba( impl_Parent_Specification( ) );
      cba.set_key( key );
   }

   Meta_Specification_Copy_Child_Links& impl_Parent_Specification_Copy_Child_Links( )
   {
      if( !cp_Parent_Specification_Copy_Child_Links )
      {
         cp_Parent_Specification_Copy_Child_Links.init( );

         p_obj->setup_graph_parent( *cp_Parent_Specification_Copy_Child_Links, c_field_id_Parent_Specification_Copy_Child_Links, v_Parent_Specification_Copy_Child_Links );
      }
      return *cp_Parent_Specification_Copy_Child_Links;
   }

   const Meta_Specification_Copy_Child_Links& impl_Parent_Specification_Copy_Child_Links( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Parent_Specification_Copy_Child_Links )
      {
         cp_Parent_Specification_Copy_Child_Links.init( );

         p_obj->setup_graph_parent( *cp_Parent_Specification_Copy_Child_Links, c_field_id_Parent_Specification_Copy_Child_Links, v_Parent_Specification_Copy_Child_Links );
      }
      return *cp_Parent_Specification_Copy_Child_Links;
   }

   void impl_Parent_Specification_Copy_Child_Links( const string& key )
   {
      class_base_accessor cba( impl_Parent_Specification_Copy_Child_Links( ) );
      cba.set_key( key );
   }

   Meta_Permission& impl_Permission( )
   {
      if( !cp_Permission )
      {
         cp_Permission.init( );

         p_obj->setup_graph_parent( *cp_Permission, c_field_id_Permission, v_Permission );
      }
      return *cp_Permission;
   }

   const Meta_Permission& impl_Permission( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Permission )
      {
         cp_Permission.init( );

         p_obj->setup_graph_parent( *cp_Permission, c_field_id_Permission, v_Permission );
      }
      return *cp_Permission;
   }

   void impl_Permission( const string& key )
   {
      class_base_accessor cba( impl_Permission( ) );
      cba.set_key( key );
   }

   Meta_Procedure& impl_Procedure( )
   {
      if( !cp_Procedure )
      {
         cp_Procedure.init( );

         p_obj->setup_graph_parent( *cp_Procedure, c_field_id_Procedure, v_Procedure );
      }
      return *cp_Procedure;
   }

   const Meta_Procedure& impl_Procedure( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Procedure )
      {
         cp_Procedure.init( );

         p_obj->setup_graph_parent( *cp_Procedure, c_field_id_Procedure, v_Procedure );
      }
      return *cp_Procedure;
   }

   void impl_Procedure( const string& key )
   {
      class_base_accessor cba( impl_Procedure( ) );
      cba.set_key( key );
   }

   Meta_Procedure_Arg& impl_Procedure_Arg( )
   {
      if( !cp_Procedure_Arg )
      {
         cp_Procedure_Arg.init( );

         p_obj->setup_graph_parent( *cp_Procedure_Arg, c_field_id_Procedure_Arg, v_Procedure_Arg );
      }
      return *cp_Procedure_Arg;
   }

   const Meta_Procedure_Arg& impl_Procedure_Arg( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Procedure_Arg )
      {
         cp_Procedure_Arg.init( );

         p_obj->setup_graph_parent( *cp_Procedure_Arg, c_field_id_Procedure_Arg, v_Procedure_Arg );
      }
      return *cp_Procedure_Arg;
   }

   void impl_Procedure_Arg( const string& key )
   {
      class_base_accessor cba( impl_Procedure_Arg( ) );
      cba.set_key( key );
   }

   Meta_Procedure_Arg& impl_Procedure_Arg_2( )
   {
      if( !cp_Procedure_Arg_2 )
      {
         cp_Procedure_Arg_2.init( );

         p_obj->setup_graph_parent( *cp_Procedure_Arg_2, c_field_id_Procedure_Arg_2, v_Procedure_Arg_2 );
      }
      return *cp_Procedure_Arg_2;
   }

   const Meta_Procedure_Arg& impl_Procedure_Arg_2( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Procedure_Arg_2 )
      {
         cp_Procedure_Arg_2.init( );

         p_obj->setup_graph_parent( *cp_Procedure_Arg_2, c_field_id_Procedure_Arg_2, v_Procedure_Arg_2 );
      }
      return *cp_Procedure_Arg_2;
   }

   void impl_Procedure_Arg_2( const string& key )
   {
      class_base_accessor cba( impl_Procedure_Arg_2( ) );
      cba.set_key( key );
   }

   Meta_Procedure_Arg& impl_Procedure_Arg_3( )
   {
      if( !cp_Procedure_Arg_3 )
      {
         cp_Procedure_Arg_3.init( );

         p_obj->setup_graph_parent( *cp_Procedure_Arg_3, c_field_id_Procedure_Arg_3, v_Procedure_Arg_3 );
      }
      return *cp_Procedure_Arg_3;
   }

   const Meta_Procedure_Arg& impl_Procedure_Arg_3( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Procedure_Arg_3 )
      {
         cp_Procedure_Arg_3.init( );

         p_obj->setup_graph_parent( *cp_Procedure_Arg_3, c_field_id_Procedure_Arg_3, v_Procedure_Arg_3 );
      }
      return *cp_Procedure_Arg_3;
   }

   void impl_Procedure_Arg_3( const string& key )
   {
      class_base_accessor cba( impl_Procedure_Arg_3( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Source_Child( )
   {
      if( !cp_Source_Child )
      {
         cp_Source_Child.init( );

         p_obj->setup_graph_parent( *cp_Source_Child, c_field_id_Source_Child, v_Source_Child );
      }
      return *cp_Source_Child;
   }

   const Meta_Field& impl_Source_Child( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Child )
      {
         cp_Source_Child.init( );

         p_obj->setup_graph_parent( *cp_Source_Child, c_field_id_Source_Child, v_Source_Child );
      }
      return *cp_Source_Child;
   }

   void impl_Source_Child( const string& key )
   {
      class_base_accessor cba( impl_Source_Child( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Source_Child_2( )
   {
      if( !cp_Source_Child_2 )
      {
         cp_Source_Child_2.init( );

         p_obj->setup_graph_parent( *cp_Source_Child_2, c_field_id_Source_Child_2, v_Source_Child_2 );
      }
      return *cp_Source_Child_2;
   }

   const Meta_Field& impl_Source_Child_2( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Child_2 )
      {
         cp_Source_Child_2.init( );

         p_obj->setup_graph_parent( *cp_Source_Child_2, c_field_id_Source_Child_2, v_Source_Child_2 );
      }
      return *cp_Source_Child_2;
   }

   void impl_Source_Child_2( const string& key )
   {
      class_base_accessor cba( impl_Source_Child_2( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Source_Child_Class( )
   {
      if( !cp_Source_Child_Class )
      {
         cp_Source_Child_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Child_Class, c_field_id_Source_Child_Class, v_Source_Child_Class );
      }
      return *cp_Source_Child_Class;
   }

   const Meta_Class& impl_Source_Child_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Child_Class )
      {
         cp_Source_Child_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Child_Class, c_field_id_Source_Child_Class, v_Source_Child_Class );
      }
      return *cp_Source_Child_Class;
   }

   void impl_Source_Child_Class( const string& key )
   {
      class_base_accessor cba( impl_Source_Child_Class( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Source_Class( )
   {
      if( !cp_Source_Class )
      {
         cp_Source_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Class, c_field_id_Source_Class, v_Source_Class );
      }
      return *cp_Source_Class;
   }

   const Meta_Class& impl_Source_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Class )
      {
         cp_Source_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Class, c_field_id_Source_Class, v_Source_Class );
      }
      return *cp_Source_Class;
   }

   void impl_Source_Class( const string& key )
   {
      class_base_accessor cba( impl_Source_Class( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Source_Field( )
   {
      if( !cp_Source_Field )
      {
         cp_Source_Field.init( );

         p_obj->setup_graph_parent( *cp_Source_Field, c_field_id_Source_Field, v_Source_Field );
      }
      return *cp_Source_Field;
   }

   const Meta_Field& impl_Source_Field( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Field )
      {
         cp_Source_Field.init( );

         p_obj->setup_graph_parent( *cp_Source_Field, c_field_id_Source_Field, v_Source_Field );
      }
      return *cp_Source_Field;
   }

   void impl_Source_Field( const string& key )
   {
      class_base_accessor cba( impl_Source_Field( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Source_Field_Class( )
   {
      if( !cp_Source_Field_Class )
      {
         cp_Source_Field_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Field_Class, c_field_id_Source_Field_Class, v_Source_Field_Class );
      }
      return *cp_Source_Field_Class;
   }

   const Meta_Class& impl_Source_Field_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Field_Class )
      {
         cp_Source_Field_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Field_Class, c_field_id_Source_Field_Class, v_Source_Field_Class );
      }
      return *cp_Source_Field_Class;
   }

   void impl_Source_Field_Class( const string& key )
   {
      class_base_accessor cba( impl_Source_Field_Class( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Source_Grandchild( )
   {
      if( !cp_Source_Grandchild )
      {
         cp_Source_Grandchild.init( );

         p_obj->setup_graph_parent( *cp_Source_Grandchild, c_field_id_Source_Grandchild, v_Source_Grandchild );
      }
      return *cp_Source_Grandchild;
   }

   const Meta_Field& impl_Source_Grandchild( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Grandchild )
      {
         cp_Source_Grandchild.init( );

         p_obj->setup_graph_parent( *cp_Source_Grandchild, c_field_id_Source_Grandchild, v_Source_Grandchild );
      }
      return *cp_Source_Grandchild;
   }

   void impl_Source_Grandchild( const string& key )
   {
      class_base_accessor cba( impl_Source_Grandchild( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Source_Parent( )
   {
      if( !cp_Source_Parent )
      {
         cp_Source_Parent.init( );

         p_obj->setup_graph_parent( *cp_Source_Parent, c_field_id_Source_Parent, v_Source_Parent );
      }
      return *cp_Source_Parent;
   }

   const Meta_Field& impl_Source_Parent( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Parent )
      {
         cp_Source_Parent.init( );

         p_obj->setup_graph_parent( *cp_Source_Parent, c_field_id_Source_Parent, v_Source_Parent );
      }
      return *cp_Source_Parent;
   }

   void impl_Source_Parent( const string& key )
   {
      class_base_accessor cba( impl_Source_Parent( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Source_Parent_Class( )
   {
      if( !cp_Source_Parent_Class )
      {
         cp_Source_Parent_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Parent_Class, c_field_id_Source_Parent_Class, v_Source_Parent_Class );
      }
      return *cp_Source_Parent_Class;
   }

   const Meta_Class& impl_Source_Parent_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Source_Parent_Class )
      {
         cp_Source_Parent_Class.init( );

         p_obj->setup_graph_parent( *cp_Source_Parent_Class, c_field_id_Source_Parent_Class, v_Source_Parent_Class );
      }
      return *cp_Source_Parent_Class;
   }

   void impl_Source_Parent_Class( const string& key )
   {
      class_base_accessor cba( impl_Source_Parent_Class( ) );
      cba.set_key( key );
   }

   Meta_Specification_Type& impl_Specification_Type( )
   {
      if( !cp_Specification_Type )
      {
         cp_Specification_Type.init( );

         p_obj->setup_graph_parent( *cp_Specification_Type, c_field_id_Specification_Type, v_Specification_Type );
      }
      return *cp_Specification_Type;
   }

   const Meta_Specification_Type& impl_Specification_Type( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Specification_Type )
      {
         cp_Specification_Type.init( );

         p_obj->setup_graph_parent( *cp_Specification_Type, c_field_id_Specification_Type, v_Specification_Type );
      }
      return *cp_Specification_Type;
   }

   void impl_Specification_Type( const string& key )
   {
      class_base_accessor cba( impl_Specification_Type( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Test_Child( )
   {
      if( !cp_Test_Child )
      {
         cp_Test_Child.init( );

         p_obj->setup_graph_parent( *cp_Test_Child, c_field_id_Test_Child, v_Test_Child );
      }
      return *cp_Test_Child;
   }

   const Meta_Field& impl_Test_Child( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Test_Child )
      {
         cp_Test_Child.init( );

         p_obj->setup_graph_parent( *cp_Test_Child, c_field_id_Test_Child, v_Test_Child );
      }
      return *cp_Test_Child;
   }

   void impl_Test_Child( const string& key )
   {
      class_base_accessor cba( impl_Test_Child( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Test_Field( )
   {
      if( !cp_Test_Field )
      {
         cp_Test_Field.init( );

         p_obj->setup_graph_parent( *cp_Test_Field, c_field_id_Test_Field, v_Test_Field );
      }
      return *cp_Test_Field;
   }

   const Meta_Field& impl_Test_Field( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Test_Field )
      {
         cp_Test_Field.init( );

         p_obj->setup_graph_parent( *cp_Test_Field, c_field_id_Test_Field, v_Test_Field );
      }
      return *cp_Test_Field;
   }

   void impl_Test_Field( const string& key )
   {
      class_base_accessor cba( impl_Test_Field( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Test_Field_Class( )
   {
      if( !cp_Test_Field_Class )
      {
         cp_Test_Field_Class.init( );

         p_obj->setup_graph_parent( *cp_Test_Field_Class, c_field_id_Test_Field_Class, v_Test_Field_Class );
      }
      return *cp_Test_Field_Class;
   }

   const Meta_Class& impl_Test_Field_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Test_Field_Class )
      {
         cp_Test_Field_Class.init( );

         p_obj->setup_graph_parent( *cp_Test_Field_Class, c_field_id_Test_Field_Class, v_Test_Field_Class );
      }
      return *cp_Test_Field_Class;
   }

   void impl_Test_Field_Class( const string& key )
   {
      class_base_accessor cba( impl_Test_Field_Class( ) );
      cba.set_key( key );
   }

   Meta_Field& impl_Test_Parent( )
   {
      if( !cp_Test_Parent )
      {
         cp_Test_Parent.init( );

         p_obj->setup_graph_parent( *cp_Test_Parent, c_field_id_Test_Parent, v_Test_Parent );
      }
      return *cp_Test_Parent;
   }

   const Meta_Field& impl_Test_Parent( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Test_Parent )
      {
         cp_Test_Parent.init( );

         p_obj->setup_graph_parent( *cp_Test_Parent, c_field_id_Test_Parent, v_Test_Parent );
      }
      return *cp_Test_Parent;
   }

   void impl_Test_Parent( const string& key )
   {
      class_base_accessor cba( impl_Test_Parent( ) );
      cba.set_key( key );
   }

   Meta_Class& impl_Test_Parent_Class( )
   {
      if( !cp_Test_Parent_Class )
      {
         cp_Test_Parent_Class.init( );

         p_obj->setup_graph_parent( *cp_Test_Parent_Class, c_field_id_Test_Parent_Class, v_Test_Parent_Class );
      }
      return *cp_Test_Parent_Class;
   }

   const Meta_Class& impl_Test_Parent_Class( ) const
   {
      lazy_fetch( p_obj );

      if( !cp_Test_Parent_Class )
      {
         cp_Test_Parent_Class.init( );

         p_obj->setup_graph_parent( *cp_Test_Parent_Class, c_field_id_Test_Parent_Class, v_Test_Parent_Class );
      }
      return *cp_Test_Parent_Class;
   }

   void impl_Test_Parent_Class( const string& key )
   {
      class_base_accessor cba( impl_Test_Parent_Class( ) );
      cba.set_key( key );
   }

   Meta_Specification& impl_child_Specification_Parent( )
   {
      if( !cp_child_Specification_Parent )
      {
         cp_child_Specification_Parent.init( );

         p_obj->setup_graph_parent( *cp_child_Specification_Parent, "301405" );
      }
      return *cp_child_Specification_Parent;
   }

   const Meta_Specification& impl_child_Specification_Parent( ) const
   {
      if( !cp_child_Specification_Parent )
      {
         cp_child_Specification_Parent.init( );

         p_obj->setup_graph_parent( *cp_child_Specification_Parent, "301405" );
      }
      return *cp_child_Specification_Parent;
   }

   Meta_List_Field& impl_child_List_Field_Restriction_Spec( )
   {
      if( !cp_child_List_Field_Restriction_Spec )
      {
         cp_child_List_Field_Restriction_Spec.init( );

         p_obj->setup_graph_parent( *cp_child_List_Field_Restriction_Spec, "302180" );
      }
      return *cp_child_List_Field_Restriction_Spec;
   }

   const Meta_List_Field& impl_child_List_Field_Restriction_Spec( ) const
   {
      if( !cp_child_List_Field_Restriction_Spec )
      {
         cp_child_List_Field_Restriction_Spec.init( );

         p_obj->setup_graph_parent( *cp_child_List_Field_Restriction_Spec, "302180" );
      }
      return *cp_child_List_Field_Restriction_Spec;
   }

   Meta_View_Field& impl_child_View_Field_Restriction_Spec( )
   {
      if( !cp_child_View_Field_Restriction_Spec )
      {
         cp_child_View_Field_Restriction_Spec.init( );

         p_obj->setup_graph_parent( *cp_child_View_Field_Restriction_Spec, "301980" );
      }
      return *cp_child_View_Field_Restriction_Spec;
   }

   const Meta_View_Field& impl_child_View_Field_Restriction_Spec( ) const
   {
      if( !cp_child_View_Field_Restriction_Spec )
      {
         cp_child_View_Field_Restriction_Spec.init( );

         p_obj->setup_graph_parent( *cp_child_View_Field_Restriction_Spec, "301980" );
      }
      return *cp_child_View_Field_Restriction_Spec;
   }

   void impl_Add_Arg_1( );

   void impl_Add_Arg_2( );

   void impl_Add_Child_Info( );

   void impl_Add_Extra_Info( );

   void impl_Add_Field( );

   void impl_Add_Field_Pair( );

   void impl_Add_Grandchild_Info( );

   void impl_Add_Info( );

   void impl_Add_Next( );

   void impl_Add_Opt_Info( );

   void impl_Add_Other_Info( );

   void impl_Add_Secondary( );

   void impl_Add_Source_Info( );

   void impl_Add_Stats_1( );

   void impl_Add_Stats_2( );

   void impl_Add_Stats_Info( );

   void impl_Generate_All_Strings( string& All_Strings, const string& Parent_Prefix );

   void impl_Generate_All_Vars( string& All_Vars, const string& Parent_Prefix );

   void impl_Move_Down( const string& Restrict_Fields, const string& Restrict_Values );

   void impl_Move_Up( const string& Restrict_Fields, const string& Restrict_Values );

   string get_field_value( int field ) const;
   void set_field_value( int field, const string& value );

   uint64_t get_state( ) const;

   const string& execute( const string& cmd_and_args );

   void clear_foreign_key( const string& field );

   void set_foreign_key_value( const string& field, const string& value );

   const string& get_foreign_key_value( const string& field );

   void get_foreign_key_values( foreign_key_data_container& foreign_key_values ) const;

   void clear( );

   bool value_will_be_provided( const string& field_name );

   void validate( unsigned state, bool is_internal, validation_error_container* p_validation_errors );

   void after_fetch( );
   void finalise_fetch( );

   void at_create( );

   void to_store( bool is_create, bool is_internal );
   void for_store( bool is_create, bool is_internal );
   void after_store( bool is_create, bool is_internal );

   bool can_destroy( bool is_internal );
   void for_destroy( bool is_internal );
   void after_destroy( bool is_internal );

   void set_default_values( );

   bool is_filtered( const set< string >& filters ) const;

   Meta_Specification* p_obj;
   class_pointer< Meta_Specification > cp_obj;

   // [<start members>]
   // [<finish members>]

   size_t total_child_relationships;

   string v_Actions;
   string v_All_Strings;
   string v_All_Vars;
   string v_Child_Rel_Field_Key;
   string v_Comments;
   string v_Field_Pairs;
   string v_Field_Values;
   string v_Fields;
   string v_Id;
   bool v_Is_Required_For_UI_Gen;
   string v_Name;
   string v_Options;
   string v_Order;
   bool v_Protect_Child_Rel;
   bool v_Protect_Procedure;
   bool v_Protect_Source_Parent;
   string v_Restrict_Values;
   string v_Strings;
   string v_Test_Value;
   bool v_Use_Source_Parent;
   bool v_Use_Test_Parent_Child;
   string v_Value;
   string v_Value_Left_Part;
   string v_Value_Literal;
   string v_Value_Numeric_String;
   string v_Value_Right_Part;
   string v_Value_String;
   string v_Vars;

   string v_Child_Rel_Child_Class;
   mutable class_pointer< Meta_Class > cp_Child_Rel_Child_Class;

   string v_Child_Relationship;
   mutable class_pointer< Meta_Relationship > cp_Child_Relationship;

   string v_Child_Specification_Type;
   mutable class_pointer< Meta_Specification_Type > cp_Child_Specification_Type;

   string v_Class;
   mutable class_pointer< Meta_Class > cp_Class;

   string v_Enum;
   mutable class_pointer< Meta_Enum > cp_Enum;

   string v_Enum_Item;
   mutable class_pointer< Meta_Enum_Item > cp_Enum_Item;

   string v_Enum_Item_2;
   mutable class_pointer< Meta_Enum_Item > cp_Enum_Item_2;

   string v_Enum_Item_3;
   mutable class_pointer< Meta_Enum_Item > cp_Enum_Item_3;

   string v_Enum_Item_4;
   mutable class_pointer< Meta_Enum_Item > cp_Enum_Item_4;

   string v_Enum_Item_5;
   mutable class_pointer< Meta_Enum_Item > cp_Enum_Item_5;

   string v_Field;
   mutable class_pointer< Meta_Field > cp_Field;

   string v_Field_Class;
   mutable class_pointer< Meta_Class > cp_Field_Class;

   string v_Model;
   mutable class_pointer< Meta_Model > cp_Model;

   string v_Modifier;
   mutable class_pointer< Meta_Modifier > cp_Modifier;

   string v_Other_Class;
   mutable class_pointer< Meta_Class > cp_Other_Class;

   string v_Other_Field;
   mutable class_pointer< Meta_Field > cp_Other_Field;

   string v_Other_Field_2;
   mutable class_pointer< Meta_Field > cp_Other_Field_2;

   string v_Other_Procedure;
   mutable class_pointer< Meta_Procedure > cp_Other_Procedure;

   string v_Other_Procedure_2;
   mutable class_pointer< Meta_Procedure > cp_Other_Procedure_2;

   string v_Parent_Specification;
   mutable class_pointer< Meta_Specification > cp_Parent_Specification;

   string v_Parent_Specification_Copy_Child_Links;
   mutable class_pointer< Meta_Specification_Copy_Child_Links > cp_Parent_Specification_Copy_Child_Links;

   string v_Permission;
   mutable class_pointer< Meta_Permission > cp_Permission;

   string v_Procedure;
   mutable class_pointer< Meta_Procedure > cp_Procedure;

   string v_Procedure_Arg;
   mutable class_pointer< Meta_Procedure_Arg > cp_Procedure_Arg;

   string v_Procedure_Arg_2;
   mutable class_pointer< Meta_Procedure_Arg > cp_Procedure_Arg_2;

   string v_Procedure_Arg_3;
   mutable class_pointer< Meta_Procedure_Arg > cp_Procedure_Arg_3;

   string v_Source_Child;
   mutable class_pointer< Meta_Field > cp_Source_Child;

   string v_Source_Child_2;
   mutable class_pointer< Meta_Field > cp_Source_Child_2;

   string v_Source_Child_Class;
   mutable class_pointer< Meta_Class > cp_Source_Child_Class;

   string v_Source_Class;
   mutable class_pointer< Meta_Class > cp_Source_Class;

   string v_Source_Field;
   mutable class_pointer< Meta_Field > cp_Source_Field;

   string v_Source_Field_Class;
   mutable class_pointer< Meta_Class > cp_Source_Field_Class;

   string v_Source_Grandchild;
   mutable class_pointer< Meta_Field > cp_Source_Grandchild;

   string v_Source_Parent;
   mutable class_pointer< Meta_Field > cp_Source_Parent;

   string v_Source_Parent_Class;
   mutable class_pointer< Meta_Class > cp_Source_Parent_Class;

   string v_Specification_Type;
   mutable class_pointer< Meta_Specification_Type > cp_Specification_Type;

   string v_Test_Child;
   mutable class_pointer< Meta_Field > cp_Test_Child;

   string v_Test_Field;
   mutable class_pointer< Meta_Field > cp_Test_Field;

   string v_Test_Field_Class;
   mutable class_pointer< Meta_Class > cp_Test_Field_Class;

   string v_Test_Parent;
   mutable class_pointer< Meta_Field > cp_Test_Parent;

   string v_Test_Parent_Class;
   mutable class_pointer< Meta_Class > cp_Test_Parent_Class;

   mutable class_pointer< Meta_Specification > cp_child_Specification_Parent;
   mutable class_pointer< Meta_List_Field > cp_child_List_Field_Restriction_Spec;
   mutable class_pointer< Meta_View_Field > cp_child_View_Field_Restriction_Spec;
};

void Meta_Specification::impl::impl_Add_Arg_1( )
{
   // [<start Add_Arg_1_impl>]
   // [<finish Add_Arg_1_impl>]
}

void Meta_Specification::impl::impl_Add_Arg_2( )
{
   // [<start Add_Arg_2_impl>]
   // [<finish Add_Arg_2_impl>]
}

void Meta_Specification::impl::impl_Add_Child_Info( )
{
   // [<start Add_Child_Info_impl>]
   // [<finish Add_Child_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Extra_Info( )
{
   // [<start Add_Extra_Info_impl>]
   // [<finish Add_Extra_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Field( )
{
   // [<start Add_Field_impl>]
   // [<finish Add_Field_impl>]
}

void Meta_Specification::impl::impl_Add_Field_Pair( )
{
   // [<start Add_Field_Pair_impl>]
   // [<finish Add_Field_Pair_impl>]
}

void Meta_Specification::impl::impl_Add_Grandchild_Info( )
{
   // [<start Add_Grandchild_Info_impl>]
   // [<finish Add_Grandchild_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Info( )
{
   // [<start Add_Info_impl>]
   // [<finish Add_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Next( )
{
   // [<start Add_Next_impl>]
   // [<finish Add_Next_impl>]
}

void Meta_Specification::impl::impl_Add_Opt_Info( )
{
   // [<start Add_Opt_Info_impl>]
   // [<finish Add_Opt_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Other_Info( )
{
   // [<start Add_Other_Info_impl>]
   // [<finish Add_Other_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Secondary( )
{
   // [<start Add_Secondary_impl>]
   // [<finish Add_Secondary_impl>]
}

void Meta_Specification::impl::impl_Add_Source_Info( )
{
   // [<start Add_Source_Info_impl>]
   // [<finish Add_Source_Info_impl>]
}

void Meta_Specification::impl::impl_Add_Stats_1( )
{
   // [<start Add_Stats_1_impl>]
   // [<finish Add_Stats_1_impl>]
}

void Meta_Specification::impl::impl_Add_Stats_2( )
{
   // [<start Add_Stats_2_impl>]
   // [<finish Add_Stats_2_impl>]
}

void Meta_Specification::impl::impl_Add_Stats_Info( )
{
   // [<start Add_Stats_Info_impl>]
   // [<finish Add_Stats_Info_impl>]
}

void Meta_Specification::impl::impl_Generate_All_Strings( string& All_Strings, const string& Parent_Prefix )
{
   // [<start Generate_All_Strings_impl>]
//idk
   // NOTE: If a recovery is in progress or a cascade is in progress then do nothing.
   if( storage_locked_for_admin( ) || get_obj( ).get_is_being_cascaded( ) )
      return;

   if( get_obj( ).get_key( ).empty( ) )
      throw runtime_error( "unexpected call to Meta_Specification::Generate_All_Strings" );

   string strings( get_obj( ).Strings( ) );

   if( get_obj( ).child_Specification_Parent( ).iterate_forwards( "", to_string( c_field_id_Strings ) ) )
   {
      do
      {
         string child_strings;
         get_obj( ).child_Specification_Parent( ).Generate_All_Strings( child_strings, get_obj( ).Specification_Type( ).Child_Prefix( ) );

         if( !child_strings.empty( ) )
         {
            if( !strings.empty( ) )
               strings += "\r\n";
            strings += child_strings;
         }

      } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );
   }

   map< string, string > all_strings;
   string initial_strings( strings );
   string::size_type pos = 0;

   while( !strings.empty( ) )
   {
      pos = strings.find( "\r\n" );
      string next( strings.substr( 0, pos ) );

      if( !Parent_Prefix.empty( ) )
         next = Parent_Prefix + "_" + next;

      string::size_type npos = next.find( '=' );
      if( npos == string::npos )
         throw runtime_error( "unexpected format for specification strings '" + initial_strings + "'" );

      all_strings[ next.substr( 0, npos ) ] = next.substr( npos + 1 );

      if( pos == string::npos )
         break;

      strings.erase( 0, pos + 2 );
   }

   for( map< string, string >::const_iterator i = all_strings.begin( ), end = all_strings.end( ); i != end; ++i )
   {
      if( !All_Strings.empty( ) )
         All_Strings += "\r\n";
      All_Strings += i->first + '=' + i->second;
   }
   // [<finish Generate_All_Strings_impl>]
}

void Meta_Specification::impl::impl_Generate_All_Vars( string& All_Vars, const string& Parent_Prefix )
{
   // [<start Generate_All_Vars_impl>]
//idk
   // NOTE: If a recovery is in progress or a cascade is in progress then do nothing.
   if( storage_locked_for_admin( ) || get_obj( ).get_is_being_cascaded( ) )
      return;

   if( get_obj( ).get_key( ).empty( ) )
      throw runtime_error( "unexpected call to Meta_Specification::Generate_All_Vars" );

   string vars( get_obj( ).Vars( ) );

   string def_vars( get_obj( ).Specification_Type( ).Default_Child_Vars( ) );
   if( !def_vars.empty( ) )
   {
      if( !vars.empty( ) )
         vars += "\r\n";
      vars += def_vars;
   }

   if( get_obj( ).child_Specification_Parent( ).iterate_forwards( "", to_string( c_field_id_Vars ) ) )
   {
      do
      {
         string child_vars;
         get_obj( ).child_Specification_Parent( ).Generate_All_Vars( child_vars, get_obj( ).Specification_Type( ).Child_Prefix( ) );

         if( !child_vars.empty( ) )
         {
            if( !vars.empty( ) )
               vars += "\r\n";
            vars += child_vars;
         }

      } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );
   }

   map< string, string > all_vars;
   string initial_vars( vars );
   string::size_type pos = 0;

   while( !vars.empty( ) )
   {
      pos = vars.find( "\r\n" );
      string next( vars.substr( 0, pos ) );

      if( !Parent_Prefix.empty( ) )
         next = Parent_Prefix + "_" + next;

      string::size_type npos = next.find( '=' );
      if( npos == string::npos )
         throw runtime_error( "unexpected format for specification vars '" + initial_vars + "'" );

      all_vars[ next.substr( 0, npos ) ] = next.substr( npos + 1 );

      if( pos == string::npos )
         break;

      vars.erase( 0, pos + 2 );
   }

   for( map< string, string >::const_iterator i = all_vars.begin( ), end = all_vars.end( ); i != end; ++i )
   {
      if( !All_Vars.empty( ) )
         All_Vars += "\r\n";
      All_Vars += i->first + "=" + i->second;
   }
   // [<finish Generate_All_Vars_impl>]
}

void Meta_Specification::impl::impl_Move_Down( const string& Restrict_Fields, const string& Restrict_Values )
{
   // [(start move_up_and_down)]
   transaction_start( );
   try
   {
      if( !Restrict_Fields.empty( ) )
      {
         get_obj( ).op_update( get_obj( ).get_key( ), c_field_name_Order );

         class_pointer< Meta_Specification > cp_other( e_create_instance );

         int num_fixed = 0;
         if( !Restrict_Fields.empty( ) )
            num_fixed = split_count( Restrict_Fields );

         string key_info( Restrict_Fields );
         if( num_fixed )
            key_info += ',';
         key_info += string( c_field_id_Order );

         if( !num_fixed )
            key_info += ' ' + get_obj( ).Order( );
         else
         {
            key_info += '#' + to_string( num_fixed );
            key_info += ' ' + Restrict_Values + ',' + get_obj( ).Order( );
         }

         // NOTE: Only the first record is required so set the row limit to 1.
         if( cp_other->iterate_forwards( key_info, string( c_field_name_Order ), false, 1 ) )
         {
            string old_val( get_obj( ).Order( ) );
            string new_val( cp_other->Order( ) );

            get_obj( ).Order( gen_key( ) );
            get_obj( ).op_apply( );

            get_obj( ).op_update( get_obj( ).get_key( ), c_field_name_Order );

            cp_other->op_update( cp_other->get_key( ), c_field_name_Order );
            cp_other->Order( old_val );
            cp_other->op_apply( );

            get_obj( ).Order( new_val );
            get_obj( ).op_apply( );

            cp_other->iterate_stop( );
         }
         else
            get_obj( ).op_cancel( );
      }
      else
      {
         // NOTE: This code block exists to handle legacy transactions that can only pass empty strings
         // to the restrict fields/values. Newer models should not specify parent/extra fields in their
         // "move_up_and_down" specifications as they are not needed when using restrict fields/values.
         get_obj( ).op_update( get_obj( ).get_key( ) );

         Meta_Model parent;
         parent.perform_fetch( get_obj( ).Model( ) );

         string key_info( c_field_id_Parent_Specification );
         key_info += ',' + string( c_field_id_Order );
         key_info += "#1 " + to_string( get_obj( ).Parent_Specification( ) ) + ',' + get_obj( ).Order( );
         // NOTE: Only the first record is required so set the row limit to 1.
         if( parent.child_Specification( ).iterate_forwards( key_info, false, 1 ) )
         {
            string old_val( get_obj( ).Order( ) );
            string new_val( parent.child_Specification( ).Order( ) );

            get_obj( ).Order( gen_key( ) );
            get_obj( ).op_apply( );

            get_obj( ).op_update( );

            parent.child_Specification( ).op_update( );
            parent.child_Specification( ).Order( old_val );
            parent.child_Specification( ).op_apply( );

            get_obj( ).Order( new_val );
            get_obj( ).op_apply( );

            parent.child_Specification( ).iterate_stop( );
         }
         else
            get_obj( ).op_cancel( );
      }

      transaction_commit( );
   }
   catch( ... )
   {
      transaction_rollback( );
      throw;
   }
   // [(finish move_up_and_down)]

   // [<start Move_Down_impl>]
   // [<finish Move_Down_impl>]
}

void Meta_Specification::impl::impl_Move_Up( const string& Restrict_Fields, const string& Restrict_Values )
{
   // [(start move_up_and_down)]
   transaction_start( );
   try
   {
      if( !Restrict_Fields.empty( ) )
      {
         get_obj( ).op_update( get_obj( ).get_key( ), c_field_name_Order );

         class_pointer< Meta_Specification > cp_other( e_create_instance );

         int num_fixed = 0;
         if( !Restrict_Fields.empty( ) )
            num_fixed = split_count( Restrict_Fields );

         string key_info( Restrict_Fields );
         if( num_fixed )
            key_info += ',';
         key_info += string( c_field_id_Order );

         if( !num_fixed )
            key_info += ' ' + get_obj( ).Order( );
         else
         {
            key_info += '#' + to_string( num_fixed );
            key_info += ' ' + Restrict_Values + ',' + get_obj( ).Order( );
         }

         // NOTE: Only the first record is required so set the row limit to 1.
         if( cp_other->iterate_backwards( key_info, string( c_field_name_Order ), false, 1 ) )
         {
            string old_val( get_obj( ).Order( ) );
            string new_val( cp_other->Order( ) );

            get_obj( ).Order( gen_key( ) );
            get_obj( ).op_apply( );

            get_obj( ).op_update( get_obj( ).get_key( ), c_field_name_Order );

            cp_other->op_update( cp_other->get_key( ), c_field_name_Order );
            cp_other->Order( old_val );
            cp_other->op_apply( );

            get_obj( ).Order( new_val );
            get_obj( ).op_apply( );

            cp_other->iterate_stop( );
         }
         else
            get_obj( ).op_cancel( );
      }
      else
      {
         // NOTE: This code block exists to handle legacy transactions that can only pass empty strings
         // to the restrict fields/values. Newer models should not specify parent/extra fields in their
         // "move_up_and_down" specifications as they are not needed when using restrict fields/values.
         get_obj( ).op_update( get_obj( ).get_key( ) );

         Meta_Model parent;
         parent.perform_fetch( get_obj( ).Model( ) );

         string key_info( c_field_id_Parent_Specification );
         key_info += ',' + string( c_field_id_Order );
         key_info += "#1 " + to_string( get_obj( ).Parent_Specification( ) ) + ',' + get_obj( ).Order( );
         // NOTE: Only the first record is required so set the row limit to 1.
         if( parent.child_Specification( ).iterate_backwards( key_info, false, 1 ) )
         {
            string old_val( get_obj( ).Order( ) );
            string new_val( parent.child_Specification( ).Order( ) );

            get_obj( ).Order( gen_key( ) );
            get_obj( ).op_apply( );

            get_obj( ).op_update( );

            parent.child_Specification( ).op_update( );
            parent.child_Specification( ).Order( old_val );
            parent.child_Specification( ).op_apply( );

            get_obj( ).Order( new_val );
            get_obj( ).op_apply( );

            parent.child_Specification( ).iterate_stop( );
         }
         else
            get_obj( ).op_cancel( );
      }

      transaction_commit( );
   }
   catch( ... )
   {
      transaction_rollback( );
      throw;
   }
   // [(finish move_up_and_down)]

   // [<start Move_Up_impl>]
   // [<finish Move_Up_impl>]
}

string Meta_Specification::impl::get_field_value( int field ) const
{
   string retval;

   switch( field )
   {
      case 0:
      retval = to_string( impl_Actions( ) );
      break;

      case 1:
      retval = to_string( impl_All_Strings( ) );
      break;

      case 2:
      retval = to_string( impl_All_Vars( ) );
      break;

      case 3:
      retval = to_string( impl_Child_Rel_Child_Class( ) );
      break;

      case 4:
      retval = to_string( impl_Child_Rel_Field_Key( ) );
      break;

      case 5:
      retval = to_string( impl_Child_Relationship( ) );
      break;

      case 6:
      retval = to_string( impl_Child_Specification_Type( ) );
      break;

      case 7:
      retval = to_string( impl_Class( ) );
      break;

      case 8:
      retval = to_string( impl_Comments( ) );
      break;

      case 9:
      retval = to_string( impl_Enum( ) );
      break;

      case 10:
      retval = to_string( impl_Enum_Item( ) );
      break;

      case 11:
      retval = to_string( impl_Enum_Item_2( ) );
      break;

      case 12:
      retval = to_string( impl_Enum_Item_3( ) );
      break;

      case 13:
      retval = to_string( impl_Enum_Item_4( ) );
      break;

      case 14:
      retval = to_string( impl_Enum_Item_5( ) );
      break;

      case 15:
      retval = to_string( impl_Field( ) );
      break;

      case 16:
      retval = to_string( impl_Field_Class( ) );
      break;

      case 17:
      retval = to_string( impl_Field_Pairs( ) );
      break;

      case 18:
      retval = to_string( impl_Field_Values( ) );
      break;

      case 19:
      retval = to_string( impl_Fields( ) );
      break;

      case 20:
      retval = to_string( impl_Id( ) );
      break;

      case 21:
      retval = to_string( impl_Is_Required_For_UI_Gen( ) );
      break;

      case 22:
      retval = to_string( impl_Model( ) );
      break;

      case 23:
      retval = to_string( impl_Modifier( ) );
      break;

      case 24:
      retval = to_string( impl_Name( ) );
      break;

      case 25:
      retval = to_string( impl_Options( ) );
      break;

      case 26:
      retval = to_string( impl_Order( ) );
      break;

      case 27:
      retval = to_string( impl_Other_Class( ) );
      break;

      case 28:
      retval = to_string( impl_Other_Field( ) );
      break;

      case 29:
      retval = to_string( impl_Other_Field_2( ) );
      break;

      case 30:
      retval = to_string( impl_Other_Procedure( ) );
      break;

      case 31:
      retval = to_string( impl_Other_Procedure_2( ) );
      break;

      case 32:
      retval = to_string( impl_Parent_Specification( ) );
      break;

      case 33:
      retval = to_string( impl_Parent_Specification_Copy_Child_Links( ) );
      break;

      case 34:
      retval = to_string( impl_Permission( ) );
      break;

      case 35:
      retval = to_string( impl_Procedure( ) );
      break;

      case 36:
      retval = to_string( impl_Procedure_Arg( ) );
      break;

      case 37:
      retval = to_string( impl_Procedure_Arg_2( ) );
      break;

      case 38:
      retval = to_string( impl_Procedure_Arg_3( ) );
      break;

      case 39:
      retval = to_string( impl_Protect_Child_Rel( ) );
      break;

      case 40:
      retval = to_string( impl_Protect_Procedure( ) );
      break;

      case 41:
      retval = to_string( impl_Protect_Source_Parent( ) );
      break;

      case 42:
      retval = to_string( impl_Restrict_Values( ) );
      break;

      case 43:
      retval = to_string( impl_Source_Child( ) );
      break;

      case 44:
      retval = to_string( impl_Source_Child_2( ) );
      break;

      case 45:
      retval = to_string( impl_Source_Child_Class( ) );
      break;

      case 46:
      retval = to_string( impl_Source_Class( ) );
      break;

      case 47:
      retval = to_string( impl_Source_Field( ) );
      break;

      case 48:
      retval = to_string( impl_Source_Field_Class( ) );
      break;

      case 49:
      retval = to_string( impl_Source_Grandchild( ) );
      break;

      case 50:
      retval = to_string( impl_Source_Parent( ) );
      break;

      case 51:
      retval = to_string( impl_Source_Parent_Class( ) );
      break;

      case 52:
      retval = to_string( impl_Specification_Type( ) );
      break;

      case 53:
      retval = to_string( impl_Strings( ) );
      break;

      case 54:
      retval = to_string( impl_Test_Child( ) );
      break;

      case 55:
      retval = to_string( impl_Test_Field( ) );
      break;

      case 56:
      retval = to_string( impl_Test_Field_Class( ) );
      break;

      case 57:
      retval = to_string( impl_Test_Parent( ) );
      break;

      case 58:
      retval = to_string( impl_Test_Parent_Class( ) );
      break;

      case 59:
      retval = to_string( impl_Test_Value( ) );
      break;

      case 60:
      retval = to_string( impl_Use_Source_Parent( ) );
      break;

      case 61:
      retval = to_string( impl_Use_Test_Parent_Child( ) );
      break;

      case 62:
      retval = to_string( impl_Value( ) );
      break;

      case 63:
      retval = to_string( impl_Value_Left_Part( ) );
      break;

      case 64:
      retval = to_string( impl_Value_Literal( ) );
      break;

      case 65:
      retval = to_string( impl_Value_Numeric_String( ) );
      break;

      case 66:
      retval = to_string( impl_Value_Right_Part( ) );
      break;

      case 67:
      retval = to_string( impl_Value_String( ) );
      break;

      case 68:
      retval = to_string( impl_Vars( ) );
      break;

      default:
      throw runtime_error( "field #" + to_string( field ) + " is out of range" );
   }

   return retval;
}

void Meta_Specification::impl::set_field_value( int field, const string& value )
{
   switch( field )
   {
      case 0:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Actions, value );
      break;

      case 1:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_All_Strings, value );
      break;

      case 2:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_All_Vars, value );
      break;

      case 3:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Child_Rel_Child_Class, value );
      break;

      case 4:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Child_Rel_Field_Key, value );
      break;

      case 5:
      func_string_setter< Meta_Specification::impl, Meta_Relationship >( *this, &Meta_Specification::impl::impl_Child_Relationship, value );
      break;

      case 6:
      func_string_setter< Meta_Specification::impl, Meta_Specification_Type >( *this, &Meta_Specification::impl::impl_Child_Specification_Type, value );
      break;

      case 7:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Class, value );
      break;

      case 8:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Comments, value );
      break;

      case 9:
      func_string_setter< Meta_Specification::impl, Meta_Enum >( *this, &Meta_Specification::impl::impl_Enum, value );
      break;

      case 10:
      func_string_setter< Meta_Specification::impl, Meta_Enum_Item >( *this, &Meta_Specification::impl::impl_Enum_Item, value );
      break;

      case 11:
      func_string_setter< Meta_Specification::impl, Meta_Enum_Item >( *this, &Meta_Specification::impl::impl_Enum_Item_2, value );
      break;

      case 12:
      func_string_setter< Meta_Specification::impl, Meta_Enum_Item >( *this, &Meta_Specification::impl::impl_Enum_Item_3, value );
      break;

      case 13:
      func_string_setter< Meta_Specification::impl, Meta_Enum_Item >( *this, &Meta_Specification::impl::impl_Enum_Item_4, value );
      break;

      case 14:
      func_string_setter< Meta_Specification::impl, Meta_Enum_Item >( *this, &Meta_Specification::impl::impl_Enum_Item_5, value );
      break;

      case 15:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Field, value );
      break;

      case 16:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Field_Class, value );
      break;

      case 17:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Field_Pairs, value );
      break;

      case 18:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Field_Values, value );
      break;

      case 19:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Fields, value );
      break;

      case 20:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Id, value );
      break;

      case 21:
      func_string_setter< Meta_Specification::impl, bool >( *this, &Meta_Specification::impl::impl_Is_Required_For_UI_Gen, value );
      break;

      case 22:
      func_string_setter< Meta_Specification::impl, Meta_Model >( *this, &Meta_Specification::impl::impl_Model, value );
      break;

      case 23:
      func_string_setter< Meta_Specification::impl, Meta_Modifier >( *this, &Meta_Specification::impl::impl_Modifier, value );
      break;

      case 24:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Name, value );
      break;

      case 25:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Options, value );
      break;

      case 26:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Order, value );
      break;

      case 27:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Other_Class, value );
      break;

      case 28:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Other_Field, value );
      break;

      case 29:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Other_Field_2, value );
      break;

      case 30:
      func_string_setter< Meta_Specification::impl, Meta_Procedure >( *this, &Meta_Specification::impl::impl_Other_Procedure, value );
      break;

      case 31:
      func_string_setter< Meta_Specification::impl, Meta_Procedure >( *this, &Meta_Specification::impl::impl_Other_Procedure_2, value );
      break;

      case 32:
      func_string_setter< Meta_Specification::impl, Meta_Specification >( *this, &Meta_Specification::impl::impl_Parent_Specification, value );
      break;

      case 33:
      func_string_setter< Meta_Specification::impl, Meta_Specification_Copy_Child_Links >( *this, &Meta_Specification::impl::impl_Parent_Specification_Copy_Child_Links, value );
      break;

      case 34:
      func_string_setter< Meta_Specification::impl, Meta_Permission >( *this, &Meta_Specification::impl::impl_Permission, value );
      break;

      case 35:
      func_string_setter< Meta_Specification::impl, Meta_Procedure >( *this, &Meta_Specification::impl::impl_Procedure, value );
      break;

      case 36:
      func_string_setter< Meta_Specification::impl, Meta_Procedure_Arg >( *this, &Meta_Specification::impl::impl_Procedure_Arg, value );
      break;

      case 37:
      func_string_setter< Meta_Specification::impl, Meta_Procedure_Arg >( *this, &Meta_Specification::impl::impl_Procedure_Arg_2, value );
      break;

      case 38:
      func_string_setter< Meta_Specification::impl, Meta_Procedure_Arg >( *this, &Meta_Specification::impl::impl_Procedure_Arg_3, value );
      break;

      case 39:
      func_string_setter< Meta_Specification::impl, bool >( *this, &Meta_Specification::impl::impl_Protect_Child_Rel, value );
      break;

      case 40:
      func_string_setter< Meta_Specification::impl, bool >( *this, &Meta_Specification::impl::impl_Protect_Procedure, value );
      break;

      case 41:
      func_string_setter< Meta_Specification::impl, bool >( *this, &Meta_Specification::impl::impl_Protect_Source_Parent, value );
      break;

      case 42:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Restrict_Values, value );
      break;

      case 43:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Source_Child, value );
      break;

      case 44:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Source_Child_2, value );
      break;

      case 45:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Source_Child_Class, value );
      break;

      case 46:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Source_Class, value );
      break;

      case 47:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Source_Field, value );
      break;

      case 48:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Source_Field_Class, value );
      break;

      case 49:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Source_Grandchild, value );
      break;

      case 50:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Source_Parent, value );
      break;

      case 51:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Source_Parent_Class, value );
      break;

      case 52:
      func_string_setter< Meta_Specification::impl, Meta_Specification_Type >( *this, &Meta_Specification::impl::impl_Specification_Type, value );
      break;

      case 53:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Strings, value );
      break;

      case 54:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Test_Child, value );
      break;

      case 55:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Test_Field, value );
      break;

      case 56:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Test_Field_Class, value );
      break;

      case 57:
      func_string_setter< Meta_Specification::impl, Meta_Field >( *this, &Meta_Specification::impl::impl_Test_Parent, value );
      break;

      case 58:
      func_string_setter< Meta_Specification::impl, Meta_Class >( *this, &Meta_Specification::impl::impl_Test_Parent_Class, value );
      break;

      case 59:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Test_Value, value );
      break;

      case 60:
      func_string_setter< Meta_Specification::impl, bool >( *this, &Meta_Specification::impl::impl_Use_Source_Parent, value );
      break;

      case 61:
      func_string_setter< Meta_Specification::impl, bool >( *this, &Meta_Specification::impl::impl_Use_Test_Parent_Child, value );
      break;

      case 62:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Value, value );
      break;

      case 63:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Value_Left_Part, value );
      break;

      case 64:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Value_Literal, value );
      break;

      case 65:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Value_Numeric_String, value );
      break;

      case 66:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Value_Right_Part, value );
      break;

      case 67:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Value_String, value );
      break;

      case 68:
      func_string_setter< Meta_Specification::impl, string >( *this, &Meta_Specification::impl::impl_Vars, value );
      break;

      default:
      throw runtime_error( "field #" + to_string( field ) + " is out of range" );
   }
}

uint64_t Meta_Specification::impl::get_state( ) const
{
   uint64_t state = 0;

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Other_Class( ) == false )
      state |= c_modifier_Hide_Other_Class;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Field( ) == false )
      state |= c_modifier_Hide_Field;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Other_Field( ) == false )
      state |= c_modifier_Hide_Other_Field;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Procedure( ) == false )
      state |= c_modifier_Hide_Procedure;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure_Arg( ) == false )
      state |= c_modifier_Hide_Procedure_Arg;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure_Arg_2( ) == false )
      state |= c_modifier_Hide_Procedure_Arg_2;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure_Arg_3( ) == false )
      state |= c_modifier_Hide_Procedure_Arg_3;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Procedure( ) == false )
      state |= c_modifier_Hide_Other_Procedure;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Procedure_2( ) == false )
      state |= c_modifier_Hide_Other_Procedure_2;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Modifier( ) == false )
      state |= c_modifier_Hide_Modifier;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Enum( ) == false )
      state |= c_modifier_Hide_Enum;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item( ) == false )
      state |= c_modifier_Hide_Enum_Item;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_2( ) == false )
      state |= c_modifier_Hide_Enum_Item_2;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_3( ) == false )
      state |= c_modifier_Hide_Enum_Item_3;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_4( ) == false )
      state |= c_modifier_Hide_Enum_Item_4;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_5( ) == false )
      state |= c_modifier_Hide_Enum_Item_5;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Value( ) == false )
      state |= c_modifier_Hide_Value;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Source_Parent( ) == false )
      state |= c_modifier_Hide_Source_Parent;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Source_Field( ) == false )
      state |= c_modifier_Hide_Source_Field;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Test_Field( ) == false )
      state |= c_modifier_Hide_Test_Field;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Test_Value( ) == false )
      state |= c_modifier_Hide_Test_Value;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Options( ) == false )
      state |= c_modifier_Hide_Options;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Source_Child( ) == false )
      state |= c_modifier_Hide_Source_Child;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) == false )
      state |= c_modifier_Hide_Use_Source_Parent;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && get_obj( ).Use_Source_Parent( ) == false )
      state |= c_modifier_Hide_Source_Parent;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && get_obj( ).Use_Source_Parent( ) == false )
      state |= c_modifier_Hide_Source_Child;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && get_obj( ).Use_Source_Parent( ) == true )
      state |= c_modifier_Hide_Source_Field;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Permission( ) == false )
      state |= c_modifier_Hide_Permission;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Protect_Source_Parent( ) == true )
      state |= c_modifier_Protect_Source_Parent;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Protect_Source_Parent( ) == true )
      state |= c_modifier_Protect_Source_Parent;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Child_Relationship( ) == false )
      state |= c_modifier_Hide_Child_Relationship;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( !get_obj( ).get_key( ).empty( ) && get_obj( ).Specification_Type( ).Protect_Class_From_Update( ) == true )
      state |= c_modifier_Protect_Class;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) == false )
      state |= c_modifier_Hide_Use_Test_Parent_Child;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) && get_obj( ).Use_Test_Parent_Child( ) == false )
      state |= c_modifier_Hide_Test_Parent;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) && get_obj( ).Use_Test_Parent_Child( ) == false )
      state |= c_modifier_Hide_Test_Child;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) && get_obj( ).Use_Test_Parent_Child( ) == true )
      state |= c_modifier_Hide_Test_Field;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Protect_Child_Rel( ) == true )
      state |= c_modifier_Protect_Child_Relationship;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Other_Field_2( ) == false )
      state |= c_modifier_Hide_Other_Field_2;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Source_Child_2( ) == false )
      state |= c_modifier_Hide_Source_Child_2;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && get_obj( ).Use_Source_Parent( ) == false )
      state |= c_modifier_Hide_Source_Child_2;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( !get_obj( ).get_key( ).empty( ) && get_obj( ).Specification_Type( ).Protect_Child_Rel_From_Update( ) == true )
      state |= c_modifier_Protect_Child_Relationship;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Protect_Procedure( ) == true )
      state |= c_modifier_Protect_Procedure;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Source_Grandchild( ) == false )
      state |= c_modifier_Hide_Source_Grandchild;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && get_obj( ).Use_Source_Parent( ) == false )
      state |= c_modifier_Hide_Source_Grandchild;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Protect_Class_From_Edit( ) == true )
      state |= c_modifier_Protect_Class;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Allow_Source_Class( ) == false )
      state |= c_modifier_Hide_Source_Class;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Protect_Procedure_From_Edit( ) == true )
      state |= c_modifier_Protect_Procedure;
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   if( get_obj( ).Specification_Type( ).Use_Field_Enum( ) == true )
      state |= c_modifier_Protect_Enum;
   // [(finish modifier_field_value)]

   // [<start get_state>]
   // [<finish get_state>]

   return state;
}

const string& Meta_Specification::impl::execute( const string& cmd_and_args )
{
   execute_command( cmd_and_args );
   return retval;
}

void Meta_Specification::impl::clear_foreign_key( const string& field )
{
   if( field.empty( ) )
      throw runtime_error( "unexpected empty field name/id" );
   else if( field == c_field_id_Child_Rel_Child_Class || field == c_field_name_Child_Rel_Child_Class )
      impl_Child_Rel_Child_Class( "" );
   else if( field == c_field_id_Child_Relationship || field == c_field_name_Child_Relationship )
      impl_Child_Relationship( "" );
   else if( field == c_field_id_Child_Specification_Type || field == c_field_name_Child_Specification_Type )
      impl_Child_Specification_Type( "" );
   else if( field == c_field_id_Class || field == c_field_name_Class )
      impl_Class( "" );
   else if( field == c_field_id_Enum || field == c_field_name_Enum )
      impl_Enum( "" );
   else if( field == c_field_id_Enum_Item || field == c_field_name_Enum_Item )
      impl_Enum_Item( "" );
   else if( field == c_field_id_Enum_Item_2 || field == c_field_name_Enum_Item_2 )
      impl_Enum_Item_2( "" );
   else if( field == c_field_id_Enum_Item_3 || field == c_field_name_Enum_Item_3 )
      impl_Enum_Item_3( "" );
   else if( field == c_field_id_Enum_Item_4 || field == c_field_name_Enum_Item_4 )
      impl_Enum_Item_4( "" );
   else if( field == c_field_id_Enum_Item_5 || field == c_field_name_Enum_Item_5 )
      impl_Enum_Item_5( "" );
   else if( field == c_field_id_Field || field == c_field_name_Field )
      impl_Field( "" );
   else if( field == c_field_id_Field_Class || field == c_field_name_Field_Class )
      impl_Field_Class( "" );
   else if( field == c_field_id_Model || field == c_field_name_Model )
      impl_Model( "" );
   else if( field == c_field_id_Modifier || field == c_field_name_Modifier )
      impl_Modifier( "" );
   else if( field == c_field_id_Other_Class || field == c_field_name_Other_Class )
      impl_Other_Class( "" );
   else if( field == c_field_id_Other_Field || field == c_field_name_Other_Field )
      impl_Other_Field( "" );
   else if( field == c_field_id_Other_Field_2 || field == c_field_name_Other_Field_2 )
      impl_Other_Field_2( "" );
   else if( field == c_field_id_Other_Procedure || field == c_field_name_Other_Procedure )
      impl_Other_Procedure( "" );
   else if( field == c_field_id_Other_Procedure_2 || field == c_field_name_Other_Procedure_2 )
      impl_Other_Procedure_2( "" );
   else if( field == c_field_id_Parent_Specification || field == c_field_name_Parent_Specification )
      impl_Parent_Specification( "" );
   else if( field == c_field_id_Parent_Specification_Copy_Child_Links || field == c_field_name_Parent_Specification_Copy_Child_Links )
      impl_Parent_Specification_Copy_Child_Links( "" );
   else if( field == c_field_id_Permission || field == c_field_name_Permission )
      impl_Permission( "" );
   else if( field == c_field_id_Procedure || field == c_field_name_Procedure )
      impl_Procedure( "" );
   else if( field == c_field_id_Procedure_Arg || field == c_field_name_Procedure_Arg )
      impl_Procedure_Arg( "" );
   else if( field == c_field_id_Procedure_Arg_2 || field == c_field_name_Procedure_Arg_2 )
      impl_Procedure_Arg_2( "" );
   else if( field == c_field_id_Procedure_Arg_3 || field == c_field_name_Procedure_Arg_3 )
      impl_Procedure_Arg_3( "" );
   else if( field == c_field_id_Source_Child || field == c_field_name_Source_Child )
      impl_Source_Child( "" );
   else if( field == c_field_id_Source_Child_2 || field == c_field_name_Source_Child_2 )
      impl_Source_Child_2( "" );
   else if( field == c_field_id_Source_Child_Class || field == c_field_name_Source_Child_Class )
      impl_Source_Child_Class( "" );
   else if( field == c_field_id_Source_Class || field == c_field_name_Source_Class )
      impl_Source_Class( "" );
   else if( field == c_field_id_Source_Field || field == c_field_name_Source_Field )
      impl_Source_Field( "" );
   else if( field == c_field_id_Source_Field_Class || field == c_field_name_Source_Field_Class )
      impl_Source_Field_Class( "" );
   else if( field == c_field_id_Source_Grandchild || field == c_field_name_Source_Grandchild )
      impl_Source_Grandchild( "" );
   else if( field == c_field_id_Source_Parent || field == c_field_name_Source_Parent )
      impl_Source_Parent( "" );
   else if( field == c_field_id_Source_Parent_Class || field == c_field_name_Source_Parent_Class )
      impl_Source_Parent_Class( "" );
   else if( field == c_field_id_Specification_Type || field == c_field_name_Specification_Type )
      impl_Specification_Type( "" );
   else if( field == c_field_id_Test_Child || field == c_field_name_Test_Child )
      impl_Test_Child( "" );
   else if( field == c_field_id_Test_Field || field == c_field_name_Test_Field )
      impl_Test_Field( "" );
   else if( field == c_field_id_Test_Field_Class || field == c_field_name_Test_Field_Class )
      impl_Test_Field_Class( "" );
   else if( field == c_field_id_Test_Parent || field == c_field_name_Test_Parent )
      impl_Test_Parent( "" );
   else if( field == c_field_id_Test_Parent_Class || field == c_field_name_Test_Parent_Class )
      impl_Test_Parent_Class( "" );
   else
      throw runtime_error( "unknown foreign key field '" + field + "'" );
}

void Meta_Specification::impl::set_foreign_key_value( const string& field, const string& value )
{
   if( field.empty( ) )
      throw runtime_error( "unexpected empty field name/id for value: " + value );
   else if( field == c_field_id_Child_Rel_Child_Class || field == c_field_name_Child_Rel_Child_Class )
      v_Child_Rel_Child_Class = value;
   else if( field == c_field_id_Child_Relationship || field == c_field_name_Child_Relationship )
      v_Child_Relationship = value;
   else if( field == c_field_id_Child_Specification_Type || field == c_field_name_Child_Specification_Type )
      v_Child_Specification_Type = value;
   else if( field == c_field_id_Class || field == c_field_name_Class )
      v_Class = value;
   else if( field == c_field_id_Enum || field == c_field_name_Enum )
      v_Enum = value;
   else if( field == c_field_id_Enum_Item || field == c_field_name_Enum_Item )
      v_Enum_Item = value;
   else if( field == c_field_id_Enum_Item_2 || field == c_field_name_Enum_Item_2 )
      v_Enum_Item_2 = value;
   else if( field == c_field_id_Enum_Item_3 || field == c_field_name_Enum_Item_3 )
      v_Enum_Item_3 = value;
   else if( field == c_field_id_Enum_Item_4 || field == c_field_name_Enum_Item_4 )
      v_Enum_Item_4 = value;
   else if( field == c_field_id_Enum_Item_5 || field == c_field_name_Enum_Item_5 )
      v_Enum_Item_5 = value;
   else if( field == c_field_id_Field || field == c_field_name_Field )
      v_Field = value;
   else if( field == c_field_id_Field_Class || field == c_field_name_Field_Class )
      v_Field_Class = value;
   else if( field == c_field_id_Model || field == c_field_name_Model )
      v_Model = value;
   else if( field == c_field_id_Modifier || field == c_field_name_Modifier )
      v_Modifier = value;
   else if( field == c_field_id_Other_Class || field == c_field_name_Other_Class )
      v_Other_Class = value;
   else if( field == c_field_id_Other_Field || field == c_field_name_Other_Field )
      v_Other_Field = value;
   else if( field == c_field_id_Other_Field_2 || field == c_field_name_Other_Field_2 )
      v_Other_Field_2 = value;
   else if( field == c_field_id_Other_Procedure || field == c_field_name_Other_Procedure )
      v_Other_Procedure = value;
   else if( field == c_field_id_Other_Procedure_2 || field == c_field_name_Other_Procedure_2 )
      v_Other_Procedure_2 = value;
   else if( field == c_field_id_Parent_Specification || field == c_field_name_Parent_Specification )
      v_Parent_Specification = value;
   else if( field == c_field_id_Parent_Specification_Copy_Child_Links || field == c_field_name_Parent_Specification_Copy_Child_Links )
      v_Parent_Specification_Copy_Child_Links = value;
   else if( field == c_field_id_Permission || field == c_field_name_Permission )
      v_Permission = value;
   else if( field == c_field_id_Procedure || field == c_field_name_Procedure )
      v_Procedure = value;
   else if( field == c_field_id_Procedure_Arg || field == c_field_name_Procedure_Arg )
      v_Procedure_Arg = value;
   else if( field == c_field_id_Procedure_Arg_2 || field == c_field_name_Procedure_Arg_2 )
      v_Procedure_Arg_2 = value;
   else if( field == c_field_id_Procedure_Arg_3 || field == c_field_name_Procedure_Arg_3 )
      v_Procedure_Arg_3 = value;
   else if( field == c_field_id_Source_Child || field == c_field_name_Source_Child )
      v_Source_Child = value;
   else if( field == c_field_id_Source_Child_2 || field == c_field_name_Source_Child_2 )
      v_Source_Child_2 = value;
   else if( field == c_field_id_Source_Child_Class || field == c_field_name_Source_Child_Class )
      v_Source_Child_Class = value;
   else if( field == c_field_id_Source_Class || field == c_field_name_Source_Class )
      v_Source_Class = value;
   else if( field == c_field_id_Source_Field || field == c_field_name_Source_Field )
      v_Source_Field = value;
   else if( field == c_field_id_Source_Field_Class || field == c_field_name_Source_Field_Class )
      v_Source_Field_Class = value;
   else if( field == c_field_id_Source_Grandchild || field == c_field_name_Source_Grandchild )
      v_Source_Grandchild = value;
   else if( field == c_field_id_Source_Parent || field == c_field_name_Source_Parent )
      v_Source_Parent = value;
   else if( field == c_field_id_Source_Parent_Class || field == c_field_name_Source_Parent_Class )
      v_Source_Parent_Class = value;
   else if( field == c_field_id_Specification_Type || field == c_field_name_Specification_Type )
      v_Specification_Type = value;
   else if( field == c_field_id_Test_Child || field == c_field_name_Test_Child )
      v_Test_Child = value;
   else if( field == c_field_id_Test_Field || field == c_field_name_Test_Field )
      v_Test_Field = value;
   else if( field == c_field_id_Test_Field_Class || field == c_field_name_Test_Field_Class )
      v_Test_Field_Class = value;
   else if( field == c_field_id_Test_Parent || field == c_field_name_Test_Parent )
      v_Test_Parent = value;
   else if( field == c_field_id_Test_Parent_Class || field == c_field_name_Test_Parent_Class )
      v_Test_Parent_Class = value;
   else
      throw runtime_error( "unknown foreign key field '" + field + "'" );
}

const string& Meta_Specification::impl::get_foreign_key_value( const string& field )
{
   if( field.empty( ) )
      throw runtime_error( "unexpected empty field name/id" );
   else if( field == c_field_id_Child_Rel_Child_Class || field == c_field_name_Child_Rel_Child_Class )
      return v_Child_Rel_Child_Class;
   else if( field == c_field_id_Child_Relationship || field == c_field_name_Child_Relationship )
      return v_Child_Relationship;
   else if( field == c_field_id_Child_Specification_Type || field == c_field_name_Child_Specification_Type )
      return v_Child_Specification_Type;
   else if( field == c_field_id_Class || field == c_field_name_Class )
      return v_Class;
   else if( field == c_field_id_Enum || field == c_field_name_Enum )
      return v_Enum;
   else if( field == c_field_id_Enum_Item || field == c_field_name_Enum_Item )
      return v_Enum_Item;
   else if( field == c_field_id_Enum_Item_2 || field == c_field_name_Enum_Item_2 )
      return v_Enum_Item_2;
   else if( field == c_field_id_Enum_Item_3 || field == c_field_name_Enum_Item_3 )
      return v_Enum_Item_3;
   else if( field == c_field_id_Enum_Item_4 || field == c_field_name_Enum_Item_4 )
      return v_Enum_Item_4;
   else if( field == c_field_id_Enum_Item_5 || field == c_field_name_Enum_Item_5 )
      return v_Enum_Item_5;
   else if( field == c_field_id_Field || field == c_field_name_Field )
      return v_Field;
   else if( field == c_field_id_Field_Class || field == c_field_name_Field_Class )
      return v_Field_Class;
   else if( field == c_field_id_Model || field == c_field_name_Model )
      return v_Model;
   else if( field == c_field_id_Modifier || field == c_field_name_Modifier )
      return v_Modifier;
   else if( field == c_field_id_Other_Class || field == c_field_name_Other_Class )
      return v_Other_Class;
   else if( field == c_field_id_Other_Field || field == c_field_name_Other_Field )
      return v_Other_Field;
   else if( field == c_field_id_Other_Field_2 || field == c_field_name_Other_Field_2 )
      return v_Other_Field_2;
   else if( field == c_field_id_Other_Procedure || field == c_field_name_Other_Procedure )
      return v_Other_Procedure;
   else if( field == c_field_id_Other_Procedure_2 || field == c_field_name_Other_Procedure_2 )
      return v_Other_Procedure_2;
   else if( field == c_field_id_Parent_Specification || field == c_field_name_Parent_Specification )
      return v_Parent_Specification;
   else if( field == c_field_id_Parent_Specification_Copy_Child_Links || field == c_field_name_Parent_Specification_Copy_Child_Links )
      return v_Parent_Specification_Copy_Child_Links;
   else if( field == c_field_id_Permission || field == c_field_name_Permission )
      return v_Permission;
   else if( field == c_field_id_Procedure || field == c_field_name_Procedure )
      return v_Procedure;
   else if( field == c_field_id_Procedure_Arg || field == c_field_name_Procedure_Arg )
      return v_Procedure_Arg;
   else if( field == c_field_id_Procedure_Arg_2 || field == c_field_name_Procedure_Arg_2 )
      return v_Procedure_Arg_2;
   else if( field == c_field_id_Procedure_Arg_3 || field == c_field_name_Procedure_Arg_3 )
      return v_Procedure_Arg_3;
   else if( field == c_field_id_Source_Child || field == c_field_name_Source_Child )
      return v_Source_Child;
   else if( field == c_field_id_Source_Child_2 || field == c_field_name_Source_Child_2 )
      return v_Source_Child_2;
   else if( field == c_field_id_Source_Child_Class || field == c_field_name_Source_Child_Class )
      return v_Source_Child_Class;
   else if( field == c_field_id_Source_Class || field == c_field_name_Source_Class )
      return v_Source_Class;
   else if( field == c_field_id_Source_Field || field == c_field_name_Source_Field )
      return v_Source_Field;
   else if( field == c_field_id_Source_Field_Class || field == c_field_name_Source_Field_Class )
      return v_Source_Field_Class;
   else if( field == c_field_id_Source_Grandchild || field == c_field_name_Source_Grandchild )
      return v_Source_Grandchild;
   else if( field == c_field_id_Source_Parent || field == c_field_name_Source_Parent )
      return v_Source_Parent;
   else if( field == c_field_id_Source_Parent_Class || field == c_field_name_Source_Parent_Class )
      return v_Source_Parent_Class;
   else if( field == c_field_id_Specification_Type || field == c_field_name_Specification_Type )
      return v_Specification_Type;
   else if( field == c_field_id_Test_Child || field == c_field_name_Test_Child )
      return v_Test_Child;
   else if( field == c_field_id_Test_Field || field == c_field_name_Test_Field )
      return v_Test_Field;
   else if( field == c_field_id_Test_Field_Class || field == c_field_name_Test_Field_Class )
      return v_Test_Field_Class;
   else if( field == c_field_id_Test_Parent || field == c_field_name_Test_Parent )
      return v_Test_Parent;
   else if( field == c_field_id_Test_Parent_Class || field == c_field_name_Test_Parent_Class )
      return v_Test_Parent_Class;
   else
      throw runtime_error( "unknown foreign key field '" + field + "'" );
}

void Meta_Specification::impl::get_foreign_key_values( foreign_key_data_container& foreign_key_values ) const
{
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Child_Rel_Child_Class, v_Child_Rel_Child_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Child_Relationship, v_Child_Relationship ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Child_Specification_Type, v_Child_Specification_Type ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Class, v_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Enum, v_Enum ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Enum_Item, v_Enum_Item ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Enum_Item_2, v_Enum_Item_2 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Enum_Item_3, v_Enum_Item_3 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Enum_Item_4, v_Enum_Item_4 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Enum_Item_5, v_Enum_Item_5 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Field, v_Field ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Field_Class, v_Field_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Model, v_Model ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Modifier, v_Modifier ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Other_Class, v_Other_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Other_Field, v_Other_Field ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Other_Field_2, v_Other_Field_2 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Other_Procedure, v_Other_Procedure ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Other_Procedure_2, v_Other_Procedure_2 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Parent_Specification, v_Parent_Specification ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Parent_Specification_Copy_Child_Links, v_Parent_Specification_Copy_Child_Links ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Permission, v_Permission ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Procedure, v_Procedure ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Procedure_Arg, v_Procedure_Arg ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Procedure_Arg_2, v_Procedure_Arg_2 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Procedure_Arg_3, v_Procedure_Arg_3 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Child, v_Source_Child ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Child_2, v_Source_Child_2 ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Child_Class, v_Source_Child_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Class, v_Source_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Field, v_Source_Field ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Field_Class, v_Source_Field_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Grandchild, v_Source_Grandchild ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Parent, v_Source_Parent ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Source_Parent_Class, v_Source_Parent_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Specification_Type, v_Specification_Type ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Test_Child, v_Test_Child ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Test_Field, v_Test_Field ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Test_Field_Class, v_Test_Field_Class ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Test_Parent, v_Test_Parent ) );
   foreign_key_values.insert( foreign_key_data_value_type( c_field_id_Test_Parent_Class, v_Test_Parent_Class ) );
}

void Meta_Specification::impl::clear( )
{
   v_Actions = gv_default_Actions;
   v_All_Strings = gv_default_All_Strings;
   v_All_Vars = gv_default_All_Vars;
   v_Child_Rel_Field_Key = gv_default_Child_Rel_Field_Key;
   v_Comments = gv_default_Comments;
   v_Field_Pairs = gv_default_Field_Pairs;
   v_Field_Values = gv_default_Field_Values;
   v_Fields = gv_default_Fields;
   v_Id = gv_default_Id;
   v_Is_Required_For_UI_Gen = gv_default_Is_Required_For_UI_Gen;
   v_Name = gv_default_Name;
   v_Options = gv_default_Options;
   v_Order = gv_default_Order;
   v_Protect_Child_Rel = gv_default_Protect_Child_Rel;
   v_Protect_Procedure = gv_default_Protect_Procedure;
   v_Protect_Source_Parent = gv_default_Protect_Source_Parent;
   v_Restrict_Values = gv_default_Restrict_Values;
   v_Strings = gv_default_Strings;
   v_Test_Value = gv_default_Test_Value;
   v_Use_Source_Parent = gv_default_Use_Source_Parent;
   v_Use_Test_Parent_Child = gv_default_Use_Test_Parent_Child;
   v_Value = gv_default_Value;
   v_Value_Left_Part = gv_default_Value_Left_Part;
   v_Value_Literal = gv_default_Value_Literal;
   v_Value_Numeric_String = gv_default_Value_Numeric_String;
   v_Value_Right_Part = gv_default_Value_Right_Part;
   v_Value_String = gv_default_Value_String;
   v_Vars = gv_default_Vars;

   v_Child_Rel_Child_Class = string( );
   if( cp_Child_Rel_Child_Class )
      p_obj->setup_foreign_key( *cp_Child_Rel_Child_Class, v_Child_Rel_Child_Class );

   v_Child_Relationship = string( );
   if( cp_Child_Relationship )
      p_obj->setup_foreign_key( *cp_Child_Relationship, v_Child_Relationship );

   v_Child_Specification_Type = string( );
   if( cp_Child_Specification_Type )
      p_obj->setup_foreign_key( *cp_Child_Specification_Type, v_Child_Specification_Type );

   v_Class = string( );
   if( cp_Class )
      p_obj->setup_foreign_key( *cp_Class, v_Class );

   v_Enum = string( );
   if( cp_Enum )
      p_obj->setup_foreign_key( *cp_Enum, v_Enum );

   v_Enum_Item = string( );
   if( cp_Enum_Item )
      p_obj->setup_foreign_key( *cp_Enum_Item, v_Enum_Item );

   v_Enum_Item_2 = string( );
   if( cp_Enum_Item_2 )
      p_obj->setup_foreign_key( *cp_Enum_Item_2, v_Enum_Item_2 );

   v_Enum_Item_3 = string( );
   if( cp_Enum_Item_3 )
      p_obj->setup_foreign_key( *cp_Enum_Item_3, v_Enum_Item_3 );

   v_Enum_Item_4 = string( );
   if( cp_Enum_Item_4 )
      p_obj->setup_foreign_key( *cp_Enum_Item_4, v_Enum_Item_4 );

   v_Enum_Item_5 = string( );
   if( cp_Enum_Item_5 )
      p_obj->setup_foreign_key( *cp_Enum_Item_5, v_Enum_Item_5 );

   v_Field = string( );
   if( cp_Field )
      p_obj->setup_foreign_key( *cp_Field, v_Field );

   v_Field_Class = string( );
   if( cp_Field_Class )
      p_obj->setup_foreign_key( *cp_Field_Class, v_Field_Class );

   v_Model = string( );
   if( cp_Model )
      p_obj->setup_foreign_key( *cp_Model, v_Model );

   v_Modifier = string( );
   if( cp_Modifier )
      p_obj->setup_foreign_key( *cp_Modifier, v_Modifier );

   v_Other_Class = string( );
   if( cp_Other_Class )
      p_obj->setup_foreign_key( *cp_Other_Class, v_Other_Class );

   v_Other_Field = string( );
   if( cp_Other_Field )
      p_obj->setup_foreign_key( *cp_Other_Field, v_Other_Field );

   v_Other_Field_2 = string( );
   if( cp_Other_Field_2 )
      p_obj->setup_foreign_key( *cp_Other_Field_2, v_Other_Field_2 );

   v_Other_Procedure = string( );
   if( cp_Other_Procedure )
      p_obj->setup_foreign_key( *cp_Other_Procedure, v_Other_Procedure );

   v_Other_Procedure_2 = string( );
   if( cp_Other_Procedure_2 )
      p_obj->setup_foreign_key( *cp_Other_Procedure_2, v_Other_Procedure_2 );

   v_Parent_Specification = string( );
   if( cp_Parent_Specification )
      p_obj->setup_foreign_key( *cp_Parent_Specification, v_Parent_Specification );

   v_Parent_Specification_Copy_Child_Links = string( );
   if( cp_Parent_Specification_Copy_Child_Links )
      p_obj->setup_foreign_key( *cp_Parent_Specification_Copy_Child_Links, v_Parent_Specification_Copy_Child_Links );

   v_Permission = string( );
   if( cp_Permission )
      p_obj->setup_foreign_key( *cp_Permission, v_Permission );

   v_Procedure = string( );
   if( cp_Procedure )
      p_obj->setup_foreign_key( *cp_Procedure, v_Procedure );

   v_Procedure_Arg = string( );
   if( cp_Procedure_Arg )
      p_obj->setup_foreign_key( *cp_Procedure_Arg, v_Procedure_Arg );

   v_Procedure_Arg_2 = string( );
   if( cp_Procedure_Arg_2 )
      p_obj->setup_foreign_key( *cp_Procedure_Arg_2, v_Procedure_Arg_2 );

   v_Procedure_Arg_3 = string( );
   if( cp_Procedure_Arg_3 )
      p_obj->setup_foreign_key( *cp_Procedure_Arg_3, v_Procedure_Arg_3 );

   v_Source_Child = string( );
   if( cp_Source_Child )
      p_obj->setup_foreign_key( *cp_Source_Child, v_Source_Child );

   v_Source_Child_2 = string( );
   if( cp_Source_Child_2 )
      p_obj->setup_foreign_key( *cp_Source_Child_2, v_Source_Child_2 );

   v_Source_Child_Class = string( );
   if( cp_Source_Child_Class )
      p_obj->setup_foreign_key( *cp_Source_Child_Class, v_Source_Child_Class );

   v_Source_Class = string( );
   if( cp_Source_Class )
      p_obj->setup_foreign_key( *cp_Source_Class, v_Source_Class );

   v_Source_Field = string( );
   if( cp_Source_Field )
      p_obj->setup_foreign_key( *cp_Source_Field, v_Source_Field );

   v_Source_Field_Class = string( );
   if( cp_Source_Field_Class )
      p_obj->setup_foreign_key( *cp_Source_Field_Class, v_Source_Field_Class );

   v_Source_Grandchild = string( );
   if( cp_Source_Grandchild )
      p_obj->setup_foreign_key( *cp_Source_Grandchild, v_Source_Grandchild );

   v_Source_Parent = string( );
   if( cp_Source_Parent )
      p_obj->setup_foreign_key( *cp_Source_Parent, v_Source_Parent );

   v_Source_Parent_Class = string( );
   if( cp_Source_Parent_Class )
      p_obj->setup_foreign_key( *cp_Source_Parent_Class, v_Source_Parent_Class );

   v_Specification_Type = string( );
   if( cp_Specification_Type )
      p_obj->setup_foreign_key( *cp_Specification_Type, v_Specification_Type );

   v_Test_Child = string( );
   if( cp_Test_Child )
      p_obj->setup_foreign_key( *cp_Test_Child, v_Test_Child );

   v_Test_Field = string( );
   if( cp_Test_Field )
      p_obj->setup_foreign_key( *cp_Test_Field, v_Test_Field );

   v_Test_Field_Class = string( );
   if( cp_Test_Field_Class )
      p_obj->setup_foreign_key( *cp_Test_Field_Class, v_Test_Field_Class );

   v_Test_Parent = string( );
   if( cp_Test_Parent )
      p_obj->setup_foreign_key( *cp_Test_Parent, v_Test_Parent );

   v_Test_Parent_Class = string( );
   if( cp_Test_Parent_Class )
      p_obj->setup_foreign_key( *cp_Test_Parent_Class, v_Test_Parent_Class );
}

bool Meta_Specification::impl::value_will_be_provided( const string& field_name )
{
   ( void )field_name;

   // [(start parent_auto_int_inc)]
   if( field_name == "Id" )
      return true;
   // [(finish parent_auto_int_inc)]

   // [<start value_will_be_provided>]
   // [<finish value_will_be_provided>]

   return false;
}

void Meta_Specification::impl::validate( unsigned state, bool is_internal, validation_error_container* p_validation_errors )
{
   ( void )state;
   ( void )is_internal;

   if( !p_validation_errors )
      throw runtime_error( "unexpected null validation_errors container" );

   if( is_null( v_Id ) && !value_will_be_provided( c_field_name_Id ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Id,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Id ) ) ) ) );

   if( is_null( v_Name ) && !value_will_be_provided( c_field_name_Name ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Name,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Name ) ) ) ) );

   if( is_null( v_Order ) && !value_will_be_provided( c_field_name_Order ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Order,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Order ) ) ) ) );

   if( v_Class.empty( ) && !value_will_be_provided( c_field_name_Class ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Class,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Class ) ) ) ) );

   if( v_Model.empty( ) && !value_will_be_provided( c_field_name_Model ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Model,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Model ) ) ) ) );

   if( v_Specification_Type.empty( ) && !value_will_be_provided( c_field_name_Specification_Type ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Specification_Type,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Specification_Type ) ) ) ) );

   string error_message;
   if( !is_null( v_Comments )
    && ( v_Comments != gv_default_Comments
    || !value_will_be_provided( c_field_name_Comments ) )
    && !g_Comments_domain.is_valid( v_Comments, error_message = "" ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Comments,
       get_module_string( c_field_display_name_Comments ) + " " + error_message ) );

   if( !is_null( v_Id )
    && ( v_Id != gv_default_Id
    || !value_will_be_provided( c_field_name_Id ) )
    && !g_Id_domain.is_valid( v_Id, error_message = "" ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Id,
       get_module_string( c_field_display_name_Id ) + " " + error_message ) );

   if( !is_null( v_Name )
    && ( v_Name != gv_default_Name
    || !value_will_be_provided( c_field_name_Name ) )
    && !g_Name_domain.is_valid( v_Name, error_message = "" ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Name,
       get_module_string( c_field_display_name_Name ) + " " + error_message ) );

   if( !is_null( v_Options )
    && ( v_Options != gv_default_Options
    || !value_will_be_provided( c_field_name_Options ) )
    && !g_Options_domain.is_valid( v_Options, error_message = "" ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Options,
       get_module_string( c_field_display_name_Options ) + " " + error_message ) );

   if( !is_null( v_Test_Value )
    && ( v_Test_Value != gv_default_Test_Value
    || !value_will_be_provided( c_field_name_Test_Value ) )
    && !g_Test_Value_domain.is_valid( v_Test_Value, error_message = "" ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Test_Value,
       get_module_string( c_field_display_name_Test_Value ) + " " + error_message ) );

   if( !is_null( v_Value )
    && ( v_Value != gv_default_Value
    || !value_will_be_provided( c_field_name_Value ) )
    && !g_Value_domain.is_valid( v_Value, error_message = "" ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Value,
       get_module_string( c_field_display_name_Value ) + " " + error_message ) );

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Class( ) && is_null( get_obj( ).Class( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Class,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Class ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Class( ) && is_null( get_obj( ).Other_Class( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Other_Class,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Other_Class ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Field( ) && is_null( get_obj( ).Field( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Field,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Field ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure( ) && is_null( get_obj( ).Procedure( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Procedure,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Procedure ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure_Arg( ) && is_null( get_obj( ).Procedure_Arg( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Procedure_Arg,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Procedure_Arg ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure_Arg_2( ) && is_null( get_obj( ).Procedure_Arg_2( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Procedure_Arg_2,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Procedure_Arg_2 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Procedure_Arg_3( ) && is_null( get_obj( ).Procedure_Arg_3( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Procedure_Arg_3,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Procedure_Arg_3 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Procedure( ) && is_null( get_obj( ).Other_Procedure( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Other_Procedure,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Other_Procedure ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Procedure_2( ) && is_null( get_obj( ).Other_Procedure_2( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Other_Procedure_2,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Other_Procedure_2 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Modifier( ) && is_null( get_obj( ).Modifier( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Modifier,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Modifier ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Enum( ) && is_null( get_obj( ).Enum( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Enum,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Enum ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item( ) && is_null( get_obj( ).Enum_Item( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Enum_Item,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Enum_Item ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_2( ) && is_null( get_obj( ).Enum_Item_2( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Enum_Item_2,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Enum_Item_2 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_3( ) && is_null( get_obj( ).Enum_Item_3( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Enum_Item_3,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Enum_Item_3 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_4( ) && is_null( get_obj( ).Enum_Item_4( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Enum_Item_4,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Enum_Item_4 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Enum_Item_5( ) && is_null( get_obj( ).Enum_Item_5( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Enum_Item_5,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Enum_Item_5 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Value( ) && is_null( get_obj( ).Value( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Value,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Value ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Source_Parent( ) && is_null( get_obj( ).Source_Parent( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Source_Parent,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Source_Parent ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Source_Field( ) && is_null( get_obj( ).Source_Field( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Source_Field,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Source_Field ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Test_Field( ) && !get_obj( ).Use_Test_Parent_Child( ) && is_null( get_obj( ).Test_Field( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Test_Field,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Test_Field ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Test_Field( ) && get_obj( ).Use_Test_Parent_Child( ) && is_null( get_obj( ).Test_Child( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Test_Child,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Test_Child ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Test_Value( ) && is_null( get_obj( ).Test_Value( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Test_Value,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Test_Value ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Source_Child( ) && is_null( get_obj( ).Source_Child( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Source_Child,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Source_Child ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Source_Field_Or_Child( ) && !get_obj( ).Use_Source_Parent( ) && is_null( get_obj( ).Source_Field( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Source_Field,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Source_Field ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Source_Field_Or_Child( ) && get_obj( ).Use_Source_Parent( ) && is_null( get_obj( ).Source_Child( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Source_Child,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Source_Child ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Child_Relationship( ) && is_null( get_obj( ).Child_Relationship( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Child_Relationship,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Child_Relationship ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start meta_spec_field_type)]
   // NOTE: Scope for local variables.
   {
      string error;

      int fld_primitive = -1;
      if( !get_obj( ).Field( ).get_key( ).empty( ) )
         fld_primitive = get_obj( ).Field( ).Primitive( );

      int test_primitive = -1;
      if( get_obj( ).Test_Child( ).get_key( ).empty( ) )
      {
         if( !get_obj( ).Test_Field( ).get_key( ).empty( ) )
            test_primitive = get_obj( ).Test_Field( ).Primitive( );
      }
      else
         test_primitive = get_obj( ).Test_Child( ).Primitive( );

      int source_primitive = -1;
      if( get_obj( ).Source_Child( ).get_key( ).empty( ) )
      {
         if( !get_obj( ).Source_Field( ).get_key( ).empty( ) )
            source_primitive = get_obj( ).Source_Field( ).Primitive( );
      }
      else
         source_primitive = get_obj( ).Source_Child( ).Primitive( );

      get_obj( ).Specification_Type( ).Is_Valid_Field_Type(
       get_obj( ).Class( ).get_key( ), error,
       get_obj( ).Field( ).Parent_Class( ).get_key( ), fld_primitive,
       get_obj( ).Procedure_Arg( ).Primitive( ), get_obj( ).Procedure_Arg( ).Type( ),
       get_obj( ).Source_Parent( ).Parent_Class( ).get_key( ), source_primitive, test_primitive, get_obj( ).Test_Value( ) );

      if( !error.empty( ) )
      {
         p_validation_errors->insert( validation_error_value_type( "",
          get_string_message( GS( c_str_error ), make_pair( c_str_parm_error_error, error ) ) ) );
      }

      if( get_obj( ).Specification_Type( ).Test_Field_Type_Match( ) && get_obj( ).Field( ).Primitive( ) != test_primitive )
         p_validation_errors->insert( validation_error_value_type( "",
          get_string_message( GS( c_str_field_types_must_match ), make_pair(
          c_str_parm_field_types_must_match_field1, get_module_string( c_field_display_name_Field ) ),
          make_pair( c_str_parm_field_types_must_match_field2, get_module_string( c_field_display_name_Test_Field ) ) ) ) );

      if( get_obj( ).Specification_Type( ).Source_Field_Type_Match( ) && get_obj( ).Field( ).Primitive( ) != source_primitive )
         p_validation_errors->insert( validation_error_value_type( "",
          get_string_message( GS( c_str_field_types_must_match ), make_pair(
          c_str_parm_field_types_must_match_field1, get_module_string( c_field_display_name_Field ) ),
          make_pair( c_str_parm_field_types_must_match_field2, get_module_string( c_field_display_name_Source_Field ) ) ) ) );

      if( get_obj( ).Specification_Type( ).Source_Field_Needs_Test_Field( )
       && get_obj( ).Test_Field( ).get_key( ).empty( ) && !get_obj( ).Source_Field( ).get_key( ).empty( ) )
         p_validation_errors->insert( validation_error_value_type( "",
          get_string_message( GS( c_str_field_must_be_empty_match ), make_pair(
          c_str_parm_field_must_be_empty_match_field2, get_module_string( c_field_display_name_Source_Field ) ),
          make_pair( c_str_parm_field_must_be_empty_match_field1, get_module_string( c_field_display_name_Test_Field ) ) ) ) );

      if( get_obj( ).Specification_Type( ).Child_Relationship_Class_Match( )
       && get_obj( ).Class( ).get_key( ) != get_obj( ).Child_Relationship( ).Child_Class( ).get_key( ) )
         p_validation_errors->insert( validation_error_value_type( c_field_name_Child_Relationship,
          get_module_string( c_field_display_name_Child_Relationship ) + " must be a self-relationship." ) ); // FUTURE: Should be in module_strings...

      if( get_obj( ).Specification_Type( ).Child_Rel_Parent_Match( )
       && get_obj( ).Parent_Specification( ).Class( ).get_key( ) != get_obj( ).Child_Relationship( ).Child_Class( ).get_key( ) )
         p_validation_errors->insert( validation_error_value_type( c_field_name_Child_Relationship,
          get_module_string( c_field_display_name_Child_Relationship ) + " must match the parent specification." ) ); // FUTURE: Should be in module_strings...

      if( get_obj( ).Specification_Type( ).Child_Rel_Grandparent_Match( )
       && get_obj( ).Parent_Specification( ).Parent_Specification( ).Class( ).get_key( ) != get_obj( ).Child_Relationship( ).Child_Class( ).get_key( ) )
         p_validation_errors->insert( validation_error_value_type( c_field_name_Child_Relationship,
          get_module_string( c_field_display_name_Child_Relationship ) + " must match the grandparent specification." ) ); // FUTURE: Should be in module_strings...

      if( get_obj( ).Specification_Type( ).get_key( ) == "user_info"
       && ( get_obj( ).Test_Field( ).Extra( ) != 10 // i.e. password
       &&  get_obj( ).Test_Field( ).Extra( ) != 26 ) ) // i.e. hpassword
         p_validation_errors->insert( validation_error_value_type( "", "Test Field is not a valid 'password' field." ) ); // FUTURE: Should be in module_strings...
   }
   // [(finish meta_spec_field_type)]

   // [(start check_null_match)]
   if( is_null( get_obj( ).Test_Child( ) ) && !is_null( get_obj( ).Test_Parent( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Test_Child,
       get_string_message( GS( c_str_field_must_be_empty_match ), make_pair(
       c_str_parm_field_must_be_empty_match_field2, get_module_string( c_field_display_name_Test_Parent ) ),
       make_pair( c_str_parm_field_must_be_empty_match_field1, get_module_string( c_field_display_name_Test_Child ) ) ) ) );
   // [(finish check_null_match)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Field( ) && is_null( get_obj( ).Other_Field( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Other_Field,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Other_Field ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Source_Child_2( ) && is_null( get_obj( ).Source_Child_2( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Source_Child_2,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Source_Child_2 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Permission( ) && is_null( get_obj( ).Permission( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Permission,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Permission ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [(start check_cond_non_null)]
   if( get_obj( ).Specification_Type( ).Needs_Other_Field_2( ) && is_null( get_obj( ).Other_Field_2( ) ) )
      p_validation_errors->insert( validation_error_value_type( c_field_name_Other_Field_2,
       get_string_message( GS( c_str_field_must_not_be_empty ), make_pair(
       c_str_parm_field_must_not_be_empty_field, get_module_string( c_field_display_name_Other_Field_2 ) ) ) ) );
   // [(finish check_cond_non_null)]

   // [<start validate>]
   // [<finish validate>]
}

void Meta_Specification::impl::after_fetch( )
{
   set< string > required_transients;

   p_obj->get_required_field_names( required_transients, true );

   if( cp_Child_Rel_Child_Class )
      p_obj->setup_foreign_key( *cp_Child_Rel_Child_Class, v_Child_Rel_Child_Class );

   if( cp_Child_Relationship )
      p_obj->setup_foreign_key( *cp_Child_Relationship, v_Child_Relationship );

   if( cp_Child_Specification_Type )
      p_obj->setup_foreign_key( *cp_Child_Specification_Type, v_Child_Specification_Type );

   if( cp_Class )
      p_obj->setup_foreign_key( *cp_Class, v_Class );

   if( cp_Enum )
      p_obj->setup_foreign_key( *cp_Enum, v_Enum );

   if( cp_Enum_Item )
      p_obj->setup_foreign_key( *cp_Enum_Item, v_Enum_Item );

   if( cp_Enum_Item_2 )
      p_obj->setup_foreign_key( *cp_Enum_Item_2, v_Enum_Item_2 );

   if( cp_Enum_Item_3 )
      p_obj->setup_foreign_key( *cp_Enum_Item_3, v_Enum_Item_3 );

   if( cp_Enum_Item_4 )
      p_obj->setup_foreign_key( *cp_Enum_Item_4, v_Enum_Item_4 );

   if( cp_Enum_Item_5 )
      p_obj->setup_foreign_key( *cp_Enum_Item_5, v_Enum_Item_5 );

   if( cp_Field )
      p_obj->setup_foreign_key( *cp_Field, v_Field );

   if( cp_Field_Class )
      p_obj->setup_foreign_key( *cp_Field_Class, v_Field_Class );

   if( cp_Model )
      p_obj->setup_foreign_key( *cp_Model, v_Model );

   if( cp_Modifier )
      p_obj->setup_foreign_key( *cp_Modifier, v_Modifier );

   if( cp_Other_Class )
      p_obj->setup_foreign_key( *cp_Other_Class, v_Other_Class );

   if( cp_Other_Field )
      p_obj->setup_foreign_key( *cp_Other_Field, v_Other_Field );

   if( cp_Other_Field_2 )
      p_obj->setup_foreign_key( *cp_Other_Field_2, v_Other_Field_2 );

   if( cp_Other_Procedure )
      p_obj->setup_foreign_key( *cp_Other_Procedure, v_Other_Procedure );

   if( cp_Other_Procedure_2 )
      p_obj->setup_foreign_key( *cp_Other_Procedure_2, v_Other_Procedure_2 );

   if( cp_Parent_Specification )
      p_obj->setup_foreign_key( *cp_Parent_Specification, v_Parent_Specification );

   if( cp_Parent_Specification_Copy_Child_Links )
      p_obj->setup_foreign_key( *cp_Parent_Specification_Copy_Child_Links, v_Parent_Specification_Copy_Child_Links );

   if( cp_Permission )
      p_obj->setup_foreign_key( *cp_Permission, v_Permission );

   if( cp_Procedure )
      p_obj->setup_foreign_key( *cp_Procedure, v_Procedure );

   if( cp_Procedure_Arg )
      p_obj->setup_foreign_key( *cp_Procedure_Arg, v_Procedure_Arg );

   if( cp_Procedure_Arg_2 )
      p_obj->setup_foreign_key( *cp_Procedure_Arg_2, v_Procedure_Arg_2 );

   if( cp_Procedure_Arg_3 )
      p_obj->setup_foreign_key( *cp_Procedure_Arg_3, v_Procedure_Arg_3 );

   if( cp_Source_Child )
      p_obj->setup_foreign_key( *cp_Source_Child, v_Source_Child );

   if( cp_Source_Child_2 )
      p_obj->setup_foreign_key( *cp_Source_Child_2, v_Source_Child_2 );

   if( cp_Source_Child_Class )
      p_obj->setup_foreign_key( *cp_Source_Child_Class, v_Source_Child_Class );

   if( cp_Source_Class )
      p_obj->setup_foreign_key( *cp_Source_Class, v_Source_Class );

   if( cp_Source_Field )
      p_obj->setup_foreign_key( *cp_Source_Field, v_Source_Field );

   if( cp_Source_Field_Class )
      p_obj->setup_foreign_key( *cp_Source_Field_Class, v_Source_Field_Class );

   if( cp_Source_Grandchild )
      p_obj->setup_foreign_key( *cp_Source_Grandchild, v_Source_Grandchild );

   if( cp_Source_Parent )
      p_obj->setup_foreign_key( *cp_Source_Parent, v_Source_Parent );

   if( cp_Source_Parent_Class )
      p_obj->setup_foreign_key( *cp_Source_Parent_Class, v_Source_Parent_Class );

   if( cp_Specification_Type )
      p_obj->setup_foreign_key( *cp_Specification_Type, v_Specification_Type );

   if( cp_Test_Child )
      p_obj->setup_foreign_key( *cp_Test_Child, v_Test_Child );

   if( cp_Test_Field )
      p_obj->setup_foreign_key( *cp_Test_Field, v_Test_Field );

   if( cp_Test_Field_Class )
      p_obj->setup_foreign_key( *cp_Test_Field_Class, v_Test_Field_Class );

   if( cp_Test_Parent )
      p_obj->setup_foreign_key( *cp_Test_Parent, v_Test_Parent );

   if( cp_Test_Parent_Class )
      p_obj->setup_foreign_key( *cp_Test_Parent_Class, v_Test_Parent_Class );

   // [(start field_from_search_replace)]
   if( !get_obj( ).get_key( ).empty( )
    && ( get_obj( ).needs_field_value( "Vars" )
    || required_transients.count( "Vars" ) ) )
   {
      string str( get_obj( ).Specification_Type( ).Specification_Vars( ) );

      get_obj( ).Vars( str );

      get_obj( ).add_search_replacement( "Vars", "{model}", to_string( get_obj( ).Model( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{model_id}", to_string( get_obj( ).Model( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{class}", to_string( get_obj( ).Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{class_id}", to_string( get_obj( ).Class( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{oclass}", to_string( get_obj( ).Other_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{oclass_id}", to_string( get_obj( ).Other_Class( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{field}", to_string( get_obj( ).Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{fclass}", to_string( get_obj( ).Field_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{field_id}", to_string( get_obj( ).Field( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{fmandatory}", to_string( get_obj( ).Field( ).Mandatory( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{fistexttype}", to_string( get_obj( ).Field( ).Is_Text_Type( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{fpclass}", to_string( get_obj( ).Field( ).Parent_Class_Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{ofield}", to_string( get_obj( ).Other_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{ofield_id}", to_string( get_obj( ).Other_Field( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{o2field}", to_string( get_obj( ).Other_Field_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{o2field_id}", to_string( get_obj( ).Other_Field_2( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{modifier}", to_string( get_obj( ).Modifier( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{spclass}", to_string( get_obj( ).Source_Parent_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{spfield}", to_string( get_obj( ).Source_Parent( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{spfield_id}", to_string( get_obj( ).Source_Parent( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{scclass}", to_string( get_obj( ).Source_Child_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{scfield}", to_string( get_obj( ).Source_Child( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{scfield_id}", to_string( get_obj( ).Source_Child( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{sc2field}", to_string( get_obj( ).Source_Child_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{sc2field_id}", to_string( get_obj( ).Source_Child_2( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{sfield}", to_string( get_obj( ).Source_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{sfield_id}", to_string( get_obj( ).Source_Field( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{sgcfield}", to_string( get_obj( ).Source_Grandchild( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{tpfield}", to_string( get_obj( ).Test_Parent( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{tcfield}", to_string( get_obj( ).Test_Child( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{tfield}", to_string( get_obj( ).Test_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{tfield_id}", to_string( get_obj( ).Test_Field( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{tfclass}", to_string( get_obj( ).Test_Field_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{tvalue}", to_string( get_obj( ).Test_Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{perm}", to_string( get_obj( ).Permission( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{procedure}", to_string( get_obj( ).Procedure( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{procedure_id}", to_string( get_obj( ).Procedure( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{procedure_arg}", to_string( get_obj( ).Procedure_Arg( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{procedure_arg2}", to_string( get_obj( ).Procedure_Arg_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{procedure_arg3}", to_string( get_obj( ).Procedure_Arg_3( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{oprocedure}", to_string( get_obj( ).Other_Procedure( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{oprocedure_id}", to_string( get_obj( ).Other_Procedure( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{o2procedure}", to_string( get_obj( ).Other_Procedure_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{o2procedure_id}", to_string( get_obj( ).Other_Procedure_2( ).Id( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{cname}", to_string( get_obj( ).Child_Relationship( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{child}", to_string( get_obj( ).Child_Relationship( ).Child_Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{cclass}", to_string( get_obj( ).Child_Relationship( ).Child_Class_Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{cffield}", to_string( get_obj( ).Child_Relationship( ).Child_Class_File_Field_Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{primitive}", to_string( get_obj( ).Field( ).Primitive( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum}", to_string( get_obj( ).Enum( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum_item}", to_string( get_obj( ).Enum_Item( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum_value}", to_string( get_obj( ).Enum_Item( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum2_item}", to_string( get_obj( ).Enum_Item_2( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum2_value}", to_string( get_obj( ).Enum_Item_2( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum3_item}", to_string( get_obj( ).Enum_Item_3( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum3_value}", to_string( get_obj( ).Enum_Item_3( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum4_item}", to_string( get_obj( ).Enum_Item_4( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum4_value}", to_string( get_obj( ).Enum_Item_4( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum5_item}", to_string( get_obj( ).Enum_Item_5( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{enum5_value}", to_string( get_obj( ).Enum_Item_5( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{value}", to_string( get_obj( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{value_literal}", to_string( get_obj( ).Value_Literal( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{value_string}", to_string( get_obj( ).Value_String( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{value_leftpart}", to_string( get_obj( ).Value_Left_Part( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{value_rightpart}", to_string( get_obj( ).Value_Right_Part( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{field_values}", to_string( get_obj( ).Field_Values( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{fields}", to_string( get_obj( ).Fields( ) ) );
      get_obj( ).add_search_replacement( "Vars", "{field_pairs}", to_string( get_obj( ).Field_Pairs( ) ) );

      vector< string > options_set;
      split_string( get_obj( ).Options( ), options_set, ' ' );

      for( size_t i = 0; i < options_set.size( ); i++ )
      {
         string next_search;

         string next_opt( options_set[ i ] );
         string::size_type pos = next_opt.find( '=' );

         string next_val;
         if( pos != string::npos )
            next_val = next_opt.substr( pos + 1 );

         next_search = "{?"  + next_opt + "}";
         get_obj( ).add_search_replacement( "Vars", next_search, "true" );

         if( pos != string::npos )
         {
            next_search = "{#"  + next_opt.substr( 0, pos ) + "}";
            get_obj( ).add_search_replacement( "Vars", next_search, next_val );
         }
      }
   }
   // [(finish field_from_search_replace)]

   // [(start field_from_search_replace)]
   if( !get_obj( ).get_key( ).empty( )
    && ( get_obj( ).needs_field_value( "Strings" )
    || required_transients.count( "Strings" ) ) )
   {
      string str( get_obj( ).Specification_Type( ).Specification_Strings( ) );

      get_obj( ).Strings( str );

      get_obj( ).add_search_replacement( "Strings", "{model}", to_string( get_obj( ).Model( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{class}", to_string( get_obj( ).Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{field}", to_string( get_obj( ).Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{fclass}", to_string( get_obj( ).Field_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{modifier}", to_string( get_obj( ).Modifier( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{spfield}", to_string( get_obj( ).Source_Parent( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{scfield}", to_string( get_obj( ).Source_Child( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{sc2field}", to_string( get_obj( ).Source_Child_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{sfield}", to_string( get_obj( ).Source_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{tpfield}", to_string( get_obj( ).Test_Parent( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{tcfield}", to_string( get_obj( ).Test_Child( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{tfield}", to_string( get_obj( ).Test_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{tfclass}", to_string( get_obj( ).Test_Field_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{tvalue}", to_string( get_obj( ).Test_Value( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{procedure}", to_string( get_obj( ).Procedure( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{child}", to_string( get_obj( ).Child_Relationship( ).Child_Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{enum}", to_string( get_obj( ).Enum( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{enum_item}", to_string( get_obj( ).Enum_Item( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{enum_value}", to_string( get_obj( ).Enum_Item( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{value}", to_string( get_obj( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Strings", "{value_rightpart}", to_string( get_obj( ).Value_Right_Part( ) ) );
   }
   // [(finish field_from_search_replace)]

   // [<start after_fetch>]
   // [<finish after_fetch>]
}

void Meta_Specification::impl::finalise_fetch( )
{
   set< string > required_transients;

   p_obj->get_required_field_names( required_transients, true );

   // [(start field_from_procedure_call)]
   if( !get_obj( ).get_key( ).empty( )
    && ( get_obj( ).needs_field_value( "All_Vars" )
    || required_transients.count( "All_Vars" ) ) )
   {
      string str;
      get_obj( ).Generate_All_Vars( str, "" );
      get_obj( ).All_Vars( str );
   }
   // [(finish field_from_procedure_call)]

   // [(start field_from_procedure_call)]
   if( !get_obj( ).get_key( ).empty( )
    && ( get_obj( ).needs_field_value( "All_Strings" )
    || required_transients.count( "All_Strings" ) ) )
   {
      string str;
      get_obj( ).Generate_All_Strings( str, "" );
      get_obj( ).All_Strings( str );
   }
   // [(finish field_from_procedure_call)]

   // [<start finalise_fetch>]
   // [<finish finalise_fetch>]
}

void Meta_Specification::impl::at_create( )
{
   // [<start at_create>]
   // [<finish at_create>]
}

void Meta_Specification::impl::to_store( bool is_create, bool is_internal )
{
   ( void )is_create;
   ( void )is_internal;

   uint64_t state = p_obj->get_state( );
   ( void )state;

   // [(start meta_spec_field_type)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "user_info"
    && !get_obj( ).Class( ).get_key( ).empty( ) && is_null( get_obj( ).Source_Parent( ) ) )
   {
      if( get_obj( ).Class( ).child_Field( ).iterate_forwards( ) )
      {
         do
         {
            if( get_obj( ).Class( ).child_Field( ).Extra( ) == -2 ) // i.e. user_group
            {
               get_obj( ).Source_Parent( get_obj( ).Class( ).child_Field( ) );
               break;
            }
         } while( get_obj( ).Class( ).child_Field( ).iterate_next( ) );
      }
   }
   // [(finish meta_spec_field_type)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Model( ) ) && !to_string( get_obj( ).Parent_Specification( ) ).empty( ) )
      get_obj( ).Model( get_obj( ).Parent_Specification( ).Model( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Specification_Type( ) ) && !to_string( get_obj( ).Parent_Specification( ) ).empty( ) )
      get_obj( ).Specification_Type( get_obj( ).Parent_Specification( ).Child_Specification_Type( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Class( ) == true )
      get_obj( ).Class( get_obj( ).Parent_Specification( ).Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Source_Parent_For_Class( ) == true )
      get_obj( ).Class( get_obj( ).Parent_Specification( ).Source_Parent_Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Child_Rel_For_Class( ) == true )
      get_obj( ).Class( get_obj( ).Parent_Specification( ).Child_Rel_Child_Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Field_For_Class( ) == true )
      get_obj( ).Class( get_obj( ).Parent_Specification( ).Field_Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Source_Field_For_Class( ) == true )
      get_obj( ).Class( get_obj( ).Parent_Specification( ).Source_Field_Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Other_Class_For_Class( ) == true )
      get_obj( ).Class( get_obj( ).Parent_Specification( ).Other_Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Source_Parent( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Source_Parent( ) == true )
      get_obj( ).Source_Parent( get_obj( ).Parent_Specification( ).Source_Parent( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Source_Parent( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Child_Rel_As_Source_Parent( ) == true )
      get_obj( ).Source_Parent( get_obj( ).Parent_Specification( ).Child_Rel_Field_Key( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Source_Class( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Source_Class( ) == true )
      get_obj( ).Source_Class( get_obj( ).Parent_Specification( ).Source_Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Actions( ) ) )
      get_obj( ).Actions( get_obj( ).Specification_Type( ).Specification_Actions( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Child_Specification_Type( ) ) )
      get_obj( ).Child_Specification_Type( get_obj( ).Specification_Type( ).Child_Specification_Type( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Model( ) ) )
      get_obj( ).Model( get_obj( ).Class( ).Model( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Source_Class( ) ) )
      get_obj( ).Source_Class( get_obj( ).Class( ) );
   // [(finish default_to_field)]

   // [(start field_clear_on_changed_fk)]
   if( !is_create && get_obj( ).Class( ).has_changed( ) )
      get_obj( ).Source_Parent( "" );
   // [(finish field_clear_on_changed_fk)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && get_obj( ).Use_Source_Parent( ) )
      get_obj( ).Source_Field( "" );
   // [(finish field_clear)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && !get_obj( ).Use_Source_Parent( ) )
      get_obj( ).Source_Parent( "" );
   // [(finish field_clear)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && !get_obj( ).Use_Source_Parent( ) )
      get_obj( ).Source_Child( "" );
   // [(finish field_clear)]

   // [(start field_clear_on_changed_fk)]
   if( !is_create && get_obj( ).Class( ).has_changed( ) )
      get_obj( ).Child_Relationship( "" );
   // [(finish field_clear_on_changed_fk)]

   // [(start field_from_other_field)]
   get_obj( ).Source_Parent_Class( get_obj( ).Source_Parent( ).Parent_Class( ) );
   // [(finish field_from_other_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Source_Parent_Class( ) ) && get_obj( ).Specification_Type( ).Use_Class_As_Source_Parent_Class( ) == true )
      get_obj( ).Source_Parent_Class( get_obj( ).Class( ) );
   // [(finish default_to_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Name( ) ) )
      get_obj( ).Name( get_obj( ).Specification_Type( ).Specification_Name( ) );
   // [(finish default_to_field)]

   // [(start default_from_key)]
   if( !get_obj( ).get_clone_key( ).empty( ) || ( is_create && is_null( get_obj( ).Order( ) ) ) )
      get_obj( ).Order( get_obj( ).get_key( ) );
   // [(finish default_from_key)]

   // [(start field_clear_on_changed_fk)]
   if( get_obj( ).Specification_Type( ).Use_Field_Enum( ) && get_obj( ).Class( ).has_changed( ) )
      get_obj( ).Enum( "" );
   // [(finish field_clear_on_changed_fk)]

   // [(start field_clear_on_changed_fk)]
   if( !is_create && get_obj( ).Class( ).has_changed( ) )
      get_obj( ).Test_Parent( "" );
   // [(finish field_clear_on_changed_fk)]

   // [(start field_from_other_field)]
   get_obj( ).Test_Parent_Class( get_obj( ).Test_Parent( ).Parent_Class( ) );
   // [(finish field_from_other_field)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) && get_obj( ).Use_Test_Parent_Child( ) )
      get_obj( ).Test_Field( "" );
   // [(finish field_clear)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) && !get_obj( ).Use_Test_Parent_Child( ) )
      get_obj( ).Test_Parent( "" );
   // [(finish field_clear)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Test_Field_Choice( ) && !get_obj( ).Use_Test_Parent_Child( ) )
      get_obj( ).Test_Child( "" );
   // [(finish field_clear)]

   // [(start field_from_other_field)]
   get_obj( ).Child_Rel_Field_Key( get_obj( ).Child_Relationship( ).Field_Key( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   get_obj( ).Child_Rel_Child_Class( get_obj( ).Child_Relationship( ).Child_Class( ) );
   // [(finish field_from_other_field)]

   // [(start default_to_field)]
   if( is_create && is_null( get_obj( ).Procedure( ) ) && get_obj( ).Specification_Type( ).Use_Parent_Procedure( ) == true )
      get_obj( ).Procedure( get_obj( ).Parent_Specification( ).Procedure( ) );
   // [(finish default_to_field)]

   // [(start field_from_other_field)]
   get_obj( ).Is_Required_For_UI_Gen( get_obj( ).Specification_Type( ).Is_Required_For_UI_Gen( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Source_Field( ) ) && get_obj( ).Specification_Type( ).Set_Field_To_Source_Field_Or_Child( ) == true )
      get_obj( ).Field( get_obj( ).Source_Field( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Source_Child( ) ) && get_obj( ).Specification_Type( ).Set_Field_To_Source_Field_Or_Child( ) == true )
      get_obj( ).Field( get_obj( ).Source_Child( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   get_obj( ).Value_Literal( get_obj( ).Value( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Value( ) ) && get_obj( ).Field( ).Is_Text_Type( ) == true )
      get_obj( ).Value_Literal( quoted_literal( get_obj( ).Value( ) ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Value( ) ) )
      get_obj( ).Value_String( unquoted_literal( get_obj( ).Value( ) ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Value( ) ) )
      get_obj( ).Value_Numeric_String( numeric_name( get_obj( ).Value( ) ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Value( ) ) )
      get_obj( ).Value_Left_Part( value_leftpart( get_obj( ).Value( ) ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( !is_null( get_obj( ).Value( ) ) )
      get_obj( ).Value_Right_Part( value_rightpart( get_obj( ).Value( ) ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   if( get_obj( ).Specification_Type( ).Use_Field_Enum( ) == true )
      get_obj( ).Enum( get_obj( ).Field( ).Enum( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   get_obj( ).Field_Class( get_obj( ).Field( ).Parent_Class( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   get_obj( ).Test_Field_Class( get_obj( ).Test_Field( ).Parent_Class( ) );
   // [(finish field_from_other_field)]

   // [(start field_from_other_field)]
   get_obj( ).Source_Child_Class( get_obj( ).Source_Child( ).Parent_Class( ) );
   // [(finish field_from_other_field)]

   // [(start meta_spec_field_values)]
   // NOTE: Scope for local variables.
   {
      string str, rstr;
      if( !is_create && get_obj( ).child_Specification_Parent( ).iterate_forwards( ) )
      {
         do
         {
            if( get_obj( ).child_Specification_Parent( ).Specification_Type( ).get_key( ) == "restriction_field_list" )
            {
               string key_info( FIELD_ID( Meta, Specification, Order ) );
               key_info += ' ';
               if( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_forwards( key_info ) )
               {
                  do
                  {
                     if( !rstr.empty( ) )
                        rstr += "+";

                     string value( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Value( ) );
                     if( !value.empty( ) && value[ 0 ] == '@' )
                     {
                        if( value != "@order" )
                           rstr += value + ":";
                        value.erase( );
                     }

                     rstr += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Id( );

                     if( value == "<none>" )
                        rstr += "=";
                     else if( !value.empty( ) )
                        rstr += "=" + value;

                     if( !str.empty( ) )
                        str += "_and_";

                     str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Name( );
                  } while( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_next( ) );
               }
               get_obj( ).child_Specification_Parent( ).iterate_stop( );
               break;
            }
         } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );
      }

      if( get_obj( ).Specification_Type( ).get_key( ) == "restriction" )
      {
         if( !get_obj( ).Value( ).empty( ) )
         {
            if( !rstr.empty( ) )
               rstr += "+";
            rstr += get_obj( ).Value( );
         }
      }

      if( !is_create || get_obj( ).Specification_Type( ).get_key( ) == "restriction" )
      {
         get_obj( ).Field_Values( str );
         get_obj( ).Restrict_Values( rstr );
      }
   }
   // [(finish meta_spec_field_values)]

   // [(start field_clear)]
   get_obj( ).Fields( "" );
   // [(finish field_clear)]

   // [(start field_clear)]
   get_obj( ).Field_Pairs( "" );
   // [(finish field_clear)]

   // [(start meta_spec_field_pairs)]
   if( !is_create && get_obj( ).child_Specification_Parent( ).iterate_forwards( ) )
   {
      string str( get_obj( ).Fields( ) );
      do
      {
         if( get_obj( ).child_Specification_Parent( ).Name( ) == "field_list" )
         {
            string key_info( FIELD_ID( Meta, Specification, Order ) );
            key_info += ' ';
            if( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_forwards( key_info ) )
            {
               do
               {
                  if( !str.empty( ) )
                     str += " ";

                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Name( );

               } while( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_next( ) );
            }
            get_obj( ).child_Specification_Parent( ).iterate_stop( );
            break;
         }
      } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );

      get_obj( ).Fields( str );
   }
   // [(finish meta_spec_field_pairs)]

   // [(start meta_spec_field_pairs)]
   if( !is_create && get_obj( ).child_Specification_Parent( ).iterate_forwards( ) )
   {
      string str( get_obj( ).Field_Pairs( ) );
      do
      {
         if( get_obj( ).child_Specification_Parent( ).Name( ) == "field_pair_list" )
         {
            string key_info( FIELD_ID( Meta, Specification, Order ) );
            key_info += ' ';
            if( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_forwards( key_info ) )
            {
               do
               {
                  if( !str.empty( ) )
                     str += " ";

                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Name( );

                  str += ",";
                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Source_Child( ).Name( );

                  str += ",";
                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Parent_Class_Name( );

               } while( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_next( ) );
            }
            get_obj( ).child_Specification_Parent( ).iterate_stop( );
            break;
         }
      } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );

      get_obj( ).Field_Pairs( str );
   }
   // [(finish meta_spec_field_pairs)]

   // [(start meta_spec_field_pairs)]
   if( !is_create && get_obj( ).child_Specification_Parent( ).iterate_forwards( ) )
   {
      string str( get_obj( ).Field_Pairs( ) );
      do
      {
         if( get_obj( ).child_Specification_Parent( ).Name( ) == "field_pair2_list" )
         {
            string key_info( FIELD_ID( Meta, Specification, Order ) );
            key_info += ' ';
            if( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_forwards( key_info ) )
            {
               do
               {
                  if( !str.empty( ) )
                     str += " ";

                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Name( );

                  str += ",";
                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Source_Field( ).Name( );

                  str += ",";
                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Parent_Class_Name( );

               } while( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_next( ) );
            }
            get_obj( ).child_Specification_Parent( ).iterate_stop( );
            break;
         }
      } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );

      get_obj( ).Field_Pairs( str );
   }
   // [(finish meta_spec_field_pairs)]

   // [(start meta_spec_field_pairs)]
   if( !is_create && get_obj( ).child_Specification_Parent( ).iterate_forwards( ) )
   {
      string str( get_obj( ).Field_Pairs( ) );
      do
      {
         if( get_obj( ).child_Specification_Parent( ).Name( ) == "field_pair_g_list" )
         {
            string key_info( FIELD_ID( Meta, Specification, Order ) );
            key_info += ' ';
            if( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_forwards( key_info ) )
            {
               do
               {
                  if( !str.empty( ) )
                     str += " ";

                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Name( );

                  str += ",";
                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Source_Grandchild( ).Name( );

                  str += ",";
                  str += get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).Field( ).Parent_Class_Name( );

               } while( get_obj( ).child_Specification_Parent( ).child_Specification_Parent( ).iterate_next( ) );
            }
            get_obj( ).child_Specification_Parent( ).iterate_stop( );
            break;
         }
      } while( get_obj( ).child_Specification_Parent( ).iterate_next( ) );

      get_obj( ).Field_Pairs( str );
   }
   // [(finish meta_spec_field_pairs)]

   // [(start field_from_search_replace)]
   if( get_obj( ).get_is_editing( ) )
   {
      string str( get_obj( ).Specification_Type( ).Specification_Name( ) );

      get_obj( ).Name( str );

      get_obj( ).add_search_replacement( "Name", "{class}", to_string( get_obj( ).Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{field}", to_string( get_obj( ).Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{ofield}", to_string( get_obj( ).Other_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{o2field}", to_string( get_obj( ).Other_Field_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{modifier}", to_string( get_obj( ).Modifier( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{sclass}", to_string( get_obj( ).Source_Class( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{spfield}", to_string( get_obj( ).Source_Parent( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{scfield}", to_string( get_obj( ).Source_Child( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{sc2field}", to_string( get_obj( ).Source_Child_2( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{sfield}", to_string( get_obj( ).Source_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{sgcfield}", to_string( get_obj( ).Source_Grandchild( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{tpfield}", to_string( get_obj( ).Test_Parent( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{tcfield}", to_string( get_obj( ).Test_Child( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{tfield}", to_string( get_obj( ).Test_Field( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{tvalue}", to_string( get_obj( ).Test_Value( ) ) );
      get_obj( ).add_search_replacement( "Name", "{perm}", to_string( get_obj( ).Permission( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{procedure}", to_string( get_obj( ).Procedure( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{procedure_arg}", to_string( get_obj( ).Procedure_Arg( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{cname}", to_string( get_obj( ).Child_Relationship( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{child}", to_string( get_obj( ).Child_Relationship( ).Child_Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{cclass}", to_string( get_obj( ).Child_Relationship( ).Child_Class_Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{enum}", to_string( get_obj( ).Enum( ).Name( ) ) );
      get_obj( ).add_search_replacement( "Name", "{enum_item}", to_string( get_obj( ).Enum_Item( ).Label( ) ) );
      get_obj( ).add_search_replacement( "Name", "{value}", to_string( get_obj( ).Value( ) ) );
      get_obj( ).add_search_replacement( "Name", "{value_numstr}", to_string( get_obj( ).Value_Numeric_String( ) ) );
      get_obj( ).add_search_replacement( "Name", "{field_values}", to_string( get_obj( ).Field_Values( ) ) );
      get_obj( ).add_search_replacement( "Name", "{fields}", to_string( get_obj( ).Fields( ) ) );
      get_obj( ).add_search_replacement( "Name", "{field_pairs}", to_string( get_obj( ).Field_Pairs( ) ) );

      get_obj( ).set_search_replace_separator( "Name", '_' );

      get_obj( ).set_search_replace_has_opt_prefixing( "Name" );
   }
   // [(finish field_from_search_replace)]

   // [(start field_clear)]
   if( get_obj( ).Specification_Type( ).Allow_FK_Source_Field_Choice( ) && !get_obj( ).Use_Source_Parent( ) )
      get_obj( ).Source_Child_2( "" );
   // [(finish field_clear)]

   // [(start field_from_other_field)]
   get_obj( ).Source_Field_Class( get_obj( ).Source_Field( ).Parent_Class( ) );
   // [(finish field_from_other_field)]

   // [<start to_store>]
   // [<finish to_store>]
}

void Meta_Specification::impl::for_store( bool is_create, bool is_internal )
{
   ( void )is_create;
   ( void )is_internal;

   // [(start parent_auto_int_inc)]
   if( is_create && is_null( get_obj( ).Id( ) ) )
   {
      get_obj( ).Model( ).op_update( get_obj( ).Model( ), FIELD_NAME( Meta, Model, Next_Specification_Id ) );

      get_obj( ).Id( get_obj( ).Model( ).Next_Specification_Id( ) );

      get_obj( ).Model( ).Next_Specification_Id( auto_int_increment( get_obj( ).Model( ).Next_Specification_Id( ) ) );
      get_obj( ).Model( ).op_apply( );
   }
   // [(finish parent_auto_int_inc)]

   // [(start parent_field_from_other)]
   if( is_create && get_obj( ).Specification_Type( ).Has_Next_Specification_Info( ) == true )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      cp_parent->op_update( );
      cp_parent->Actions( get_obj( ).Specification_Type( ).Next_Specification_Actions( ) );
      cp_parent->op_apply( );
   }
   // [(finish parent_field_from_other)]

   // [(start parent_field_from_other)]
   if( is_create && get_obj( ).Specification_Type( ).Has_Next_Specification_Info( ) == true )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      cp_parent->op_update( );
      cp_parent->Child_Specification_Type( get_obj( ).Specification_Type( ).Next_Child_Specification_Type( ) );
      cp_parent->op_apply( );
   }
   // [(finish parent_field_from_other)]

   // [(start parent_field_from_other)]
   if( is_create && get_obj( ).Specification_Type( ).Has_Next_Specification_Info( ) == true )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      cp_parent->op_update( );
      cp_parent->Protect_Source_Parent( get_obj( ).Specification_Type( ).Next_Protect_Source_Parent( ) );
      cp_parent->op_apply( );
   }
   // [(finish parent_field_from_other)]

   // [(start parent_field_from_other)]
   if( is_create && get_obj( ).Specification_Type( ).Has_Next_Specification_Info( ) == true )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      cp_parent->op_update( );
      cp_parent->Protect_Procedure( get_obj( ).Specification_Type( ).Next_Protect_Procedure( ) );
      cp_parent->op_apply( );
   }
   // [(finish parent_field_from_other)]

   // [(start parent_field_from_other)]
   if( is_create && get_obj( ).Specification_Type( ).Has_Next_Specification_Info( ) == true )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      cp_parent->op_update( );
      cp_parent->Protect_Child_Rel( get_obj( ).Specification_Type( ).Next_Protect_Child_Rel( ) );
      cp_parent->op_apply( );
   }
   // [(finish parent_field_from_other)]

   // [<start for_store>]
   // [<finish for_store>]
}

void Meta_Specification::impl::after_store( bool is_create, bool is_internal )
{
   ( void )is_create;
   ( void )is_internal;

   // [(start copy_child_links_from_fk)]
   if( is_create
    && get_obj( ).get_clone_key( ).empty( )
    && get_obj( ).Specification_Type( ).child_Specification_Type_Parent( ).iterate_forwards( ) )
   {
      int child_num = 0;
      do
      {
         string child_key( construct_key_from_int( get_obj( ).get_key( ), ++child_num ) );

         get_obj( ).child_Specification_Parent( ).op_create( child_key );

         get_obj( ).child_Specification_Parent( ).Parent_Specification( get_obj( ).get_key( ) );
         get_obj( ).child_Specification_Parent( ).Specification_Type( get_obj( ).Specification_Type( ).child_Specification_Type_Parent( ).get_key( ) );

         get_obj( ).child_Specification_Parent( ).Actions( get_obj( ).Specification_Type( ).child_Specification_Type_Parent( ).Specification_Actions( ) );

         get_obj( ).child_Specification_Parent( ).op_apply( );

      } while( get_obj( ).Specification_Type( ).child_Specification_Type_Parent( ).iterate_next( ) );
   }
   // [(finish copy_child_links_from_fk)]

   // [(start update_parent_cascade)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "field" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "field_pair" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "field_pair2" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "field_pair_g" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "field_restrict" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( get_obj( ).Specification_Type( ).get_key( ) == "home_message_stats_info" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [<start after_store>]
   // [<finish after_store>]
}

bool Meta_Specification::impl::can_destroy( bool is_internal )
{
   bool retval = is_internal || !( get_state( ) & c_state_undeletable );

   // [(start destroy_restrict)]
   if( !is_internal && get_obj( ).Specification_Type( ).Is_System( ) == true )
      retval = false;
   // [(finish destroy_restrict)]

   // [<start can_destroy>]
   // [<finish can_destroy>]

   return retval;
}

void Meta_Specification::impl::for_destroy( bool is_internal )
{
   ( void )is_internal;

   // [<start for_destroy>]
   // [<finish for_destroy>]
}

void Meta_Specification::impl::after_destroy( bool is_internal )
{
   ( void )is_internal;

   // [(start update_parent_cascade)]
   if( !get_obj( ).get_is_being_cascaded( ) && get_obj( ).Specification_Type( ).get_key( ) == "field" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( !get_obj( ).get_is_being_cascaded( ) && get_obj( ).Specification_Type( ).get_key( ) == "field_pair" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( !get_obj( ).get_is_being_cascaded( ) && get_obj( ).Specification_Type( ).get_key( ) == "field_pair2" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( !get_obj( ).get_is_being_cascaded( ) && get_obj( ).Specification_Type( ).get_key( ) == "field_pair_g" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( !get_obj( ).get_is_being_cascaded( ) && get_obj( ).Specification_Type( ).get_key( ) == "field_restrict" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   if( !get_obj( ).get_is_being_cascaded( ) && get_obj( ).Specification_Type( ).get_key( ) == "home_message_stats_info" )
   {
      class_pointer< Meta_Specification > cp_parent( &get_obj( ).Parent_Specification( ) );

      if( !cp_parent->get_key( ).empty( ) )
      {
         cp_parent->op_update( );
         cp_parent->op_apply( );
      }
   }
   // [(finish update_parent_cascade)]

   // [<start after_destroy>]
   // [<finish after_destroy>]
}

void Meta_Specification::impl::set_default_values( )
{
   clear( );
}

bool Meta_Specification::impl::is_filtered( const set< string >& filters ) const
{
   ( void )filters;

   // [<start is_filtered>]
   // [<finish is_filtered>]

   return false;
}

#undef MODULE_TRACE
#define MODULE_TRACE( x ) trace( x )

Meta_Specification::Meta_Specification( )
{
   set_version( c_version );

   p_impl = new impl( *this );
}

Meta_Specification::~Meta_Specification( )
{
   cleanup( );
   delete p_impl;
}

const string& Meta_Specification::Actions( ) const
{
   return p_impl->impl_Actions( );
}

void Meta_Specification::Actions( const string& Actions )
{
   p_impl->impl_Actions( Actions );
}

const string& Meta_Specification::All_Strings( ) const
{
   return p_impl->impl_All_Strings( );
}

void Meta_Specification::All_Strings( const string& All_Strings )
{
   p_impl->impl_All_Strings( All_Strings );
}

const string& Meta_Specification::All_Vars( ) const
{
   return p_impl->impl_All_Vars( );
}

void Meta_Specification::All_Vars( const string& All_Vars )
{
   p_impl->impl_All_Vars( All_Vars );
}

const string& Meta_Specification::Child_Rel_Field_Key( ) const
{
   return p_impl->impl_Child_Rel_Field_Key( );
}

void Meta_Specification::Child_Rel_Field_Key( const string& Child_Rel_Field_Key )
{
   p_impl->impl_Child_Rel_Field_Key( Child_Rel_Field_Key );
}

const string& Meta_Specification::Comments( ) const
{
   return p_impl->impl_Comments( );
}

void Meta_Specification::Comments( const string& Comments )
{
   p_impl->impl_Comments( Comments );
}

const string& Meta_Specification::Field_Pairs( ) const
{
   return p_impl->impl_Field_Pairs( );
}

void Meta_Specification::Field_Pairs( const string& Field_Pairs )
{
   p_impl->impl_Field_Pairs( Field_Pairs );
}

const string& Meta_Specification::Field_Values( ) const
{
   return p_impl->impl_Field_Values( );
}

void Meta_Specification::Field_Values( const string& Field_Values )
{
   p_impl->impl_Field_Values( Field_Values );
}

const string& Meta_Specification::Fields( ) const
{
   return p_impl->impl_Fields( );
}

void Meta_Specification::Fields( const string& Fields )
{
   p_impl->impl_Fields( Fields );
}

const string& Meta_Specification::Id( ) const
{
   return p_impl->impl_Id( );
}

void Meta_Specification::Id( const string& Id )
{
   p_impl->impl_Id( Id );
}

bool Meta_Specification::Is_Required_For_UI_Gen( ) const
{
   return p_impl->impl_Is_Required_For_UI_Gen( );
}

void Meta_Specification::Is_Required_For_UI_Gen( bool Is_Required_For_UI_Gen )
{
   p_impl->impl_Is_Required_For_UI_Gen( Is_Required_For_UI_Gen );
}

const string& Meta_Specification::Name( ) const
{
   return p_impl->impl_Name( );
}

void Meta_Specification::Name( const string& Name )
{
   p_impl->impl_Name( Name );
}

const string& Meta_Specification::Options( ) const
{
   return p_impl->impl_Options( );
}

void Meta_Specification::Options( const string& Options )
{
   p_impl->impl_Options( Options );
}

const string& Meta_Specification::Order( ) const
{
   return p_impl->impl_Order( );
}

void Meta_Specification::Order( const string& Order )
{
   p_impl->impl_Order( Order );
}

bool Meta_Specification::Protect_Child_Rel( ) const
{
   return p_impl->impl_Protect_Child_Rel( );
}

void Meta_Specification::Protect_Child_Rel( bool Protect_Child_Rel )
{
   p_impl->impl_Protect_Child_Rel( Protect_Child_Rel );
}

bool Meta_Specification::Protect_Procedure( ) const
{
   return p_impl->impl_Protect_Procedure( );
}

void Meta_Specification::Protect_Procedure( bool Protect_Procedure )
{
   p_impl->impl_Protect_Procedure( Protect_Procedure );
}

bool Meta_Specification::Protect_Source_Parent( ) const
{
   return p_impl->impl_Protect_Source_Parent( );
}

void Meta_Specification::Protect_Source_Parent( bool Protect_Source_Parent )
{
   p_impl->impl_Protect_Source_Parent( Protect_Source_Parent );
}

const string& Meta_Specification::Restrict_Values( ) const
{
   return p_impl->impl_Restrict_Values( );
}

void Meta_Specification::Restrict_Values( const string& Restrict_Values )
{
   p_impl->impl_Restrict_Values( Restrict_Values );
}

const string& Meta_Specification::Strings( ) const
{
   return p_impl->impl_Strings( );
}

void Meta_Specification::Strings( const string& Strings )
{
   p_impl->impl_Strings( Strings );
}

const string& Meta_Specification::Test_Value( ) const
{
   return p_impl->impl_Test_Value( );
}

void Meta_Specification::Test_Value( const string& Test_Value )
{
   p_impl->impl_Test_Value( Test_Value );
}

bool Meta_Specification::Use_Source_Parent( ) const
{
   return p_impl->impl_Use_Source_Parent( );
}

void Meta_Specification::Use_Source_Parent( bool Use_Source_Parent )
{
   p_impl->impl_Use_Source_Parent( Use_Source_Parent );
}

bool Meta_Specification::Use_Test_Parent_Child( ) const
{
   return p_impl->impl_Use_Test_Parent_Child( );
}

void Meta_Specification::Use_Test_Parent_Child( bool Use_Test_Parent_Child )
{
   p_impl->impl_Use_Test_Parent_Child( Use_Test_Parent_Child );
}

const string& Meta_Specification::Value( ) const
{
   return p_impl->impl_Value( );
}

void Meta_Specification::Value( const string& Value )
{
   p_impl->impl_Value( Value );
}

const string& Meta_Specification::Value_Left_Part( ) const
{
   return p_impl->impl_Value_Left_Part( );
}

void Meta_Specification::Value_Left_Part( const string& Value_Left_Part )
{
   p_impl->impl_Value_Left_Part( Value_Left_Part );
}

const string& Meta_Specification::Value_Literal( ) const
{
   return p_impl->impl_Value_Literal( );
}

void Meta_Specification::Value_Literal( const string& Value_Literal )
{
   p_impl->impl_Value_Literal( Value_Literal );
}

const string& Meta_Specification::Value_Numeric_String( ) const
{
   return p_impl->impl_Value_Numeric_String( );
}

void Meta_Specification::Value_Numeric_String( const string& Value_Numeric_String )
{
   p_impl->impl_Value_Numeric_String( Value_Numeric_String );
}

const string& Meta_Specification::Value_Right_Part( ) const
{
   return p_impl->impl_Value_Right_Part( );
}

void Meta_Specification::Value_Right_Part( const string& Value_Right_Part )
{
   p_impl->impl_Value_Right_Part( Value_Right_Part );
}

const string& Meta_Specification::Value_String( ) const
{
   return p_impl->impl_Value_String( );
}

void Meta_Specification::Value_String( const string& Value_String )
{
   p_impl->impl_Value_String( Value_String );
}

const string& Meta_Specification::Vars( ) const
{
   return p_impl->impl_Vars( );
}

void Meta_Specification::Vars( const string& Vars )
{
   p_impl->impl_Vars( Vars );
}

Meta_Class& Meta_Specification::Child_Rel_Child_Class( )
{
   return p_impl->impl_Child_Rel_Child_Class( );
}

const Meta_Class& Meta_Specification::Child_Rel_Child_Class( ) const
{
   return p_impl->impl_Child_Rel_Child_Class( );
}

void Meta_Specification::Child_Rel_Child_Class( const string& key )
{
   p_impl->impl_Child_Rel_Child_Class( key );
}

Meta_Relationship& Meta_Specification::Child_Relationship( )
{
   return p_impl->impl_Child_Relationship( );
}

const Meta_Relationship& Meta_Specification::Child_Relationship( ) const
{
   return p_impl->impl_Child_Relationship( );
}

void Meta_Specification::Child_Relationship( const string& key )
{
   p_impl->impl_Child_Relationship( key );
}

Meta_Specification_Type& Meta_Specification::Child_Specification_Type( )
{
   return p_impl->impl_Child_Specification_Type( );
}

const Meta_Specification_Type& Meta_Specification::Child_Specification_Type( ) const
{
   return p_impl->impl_Child_Specification_Type( );
}

void Meta_Specification::Child_Specification_Type( const string& key )
{
   p_impl->impl_Child_Specification_Type( key );
}

Meta_Class& Meta_Specification::Class( )
{
   return p_impl->impl_Class( );
}

const Meta_Class& Meta_Specification::Class( ) const
{
   return p_impl->impl_Class( );
}

void Meta_Specification::Class( const string& key )
{
   p_impl->impl_Class( key );
}

Meta_Enum& Meta_Specification::Enum( )
{
   return p_impl->impl_Enum( );
}

const Meta_Enum& Meta_Specification::Enum( ) const
{
   return p_impl->impl_Enum( );
}

void Meta_Specification::Enum( const string& key )
{
   p_impl->impl_Enum( key );
}

Meta_Enum_Item& Meta_Specification::Enum_Item( )
{
   return p_impl->impl_Enum_Item( );
}

const Meta_Enum_Item& Meta_Specification::Enum_Item( ) const
{
   return p_impl->impl_Enum_Item( );
}

void Meta_Specification::Enum_Item( const string& key )
{
   p_impl->impl_Enum_Item( key );
}

Meta_Enum_Item& Meta_Specification::Enum_Item_2( )
{
   return p_impl->impl_Enum_Item_2( );
}

const Meta_Enum_Item& Meta_Specification::Enum_Item_2( ) const
{
   return p_impl->impl_Enum_Item_2( );
}

void Meta_Specification::Enum_Item_2( const string& key )
{
   p_impl->impl_Enum_Item_2( key );
}

Meta_Enum_Item& Meta_Specification::Enum_Item_3( )
{
   return p_impl->impl_Enum_Item_3( );
}

const Meta_Enum_Item& Meta_Specification::Enum_Item_3( ) const
{
   return p_impl->impl_Enum_Item_3( );
}

void Meta_Specification::Enum_Item_3( const string& key )
{
   p_impl->impl_Enum_Item_3( key );
}

Meta_Enum_Item& Meta_Specification::Enum_Item_4( )
{
   return p_impl->impl_Enum_Item_4( );
}

const Meta_Enum_Item& Meta_Specification::Enum_Item_4( ) const
{
   return p_impl->impl_Enum_Item_4( );
}

void Meta_Specification::Enum_Item_4( const string& key )
{
   p_impl->impl_Enum_Item_4( key );
}

Meta_Enum_Item& Meta_Specification::Enum_Item_5( )
{
   return p_impl->impl_Enum_Item_5( );
}

const Meta_Enum_Item& Meta_Specification::Enum_Item_5( ) const
{
   return p_impl->impl_Enum_Item_5( );
}

void Meta_Specification::Enum_Item_5( const string& key )
{
   p_impl->impl_Enum_Item_5( key );
}

Meta_Field& Meta_Specification::Field( )
{
   return p_impl->impl_Field( );
}

const Meta_Field& Meta_Specification::Field( ) const
{
   return p_impl->impl_Field( );
}

void Meta_Specification::Field( const string& key )
{
   p_impl->impl_Field( key );
}

Meta_Class& Meta_Specification::Field_Class( )
{
   return p_impl->impl_Field_Class( );
}

const Meta_Class& Meta_Specification::Field_Class( ) const
{
   return p_impl->impl_Field_Class( );
}

void Meta_Specification::Field_Class( const string& key )
{
   p_impl->impl_Field_Class( key );
}

Meta_Model& Meta_Specification::Model( )
{
   return p_impl->impl_Model( );
}

const Meta_Model& Meta_Specification::Model( ) const
{
   return p_impl->impl_Model( );
}

void Meta_Specification::Model( const string& key )
{
   p_impl->impl_Model( key );
}

Meta_Modifier& Meta_Specification::Modifier( )
{
   return p_impl->impl_Modifier( );
}

const Meta_Modifier& Meta_Specification::Modifier( ) const
{
   return p_impl->impl_Modifier( );
}

void Meta_Specification::Modifier( const string& key )
{
   p_impl->impl_Modifier( key );
}

Meta_Class& Meta_Specification::Other_Class( )
{
   return p_impl->impl_Other_Class( );
}

const Meta_Class& Meta_Specification::Other_Class( ) const
{
   return p_impl->impl_Other_Class( );
}

void Meta_Specification::Other_Class( const string& key )
{
   p_impl->impl_Other_Class( key );
}

Meta_Field& Meta_Specification::Other_Field( )
{
   return p_impl->impl_Other_Field( );
}

const Meta_Field& Meta_Specification::Other_Field( ) const
{
   return p_impl->impl_Other_Field( );
}

void Meta_Specification::Other_Field( const string& key )
{
   p_impl->impl_Other_Field( key );
}

Meta_Field& Meta_Specification::Other_Field_2( )
{
   return p_impl->impl_Other_Field_2( );
}

const Meta_Field& Meta_Specification::Other_Field_2( ) const
{
   return p_impl->impl_Other_Field_2( );
}

void Meta_Specification::Other_Field_2( const string& key )
{
   p_impl->impl_Other_Field_2( key );
}

Meta_Procedure& Meta_Specification::Other_Procedure( )
{
   return p_impl->impl_Other_Procedure( );
}

const Meta_Procedure& Meta_Specification::Other_Procedure( ) const
{
   return p_impl->impl_Other_Procedure( );
}

void Meta_Specification::Other_Procedure( const string& key )
{
   p_impl->impl_Other_Procedure( key );
}

Meta_Procedure& Meta_Specification::Other_Procedure_2( )
{
   return p_impl->impl_Other_Procedure_2( );
}

const Meta_Procedure& Meta_Specification::Other_Procedure_2( ) const
{
   return p_impl->impl_Other_Procedure_2( );
}

void Meta_Specification::Other_Procedure_2( const string& key )
{
   p_impl->impl_Other_Procedure_2( key );
}

Meta_Specification& Meta_Specification::Parent_Specification( )
{
   return p_impl->impl_Parent_Specification( );
}

const Meta_Specification& Meta_Specification::Parent_Specification( ) const
{
   return p_impl->impl_Parent_Specification( );
}

void Meta_Specification::Parent_Specification( const string& key )
{
   p_impl->impl_Parent_Specification( key );
}

Meta_Specification_Copy_Child_Links& Meta_Specification::Parent_Specification_Copy_Child_Links( )
{
   return p_impl->impl_Parent_Specification_Copy_Child_Links( );
}

const Meta_Specification_Copy_Child_Links& Meta_Specification::Parent_Specification_Copy_Child_Links( ) const
{
   return p_impl->impl_Parent_Specification_Copy_Child_Links( );
}

void Meta_Specification::Parent_Specification_Copy_Child_Links( const string& key )
{
   p_impl->impl_Parent_Specification_Copy_Child_Links( key );
}

Meta_Permission& Meta_Specification::Permission( )
{
   return p_impl->impl_Permission( );
}

const Meta_Permission& Meta_Specification::Permission( ) const
{
   return p_impl->impl_Permission( );
}

void Meta_Specification::Permission( const string& key )
{
   p_impl->impl_Permission( key );
}

Meta_Procedure& Meta_Specification::Procedure( )
{
   return p_impl->impl_Procedure( );
}

const Meta_Procedure& Meta_Specification::Procedure( ) const
{
   return p_impl->impl_Procedure( );
}

void Meta_Specification::Procedure( const string& key )
{
   p_impl->impl_Procedure( key );
}

Meta_Procedure_Arg& Meta_Specification::Procedure_Arg( )
{
   return p_impl->impl_Procedure_Arg( );
}

const Meta_Procedure_Arg& Meta_Specification::Procedure_Arg( ) const
{
   return p_impl->impl_Procedure_Arg( );
}

void Meta_Specification::Procedure_Arg( const string& key )
{
   p_impl->impl_Procedure_Arg( key );
}

Meta_Procedure_Arg& Meta_Specification::Procedure_Arg_2( )
{
   return p_impl->impl_Procedure_Arg_2( );
}

const Meta_Procedure_Arg& Meta_Specification::Procedure_Arg_2( ) const
{
   return p_impl->impl_Procedure_Arg_2( );
}

void Meta_Specification::Procedure_Arg_2( const string& key )
{
   p_impl->impl_Procedure_Arg_2( key );
}

Meta_Procedure_Arg& Meta_Specification::Procedure_Arg_3( )
{
   return p_impl->impl_Procedure_Arg_3( );
}

const Meta_Procedure_Arg& Meta_Specification::Procedure_Arg_3( ) const
{
   return p_impl->impl_Procedure_Arg_3( );
}

void Meta_Specification::Procedure_Arg_3( const string& key )
{
   p_impl->impl_Procedure_Arg_3( key );
}

Meta_Field& Meta_Specification::Source_Child( )
{
   return p_impl->impl_Source_Child( );
}

const Meta_Field& Meta_Specification::Source_Child( ) const
{
   return p_impl->impl_Source_Child( );
}

void Meta_Specification::Source_Child( const string& key )
{
   p_impl->impl_Source_Child( key );
}

Meta_Field& Meta_Specification::Source_Child_2( )
{
   return p_impl->impl_Source_Child_2( );
}

const Meta_Field& Meta_Specification::Source_Child_2( ) const
{
   return p_impl->impl_Source_Child_2( );
}

void Meta_Specification::Source_Child_2( const string& key )
{
   p_impl->impl_Source_Child_2( key );
}

Meta_Class& Meta_Specification::Source_Child_Class( )
{
   return p_impl->impl_Source_Child_Class( );
}

const Meta_Class& Meta_Specification::Source_Child_Class( ) const
{
   return p_impl->impl_Source_Child_Class( );
}

void Meta_Specification::Source_Child_Class( const string& key )
{
   p_impl->impl_Source_Child_Class( key );
}

Meta_Class& Meta_Specification::Source_Class( )
{
   return p_impl->impl_Source_Class( );
}

const Meta_Class& Meta_Specification::Source_Class( ) const
{
   return p_impl->impl_Source_Class( );
}

void Meta_Specification::Source_Class( const string& key )
{
   p_impl->impl_Source_Class( key );
}

Meta_Field& Meta_Specification::Source_Field( )
{
   return p_impl->impl_Source_Field( );
}

const Meta_Field& Meta_Specification::Source_Field( ) const
{
   return p_impl->impl_Source_Field( );
}

void Meta_Specification::Source_Field( const string& key )
{
   p_impl->impl_Source_Field( key );
}

Meta_Class& Meta_Specification::Source_Field_Class( )
{
   return p_impl->impl_Source_Field_Class( );
}

const Meta_Class& Meta_Specification::Source_Field_Class( ) const
{
   return p_impl->impl_Source_Field_Class( );
}

void Meta_Specification::Source_Field_Class( const string& key )
{
   p_impl->impl_Source_Field_Class( key );
}

Meta_Field& Meta_Specification::Source_Grandchild( )
{
   return p_impl->impl_Source_Grandchild( );
}

const Meta_Field& Meta_Specification::Source_Grandchild( ) const
{
   return p_impl->impl_Source_Grandchild( );
}

void Meta_Specification::Source_Grandchild( const string& key )
{
   p_impl->impl_Source_Grandchild( key );
}

Meta_Field& Meta_Specification::Source_Parent( )
{
   return p_impl->impl_Source_Parent( );
}

const Meta_Field& Meta_Specification::Source_Parent( ) const
{
   return p_impl->impl_Source_Parent( );
}

void Meta_Specification::Source_Parent( const string& key )
{
   p_impl->impl_Source_Parent( key );
}

Meta_Class& Meta_Specification::Source_Parent_Class( )
{
   return p_impl->impl_Source_Parent_Class( );
}

const Meta_Class& Meta_Specification::Source_Parent_Class( ) const
{
   return p_impl->impl_Source_Parent_Class( );
}

void Meta_Specification::Source_Parent_Class( const string& key )
{
   p_impl->impl_Source_Parent_Class( key );
}

Meta_Specification_Type& Meta_Specification::Specification_Type( )
{
   return p_impl->impl_Specification_Type( );
}

const Meta_Specification_Type& Meta_Specification::Specification_Type( ) const
{
   return p_impl->impl_Specification_Type( );
}

void Meta_Specification::Specification_Type( const string& key )
{
   p_impl->impl_Specification_Type( key );
}

Meta_Field& Meta_Specification::Test_Child( )
{
   return p_impl->impl_Test_Child( );
}

const Meta_Field& Meta_Specification::Test_Child( ) const
{
   return p_impl->impl_Test_Child( );
}

void Meta_Specification::Test_Child( const string& key )
{
   p_impl->impl_Test_Child( key );
}

Meta_Field& Meta_Specification::Test_Field( )
{
   return p_impl->impl_Test_Field( );
}

const Meta_Field& Meta_Specification::Test_Field( ) const
{
   return p_impl->impl_Test_Field( );
}

void Meta_Specification::Test_Field( const string& key )
{
   p_impl->impl_Test_Field( key );
}

Meta_Class& Meta_Specification::Test_Field_Class( )
{
   return p_impl->impl_Test_Field_Class( );
}

const Meta_Class& Meta_Specification::Test_Field_Class( ) const
{
   return p_impl->impl_Test_Field_Class( );
}

void Meta_Specification::Test_Field_Class( const string& key )
{
   p_impl->impl_Test_Field_Class( key );
}

Meta_Field& Meta_Specification::Test_Parent( )
{
   return p_impl->impl_Test_Parent( );
}

const Meta_Field& Meta_Specification::Test_Parent( ) const
{
   return p_impl->impl_Test_Parent( );
}

void Meta_Specification::Test_Parent( const string& key )
{
   p_impl->impl_Test_Parent( key );
}

Meta_Class& Meta_Specification::Test_Parent_Class( )
{
   return p_impl->impl_Test_Parent_Class( );
}

const Meta_Class& Meta_Specification::Test_Parent_Class( ) const
{
   return p_impl->impl_Test_Parent_Class( );
}

void Meta_Specification::Test_Parent_Class( const string& key )
{
   p_impl->impl_Test_Parent_Class( key );
}

Meta_Specification& Meta_Specification::child_Specification_Parent( )
{
   return p_impl->impl_child_Specification_Parent( );
}

const Meta_Specification& Meta_Specification::child_Specification_Parent( ) const
{
   return p_impl->impl_child_Specification_Parent( );
}

Meta_List_Field& Meta_Specification::child_List_Field_Restriction_Spec( )
{
   return p_impl->impl_child_List_Field_Restriction_Spec( );
}

const Meta_List_Field& Meta_Specification::child_List_Field_Restriction_Spec( ) const
{
   return p_impl->impl_child_List_Field_Restriction_Spec( );
}

Meta_View_Field& Meta_Specification::child_View_Field_Restriction_Spec( )
{
   return p_impl->impl_child_View_Field_Restriction_Spec( );
}

const Meta_View_Field& Meta_Specification::child_View_Field_Restriction_Spec( ) const
{
   return p_impl->impl_child_View_Field_Restriction_Spec( );
}

void Meta_Specification::Add_Arg_1(  )
{
   p_impl->impl_Add_Arg_1(  );
}

void Meta_Specification::Add_Arg_2(  )
{
   p_impl->impl_Add_Arg_2(  );
}

void Meta_Specification::Add_Child_Info(  )
{
   p_impl->impl_Add_Child_Info(  );
}

void Meta_Specification::Add_Extra_Info(  )
{
   p_impl->impl_Add_Extra_Info(  );
}

void Meta_Specification::Add_Field(  )
{
   p_impl->impl_Add_Field(  );
}

void Meta_Specification::Add_Field_Pair(  )
{
   p_impl->impl_Add_Field_Pair(  );
}

void Meta_Specification::Add_Grandchild_Info(  )
{
   p_impl->impl_Add_Grandchild_Info(  );
}

void Meta_Specification::Add_Info(  )
{
   p_impl->impl_Add_Info(  );
}

void Meta_Specification::Add_Next(  )
{
   p_impl->impl_Add_Next(  );
}

void Meta_Specification::Add_Opt_Info(  )
{
   p_impl->impl_Add_Opt_Info(  );
}

void Meta_Specification::Add_Other_Info(  )
{
   p_impl->impl_Add_Other_Info(  );
}

void Meta_Specification::Add_Secondary(  )
{
   p_impl->impl_Add_Secondary(  );
}

void Meta_Specification::Add_Source_Info(  )
{
   p_impl->impl_Add_Source_Info(  );
}

void Meta_Specification::Add_Stats_1(  )
{
   p_impl->impl_Add_Stats_1(  );
}

void Meta_Specification::Add_Stats_2(  )
{
   p_impl->impl_Add_Stats_2(  );
}

void Meta_Specification::Add_Stats_Info(  )
{
   p_impl->impl_Add_Stats_Info(  );
}

void Meta_Specification::Generate_All_Strings( string& All_Strings, const string& Parent_Prefix )
{
   p_impl->impl_Generate_All_Strings( All_Strings, Parent_Prefix );
}

void Meta_Specification::Generate_All_Vars( string& All_Vars, const string& Parent_Prefix )
{
   p_impl->impl_Generate_All_Vars( All_Vars, Parent_Prefix );
}

void Meta_Specification::Move_Down( const string& Restrict_Fields, const string& Restrict_Values )
{
   p_impl->impl_Move_Down( Restrict_Fields, Restrict_Values );
}

void Meta_Specification::Move_Up( const string& Restrict_Fields, const string& Restrict_Values )
{
   p_impl->impl_Move_Up( Restrict_Fields, Restrict_Values );
}

string Meta_Specification::get_field_value( int field ) const
{
   return p_impl->get_field_value( field );
}

void Meta_Specification::set_field_value( int field, const string& value )
{
   p_impl->set_field_value( field, value );
}

bool Meta_Specification::is_field_transient( int field ) const
{
   return static_is_field_transient( ( field_id )( field + 1 ) );
}

string Meta_Specification::get_field_name( int field ) const
{
   return static_get_field_name( ( field_id )( field + 1 ) );
}

int Meta_Specification::get_field_num( const string& field ) const
{
   int rc = static_get_field_num( field );

   if( rc < 0 )
      throw runtime_error( "unknown field name/id '" + field + "' in get_field_num( )" );

   return rc;
}

bool Meta_Specification::has_field_changed( const string& field ) const
{
   return class_base::has_field_changed( get_field_num( field ) );
}

uint64_t Meta_Specification::get_state( ) const
{
   uint64_t state = 0;

   state |= p_impl->get_state( );

   return state;
}

const string& Meta_Specification::execute( const string& cmd_and_args )
{
   return p_impl->execute( cmd_and_args );
}

void Meta_Specification::clear( )
{
   p_impl->clear( );
}

void Meta_Specification::validate( unsigned state, bool is_internal )
{
   p_impl->validate( state, is_internal, &validation_errors );
}

void Meta_Specification::after_fetch( )
{
   p_impl->after_fetch( );
}

void Meta_Specification::finalise_fetch( )
{
   p_impl->finalise_fetch( );
}

void Meta_Specification::at_create( )
{
   p_impl->at_create( );
}

void Meta_Specification::to_store( bool is_create, bool is_internal )
{
   p_impl->to_store( is_create, is_internal );
}

void Meta_Specification::for_store( bool is_create, bool is_internal )
{
   p_impl->for_store( is_create, is_internal );
}

void Meta_Specification::after_store( bool is_create, bool is_internal )
{
   p_impl->after_store( is_create, is_internal );
}

bool Meta_Specification::can_destroy( bool is_internal )
{
   return p_impl->can_destroy( is_internal );
}

void Meta_Specification::for_destroy( bool is_internal )
{
   p_impl->for_destroy( is_internal );
}

void Meta_Specification::after_destroy( bool is_internal )
{
   p_impl->after_destroy( is_internal );
}

void Meta_Specification::set_default_values( )
{
   p_impl->set_default_values( );
}

bool Meta_Specification::is_filtered( const set< string >& filters ) const
{
   return p_impl->is_filtered( filters );
}

const char* Meta_Specification::get_field_id(
 const string& name, bool* p_sql_numeric, string* p_type_name ) const
{
   const char* p_id( 0 );

   if( name.empty( ) )
      throw runtime_error( "unexpected empty field name for get_field_id" );
   else if( name == c_field_name_Actions )
   {
      p_id = c_field_id_Actions;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_All_Strings )
   {
      p_id = c_field_id_All_Strings;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_All_Vars )
   {
      p_id = c_field_id_All_Vars;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Child_Rel_Child_Class )
   {
      p_id = c_field_id_Child_Rel_Child_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Child_Rel_Field_Key )
   {
      p_id = c_field_id_Child_Rel_Field_Key;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Child_Relationship )
   {
      p_id = c_field_id_Child_Relationship;

      if( p_type_name )
         *p_type_name = "Meta_Relationship";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Child_Specification_Type )
   {
      p_id = c_field_id_Child_Specification_Type;

      if( p_type_name )
         *p_type_name = "Meta_Specification_Type";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Class )
   {
      p_id = c_field_id_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Comments )
   {
      p_id = c_field_id_Comments;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Enum )
   {
      p_id = c_field_id_Enum;

      if( p_type_name )
         *p_type_name = "Meta_Enum";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Enum_Item )
   {
      p_id = c_field_id_Enum_Item;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Enum_Item_2 )
   {
      p_id = c_field_id_Enum_Item_2;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Enum_Item_3 )
   {
      p_id = c_field_id_Enum_Item_3;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Enum_Item_4 )
   {
      p_id = c_field_id_Enum_Item_4;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Enum_Item_5 )
   {
      p_id = c_field_id_Enum_Item_5;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Field )
   {
      p_id = c_field_id_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Field_Class )
   {
      p_id = c_field_id_Field_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Field_Pairs )
   {
      p_id = c_field_id_Field_Pairs;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Field_Values )
   {
      p_id = c_field_id_Field_Values;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Fields )
   {
      p_id = c_field_id_Fields;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Id )
   {
      p_id = c_field_id_Id;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Is_Required_For_UI_Gen )
   {
      p_id = c_field_id_Is_Required_For_UI_Gen;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( name == c_field_name_Model )
   {
      p_id = c_field_id_Model;

      if( p_type_name )
         *p_type_name = "Meta_Model";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Modifier )
   {
      p_id = c_field_id_Modifier;

      if( p_type_name )
         *p_type_name = "Meta_Modifier";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Name )
   {
      p_id = c_field_id_Name;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Options )
   {
      p_id = c_field_id_Options;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Order )
   {
      p_id = c_field_id_Order;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Other_Class )
   {
      p_id = c_field_id_Other_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Other_Field )
   {
      p_id = c_field_id_Other_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Other_Field_2 )
   {
      p_id = c_field_id_Other_Field_2;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Other_Procedure )
   {
      p_id = c_field_id_Other_Procedure;

      if( p_type_name )
         *p_type_name = "Meta_Procedure";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Other_Procedure_2 )
   {
      p_id = c_field_id_Other_Procedure_2;

      if( p_type_name )
         *p_type_name = "Meta_Procedure";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Parent_Specification )
   {
      p_id = c_field_id_Parent_Specification;

      if( p_type_name )
         *p_type_name = "Meta_Specification";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Parent_Specification_Copy_Child_Links )
   {
      p_id = c_field_id_Parent_Specification_Copy_Child_Links;

      if( p_type_name )
         *p_type_name = "Meta_Specification_Copy_Child_Links";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Permission )
   {
      p_id = c_field_id_Permission;

      if( p_type_name )
         *p_type_name = "Meta_Permission";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Procedure )
   {
      p_id = c_field_id_Procedure;

      if( p_type_name )
         *p_type_name = "Meta_Procedure";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Procedure_Arg )
   {
      p_id = c_field_id_Procedure_Arg;

      if( p_type_name )
         *p_type_name = "Meta_Procedure_Arg";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Procedure_Arg_2 )
   {
      p_id = c_field_id_Procedure_Arg_2;

      if( p_type_name )
         *p_type_name = "Meta_Procedure_Arg";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Procedure_Arg_3 )
   {
      p_id = c_field_id_Procedure_Arg_3;

      if( p_type_name )
         *p_type_name = "Meta_Procedure_Arg";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Protect_Child_Rel )
   {
      p_id = c_field_id_Protect_Child_Rel;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( name == c_field_name_Protect_Procedure )
   {
      p_id = c_field_id_Protect_Procedure;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( name == c_field_name_Protect_Source_Parent )
   {
      p_id = c_field_id_Protect_Source_Parent;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( name == c_field_name_Restrict_Values )
   {
      p_id = c_field_id_Restrict_Values;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Child )
   {
      p_id = c_field_id_Source_Child;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Child_2 )
   {
      p_id = c_field_id_Source_Child_2;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Child_Class )
   {
      p_id = c_field_id_Source_Child_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Class )
   {
      p_id = c_field_id_Source_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Field )
   {
      p_id = c_field_id_Source_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Field_Class )
   {
      p_id = c_field_id_Source_Field_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Grandchild )
   {
      p_id = c_field_id_Source_Grandchild;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Parent )
   {
      p_id = c_field_id_Source_Parent;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Source_Parent_Class )
   {
      p_id = c_field_id_Source_Parent_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Specification_Type )
   {
      p_id = c_field_id_Specification_Type;

      if( p_type_name )
         *p_type_name = "Meta_Specification_Type";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Strings )
   {
      p_id = c_field_id_Strings;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Test_Child )
   {
      p_id = c_field_id_Test_Child;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Test_Field )
   {
      p_id = c_field_id_Test_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Test_Field_Class )
   {
      p_id = c_field_id_Test_Field_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Test_Parent )
   {
      p_id = c_field_id_Test_Parent;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Test_Parent_Class )
   {
      p_id = c_field_id_Test_Parent_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Test_Value )
   {
      p_id = c_field_id_Test_Value;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Use_Source_Parent )
   {
      p_id = c_field_id_Use_Source_Parent;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( name == c_field_name_Use_Test_Parent_Child )
   {
      p_id = c_field_id_Use_Test_Parent_Child;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( name == c_field_name_Value )
   {
      p_id = c_field_id_Value;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Value_Left_Part )
   {
      p_id = c_field_id_Value_Left_Part;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Value_Literal )
   {
      p_id = c_field_id_Value_Literal;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Value_Numeric_String )
   {
      p_id = c_field_id_Value_Numeric_String;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Value_Right_Part )
   {
      p_id = c_field_id_Value_Right_Part;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Value_String )
   {
      p_id = c_field_id_Value_String;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( name == c_field_name_Vars )
   {
      p_id = c_field_id_Vars;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }

   return p_id;
}

const char* Meta_Specification::get_field_name(
 const string& id, bool* p_sql_numeric, string* p_type_name ) const
{
   const char* p_name( 0 );

   if( id.empty( ) )
      throw runtime_error( "unexpected empty field id for get_field_name" );
   else if( id == c_field_id_Actions )
   {
      p_name = c_field_name_Actions;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_All_Strings )
   {
      p_name = c_field_name_All_Strings;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_All_Vars )
   {
      p_name = c_field_name_All_Vars;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Child_Rel_Child_Class )
   {
      p_name = c_field_name_Child_Rel_Child_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Child_Rel_Field_Key )
   {
      p_name = c_field_name_Child_Rel_Field_Key;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Child_Relationship )
   {
      p_name = c_field_name_Child_Relationship;

      if( p_type_name )
         *p_type_name = "Meta_Relationship";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Child_Specification_Type )
   {
      p_name = c_field_name_Child_Specification_Type;

      if( p_type_name )
         *p_type_name = "Meta_Specification_Type";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Class )
   {
      p_name = c_field_name_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Comments )
   {
      p_name = c_field_name_Comments;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Enum )
   {
      p_name = c_field_name_Enum;

      if( p_type_name )
         *p_type_name = "Meta_Enum";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Enum_Item )
   {
      p_name = c_field_name_Enum_Item;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Enum_Item_2 )
   {
      p_name = c_field_name_Enum_Item_2;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Enum_Item_3 )
   {
      p_name = c_field_name_Enum_Item_3;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Enum_Item_4 )
   {
      p_name = c_field_name_Enum_Item_4;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Enum_Item_5 )
   {
      p_name = c_field_name_Enum_Item_5;

      if( p_type_name )
         *p_type_name = "Meta_Enum_Item";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Field )
   {
      p_name = c_field_name_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Field_Class )
   {
      p_name = c_field_name_Field_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Field_Pairs )
   {
      p_name = c_field_name_Field_Pairs;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Field_Values )
   {
      p_name = c_field_name_Field_Values;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Fields )
   {
      p_name = c_field_name_Fields;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Id )
   {
      p_name = c_field_name_Id;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Is_Required_For_UI_Gen )
   {
      p_name = c_field_name_Is_Required_For_UI_Gen;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( id == c_field_id_Model )
   {
      p_name = c_field_name_Model;

      if( p_type_name )
         *p_type_name = "Meta_Model";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Modifier )
   {
      p_name = c_field_name_Modifier;

      if( p_type_name )
         *p_type_name = "Meta_Modifier";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Name )
   {
      p_name = c_field_name_Name;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Options )
   {
      p_name = c_field_name_Options;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Order )
   {
      p_name = c_field_name_Order;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Other_Class )
   {
      p_name = c_field_name_Other_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Other_Field )
   {
      p_name = c_field_name_Other_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Other_Field_2 )
   {
      p_name = c_field_name_Other_Field_2;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Other_Procedure )
   {
      p_name = c_field_name_Other_Procedure;

      if( p_type_name )
         *p_type_name = "Meta_Procedure";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Other_Procedure_2 )
   {
      p_name = c_field_name_Other_Procedure_2;

      if( p_type_name )
         *p_type_name = "Meta_Procedure";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Parent_Specification )
   {
      p_name = c_field_name_Parent_Specification;

      if( p_type_name )
         *p_type_name = "Meta_Specification";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Parent_Specification_Copy_Child_Links )
   {
      p_name = c_field_name_Parent_Specification_Copy_Child_Links;

      if( p_type_name )
         *p_type_name = "Meta_Specification_Copy_Child_Links";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Permission )
   {
      p_name = c_field_name_Permission;

      if( p_type_name )
         *p_type_name = "Meta_Permission";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Procedure )
   {
      p_name = c_field_name_Procedure;

      if( p_type_name )
         *p_type_name = "Meta_Procedure";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Procedure_Arg )
   {
      p_name = c_field_name_Procedure_Arg;

      if( p_type_name )
         *p_type_name = "Meta_Procedure_Arg";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Procedure_Arg_2 )
   {
      p_name = c_field_name_Procedure_Arg_2;

      if( p_type_name )
         *p_type_name = "Meta_Procedure_Arg";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Procedure_Arg_3 )
   {
      p_name = c_field_name_Procedure_Arg_3;

      if( p_type_name )
         *p_type_name = "Meta_Procedure_Arg";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Protect_Child_Rel )
   {
      p_name = c_field_name_Protect_Child_Rel;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( id == c_field_id_Protect_Procedure )
   {
      p_name = c_field_name_Protect_Procedure;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( id == c_field_id_Protect_Source_Parent )
   {
      p_name = c_field_name_Protect_Source_Parent;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( id == c_field_id_Restrict_Values )
   {
      p_name = c_field_name_Restrict_Values;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Child )
   {
      p_name = c_field_name_Source_Child;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Child_2 )
   {
      p_name = c_field_name_Source_Child_2;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Child_Class )
   {
      p_name = c_field_name_Source_Child_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Class )
   {
      p_name = c_field_name_Source_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Field )
   {
      p_name = c_field_name_Source_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Field_Class )
   {
      p_name = c_field_name_Source_Field_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Grandchild )
   {
      p_name = c_field_name_Source_Grandchild;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Parent )
   {
      p_name = c_field_name_Source_Parent;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Source_Parent_Class )
   {
      p_name = c_field_name_Source_Parent_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Specification_Type )
   {
      p_name = c_field_name_Specification_Type;

      if( p_type_name )
         *p_type_name = "Meta_Specification_Type";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Strings )
   {
      p_name = c_field_name_Strings;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Test_Child )
   {
      p_name = c_field_name_Test_Child;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Test_Field )
   {
      p_name = c_field_name_Test_Field;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Test_Field_Class )
   {
      p_name = c_field_name_Test_Field_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Test_Parent )
   {
      p_name = c_field_name_Test_Parent;

      if( p_type_name )
         *p_type_name = "Meta_Field";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Test_Parent_Class )
   {
      p_name = c_field_name_Test_Parent_Class;

      if( p_type_name )
         *p_type_name = "Meta_Class";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Test_Value )
   {
      p_name = c_field_name_Test_Value;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Use_Source_Parent )
   {
      p_name = c_field_name_Use_Source_Parent;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( id == c_field_id_Use_Test_Parent_Child )
   {
      p_name = c_field_name_Use_Test_Parent_Child;

      if( p_type_name )
         *p_type_name = "bool";

      if( p_sql_numeric )
         *p_sql_numeric = true;
   }
   else if( id == c_field_id_Value )
   {
      p_name = c_field_name_Value;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Value_Left_Part )
   {
      p_name = c_field_name_Value_Left_Part;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Value_Literal )
   {
      p_name = c_field_name_Value_Literal;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Value_Numeric_String )
   {
      p_name = c_field_name_Value_Numeric_String;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Value_Right_Part )
   {
      p_name = c_field_name_Value_Right_Part;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Value_String )
   {
      p_name = c_field_name_Value_String;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }
   else if( id == c_field_id_Vars )
   {
      p_name = c_field_name_Vars;

      if( p_type_name )
         *p_type_name = "string";

      if( p_sql_numeric )
         *p_sql_numeric = false;
   }

   return p_name;
}

string Meta_Specification::get_field_display_name( const string& id ) const
{
   string display_name;

   if( id.empty( ) )
      throw runtime_error( "unexpected empty field id for get_field_display_name" );
   else if( id == c_field_id_Actions )
      display_name = get_module_string( c_field_display_name_Actions );
   else if( id == c_field_id_All_Strings )
      display_name = get_module_string( c_field_display_name_All_Strings );
   else if( id == c_field_id_All_Vars )
      display_name = get_module_string( c_field_display_name_All_Vars );
   else if( id == c_field_id_Child_Rel_Child_Class )
      display_name = get_module_string( c_field_display_name_Child_Rel_Child_Class );
   else if( id == c_field_id_Child_Rel_Field_Key )
      display_name = get_module_string( c_field_display_name_Child_Rel_Field_Key );
   else if( id == c_field_id_Child_Relationship )
      display_name = get_module_string( c_field_display_name_Child_Relationship );
   else if( id == c_field_id_Child_Specification_Type )
      display_name = get_module_string( c_field_display_name_Child_Specification_Type );
   else if( id == c_field_id_Class )
      display_name = get_module_string( c_field_display_name_Class );
   else if( id == c_field_id_Comments )
      display_name = get_module_string( c_field_display_name_Comments );
   else if( id == c_field_id_Enum )
      display_name = get_module_string( c_field_display_name_Enum );
   else if( id == c_field_id_Enum_Item )
      display_name = get_module_string( c_field_display_name_Enum_Item );
   else if( id == c_field_id_Enum_Item_2 )
      display_name = get_module_string( c_field_display_name_Enum_Item_2 );
   else if( id == c_field_id_Enum_Item_3 )
      display_name = get_module_string( c_field_display_name_Enum_Item_3 );
   else if( id == c_field_id_Enum_Item_4 )
      display_name = get_module_string( c_field_display_name_Enum_Item_4 );
   else if( id == c_field_id_Enum_Item_5 )
      display_name = get_module_string( c_field_display_name_Enum_Item_5 );
   else if( id == c_field_id_Field )
      display_name = get_module_string( c_field_display_name_Field );
   else if( id == c_field_id_Field_Class )
      display_name = get_module_string( c_field_display_name_Field_Class );
   else if( id == c_field_id_Field_Pairs )
      display_name = get_module_string( c_field_display_name_Field_Pairs );
   else if( id == c_field_id_Field_Values )
      display_name = get_module_string( c_field_display_name_Field_Values );
   else if( id == c_field_id_Fields )
      display_name = get_module_string( c_field_display_name_Fields );
   else if( id == c_field_id_Id )
      display_name = get_module_string( c_field_display_name_Id );
   else if( id == c_field_id_Is_Required_For_UI_Gen )
      display_name = get_module_string( c_field_display_name_Is_Required_For_UI_Gen );
   else if( id == c_field_id_Model )
      display_name = get_module_string( c_field_display_name_Model );
   else if( id == c_field_id_Modifier )
      display_name = get_module_string( c_field_display_name_Modifier );
   else if( id == c_field_id_Name )
      display_name = get_module_string( c_field_display_name_Name );
   else if( id == c_field_id_Options )
      display_name = get_module_string( c_field_display_name_Options );
   else if( id == c_field_id_Order )
      display_name = get_module_string( c_field_display_name_Order );
   else if( id == c_field_id_Other_Class )
      display_name = get_module_string( c_field_display_name_Other_Class );
   else if( id == c_field_id_Other_Field )
      display_name = get_module_string( c_field_display_name_Other_Field );
   else if( id == c_field_id_Other_Field_2 )
      display_name = get_module_string( c_field_display_name_Other_Field_2 );
   else if( id == c_field_id_Other_Procedure )
      display_name = get_module_string( c_field_display_name_Other_Procedure );
   else if( id == c_field_id_Other_Procedure_2 )
      display_name = get_module_string( c_field_display_name_Other_Procedure_2 );
   else if( id == c_field_id_Parent_Specification )
      display_name = get_module_string( c_field_display_name_Parent_Specification );
   else if( id == c_field_id_Parent_Specification_Copy_Child_Links )
      display_name = get_module_string( c_field_display_name_Parent_Specification_Copy_Child_Links );
   else if( id == c_field_id_Permission )
      display_name = get_module_string( c_field_display_name_Permission );
   else if( id == c_field_id_Procedure )
      display_name = get_module_string( c_field_display_name_Procedure );
   else if( id == c_field_id_Procedure_Arg )
      display_name = get_module_string( c_field_display_name_Procedure_Arg );
   else if( id == c_field_id_Procedure_Arg_2 )
      display_name = get_module_string( c_field_display_name_Procedure_Arg_2 );
   else if( id == c_field_id_Procedure_Arg_3 )
      display_name = get_module_string( c_field_display_name_Procedure_Arg_3 );
   else if( id == c_field_id_Protect_Child_Rel )
      display_name = get_module_string( c_field_display_name_Protect_Child_Rel );
   else if( id == c_field_id_Protect_Procedure )
      display_name = get_module_string( c_field_display_name_Protect_Procedure );
   else if( id == c_field_id_Protect_Source_Parent )
      display_name = get_module_string( c_field_display_name_Protect_Source_Parent );
   else if( id == c_field_id_Restrict_Values )
      display_name = get_module_string( c_field_display_name_Restrict_Values );
   else if( id == c_field_id_Source_Child )
      display_name = get_module_string( c_field_display_name_Source_Child );
   else if( id == c_field_id_Source_Child_2 )
      display_name = get_module_string( c_field_display_name_Source_Child_2 );
   else if( id == c_field_id_Source_Child_Class )
      display_name = get_module_string( c_field_display_name_Source_Child_Class );
   else if( id == c_field_id_Source_Class )
      display_name = get_module_string( c_field_display_name_Source_Class );
   else if( id == c_field_id_Source_Field )
      display_name = get_module_string( c_field_display_name_Source_Field );
   else if( id == c_field_id_Source_Field_Class )
      display_name = get_module_string( c_field_display_name_Source_Field_Class );
   else if( id == c_field_id_Source_Grandchild )
      display_name = get_module_string( c_field_display_name_Source_Grandchild );
   else if( id == c_field_id_Source_Parent )
      display_name = get_module_string( c_field_display_name_Source_Parent );
   else if( id == c_field_id_Source_Parent_Class )
      display_name = get_module_string( c_field_display_name_Source_Parent_Class );
   else if( id == c_field_id_Specification_Type )
      display_name = get_module_string( c_field_display_name_Specification_Type );
   else if( id == c_field_id_Strings )
      display_name = get_module_string( c_field_display_name_Strings );
   else if( id == c_field_id_Test_Child )
      display_name = get_module_string( c_field_display_name_Test_Child );
   else if( id == c_field_id_Test_Field )
      display_name = get_module_string( c_field_display_name_Test_Field );
   else if( id == c_field_id_Test_Field_Class )
      display_name = get_module_string( c_field_display_name_Test_Field_Class );
   else if( id == c_field_id_Test_Parent )
      display_name = get_module_string( c_field_display_name_Test_Parent );
   else if( id == c_field_id_Test_Parent_Class )
      display_name = get_module_string( c_field_display_name_Test_Parent_Class );
   else if( id == c_field_id_Test_Value )
      display_name = get_module_string( c_field_display_name_Test_Value );
   else if( id == c_field_id_Use_Source_Parent )
      display_name = get_module_string( c_field_display_name_Use_Source_Parent );
   else if( id == c_field_id_Use_Test_Parent_Child )
      display_name = get_module_string( c_field_display_name_Use_Test_Parent_Child );
   else if( id == c_field_id_Value )
      display_name = get_module_string( c_field_display_name_Value );
   else if( id == c_field_id_Value_Left_Part )
      display_name = get_module_string( c_field_display_name_Value_Left_Part );
   else if( id == c_field_id_Value_Literal )
      display_name = get_module_string( c_field_display_name_Value_Literal );
   else if( id == c_field_id_Value_Numeric_String )
      display_name = get_module_string( c_field_display_name_Value_Numeric_String );
   else if( id == c_field_id_Value_Right_Part )
      display_name = get_module_string( c_field_display_name_Value_Right_Part );
   else if( id == c_field_id_Value_String )
      display_name = get_module_string( c_field_display_name_Value_String );
   else if( id == c_field_id_Vars )
      display_name = get_module_string( c_field_display_name_Vars );

   return display_name;
}

void Meta_Specification::clear_foreign_key( const string& field )
{
   p_impl->clear_foreign_key( field );
}

void Meta_Specification::set_foreign_key_value( const string& field, const string& value )
{
   p_impl->set_foreign_key_value( field, value );
}

const string& Meta_Specification::get_foreign_key_value( const string& field )
{
   return p_impl->get_foreign_key_value( field );
}

void Meta_Specification::get_foreign_key_values( foreign_key_data_container& foreign_key_values ) const
{
   p_impl->get_foreign_key_values( foreign_key_values );
}

void Meta_Specification::setup_foreign_key( Meta_Class& o, const string& value )
{
   static_cast< Meta_Class& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Relationship& o, const string& value )
{
   static_cast< Meta_Relationship& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Specification_Type& o, const string& value )
{
   static_cast< Meta_Specification_Type& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Enum& o, const string& value )
{
   static_cast< Meta_Enum& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Enum_Item& o, const string& value )
{
   static_cast< Meta_Enum_Item& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Field& o, const string& value )
{
   static_cast< Meta_Field& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Model& o, const string& value )
{
   static_cast< Meta_Model& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Modifier& o, const string& value )
{
   static_cast< Meta_Modifier& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Procedure& o, const string& value )
{
   static_cast< Meta_Procedure& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Specification& o, const string& value )
{
   static_cast< Meta_Specification& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Specification_Copy_Child_Links& o, const string& value )
{
   static_cast< Meta_Specification_Copy_Child_Links& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Permission& o, const string& value )
{
   static_cast< Meta_Permission& >( o ).set_key( value );
}

void Meta_Specification::setup_foreign_key( Meta_Procedure_Arg& o, const string& value )
{
   static_cast< Meta_Procedure_Arg& >( o ).set_key( value );
}

void Meta_Specification::setup_graph_parent( Meta_Specification& o, const string& foreign_key_field )
{
   static_cast< Meta_Specification& >( o ).set_graph_parent( this, foreign_key_field );
}

void Meta_Specification::setup_graph_parent( Meta_List_Field& o, const string& foreign_key_field )
{
   static_cast< Meta_List_Field& >( o ).set_graph_parent( this, foreign_key_field );
}

void Meta_Specification::setup_graph_parent( Meta_View_Field& o, const string& foreign_key_field )
{
   static_cast< Meta_View_Field& >( o ).set_graph_parent( this, foreign_key_field );
}

void Meta_Specification::setup_graph_parent(
 Meta_Class& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Class& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Class& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Relationship& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Relationship& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Relationship& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Specification_Type& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Specification_Type& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Specification_Type& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Enum& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Enum& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Enum& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Enum_Item& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Enum_Item& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Enum_Item& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Field& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Field& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Field& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Model& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Model& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Model& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Modifier& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Modifier& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Modifier& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Procedure& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Procedure& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Procedure& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Specification& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Specification& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Specification& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Specification_Copy_Child_Links& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Specification_Copy_Child_Links& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Specification_Copy_Child_Links& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Permission& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Permission& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Permission& >( o ).set_key( init_value );
}

void Meta_Specification::setup_graph_parent(
 Meta_Procedure_Arg& o, const string& foreign_key_field, const string& init_value )
{
   static_cast< Meta_Procedure_Arg& >( o ).set_graph_parent( this, foreign_key_field, true );
   static_cast< Meta_Procedure_Arg& >( o ).set_key( init_value );
}

size_t Meta_Specification::get_total_child_relationships( ) const
{
   return p_impl->total_child_relationships;
}

void Meta_Specification::set_total_child_relationships( size_t new_total_child_relationships ) const
{
   p_impl->total_child_relationships = new_total_child_relationships;
}

size_t Meta_Specification::get_num_foreign_key_children( bool is_internal ) const
{
   size_t rc = 3;

   if( !is_internal )
   {
      g_external_aliases_lookup.clear( );

      for( external_aliases_const_iterator
       eaci = g_external_aliases.begin( ), end = g_external_aliases.end( ); eaci != end; ++eaci )
      {
         size_t num_extra = eaci->second->get_num_foreign_key_children( true );

         if( num_extra )
         {
            eaci->second->set_key( get_key( ) );
            eaci->second->copy_all_field_values( *this );

            g_external_aliases_lookup.insert( make_pair( rc, eaci->second ) );

            rc += num_extra;
         }
      }
   }

   set_total_child_relationships( rc );

   return rc;
}

class_base* Meta_Specification::get_next_foreign_key_child(
 size_t child_num, string& next_child_field, cascade_op op, bool is_internal )
{
   class_base* p_class_base = 0;

   if( child_num >= 3 )
   {
      external_aliases_lookup_const_iterator ealci = g_external_aliases_lookup.lower_bound( child_num );
      if( ealci == g_external_aliases_lookup.end( ) || ealci->first > child_num )
         --ealci;

      p_class_base = ealci->second->get_next_foreign_key_child( child_num - ealci->first, next_child_field, op, true );
   }
   else
   {
      switch( child_num )
      {
         case 0:
         if( op == e_cascade_op_destroy )
         {
            next_child_field = "301405";
            p_class_base = &child_Specification_Parent( );
         }
         break;

         case 1:
         if( op == e_cascade_op_restrict )
         {
            next_child_field = "302180";
            p_class_base = &child_List_Field_Restriction_Spec( );
         }
         break;

         case 2:
         if( op == e_cascade_op_restrict )
         {
            next_child_field = "301980";
            p_class_base = &child_View_Field_Restriction_Spec( );
         }
         break;
      }
   }

   return p_class_base;
}

const char* Meta_Specification::class_id( ) const
{
   return static_class_id( );
}

const char* Meta_Specification::class_name( ) const
{
   return static_class_name( );
}

const char* Meta_Specification::plural_name( ) const
{
   return static_plural_name( );
}

const char* Meta_Specification::module_id( ) const
{
   return static_module_id( );
}

const char* Meta_Specification::module_name( ) const
{
   return static_module_name( );
}

string Meta_Specification::get_display_name( bool plural ) const
{
   string key( plural ? "plural_" : "class_" );
   key += "specification";

   return get_module_string( key );
}

bool Meta_Specification::get_is_alias( ) const
{
   return false;
}

void Meta_Specification::get_alias_base_info( pair< string, string >& alias_base_info ) const
{
   ( void )alias_base_info;
}

void Meta_Specification::get_base_class_info( vector< pair< string, string > >& base_class_info ) const
{
   ( void )base_class_info;
}

class_base& Meta_Specification::get_or_create_graph_child( const string& context )
{
   class_base* p_class_base( 0 );

   string::size_type pos = context.find( '.' );
   string sub_context( context.substr( 0, pos ) );

   if( sub_context.empty( ) )
      throw runtime_error( "unexpected empty sub-context" );
   else if( sub_context == "_301405" || sub_context == "child_Specification_Parent" )
      p_class_base = &child_Specification_Parent( );
   else if( sub_context == "_302180" || sub_context == "child_List_Field_Restriction_Spec" )
      p_class_base = &child_List_Field_Restriction_Spec( );
   else if( sub_context == "_301980" || sub_context == "child_View_Field_Restriction_Spec" )
      p_class_base = &child_View_Field_Restriction_Spec( );
   else if( sub_context == c_field_id_Child_Rel_Child_Class || sub_context == c_field_name_Child_Rel_Child_Class )
      p_class_base = &Child_Rel_Child_Class( );
   else if( sub_context == c_field_id_Child_Relationship || sub_context == c_field_name_Child_Relationship )
      p_class_base = &Child_Relationship( );
   else if( sub_context == c_field_id_Child_Specification_Type || sub_context == c_field_name_Child_Specification_Type )
      p_class_base = &Child_Specification_Type( );
   else if( sub_context == c_field_id_Class || sub_context == c_field_name_Class )
      p_class_base = &Class( );
   else if( sub_context == c_field_id_Enum || sub_context == c_field_name_Enum )
      p_class_base = &Enum( );
   else if( sub_context == c_field_id_Enum_Item || sub_context == c_field_name_Enum_Item )
      p_class_base = &Enum_Item( );
   else if( sub_context == c_field_id_Enum_Item_2 || sub_context == c_field_name_Enum_Item_2 )
      p_class_base = &Enum_Item_2( );
   else if( sub_context == c_field_id_Enum_Item_3 || sub_context == c_field_name_Enum_Item_3 )
      p_class_base = &Enum_Item_3( );
   else if( sub_context == c_field_id_Enum_Item_4 || sub_context == c_field_name_Enum_Item_4 )
      p_class_base = &Enum_Item_4( );
   else if( sub_context == c_field_id_Enum_Item_5 || sub_context == c_field_name_Enum_Item_5 )
      p_class_base = &Enum_Item_5( );
   else if( sub_context == c_field_id_Field || sub_context == c_field_name_Field )
      p_class_base = &Field( );
   else if( sub_context == c_field_id_Field_Class || sub_context == c_field_name_Field_Class )
      p_class_base = &Field_Class( );
   else if( sub_context == c_field_id_Model || sub_context == c_field_name_Model )
      p_class_base = &Model( );
   else if( sub_context == c_field_id_Modifier || sub_context == c_field_name_Modifier )
      p_class_base = &Modifier( );
   else if( sub_context == c_field_id_Other_Class || sub_context == c_field_name_Other_Class )
      p_class_base = &Other_Class( );
   else if( sub_context == c_field_id_Other_Field || sub_context == c_field_name_Other_Field )
      p_class_base = &Other_Field( );
   else if( sub_context == c_field_id_Other_Field_2 || sub_context == c_field_name_Other_Field_2 )
      p_class_base = &Other_Field_2( );
   else if( sub_context == c_field_id_Other_Procedure || sub_context == c_field_name_Other_Procedure )
      p_class_base = &Other_Procedure( );
   else if( sub_context == c_field_id_Other_Procedure_2 || sub_context == c_field_name_Other_Procedure_2 )
      p_class_base = &Other_Procedure_2( );
   else if( sub_context == c_field_id_Parent_Specification || sub_context == c_field_name_Parent_Specification )
      p_class_base = &Parent_Specification( );
   else if( sub_context == c_field_id_Parent_Specification_Copy_Child_Links || sub_context == c_field_name_Parent_Specification_Copy_Child_Links )
      p_class_base = &Parent_Specification_Copy_Child_Links( );
   else if( sub_context == c_field_id_Permission || sub_context == c_field_name_Permission )
      p_class_base = &Permission( );
   else if( sub_context == c_field_id_Procedure || sub_context == c_field_name_Procedure )
      p_class_base = &Procedure( );
   else if( sub_context == c_field_id_Procedure_Arg || sub_context == c_field_name_Procedure_Arg )
      p_class_base = &Procedure_Arg( );
   else if( sub_context == c_field_id_Procedure_Arg_2 || sub_context == c_field_name_Procedure_Arg_2 )
      p_class_base = &Procedure_Arg_2( );
   else if( sub_context == c_field_id_Procedure_Arg_3 || sub_context == c_field_name_Procedure_Arg_3 )
      p_class_base = &Procedure_Arg_3( );
   else if( sub_context == c_field_id_Source_Child || sub_context == c_field_name_Source_Child )
      p_class_base = &Source_Child( );
   else if( sub_context == c_field_id_Source_Child_2 || sub_context == c_field_name_Source_Child_2 )
      p_class_base = &Source_Child_2( );
   else if( sub_context == c_field_id_Source_Child_Class || sub_context == c_field_name_Source_Child_Class )
      p_class_base = &Source_Child_Class( );
   else if( sub_context == c_field_id_Source_Class || sub_context == c_field_name_Source_Class )
      p_class_base = &Source_Class( );
   else if( sub_context == c_field_id_Source_Field || sub_context == c_field_name_Source_Field )
      p_class_base = &Source_Field( );
   else if( sub_context == c_field_id_Source_Field_Class || sub_context == c_field_name_Source_Field_Class )
      p_class_base = &Source_Field_Class( );
   else if( sub_context == c_field_id_Source_Grandchild || sub_context == c_field_name_Source_Grandchild )
      p_class_base = &Source_Grandchild( );
   else if( sub_context == c_field_id_Source_Parent || sub_context == c_field_name_Source_Parent )
      p_class_base = &Source_Parent( );
   else if( sub_context == c_field_id_Source_Parent_Class || sub_context == c_field_name_Source_Parent_Class )
      p_class_base = &Source_Parent_Class( );
   else if( sub_context == c_field_id_Specification_Type || sub_context == c_field_name_Specification_Type )
      p_class_base = &Specification_Type( );
   else if( sub_context == c_field_id_Test_Child || sub_context == c_field_name_Test_Child )
      p_class_base = &Test_Child( );
   else if( sub_context == c_field_id_Test_Field || sub_context == c_field_name_Test_Field )
      p_class_base = &Test_Field( );
   else if( sub_context == c_field_id_Test_Field_Class || sub_context == c_field_name_Test_Field_Class )
      p_class_base = &Test_Field_Class( );
   else if( sub_context == c_field_id_Test_Parent || sub_context == c_field_name_Test_Parent )
      p_class_base = &Test_Parent( );
   else if( sub_context == c_field_id_Test_Parent_Class || sub_context == c_field_name_Test_Parent_Class )
      p_class_base = &Test_Parent_Class( );

   if( !p_class_base )
      throw runtime_error( "unknown sub-context '" + sub_context + "'" );

   if( pos != string::npos )
      p_class_base = &p_class_base->get_or_create_graph_child( context.substr( pos + 1 ) );

   return *p_class_base;
}

void Meta_Specification::get_sql_column_names(
 vector< string >& names, bool* p_done, const string* p_class_name ) const
{
   if( p_done && *p_done )
      return;

   names.push_back( "C_Actions" );
   names.push_back( "C_Child_Rel_Child_Class" );
   names.push_back( "C_Child_Rel_Field_Key" );
   names.push_back( "C_Child_Relationship" );
   names.push_back( "C_Child_Specification_Type" );
   names.push_back( "C_Class" );
   names.push_back( "C_Comments" );
   names.push_back( "C_Enum" );
   names.push_back( "C_Enum_Item" );
   names.push_back( "C_Enum_Item_2" );
   names.push_back( "C_Enum_Item_3" );
   names.push_back( "C_Enum_Item_4" );
   names.push_back( "C_Enum_Item_5" );
   names.push_back( "C_Field" );
   names.push_back( "C_Field_Class" );
   names.push_back( "C_Field_Pairs" );
   names.push_back( "C_Field_Values" );
   names.push_back( "C_Fields" );
   names.push_back( "C_Id" );
   names.push_back( "C_Is_Required_For_UI_Gen" );
   names.push_back( "C_Model" );
   names.push_back( "C_Modifier" );
   names.push_back( "C_Name" );
   names.push_back( "C_Options" );
   names.push_back( "C_Order" );
   names.push_back( "C_Other_Class" );
   names.push_back( "C_Other_Field" );
   names.push_back( "C_Other_Field_2" );
   names.push_back( "C_Other_Procedure" );
   names.push_back( "C_Other_Procedure_2" );
   names.push_back( "C_Parent_Specification" );
   names.push_back( "C_Parent_Specification_Copy_Child_Links" );
   names.push_back( "C_Permission" );
   names.push_back( "C_Procedure" );
   names.push_back( "C_Procedure_Arg" );
   names.push_back( "C_Procedure_Arg_2" );
   names.push_back( "C_Procedure_Arg_3" );
   names.push_back( "C_Protect_Child_Rel" );
   names.push_back( "C_Protect_Procedure" );
   names.push_back( "C_Protect_Source_Parent" );
   names.push_back( "C_Restrict_Values" );
   names.push_back( "C_Source_Child" );
   names.push_back( "C_Source_Child_2" );
   names.push_back( "C_Source_Child_Class" );
   names.push_back( "C_Source_Class" );
   names.push_back( "C_Source_Field" );
   names.push_back( "C_Source_Field_Class" );
   names.push_back( "C_Source_Grandchild" );
   names.push_back( "C_Source_Parent" );
   names.push_back( "C_Source_Parent_Class" );
   names.push_back( "C_Specification_Type" );
   names.push_back( "C_Test_Child" );
   names.push_back( "C_Test_Field" );
   names.push_back( "C_Test_Field_Class" );
   names.push_back( "C_Test_Parent" );
   names.push_back( "C_Test_Parent_Class" );
   names.push_back( "C_Test_Value" );
   names.push_back( "C_Use_Source_Parent" );
   names.push_back( "C_Use_Test_Parent_Child" );
   names.push_back( "C_Value" );
   names.push_back( "C_Value_Left_Part" );
   names.push_back( "C_Value_Literal" );
   names.push_back( "C_Value_Numeric_String" );
   names.push_back( "C_Value_Right_Part" );
   names.push_back( "C_Value_String" );

   if( p_done && p_class_name && *p_class_name == static_class_name( ) )
      *p_done = true;
}

void Meta_Specification::get_sql_column_values(
 vector< string >& values, bool* p_done, const string* p_class_name ) const
{
   if( p_done && *p_done )
      return;

   values.push_back( sql_quote( to_string( Actions( ) ) ) );
   values.push_back( sql_quote( to_string( Child_Rel_Child_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Child_Rel_Field_Key( ) ) ) );
   values.push_back( sql_quote( to_string( Child_Relationship( ) ) ) );
   values.push_back( sql_quote( to_string( Child_Specification_Type( ) ) ) );
   values.push_back( sql_quote( to_string( Class( ) ) ) );
   values.push_back( sql_quote( to_string( Comments( ) ) ) );
   values.push_back( sql_quote( to_string( Enum( ) ) ) );
   values.push_back( sql_quote( to_string( Enum_Item( ) ) ) );
   values.push_back( sql_quote( to_string( Enum_Item_2( ) ) ) );
   values.push_back( sql_quote( to_string( Enum_Item_3( ) ) ) );
   values.push_back( sql_quote( to_string( Enum_Item_4( ) ) ) );
   values.push_back( sql_quote( to_string( Enum_Item_5( ) ) ) );
   values.push_back( sql_quote( to_string( Field( ) ) ) );
   values.push_back( sql_quote( to_string( Field_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Field_Pairs( ) ) ) );
   values.push_back( sql_quote( to_string( Field_Values( ) ) ) );
   values.push_back( sql_quote( to_string( Fields( ) ) ) );
   values.push_back( sql_quote( to_string( Id( ) ) ) );
   values.push_back( to_string( Is_Required_For_UI_Gen( ) ) );
   values.push_back( sql_quote( to_string( Model( ) ) ) );
   values.push_back( sql_quote( to_string( Modifier( ) ) ) );
   values.push_back( sql_quote( to_string( Name( ) ) ) );
   values.push_back( sql_quote( to_string( Options( ) ) ) );
   values.push_back( sql_quote( to_string( Order( ) ) ) );
   values.push_back( sql_quote( to_string( Other_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Other_Field( ) ) ) );
   values.push_back( sql_quote( to_string( Other_Field_2( ) ) ) );
   values.push_back( sql_quote( to_string( Other_Procedure( ) ) ) );
   values.push_back( sql_quote( to_string( Other_Procedure_2( ) ) ) );
   values.push_back( sql_quote( to_string( Parent_Specification( ) ) ) );
   values.push_back( sql_quote( to_string( Parent_Specification_Copy_Child_Links( ) ) ) );
   values.push_back( sql_quote( to_string( Permission( ) ) ) );
   values.push_back( sql_quote( to_string( Procedure( ) ) ) );
   values.push_back( sql_quote( to_string( Procedure_Arg( ) ) ) );
   values.push_back( sql_quote( to_string( Procedure_Arg_2( ) ) ) );
   values.push_back( sql_quote( to_string( Procedure_Arg_3( ) ) ) );
   values.push_back( to_string( Protect_Child_Rel( ) ) );
   values.push_back( to_string( Protect_Procedure( ) ) );
   values.push_back( to_string( Protect_Source_Parent( ) ) );
   values.push_back( sql_quote( to_string( Restrict_Values( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Child( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Child_2( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Child_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Field( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Field_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Grandchild( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Parent( ) ) ) );
   values.push_back( sql_quote( to_string( Source_Parent_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Specification_Type( ) ) ) );
   values.push_back( sql_quote( to_string( Test_Child( ) ) ) );
   values.push_back( sql_quote( to_string( Test_Field( ) ) ) );
   values.push_back( sql_quote( to_string( Test_Field_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Test_Parent( ) ) ) );
   values.push_back( sql_quote( to_string( Test_Parent_Class( ) ) ) );
   values.push_back( sql_quote( to_string( Test_Value( ) ) ) );
   values.push_back( to_string( Use_Source_Parent( ) ) );
   values.push_back( to_string( Use_Test_Parent_Child( ) ) );
   values.push_back( sql_quote( to_string( Value( ) ) ) );
   values.push_back( sql_quote( to_string( Value_Left_Part( ) ) ) );
   values.push_back( sql_quote( to_string( Value_Literal( ) ) ) );
   values.push_back( sql_quote( to_string( Value_Numeric_String( ) ) ) );
   values.push_back( sql_quote( to_string( Value_Right_Part( ) ) ) );
   values.push_back( sql_quote( to_string( Value_String( ) ) ) );

   if( p_done && p_class_name && *p_class_name == static_class_name( ) )
      *p_done = true;
}

void Meta_Specification::get_required_field_names(
 set< string >& names, bool required_transients, set< string >* p_dependents ) const
{
   set< string > local_dependents;
   set< string >& dependents( p_dependents ? *p_dependents : local_dependents );

   get_always_required_field_names( names, required_transients, dependents );

   // [(start field_dependency)]
   if( needs_field_value( "All_Vars", dependents ) )
   {
      dependents.insert( "Vars" );

      if( ( required_transients && is_field_transient( e_field_id_Vars ) )
       || ( !required_transients && !is_field_transient( e_field_id_Vars ) ) )
         names.insert( "Vars" );
   }
   // [(finish field_dependency)]

   // [(start field_dependency)]
   if( needs_field_value( "All_Strings", dependents ) )
   {
      dependents.insert( "Strings" );

      if( ( required_transients && is_field_transient( e_field_id_Strings ) )
       || ( !required_transients && !is_field_transient( e_field_id_Strings ) ) )
         names.insert( "Strings" );
   }
   // [(finish field_dependency)]

   // [(start field_from_search_replace)]
   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Model" );

      if( ( required_transients && is_field_transient( e_field_id_Model ) )
       || ( !required_transients && !is_field_transient( e_field_id_Model ) ) )
         names.insert( "Model" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Model" );

      if( ( required_transients && is_field_transient( e_field_id_Model ) )
       || ( !required_transients && !is_field_transient( e_field_id_Model ) ) )
         names.insert( "Model" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Class" );

      if( ( required_transients && is_field_transient( e_field_id_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Class ) ) )
         names.insert( "Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Class" );

      if( ( required_transients && is_field_transient( e_field_id_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Class ) ) )
         names.insert( "Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Class ) ) )
         names.insert( "Other_Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Class ) ) )
         names.insert( "Other_Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Field_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field_Class ) ) )
         names.insert( "Field_Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Field ) ) )
         names.insert( "Other_Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Field ) ) )
         names.insert( "Other_Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Field_2" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Field_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Field_2 ) ) )
         names.insert( "Other_Field_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Field_2" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Field_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Field_2 ) ) )
         names.insert( "Other_Field_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Modifier" );

      if( ( required_transients && is_field_transient( e_field_id_Modifier ) )
       || ( !required_transients && !is_field_transient( e_field_id_Modifier ) ) )
         names.insert( "Modifier" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Parent_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Parent_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Parent_Class ) ) )
         names.insert( "Source_Parent_Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Parent" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Parent ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Parent ) ) )
         names.insert( "Source_Parent" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Parent" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Parent ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Parent ) ) )
         names.insert( "Source_Parent" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Child_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child_Class ) ) )
         names.insert( "Source_Child_Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Child" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child ) ) )
         names.insert( "Source_Child" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Child" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child ) ) )
         names.insert( "Source_Child" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Child_2" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child_2 ) ) )
         names.insert( "Source_Child_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Child_2" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child_2 ) ) )
         names.insert( "Source_Child_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Field ) ) )
         names.insert( "Source_Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Field ) ) )
         names.insert( "Source_Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Source_Grandchild" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Grandchild ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Grandchild ) ) )
         names.insert( "Source_Grandchild" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Test_Parent" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Parent ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Parent ) ) )
         names.insert( "Test_Parent" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Test_Child" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Child ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Child ) ) )
         names.insert( "Test_Child" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Test_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Field ) ) )
         names.insert( "Test_Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Test_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Field ) ) )
         names.insert( "Test_Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Test_Field_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Field_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Field_Class ) ) )
         names.insert( "Test_Field_Class" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Test_Value" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Value ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Value ) ) )
         names.insert( "Test_Value" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Permission" );

      if( ( required_transients && is_field_transient( e_field_id_Permission ) )
       || ( !required_transients && !is_field_transient( e_field_id_Permission ) ) )
         names.insert( "Permission" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Procedure" );

      if( ( required_transients && is_field_transient( e_field_id_Procedure ) )
       || ( !required_transients && !is_field_transient( e_field_id_Procedure ) ) )
         names.insert( "Procedure" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Procedure" );

      if( ( required_transients && is_field_transient( e_field_id_Procedure ) )
       || ( !required_transients && !is_field_transient( e_field_id_Procedure ) ) )
         names.insert( "Procedure" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Procedure_Arg" );

      if( ( required_transients && is_field_transient( e_field_id_Procedure_Arg ) )
       || ( !required_transients && !is_field_transient( e_field_id_Procedure_Arg ) ) )
         names.insert( "Procedure_Arg" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Procedure_Arg_2" );

      if( ( required_transients && is_field_transient( e_field_id_Procedure_Arg_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Procedure_Arg_2 ) ) )
         names.insert( "Procedure_Arg_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Procedure_Arg_3" );

      if( ( required_transients && is_field_transient( e_field_id_Procedure_Arg_3 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Procedure_Arg_3 ) ) )
         names.insert( "Procedure_Arg_3" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Procedure" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Procedure ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Procedure ) ) )
         names.insert( "Other_Procedure" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Procedure" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Procedure ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Procedure ) ) )
         names.insert( "Other_Procedure" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Procedure_2" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Procedure_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Procedure_2 ) ) )
         names.insert( "Other_Procedure_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Other_Procedure_2" );

      if( ( required_transients && is_field_transient( e_field_id_Other_Procedure_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Other_Procedure_2 ) ) )
         names.insert( "Other_Procedure_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Child_Relationship" );

      if( ( required_transients && is_field_transient( e_field_id_Child_Relationship ) )
       || ( !required_transients && !is_field_transient( e_field_id_Child_Relationship ) ) )
         names.insert( "Child_Relationship" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Child_Relationship" );

      if( ( required_transients && is_field_transient( e_field_id_Child_Relationship ) )
       || ( !required_transients && !is_field_transient( e_field_id_Child_Relationship ) ) )
         names.insert( "Child_Relationship" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Child_Relationship" );

      if( ( required_transients && is_field_transient( e_field_id_Child_Relationship ) )
       || ( !required_transients && !is_field_transient( e_field_id_Child_Relationship ) ) )
         names.insert( "Child_Relationship" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Child_Relationship" );

      if( ( required_transients && is_field_transient( e_field_id_Child_Relationship ) )
       || ( !required_transients && !is_field_transient( e_field_id_Child_Relationship ) ) )
         names.insert( "Child_Relationship" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum" );

      if( ( required_transients && is_field_transient( e_field_id_Enum ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum ) ) )
         names.insert( "Enum" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item ) ) )
         names.insert( "Enum_Item" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item ) ) )
         names.insert( "Enum_Item" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_2" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_2 ) ) )
         names.insert( "Enum_Item_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_2" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_2 ) ) )
         names.insert( "Enum_Item_2" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_3" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_3 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_3 ) ) )
         names.insert( "Enum_Item_3" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_3" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_3 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_3 ) ) )
         names.insert( "Enum_Item_3" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_4" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_4 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_4 ) ) )
         names.insert( "Enum_Item_4" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_4" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_4 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_4 ) ) )
         names.insert( "Enum_Item_4" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_5" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_5 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_5 ) ) )
         names.insert( "Enum_Item_5" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Enum_Item_5" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item_5 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item_5 ) ) )
         names.insert( "Enum_Item_5" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Value" );

      if( ( required_transients && is_field_transient( e_field_id_Value ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value ) ) )
         names.insert( "Value" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Value_Literal" );

      if( ( required_transients && is_field_transient( e_field_id_Value_Literal ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value_Literal ) ) )
         names.insert( "Value_Literal" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Value_String" );

      if( ( required_transients && is_field_transient( e_field_id_Value_String ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value_String ) ) )
         names.insert( "Value_String" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Value_Left_Part" );

      if( ( required_transients && is_field_transient( e_field_id_Value_Left_Part ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value_Left_Part ) ) )
         names.insert( "Value_Left_Part" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Value_Right_Part" );

      if( ( required_transients && is_field_transient( e_field_id_Value_Right_Part ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value_Right_Part ) ) )
         names.insert( "Value_Right_Part" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field_Values" );

      if( ( required_transients && is_field_transient( e_field_id_Field_Values ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field_Values ) ) )
         names.insert( "Field_Values" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Fields" );

      if( ( required_transients && is_field_transient( e_field_id_Fields ) )
       || ( !required_transients && !is_field_transient( e_field_id_Fields ) ) )
         names.insert( "Fields" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Field_Pairs" );

      if( ( required_transients && is_field_transient( e_field_id_Field_Pairs ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field_Pairs ) ) )
         names.insert( "Field_Pairs" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Options" );

      if( ( required_transients && is_field_transient( e_field_id_Options ) )
       || ( !required_transients && !is_field_transient( e_field_id_Options ) ) )
         names.insert( "Options" );
   }

   if( needs_field_value( "Vars", dependents ) )
   {
      dependents.insert( "Specification_Type" );

      if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
       || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
         names.insert( "Specification_Type" );
   }
   // [(finish field_from_search_replace)]

   // [(start field_from_search_replace)]
   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Model" );

      if( ( required_transients && is_field_transient( e_field_id_Model ) )
       || ( !required_transients && !is_field_transient( e_field_id_Model ) ) )
         names.insert( "Model" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Class" );

      if( ( required_transients && is_field_transient( e_field_id_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Class ) ) )
         names.insert( "Class" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Field" );

      if( ( required_transients && is_field_transient( e_field_id_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field ) ) )
         names.insert( "Field" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Field_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Field_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Field_Class ) ) )
         names.insert( "Field_Class" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Modifier" );

      if( ( required_transients && is_field_transient( e_field_id_Modifier ) )
       || ( !required_transients && !is_field_transient( e_field_id_Modifier ) ) )
         names.insert( "Modifier" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Source_Parent" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Parent ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Parent ) ) )
         names.insert( "Source_Parent" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Source_Child" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child ) ) )
         names.insert( "Source_Child" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Source_Child_2" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Child_2 ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Child_2 ) ) )
         names.insert( "Source_Child_2" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Source_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Source_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Source_Field ) ) )
         names.insert( "Source_Field" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Test_Parent" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Parent ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Parent ) ) )
         names.insert( "Test_Parent" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Test_Child" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Child ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Child ) ) )
         names.insert( "Test_Child" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Test_Field" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Field ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Field ) ) )
         names.insert( "Test_Field" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Test_Field_Class" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Field_Class ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Field_Class ) ) )
         names.insert( "Test_Field_Class" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Test_Value" );

      if( ( required_transients && is_field_transient( e_field_id_Test_Value ) )
       || ( !required_transients && !is_field_transient( e_field_id_Test_Value ) ) )
         names.insert( "Test_Value" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Procedure" );

      if( ( required_transients && is_field_transient( e_field_id_Procedure ) )
       || ( !required_transients && !is_field_transient( e_field_id_Procedure ) ) )
         names.insert( "Procedure" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Child_Relationship" );

      if( ( required_transients && is_field_transient( e_field_id_Child_Relationship ) )
       || ( !required_transients && !is_field_transient( e_field_id_Child_Relationship ) ) )
         names.insert( "Child_Relationship" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Enum" );

      if( ( required_transients && is_field_transient( e_field_id_Enum ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum ) ) )
         names.insert( "Enum" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Enum_Item" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item ) ) )
         names.insert( "Enum_Item" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Enum_Item" );

      if( ( required_transients && is_field_transient( e_field_id_Enum_Item ) )
       || ( !required_transients && !is_field_transient( e_field_id_Enum_Item ) ) )
         names.insert( "Enum_Item" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Value" );

      if( ( required_transients && is_field_transient( e_field_id_Value ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value ) ) )
         names.insert( "Value" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Value_Right_Part" );

      if( ( required_transients && is_field_transient( e_field_id_Value_Right_Part ) )
       || ( !required_transients && !is_field_transient( e_field_id_Value_Right_Part ) ) )
         names.insert( "Value_Right_Part" );
   }

   if( needs_field_value( "Strings", dependents ) )
   {
      dependents.insert( "Specification_Type" );

      if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
       || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
         names.insert( "Specification_Type" );
   }
   // [(finish field_from_search_replace)]

   // [<start get_required_field_names>]
   // [<finish get_required_field_names>]
}

void Meta_Specification::get_always_required_field_names(
 set< string >& names, bool required_transients, set< string >& dependents ) const
{
   ( void )names;
   ( void )dependents;
   ( void )required_transients;

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Other_Class modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Field modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Other_Field modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Procedure modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Procedure_Arg modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Procedure_Arg_2 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Procedure_Arg_3 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Other_Procedure modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Other_Procedure_2 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Modifier modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Enum modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Enum_Item modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Enum_Item_2 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Enum_Item_3 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Enum_Item_4 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Enum_Item_5 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Value modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Source_Parent modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Source_Field modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Test_Field modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Test_Value modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Options modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Source_Child modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Use_Source_Parent modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Source_Parent" ); // (for Hide_Source_Parent modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Source_Parent ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Source_Parent ) ) )
      names.insert( "Use_Source_Parent" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Source_Parent" ); // (for Hide_Source_Child modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Source_Parent ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Source_Parent ) ) )
      names.insert( "Use_Source_Parent" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Source_Parent" ); // (for Hide_Source_Field modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Source_Parent ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Source_Parent ) ) )
      names.insert( "Use_Source_Parent" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Permission modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Protect_Source_Parent" ); // (for Protect_Source_Parent modifier)

   if( ( required_transients && is_field_transient( e_field_id_Protect_Source_Parent ) )
    || ( !required_transients && !is_field_transient( e_field_id_Protect_Source_Parent ) ) )
      names.insert( "Protect_Source_Parent" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Protect_Source_Parent modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Child_Relationship modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Protect_Class modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Use_Test_Parent_Child modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Test_Parent_Child" ); // (for Hide_Test_Parent modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Test_Parent_Child ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Test_Parent_Child ) ) )
      names.insert( "Use_Test_Parent_Child" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Test_Parent_Child" ); // (for Hide_Test_Child modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Test_Parent_Child ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Test_Parent_Child ) ) )
      names.insert( "Use_Test_Parent_Child" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Test_Parent_Child" ); // (for Hide_Test_Field modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Test_Parent_Child ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Test_Parent_Child ) ) )
      names.insert( "Use_Test_Parent_Child" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Protect_Child_Rel" ); // (for Protect_Child_Relationship modifier)

   if( ( required_transients && is_field_transient( e_field_id_Protect_Child_Rel ) )
    || ( !required_transients && !is_field_transient( e_field_id_Protect_Child_Rel ) ) )
      names.insert( "Protect_Child_Rel" );
   // [(finish modifier_field_value)]

   // [(start move_up_and_down)]
   dependents.insert( "Order" );

   if( ( required_transients && is_field_transient( e_field_id_Order ) )
    || ( !required_transients && !is_field_transient( e_field_id_Order ) ) )
      names.insert( "Order" );
   // [(finish move_up_and_down)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Other_Field_2 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Source_Child_2 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Source_Parent" ); // (for Hide_Source_Child_2 modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Source_Parent ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Source_Parent ) ) )
      names.insert( "Use_Source_Parent" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Protect_Child_Relationship modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Protect_Procedure" ); // (for Protect_Procedure modifier)

   if( ( required_transients && is_field_transient( e_field_id_Protect_Procedure ) )
    || ( !required_transients && !is_field_transient( e_field_id_Protect_Procedure ) ) )
      names.insert( "Protect_Procedure" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Source_Grandchild modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Use_Source_Parent" ); // (for Hide_Source_Grandchild modifier)

   if( ( required_transients && is_field_transient( e_field_id_Use_Source_Parent ) )
    || ( !required_transients && !is_field_transient( e_field_id_Use_Source_Parent ) ) )
      names.insert( "Use_Source_Parent" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Protect_Class modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Hide_Source_Class modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Protect_Procedure modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start update_parent_cascade)]
   dependents.insert( "Parent_Specification" );

   if( ( required_transients && is_field_transient( e_field_id_Parent_Specification ) )
    || ( !required_transients && !is_field_transient( e_field_id_Parent_Specification ) ) )
      names.insert( "Parent_Specification" );
   // [(finish update_parent_cascade)]

   // [(start modifier_field_value)]
   dependents.insert( "Specification_Type" ); // (for Protect_Enum modifier)

   if( ( required_transients && is_field_transient( e_field_id_Specification_Type ) )
    || ( !required_transients && !is_field_transient( e_field_id_Specification_Type ) ) )
      names.insert( "Specification_Type" );
   // [(finish modifier_field_value)]

   // [(start update_parent_cascade)]
   dependents.insert( "Parent_Specification" );

   if( ( required_transients && is_field_transient( e_field_id_Parent_Specification ) )
    || ( !required_transients && !is_field_transient( e_field_id_Parent_Specification ) ) )
      names.insert( "Parent_Specification" );
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   dependents.insert( "Parent_Specification" );

   if( ( required_transients && is_field_transient( e_field_id_Parent_Specification ) )
    || ( !required_transients && !is_field_transient( e_field_id_Parent_Specification ) ) )
      names.insert( "Parent_Specification" );
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   dependents.insert( "Parent_Specification" );

   if( ( required_transients && is_field_transient( e_field_id_Parent_Specification ) )
    || ( !required_transients && !is_field_transient( e_field_id_Parent_Specification ) ) )
      names.insert( "Parent_Specification" );
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   dependents.insert( "Parent_Specification" );

   if( ( required_transients && is_field_transient( e_field_id_Parent_Specification ) )
    || ( !required_transients && !is_field_transient( e_field_id_Parent_Specification ) ) )
      names.insert( "Parent_Specification" );
   // [(finish update_parent_cascade)]

   // [(start update_parent_cascade)]
   dependents.insert( "Parent_Specification" );

   if( ( required_transients && is_field_transient( e_field_id_Parent_Specification ) )
    || ( !required_transients && !is_field_transient( e_field_id_Parent_Specification ) ) )
      names.insert( "Parent_Specification" );
   // [(finish update_parent_cascade)]

   // [<start get_always_required_field_names>]
   // [<finish get_always_required_field_names>]
}

void Meta_Specification::get_transient_replacement_field_names( const string& name, vector< string >& names ) const
{
   ( void )name;
   ( void )names;

   // [<start get_transient_replacement_field_names>]
   // [<finish get_transient_replacement_field_names>]
}

void Meta_Specification::do_generate_sql( generate_sql_type type, vector< string >& sql_stmts ) const
{
   generate_sql( static_class_name( ), type, sql_stmts );
}

const char* Meta_Specification::static_resolved_module_id( )
{
   return static_module_id( );
}

const char* Meta_Specification::static_resolved_module_name( )
{
   return static_module_name( );
}

const char* Meta_Specification::static_lock_class_id( )
{
   return "115100";
}

const char* Meta_Specification::static_check_class_name( )
{
   return "Specification";
}

bool Meta_Specification::static_has_derivations( )
{
   return !g_derivations.empty( );
}

void Meta_Specification::static_get_class_info( class_info_container& class_info )
{
   class_info.push_back( "100.115100" );
}

void Meta_Specification::static_get_field_info( field_info_container& all_field_info )
{
   all_field_info.push_back( field_info( "115108", "Actions", "string", false ) );
   all_field_info.push_back( field_info( "115124", "All_Strings", "string", false ) );
   all_field_info.push_back( field_info( "115123", "All_Vars", "string", false ) );
   all_field_info.push_back( field_info( "301491", "Child_Rel_Child_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "115121", "Child_Rel_Field_Key", "string", false ) );
   all_field_info.push_back( field_info( "301475", "Child_Relationship", "Meta_Relationship", false ) );
   all_field_info.push_back( field_info( "301406", "Child_Specification_Type", "Meta_Specification_Type", false ) );
   all_field_info.push_back( field_info( "301420", "Class", "Meta_Class", true ) );
   all_field_info.push_back( field_info( "115112", "Comments", "string", false ) );
   all_field_info.push_back( field_info( "301460", "Enum", "Meta_Enum", false ) );
   all_field_info.push_back( field_info( "301470", "Enum_Item", "Meta_Enum_Item", false ) );
   all_field_info.push_back( field_info( "301471", "Enum_Item_2", "Meta_Enum_Item", false ) );
   all_field_info.push_back( field_info( "301472", "Enum_Item_3", "Meta_Enum_Item", false ) );
   all_field_info.push_back( field_info( "301473", "Enum_Item_4", "Meta_Enum_Item", false ) );
   all_field_info.push_back( field_info( "301474", "Enum_Item_5", "Meta_Enum_Item", false ) );
   all_field_info.push_back( field_info( "301430", "Field", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301492", "Field_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "115120", "Field_Pairs", "string", false ) );
   all_field_info.push_back( field_info( "115113", "Field_Values", "string", false ) );
   all_field_info.push_back( field_info( "115126", "Fields", "string", false ) );
   all_field_info.push_back( field_info( "115117", "Id", "string", false ) );
   all_field_info.push_back( field_info( "115128", "Is_Required_For_UI_Gen", "bool", false ) );
   all_field_info.push_back( field_info( "301400", "Model", "Meta_Model", true ) );
   all_field_info.push_back( field_info( "301440", "Modifier", "Meta_Modifier", false ) );
   all_field_info.push_back( field_info( "115101", "Name", "string", false ) );
   all_field_info.push_back( field_info( "115104", "Options", "string", false ) );
   all_field_info.push_back( field_info( "115105", "Order", "string", false ) );
   all_field_info.push_back( field_info( "301421", "Other_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "301435", "Other_Field", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301436", "Other_Field_2", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301451", "Other_Procedure", "Meta_Procedure", false ) );
   all_field_info.push_back( field_info( "301452", "Other_Procedure_2", "Meta_Procedure", false ) );
   all_field_info.push_back( field_info( "301405", "Parent_Specification", "Meta_Specification", false ) );
   all_field_info.push_back( field_info( "302550", "Parent_Specification_Copy_Child_Links", "Meta_Specification_Copy_Child_Links", false ) );
   all_field_info.push_back( field_info( "301499", "Permission", "Meta_Permission", false ) );
   all_field_info.push_back( field_info( "301450", "Procedure", "Meta_Procedure", false ) );
   all_field_info.push_back( field_info( "301498", "Procedure_Arg", "Meta_Procedure_Arg", false ) );
   all_field_info.push_back( field_info( "301477", "Procedure_Arg_2", "Meta_Procedure_Arg", false ) );
   all_field_info.push_back( field_info( "301478", "Procedure_Arg_3", "Meta_Procedure_Arg", false ) );
   all_field_info.push_back( field_info( "115122", "Protect_Child_Rel", "bool", false ) );
   all_field_info.push_back( field_info( "115115", "Protect_Procedure", "bool", false ) );
   all_field_info.push_back( field_info( "115111", "Protect_Source_Parent", "bool", false ) );
   all_field_info.push_back( field_info( "115118", "Restrict_Values", "string", false ) );
   all_field_info.push_back( field_info( "301495", "Source_Child", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301496", "Source_Child_2", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301489", "Source_Child_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "301494", "Source_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "301481", "Source_Field", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301482", "Source_Field_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "301476", "Source_Grandchild", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301480", "Source_Parent", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301490", "Source_Parent_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "301410", "Specification_Type", "Meta_Specification_Type", true ) );
   all_field_info.push_back( field_info( "115119", "Strings", "string", false ) );
   all_field_info.push_back( field_info( "301488", "Test_Child", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301485", "Test_Field", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301493", "Test_Field_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "301486", "Test_Parent", "Meta_Field", false ) );
   all_field_info.push_back( field_info( "301487", "Test_Parent_Class", "Meta_Class", false ) );
   all_field_info.push_back( field_info( "115103", "Test_Value", "string", false ) );
   all_field_info.push_back( field_info( "115107", "Use_Source_Parent", "bool", false ) );
   all_field_info.push_back( field_info( "115110", "Use_Test_Parent_Child", "bool", false ) );
   all_field_info.push_back( field_info( "115102", "Value", "string", false ) );
   all_field_info.push_back( field_info( "115129", "Value_Left_Part", "string", false ) );
   all_field_info.push_back( field_info( "115116", "Value_Literal", "string", false ) );
   all_field_info.push_back( field_info( "115127", "Value_Numeric_String", "string", false ) );
   all_field_info.push_back( field_info( "115130", "Value_Right_Part", "string", false ) );
   all_field_info.push_back( field_info( "115125", "Value_String", "string", false ) );
   all_field_info.push_back( field_info( "115114", "Vars", "string", false ) );
}

void Meta_Specification::static_get_foreign_key_info( foreign_key_info_container& foreign_key_info )
{
   ( void )foreign_key_info;

   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Child_Rel_Child_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Child_Relationship, make_pair( "Meta.115100", "Meta_Relationship" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Child_Specification_Type, make_pair( "Meta.115100", "Meta_Specification_Type" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Enum, make_pair( "Meta.115100", "Meta_Enum" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Enum_Item, make_pair( "Meta.115100", "Meta_Enum_Item" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Enum_Item_2, make_pair( "Meta.115100", "Meta_Enum_Item" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Enum_Item_3, make_pair( "Meta.115100", "Meta_Enum_Item" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Enum_Item_4, make_pair( "Meta.115100", "Meta_Enum_Item" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Enum_Item_5, make_pair( "Meta.115100", "Meta_Enum_Item" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Field, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Field_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Model, make_pair( "Meta.115100", "Meta_Model" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Modifier, make_pair( "Meta.115100", "Meta_Modifier" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Other_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Other_Field, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Other_Field_2, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Other_Procedure, make_pair( "Meta.115100", "Meta_Procedure" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Other_Procedure_2, make_pair( "Meta.115100", "Meta_Procedure" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Parent_Specification, make_pair( "Meta.115100", "Meta_Specification" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Parent_Specification_Copy_Child_Links, make_pair( "Meta.115100", "Meta_Specification_Copy_Child_Links" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Permission, make_pair( "Meta.115100", "Meta_Permission" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Procedure, make_pair( "Meta.115100", "Meta_Procedure" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Procedure_Arg, make_pair( "Meta.115100", "Meta_Procedure_Arg" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Procedure_Arg_2, make_pair( "Meta.115100", "Meta_Procedure_Arg" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Procedure_Arg_3, make_pair( "Meta.115100", "Meta_Procedure_Arg" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Child, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Child_2, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Child_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Field, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Field_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Grandchild, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Parent, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Source_Parent_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Specification_Type, make_pair( "Meta.115100", "Meta_Specification_Type" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Test_Child, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Test_Field, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Test_Field_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Test_Parent, make_pair( "Meta.115100", "Meta_Field" ) ) );
   foreign_key_info.insert( foreign_key_info_value_type( c_field_id_Test_Parent_Class, make_pair( "Meta.115100", "Meta_Class" ) ) );
}

int Meta_Specification::static_get_num_fields( bool* p_done, const string* p_class_name )
{
   if( p_done && p_class_name && *p_class_name == static_class_name( ) )
      *p_done = true;

   return c_num_fields;
}

bool Meta_Specification::static_is_field_transient( field_id id )
{
   return is_transient_field( static_get_field_id( id ) );
}

const char* Meta_Specification::static_get_field_id( field_id id )
{
   const char* p_id = 0;

   switch( id )
   {
      case 1:
      p_id = "115108";
      break;

      case 2:
      p_id = "115124";
      break;

      case 3:
      p_id = "115123";
      break;

      case 4:
      p_id = "301491";
      break;

      case 5:
      p_id = "115121";
      break;

      case 6:
      p_id = "301475";
      break;

      case 7:
      p_id = "301406";
      break;

      case 8:
      p_id = "301420";
      break;

      case 9:
      p_id = "115112";
      break;

      case 10:
      p_id = "301460";
      break;

      case 11:
      p_id = "301470";
      break;

      case 12:
      p_id = "301471";
      break;

      case 13:
      p_id = "301472";
      break;

      case 14:
      p_id = "301473";
      break;

      case 15:
      p_id = "301474";
      break;

      case 16:
      p_id = "301430";
      break;

      case 17:
      p_id = "301492";
      break;

      case 18:
      p_id = "115120";
      break;

      case 19:
      p_id = "115113";
      break;

      case 20:
      p_id = "115126";
      break;

      case 21:
      p_id = "115117";
      break;

      case 22:
      p_id = "115128";
      break;

      case 23:
      p_id = "301400";
      break;

      case 24:
      p_id = "301440";
      break;

      case 25:
      p_id = "115101";
      break;

      case 26:
      p_id = "115104";
      break;

      case 27:
      p_id = "115105";
      break;

      case 28:
      p_id = "301421";
      break;

      case 29:
      p_id = "301435";
      break;

      case 30:
      p_id = "301436";
      break;

      case 31:
      p_id = "301451";
      break;

      case 32:
      p_id = "301452";
      break;

      case 33:
      p_id = "301405";
      break;

      case 34:
      p_id = "302550";
      break;

      case 35:
      p_id = "301499";
      break;

      case 36:
      p_id = "301450";
      break;

      case 37:
      p_id = "301498";
      break;

      case 38:
      p_id = "301477";
      break;

      case 39:
      p_id = "301478";
      break;

      case 40:
      p_id = "115122";
      break;

      case 41:
      p_id = "115115";
      break;

      case 42:
      p_id = "115111";
      break;

      case 43:
      p_id = "115118";
      break;

      case 44:
      p_id = "301495";
      break;

      case 45:
      p_id = "301496";
      break;

      case 46:
      p_id = "301489";
      break;

      case 47:
      p_id = "301494";
      break;

      case 48:
      p_id = "301481";
      break;

      case 49:
      p_id = "301482";
      break;

      case 50:
      p_id = "301476";
      break;

      case 51:
      p_id = "301480";
      break;

      case 52:
      p_id = "301490";
      break;

      case 53:
      p_id = "301410";
      break;

      case 54:
      p_id = "115119";
      break;

      case 55:
      p_id = "301488";
      break;

      case 56:
      p_id = "301485";
      break;

      case 57:
      p_id = "301493";
      break;

      case 58:
      p_id = "301486";
      break;

      case 59:
      p_id = "301487";
      break;

      case 60:
      p_id = "115103";
      break;

      case 61:
      p_id = "115107";
      break;

      case 62:
      p_id = "115110";
      break;

      case 63:
      p_id = "115102";
      break;

      case 64:
      p_id = "115129";
      break;

      case 65:
      p_id = "115116";
      break;

      case 66:
      p_id = "115127";
      break;

      case 67:
      p_id = "115130";
      break;

      case 68:
      p_id = "115125";
      break;

      case 69:
      p_id = "115114";
      break;
   }

   if( !p_id )
      throw runtime_error( "unknown field id #" + to_string( id ) + " for class Specification" );

   return p_id;
}

const char* Meta_Specification::static_get_field_name( field_id id )
{
   const char* p_id = 0;

   switch( id )
   {
      case 1:
      p_id = "Actions";
      break;

      case 2:
      p_id = "All_Strings";
      break;

      case 3:
      p_id = "All_Vars";
      break;

      case 4:
      p_id = "Child_Rel_Child_Class";
      break;

      case 5:
      p_id = "Child_Rel_Field_Key";
      break;

      case 6:
      p_id = "Child_Relationship";
      break;

      case 7:
      p_id = "Child_Specification_Type";
      break;

      case 8:
      p_id = "Class";
      break;

      case 9:
      p_id = "Comments";
      break;

      case 10:
      p_id = "Enum";
      break;

      case 11:
      p_id = "Enum_Item";
      break;

      case 12:
      p_id = "Enum_Item_2";
      break;

      case 13:
      p_id = "Enum_Item_3";
      break;

      case 14:
      p_id = "Enum_Item_4";
      break;

      case 15:
      p_id = "Enum_Item_5";
      break;

      case 16:
      p_id = "Field";
      break;

      case 17:
      p_id = "Field_Class";
      break;

      case 18:
      p_id = "Field_Pairs";
      break;

      case 19:
      p_id = "Field_Values";
      break;

      case 20:
      p_id = "Fields";
      break;

      case 21:
      p_id = "Id";
      break;

      case 22:
      p_id = "Is_Required_For_UI_Gen";
      break;

      case 23:
      p_id = "Model";
      break;

      case 24:
      p_id = "Modifier";
      break;

      case 25:
      p_id = "Name";
      break;

      case 26:
      p_id = "Options";
      break;

      case 27:
      p_id = "Order";
      break;

      case 28:
      p_id = "Other_Class";
      break;

      case 29:
      p_id = "Other_Field";
      break;

      case 30:
      p_id = "Other_Field_2";
      break;

      case 31:
      p_id = "Other_Procedure";
      break;

      case 32:
      p_id = "Other_Procedure_2";
      break;

      case 33:
      p_id = "Parent_Specification";
      break;

      case 34:
      p_id = "Parent_Specification_Copy_Child_Links";
      break;

      case 35:
      p_id = "Permission";
      break;

      case 36:
      p_id = "Procedure";
      break;

      case 37:
      p_id = "Procedure_Arg";
      break;

      case 38:
      p_id = "Procedure_Arg_2";
      break;

      case 39:
      p_id = "Procedure_Arg_3";
      break;

      case 40:
      p_id = "Protect_Child_Rel";
      break;

      case 41:
      p_id = "Protect_Procedure";
      break;

      case 42:
      p_id = "Protect_Source_Parent";
      break;

      case 43:
      p_id = "Restrict_Values";
      break;

      case 44:
      p_id = "Source_Child";
      break;

      case 45:
      p_id = "Source_Child_2";
      break;

      case 46:
      p_id = "Source_Child_Class";
      break;

      case 47:
      p_id = "Source_Class";
      break;

      case 48:
      p_id = "Source_Field";
      break;

      case 49:
      p_id = "Source_Field_Class";
      break;

      case 50:
      p_id = "Source_Grandchild";
      break;

      case 51:
      p_id = "Source_Parent";
      break;

      case 52:
      p_id = "Source_Parent_Class";
      break;

      case 53:
      p_id = "Specification_Type";
      break;

      case 54:
      p_id = "Strings";
      break;

      case 55:
      p_id = "Test_Child";
      break;

      case 56:
      p_id = "Test_Field";
      break;

      case 57:
      p_id = "Test_Field_Class";
      break;

      case 58:
      p_id = "Test_Parent";
      break;

      case 59:
      p_id = "Test_Parent_Class";
      break;

      case 60:
      p_id = "Test_Value";
      break;

      case 61:
      p_id = "Use_Source_Parent";
      break;

      case 62:
      p_id = "Use_Test_Parent_Child";
      break;

      case 63:
      p_id = "Value";
      break;

      case 64:
      p_id = "Value_Left_Part";
      break;

      case 65:
      p_id = "Value_Literal";
      break;

      case 66:
      p_id = "Value_Numeric_String";
      break;

      case 67:
      p_id = "Value_Right_Part";
      break;

      case 68:
      p_id = "Value_String";
      break;

      case 69:
      p_id = "Vars";
      break;
   }

   if( !p_id )
      throw runtime_error( "unknown field id #" + to_string( id ) + " for class Specification" );

   return p_id;
}

int Meta_Specification::static_get_field_num( const string& field )
{
   int rc = 0;

   if( field.empty( ) )
      throw runtime_error( "unexpected empty field name/id for static_get_field_num( )" );
   else if( field == c_field_id_Actions || field == c_field_name_Actions )
      rc += 1;
   else if( field == c_field_id_All_Strings || field == c_field_name_All_Strings )
      rc += 2;
   else if( field == c_field_id_All_Vars || field == c_field_name_All_Vars )
      rc += 3;
   else if( field == c_field_id_Child_Rel_Child_Class || field == c_field_name_Child_Rel_Child_Class )
      rc += 4;
   else if( field == c_field_id_Child_Rel_Field_Key || field == c_field_name_Child_Rel_Field_Key )
      rc += 5;
   else if( field == c_field_id_Child_Relationship || field == c_field_name_Child_Relationship )
      rc += 6;
   else if( field == c_field_id_Child_Specification_Type || field == c_field_name_Child_Specification_Type )
      rc += 7;
   else if( field == c_field_id_Class || field == c_field_name_Class )
      rc += 8;
   else if( field == c_field_id_Comments || field == c_field_name_Comments )
      rc += 9;
   else if( field == c_field_id_Enum || field == c_field_name_Enum )
      rc += 10;
   else if( field == c_field_id_Enum_Item || field == c_field_name_Enum_Item )
      rc += 11;
   else if( field == c_field_id_Enum_Item_2 || field == c_field_name_Enum_Item_2 )
      rc += 12;
   else if( field == c_field_id_Enum_Item_3 || field == c_field_name_Enum_Item_3 )
      rc += 13;
   else if( field == c_field_id_Enum_Item_4 || field == c_field_name_Enum_Item_4 )
      rc += 14;
   else if( field == c_field_id_Enum_Item_5 || field == c_field_name_Enum_Item_5 )
      rc += 15;
   else if( field == c_field_id_Field || field == c_field_name_Field )
      rc += 16;
   else if( field == c_field_id_Field_Class || field == c_field_name_Field_Class )
      rc += 17;
   else if( field == c_field_id_Field_Pairs || field == c_field_name_Field_Pairs )
      rc += 18;
   else if( field == c_field_id_Field_Values || field == c_field_name_Field_Values )
      rc += 19;
   else if( field == c_field_id_Fields || field == c_field_name_Fields )
      rc += 20;
   else if( field == c_field_id_Id || field == c_field_name_Id )
      rc += 21;
   else if( field == c_field_id_Is_Required_For_UI_Gen || field == c_field_name_Is_Required_For_UI_Gen )
      rc += 22;
   else if( field == c_field_id_Model || field == c_field_name_Model )
      rc += 23;
   else if( field == c_field_id_Modifier || field == c_field_name_Modifier )
      rc += 24;
   else if( field == c_field_id_Name || field == c_field_name_Name )
      rc += 25;
   else if( field == c_field_id_Options || field == c_field_name_Options )
      rc += 26;
   else if( field == c_field_id_Order || field == c_field_name_Order )
      rc += 27;
   else if( field == c_field_id_Other_Class || field == c_field_name_Other_Class )
      rc += 28;
   else if( field == c_field_id_Other_Field || field == c_field_name_Other_Field )
      rc += 29;
   else if( field == c_field_id_Other_Field_2 || field == c_field_name_Other_Field_2 )
      rc += 30;
   else if( field == c_field_id_Other_Procedure || field == c_field_name_Other_Procedure )
      rc += 31;
   else if( field == c_field_id_Other_Procedure_2 || field == c_field_name_Other_Procedure_2 )
      rc += 32;
   else if( field == c_field_id_Parent_Specification || field == c_field_name_Parent_Specification )
      rc += 33;
   else if( field == c_field_id_Parent_Specification_Copy_Child_Links || field == c_field_name_Parent_Specification_Copy_Child_Links )
      rc += 34;
   else if( field == c_field_id_Permission || field == c_field_name_Permission )
      rc += 35;
   else if( field == c_field_id_Procedure || field == c_field_name_Procedure )
      rc += 36;
   else if( field == c_field_id_Procedure_Arg || field == c_field_name_Procedure_Arg )
      rc += 37;
   else if( field == c_field_id_Procedure_Arg_2 || field == c_field_name_Procedure_Arg_2 )
      rc += 38;
   else if( field == c_field_id_Procedure_Arg_3 || field == c_field_name_Procedure_Arg_3 )
      rc += 39;
   else if( field == c_field_id_Protect_Child_Rel || field == c_field_name_Protect_Child_Rel )
      rc += 40;
   else if( field == c_field_id_Protect_Procedure || field == c_field_name_Protect_Procedure )
      rc += 41;
   else if( field == c_field_id_Protect_Source_Parent || field == c_field_name_Protect_Source_Parent )
      rc += 42;
   else if( field == c_field_id_Restrict_Values || field == c_field_name_Restrict_Values )
      rc += 43;
   else if( field == c_field_id_Source_Child || field == c_field_name_Source_Child )
      rc += 44;
   else if( field == c_field_id_Source_Child_2 || field == c_field_name_Source_Child_2 )
      rc += 45;
   else if( field == c_field_id_Source_Child_Class || field == c_field_name_Source_Child_Class )
      rc += 46;
   else if( field == c_field_id_Source_Class || field == c_field_name_Source_Class )
      rc += 47;
   else if( field == c_field_id_Source_Field || field == c_field_name_Source_Field )
      rc += 48;
   else if( field == c_field_id_Source_Field_Class || field == c_field_name_Source_Field_Class )
      rc += 49;
   else if( field == c_field_id_Source_Grandchild || field == c_field_name_Source_Grandchild )
      rc += 50;
   else if( field == c_field_id_Source_Parent || field == c_field_name_Source_Parent )
      rc += 51;
   else if( field == c_field_id_Source_Parent_Class || field == c_field_name_Source_Parent_Class )
      rc += 52;
   else if( field == c_field_id_Specification_Type || field == c_field_name_Specification_Type )
      rc += 53;
   else if( field == c_field_id_Strings || field == c_field_name_Strings )
      rc += 54;
   else if( field == c_field_id_Test_Child || field == c_field_name_Test_Child )
      rc += 55;
   else if( field == c_field_id_Test_Field || field == c_field_name_Test_Field )
      rc += 56;
   else if( field == c_field_id_Test_Field_Class || field == c_field_name_Test_Field_Class )
      rc += 57;
   else if( field == c_field_id_Test_Parent || field == c_field_name_Test_Parent )
      rc += 58;
   else if( field == c_field_id_Test_Parent_Class || field == c_field_name_Test_Parent_Class )
      rc += 59;
   else if( field == c_field_id_Test_Value || field == c_field_name_Test_Value )
      rc += 60;
   else if( field == c_field_id_Use_Source_Parent || field == c_field_name_Use_Source_Parent )
      rc += 61;
   else if( field == c_field_id_Use_Test_Parent_Child || field == c_field_name_Use_Test_Parent_Child )
      rc += 62;
   else if( field == c_field_id_Value || field == c_field_name_Value )
      rc += 63;
   else if( field == c_field_id_Value_Left_Part || field == c_field_name_Value_Left_Part )
      rc += 64;
   else if( field == c_field_id_Value_Literal || field == c_field_name_Value_Literal )
      rc += 65;
   else if( field == c_field_id_Value_Numeric_String || field == c_field_name_Value_Numeric_String )
      rc += 66;
   else if( field == c_field_id_Value_Right_Part || field == c_field_name_Value_Right_Part )
      rc += 67;
   else if( field == c_field_id_Value_String || field == c_field_name_Value_String )
      rc += 68;
   else if( field == c_field_id_Vars || field == c_field_name_Vars )
      rc += 69;

   return rc - 1;
}

procedure_info_container& Meta_Specification::static_get_procedure_info( )
{
   static bool initialised = false;
   static procedure_info_container procedures;

   if( !initialised )
   {
      initialised = true;
      procedures.insert( make_pair( "115439", "Add_Arg_1" ) );
      procedures.insert( make_pair( "115440", "Add_Arg_2" ) );
      procedures.insert( make_pair( "115432", "Add_Child_Info" ) );
      procedures.insert( make_pair( "115443", "Add_Extra_Info" ) );
      procedures.insert( make_pair( "115430", "Add_Field" ) );
      procedures.insert( make_pair( "115431", "Add_Field_Pair" ) );
      procedures.insert( make_pair( "115438", "Add_Grandchild_Info" ) );
      procedures.insert( make_pair( "115441", "Add_Info" ) );
      procedures.insert( make_pair( "115444", "Add_Next" ) );
      procedures.insert( make_pair( "115442", "Add_Opt_Info" ) );
      procedures.insert( make_pair( "115445", "Add_Other_Info" ) );
      procedures.insert( make_pair( "115433", "Add_Secondary" ) );
      procedures.insert( make_pair( "115437", "Add_Source_Info" ) );
      procedures.insert( make_pair( "115434", "Add_Stats_1" ) );
      procedures.insert( make_pair( "115435", "Add_Stats_2" ) );
      procedures.insert( make_pair( "115436", "Add_Stats_Info" ) );
      procedures.insert( make_pair( "115510", "Generate_All_Strings" ) );
      procedures.insert( make_pair( "115500", "Generate_All_Vars" ) );
      procedures.insert( make_pair( "115420", "Move_Down" ) );
      procedures.insert( make_pair( "115410", "Move_Up" ) );
   }

   return procedures;
}

string Meta_Specification::static_get_sql_columns( )
{
   string sql_columns;

   sql_columns += 
    "C_Key_ VARCHAR(64),"
    "C_Ver_ INTEGER NOT NULL,"
    "C_Rev_ INTEGER NOT NULL,"
    "C_Typ_ VARCHAR(24) NOT NULL,"
    "C_Actions VARCHAR(128) NOT NULL,"
    "C_Child_Rel_Child_Class VARCHAR(64) NOT NULL,"
    "C_Child_Rel_Field_Key VARCHAR(128) NOT NULL,"
    "C_Child_Relationship VARCHAR(64) NOT NULL,"
    "C_Child_Specification_Type VARCHAR(64) NOT NULL,"
    "C_Class VARCHAR(64) NOT NULL,"
    "C_Comments VARCHAR(128) NOT NULL,"
    "C_Enum VARCHAR(64) NOT NULL,"
    "C_Enum_Item VARCHAR(64) NOT NULL,"
    "C_Enum_Item_2 VARCHAR(64) NOT NULL,"
    "C_Enum_Item_3 VARCHAR(64) NOT NULL,"
    "C_Enum_Item_4 VARCHAR(64) NOT NULL,"
    "C_Enum_Item_5 VARCHAR(64) NOT NULL,"
    "C_Field VARCHAR(64) NOT NULL,"
    "C_Field_Class VARCHAR(64) NOT NULL,"
    "C_Field_Pairs TEXT NOT NULL,"
    "C_Field_Values TEXT NOT NULL,"
    "C_Fields TEXT NOT NULL,"
    "C_Id VARCHAR(128) NOT NULL,"
    "C_Is_Required_For_UI_Gen INTEGER NOT NULL,"
    "C_Model VARCHAR(64) NOT NULL,"
    "C_Modifier VARCHAR(64) NOT NULL,"
    "C_Name VARCHAR(128) NOT NULL,"
    "C_Options VARCHAR(128) NOT NULL,"
    "C_Order VARCHAR(128) NOT NULL,"
    "C_Other_Class VARCHAR(64) NOT NULL,"
    "C_Other_Field VARCHAR(64) NOT NULL,"
    "C_Other_Field_2 VARCHAR(64) NOT NULL,"
    "C_Other_Procedure VARCHAR(64) NOT NULL,"
    "C_Other_Procedure_2 VARCHAR(64) NOT NULL,"
    "C_Parent_Specification VARCHAR(64) NOT NULL,"
    "C_Parent_Specification_Copy_Child_Links VARCHAR(64) NOT NULL,"
    "C_Permission VARCHAR(64) NOT NULL,"
    "C_Procedure VARCHAR(64) NOT NULL,"
    "C_Procedure_Arg VARCHAR(64) NOT NULL,"
    "C_Procedure_Arg_2 VARCHAR(64) NOT NULL,"
    "C_Procedure_Arg_3 VARCHAR(64) NOT NULL,"
    "C_Protect_Child_Rel INTEGER NOT NULL,"
    "C_Protect_Procedure INTEGER NOT NULL,"
    "C_Protect_Source_Parent INTEGER NOT NULL,"
    "C_Restrict_Values VARCHAR(128) NOT NULL,"
    "C_Source_Child VARCHAR(64) NOT NULL,"
    "C_Source_Child_2 VARCHAR(64) NOT NULL,"
    "C_Source_Child_Class VARCHAR(64) NOT NULL,"
    "C_Source_Class VARCHAR(64) NOT NULL,"
    "C_Source_Field VARCHAR(64) NOT NULL,"
    "C_Source_Field_Class VARCHAR(64) NOT NULL,"
    "C_Source_Grandchild VARCHAR(64) NOT NULL,"
    "C_Source_Parent VARCHAR(64) NOT NULL,"
    "C_Source_Parent_Class VARCHAR(64) NOT NULL,"
    "C_Specification_Type VARCHAR(64) NOT NULL,"
    "C_Test_Child VARCHAR(64) NOT NULL,"
    "C_Test_Field VARCHAR(64) NOT NULL,"
    "C_Test_Field_Class VARCHAR(64) NOT NULL,"
    "C_Test_Parent VARCHAR(64) NOT NULL,"
    "C_Test_Parent_Class VARCHAR(64) NOT NULL,"
    "C_Test_Value VARCHAR(128) NOT NULL,"
    "C_Use_Source_Parent INTEGER NOT NULL,"
    "C_Use_Test_Parent_Child INTEGER NOT NULL,"
    "C_Value VARCHAR(128) NOT NULL,"
    "C_Value_Left_Part VARCHAR(128) NOT NULL,"
    "C_Value_Literal VARCHAR(128) NOT NULL,"
    "C_Value_Numeric_String VARCHAR(128) NOT NULL,"
    "C_Value_Right_Part VARCHAR(128) NOT NULL,"
    "C_Value_String VARCHAR(128) NOT NULL,"
    "PRIMARY KEY(C_Key_)";

   return sql_columns;
}

void Meta_Specification::static_get_text_search_fields( vector< string >& fields )
{
   ( void )fields;
}

void Meta_Specification::static_get_all_enum_pairs( vector< pair< string, string > >& pairs )
{
   ( void )pairs;
}

void Meta_Specification::static_get_sql_indexes( vector< string >& indexes )
{
   indexes.push_back( "C_Class,C_Parent_Specification,C_Order" );
   indexes.push_back( "C_Class,C_Specification_Type,C_Key_" );
   indexes.push_back( "C_Model,C_Id" );
   indexes.push_back( "C_Model,C_Order" );
   indexes.push_back( "C_Model,C_Parent_Specification,C_Id" );
   indexes.push_back( "C_Model,C_Parent_Specification,C_Name" );
   indexes.push_back( "C_Model,C_Parent_Specification,C_Order" );
   indexes.push_back( "C_Parent_Specification,C_Order,C_Key_" );
}

void Meta_Specification::static_get_sql_unique_indexes( vector< string >& indexes )
{
   indexes.push_back( "C_Class,C_Parent_Specification,C_Order" );
   indexes.push_back( "C_Model,C_Id" );
   indexes.push_back( "C_Model,C_Order" );
   indexes.push_back( "C_Model,C_Parent_Specification,C_Id" );
   indexes.push_back( "C_Model,C_Parent_Specification,C_Name" );
   indexes.push_back( "C_Model,C_Parent_Specification,C_Order" );
}

void Meta_Specification::static_insert_derivation( const string& module_and_class_id )
{
   g_derivations.insert( module_and_class_id );
}

void Meta_Specification::static_remove_derivation( const string& module_and_class_id )
{
   if( g_derivations.count( module_and_class_id ) )
      g_derivations.erase( module_and_class_id );
}

void Meta_Specification::static_insert_external_alias( const string& module_and_class_id, Meta_Specification* p_instance )
{
   g_external_aliases.insert( external_aliases_value_type( module_and_class_id, p_instance ) );
}

void Meta_Specification::static_remove_external_alias( const string& module_and_class_id )
{
   if( g_external_aliases.count( module_and_class_id ) )
   {
      delete g_external_aliases[ module_and_class_id ];
      g_external_aliases.erase( module_and_class_id );
   }
}

void Meta_Specification::static_class_init( const char* p_module_name )
{
   if( !p_module_name )
      throw runtime_error( "unexpected null module name pointer for init" );

   // [<start static_class_init>]
   // [<finish static_class_init>]
}

void Meta_Specification::static_class_term( const char* p_module_name )
{
   if( !p_module_name )
      throw runtime_error( "unexpected null module name pointer for term" );

   // [<start static_class_term>]
   // [<finish static_class_term>]
}
