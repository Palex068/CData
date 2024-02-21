#include "unit_tests.h"

START_TEST(test_s21_strncpy_1) {
  char str_1[10] = "";
  char str_2[50] = "String";
  s21_size_t n = 3;
  ck_assert_str_eq(s21_strncpy(str_1, str_2, n), strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_2) {
  char str_1[10] = "";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str_1, str_2, n), strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_3) {
  char str_1[50] = "Hello";
  char str_2[50] = "";
  s21_size_t n = 1;
  ck_assert_str_eq(s21_strncpy(str_1, str_2, n), strncpy(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncpy_4) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "";
  s21_size_t n = 0;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_5) {
  char s1[70] = "";
  char s2[70] = "";
  char s3[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  s21_size_t n = strlen(s3);
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_6) {
  char s1[5] = "";
  char s2[5] = "";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_7) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "Good";
  s21_size_t n = 5;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_8) {
  char s1[20] = "Hello, world!";
  char s2[20] = "Hello, world!";
  char s3[] = "\0";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

START_TEST(test_s21_strncpy_9) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "fг-аг-аг";
  s21_size_t n = 1;
  ck_assert_pstr_eq(strncpy(s1, s3, n), s21_strncpy(s2, s3, n));
}
END_TEST

Suite *make_strncpy_suite(void) {
  Suite *s = suite_create("strncpy");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strncpy_1);
  tcase_add_test(tc_strings, test_s21_strncpy_2);
  tcase_add_test(tc_strings, test_s21_strncpy_3);
  tcase_add_test(tc_strings, test_s21_strncpy_4);
  tcase_add_test(tc_strings, test_s21_strncpy_5);
  tcase_add_test(tc_strings, test_s21_strncpy_6);
  tcase_add_test(tc_strings, test_s21_strncpy_7);
  tcase_add_test(tc_strings, test_s21_strncpy_8);
  tcase_add_test(tc_strings, test_s21_strncpy_9);
  return s;
}
