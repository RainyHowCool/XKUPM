/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00
 *  PMIO(Basic Package Manager I/O Control)
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

#ifndef PMIO_H
    #define PMIO_H
#endif

#include <stdio.h>
#include "xkstring.h"
#include "modules/TextAttributes.h"

namespace pmio{
    static const char endl = '\n';
    static FILE* object = stdout; // output object(SCREEN DISPLAY)
    static bool isPutting = false; // Rewrite anything about it in future
    /* 39~66 Some output functions, what can i say?*/
    inline void putn(xkstring str){
        fprintf(object,"%s",str.cstr());
    }
    inline void putn(const char* str){
        fprintf(object,"%s",str);
    }
    inline void putn(char* str){
        fprintf(object,"%s",str);
    }
    inline void putn(char chr){
        fprintf(object,"%c",chr);
    }
    inline void putn(int num){
        fprintf(object,"%d",num);
    }

    inline void putn(float num){
        fprintf(object,"%f",num);
    }
    inline void putn(double num){
        fprintf(object,"%f",num);
    }
    inline void putn(long unsigned int num){
        fprintf(object,"%lu",num);
    }
    inline void putn(long long unsigned int num){
        fprintf(object,"%llu",num);
    }

    class PutStr {
    public:
        template<typename T>
        PutStr& operator<<(T obj) {
            object = stdout;
            putn(obj);  // output once
            return *this;
        }
    };

    class PutErrorStr {
    public:
        PutErrorStr& operator<<(char obj) { //Special execution,Rewrite it in future pls
            if(!isPutting){
                object = stderr;
                TextColor.red(); // Text v
                TextAttribute.bold(); // Attributes
                putn("ERROR: ");
                textAttr_reset();
            }
            isPutting = true;
            putn(obj);
            if(obj == endl) isPutting = false;
            return *this;
        }
        template<typename T>
        PutErrorStr& operator<<(T obj) {
            if(!isPutting){
                object = stderr;
                TextColor.red(); // Text v
                TextAttribute.bold(); // Attributes
                putn("ERROR: "); // Error header
                textAttr_reset();
            }
            isPutting = true;
            putn(obj);
            return *this;
        }
    };
    class PutInfoStr {
    public:
        PutInfoStr& operator<<(char obj) { // Special, too.
            if(!isPutting){
                object = stdout;
                TextColor.cyan(); // Text v
                TextAttribute.bold(); // Attributes
                putn("INFO:  ");
                textAttr_reset();
            }
            isPutting = true;
            putn(obj);
            if(obj == endl) isPutting = false;
            return *this;
        }
        template<typename T>
        PutInfoStr& operator<<(T obj) {
            if(!isPutting){
                object = stdout;
                TextColor.cyan(); // Text v
                TextAttribute.bold(); // Attributes
                putn("INFO:  ");
                textAttr_reset();
            }
            isPutting = true;
            putn(obj);
            return *this;
        }
    };

    static PutStr put;
    static PutErrorStr perr;
    static PutInfoStr pinfo;
}