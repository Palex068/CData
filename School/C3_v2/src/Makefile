CC=gcc
CFLAGS=-Wall -Werror -Wextra -std=c11 -lm
STATIC = ar rcs
TESTFLAGC = -lcheck

GCOVFLAGS = -fprofile-arcs -ftest-coverage
SOURCES_ALL:=$(wildcard *.c ./tests/*.c)
SOURCES_FUN:=$(shell find . -not -name "test*.c" -name "*.c")
UNAME:=$(shell uname -s)

ifeq ($(UNAME),Linux)
	LDFLAGS=-lcheck -lsubunit -lrt -lpthread -lm
	OPEN_CM=xdg-open
endif
ifeq ($(UNAME),Darwin)
	LDFLAGS=-lcheck
	OPEN_CM=open
endif

all: s21_string.a test gcov_report

s21_string.o: s21_string.c
	$(CC) $(CFLAGS) -c s21_string.c -lm

s21_string.a: s21_string.o
	ar rcs s21_string.a s21_string.o
	ranlib s21_string.a

test: s21_string.a test.o test_memchr.o test_memcmp.o test_memcpy.o test_memset.o test_strcat.o test_strncat.o test_strchr.o test_strncmp.o test_strncpy.o test_strcspn.o test_strerror.o test_strlen.o test_strpbrk.o test_strrchr.o test_sprintf_c.o test_sprintf_e.o test_sprintf_f.o test_sprintf_g.o test_strstr.o test_strtok.o test_sprintf_octal.o test_sprintf_percent.o test_sprintf_n.o test_sprintf_string.o test_sprintf_unsigned.o test_sprintf_hex2.o test_sprintf_hex1.o test_sprintf_pointer.o test_sprintf_d.o test_sprintf_i.o test_to_upper.o test_to_lower.o test_insert.o test_trim.o test_sscanf_c.o test_sscanf_d.o test_sscanf_empty.o test_sscanf_i.o test_sscanf_n.o test_sscanf_o.o test_sscanf_p.o test_sscanf_real.o test_sscanf_x.o
	$(CC)  test.o test_memchr.o test_memcmp.o test_memcpy.o test_memset.o test_strcat.o test_strncat.o test_strchr.o test_strncmp.o test_strncpy.o test_strcspn.o test_strerror.o test_strlen.o test_strpbrk.o test_strrchr.o test_sprintf_c.o test_sprintf_e.o test_sprintf_f.o test_sprintf_g.o test_strstr.o test_strtok.o test_sprintf_octal.o test_sprintf_percent.o test_sprintf_n.o test_sprintf_string.o test_sprintf_unsigned.o test_sprintf_hex2.o test_sprintf_hex1.o test_sprintf_pointer.o test_sprintf_d.o test_sprintf_i.o test_to_upper.o test_to_lower.o test_insert.o test_trim.o test_sscanf_c.o test_sscanf_d.o test_sscanf_empty.o test_sscanf_i.o test_sscanf_n.o test_sscanf_o.o test_sscanf_p.o test_sscanf_real.o test_sscanf_x.o -L. s21_string.a $(LDFLAGS) -o test

test.o: ./tests/test_me.c
	$(CC) $(CFLAGS) -c $^ -o $@

test_insert.o: ./tests/test_insert.c
	$(CC) $(CFLAGS) -c ./tests/test_insert.c -lm

test_memchr.o: ./tests/test_memchr.c
	$(CC) $(CFLAGS) -c ./tests/test_memchr.c -lm

test_memcmp.o: ./tests/test_memcmp.c
	$(CC) $(CFLAGS) -c ./tests/test_memcmp.c -lm

test_memcpy.o: ./tests/test_memcpy.c
	$(CC) $(CFLAGS) -c ./tests/test_memcpy.c -lm

test_memset.o: ./tests/test_memset.c
	$(CC) $(CFLAGS) -c ./tests/test_memset.c -lm

test_strcat.o: ./tests/test_strcat.c
	$(CC) $(CFLAGS) -c ./tests/test_strcat.c -lm

test_strncat.o: ./tests/test_strncat.c
	$(CC) $(CFLAGS) -c ./tests/test_strncat.c -lm

test_strchr.o: ./tests/test_strchr.c
	$(CC) $(CFLAGS) -c ./tests/test_strchr.c -lm

test_strncmp.o: ./tests/test_strncmp.c
	$(CC) $(CFLAGS) -c ./tests/test_strncmp.c -lm

test_strncpy.o: ./tests/test_strncpy.c
	$(CC) $(CFLAGS) -c ./tests/test_strncpy.c -lm

test_strcspn.o: ./tests/test_strcspn.c
	$(CC) $(CFLAGS) -c ./tests/test_strcspn.c -lm

test_strerror.o: ./tests/test_strerror.c
	$(CC) $(CFLAGS) -c ./tests/test_strerror.c -lm

test_strlen.o: ./tests/test_strlen.c
	$(CC) $(CFLAGS) -c ./tests/test_strlen.c -lm

test_strpbrk.o: ./tests/test_strpbrk.c
	$(CC) $(CFLAGS) -c ./tests/test_strpbrk.c -lm

test_strrchr.o: ./tests/test_strrchr.c
	$(CC) $(CFLAGS) -c ./tests/test_strrchr.c -lm

test_sprintf_c.o: ./tests/test_sprintf_c.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_c.c -lm

test_sprintf_e.o: ./tests/test_sprintf_e.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_e.c -lm

test_sprintf_f.o: ./tests/test_sprintf_f.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_f.c -lm

test_sprintf_g.o: ./tests/test_sprintf_g.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_g.c -lm

test_strstr.o: ./tests/test_strstr.c
	$(CC) $(CFLAGS) -c ./tests/test_strstr.c -lm

test_strtok.o: ./tests/test_strtok.c
	$(CC) $(CFLAGS) -c ./tests/test_strtok.c -lm

test_sprintf_octal.o: ./tests/test_sprintf_octal.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_octal.c -lm

test_sprintf_percent.o: ./tests/test_sprintf_percent.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_percent.c -lm

test_sprintf_n.o: ./tests/test_sprintf_n.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_n.c -lm

test_sprintf_string.o: ./tests/test_sprintf_string.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_string.c -lm

test_sprintf_unsigned.o: ./tests/test_sprintf_unsigned.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_unsigned.c -lm

test_sprintf_hex2.o: ./tests/test_sprintf_hex2.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_hex2.c -lm

test_sprintf_hex1.o: ./tests/test_sprintf_hex1.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_hex1.c -lm

test_sprintf_pointer.o: ./tests/test_sprintf_pointer.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_pointer.c -lm

test_sprintf_d.o: ./tests/test_sprintf_d.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_d.c -lm

test_sprintf_i.o: ./tests/test_sprintf_i.c
	$(CC) $(CFLAGS) -c ./tests/test_sprintf_i.c -lm

test_sscanf_c.o: ./tests/test_sscanf_c.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_c.c -lm

test_sscanf_d.o: ./tests/test_sscanf_d.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_d.c -lm

test_sscanf_empty.o: ./tests/test_sscanf_empty.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_empty.c -lm

test_sscanf_i.o: ./tests/test_sscanf_i.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_i.c -lm

test_sscanf_n.o: ./tests/test_sscanf_n.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_n.c -lm

test_sscanf_o.o: ./tests/test_sscanf_o.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_o.c -lm

test_sscanf_p.o: ./tests/test_sscanf_p.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_p.c -lm

test_sscanf_real.o: ./tests/test_sscanf_real.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_real.c -lm

test_sscanf_x.o: ./tests/test_sscanf_x.c
	$(CC) $(CFLAGS) -c ./tests/test_sscanf_x.c -lm

test_to_upper.o: ./tests/test_to_upper.c
	$(CC) $(CFLAGS) -c ./tests/test_to_upper.c -lm

test_to_lower.o: ./tests/test_to_lower.c
	$(CC) $(CFLAGS) -c ./tests/test_to_lower.c -lm

test_trim.o: ./tests/test_trim.c
	$(CC) $(CFLAGS) -c ./tests/test_trim.c -lm

gcov_report: test
	$(CC) $(GCOVFLAGS) $(SOURCES_ALL) $(LDFLAGS) -o report.out
	./report.out
	gcov -f $(SOURCES_FUN)
	lcov -t "gcov_report" -o Coverage_Report.info -c -d .
	genhtml -o ./report Coverage_Report.info
	$(OPEN_CM) ./report/index-sort-f.html

libs: s21_string.a

clean:
	rm -rf *.o *.a *.gcno *.gcda *.css *.html *.gcov *.info ./report test *.out

rebuild:
	make clean all