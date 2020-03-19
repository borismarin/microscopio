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
    src/aoldaq_core.c
    src/fpga.c
    src/pipe.c)

# Matlab's MEX apparently only likes .lib files.
# Let's build a static version too, then!
ADD_LIBRARY(aoldaq_static STATIC
    src/aoldaq_core.c
    src/fpga.c
    src/pipe.c)

# Set our own OS flags and the specific 
IF(UNIX AND NOT APPLE)
    ADD_DEFINITIONS(-DAOL_UNIX)
    LINK_DIRECTORIES(./external/lib/linux64)

    # Shared version
    SET_TARGET_PROPERTIES(aoldaq PROPERTIES COMPILE_OPTIONS "-pthread")
    SET_TARGET_PROPERTIES(aoldaq PROPERTIES INTERFACE_COMPILE_OPTIONS "-pthread")
    
    TARGET_LINK_LIBRARIES(aoldaq pthread)

    TARGET_SOURCES(aoldaq PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/os_pipe_unix.c)

    # Static version
    SET_TARGET_PROPERTIES(aoldaq_static PROPERTIES COMPILE_OPTIONS "-pthread")
    SET_TARGET_PROPERTIES(aoldaq_static PROPERTIES INTERFACE_COMPILE_OPTIONS "-pthread")
    
    TARGET_LINK_LIBRARIES(aoldaq_static pthread)

    TARGET_SOURCES(aoldaq_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/os_pipe_unix.c)
ELSEIF(WIN32)
    ADD_DEFINITIONS(-DAOL_WIN32)

    LINK_DIRECTORIES(./external/lib/win64)
    TARGET_INCLUDE_DIRECTORIES(aoldaq PRIVATE ./external/include.win64) # pthreads!
    #TARGET_LINK_LIBRARIES(aoldaq pthreadVC2)

    TARGET_LINK_LIBRARIES(aoldaq pthread)
    TARGET_LINK_LIBRARIES(aoldaq_static pthread)

    TARGET_SOURCES(aoldaq PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/os_pipe_win32.c)
    TARGET_SOURCES(aoldaq_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src/os_pipe_win32.c)
ENDIF(UNIX AND NOT APPLE)

# Win32 is picky...
ADD_DEFINITIONS(-DAOL_BUILD)

# Add the headers
TARGET_INCLUDE_DIRECTORIES(aoldaq PUBLIC ./include)
TARGET_INCLUDE_DIRECTORIES(aoldaq PRIVATE ./external/include)

TARGET_INCLUDE_DIRECTORIES(aoldaq_static PUBLIC ./include)
TARGET_INCLUDE_DIRECTORIES(aoldaq_static PRIVATE ./external/include)

# Specify the public header
SET_TARGET_PROPERTIES(aoldaq PROPERTIES PUBLIC_HEADER include/aoldaq.h)
SET_TARGET_PROPERTIES(aoldaq_static PROPERTIES PUBLIC_HEADER include/aoldaq.h)

# Set the .so file version
SET_TARGET_PROPERTIES(aoldaq PROPERTIES VERSION ${PROJECT_VERSION})
SET_TARGET_PROPERTIES(aoldaq PROPERTIES SOVERSION 1)

SET_TARGET_PROPERTIES(aoldaq_static PROPERTIES VERSION ${PROJECT_VERSION})
SET_TARGET_PROPERTIES(aoldaq_static PROPERTIES SOVERSION 1)

# TODO: Describe the install part
