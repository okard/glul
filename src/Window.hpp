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
#ifndef __WINDOW_H__
#define __WINDOW_H__

/*
* Include Platform Implementation
*/
#ifdef WIN32
  #include "win32/WindowImpl.hpp"
#else
  #include "xlib/WindowImpl.hpp"
#endif

#include "WindowEvent.hpp"

namespace glul
{
    
/**
* Window Class
*/
class Window : public WindowImpl
{
    //friend to allow private access
    friend class WindowImpl;
    
    private:
        WindowEventHandler* eventHandler;
        
    public:
        Window();
        Window(const char* title, int width, int height);
        ~Window();
        
        /**
        * set event handler
        */
        void setEventHandler(WindowEventHandler* handler);
        
        /**
        * get event handler
        */
        WindowEventHandler* getEventHandler();
};

} //end namespace glul

#endif /* __WINDOW_H__ */
