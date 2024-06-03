CC=g++ -std=c++17 -Wall -Werror -Wextra -pedantic -g
CHECKFLAGS=-lgtest
REPORTDIR=gcov_report
GCOV=--coverage
OS = $(shell uname)

all: test

s21_matrix_oop.a:
	$(CC) -c s21_matrix_oop.cpp -o matrix_oop.o
	ar rcs matrix_oop.a matrix_oop.o

test: clean
	$(CC) $(GCOV) -c s21_matrix_oop.cpp 
	$(CC) -c test.cpp $(CHECKFLAGS)
	$(CC) $(GCOV) -o matrix_test test.o s21_matrix_oop.o $(CHECKFLAGS)
	./matrix_test

check:
	cppcheck *.cpp && cppcheck --enable=all --language=c++ *.h

linters: 
	# cp ../materials/linters/clang-format .
	clang-format -i *.cpp *.h
	#rm clang-format

linters_check:
	clang-format -n *.cpp *.h

leaks: test
ifeq ($(OS), Linux)
	CK_FORK=no valgrind --tool=memcheck --leak-check=full ./matrix_test
else
	leaks -atExit -- ./matrix_test
endif

gcov_report: test
	lcov -t "Unit-tests of matrix_oop" -o s21_matrix_oop.info -c -d .
	genhtml -o $(REPORTDIR) s21_matrix_oop.info
	open -a "Safari" ./$(REPORTDIR)/index.html

clean:
	rm -rf ./*.o ./*.a ./a.out ./*.gcno ./*.gcda ./$(REPORTDIR) *.info ./*.info report matrix_test matrix_oop