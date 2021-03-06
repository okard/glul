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
#include "EventLoopImpl.hpp"

#include <glul/EventLoop.hpp>
#include <glul/Window.hpp>
#include <glul/Exception.hpp>

using namespace glul;


/**
* Constructor
*/
EventLoopImpl::EventLoopImpl()
{
    //Connect to X Server Display
    display = XOpenDisplay(NULL);
    if(display == NULL)
        throw Exception("failed to connect to xserver");
}
    
/**
* Destructor
*/
EventLoopImpl::~EventLoopImpl()
{
}
    
/**
* \brief get a new event
*/
bool EventLoopImpl::getEvent()
{
    XNextEvent(display, &event);
    return true;
}
        
/**
* \brief peek a new event
*/
bool EventLoopImpl::peekEvent()
{
    XPeekEvent(display, &event);
    return true;
}

/**
* \brief dispatch events
*/
bool EventLoopImpl::dispatch()
{
    glul::Window::dispatch(event);
    
    return true;
}

/**
* Get Xlib Display
*/
Display* EventLoopImpl::xlibDisplay()
{
    return display;
}
