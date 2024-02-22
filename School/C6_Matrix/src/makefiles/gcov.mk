_gcov:
	lcov -t "$(TEST_EXECUTABLE)" -o coverage.info -c -d .
	genhtml -o report coverage.info

_gcov-open:
	open report/index.html

_add-coverage:
	$(eval FLAGS += --coverage)
	$(eval TFLAGS += --coverage)

_gcov-report: clean unittests.c _add-coverage test _gcov

test-gcov: _gcov-report _gcov-open
test-gcov_wsl: _gcov-report
test-gcov_mac: _add-coverage start_mac_x _gcov _gcov-open
