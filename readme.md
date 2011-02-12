OpenGL Utility Library 
====================

Abstract some basics for OpenGL on different platforms.

Design Principles
--------------------------
* KISS - Keep it small and simple
* Lightweight
* Cross Platform (currently aiming for linux/posix and windows, no  MacOS X support beacuse i have no mac)
* Documentation - Try to provide well documented code

Features
--------------------------
* Event/Message Loop Handling
* OpenGL Window
* Input Handling
* Xlib/Win32 Backend
  

TODOs
--------------------------
* Finish working input handling
* Add support for joysticks, gamepads, ... 
* Add support for XInput(2) 
* Update XCB Implementation
  It seems XCB can support OpenGL now [XCB GLX](http://xcb.freedesktop.org/manual/group__XCB__Glx__API.html)
* DirectInput Support for Windows
* Handling multiple input devices (mouse, keyboard, ...)


