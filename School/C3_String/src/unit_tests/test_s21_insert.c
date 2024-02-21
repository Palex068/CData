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
Suite *make_insert_suite(void) {
  Suite *s = suite_create("insert");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_insert_1);
  tcase_add_test(tc_strings, test_s21_insert_2);
  tcase_add_test(tc_strings, test_s21_insert_3);
  return s;
}