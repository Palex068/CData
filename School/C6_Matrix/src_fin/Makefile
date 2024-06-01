NAME=s21_matrix.a

CC=gcc
TEST_EXECUTABLE=testing
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

all: $(NAME) test

$(NAME):
	$(CC) $(CFLAGS) -c *.c
	ar r $(NAME) *.o
	rm *.o

test: objects_test objects_lib
	$(CC) $(TFLAGS) *.o -o $(TEST_EXECUTABLE) $(OSFLAG)
	@printf "\n"
	@echo "UNIT Tests start here"
	@echo "------------------------------------------------"
	@./$(TEST_EXECUTABLE)
	@rm *.o

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n *.c *.h tests/*.c tests/*.h
	clang-format -i *.c *.h tests/*.c tests/*.h
	rm .clang-format

objects_test:
	$(CC) $(CFLAGS) -c tests/*.c

objects_lib:
	$(CC) $(CFLAGS) -c $(TFLAGS) *.c

gcovr_report: clean $(NAME) test
	gcovr
	gcovr --html-details -o report.html
	open report.html

gcov_report: clean $(NAME) test
	gcov *.c
	lcov --capture --directory . -o lcov.info
	genhtml lcov.info --highlight --legend -output-directory report
	open report/index.html

clean:
	rm -rf report build docs
	rm -f *.a *.o *.gcda *.gcno *.gcov *.info $(TEST_EXECUTABLE) *.html *.log *.css

include makefiles/util.mk
include makefiles/cppcheck.mk
include makefiles/docker.mk
include makefiles/valgrind.mk