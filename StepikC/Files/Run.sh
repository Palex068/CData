#!/bin/bash

file=$1

# cp ../materials/linters/.clang-format .clang-format

clang-format $file -i 
# cppcheck --enable=all --suppress=missingIncludeSystem $file

gcc -Wall -Wextra -Werror $file -o build

./build
rm build