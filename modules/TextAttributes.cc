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

#include <stdio.h>
#include "modules/TextAttributes.h"

void _flush(){ //刷新缓冲区
    fflush(stdout);
    fflush(stderr);
}
// g_TextColor class : Change text color
void g_TextColor::black(){
    printf("\e[0;30m");
    _flush();
}
void g_TextColor::red(){
    printf("\033[31m");
    _flush();
}
void g_TextColor::green(){
    printf("\e[0;32m");
    _flush();
}
void g_TextColor::brown(){
    printf("\e[0;33m");
    _flush();
}
void g_TextColor::yellow(){
    printf("\e[1;33m");
    _flush();
}
void g_TextColor::blue(){
    printf("\e[0;34m");
    _flush();
}
void g_TextColor::purple(){
    printf("\e[0;35m");
    _flush();
}
void g_TextColor::cyan(){
    printf("\e[0;36m");
    _flush();
}
void g_TextColor::gray(){
    printf("\e[0;37m");
    _flush();
}
void g_TextColor::white(){
    printf("\e[1;37m");
    _flush();
}
void g_TextColor::lightBlack(){
    printf("\e[1;30m");
    _flush();
}
void g_TextColor::lightRed(){
    printf("\e[1;31m");
    _flush();
}
void g_TextColor::lightGreen(){
    printf("\e[1;32m");
    _flush();
}
void g_TextColor::lightBlue(){
    printf("\e[1;34m");
    _flush();
}
void g_TextColor::lightPurple(){
    printf("\e[1;35m");
    _flush();
}
void g_TextColor::lightCyan(){
    printf("\e[1;36m");
    _flush();
}

// g_TextAttribute : change Text Extra Attributes
void g_TextAttribute::bold(){
    printf("\e[1m");
    _flush();
}
void g_TextAttribute::underline(){
    printf("\e[4m");
    _flush();
}
void g_TextAttribute::blink(){
    printf("\e[5m");
    _flush();
}
void g_TextAttribute::hide(){
    printf("\e[8m");
    _flush();
}
void g_TextAttribute::clear(){
    printf("\e[2J");
    _flush();
}

void textAttr_reset(){ // reset text attributes
    printf("\033[0m");
    _flush();
}