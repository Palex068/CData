#include "unit_tests.h"

START_TEST(test_s21_memset_1) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = strlen(s1);
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_2) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 5;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_3) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = ' ';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_4) {
  char s1[] = "";
  char s2[] = "";
  int ch = '\0';
  s21_size_t n = 0;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_5) {
  char s1[] = "Hello";
  char s2[] = "Hello";
  int ch = '\0';
  s21_size_t n = 4;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_6) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  int ch = 80;
  s21_size_t n = 7;
  ck_assert_str_eq(memset(s1, ch, n), s21_memset(s2, ch, n));
}
END_TEST

START_TEST(test_s21_memset_7) {
  char str_1[50] = "This is a test of the memset function";
  s21_size_t n = 4;
  ck_assert_pstr_eq(s21_memset(str_1, '*', n), memset(str_1, '*', n));
}
END_TEST

START_TEST(test_s21_memset_8) {
  char str_1[50] = "";
  char str_2 = '1';
  s21_size_t n = 1;
  ck_assert_pstr_eq(s21_memset(str_1, str_2, n), memset(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_memset_9) {
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
  tcase_add_test(tc_strings, test_s21_memset_4);
  tcase_add_test(tc_strings, test_s21_memset_5);
  tcase_add_test(tc_strings, test_s21_memset_6);
  tcase_add_test(tc_strings, test_s21_memset_7);
  tcase_add_test(tc_strings, test_s21_memset_8);
  tcase_add_test(tc_strings, test_s21_memset_9);
  return s;
}
