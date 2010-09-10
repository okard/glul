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

#ifndef __WINDOWIMPL_H__
#define __WINDOWIMPL_H__

#include "base/WindowBase.hpp"


#include <X11/Xlib.h>


/**
* \brief XLIB Window Implementation
*/
class WindowImpl : public WindowBase
{
  private:
      ///Window
      ::Window window;
  
  protected:
      /**
      * \brief initialize
      */
      void initialize(const char* title, int width, int height);
  
  public:
      /**
      * \brief show
      */
      void show();
    
      /**
      * \brief dispatch
      */
      static void dispatch(XEvent& event);
};

#endif /* __WINDOWIMPL_H__ */