CFLAGS = -Wall -Wextra -Werror
INSTALL_FILES = brick_game/tetris/tetris.c gui/cli/console_front.c game.c -lncurses
TEST_FILES = test/test.c brick_game/tetris/tetris.c gui/cli/console_front.c -lcheck -lncurses
GCOV_FILES = test/test.c brick_game/tetris/tetris.c -lcheck
GCOVFLAGS = -fprofile-arcs -ftest-coverage --coverage
DIST_DIR = s21_Tetris

.PHONY: test

UNAME_S = $(shell uname)

ifeq ($(UNAME_S),Darwin)
OPEN_CMD = open
endif

ifeq ($(UNAME_S),Linux)
OPEN_CMD = xdg-open
ADD_LDFLAGS = -lm -lsubunit
endif

all: install

install:
	mkdir -p build
	gcc $(CFLAGS) $(INSTALL_FILES) $(ADD_LDFLAGS) -o build/Tetris
	echo 0 > build/max_score.txt

uninstall:
	rm -rf build

test:
	echo 0 > test/max_score.txt
	gcc $(CFLAGS) $(TEST_FILES) $(ADD_LDFLAGS) -o test/test
	cd test && ./test

gcov_report:
	mkdir -p gcov
	echo 0 > gcov/max_score.txt
	gcc $(CFLAGS) $(GCOVFLAGS) $(GCOV_FILES) $(ADD_LDFLAGS) -o ./gcov/gcov_test
	cd gcov && ./gcov_test
	mv *.gcno *.gcda ./gcov
	lcov --capture --directory ./gcov --output-file ./gcov/coverage.info
	genhtml -o ./gcov/report ./gcov/coverage.info
	$(OPEN_CMD) ./gcov/report/index.html

dvi:
	$(OPEN_CMD) Documentation.html

dist:
	mkdir -p $(DIST_DIR)
	cp -a brick_game $(DIST_DIR)
	cp -a gui $(DIST_DIR)
	cp -a test $(DIST_DIR)
	cp -a *.c $(DIST_DIR)
	cp -a *.h $(DIST_DIR)
	cp -a Documentation.html $(DIST_DIR)
	tar -czf s21_Tetris.tar.gz $(DIST_DIR)
	rm -rf $(DIST_DIR)
	
clang_format:
	cp ../../../materials/linters/.clang-format ../../brick_game/tetris/.clang-format
	clang-format -i *.c *.h
	clang-format -i ../../gui/cli/*.c ../../gui/cli/*.h
	clang-format -i ../../test/*.c ../../test/*.h
	rm -f .clang-format

clang_check:
	cp ../../../materials/linters/.clang-format ../../brick_game/tetris/.clang-format
	clang-format -n *.c *.h
	clang-format -n ../../gui/cli/*.c ../../gui/cli/*.h
	clang-format -n ../../test/*.c ../../test/*.h
	rm -f .clang-format

leaks_game: install
	cd build && leaks -atExit -- ./Tetris

leaks_test: test
	cd ../../test && leaks -atExit -- ./test

clean:
	cd test && rm -f test && rm -f *.txt
	rm -rf gcov
	rm -f s21_Tetris.tar.gz
