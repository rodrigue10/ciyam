storage_init ciyam
session_variable @attached_file_path .
pc guest 20120102 100 105100 guest_model "105101=Sample,300500=guests,105102=0.1,105103=2012,105104=M001,105112=0"
guest_model
pf 100 105100 guest_model "105101,105102,105103,105104,105105,105106,105107,105108,105109,105110,105111,105112,105113,105114"
[guest_model =1.0 512 100:105100] Sample,0.1,2012,M001,M001C100,M001S1000,M001L100,M001V100,,,,2,0,
pc guest 20120102 100 136100 guest_standard "136101=Standard,136107=Standard,302810=Standard,302800=guest_model"
guest_standard
pe guest 20120102 100 136100 "-v=@async=false,@message=Installing Standard Package..." guest_standard =1.0 -136410
pc guest 20120102 100 136100 guest_user "136101=User,136107=User,302810=User,302800=guest_model"
guest_user
pe guest 20120102 100 136100 "-v=@async=false,@message=Installing User Package..." guest_user =1.0 -136410
pf 100 106100 "106104 " 106101,106102,106104 -min
System_Information,System_Information,M001C100
User,User,M001C101
pf 100 107100 "107110 " 107101,107110 -min
Name,M001C100F100
Vendor,M001C100F101
Reference,M001C100F102
Message,M001C100F103
Actions,M001C100F104
Dummy_Self,M001C101F100
User_Id,M001C101F101
User_Id_or_Name,M001C101F102
User_Name,M001C101F103
User_Password_Change,M001C101F104
Actions,M001C101F105
Active,M001C101F106
Change_Password_Time,M001C101F107
Template,M001C101F108
Unique,M001C101F109
Unix_Timestamp,M001C101F110
User_Hash,M001C101F111
Password,M001C101F112
Password_Change_After,M001C101F113
Password_Hash,M001C101F114
Class_Id,M001C101F115
Command_Hash,M001C101F116
Created_On,M001C101F117
Description,M001C101F118
Email,M001C101F119
Email_Failure,M001C101F120
Email_Address,M001C101F121
Has_Password,M001C101F122
Hide_Email_Address,M001C101F123
Is_In_Restore,M001C101F124
Not_Is_In_Restore,M001C101F125
Permissions,M001C101F126
Reset_Password,M001C101F127
Rescue_Password,M001C101F128
Is_Self_Or_Admin,M001C101F129
Key,M001C101F130
Must_Change_Password,M001C101F131
No_Email,M001C101F132
No_Email_Padding,M001C101F133
Read_Access_Only,M001C101F134
pf 100 103100 "103104 " 103101,103104 -min
primitive,E000
primitive,E000
Currency,E100
Day_Type,E101
Customary_Event,E102
Month,E103
Day_Of_Month,E104
Day_Number,E105
Day_Set,E106
Date_Cycle,E107
Day_Of_Week,E108
Minutes,E109
Occurrence,E110
Orientation,E111
Change_Password_Seconds,E112
pf 100 102100 "102111 " 102101,102111 -min
string,T000
string,T000
datetime,T001
datetime,T001
date,T002
date,T002
time,T003
time,T003
numeric,T004
numeric,T004
int,T005
int,T005
bool,T006
bool,T006
foreign_key,T007
foreign_key,T007
bytes,T100
str001,T101
str002,T102
str003,T103
str004,T104
str005,T105
str010,T106
str015,T107
str020,T108
str025,T109
str030,T110
str040,T111
str050,T112
str060,T113
str080,T114
str100,T115
str125,T116
str150,T117
str200,T118
year,T119
duration,T120
filename,T121
0..10,T122
1..10,T123
0..100,T124
1..100,T125
0..1000,T126
1..1000,T127
0..10000,T128
1..10000,T129
0..100000,T130
1..100000,T131
std_date,T132
std_time,T133
std_datetime,T134
std_timestamp,T135
std_numeric,T136
std_percentage,T137
std_money,T138
std_money_amount,T139
std_crypto,T140
std_crypto_amount,T141
