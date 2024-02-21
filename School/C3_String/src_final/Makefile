CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS=-fprofile-arcs -ftest-coverage
FSANITIZE_FLAGS=-fsanitize=address -g
LINUX=-lcheck -lm -lsubunit
MACOS=-lcheck
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
 OSFLAG = $(MACOS)
else
 OSFLAG = $(LINUX)
endif

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(CFLAGS) -c *.c
	ar r s21_string.a *.o
	rm *.o

test: objects_test objects_lib
	$(CC) $(TFLAGS) *.o -o test $(OSFLAG)
	./test

check-fsanitize: clean objects_test objects_lib_fsanitize
	$(CC) $(FSANITIZE_FLAGS) *.o -o test $(OSFLAG)
	./test

check-valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all ./test

objects_lib_fsanitize:
	$(CC) $(CFLAGS) $(FSANITIZE_FLAGS) -c *.c

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c unit_tests/*.c
	rm .clang-format

objects_test:
	$(CC) $(CFLAGS) -c ./unit_tests/*.c

objects_lib:
	$(CC) $(CFLAGS) -c $(TFLAGS) *.c

gcov_report:
	gcovr
	gcovr --html-details -o report.html
	open report.html

clean:
	rm -f *.html *.css *.gc* *.o *.a test

rebuild: clean all

