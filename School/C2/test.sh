#!/bin/bash

./s21_cat s21_cat.c >> s21_cat.txt
cat s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -b s21_cat.c >> s21_cat.txt
cat -b s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -e s21_cat.c >> s21_cat.txt
cat -e s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -n s21_cat.c >> s21_cat.txt
cat -n s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -s s21_cat.c >> s21_cat.txt
cat -s s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt

./s21_cat -t s21_cat.c >> s21_cat.txt
cat -t s21_cat.c >> cat.txt
diff -s s21_cat.txt cat.txt
rm s21_cat.txt cat.txt