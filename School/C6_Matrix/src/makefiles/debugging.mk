test-debugging: clean _add-sanitize _unittests-forking_disable _test-unittests _test-compile

test-lldb: test-debugging
	lldb $(TEST_EXECUTABLE)

test-gdb: test-debugging
	gdb $(TEST_EXECUTABLE)

test-lldb_report: test-debugging _dir-report
	@xcrun lldb -o "run" -o "q" $(TEST_EXECUTABLE) &> report/lldb.log

test-gdb_report: test-debugging _dir-report
	gdb -ex "run" -ex "q" $(TEST_EXECUTABLE) > report/gdb.log 2>&1

_add-sanitize:
	$(eval FLAGS += -fsanitize=address -fsanitize=undefined -g -O0)
