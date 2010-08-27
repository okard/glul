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

#ifndef __WINDOWIMPL_H__
#define __WINDOWIMPL_H__

#include <xcb/xcb.h>

#include "base/WindowBase.hpp"

/**
* \brief XCB Window Implementation
*/
class WindowImpl : public WindowBase
{
  private:
    xcb_window_t        window; //window
    xcb_gcontext_t      gc; //graphic context
    uint32_t            mask; //mask for values               
    uint32_t            values[2]; //parameter values 
  
  protected:
    void initialize(const char* title, int width, int height);
  
  public:
    void show();
    
    
    static void dispatch(xcb_generic_event_t* ev);
};

#endif /* __WINDOWIMPL_H__ */
