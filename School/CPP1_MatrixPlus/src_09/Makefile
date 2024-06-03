SHELL = /bin/sh 

CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++17 -g
TFLAGS = -lm
GTESTFLAGS = -lgtest -pthread
GFLAGS = --coverage -fprofile-arcs -ftest-coverage
LIB = s21_matrix_oop.a

SRC = s21_matrix_oop.cpp
OBJ = $(SRC:.cpp=.o)
ALL_SRC = $(SRC) unit_test/*.cpp

all: clear $(LIB)

clean:
	rm -rf gcov
	rm -f $(OBJ) $(LIB) unit_test/unit_test

test: clear clean $(LIB)
	$(CXX) $(CXXFLAGS) $(ALL_SRC) $(LIB) $(TFLAGS) $(GTESTFLAGS) -o unit_test/unit_test
	unit_test/unit_test

$(LIB): $(OBJ)
	ar rc $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

rebuild: clean clear all

gcov_report: clear clean $(LIB)
	mkdir -p gcov
	$(CXX) $(CXXFLAGS) $(GFLAGS) $(ALL_SRC) $(LIB) $(TFLAGS) $(GTESTFLAGS) -o gcov/gcov_test
	cd gcov && ./gcov_test
	lcov --capture --directory . --output-file gcov/coverage.info
	lcov --remove gcov/coverage.info '*/unit_test/*' '/usr/*' '11/*' -o gcov/coverage.info
	genhtml -o gcov/report gcov/coverage.info

clang-format:
	clang-format -i $(ALL_SRC) *.h unit_test/*.h

clang-check:
	clang-format -n $(ALL_SRC) *.h unit_test/*.h

valgrind: test
	valgrind --tool=memcheck --leak-check=yes unit_test/unit_test

clear:
	clear

.PHONY: all clean test $(LIB) rebuild clang-format clang-check valgrind clear