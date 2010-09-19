/*
OpenGL Utility Library

Copyright (c) 2010 okard

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/
#include "GlContextImpl.hpp"
//Windows Implementation

#include <glul/EventLoop>
#include <glul/GlContext>

using namespace glul;

/**
* Constructor
*/
GlContextImpl::GlContextImpl(Window& win)
    : window(win)
{
    // get the device context (DC)
    mhDC = GetDC( window.winWindow() );

    //set the pixel format for the DC
    PIXELFORMATDESCRIPTOR pfd;
    ZeroMemory( &pfd, sizeof( pfd ) );
    pfd.nSize = sizeof( pfd );
    pfd.nVersion = 1;
    pfd.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL |
                  PFD_DOUBLEBUFFER;
    pfd.iPixelType = PFD_TYPE_RGBA;
    pfd.cColorBits = 24;
    pfd.cDepthBits = 16;
    pfd.iLayerType = PFD_MAIN_PLANE;
    int format = ChoosePixelFormat( mhDC, &pfd );
    SetPixelFormat( mhDC, format, &pfd );

    // create the render context (RC)
    mhRC = wglCreateContext( mhDC );
}
        
/**
* Destructor
*/
GlContextImpl::~GlContextImpl()
{
    wglDeleteContext( mhRC );
    ReleaseDC( window.winWindow(), mhDC );
}
        
/**
* make GlContext current
*/
void GlContextImpl::makeCurrent()
{
    wglMakeCurrent( mhDC, mhRC );
}
        
/**
* swap buffers
*/
void GlContextImpl::swap()
{
    SwapBuffers(mhDC);	
}