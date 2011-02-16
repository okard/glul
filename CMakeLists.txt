############################################
# CMake File for OpenGL Utility Library glul
############################################
cmake_minimum_required(VERSION 2.8) 

project(glul)

include_directories(src)
include_directories(include)

find_package(OpenGL)

# Include Platform specific files to build
if(WIN32)
    set(GLUL_PLATFORM_SRC src/win/EventLoopImpl.cpp
                        src/win/WindowImpl.cpp
                        src/win/GlContextImpl.cpp)
    set(GLUL_PLATFORM_LIBS)

elseif(GLUL_XCB)
    add_definitions(-DGLUL_XCB)
    set(GLUL_PLATFORM_SRC src/xcb/EventLoopImpl.cpp
                          src/xcb/WindowImpl.cpp
                          src/xcb/GlContextImpl.cpp)
    set(GLUL_PLATFORM_LIBS "xcb")

else()
    add_definitions(-DGLUL_XLIB)
    set(GLUL_PLATFORM_SRC src/xlib/EventLoopImpl.cpp
                          src/xlib/WindowImpl.cpp
                          src/xlib/GlContextImpl.cpp)
    find_package(X11)
    set(GLUL_PLATFORM_LIBS ${X11_LIBRARIES})
endif()

#definitions
add_definitions(-DGLEW_STATIC) # GLEW_BUILD for dll/so

# Library
add_library(glul SHARED
            ${GLUL_PLATFORM_SRC}
            src/glew/glew.c
            src/glew/Glew.cpp
            src/EventLoop.cpp
            src/Window.cpp
            src/GlWindow.cpp)

target_link_libraries(glul ${OPENGL_LIBRARIES} ${GLUL_PLATFORM_LIBS})

set(GLULTESTS true)
if(DEFINED GLULTESTS)
  enable_testing()
  add_subdirectory(tests)
endif(DEFINED GLULTESTS)
