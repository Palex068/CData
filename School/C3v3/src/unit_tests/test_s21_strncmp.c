#include "unit_tests.h"

START_TEST(test_s21_strncmp_1) {
  char str_1[50] = "1234567890";
  char str_2[50] = "1234507890";
  s21_size_t n = 5;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncmp_2) {
  char str_1[50] = "1234567890";
  char str_2[50] = "1234507890";
  s21_size_t n = 7;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncmp_3) {
  char str_1[50] = "1234567890";
  char str_2[50] = "12345";
  s21_size_t n = 6;
  ck_assert_int_eq(s21_strncmp(str_1, str_2, n), strncmp(str_1, str_2, n));
}
END_TEST

START_TEST(test_s21_strncmp_4) {
  char s1[] = "f";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_5) {
  char s1[] = "";
  char s2[] = "j";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 19;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_7) {
  char s1[] = "1242434246364377659";
  char s2[] = "1242434246364377659";
  s21_size_t n = 2;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_8) {
  char s1[] = "g124243425";
  char s2[] = "124243424";
  s21_size_t n = 0;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_9) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_10) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_11) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, worldj";
  s21_size_t n = 14;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

START_TEST(test_s21_strncmp_12) {
  char s1[] = "";
  char s2[] = "";
  s21_size_t n = 1;
  int n1 = strncmp(s1, s2, n);
  n1 = n1 > 0 ? 1 : n1 == 0 ? 0 : -1;
  int n2 = s21_strncmp(s1, s2, n);
  n2 = n2 > 0 ? 1 : n2 == 0 ? 0 : -1;
  ck_assert_int_eq(n1, n2);
}
END_TEST

Suite *make_strncmp_suite(void) {
  Suite *s = suite_create("strncmp");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strncmp_1);
  tcase_add_test(tc_strings, test_s21_strncmp_2);
  tcase_add_test(tc_strings, test_s21_strncmp_3);
  tcase_add_test(tc_strings, test_s21_strncmp_4);
  tcase_add_test(tc_strings, test_s21_strncmp_5);
  tcase_add_test(tc_strings, test_s21_strncmp_6);
  tcase_add_test(tc_strings, test_s21_strncmp_7);
  tcase_add_test(tc_strings, test_s21_strncmp_8);
  tcase_add_test(tc_strings, test_s21_strncmp_9);
  tcase_add_test(tc_strings, test_s21_strncmp_10);
  tcase_add_test(tc_strings, test_s21_strncmp_11);
  tcase_add_test(tc_strings, test_s21_strncmp_12);
  return s;
}
