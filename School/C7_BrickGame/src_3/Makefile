CC = gcc
TEST_LIBS = -lcheck -lm
FLAGS = -Wall -Wextra -Werror -std=c11
P = -pedantic -lm
DB = -g -O0
LNC = -lncurses
SOURCES = $(wildcard brick_game/tetris/*.c)
OBJECTS = $(patsubst brick_game/tetris/%.c, brick_game/tetris/%.o, $(SOURCES))
OS := $(shell uname)

ifeq ($(OS), Linux)
	TEST_LIBS = -lcheck -pthread -lrt -lm -lsubunit
else
	TEST_LIBS = $(shell pkg-config --libs --cflags check) -lm
endif

all: install test

install: fix clean
	$(CC) $(FLAGS) $(P) $(DB) main.c brick_game/tetris/*.c gui/cli/*.c -o tetris $(LNC)
	./tetris

uninstall: clean
	rm -rf ./tetris

clean:
	rm -rf *.o *.a *.gcno *.gcda *.gcov *.info report *.dSYM .clang-format brick_game/tetris/*.o s21_test

tetris.a: $(OBJECTS)
	ar rcs tetris.a $(OBJECTS)
	ranlib tetris.a

test: fix tetris.a
	$(CC) $(FLAGS) $(LNC) test/*.c brick_game/tetris/*.c tetris.a $(TEST_LIBS) -o s21_test
	./s21_test

brew:
	curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh
	brew install lcov
gcov_flag:
	$(eval FLAGS += --coverage)
gcov_report: fix clean gcov_flag test
	mkdir -p report
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory report
	rm -rf *.gcno *.gcda *.gcov
	open report/index.html

format:
	cp ../materials/linters/.clang-format .
	clang-format -n main.c
	clang-format -n brick_game/tetris/*.c brick_game/tetris/*.h
	clang-format -n gui/cli/*.c gui/cli/*.h
	clang-format -n test/*.c test/*.h
fix:
	cp ../materials/linters/.clang-format .
	clang-format -i main.c
	clang-format -i brick_game/tetris/*.c brick_game/tetris/*.h
	clang-format -i gui/cli/*.c gui/cli/*.h
	clang-format -i test/*.c test/*.h

leaks:
	leaks -atExit -- ./tetris
cpp:
	cppcheck --enable=all --suppress=missingIncludeSystem ./*.c
	cppcheck --enable=all --suppress=missingIncludeSystem ./test/*.c
	cppcheck --enable=all --suppress=missingIncludeSystem ./brick_game/tetris/*.c
	cppcheck --enable=all --suppress=missingIncludeSystem ./gui/cli/*.c
