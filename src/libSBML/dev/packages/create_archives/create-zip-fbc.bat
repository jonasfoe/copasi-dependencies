@ echo off
REM 
REM This script creates a source archive for the FBC package
REM 

SET THIS_DIR=%~dp0
SET PACKAGE_NAME=fbc
set VERSION=libSBML-5.10.2-%PACKAGE_NAME%-src
SET DIST_DIR=%~dp0\%VERSION%
SET PACKAGE_DIR=%~dp0\..\..\..\

SET ZIP=%THIS_DIR%\bin\zip --out "..\%VERSION%.zip" -9 -r 

IF NOT EXIST "%PACKAGE_DIR%" goto NO_DIR

REM IF EXIST "%THIS_DIR%\temp" goto TEMP_CREATED
REM mkdir "%THIS_DIR%\temp"
REM :TEMP_CREATED

IF EXIST "%DIST_DIR%" goto CREATED
mkdir "%DIST_DIR%"
:CREATED

cd /d %DIST_DIR%
mkdir src
mkdir src\sbml
mkdir src\sbml\packages
mkdir src\sbml\packages\%PACKAGE_NAME%
mkdir src\sbml\packages\%PACKAGE_NAME%\common
mkdir src\sbml\packages\%PACKAGE_NAME%\extension
mkdir src\sbml\packages\%PACKAGE_NAME%\extension\test
mkdir src\sbml\packages\%PACKAGE_NAME%\extension\test\test-data
mkdir src\sbml\packages\%PACKAGE_NAME%\sbml
mkdir src\sbml\packages\%PACKAGE_NAME%\util
mkdir src\sbml\packages\%PACKAGE_NAME%\validator
mkdir src\sbml\packages\%PACKAGE_NAME%\validator\constraints
mkdir src\sbml\packages\%PACKAGE_NAME%\validator\test
mkdir src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data
mkdir src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\general-constraints
mkdir src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\identifier-constraints


copy /y %PACKAGE_DIR%\%PACKAGE_NAME%-package.cmake .
copy /y %PACKAGE_DIR%\src\%PACKAGE_NAME%-package.cmake src

copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%-register*      src\sbml\packages
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\*.in      src\sbml\packages\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\common\*.in      src\sbml\packages\%PACKAGE_NAME%\common\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\common\*.h      src\sbml\packages\%PACKAGE_NAME%\common\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\*.in   src\sbml\packages\%PACKAGE_NAME%\extension\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\*.h   src\sbml\packages\%PACKAGE_NAME%\extension\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\*.cpp src\sbml\packages\%PACKAGE_NAME%\extension\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\sbml\*.in        src\sbml\packages\%PACKAGE_NAME%\sbml\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\sbml\*.h        src\sbml\packages\%PACKAGE_NAME%\sbml\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\sbml\*.cpp      src\sbml\packages\%PACKAGE_NAME%\sbml\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\util\*.in        src\sbml\packages\%PACKAGE_NAME%\util\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\util\*.h        src\sbml\packages\%PACKAGE_NAME%\util\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\util\*.cpp      src\sbml\packages\%PACKAGE_NAME%\util\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\*.in        src\sbml\packages\%PACKAGE_NAME%\validator\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\*.h        src\sbml\packages\%PACKAGE_NAME%\validator\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\*.cpp      src\sbml\packages\%PACKAGE_NAME%\validator\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\constraints\*.in        src\sbml\packages\%PACKAGE_NAME%\validator\constraints
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\constraints\*.h        src\sbml\packages\%PACKAGE_NAME%\validator\constraints
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\constraints\*.cpp      src\sbml\packages\%PACKAGE_NAME%\validator\constraints

copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\test\*.in             src\sbml\packages\%PACKAGE_NAME%\extension\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\test\*.h             src\sbml\packages\%PACKAGE_NAME%\extension\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\test\*.c             src\sbml\packages\%PACKAGE_NAME%\extension\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\test\*.cpp           src\sbml\packages\%PACKAGE_NAME%\extension\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\test\*.txt           src\sbml\packages\%PACKAGE_NAME%\extension\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\extension\test\test-data\*.xml src\sbml\packages\%PACKAGE_NAME%\extension\test\test-data

copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\*.in             src\sbml\packages\%PACKAGE_NAME%\validator\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\*.in             src\sbml\packages\%PACKAGE_NAME%\validator\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\*.h             src\sbml\packages\%PACKAGE_NAME%\validator\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\*.c             src\sbml\packages\%PACKAGE_NAME%\validator\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\*.cpp           src\sbml\packages\%PACKAGE_NAME%\validator\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\*.txt           src\sbml\packages\%PACKAGE_NAME%\validator\test\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\*.in src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\general-constraints\*.xml src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\general-constraints
copy /y %PACKAGE_DIR%\src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\identifier-constraints\*.xml src\sbml\packages\%PACKAGE_NAME%\validator\test\test-data\identifier-constraints

mkdir src\bindings
mkdir src\bindings\csharp
mkdir src\bindings\java
mkdir src\bindings\matlab
mkdir src\bindings\matlab\test
mkdir src\bindings\matlab\test\test-data
mkdir src\bindings\perl
mkdir src\bindings\python
mkdir src\bindings\r
mkdir src\bindings\ruby
mkdir src\bindings\swig

copy /y %PACKAGE_DIR%\src\bindings\csharp\*-%PACKAGE_NAME%.i    src\bindings\csharp
copy /y %PACKAGE_DIR%\src\bindings\java\*-%PACKAGE_NAME%.i      src\bindings\java
copy /y %PACKAGE_DIR%\src\bindings\matlab\*.c                    src\bindings\matlab
copy /y %PACKAGE_DIR%\src\bindings\matlab\*.m                    src\bindings\matlab
copy /y %PACKAGE_DIR%\src\bindings\matlab\test\*.m               src\bindings\matlab\test
copy /y %PACKAGE_DIR%\src\bindings\matlab\test\test-data\*.xml   src\bindings\matlab\test\test-data
copy /y %PACKAGE_DIR%\src\bindings\perl\*-%PACKAGE_NAME%.cpp    src\bindings\perl
copy /y %PACKAGE_DIR%\src\bindings\perl\*-%PACKAGE_NAME%.i      src\bindings\perl
copy /y %PACKAGE_DIR%\src\bindings\python\*-%PACKAGE_NAME%.cpp  src\bindings\python
copy /y %PACKAGE_DIR%\src\bindings\python\*-%PACKAGE_NAME%.i    src\bindings\python
copy /y %PACKAGE_DIR%\src\bindings\r\*-%PACKAGE_NAME%.cpp       src\bindings\r
copy /y %PACKAGE_DIR%\src\bindings\r\*-%PACKAGE_NAME%.i         src\bindings\r
copy /y %PACKAGE_DIR%\src\bindings\ruby\*-%PACKAGE_NAME%.cpp    src\bindings\ruby
copy /y %PACKAGE_DIR%\src\bindings\ruby\*-%PACKAGE_NAME%.i      src\bindings\ruby
copy /y %PACKAGE_DIR%\src\bindings\swig\%PACKAGE_NAME%-*.i      src\bindings\swig
copy /y %PACKAGE_DIR%\src\bindings\swig\%PACKAGE_NAME%-*.h      src\bindings\swig

mkdir examples
mkdir examples\sample-models
mkdir examples\sample-models\fbc
mkdir examples\cpp
mkdir examples\cpp\%PACKAGE_NAME%
mkdir examples\csharp
mkdir examples\csharp\%PACKAGE_NAME%
mkdir examples\java
mkdir examples\java\%PACKAGE_NAME%
mkdir examples\python
mkdir examples\python\%PACKAGE_NAME%
mkdir examples\perl
mkdir examples\perl\%PACKAGE_NAME%
mkdir examples\r
mkdir examples\r\%PACKAGE_NAME%
mkdir examples\ruby
mkdir examples\ruby\%PACKAGE_NAME%

copy /y %PACKAGE_DIR%\examples\%PACKAGE_NAME%-package.cmake     examples
copy /y "%PACKAGE_DIR%\examples\c++\%PACKAGE_NAME%\*.in"        examples\cpp\%PACKAGE_NAME%\
copy /y "%PACKAGE_DIR%\examples\c++\%PACKAGE_NAME%\*.cpp"       examples\cpp\%PACKAGE_NAME%\
copy /y "%PACKAGE_DIR%\examples\c++\%PACKAGE_NAME%\*.txt"       examples\cpp\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\csharp\%PACKAGE_NAME%\*.cs       examples\csharp\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\csharp\%PACKAGE_NAME%\*.txt      examples\csharp\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\java\%PACKAGE_NAME%\*.java       examples\java\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\java\%PACKAGE_NAME%\*.txt        examples\java\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\python\%PACKAGE_NAME%\*.py       examples\python\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\ruby\%PACKAGE_NAME%\*.rb         examples\ruby\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\perl\%PACKAGE_NAME%\*.pl         examples\perl\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\r\%PACKAGE_NAME%\*.R             examples\r\%PACKAGE_NAME%\
copy /y %PACKAGE_DIR%\examples\sample-models\%PACKAGE_NAME%\*.xml        examples\sample-models\%PACKAGE_NAME%\

cd examples
rename cpp "c++"


:COPY_COMPLETE

cd /d %DIST_DIR%
echo. 
echo creating archive with: %ZIP% *.cmake src examples
echo.
%ZIP% *.cmake src examples

goto DONE

:NO_DIR
echo. 
echo The package directory %PACKAGE_DIR% could not be found. 
echo.

:DONE
cd /d %THIS_DIR%
rd /s /q %DIST_DIR%

REM UNSET VARIABLES
SET THIS_DIR=
SET PACKAGE_NAME=
set VERSION=
SET DIST_DIR=
SET PACKAGE_DIR=
SET ZIP=