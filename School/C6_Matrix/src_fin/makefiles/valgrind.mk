test-valgrind: clean test
	valgrind --leak-check=full --show-reachable=yes --track-fds=yes ./$(TEST_EXECUTABLE)

test-valgrind_report: clean test _dir-report
	valgrind --leak-check=full --show-reachable=yes --track-fds=yes --log-file=report/valgrind.log ./$(TEST_EXECUTABLE)
