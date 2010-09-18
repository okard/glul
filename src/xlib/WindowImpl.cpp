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
#include "WindowImpl.hpp"

#include <map>

#include <glul/EventLoop>
#include <glul/Window>

//namespace
using namespace glul;

///map structure to dispatch window events
std::map< ::Window, glul::Window*> xlib_window_map;

/**
* Initialize Window
*/
void WindowImpl::initialize(const char* title, int width, int height)
{
    display = glul::EventLoopPtr->xlibDisplay();
    
    int screen = DefaultScreen(display);
    ::Window root = DefaultRootWindow(display);
    
    //set attributes
    //attributes.colormap = cmap;
    attributes.event_mask = StructureNotifyMask | SubstructureNotifyMask | ExposureMask | KeyPressMask ;
 
    window = XCreateWindow(display, root, 0, 0, width, height, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &attributes);

    //save mapping
    xlib_window_map[window] = &self;
    
    XStoreName(display, window, title);
    XMapWindow(display, window);
    XFlush(display);
}
  
/**
* Show Window
*/
void WindowImpl::show()
{
}

/**
* get window height
*/
int WindowImpl::getHeight()
{
    XGetWindowAttributes(display, window, &gwa);
    return gwa.height;
}
        
/**
* get window width
*/
int WindowImpl::getWidth()
{
    XGetWindowAttributes(display, window, &gwa);
    return gwa.width;
}

/**
* get xlib Window
*/
::Window WindowImpl::xlibWindow()
{
    return window;
}
    
/**
* Window Dispatch
*/
void WindowImpl::dispatch(XEvent& event)
{
    Window* win = xlib_window_map[event.xany.window];
    
    switch(event.type)
    {
        case Expose:
            win->OnPaint();
            break;
        case ConfigureNotify:
            win->OnResize();
            break;
        case KeyPress:
            break;
    }
}