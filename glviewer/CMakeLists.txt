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

ADD_SUBDIRECTORY(aoldaq)

# Add the headers
INCLUDE_DIRECTORIES(../aoldaq/include)
LINK_DIRECTORIES(../aoldaq/build)

SET(GLEW32 "")

IF(WIN32)
    ADD_DEFINITIONS(-DWIN32)
    ADD_DEFINITIONS(-D_CRT_SECURE_NO_WARNINGS)
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/deps/freeglut/include)
    INCLUDE_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/include)
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/deps/freeglut/lib/x64)
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/deps/glew-2.1.0/lib/Release/x64)
    LINK_DIRECTORIES(${CMAKE_CURRENT_SOURCE_DIR}/../aoldaq/build_win)

    SET(GLEW32 "glew32")
ENDIF(WIN32)

# Add the source files
ADD_EXECUTABLE(glviewer
    src/shader.c
    src/vao.c
    src/texture.c
    src/util.c
    src/main.c)

# Copy the shaders
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/quad.vs.glsl ${CMAKE_BINARY_DIR}/quad.vs.glsl COPYONLY)
CONFIGURE_FILE(${CMAKE_CURRENT_SOURCE_DIR}/quad.fs.glsl ${CMAKE_BINARY_DIR}/quad.fs.glsl COPYONLY)

TARGET_LINK_LIBRARIES(glviewer aoldaq ${GLEW32} -lglut -lGLEW -lGLU -lGL -lm)

# TODO: Describe the install part
