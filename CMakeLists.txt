############################################
# CMake File for OpenGL Utility Library glul
############################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

PROJECT(glul)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(include)

# Include Platform specific files to build
IF(WIN32)
  set(GLUL_PLATFORM_SRC src/win32/EventLoopImpl.cpp)
ELSE()
  set(GLUL_PLATFORM_SRC src/xlib/EventLoopImpl.cpp
                        src/xlib/WindowImpl.cpp)
  set(GLUL_PLATFORM_LIBS "X11")
ENDIF()

# Library
ADD_LIBRARY(glul 
            ${GLUL_PLATFORM_SRC}
            src/base/EventLoopBase.cpp
            src/EventLoop.cpp
            src/base/WindowBase.cpp
            src/Window.cpp)

TARGET_LINK_LIBRARIES(glul ${GLUL_PLATFORM_LIBS})


# Simple test app
ADD_EXECUTABLE(simple_test tests/simple_test.cpp)
TARGET_LINK_LIBRARIES(simple_test glul)
