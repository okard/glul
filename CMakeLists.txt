############################################
# CMake File for OpenGL Utility Library glul
############################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

PROJECT(glul)

INCLUDE_DIRECTORIES(src)

# Include Platform specific files to build
IF(WIN32)
  set(GLUL_PLATFORM_SRC src/win32/EventLoopImpl.cpp)
ELSE()
  set(GLUL_PLATFORM_SRC src/xcb/EventLoopImpl.cpp)
ENDIF()

# Library
ADD_LIBRARY(glul 
            ${GLUL_PLATFORM_SRC}
            src/EventLoop.cpp)