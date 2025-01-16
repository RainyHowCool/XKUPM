/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00
 *  xkstring
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

#include <stdlib.h>
#include <string.h>
#include "xkstring.h"

/*
 * XKString Class
 * -- Custom C++ String class like std::string --
 * Usage: xkstring str1 = "Hello, World";
 * Convert to const char*(C Style): const char* str2 = str1.cstr();
 * Get string length: size_t len = str1.length();
 * 
 * IMPORTANT WARNING: DON'T USE FUNCTION 'append()' AND FUNTION 'join()'
 * BECAUSE IT WILL MAKE SEGMENTATION FAULT AND CRASHED. NOBOBY LIKE IT!!
 */

xkstring::xkstring(const char* string){
    _stringBuffer = (char*)malloc(strlen(string));
    _stringBuffer = (char*)string;
}
xkstring::xkstring(){
    _stringBuffer = (char*)calloc(4096,4096); // Empty
}
const char* xkstring::cstr(){
    return (const char*)_stringBuffer;
}
size_t xkstring::length(){
    return strlen(_stringBuffer);
}
void xkstring::append(char chr){ // DON'T USE
    _stringBuffer[strlen(_stringBuffer) + 1] = chr;
}
void xkstring::join(xkstring str){ // DON'T USE
    strcat(_stringBuffer, str.cstr());
}
void xkstring::join(const char* str){ // DON'T USE
    strcat(_stringBuffer, str);
}

xkstring emptyStr(){ // Produce a Empty xkstring object, like its name
    xkstring ret = "";
    return ret;
}

xkstring toStr(const char* str){ // Convert const char* to xkstring object
    xkstring returnObject = str;
    return returnObject;
}