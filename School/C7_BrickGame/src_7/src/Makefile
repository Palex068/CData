CC=gcc
CFLAGS=-Wall -Wextra -Werror -std=c11 -g
TFLAGS=--coverage
LINUX=-lm -lcheck -lncurses
MACOS=-lcheck -lncurses
CHSUB=-lsubunit 

BACKENDPATH=brick_game/tetris/
FRONTENDPATH=gui/cli/

BUILD=build/
DISTDIR=s21_tetris-1.0/

OS=$(shell uname -s)

ifeq ($(OS), Darwin)
 OSFLAG = $(MACOS)
 OSTEST =
else
 OSFLAG = $(LINUX)
 OSTEST = $(CHSUB)
endif

all: install

install: objects_lib
	@mkdir $(BUILD)
	@$(CC) $(CFLAGS) *.o $(FRONTENDPATH)*.c -o $(BUILD)tetris $(OSFLAG)
	@rm *.o
	@echo "\033[32mTetris installed \033[0m"

uninstall: clean
	@echo "\033[31mTetris uninstalled \033[0m"

dvi:
	doxygen .Doxyfile
	open doxygen/html/index.html

dist:
	@mkdir $(DISTDIR)
	@cp -a brick_game $(DISTDIR)
	@cp -a gui $(DISTDIR)
	@cp -a tests $(DISTDIR)
	@cp -a .Doxyfile $(DISTDIR)
	@cp -a Makefile $(DISTDIR)
	tar -czf s21_tetris-1.0.tar.gz $(DISTDIR)
	@rm -rf $(DISTDIR)

test: clean objects_test 
	$(CC) $(TFLAGS) *.o -o test $(OSFLAG) $(OSTEST) 
	@printf "\n"
	@echo "UNIT Tests start here"
	@echo "------------------------------------------------------------------------------"
	./test

objects_test: clean
	$(CC) $(CFLAGS) -c tests/*.c
	$(CC) $(CFLAGS) -c $(BACKENDPATH)*.c $(TFLAGS)

objects_lib:
	@$(CC) $(CFLAGS) -c $(BACKENDPATH)*.c

clang:
	cp ../materials/linters/.clang-format .
	clang-format -n $(BACKENDPATH)*.c $(BACKENDPATH)*.h $(FRONTENDPATH)*.c $(FRONTENDPATH)*.h tests/*.c tests/*.h
	rm .clang-format

gcov_report:
	gcovr
	gcovr --html-details -o report.html
	open report.html

lcov_report:
	gcov backend.o figures.o
	lcov --capture --directory . -o lcov.info
	genhtml lcov.info --highlight --legend -output-directory report
	open report/index.html

clean:
ifneq (,$(wildcard report*))
	@rm -rf report* *.info
endif
ifneq (,$(wildcard doxygen))
	@rm -rf doxygen
endif
ifneq (,$(wildcard s21_tetris-1.0*))
	@rm -rf s21_tetris-1.0*
endif
	-@rm -rf *.gc* *.o *.a $(BUILD) test *.txt 2> /dev/null || true

rebuild:
	make clean ; make all