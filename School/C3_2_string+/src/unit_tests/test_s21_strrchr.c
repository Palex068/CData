#include "unit_tests.h"

START_TEST(test_s21_strrchr_1) {
  char str_1[50] = "0163456769";
  char str_2 = '6';
  ck_assert_str_eq(s21_strrchr(str_1, str_2), strrchr(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strrchr_2) {
  char str_1[50] = "016356769";
  char str_2 = '4';
  ck_assert_ptr_null(s21_strrchr(str_1, str_2));
  ck_assert_ptr_null(strrchr(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strrchr_3) {
  char str_1[50] = "0163 \0 456769";
  char str_2 = ' ';
  ck_assert_str_eq(s21_strrchr(str_1, str_2), strrchr(str_1, str_2));
}
END_TEST

Suite *make_strrchr_suite(void) {
  Suite *s = suite_create("strrchr");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strrchr_1);
  tcase_add_test(tc_strings, test_s21_strrchr_2);
  tcase_add_test(tc_strings, test_s21_strrchr_3);
  return s;
}
