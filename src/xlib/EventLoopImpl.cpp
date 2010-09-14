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

#include "EventLoopImpl.hpp"

#include <glul/EventLoop>
#include <glul/Window>

using namespace glul;


/**
* Constructor
*/
EventLoopImpl::EventLoopImpl()
{
    //Connect to X Server Display
    display = XOpenDisplay(NULL);
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
}
        
/**
* \brief peek a new event
*/
bool EventLoopImpl::peekEvent()
{
    XPeekEvent(display, &event);
}

/**
* \brief dispatch events
*/
bool EventLoopImpl::dispatch()
{
    Window::dispatch(event);
    
    return true;
}

/**
* Get Xlib Display
*/
Display* EventLoopImpl::xlibDisplay()
{
    return display;
}
