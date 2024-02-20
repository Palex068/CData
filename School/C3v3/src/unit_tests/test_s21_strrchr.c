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

START_TEST(test_s21_strrchr_4) {
  char s[] = "Hello, world!";
  int ch = 33;
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_5) {
  char s[] = "Hello, Polina!";
  int ch = 'P';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_6) {
  char s[] = "Hello, world!";
  int ch = 'w';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_7) {
  char s[] = "Hello, world!";
  int ch = '0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_8) {
  char s[] = "Hello, world!";
  int ch = 'm';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_9) {
  char s[] = "Hello, world!";
  int ch = 'h';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_10) {
  char s[] = "Hello, world!";
  int ch = '\0';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

START_TEST(test_s21_strrchr_11) {
  char s[] = "Hello, world!";
  int ch = ',';
  ck_assert_pstr_eq(strrchr(s, ch), s21_strrchr(s, ch));
}
END_TEST

Suite *make_strrchr_suite(void) {
  Suite *s = suite_create("strrchr");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strrchr_1);
  tcase_add_test(tc_strings, test_s21_strrchr_2);
  tcase_add_test(tc_strings, test_s21_strrchr_3);
  tcase_add_test(tc_strings, test_s21_strrchr_4);
  tcase_add_test(tc_strings, test_s21_strrchr_5);
  tcase_add_test(tc_strings, test_s21_strrchr_6);
  tcase_add_test(tc_strings, test_s21_strrchr_7);
  tcase_add_test(tc_strings, test_s21_strrchr_8);
  tcase_add_test(tc_strings, test_s21_strrchr_9);
  tcase_add_test(tc_strings, test_s21_strrchr_10);
  tcase_add_test(tc_strings, test_s21_strrchr_11);
  return s;
}
