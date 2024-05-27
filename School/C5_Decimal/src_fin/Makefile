CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS=--coverage
LINUX=-lcheck -lm -lsubunit
MACOS=-lcheck
OS=$(shell uname -s)

ifeq ($(OS), Darwin)
 OSFLAG = $(MACOS)
else
 OSFLAG = $(LINUX)
endif

all: s21_decimal.a test lcov_report

s21_decimal.a:
	$(CC) $(CFLAGS) -c *.c
	ar r s21_decimal.a *.o
	rm *.o

test: objects_test objects_lib
	$(CC) $(TFLAGS) *.o -o test $(OSFLAG)
	@printf "\n"
	@echo "UNIT Tests start here"
	@echo "------------------------------------------------"
	@./test

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h tests/*.c tests/*.h
	rm .clang-format

objects_test:
	$(CC) $(CFLAGS) -c tests/*.c

objects_lib:
	$(CC) $(CFLAGS) -c $(TFLAGS) *.c

gcov_report:
	gcovr
	gcovr --html-details -o report.html
	open report.html

lcov_report:
	gcov *.c
	lcov --capture --directory . -o lcov.info
	genhtml lcov.info --highlight --legend -output-directory report
	open report/index.html

clean:
	@rm -rf report 2> /dev/null
	@rm *.o *.gc* tests/*.gc* *.css *.html *.a test *.info 2> /dev/null

rebuild:
	make clean ; make all