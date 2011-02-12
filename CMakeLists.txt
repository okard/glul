############################################
# CMake File for OpenGL Utility Library glul
############################################
CMAKE_MINIMUM_REQUIRED(VERSION 2.8) 

PROJECT(glul)

SET(GLUL_XCB true)

INCLUDE_DIRECTORIES(src)
INCLUDE_DIRECTORIES(include)

# Include Platform specific files to build
IF(WIN32)
    set(GLUL_PLATFORM_SRC src/win/EventLoopImpl.cpp
                        src/win/WindowImpl.cpp
                        src/win/GlContextImpl.cpp)
    set(GLUL_PLATFORM_LIBS "OpenGL32")

ELSEIF(GLUL_XCB)
    add_definitions(-DGLUL_XCB)
    set(GLUL_PLATFORM_SRC src/xcb/EventLoopImpl.cpp
                          src/xcb/WindowImpl.cpp
                          src/xcb/GlContextImpl.cpp)
    set(GLUL_PLATFORM_LIBS "xcb" "GL" "GLU")

ELSE()
    add_definitions(-DGLUL_XLIB)
    set(GLUL_PLATFORM_SRC src/xlib/EventLoopImpl.cpp
                          src/xlib/WindowImpl.cpp
                          src/xlib/GlContextImpl.cpp)
    set(GLUL_PLATFORM_LIBS "X11" "GL" "GLU")
ENDIF()

#definitions
ADD_DEFINITIONS(-DGLEW_STATIC) # GLEW_BUILD for dll/so

# Library
ADD_LIBRARY(glul SHARED
            ${GLUL_PLATFORM_SRC}
            src/glew/glew.c
            src/glew/Glew.cpp
            src/EventLoop.cpp
            src/Window.cpp
            src/GlWindow.cpp)

TARGET_LINK_LIBRARIES(glul ${GLUL_PLATFORM_LIBS})

SET(GLULTESTS true)
IF(DEFINED GLULTESTS)
  ENABLE_TESTING()
  SUBDIRS(tests)
ENDIF(DEFINED GLULTESTS)
