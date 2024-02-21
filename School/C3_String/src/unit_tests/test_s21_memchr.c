#include "unit_tests.h"

START_TEST(test_s21_memchr_1) {
  char str_1[10] = "1234567890";
  char str_2 = '4';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memchr(str_1, str_2, n), memchr(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memchr_2) {
  char str_1[50] = "This is a string";
  char str_2 = 'r';
  s21_size_t n = 16;
  ck_assert_pstr_eq(s21_memchr(str_1, str_2, n), memchr(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memchr_3) {
  char str_1[50] = "This is a string";
  char str_2 = 'w';
  s21_size_t n = 16;
  ck_assert_pstr_eq(s21_memchr(str_1, str_2, n), memchr(str_1, str_2, n));
}
END_TEST

Suite *make_memchr_suite(void) {
  Suite *s = suite_create("memchr");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_memchr_1);
  tcase_add_test(tc_strings, test_s21_memchr_2);
  tcase_add_test(tc_strings, test_s21_memchr_3);
  return s;
}
