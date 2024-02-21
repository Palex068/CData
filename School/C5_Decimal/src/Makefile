CC=gcc
FLAGS=-std=c11 -Wall -Werror -Wextra
TFLAGS=-fprofile-arcs -ftest-coverage
OBJECT=s21_decimal.a
LINUX=-lcheck -lm -lsubunit
MACOS=-lcheck
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
 OSFLAG = $(MACOS)
else
 OSFLAG = $(LINUX)
endif

S21_DECIMAL_C=s21_*.c
S21_DECIMAL_H=s21_*.h
S21_DECIMAL_O=s21_*.o
TESTS=tests

ifeq ($(shell uname -s),Linux)
	TEST_FLAGS+=-lsubunit
endif

all: s21_decimal.a test gcov_report

s21_decimal.a:
	@$(CC) $(CFLAGS) -c *.c
	@ar r $(OBJECT) *.o
	@rm *.o

test: objects_test objects_lib
	@$(CC) $(TFLAGS) *.o -o test $(OSFLAG);
	@./test

style:
	@cp ../materials/linters/.clang-format .
	@clang-format -n *.c tests/*.c
	@rm .clang-format
	# clang-format -style=google -i test/*.c *.c *.h
	# clang-format -style=google -n test/*.c *.c *.h

cppcheck:
	@cppcheck --enable=all --suppress=missingIncludeSystem *.c ./tests *.c

objects_test:
	@$(CC) $(CFLAGS) -c ./tests/*.c

objects_lib:
	@$(CC) $(CFLAGS) -c $(TFLAGS) *.c

gcov_report:
	gcovr
	@gcovr --html-details -o report.html
	@open report.html

clean:
	@-rm *.html *.css *.gc* *.o *.a test

rebuild: clean all

mem: test
ifeq ($(shell uname -s),Linux)
	valgrind -s --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all ./$(TESTS)
else
	leaks --atExit -- ./$(TESTS)
endif