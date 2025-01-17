#!/bin/sh

<< EOF
   Copyright 2025 xiaokuai(@小块SIXTEEN)

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
EOF

cmake .
make
echo "Start build"
rm -rf CMakeFiles/
rm -rf cmake_install.cmake
rm -rf CMakeCache.txt
rm -rf Makefile
chmod +777 xkupm
echo "Build stop"
