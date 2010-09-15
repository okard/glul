############################################
# CMake File for OpenGL Utility Library glul
############################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

PROJECT(glul)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(include)

# Include Platform specific files to build
IF(WIN32)
  set(GLUL_PLATFORM_SRC src/win/EventLoopImpl.cpp
                        src/win/WindowImpl.cpp
                        src/win/GlContextImpl.cpp)
ELSE()
  set(GLUL_PLATFORM_SRC src/xlib/EventLoopImpl.cpp
                        src/xlib/WindowImpl.cpp
                        src/xlib/GlContextImpl.cpp)
  set(GLUL_PLATFORM_LIBS "X11" "GL" "GLU")
ENDIF()

# Library
ADD_LIBRARY(glul 
            ${GLUL_PLATFORM_SRC}
            src/EventLoop.cpp
            src/Window.cpp)

TARGET_LINK_LIBRARIES(glul ${GLUL_PLATFORM_LIBS})


# Simple test app
ADD_EXECUTABLE(simple_test tests/simple_test.cpp)
TARGET_LINK_LIBRARIES(simple_test glul)

# Simple test app
ADD_EXECUTABLE(simple_gl_test tests/simple_gl_test.cpp)
TARGET_LINK_LIBRARIES(simple_gl_test glul)