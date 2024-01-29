SHELL := /bin/bash
CC= gcc -std=c11
CFLAGS= -Wall -Wextra -Werror
CAT= s21_cat.c
FILE=cat_test

all: s21_cat

s21_cat:
	$(CC) $(CFLAGS) $(CAT) -o s21_cat

test:
	-diff <(./s21_cat $(FILE)) <(cat $(FILE))
	-diff <(./s21_cat -e $(FILE)) <(cat -e $(FILE))
	-diff <(./s21_cat -v $(FILE)) <(cat -v $(FILE))
	-diff <(./s21_cat -t $(FILE)) <(cat -t $(FILE))
	-diff <(./s21_cat -s $(FILE)) <(cat -s $(FILE))
	-diff <(./s21_cat --squeeze-blank $(FILE)) <(cat -s $(FILE))
	-diff <(./s21_cat -n $(FILE)) <(cat -n $(FILE))
	-diff <(./s21_cat --number $(FILE)) <(cat -n $(FILE))
	-diff <(./s21_cat -b $(FILE)) <(cat -b $(FILE))
	-diff <(./s21_cat --number-nonblank $(FILE)) <(cat -b $(FILE))
	-diff <(./s21_cat -etsn $(FILE)) <(cat -etsn $(FILE))

clean:
	rm -rf s21_cat
	rm -rf *.a *.out *.o *.txt

rebuild:
	make clean
	make all
	rm -rf  *.o *.a