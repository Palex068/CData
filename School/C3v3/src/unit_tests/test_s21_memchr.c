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

START_TEST(test_s21_memchr_4) {
  char str[] = "Hello, world!";
  int ch = 65;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_5) {
  char str[] = "Hello, world!";
  int ch = 'l';
  s21_size_t len = 10;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_6) {
  char str[] = "Hello, world!";
  int ch = 'w';
  s21_size_t len = 5;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_7) {
  char str[] = "69917020";
  int ch = '3';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_8) {
  char str[] = "69917020";
  int ch = '6';
  s21_size_t len = 0;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_9) {
  char str[] = "69917020";
  int ch = 'g';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_10) {
  char str[] = "69917020";
  int ch = '\0';
  s21_size_t len = 9;
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_11) {
  char str[] = "Hello, world!";
  int ch = ' ';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_12) {
  char str[] = "Hello, world!";
  int ch = 101;
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

START_TEST(test_s21_memchr_13) {
  char str[] = "Hello, world!";
  int ch = '1';
  s21_size_t len = strlen(str);
  ck_assert_ptr_eq(memchr(str, ch, len), s21_memchr(str, ch, len));
}
END_TEST

Suite *make_memchr_suite(void) {
  Suite *s = suite_create("memchr");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_memchr_1);
  tcase_add_test(tc_strings, test_s21_memchr_2);
  tcase_add_test(tc_strings, test_s21_memchr_3);
  tcase_add_test(tc_strings, test_s21_memchr_4);
  tcase_add_test(tc_strings, test_s21_memchr_5);
  tcase_add_test(tc_strings, test_s21_memchr_6);
  tcase_add_test(tc_strings, test_s21_memchr_7);
  tcase_add_test(tc_strings, test_s21_memchr_8);
  tcase_add_test(tc_strings, test_s21_memchr_9);
  tcase_add_test(tc_strings, test_s21_memchr_10);
  tcase_add_test(tc_strings, test_s21_memchr_11);
  tcase_add_test(tc_strings, test_s21_memchr_12);
  tcase_add_test(tc_strings, test_s21_memchr_13);
  return s;
}
