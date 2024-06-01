NAME=s21_matrix.a

CC=gcc
TEST_EXECUTABLE=testing
FLAGS=-Wall -Wextra -Werror -std=c11
TFLAGS=-o $(TEST_EXECUTABLE) -lcheck
CODE_STYLE=-style=Google
UNAME_S := $(shell uname -s)

ifeq ($(UNAME_S), Linux)
	TFLAGS += -lm -lsubunit
endif

SRCS := $(shell find . -name "*.c" | grep -v "unittests.c")
OBJS := $(patsubst ./%,build/%,$(SRCS:.c=.o))

all: $(NAME)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rcs $@ $^

test: $(NAME) _test-unittests _test-compile _test-run

gcov_report: clean _add-coverage test _gcov _gcov-open

clean:
	rm -rf report build docs
	rm -f *.a *.o *.gcda *.gcno *.gcov *.info $(TEST_EXECUTABLE) *.html *.log tests/_unittests.check

include makefiles/util.mk
include makefiles/test.mk
include makefiles/check.mk
include makefiles/cppcheck.mk
include makefiles/gcov.mk
include makefiles/docker.mk
include makefiles/lizard.mk
include makefiles/flawfinder.mk
include makefiles/valgrind.mk
include makefiles/style.mk
include makefiles/debugging.mk
include makefiles/pedantic.mk
include makefiles/doxygen.mk
include makefiles/os.mk

.PHONY: _unittests.check unittests.c
