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

#include "../EventLoop.hpp"
#include "../Window.hpp"
#include "../Keyboard.hpp"

using glul::Window;
using glul::WindowImpl;
using glul::EventLoop;


void WindowImpl::initialize(const char* title, int width, int height)
{
        xcb_connection_t* connection = glul::EventLoopPtr->xcbConnection();
        xcb_screen_t* screen = glul::EventLoopPtr->xcbScreen();
        
        /* create black graphics context */
        gc = xcb_generate_id(connection);
        window = screen->root;
        
        mask = XCB_GC_FOREGROUND | XCB_GC_GRAPHICS_EXPOSURES;
        values[0] = screen->black_pixel;
        values[1] = 0;
        xcb_create_gc(connection, gc, window, mask, values);
    
        /* create window */
        window = xcb_generate_id(connection);
        mask = XCB_CW_BACK_PIXEL | XCB_CW_EVENT_MASK;
        values[0] = screen->white_pixel;
        //Register for required XCB Events?
        //values[1] = XCB_EVENT_MASK_EXPOSURE | XCB_EVENT_MASK_KEY_PRESS;
        values[1] = XCB_EVENT_MASK_EXPOSURE       | XCB_EVENT_MASK_BUTTON_PRESS   |
                    XCB_EVENT_MASK_BUTTON_RELEASE | XCB_EVENT_MASK_POINTER_MOTION |
                    XCB_EVENT_MASK_ENTER_WINDOW   | XCB_EVENT_MASK_LEAVE_WINDOW   |
                    XCB_EVENT_MASK_KEY_PRESS      | XCB_EVENT_MASK_KEY_RELEASE;
        
                    //Creates the window
        xcb_create_window(connection, screen->root_depth, window, screen->root,
                          0, 0, width, height, 1,
                          XCB_WINDOW_CLASS_INPUT_OUTPUT, screen->root_visual,
                          mask, values);
        
    xcb_map_window(connection, window);
 
    xcb_flush(connection);
}


void WindowImpl::show()
{
}

void WindowImpl::dispatch(xcb_generic_event_t* ev)
{
  
}
