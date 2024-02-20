#include "unit_tests.h"

START_TEST(test_s21_sscanf_1) {
  char format[] = "%d";
  char str[] = "";
  int p1, p2;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(test_s21_sscanf_2) {
  char format[] = "";
  char str[] = " ";
  int p1, p2;

  int res1 = s21_sscanf(str, format, &p1);
  int res2 = sscanf(str, format, &p2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *make_sscanf_suite(void) {
  Suite *s = suite_create("sscanf");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_sscanf_1);
  tcase_add_test(tc_strings, test_s21_sscanf_2);
  return s;
}