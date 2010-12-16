/*
OpenGL Utility Library

Copyright (c) 2010 okard

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
#ifndef __KEYBOARD_HPP__
#define __KEYBOARD_HPP__

namespace glul {

/**
* Keyboard Class
*/
class Keyboard
{
public:
    //key enum
    enum Key 
    {
        //Alpha
        KEY_A = 1, KEY_B, KEY_C, KEY_D, KEY_E, KEY_F, KEY_G, KEY_H, KEY_I, KEY_K, KEY_L, KEY_M,
        KEY_N, KEY_O, KEY_P, KEY_Q, KEY_R, KEY_S, KEY_T, KEY_U, KEY_V, KEY_W, KEY_X, KEY_Y, KEY_Z,
        //NUM
        KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9, KEY_0
        //F Keys
        KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, KEY_F11, KEY_F12
        // Special Keys
        KEY_CTRL_L, KEY_CTRL_R, KEY_SHIFT_L, KEY_SHIFT_R, KEY_ALT_L, KEY_ALT_R,
        KEY_ENTER, KEY_RETURN, KEY_SPACE,
        
        NOKEY_MAX
    };
    
private:
    //internal keymap
    bool keymap[NOKEY_MAX];
    
public:
    
    bool isKeyDown(Key k) { return keymap[k]; }
    //bool isShiftLeft();
    //bool isShiftRight();
    
    bool ShiftR() { return keymap[KEY_SHIFT_L]; }
    bool ShiftR() { return keymap[KEY_SHIFT_R]; }
    bool ControlR() { return keymap[KEY_CTRL_R]; }
    bool ControlL() { return keymap[KEY_CTRL_L]; }
    bool AltL() { return keymap[KEY_ALT_L]; }
    bool AltR() { return keymap[KEY_ALT_R]; }
};

} //end namespace glul


#endif /* __KEYBOARD_HPP__ */