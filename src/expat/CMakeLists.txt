# This file is copyrighted under the BSD-license for buildsystem files of KDE
# copyright 2010, Patrick Spendrin <ps_ml@gmx.de>

project(expat)

cmake_minimum_required(VERSION 2.6)
set(PACKAGE_BUGREPORT "expat-bugs@libexpat.org")
set(PACKAGE_NAME "expat")
set(PACKAGE_VERSION "2.1.0")
set(PACKAGE_STRING "${PACKAGE_NAME} ${PACKAGE_VERSION}")
set(PACKAGE_TARNAME "${PACKAGE_NAME}")

option(BUILD_tools "build the xmlwf tool for expat library" ON)
option(BUILD_examples "build the examples for expat library" ON)
option(BUILD_tests "build the tests for expat library" ON)
option(BUILD_shared "build a shared expat library" ON)


# compile as position independent code
if (UNIX OR CYGWIN)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()


# are we using the intel compiler
set(USING_INTEL)
if (WIN32 AND CMAKE_C_COMPILER AND ${CMAKE_C_COMPILER} MATCHES ".*icl.*$")
  message(STATUS "Detected Intel Compiler")
  set(USING_INTEL TRUE)
endif ()

# if using msvc or intel windows compiler allow for the use of the static runtime
if(MSVC OR USING_INTEL)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_CRT_NONSTDC_NO_DEPRECATE)
    set(BUILD_DEFINITIONS "${BUILD_DEFINITIONS} -D_CRT_SECURE_NO_WARNINGS")
    option(WITH_STATIC_RUNTIME "Compile using the static MSVC Runtime." OFF)
    if(WITH_STATIC_RUNTIME)
        foreach(flag_var
            CMAKE_CXX_FLAGS CMAKE_CXX_FLAGS_DEBUG CMAKE_CXX_FLAGS_RELEASE
            CMAKE_CXX_FLAGS_MINSIZEREL CMAKE_CXX_FLAGS_RELWITHDEBINFO
            CMAKE_C_FLAGS CMAKE_C_FLAGS_DEBUG CMAKE_C_FLAGS_RELEASE
            CMAKE_C_FLAGS_MINSIZEREL CMAKE_C_FLAGS_RELWITHDEBINFO)

            if(${flag_var} MATCHES "/MD")
                string(REGEX REPLACE "/MD" "/MT" ${flag_var} "${${flag_var}}")
            endif(${flag_var} MATCHES "/MD")
        endforeach(flag_var)
    add_definitions( -D_MT)
    endif(WITH_STATIC_RUNTIME)
endif(MSVC OR USING_INTEL)


# configuration options
set(XML_CONTEXT_BYTES 1024 CACHE STRING "Define to specify how much context to retain around the current parse point")
option(XML_DTD "Define to make parameter entity parsing functionality available" ON)
option(XML_NS "Define to make XML Namespaces functionality available" ON)

if(XML_DTD)
    set(XML_DTD 1)
else(XML_DTD)
    set(XML_DTD 0)
endif(XML_DTD)
if(XML_NS)
    set(XML_NS 1)
else(XML_NS)
    set(XML_NS 0)
endif(XML_NS)

if(BUILD_tests)
    enable_testing()
endif(BUILD_tests)

include(ConfigureChecks.cmake)

include_directories(${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR}/lib)
if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -wd4996)
endif(MSVC)

set(expat_SRCS
    lib/xmlparse.c
    lib/xmlrole.c
    lib/xmltok.c 
    lib/xmltok_impl.c 
    lib/xmltok_ns.c
)

if(WIN32 AND BUILD_shared)
    set(expat_SRCS ${expat_SRCS} lib/libexpat.def)
endif(WIN32 AND BUILD_shared)

if(BUILD_shared)
    set(_SHARED SHARED)
else(BUILD_shared)
   if(WIN32)
     # don't decorate
     add_definitions(-DXML_STATIC)
   endif(WIN32)
   set(_SHARED STATIC)
endif(BUILD_shared)

add_library(expat ${_SHARED} ${expat_SRCS})

message(STATUS ${CMAKE_INSTALL_PREFIX})

include(GNUInstallDirs)
install(TARGETS expat EXPORT expatTargets
        RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}"
        LIBRARY DESTINATION "${CMAKE_INSTALL_LIBDIR}"
        ARCHIVE DESTINATION "${CMAKE_INSTALL_LIBDIR}")


set(exec_prefix "${CMAKE_INSTALL_BINDIR}")
set(libdir "${CMAKE_INSTALL_LIBDIR}")
set(includedir "${CMAKE_INSTALL_INCLUDEDIR}")
configure_file(expat.pc.in "${CMAKE_CURRENT_BINARY_DIR}/expat.pc")

install(FILES lib/expat.h lib/expat_external.h DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/expat.pc DESTINATION "${CMAKE_INSTALL_LIBDIR}/pkgconfig")

# Make cmake config files for all targets
install(EXPORT expatTargets
    DESTINATION "${CMAKE_INSTALL_LIBDIR}/cmake"
    FILE expat-config.cmake)

if(BUILD_tools AND NOT WINCE)
    set(xmlwf_SRCS
        xmlwf/xmlwf.c
        xmlwf/xmlfile.c
        xmlwf/codepage.c
        xmlwf/readfilemap.c
    )

    add_executable(xmlwf ${xmlwf_SRCS})
    target_link_libraries(xmlwf expat)
    install(TARGETS xmlwf DESTINATION bin)
    install(FILES doc/xmlwf.1 DESTINATION share/man/man1)
endif(BUILD_tools AND NOT WINCE)

if(BUILD_examples)
    add_executable(elements examples/elements.c)
    target_link_libraries(elements expat)

    add_executable(outline examples/outline.c)
    target_link_libraries(outline expat)
endif(BUILD_examples)

if(BUILD_tests)
    ## these are unittests that can be run on any platform
    add_executable(runtests tests/runtests.c tests/chardata.c tests/minicheck.c)
    target_link_libraries(runtests expat)
    add_test(runtests runtests)

    add_executable(runtestspp tests/runtestspp.cpp tests/chardata.c tests/minicheck.c)
    target_link_libraries(runtestspp expat)
    add_test(runtestspp runtestspp)
endif(BUILD_tests)
