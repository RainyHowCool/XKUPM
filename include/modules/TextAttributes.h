/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00
 *  Text Colors Module
 *  2025 @小块SIXTEEN
 *  Copyright 2025 xiaokuai(@小块SIXTEEN)
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */

#ifndef TEXTATTRIBUTES_H
    #define TEXTATTRIBUTES_H
#endif

class g_TextColor{ // g_TextColor class : Change text color
public:
    void black();
    void red();
    void green();
    void brown();
    void yellow();
    void blue();
    void purple();
    void cyan();
    void gray();
    void white();
    void lightBlack();
    void lightRed();
    void lightGreen();
    void lightBlue();
    void lightPurple();
    void lightCyan();
};

class g_TextAttribute{ // g_TextAttribute : change Text Extra Attributes
public:
    void bold();
    void underline();
    void blink();
    void hide();
    void clear();
};

void textAttr_reset(); // reset text attributes

static g_TextColor TextColor;
static g_TextAttribute TextAttribute;