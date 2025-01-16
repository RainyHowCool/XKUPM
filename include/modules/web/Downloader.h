/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00
 *  Web File Downloader
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

#ifndef DOWNLOADER_H
    #define DOWNLOADER_H
#endif

#ifndef XKSTRING_H
    #include "xkstring.h"
#endif

#if defined (__linux__) // If OS is linux
    int downloadFileLinux(xkstring url, xkstring path);
    #define downloadFile downloadFileLinux // used linux downloadFile function 
#elif defined (_WIN32)
    #error Windows Downloader coming soon! // coming soon!
#else
    #error Unsupported System!
#endif