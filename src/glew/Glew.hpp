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
#ifndef __GLEW_HPP__
#define __GLEW_HPP__

#include "glew.h"
#include <cstdio>

namespace glul {

/**
* Glew Helper
*/
class GlewHelper
{
private:
    ///private constructor because of singleton
    GlewHelper();
    
    ///private copy constructor because of singleton
    GlewHelper(const GlewHelper& g);
    
    ///is glew initialized
    bool initialized;
public:  
    /**
    * Is glew ready?
    */
    bool ready();
    
    /**
    * try to init
    */
    void init();
    
    /**
    * get singleton
    */
    static GlewHelper& getSingleton();
};

///definition for faster glew helper access
static GlewHelper& Glew = GlewHelper::getSingleton();

} //end namespace glul

#endif /* __GLEW_HPP__ */