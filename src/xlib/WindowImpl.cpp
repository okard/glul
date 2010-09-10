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

#include "WindowImpl.hpp"



#include <glul/EventLoop>


void WindowImpl::initialize(const char* title, int width, int height)
{
    Display* dis = glul::EventLoopPtr->xlibDisplay();
    int screen = DefaultScreen(dis);
    window = XCreateSimpleWindow(dis, RootWindow(dis, screen), 1, 1, 500, 500, 0, BlackPixel (dis, screen), BlackPixel(dis, screen));

    XMapWindow(dis, window);
    XFlush(dis);
}
  
void WindowImpl::show()
{
}
    
    
void WindowImpl::dispatch(XEvent& event)
{
}