#include "unit_tests.h"

START_TEST(test_s21_memcmp_1) {
  char str_1[50] = "1234567890";
  char str_2[50] = "1234567890";
  s21_size_t n = 10;
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memcmp_2) {
  char str_1[50] = "anotherstring";
  char str_2[50] = "string";
  s21_size_t n = 13;
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memcmp_3) {
  char str_1[50] = "Hello";
  char str_2[50] = "";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_memcmp(str_1, str_2, n), memcmp(str_1, str_2, n));
}
END_TEST

Suite *make_memcmp_suite(void) {
  Suite *s = suite_create("memcmp");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_memcmp_1);
  tcase_add_test(tc_strings, test_s21_memcmp_2);
  tcase_add_test(tc_strings, test_s21_memcmp_3);
  return s;
}
