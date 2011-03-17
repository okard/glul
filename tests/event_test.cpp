/*
    OpenGL Utility Library

    Copyright (c) 2011 okard

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

#include<iostream>

#include <glul/EventLoop.hpp>
#include <glul/GlWindow.hpp>
#include <glul/GlContext.hpp>

using namespace glul;

/**
* Test Class
*/
class glWindow : public glul::GlWindow
{
public:
    /**
    * Constructor
    */
    glWindow()
        : GlWindow("glul", 800, 600)
    {
    }
    
    /**
    * Keyboard Key Down Event
    */
    virtual void OnKeyDown(const glul::Keyboard& keyboard)
    {
        std::cout << "Key Down" << std::endl;
    }
    
    
    /**
    * Keyboard Key Up Event
    */
    virtual void OnKeyUp(const glul::Keyboard& keyboard)
    {
        std::cout << "Key Up" << std::endl;
        
        if(keyboard.isKeyDown(Keyboard::KEY_RETURN))
        {
        }
    }
    
    /**
    * OpenGL Render Function
    */
    virtual void OnRender()
    {
        // Clear The Screen And The Depth Buffer
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);      
        glLoadIdentity();
        
        glBegin(GL_TRIANGLES);
            glColor3f(1, 0, 0);
            glVertex3f( 0.0f, 1.0f, 0.0f);              // Top
            glColor3f(0, 1, 0);
            glVertex3f(-1.0f,-1.0f, 0.0f);              // Bottom Left
            glColor3f(0, 0, 1);
            glVertex3f( 1.0f,-1.0f, 0.0f);              // Bottom Right
        glEnd();
    }
    
};


/**
* Main Method
*/
int main(int argc, char *argv[])
{
    glWindow win;
    win.show();
  
    return glul::EventLoopPtr->run();
}
 