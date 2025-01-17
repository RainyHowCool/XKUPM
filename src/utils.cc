/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00 BUILD 20250107
 *  Utils Header File
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

char* expanduser(const char* path) { //AIGC, Rewrite it in future.
    if (path[0] != '~') {
        return strdup(path);
    }

    const char* home = getenv("HOME");
    if (home == NULL) {
        fprintf(stderr, "HOME environment variable not set\n");
        exit(EXIT_FAILURE);
    }

    size_t home_len = strlen(home);
    size_t path_len = strlen(path);
    char* expanded_path = (char*)malloc(home_len + path_len - 1 + 1); // -1 for '~', +1 for '\0'
    if (expanded_path == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    strcpy(expanded_path, home);
    strcpy(expanded_path + home_len, path + 1); // Skip the '~'

    return expanded_path;
}

char* getDownloadSource(){ // Get Download Repository URL
    FILE* fp = fopen(expanduser("~/.xkupm/source.ini"),"r"); // Create File Pointer
    if(fp == NULL){ // If open file failed
        pmio::perr << "Cannot open configation file!" << pmio::endl;  // Output error message
        exit(-1); // Exit with code -1
    }
    char buffer[256];
    int fileWriteIndex = fread(buffer, 1, sizeof(buffer) - 1, fp);
    buffer[fileWriteIndex] = '\0';  // String ended must is \0!
    for(int index = 0; index < fileWriteIndex; index++){
        if(buffer[index] == '\n') buffer[index] = '\0'; // Emm....I removed all '\n' because it is really in buffer
    }
    return strdup(buffer);
}