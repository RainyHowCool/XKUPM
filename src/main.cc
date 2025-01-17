/*
 *  __  __  _  __  _   _   ____    __  __ 
 *  \ \/ / | |/ / | | | | |  _ \  |  \/  |
 *   \  /  | ' /  | | | | | |_) | | |\/| |
 *   /  \  | . \  | |_| | |  __/  | |  | |
 *  /_/\_\ |_|\_\  \___/  |_|     |_|  |_|
 *  
 *  XKUPM VERSION 1.00 BUILD 20250107
 *  Entry Point Function
 *  2025 @小块SIXTEEN
 *  Copyright 2025 xiaokuai(@小块SIXTEEN)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *      http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <unistd.h>

#include "pmio.h"
#include "message.h"
#include "modules/web/Downloader.h"
#include "utils.h"

using pmio::put;
using pmio::endl;
using pmio::perr;
using pmio::pinfo;

class VersionInfo{
public:
    xkstring getVersionName(){
        return _versionName;
    }

    int getVersion(){
        return _version;
    }

    xkstring getAsciiLogo(){
        return _asciiLogo;
    }
    
    xkstring _getCodeName(){
        return _codeName;
    }
private:
    xkstring _versionName = "XKUPM VERSION BUILD 20250107";
    const int _version = 1.0;
    xkstring _codeName = "Jelly Cake";
    xkstring _asciiLogo = "__  __  _  __  _   _   ____    __  __\n\\ \\/ / | |/ / | | | | |  _ \\  |  \\/  |\n \\  /  | ' /  | | | | | |_) | | |\\/| |\n /  \\  | . \\  | |_| | |  __/  | |  | |\n/_/\\_\\ |_|\\_\\  \\___/  |_|     |_|  |_|\n";

};

char* downloadPackage(char* packageName){
    // 1. Make URL
    xkstring repoUrl = getDownloadSource();
    char* url = (char*)malloc(repoUrl.length() + 1 + strlen(packageName) + 1 + strlen(REPO_EXTS) + strlen("/binary.xpz") + 1);
    sprintf(url, "%s/%s-%s/binary.xpz",repoUrl.cstr(),packageName,REPO_EXTS);
    // 2. Create Work Directory
    char directoryTemplate[] = "/tmp/upmDirXXXXXX";
    char *tempDirectoryName = mkdtemp(directoryTemplate);
    // 3. Download Package
    char *fileFullName = (char*)malloc(strlen(tempDirectoryName) + strlen("/binary.xpz") + 1);
    int downloadStatus = downloadFile(url, fileFullName);
    // 4. Check are done
    if(downloadStatus == -1){
        perr << "Cannot download package. Installion stopped with code -1." << endl;
        rmdir(tempDirectoryName); // Clean temp directory
        exit(-1);
    }
    return packageName;
}

void installPackage(char* packageName){
    // 1. Prepareing Installion
    put << "Repository URL: " << getDownloadSource() << endl; // output repository path
    put << "Downloading file...";
    // 2. Download Package
    char* tempDirectoryName = downloadPackage(packageName); // download it
    put << "\tDone" << endl;
    // 3. Prepare to install
    chdir(tempDirectoryName); // Change working dir to Temp Directory for Installation
}

int main(int argc, char* argv[]){ // Entry point
    VersionInfo versionInfo;
    put << versionInfo.getAsciiLogo() << endl;
    put << versionInfo.getVersionName() << endl;
    if(argc < 2){// No arguments
        perr << "No input!" << endl;
        pinfo << "Try adding arguments 'help' to get help." << endl;
    }else{
        if(!strcmp(argv[1], "help")){
            msg::getHelp(); // Output help message
        }else if(!strcmp(argv[1], "install")){
            installPackage(argv[2]); // Install Package
        }else{ // Unknown Option
            perr << "Unknown Option " << argv[1] << "!" << endl;
            pinfo << "Try adding arguments 'help' to get help." << endl;
        }
    }
}
