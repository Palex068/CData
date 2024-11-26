CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Werror

BUILD_DIR = build
EXEC = BrickGame

GCOV_DIR = test/gcov
GCOV_EXEC = test/gcov/gcov_test
LINKFLAGS = -lstdc++ -lm
GTEST_FLAGS = -I/opt/homebrew/opt/googletest/include -L/opt/homebrew/opt/googletest/lib -lgtest -lgtest_main -pthread
OPEN_CMD = open
GCOV_FLAGS = -fprofile-arcs -ftest-coverage --coverage
LCOV_FLAG = --ignore-errors inconsistent

TEST_DIR = test/bin/
TEST_SRC = brick_game/snake/snake_game.cpp brick_game/tetris/tetris_game.cpp test/test.cpp
TEST_HDR = brick_game/snake/snake_game.h brick_game/tetris/tetris_game.h test/test.h game_params.h
TEST_EXEC = test_bin

DIST_DIR = ../dist
ARCHIVE_NAME = ../BrickGame-0.1.tar.gz

.PHONY: build test dist clean

all: build install

build:
	@mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

install: build
	cp $(BUILD_DIR)/BrickGame.app/Contents/MacOS/$(EXEC) $(EXEC)

uninstall:
	rm -rf $(EXEC)

test: $(TEST_SRC) $(TEST_HDR)
	@mkdir -p $(TEST_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(GTEST_FLAGS) -o $(TEST_DIR)$(TEST_EXEC)
	cd $(TEST_DIR) && ./$(TEST_EXEC)

gcov_report:
	mkdir -p $(GCOV_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) -o $(GCOV_EXEC) $(GTEST_FLAGS) $(GCOV_FLAGS) $(LINKFLAGS)
	./$(GCOV_EXEC)
	mv *.gcno *.gcda $(GCOV_DIR)
	lcov --capture --directory $(GCOV_DIR) --output-file $(GCOV_DIR)/coverage.info $(LCOV_FLAG)
	lcov --remove $(GCOV_DIR)/coverage.info '/opt/homebrew/opt/googletest/*' '/usr/*' --output-file $(GCOV_DIR)/coverage.info $(LCOV_FLAG)
	genhtml -o $(GCOV_DIR)/report $(GCOV_DIR)/coverage.info $(LCOV_FLAG)
	$(OPEN_CMD) $(GCOV_DIR)/report/index.html

leaks: test
	cd $(TEST_DIR) && leaks -atExit -- ./$(TEST_EXEC)

clang_format:
	find . -path ./build -prune -o \( -name "*.cpp" -o -name "*.h" \) -print | xargs clang-format -i -style="{BasedOnStyle: Google, IndentWidth: 4}"

clang_check:
	find . -path ./build -prune -o \( -name "*.cpp" -o -name "*.h" \) -print | xargs clang-format -n -style="{BasedOnStyle: Google, IndentWidth: 4}"

dist:
	@mkdir -p $(DIST_DIR)
	@cp -r * $(DIST_DIR)/
	@cd $(DIST_DIR) && tar -czf $(ARCHIVE_NAME) .
	rm -rf $(DIST_DIR)

clean:
	rm -rf $(BUILD_DIR) $(EXEC) $(TEST_DIR) $(GCOV_DIR) max_score_snake.txt max_score_tetris.txt $(ARCHIVE_NAME)