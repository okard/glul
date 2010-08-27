/*
    OpenGL Utility Library
    Copyright (C) 2010  okard

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

/*
* Include Platform Implementation
*/
#ifdef WIN32
  #include "win32/WindowImpl.hpp"
#else
  #include "xcb/WindowImpl.hpp"
#endif

/**
* Window Class
*/
class Window : public WindowImpl
{
  private:
    
  public:
    Window();
    Window(const char* title, int width, int height);
    ~Window();
    
};


#endif /* __WINDOW_H__ */