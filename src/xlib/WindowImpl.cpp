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

#include <glul/EventLoop.hpp>
#include <glul/Window.hpp>
#include <glul/Keyboard.hpp>

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
    attributes.event_mask = StructureNotifyMask | SubstructureNotifyMask | ExposureMask | KeyPressMask | KeyReleaseMask;
 
    window = XCreateWindow(display, root, 0, 0, width, height, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &attributes);

    //save mapping
    xlib_window_map[window] = &self;
    
    //interested in WM_DELETE_WINDOW Message
    //for the "XIO:fatal IO error 11" error
    wmDeleteMessage = XInternAtom(display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(display, window, &wmDeleteMessage, 1);
    
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
    static Keyboard keyboard;
    static Mouse mouse;
    
    Window* win = xlib_window_map[event.xany.window];
    
    switch(event.type)
    {
        case Expose:
            win->OnPaint();
            break;
        case ConfigureNotify:
            win->windowRect.width = event.xconfigure.width;
            win->windowRect.height =  event.xconfigure.height;
            win->OnResize(win->windowRect);
            break;
        case KeyPress:
            win->OnKeyDown(keyboard);
            break;
        case KeyRelease:
            win->OnKeyUp(keyboard);
            break;
        case ClientMessage:
        if(event.xclient.data.l[0] == win->wmDeleteMessage)
        {
            //Kill Window
            XUnmapWindow(win->display, win->window);
            XDestroyWindow(win->display, win->window);   
        }
        break;
    }
}