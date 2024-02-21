#include "unit_tests.h"

START_TEST(test_s21_insert_1) {
  s21_size_t n = 2;
  char str_1[50] = "diary";
  char *str_2 = s21_insert(str_1, "ction", n);
  ck_assert_str_eq(str_2, "dictionary");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_insert_2) {
  s21_size_t n = 0;
  char str_1[50] = "diary";
  char *str_2 = s21_insert(str_1, "ction", n);
  ck_assert_str_eq(str_2, "ctiondiary");
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_insert_3) {
  s21_size_t n = 5;
  char str_1[50] = "";
  char *str_2 = s21_insert(str_1, "null", n);
  ck_assert_ptr_null(str_2);
  if (str_2) free(str_2);
}
END_TEST

START_TEST(test_s21_insert_4) {
  char s1[30] = "abcdefghij";
  char s3[] = "\'I WAS HERE\'";
  char s4[] = "abc\'I WAS HERE\'defghij";
  s21_size_t num = 3;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_5) {
  char s1[30] = "abc";
  char s3[] = "333";
  char *s4 = s21_NULL;
  s21_size_t num = 10;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_6) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char *s4 = s21_NULL;
  s21_size_t num = -1;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_7) {
  char *s1 = s21_NULL;
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_8) {
  char s1[30] = "";
  char s3[] = "";
  char s4[] = "";
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_9) {
  char s1[] = "wtf";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_10) {
  char s1[] = "";
  char *s3 = s21_NULL;
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s2, s4);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_11) {
  char s1[30] = "hello, world!";
  char s3[] = "hELLO, WORLD!";
  char s4[] = "hello, hELLO, WORLD!world!";
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_12) {
  char s1[30] = "";
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 7;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

START_TEST(test_s21_insert_13) {
  char *s1 = s21_NULL;
  char s3[] = "";
  char *s4 = s21_NULL;
  s21_size_t num = 0;
  char *s2 = s21_insert(s1, s3, num);
  ck_assert_pstr_eq(s4, s2);
  if (s2) free(s2);
}
END_TEST

Suite *make_insert_suite(void) {
  Suite *s = suite_create("insert");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_insert_1);
  tcase_add_test(tc_strings, test_s21_insert_2);
  tcase_add_test(tc_strings, test_s21_insert_3);
  tcase_add_test(tc_strings, test_s21_insert_4);
  tcase_add_test(tc_strings, test_s21_insert_5);
  tcase_add_test(tc_strings, test_s21_insert_6);
  tcase_add_test(tc_strings, test_s21_insert_7);
  tcase_add_test(tc_strings, test_s21_insert_8);
  tcase_add_test(tc_strings, test_s21_insert_9);
  tcase_add_test(tc_strings, test_s21_insert_10);
  tcase_add_test(tc_strings, test_s21_insert_11);
  tcase_add_test(tc_strings, test_s21_insert_12);
  tcase_add_test(tc_strings, test_s21_insert_13);
  return s;
}