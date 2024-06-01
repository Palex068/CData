test-cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem -I . --inconclusive --check-config .

test-cppcheck-report: _dir-report
	$(MAKE) test-cppcheck 2>&1 > report/cppcheck.log
