CXX = gcc
CFLAGS = -Wall -Werror -Wextra -x c++ -std=c++17
SOURCE = s21_matrix_err.h s21_matrix_oop.h s21_matrix_oop.cpp

all: build

build: clean s21_matrix.o

s21_matrix.o: ${SOURCE}
	${CXX} ${CFLAGS} -c ${SOURCE} 

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n ${SOURCE}
	rm ./.clang-format

clangf:
	cp ../materials/linters/.clang-format .
	clang-format -i ${SOURCE}
	rm ./.clang-format

cppcheck:
	cppcheck --enable=all --force --suppress=missingIncludeSystem --language=c++ ${SOURCE}

clean:
	rm -rf *.gch
	rm -rf *.o