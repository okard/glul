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
#include "WindowImpl.hpp"
#include "WindowClass.hpp"

#include <glul/EventLoop>

using namespace glul;

/**
* \brief initialize
*/
void WindowImpl::initialize(const char* title, int width, int height)
{
    //Create Window
    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        WindowClass::getSingleton().getClassName(),
        title,
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, width, height,
        NULL, NULL, EventLoopPtr->winInstance(), NULL);
        
    //set user defined pointer to top level window class
    SetWindowLongPtr(hwnd, GWL_USERDATA, (LONG_PTR)&self);

    //Show Window
    ShowWindow(hwnd, SW_SHOW);
    UpdateWindow(hwnd);
}
  
/**
* \brief show
*/
void WindowImpl::show()
{
    ShowWindow(hwnd, SW_SHOW);
}
        
/**
* get window height
*/
int WindowImpl::getHeight()
{
    
}
     
/**
* get window width
*/
int WindowImpl::getWidth()
{
}
   
/**
* get xlib Window
*/
HWND WindowImpl::winWindow()
{
      return hwnd;
}
        
/**
* \brief WndProc        
*/
LRESULT CALLBACK WindowImpl::WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    //Cast back user defined pointer to window class
    Window* window = (Window*)GetWindowLongPtr(hwnd, GWL_USERDATA);

    //dispatch events
    switch(msg)
    {
        case WM_PAINT:
            window->OnPaint();
        break;
        
        case WM_SIZE:
            window->OnResize(LOWORD(lParam), HIWORD(lParam));
        break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
        break;
        
        case WM_DESTROY:
            PostQuitMessage(0);
        break;
        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}