CXX=gcc
CFLAGS=-Wall -Wextra -Werror -std=c++17 -lstdc++
TEST_FLAGS=--coverage 

TEST=s21_matrix_oop_test
TARGET=s21_matrix_oop

SRC_DIRS := ./
SRCS := $(shell find $(SRC_DIRS) -name '*.cc' )
SRCSH := $(shell find $(SRC_DIRS) -name '*.h' )

OBJS = $(addsuffix .o,$(basename $(SRCS)))

all:  $(TARGET).a

push: clean
	git add .
	git commit -m'$m'
	git push origin $o


$(TARGET).a: $(OBJS)
	@ar rc $@ $(OBJS)

%.o: %.cc
	$(CXX) $(CFLAGS) -c -o $@ $<

clean: 
	$(RM) $(OBJS) $(TARGET).a test
	$(RM) gcov  *.info *.gcda *.gcno Tests/*.gcda Tests/*.gcno g$(TARGET).a 
	rm -rf *.dSYM report

test: clean $(TARGET).a
	$(CXX) $(CFLAGS) $(TARGET).a $(TEST).cc -o test -lgtest
	./test

leaks: test
	CK_FORK=no leaks --atExit -- ./test
	
style: 
	cp ../materials/linters/.clang-format .clang-format 
	clang-format -n $(SRCS)
	clang-format -n $(SRCSH)
	rm -rf .clang-format