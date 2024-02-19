#include "unit_tests.h"

START_TEST(test_s21_strerror_1) {
  int str_1 = 1;
  ck_assert_str_eq(s21_strerror(str_1), strerror(str_1));
}
END_TEST

START_TEST(test_s21_strerror_2) {
  int str_1 = -1;
  ck_assert_str_eq(s21_strerror(str_1), strerror(str_1));
}
END_TEST

START_TEST(test_s21_strerror_3) {
  int str_1 = 150;
  ck_assert_str_eq(s21_strerror(str_1), strerror(str_1));
}
END_TEST

Suite *make_strerror_suite(void) {
  Suite *s = suite_create("strerror");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strerror_1);
  tcase_add_test(tc_strings, test_s21_strerror_2);
  tcase_add_test(tc_strings, test_s21_strerror_3);
  return s;
}
