/*
    OpenGL Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include "WindowImpl.hpp"

#include "EventLoop.hpp"

void WindowImpl::initialize(const char* title, int width, int height)
{
        xcb_connection_t* connection = EventLoopPtr->xcbConnection();
        xcb_screen_t* screen = EventLoopPtr->xcbScreen();
        
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
