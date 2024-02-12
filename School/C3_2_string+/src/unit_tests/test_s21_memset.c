#include "unit_tests.h"

START_TEST(test_s21_memset_1) {
  char str_1[50] = "This is a test of the memset function";
  s21_size_t n = 4;
  ck_assert_pstr_eq(s21_memset(str_1, '*', n), memset(str_1, '*', n));
}
END_TEST

START_TEST(test_s21_memset_2) {
  char str_1[50] = "";
  char str_2 = '1';
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memset(str_1, str_2, n), memset(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memset_3) {
  char str_1[50] = "1234567890";
  char str_2 = '1';
  s21_size_t n = 10;
  ck_assert_pstr_eq(s21_memset(str_1, str_2, n), memset(str_1, str_2, n));
}
END_TEST

Suite *make_memset_suite(void) {
  Suite *s = suite_create("memset");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_memset_1);
  tcase_add_test(tc_strings, test_s21_memset_2);
  tcase_add_test(tc_strings, test_s21_memset_3);
  return s;
}
