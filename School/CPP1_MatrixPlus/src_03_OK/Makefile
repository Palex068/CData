CC := g++
CFLAGS := -Wall -Werror -Wextra -std=c++17
test_flags=--coverage


#ifeq ($(OS),Linux)
#	test_libs=$(shell pkg-config --libs --cflags gtest) $(shell pkg-config --libs --cflags gmock) -pthread
#	open=xdg-open
#else
#	test_libs=$(shell pkg-config --libs --cflags gtest) $(shell pkg-config --libs --cflags gmock) -pthread
#	open=open
#endif

.PHONY: all clean test


all: s21_matrix_oop.a

build: s21_matrix_oop.cpp
	$(CC) $(CFLAGS) -c -lstdc++ -std=c++17 s21_matrix_oop.cpp -o s21_matrix_oop.o

s21_matrix_oop.a: build
	ar rcs s21_matrix_oop.a s21_matrix_oop.o
	ranlib s21_matrix_oop.a

clean:
	rm -rf *.o *.out *.a test
	rm -rf *.gcda *.gcno report gcov_report.* gcov_report *.info

rebuild:
	make clean
	make build

leaks: test
	valgrind --leak-check=full ./test

test: clean s21_matrix_oop.a test.cpp
	$(CC) $(CFLAGS) $(test_flags) s21_matrix_oop.cpp test.cpp -o test -lgtest -lgmock -pthread 
	./test

gcov_report: clean test
	lcov -t "test" -o s21_test.info --no-external -c -d .
	genhtml -o report s21_test.info
	$(open) ./report/index.html

clang-format:
	cp ../materials/linters/.clang-format .
	clang-format -i *.cpp
	rm -f .clang-format

clang-check:
	cp ../materials/linters/.clang-format .
	clang-format -n *.cpp
	rm -f .clang-format
