_docs_report: clean
	doxygen Doxyfile

_docs_open:
	open docs/html/index.html

docs: _docs_report _docs_open
docs_wsl: _docs_report
