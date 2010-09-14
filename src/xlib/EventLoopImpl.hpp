/*
    OpenGL Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/ 

#ifndef __EVENTLOOPIMPL_H__
#define __EVENTLOOPIMPL_H__

//Xlib Includes
#include <X11/Xlib.h>
#include <X11/Xutil.h>

#include "Self.hpp"

namespace glul {
    
class EventLoop;

/**
* XLIB Event Loop Impl
*/
class EventLoopImpl : public Self<EventLoop>
{
    using Self<EventLoop>::self;
    
    private:
        ///Display
        Display *display;
    
        ///Event
        XEvent event;
    
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
        * \brief get xlib display
        */
        Display* xlibDisplay();
    
};

}//end namespace glul

#endif /* __EVENTLOOPIMPL_H__ */
