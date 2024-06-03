CC = gcc
FLAGS = -Wall -Wextra -Werror
OBJ = obj

PROJECT_NAME = tetris
LIB_NAME = tetris
LIB_SRC = $(wildcard brick_game/tetris/*.c)
GUI_SRC = $(wildcard gui/cli/*.c)

SOURCES = $(wildcard *.c)
OBJECTS = $(patsubst %.c, $(OBJDIR)%.o, $(SOURCES))
TEST = s21_test
TEST_DIR = tests/
RM_EXTS := o a out gcno gcda gcov info html css

OS := $(shell uname)
UBUNTU := $(shell hostnamectl | grep -o 'Ubuntu')
MAC_X86 := $(shell uname -a | grep -o _X86_64)
MAC_M1 := $(shell uname -a | grep -o _ARM64)

ifeq ($(OS), Linux)
	TEST_LIBS = -lcheck -pthread -lrt -lm -lsubunit
	MATH = -lm
	OPEN = xdg-open
else ifeq ($(UBUNTU), Ubuntu)
	TEST_FLAGS=-lpthread -lcheck  -Wno-nonnull -Wno-memset-transposed-args -lm -lsubunit
	OPEN = open
endif

ifeq ($(MAC_M1), _ARM64)
	TEST_LIBS := -I/opt/homebrew/opt/check/include -L/opt/homebrew/opt/check/lib -lcheck
	OPEN = open
endif
ifeq ($(MAC_X86), _X86_64)
	TEST_LIBS = $(shell pkg-config --libs --cflags check) -lm
	OPEN = open
endif

all: run

run: install
	build/$(PROJECT_NAME)

build: all

repo:
	mkdir -p $(OBJ)
$(OBJDIR)%.o: %.c
	$(CC) $(FLAGS) -c $< -o obj/$@

install: tetris.a gui.o main.o
	mkdir -p build/
	$(CC) *.o -lncurses -o build/$(PROJECT_NAME)
	rm -rf *.o

uninstall:
	rm -rf build

tetris.a: $(LIB_NAME).o
	ar rcs $(LIB_NAME).a *.o
	ranlib $(LIB_NAME).a

$(LIB_NAME).o:
	$(CC) $(FLAGS) -c $(LIB_SRC) $(DEBUG_FLAGS)

gui.o:
	$(CC) $(FLAGS) -c $(GUI_SRC)

main.o:
	$(CC) $(FLAGS) -c main.c

dvi:
	doxygen Doxyfile
	open html/index.html

dist: clean uninstall
	mkdir -p dist
	rsync -av --exclude='dist' . dist/
	cd dist && tar -czvf dist.tar.gz ./*

test:  tetris.a 
	$(CC) $(FLAGS) tests/*.c $(LIB_SRC) tetris.a $(TEST_LIBS) -o s21_test
	./$(TEST)

gcov_report: clean tetris.a
	gcc -fprofile-arcs -ftest-coverage $(LIB_SRC) $(TEST_DIR)tests.c tetris.a -o report.out -lm -lcheck
	./report.out
	gcovr --html-details -o report.html --exclude $(TEST_DIR)*.c
	open report.html

clean:
	rm -rf $(TEST) *.o *.a *.gcno *.gcda *.gcov *.info report a.out *.dSYM obj
	@for ext in $(RM_EXTS); do \
	find ./ -type f -name "*.$$ext" -exec rm {} \;; \
	done
	@rm -rf ./report
	@rm -rf ./obj
	rm -rf dist
	rm -rf html

clang:
	clang-format -n *.c
	cd brick_game/tetris && clang-format -n *.c *.h
	cd gui/cli && clang-format -n *.c *.h
	cd tests && clang-format -n *.c