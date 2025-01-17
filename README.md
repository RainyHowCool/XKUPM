# XKUPM
**XKUPM** is means `XIAOKUAI Universal Package Manager`, but now it only supports `Linux Platform`.

# Open-Source LICENSE
**XKUPM** use `Apache 2.0 LICENSE`.
NOTICE:
>   Copyright 2025 xiaokuai(@小块SIXTEEN)
>
>   Licensed under the Apache License, Version 2.0 (the "License");
>   you may not use this file except in compliance with the License.
>   You may obtain a copy of the License at
>
>       http://www.apache.org/licenses/LICENSE-2.0
>
>   Unless required by applicable law or agreed to in writing, software
>   distributed under the License is distributed on an "AS IS" BASIS,
>   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
>   See the License for the specific language governing permissions and
>   limitations under the License.

# Ready to build(IMPORTANT!)
If you want to build **XKUPM**, You have to make sure that `GCC(GNU Compiler Collection)/G++`,`GNU Make` and `CMake` is installed correctly.
<br>
## Debian series
1. Update **apt** Repository indexes
<br>
    **sudo apt update**
<br>
3. Install **build-essential**
<br>
    **sudo apt install build-essential**
<br>
4. Install **cmake**
<br>
    **sudo apt install cmake**
## Arch series
1. Update Local package database
<br>
    **sudo pacman -Sy**
<br>
3. Install **base-devel**
<br>
    **sudo pacman -S base-devel**
<br>
5. Install **cmake**
<br>
    **sudo pacman -S cmake**

# How to build
--------------
## build.sh
If you want to build **XKUPM**, you can through `build.sh`(Recommend) 
<br>
`chmod +777 .\build.sh`
<br>
`.\build.sh`
<br><br>
## CMake & GNU Make
You not only can build it through `build.sh`, you also can build it through *CMake* and *Makefile*
<br>
`cmake`
<br>
`make`
# Run it
--------
`chmod +777 .\xkupm`
<br>
`.\xkupm help`
# Usage
-------
Usage: xkupm [options] command [packages]
<br>
Command Options:
<br>
    install [source/binary] - Install package.
<br>
    update - Update Indexes & Packages.
<br>
    find   - Find package in indexes
<br>
# Support us
------------
You can give feedback via `GitHub Issues` or send an email to **rainyhowcool@outlook.com**.
<br>
If you want to add a new feature, please submit a `Pull requests`.
