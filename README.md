CIYAM Software Manufacturing Environment
========================================

The following environment variables are required by various scripts:

Name   | Description                 | Sample Value
------ | --------------------------- | ---------------
CPPENV | C++ Compiler (Windows only) | mvc
WEBDIR | Web Document Root path**    | /srv/www/htdocs

** This path must *not* contain spaces and each directory in the path must have "rwx" permissions set so that
both the Apache2 user (wwwrun) and the user account being used for development can create, update, append and
delete files in and below the path (for a development only environment it is easiest to just `chmod a+rwx`).

An optional MARKER environment variable can be used as a way of preventing accidental source code commits due
to some temporary tracing code (as it is used in the pre-commit hook script's call to 'check_source').

Environment variables LIB and INCLUDE for VC++ will require additions for MySQL and (if used) OpenSSL.

If wanting to perform a debug build for Windows use the environment variable CPPDBG.
> e.g. for VC++ set CPPDBG=DEBUG=1

The following are platform specific instructions for installing 3rd party libraries:

NOTE: Windows developers need to be using VS2003 or higher.

For Linux environments the development packages for `libpng` (and optionally `readline`) will also need to be
installed.

NOTE: More specific OS dependency installation instructions can be found in additional "<os_name>.txt" files.

MySQL
-----
http://dev.mysql.com/downloads/mysql/

[Linux]

Is normally standard but you may need to install the appropriate developer package (e.g. mysql-devel).

[Windows]

When installing make sure that the option for "Development libraries and headers" is selected.

For VC++ the LIB environment variable will need this added (replace <ver> with the MySQL version):
- C:\Program Files\MySQL\MySQL Server <ver>\lib\opt<br/>
> e.g. set LIB=C:\Program Files\MySQL\MySQL Server 5.1\lib\opt;%LIB%

For VC++ the INCLUDE environment variable will need this added (replace <ver> with the MySQL version):
- C:\Program Files\MySQL\MySQL Server <ver>\include<br/>
> e.g. set INCLUDE=C:\Program Files\MySQL\MySQL Server 5.1\include;%INCLUDE%

FastCGI
-------
https://github.com/ciyam/fcgi

[Linux]

```
tar -zxvf fcgi-2.4.6.tar.gz
cd fcgi-2.4.6

./configure
make
su
make install
```

[Windows]

```
nmake -f Makefile.nt

copy libfcgi\Release\libfcgi.dll <dest directory>
copy libfcgi\Release\libfcgi.lib <dest directory>
```

Haru PDF Library
----------------
http://libharu.org

[Linux]

```
unzip libharu-RELEASE_2_2_0.zip
cd libharu-2.2.0

./configure
make
su
make install

cp /usr/local/lib/libhpdf-2.2.0.so /usr/lib (depending upon distro)
```

[Windows]

```
unzip -j \tmp\libharu-2.1.0-vc8.zip lib_dll/libhpdf.lib lib_dll/libhpdf.dll

mkdir haru
cd haru
unzip -j \tmp\libharu-2.1.0-vc8.zip include/*
```

OpenSSL
-------
http://www.openssl.org/

[Linux]

Is normally standard but if necessary then:

```
tar xzf openssl-1.0.1h.tar.gz
cd openssl-1.0.1h

./config shared
make
make test
su
make install

cp /usr/local/ssl/lib/libssl.so.1.0.1 /usr/lib (depending upon distro)
cp /usr/local/ssl/lib/libcrypto.so.1.0.1 /usr/lib (depending upon distro)
```

[Windows]

Download and run the installation program.

For VC++ the LIB environment variable will need this added:
- C:\OpenSSL-Win32\lib<br/>
> e.g. set LIB=C:\OpenSSL-Win32\lib;%LIB%

For VC++ the INCLUDE environment variable will need this added:
- C:\OpenSSL-Win32\include<br/>
> e.g. set INCLUDE=C:\OpenSSL-Win32\include;%INCLUDE%

Other General
-------------

Note that "ciyam_server.pem" and "ciyam_client.pem" are identical public/private test only SSL keys encrypted
with the password "password".
