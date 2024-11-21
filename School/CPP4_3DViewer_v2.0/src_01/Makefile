CXX=g++
CFLAGS=-Wall -Wextra -Werror -std=c++17
TEST_FLAGS=--coverage 

TEST=Test/s21_tests
TARGET=3DViewer

README := README.md

SRC := $(shell find . -name '*.cc' )
SRCH := $(shell find . -name '*.h' )

SRC_DIRS := ./model
SRCS := $(shell find $(SRC_DIRS) -name '*.cc' )
SRCSH := $(shell find $(SRC_DIRS) -name '*.h' )

OBJS = $(addsuffix .o,$(basename $(SRCS)))

OS :=$(shell uname -s)
BLUE:=\033[96m
A :=  $(shell find $(SRC_DIRS) -name 'a.out')

ifeq ($(OS), Darwin)
	CFLAGS =-lstdc++ -std=c++17 -Wall -Wextra -Werror 
else
	CFLAGS =-lstdc++ -std=c++17 -Wall -Wextra -Werror -lrt -lm -lpthread
endif

all: $(TARGET).a

$(TARGET).a: $(OBJS)
	@ar rc $@ $(OBJS)

%.o: %.cc
	$(CXX) $(CFLAGS) -c -o $@ $<

install:
	qmake -o Executables/Makefile $(TARGET).pro
	cd Executables && make -j6

start: install
	cd Executables/$(TARGET).app/Contents/MacOS && ./$(TARGET)

uninstall: clean
	rm -rf Executables

dvi: 
	open $(README)

dist: install 
	cd .. && tar -czf $(TARGET).tgz src

tests:  $(TARGET).a
	$(CXX) $(CFLAGS) $(TARGET).a $(TEST).cc -o s21_test -lgtest 
	./s21_test


clean:
	rm -rf $(OBJS) $(TARGET).a RESULT.log $(A) */*.g* $(TEST_OBJ)
	find . -name ".DS_Store" -type f -delete
	$(RM) gcov  *.info *.gcda *.gcno Tests/*.gcda Tests/*.gcno g$(TARGET).a 
	rm -rf s21_test
	rm -rf report

clean_import:
	rm -rf Import
	mkdir Import

install_lcov:
	brew install lcov

style:
	# cp ../materials/linters/.clang-format .clang-format
	clang-format -n $(SRC)
	clang-format -n $(SRCH)
	# rm -rf .clang-format

format_style:
	# cp ../materials/linters/.clang-format .clang-format
	clang-format -i $(SRC)
	clang-format -i $(SRCH)
	# rm -rf .clang-format


valgrind: $(OBJS)
	@CK_FORK=no valgrind --trace-children=yes --track-fds=yes --track-origins=yes --leak-check=full --show-leak-kinds=all --verbose --log-file=RESULT.log  ./$(TEST_OBJ)  >/dev/null;
	cat RESULT.log

leaks: tests
	CK_FORK=no leaks -atExit -- ./s21_test

a: clean $(TARGET).a
	rm -rf a.out
	$(CXX) $(CFLAGS) $(TARGET).a aboba.cc -o a.out -g
	./a.out

push: clean
	git add .
	git commit -m '$m'
	git push origin $o