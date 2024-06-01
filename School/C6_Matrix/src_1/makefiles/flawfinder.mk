_flawfinder: _dir-report
	flawfinder --minlevel=0 --columns --context --html . > report/flawfinder.html

_flawfinder_open:
	open report/flawfinder.html

test-flawfinder: _flawfinder _flawfinder_open
test-flawfinder_wsl: _flawfinder
