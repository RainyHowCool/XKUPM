/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00 BUILD 20250117
 *  Web File Downloader Module(for Linux)
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
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>
#include <errno.h>
#include "pmio.h"

int downloadFileLinux(xkstring url, xkstring path){
    size_t commandLength = strlen("wget -O \"\" \"\"  > /dev/null 2>&1") + strlen(path.cstr()) + strlen(url.cstr()) + 1; // get url length
    char* command = (char*) malloc(commandLength * sizeof(char)); // create varible and malloc memory space
    sprintf(command, "wget -O \"%s\" \"%s\" > /dev/null 2>&1",path.cstr(),url.cstr()); // Make Command
    system(command); // Download it based wget
    struct stat buffer; // Just a buffer
    if(stat(path.cstr(), &buffer) == -1 && errno == ENOENT){ // File not found,FIXED
        pmio::perr << "Cannot access file " << path.cstr() << ".Press any key to continue." << pmio::endl; // output error message
        getchar(); // Pause
        return -1; // return code -1
    }
    return 0; // Normal return
}
