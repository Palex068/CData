CC = gcc
TESTFLAGS = -lcheck -lm -lpthread
GCCFLAGS = -Wall -Werror -Wextra
GCOVFLAGS = -fprofile-arcs -ftest-coverage

ifeq ($(shell uname -s), Linux)
	TESTFLAGS = -lm -lpthread -lcheck -lsubunit
endif

all: s21_math.a test

s21_math.a: clean
	$(CC) $(GCCFLAGS) -std=c11 -c s21_*.c
	ar rc s21_math.a *.o
	mkdir binary_files
	mv *.o binary_files

gcov_report: s21_math.a
	gcc $(GCCFLAGS) $(GCOVFLAGS) math_test.c $(TESTFLAGS) s21_*.c -o gcovreport
	./gcovreport
	lcov -t "gcovreport" -o gcovreport.info -c -d .
	genhtml -o report gcovreport.info
	open report/index.html
	rm -rf gcovreport gcovreport.info *.gcda *.gcno math_test.gcda math_test.gcno

test: s21_math.a
	$(CC) $(GCCFLAGS) $(TESTFLAGS) math_test.c s21_math.a -o math_test
	./math_test

clean:
	rm -rf *.o *.a *.gcno *.gcda *.info binary_files test math_test report