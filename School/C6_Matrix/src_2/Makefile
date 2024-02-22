CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11
CHECK_FLAGS =-lcheck
GCOV_FLAGS = -fprofile-arcs -ftest-coverage

all: s21_matrix.a test gcov_report

rebuild: clean all

test: __test__/*.c s21_matrix.c
	$(CC) $(CFLAGS) $^ -o $@ $(GCOV_FLAGS) $(CHECK_FLAGS)
	./test

s21_matrix.a:
	$(CC) $(CFLAGS) -c s21_matrix.c -o s21_matrix.o
	ar rcs $@ *.o

gcov_report:
	gcovr
	@gcovr --html-details -o report.html
	@open report.html
	# lcov -t "gcov_test" -o gcov_test.info -c -d .
	# genhtml -o report gcov_test.info
	# open ./report/index.html


clean:
	rm -fr *.o *.a s21_math.a test test.dSYM/ *.gcda *.gcno report/ test.info *.html gcov_test.info