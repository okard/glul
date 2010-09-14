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

#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

/*
* Include Platform Implementation
*/
#ifdef WIN32
  #include "win32/EventLoopImpl.hpp"
#else
  #include "xlib/EventLoopImpl.hpp"
#endif

namespace glul {

/**
* Represents a game loop
*/
class EventLoop : public EventLoopImpl
{ 
    //friend class to access private member
    friend class EventLoopImpl;
    
    private:
        /// Event Loop Singleton
        static EventLoop* instance;
        
        /**
        * Private Constructor
        */
        EventLoop();
        
        /**
        * Private Copy Constructor
        */
        EventLoop(const EventLoop& el);

        /**
        * Destructor
        */
        ~EventLoop();
        
    protected:
        /// the result of event loop
        int result;
        
        /// event loop is currently running
        bool running;
    
    public:  
        
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
        * \brief Run event loop
        */
        int run();
        
        /**
        * Exit event loop
        */
        void exit(int result);

        /**
        * \brief get singleton instance
        */
        static EventLoop& getSingleton();

        /**
        * \brief get singleton pointer
        */
        static EventLoop* getSingletonPtr();
};

/**
* Shortcut define to access event loop instance 
*/
#define EventLoopPtr EventLoop::getSingletonPtr() 

};


#endif /* __EVENTLOOP_H__ */
 