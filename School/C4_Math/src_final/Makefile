CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS=-fprofile-arcs -ftest-coverage
OBJECT=s21_math.a
LINUX=-lcheck -lm -lsubunit
MACOS=-lcheck
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
 OSFLAG = $(MACOS)
else
 OSFLAG = $(LINUX)
endif

all: s21_math.a test gcov_report

s21_math.a:
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