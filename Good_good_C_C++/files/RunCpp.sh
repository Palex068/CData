#!/bin/bash

file=$1

# cp ../materials/linters/.clang-format .clang-format

clang-format $file -i 
cppcheck --platform=win64 --enable=all --suppress=missingIncludeSystem $file

g++ -std=c++14 -Wall -Wextra -Werror $file -o build.exe

./build.exe
rm build.exe