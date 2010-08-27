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

#include "EventLoop.hpp"

EventLoop* EventLoop::instance = new EventLoop();

/**
* Constructor
*/
EventLoop::EventLoop() : EventLoopImpl(this), result(0)
{
}

/**
* Destructor
*/
EventLoop::~EventLoop()
{

}

/**
* \brief get a new event
*/
bool EventLoop::getEvent()
{
  return EventLoopImpl::getEvent();
}

/**
* \brief peek a new event
*/
bool EventLoop::peekEvent()
{
  return EventLoopImpl::peekEvent();
}

/**
* \brief dispatch events
*/
bool EventLoop::dispatch()
{
  return EventLoopImpl::dispatch();
}
 
/**
* get singelton instance
*/
EventLoop& EventLoop::getSingleton()
{
    return *instance;
}

/**
* get singleton pointer
*/
EventLoop* EventLoop::getSingletonPtr()
{
    return instance;
}

/**
* run event loop
*/
int EventLoop::run()
{
    while(getEvent())
    {
        dispatch();
    }
}
