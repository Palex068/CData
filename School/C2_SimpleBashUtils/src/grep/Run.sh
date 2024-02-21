#!/bin/bash

file=$1

# cp ../materials/linters/.clang-format .clang-format

clang-format $file -i 
cppcheck --platform=win64 --enable=all --suppress=missingIncludeSystem $file

# gcc -Wall -Wextra -Werror $file -o build
gcc $file -o build

./build
# rm build