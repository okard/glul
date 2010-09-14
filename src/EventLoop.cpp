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
#include "EventLoop.hpp"

using namespace glul;

// The EventLoop Instance
EventLoop* EventLoop::instance = new EventLoop();

/**
* Constructor
*/
EventLoop::EventLoop()
{
}

/**
* Private copy constructor
*/
EventLoop::EventLoop(const EventLoop& el)
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
* run event loop
*/
int EventLoop::run()
{
    while(getEvent())
    {
        dispatch();
    }
    return result;
}

/**
* exit event loop
*/
void EventLoop::exit(int result)
{
  running = false;
  this->result = result;
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



