CFLAGS = -Werror -Wextra -Wall
GCOVFLAGS = -fprofile-arcs -ftest-coverage --coverage
TEST_FILES = ./Test/test.c ./Parser/parse.c

.PHONY: test

install:
	mkdir -p build
	cd build && qmake ../3DViewer/3DViewer.pro && make

uninstall:
	rm -rf build
dist: clean uninstall
	tar -czf 3DViewer_v1.tar.gz ./*

rebuild: uninstall install

test:
	gcc $(CFLAGS) $(TEST_FILES) -lcheck -o ./Test/test
	./Test/test

leaks: test
	leaks -atExit -- ./Test/test

gcov_report:
	mkdir -p gcov
	gcc $(CFLAGS) $(GCOVFLAGS) $(TEST_FILES) -lcheck -o ./gcov/gcov_test
	./gcov/gcov_test
	mv *.gcno *.gcda ./gcov
	lcov --capture --directory ./gcov --output-file ./gcov/coverage.info
	genhtml -o ./gcov/report ./gcov/coverage.info
	open ./gcov/report/index.html

clang_format:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -i ./Test/*.c ./Test/*.h
	clang-format -i ./Parser/*.c ./Parser/*.h
	clang-format -i ./3DViewer/*.cpp ./3DViewer/*.h
	rm -f .clang-format

clang_check:
	cp ../materials/linters/.clang-format ./.clang-format
	clang-format -n ./Test/*.c ./Test/*.h
	clang-format -n ./Parser/*.c ./Parser/*.h
	clang-format -n ./3DViewer/*.cpp ./3DViewer/*.h
	rm -f .clang-format

clean:
	rm -f ./Test/test
	rm -rf gcov
	otchet/latex otchet/html

dvi: 
	cd otchet/ && doxygen Doxyfile && cd ..