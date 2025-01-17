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
#include <sys/types.h>
#include <sys/stat.h>

#include "pmio.h"
#include "message.h"
#include "modules/web/Downloader.h"
#include "modules/archive/Extract.h"
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
    char *fileFullName = (char*)malloc(31); // strlen(tempDirectoryName) + strlen("/binary.xpz") + 1 always is 31
    sprintf(fileFullName, "%s/binary.xpz", tempDirectoryName);
    int downloadStatus = downloadFile(toStr(url), toStr(fileFullName)); // I hate xkstring!!!!!!!!
    // 4. Check are done
    if(downloadStatus == -1){
        perr << "Cannot download package. Installion stopped with code -1." << endl;
        rmdir(tempDirectoryName); // Clean temp directory
        exit(-1);
    }
    return strdup(tempDirectoryName);
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

    mkdir("files", S_IRWXU | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH); // Create directory for extracted files, Mode755

    int downloadFileNameLength = strlen(tempDirectoryName) + 1 + strlen("binary.xpz") + 1;
    char* downloadFileName = (char*) malloc(downloadFileNameLength);
    sprintf(downloadFileName, "%s/binary.xpz", tempDirectoryName);

    int extractPathLength = strlen(tempDirectoryName) + strlen("/files") + 1;
    char* extractPath = (char*) malloc(extractPathLength);
    sprintf(extractPath, "%s/files", tempDirectoryName);

    extractArchive(toStr(downloadFileName), toStr(extractPath));
    // 4. Install
    chmod("./files/install.sh", 777); // Write + Read + Execute Premissions
    int errorLevel = system("cd files && sudo ./install.sh"); // Execute install script with root

    if(errorLevel != 0){
        perr << "Installation failed!" << endl;
        system("cd files && sudo ./remove.sh"); // Uninstall program
        pinfo << "Remove finished!" << endl;
        chdir("/");
        rmdir(tempDirectoryName); // Remove temp directory
        exit(-1);
    }
    // 5. Register Remove Information
    int copyCommandLength = strlen("cp ./files/remove.sh ~/.xkupm/removes/.sh"); + strlen(packageName) + 1;
    char* copyCommand = (char*) malloc(copyCommandLength);
    sprintf(copyCommand, "cp ./files/remove.sh ~/.xkupm/removes/%s.sh", packageName);
    system(copyCommand); // copy remove scripts to removes directory
    // 6. Clean
    chdir("/");
    rmdir(tempDirectoryName); // Remove temp directory
    pinfo << "Install finished!" << endl;
}

void removePackage(char* packageName){
    int removeScriptFullNameLength = strlen("~/.xkupm/removes/.sh") + strlen(packageName) + 1;
    char* removeScriptFullName = (char*) malloc(removeScriptFullNameLength);
    sprintf(removeScriptFullName, "~/.xkupm/removes/%s.sh", packageName);

    chmod(expanduser(removeScriptFullName), 777); // Mode 777

    int removeCommandLength = strlen("sudo ") + strlen(removeScriptFullName) + 1;
    char* removeCommand = (char*) malloc(removeCommandLength);
    sprintf(removeCommand, "sudo %s", removeCommand);

    int errorLevel = system(removeCommand); // Execute Command to remove
    put << "Remove finished!" << endl;
}

int main(int argc, char* argv[]){ // Entry point
    VersionInfo versionInfo;

    if(argc < 2){// No arguments
        put << versionInfo.getAsciiLogo() << endl;
        put << versionInfo.getVersionName() << endl;
        perr << "No input!" << endl;
        pinfo << "Try adding arguments 'help' to get help." << endl;
    }else if(!strcmp(argv[1], "help")){
        put << versionInfo.getAsciiLogo() << endl;
        put << versionInfo.getVersionName() << endl;
        msg::getHelp(); // Output help message
    }else if(!strcmp(argv[1], "install")){
        installPackage(argv[2]); // Install Package
    }else if(!strcmp(argv[1], "remove")){
        removePackage(argv[2]);
    }else{ // Unknown Option
        perr << "Unknown Option " << argv[1] << "!" << endl;
        pinfo << "Try adding arguments 'help' to get help." << endl;
    }
}
