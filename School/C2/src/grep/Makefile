SHELL := /bin/bash
CC= gcc -std=c11
CFLAGS= -Wall -Wextra -Werror
GREP= s21_grep.c
FILE= *.txt
PATTERNS=patterns.reg

all: s21_grep

s21_grep:
	$(CC) $(CFLAGS) $(GREP) -o s21_grep

test:
	-diff <(./s21_grep He $(FILE)) <(grep He $(FILE))
	-diff <(./s21_grep -v He $(FILE)) <(grep -v He $(FILE))
	-diff <(./s21_grep -i He $(FILE)) <(grep -i He $(FILE))
	-diff <(./s21_grep -iv He $(FILE)) <(grep -iv He $(FILE))
	-diff <(./s21_grep -in He $(FILE)) <(grep -in He $(FILE))
	-diff <(./s21_grep -ie "^he" $(FILE)) <(grep -ie "^he" $(FILE))
	-diff <(./s21_grep -ince "^he" $(FILE)) <(grep -ince "^he" $(FILE))
	-diff <(./s21_grep -lh se $(FILE)) <(grep -lh se $(FILE))
	-diff <(./s21_grep -hc e $(FILE)) <(grep -hc e $(FILE))

	-diff <(./s21_grep -e He -e he $(FILE)) <(grep -e He -e he $(FILE))
	-diff <(./s21_grep -s he badfile) <(grep -s he badfile)
	-diff <(./s21_grep -f $(PATTERNS) $(FILE)) <(grep -f $(PATTERNS) $(FILE))
	-diff <(./s21_grep -ohf $(PATTERNS) $(FILE)) <(grep -ohf $(PATTERNS) $(FILE))
	-diff <(./s21_grep -oi he $(FILE)) <(grep -oi he $(FILE))
	-diff <(./s21_grep -oinc he $(FILE)) <(grep -oinc he $(FILE))
	-diff <(./s21_grep -oihlnc -e he -e Se -f $(PATTERNS) $(FILE)) <(grep -oihlnc -e he -e Se -f $(PATTERNS) $(FILE))

clean:
	rm -rf s21_grep
	rm -rf *.a *.out *.o

check:
	cppcheck --enable=all --suppress=missingIncludeSystem ../../src/
	python3 ../../materials/linters/cpplint.py --extensions=c ../*/*.c
	CK_FORK=no leaks --atExit -- ./s21_grep

rebuild:
	make clean
	make all
	rm -rf  *.o *.a