_test-unittests:
	$(CC) $(FLAGS) -c unittests.c

_test-compile: $(OBJS)
	$(CC) $(FLAGS) unittests.o $(OBJS) $(TFLAGS)

SRCS_LINUX := $(shell find . -name "*.c")
OBJS_LINUX := $(patsubst ./%,build/%,$(SRCS_LINUX:.c=.o))

_test-compile_linux: $(OBJS_LINUX)
	$(CC) $(FLAGS) $(OBJS_LINUX) $(TFLAGS)

_test-run:
	./$(TEST_EXECUTABLE)

start: clean unittests.c test-style _test-unittests _add-pedantic test-cppcheck _test-compile_linux _test-run
start_mac: clean unittests.c test-style _test-unittests _add-pedantic test-cppcheck _test-compile _test-run
start_mac_x: clean unittests.c test-style _add-xcode_check _test-unittests _add-pedantic test-cppcheck _test-compile _test-run

_add-xcode_check:
	$(eval TFLAGS += -I/opt/homebrew/include -L/opt/homebrew/lib)
