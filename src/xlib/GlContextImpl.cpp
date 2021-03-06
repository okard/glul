/*
    OpenGL Utility Library

    Copyright (c) 2010  okard

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

#include <glul/EventLoop.hpp>
#include <glul/Window.hpp>
#include <glul/GlContext.hpp>
#include <glul/Exception.hpp>

using namespace glul;

/**
* Constructor
*/
GlContextImpl::GlContextImpl(Window& win)
    : window(win), display(EventLoop::getSingleton().xlibDisplay())
{
    //gl attributes
    GLint att[] = { GLX_RGBA, GLX_DEPTH_SIZE, 24, GLX_DOUBLEBUFFER, None };
    
    //choose visual
    vi = glXChooseVisual(display, 0, att);
    
    if(vi == NULL)
        throw Exception("glXChooseVisual failes");
    
    //create opengl context
    context = glXCreateContext(display, vi, NULL, GL_TRUE);
    
    if(context == NULL)
        throw Exception("glXCreateContext failes");
    
    //set colormap?
    //change depth?
    //match visual
    //set visual?
    //implement context sharing
        
    //try to get an OpenGL 3, 4 Context
}

/**
* Destructor
*/
GlContextImpl::~GlContextImpl()
{
    glXDestroyContext(display, context);
}
        
/**
* Make OpenGL Context current
*/
void GlContextImpl::makeCurrent()
{
    glXMakeCurrent(display, window.xlibWindow(), context);
}

/**
* Swap OpenGL Buffers
*/
void GlContextImpl::swap()
{
    glXSwapBuffers(display, window.xlibWindow());
}
