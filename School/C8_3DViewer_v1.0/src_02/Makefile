TARGET = 3dViewer

CC = gcc
CFLAGS = -Wall -Werror -Wextra -std=c11 -g
OS = $(shell uname)
MODULES = $(wildcard modules/*.c)
OBJECTS = $(patsubst %.c, %.o, $(MODULES))
TEST_MODUlES = test_modules

ifeq ($(OS), Linux)
	LDLIBS = -lcheck_pic -pthread -lrt -lm -lsubunit
else
	LDLIBS = -lcheck -lm
endif

all: clean install

%.o: %.c
	mkdir -p obj
	$(CC) -c $(CFLAGS) $< $(LDLIBS) -o $(patsubst modules%, obj%, $@)

install:
	@echo "Start installation"
	@mkdir -p ../build
	@cd view && cd 3dViewerUI && qmake && make &> /dev/null && make clean &> /dev/null && rm -rf Makefile && mv 3dViewerUI.app ../../../build/$(TARGET).app
	@cp -R ../build/$(TARGET).app ~/Desktop/$(TARGET).app
	@echo "┏=========================================┓"
	@echo "┃    The installation was successful.     ┃"
	@echo "┃     The project is located in the       ┃"
	@echo "┃    build folder and on the desktop.     ┃"
	@echo "┗=========================================┛"

uninstall:
	@rm -rf ~/Desktop/$(TARGET).app ../build
	@echo "Uninstall completed successfully"

dvi:
	@open ../README_RUS.md

dist:
	@mkdir -p ../dist
	@cp -R ../build/$(TARGET).app ../dist
	@cp ../README_RUS.md ../dist && cp ../README.md ../dist
	@cd ../dist && tar cvzf $(TARGET)_v1.0.tgz *
	@cd ../dist && rm -rf $(TARGET).app README.md README_RUS.md
	@echo "The build was successfully archived"

test: $(OBJECTS)
	@$(CC) $(CFLAGS) ./tests/unit_tests.c $(LDLIBS) obj/*.o -o tests/$(TEST_MODUlES)
	@echo "» Unit test results:"
	@./tests/$(TEST_MODUlES)

gcov_report: $(OBJECTS)
	@echo "┏=========================================┓"
	@echo "┃     Generating your html report ...     ┃"
	@echo "┗=========================================┛"
	@$(CC) --coverage $(CFLAGS) ./tests/unit_tests.c $(LDLIBS) ./modules/*.c -o ./tests/$(TEST_MODUlES)
	@./tests/$(TEST_MODUlES)
	@mkdir -p tests/modules_gcov
	@mv *.gcno ./tests/modules_gcov/ && mv *.gcda ./tests/modules_gcov/
	@lcov -t "test_coverage" -o test_coverage.info -c -d .
	@genhtml -o report test_coverage.info
	@open report/index.html
	@rm -rf *.gcda *.gcno report/test_coverage.info tests/modules_gcov

style_check:
	@echo "┏=========================================┓"
	@echo "┃  Checking your code for Google Style    ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -n **/*.c **/*.h view/3dViewerUI/*.h view/3dViewerUI/*.cpp
	@rm ./.clang-format

format_style:
	@echo "┏=========================================┓"
	@echo "┃  Formatting your code for Google Style  ┃"
	@echo "┗=========================================┛"
	@cp ../materials/linters/.clang-format .
	@clang-format -i **/*.c **/*.h view/3dViewerUI/*.h view/3dViewerUI/*.cpp
	@rm ./.clang-format

valgrind_check: test
	@CK_FORK=no valgrind --vgdb=no --leak-check=full \
	--show-leak-kinds=all --track-origins=yes --log-file="unit_tests_vg.log" -v --verbose -q --quiet -s tests/$(TEST_MODUlES)
	@echo "┏=========================================┓"
	@echo "┃        Valgrind check is over           ┃"
	@echo "┃       logs have been generated          ┃"
	@echo "┗=========================================┛"

clean:
	@rm -rf tests/logs/*.log tests/$(TEST_MODUlES) obj *.dSYM **/*.dSYM report test_coverage.info

fclean: clean
	@rm -rf ../build ../dist ~/Desktop/$(TARGET).app unit_tests_vg.log

.PHONY: all install uninstall dvi dist test gcov_report valgrind_check style_check format_style fonts clean fclean
