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
#ifndef __EVENTLOOPIMPL_H__
#define __EVENTLOOPIMPL_H__

#include <xcb/xcb.h>

#include "../Self.hpp"

namespace glul {
    
class EventLoop;

/**
* XCB Event Loop Impl
*/
class EventLoopImpl :  public Self<EventLoop>
{
    using Self<EventLoop>::self;
        
  private:
    //XCB Variables
    
    /// the xcb connection
    xcb_connection_t*    connection;

    /// the xcb screen
    xcb_screen_t*        screen;
    
    /// generic xcb event
    xcb_generic_event_t* event;
    
  public:
    /**
    * Constructor
    */
    EventLoopImpl();
    
    /**
    * Destructor
    */
    ~EventLoopImpl();
    
    /**
    * \brief get a new event
    */
    bool getEvent();
        
    /**
    * \brief peek a new event
    */
    bool peekEvent();

    /**
    * \brief dispatch events
    */
    bool dispatch();
    
    /**
    * XCB Specific: get xcb connection
    */
    xcb_connection_t* xcbConnection();
    
    /**
    * XCB Specific: get xcb screen
    */
    xcb_screen_t* xcbScreen();
    
    
  private:
    /**
    * Initialize XCB event loop
    */
    void init();
    
    /**
    * Dispose event loop
    */
    void dispose();
};

} //end namespace glul

#endif /* __EVENTLOOPIMPL_H__ */
