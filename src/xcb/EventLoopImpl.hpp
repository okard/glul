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

#ifndef __EVENTLOOPIMPL_H__
#define __EVENTLOOPIMPL_H__

#include <xcb/xcb.h>

#include "base/EventLoopBase.hpp"

/**
* XCB Event Loop Impl
*/
class EventLoopImpl : public EventLoopBase
{
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

#endif /* __EVENTLOOPIMPL_H__ */
