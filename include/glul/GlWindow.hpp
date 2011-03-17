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
#ifndef __GLWINDOW_HPP__
#define __GLWINDOW_HPP__

#include "Types.hpp"
#include "Window.hpp"
#include "GlContext.hpp"

namespace glul {

/**
* A basis OpenGL Window
*/
class GlWindow : public Window
{
    private:
        ///OpenGL Context
        GlContext glContext;
    
    public:
        /**
        * Constructor
        */
        GlWindow(const char* title, int width, int height);
        
        /**
        * Destructor
        */
        ~GlWindow();
        
        /**
        * OpenGL Initialize
        */
        virtual void OnInitialize();
        
        /**
        * OpenGL Render Function
        */
        virtual void OnRender();
        
         /**
        * Paint Event
        */
        virtual void OnPaint();
        
        /**
        * Resize Event
        */
        virtual void OnResize(const Rect& rect);
        
        /**
        * get Gl Context
        */
        GlContext& getContext();
};

} //end namespace glul


#endif /* __GLWINDOW_HPP__ */
