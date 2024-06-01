rebuild: clean $(NAME)

_dir-report:
	if [ ! -d "report" ]; then mkdir report; fi
