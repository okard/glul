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
#include <glul/Window.hpp>


//required because stupidity of xlib naming Window
namespace glul {

/**
* Constructor
*/
Window::Window()
{
  this-> initialize("GLUL", 800, 600);
}

/**
* Constructor
*/
Window::Window(const char* title, int width, int height)
{
  this-> initialize(title, width, height);
}

/**
* Destructor
*/
Window::~Window()
{
}

/**
* Paint Event
*/
void Window::OnPaint()
{
}
        
/**
* Resize Event
*/
void Window::OnResize(const Rect& rect)
{
}

/**
* Keydown Event
*/
void Window::OnKeyDown(const Keyboard& keyboard)
{
}

/**
* Keydown Event
*/
void Window::OnKeyUp(const Keyboard& keyboard)
{
}

/**
* Mouse Move
*/
void Window::OnMouseMove(const Mouse& mouse)
{
}

/**
* Mouse Button Down
*/
void Window::OnMouseButtonDown(const Mouse& mouse)
{
}

/**
* Mouse Button Up
*/
void Window::OnMouseButtonUp(const Mouse& mouse)
{
}
	

} //end namespace glul