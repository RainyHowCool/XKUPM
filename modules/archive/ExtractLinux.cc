/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00 BUILD 20250117
 *  tar Extract Module(for Linux)
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

#include "pmio.h"
using pmio::perr;
using pmio::endl;

int extractArchiveLinux(xkstring fileName, xkstring extractPath)
{
    int commandLength = strlen("tar -xzf  -C ") + fileName.length() + extractPath.length(); // Get string length for alloc
    char* command = (char*)malloc(commandLength); // Alloc Memory space

    int errorLevel = system(command);

    if(errorLevel != 0){ // Whoa! Extract error!
        return -1;
    }
    return 0;
}
