#include "unit_tests.h"

START_TEST(test_s21_strpbrk_1) {
  char str_1[50] = "0123456789";
  char str_2[50] = "369";
  ck_assert_str_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strpbrk_2) {
  char str_1[50] = "12345678";
  char str_2[50] = "9";
  ck_assert_ptr_null(s21_strpbrk(str_1, str_2));
  ck_assert_ptr_null(strpbrk(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strpbrk_3) {
  char str_1[50] = "01234 56789";
  char str_2[50] = " ";
  ck_assert_str_eq(s21_strpbrk(str_1, str_2), strpbrk(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strpbrk_4) {
  char s1[] = "\0";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_5) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_6) {
  char s1[] = "1242434246364377659";
  char s2[] = "364377659";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_7) {
  char s1[] = "Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_8) {
  char s1[] = "Hello, world!";
  char s2[] = "!";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

START_TEST(test_s21_strpbrk_9) {
  char s1[] = "";
  char s2[] = "He";
  ck_assert_pstr_eq(strpbrk(s1, s2), s21_strpbrk(s1, s2));
}
END_TEST

Suite *make_strpbrk_suite(void) {
  Suite *s = suite_create("strpbrk");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strpbrk_1);
  tcase_add_test(tc_strings, test_s21_strpbrk_2);
  tcase_add_test(tc_strings, test_s21_strpbrk_3);
  tcase_add_test(tc_strings, test_s21_strpbrk_4);
  tcase_add_test(tc_strings, test_s21_strpbrk_5);
  tcase_add_test(tc_strings, test_s21_strpbrk_6);
  tcase_add_test(tc_strings, test_s21_strpbrk_7);
  tcase_add_test(tc_strings, test_s21_strpbrk_8);
  tcase_add_test(tc_strings, test_s21_strpbrk_9);
  return s;
}
