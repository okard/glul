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


/**
* XCB Event Loop Impl
*/
template <class T>
class EventLoopImpl
{
  private:
    /// pointer to root instance
    T* eventlp;
    
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
    EventLoopImpl(T* eventlp)  : eventlp(eventlp), connection(0), screen(0), event(0)
    {
      init();
    }
    
    /**
    * Destructor
    */
    ~EventLoopImpl()
    {
      dispose();
    }
    
    /**
    * \brief get a new event
    */
    bool getEvent()
    {
        event = xcb_wait_for_event(connection);
    }
        
    /**
    * \brief peek a new event
    */
    bool peekEvent()
    {
        //wrong?
        event = xcb_poll_for_event(connection);
    }

    /**
    * \brief dispatch events
    */
    bool dispatch()
    {
        //dispatch to Window here
      
        delete event;
        event = 0;
    }
      
    
  private:
    /**
    * Initialize XCB event loop
    */
    void init()
    {
        //Initialize connection to xserver
        connection = xcb_connect(NULL, NULL);
        if (xcb_connection_has_error(connection)) 
        {
          //Error Handling
          //Log(LogType.Fatal, "Cannot open display");
          eventlp->result = 1;
        }
        
        /* get the first screen */
        screen = xcb_setup_roots_iterator( xcb_get_setup(connection) ).data;
    }
    
    /**
    * Dispose event loop
    */
    void dispose()
    {
        xcb_disconnect(connection);
    }
};

#endif /* __EVENTLOOPIMPL_H__ */