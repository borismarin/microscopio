# CMakeLists for the GL Viewer.
# Describes the project structure and how to build it.
#
# This was written *very fast*, and does not build on Windows.
# You will need FreeGLUT and GLEW installed 
#
# Written by: Eduardo Renesto

CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(glviewer
    VERSION 0.1
    DESCRIPTION "Sample live viewer for the AOLDAQ API using OpenGL.")

# If we're on unix-like and building debug, generate
# a compile_commands.json file to feed into ccls
IF(UNIX AND CMAKE_BUILD_TYPE MATCHES DEBUG)
    SET(CMAKE_EXPORT_COMPILE_COMMANDS 1)
ENDIF(UNIX AND CMAKE_BUILD_TYPE MATCHES DEBUG)

ADD_LIBRARY(aoldaq SHARED IMPORTED)
SET_PROPERTY(TARGET aoldaq PROPERTY IMPORTED_LOCATION 
    "${CMAKE_CURRENT_SOURCE_DIR}/../aoldaq/build/libaoldaq.so")

# Add the source files
ADD_EXECUTABLE(glviewer
    src/shader.c
    src/vao.c
    src/texture.c
    src/util.c
    src/main.c)

# Add the headers
INCLUDE_DIRECTORIES(../aoldaq/include)
LINK_DIRECTORIES(../aoldaq/build)

# Copy the shaders
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/quad.vs.glsl ${CMAKE_BINARY_DIR}/quad.vs.glsl COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/quad.fs.glsl ${CMAKE_BINARY_DIR}/quad.fs.glsl COPYONLY)

TARGET_LINK_LIBRARIES(glviewer aoldaq -lglut -lGLEW -lGLU -lGL)

# TODO: Describe the install part
