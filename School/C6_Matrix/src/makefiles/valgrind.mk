test-valgrind: clean unittests.c _test-compile_linux
	valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./$(TEST_EXECUTABLE)

test-valgrind_report: clean unittests.c _dir-report _test-compile_linux
	valgrind --leak-check=full --show-reachable=yes --track-fds=yes --log-file=report/valgrind.log ./$(TEST_EXECUTABLE)
