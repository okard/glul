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
#ifndef __EVENTLOOP_H__
#define __EVENTLOOP_H__

/*
* Include Platform Implementation
*/
#ifdef WIN32
  #include "win/EventLoopImpl.hpp"
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
 