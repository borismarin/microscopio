# CMakeLists for the AOLDAQ API.
# Describes the project structure and how to build it.
#
# Written by: Eduardo Renesto

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(aoldaq
    VERSION 0.1
    DESCRIPTION "Data Acqusition API for the Silver Lab AOL Microscope.")

# If we're on unix-like and building debug, generate
# a compile_commands.json file to feed into ccls
IF(UNIX AND CMAKE_BUILD_TYPE MATCHES DEBUG)
    SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
ENDIF(UNIX AND CMAKE_BUILD_TYPE MATCHES DEBUG)

# Add the source files
ADD_LIBRARY(aoldaq SHARED
    src/aoldaq.c)

# Add the headers
TARGET_INCLUDE_DIRECTORIES(aoldaq PRIVATE ./include)

# Specify the public header
SET_TARGET_PROPERTIES(aoldaq PROPERTIES PUBLIC_HEADER include/aoldaq.h)

# Set the .so file version
SET_TARGET_PROPERTIES(aoldaq PROPERTIES VERSION ${PROJECT_VERSION})
SET_TARGET_PROPERTIES(aoldaq PROPERTIES SOVERSION 1)

# TODO: Describe the install part
