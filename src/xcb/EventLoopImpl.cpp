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
#include "EventLoopImpl.hpp"

#include "../EventLoop.hpp"
#include "../Window.hpp"
#include "../Exception.hpp"

using namespace glul;

/**
* Constructor
*/
EventLoopImpl::EventLoopImpl()  
    : connection(0), screen(0), event(0)
{
   init();
}
    
/**
* Destructor
*/
EventLoopImpl::~EventLoopImpl()
{
   dispose();
}
   
/**
* \brief get a new event
*/
bool EventLoopImpl::getEvent()
{
   return self.running && (event = xcb_wait_for_event(connection));
}
        
/**
* \brief peek a new event
*/
bool EventLoopImpl::peekEvent()
{
    //wrong?
    return self.running && (event = xcb_poll_for_event(connection));
}

/**
* \brief dispatch events
*/
bool EventLoopImpl::dispatch()
{
    //dispatch to Window here
    glul::Window::dispatch(event);
   
    delete event;
    event = 0;
}

/**
* XCB Specific: get xcb connection
*/
xcb_connection_t* EventLoopImpl::xcbConnection()
{
  return this->connection;
}
 
/**
* XCB Specific: get xcb screen
*/
xcb_screen_t* EventLoopImpl::xcbScreen()
{
  return this->screen;
}
      
/**
* Initialize XCB event loop
*/
void EventLoopImpl::init()
{
   //Initialize connection to xserver
   connection = xcb_connect(NULL, NULL);
   if (xcb_connection_has_error(connection))
   {
      //Error Handling
      //Log(LogType.Fatal, "Cannot open display");
      self.result = 1;
   }
     
   /* get the first screen */
   screen = xcb_setup_roots_iterator( xcb_get_setup(connection) ).data;
}
    
/**
* Dispose event loop
*/
void EventLoopImpl::dispose()
{
    xcb_disconnect(connection);
}