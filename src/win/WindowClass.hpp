/*
OpenGL Utility Library

Copyright (c) 2010 okard

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
#ifndef __WINDOWCLASS_HPP__
#define __WINDOWCLASS_HPP__

#include <glul/EventLoop>
#include <glul/Window>

#include <windows.h>

//http://www.winprog.org/tutorial/simple_window.html

namespace glul {

class WindowClass
{
    private:
        WNDCLASSEX wc;

        const char* winClassName;

    private:
        WindowClass()
            : winClassName("glulWindowClass")
        {
            wc.cbSize        = sizeof(WNDCLASSEX);
            wc.style         = 0;
            wc.lpfnWndProc   = Window::WndProc;
            wc.cbClsExtra    = 0;
            wc.cbWndExtra    = 0;
            wc.hInstance     = EventLoop::getSingleton().winInstance();
            wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
            wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
            wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
            wc.lpszMenuName  = NULL;
            wc.lpszClassName = winClassName;
            wc.hIconSm       = LoadIcon(NULL, IDI_APPLICATION);

            if(!RegisterClassEx(&wc))
            {
                MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
            }
        }
        
        WindowClass(const WindowClass& wc)
        {
        }
    
    public:
        
        const char* getClassName() const
        {
            return winClassName;
        }
    
        static const WindowClass& getSingleton()
        {
            static WindowClass winclass;
            return winclass;
        }

};

} //end namespace glul


#endif /* __WINDOWCLASS_HPP__ */