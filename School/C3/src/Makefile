CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS=-fprofile-arcs -ftest-coverage

all: s21_string.a test gcov_report

s21_string.a:
	$(CC) $(CFLAGS) -c *.c
	ar r s21_string.a *.o
	rm *.o

test: objects_test objects_lib
	$(CC) $(TFLAGS) *.o -o test -lcheck
	./test

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
	rm *.html *.css *.gc* *.o *.a test

rebuild: clean all
