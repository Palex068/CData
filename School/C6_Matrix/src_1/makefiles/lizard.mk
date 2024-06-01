_lizard: _dir-report
	lizard --html . > report/lizard.html

_lizard-open:
	open report/lizard.html

test-lizard: _lizard _lizard-open
test-lizard_wsl: _lizard
