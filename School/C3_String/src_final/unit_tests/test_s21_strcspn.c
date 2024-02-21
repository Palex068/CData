#include "unit_tests.h"

START_TEST(test_s21_strcspn_1) {
  char str_1[50] = "0123456789";
  char str_2[50] = "9876";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_2) {
  char str_1[50] = "xyzbxz";
  char str_2[50] = "abc";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_3) {
  char str_1[50] = "";
  char str_2[50] = "";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_4) {
  char str_1[50] = "";
  char str_2[50] = "abc";
  ck_assert_uint_eq(s21_strcspn(str_1, str_2), strcspn(str_1, str_2));
}
END_TEST

START_TEST(test_s21_strcspn_5) {
  char s1[] = "Hello, world!";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_6) {
  char s1[] = "6";
  char s2[] = "67";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_7) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_8) {
  char s1[] = "69917020";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_9) {
  char s1[] = "699";
  char s2[] = "69917020";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_10) {
  char s1[] = "69917020";
  char s2[] = "699";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_11) {
  char s1[] = "";
  char s2[] = "";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_12) {
  char s1[] = "69917020";
  char s2[] = "6991702H";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_13) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_14) {
  char s1[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  char s2[] =
      "Hello, world!Hello, world!Hello, world!Hello, world!Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_15) {
  char s1[] = "v";
  char s2[] = "vendetta";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

START_TEST(test_s21_strcspn_16) {
  char s1[] = "";
  char s2[] = "Hello, world!";
  ck_assert_int_eq(strcspn(s1, s2), s21_strcspn(s1, s2));
}
END_TEST

Suite *make_strcspn_suite(void) {
  Suite *s = suite_create("strcspn");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strcspn_1);
  tcase_add_test(tc_strings, test_s21_strcspn_2);
  tcase_add_test(tc_strings, test_s21_strcspn_3);
  tcase_add_test(tc_strings, test_s21_strcspn_4);
  tcase_add_test(tc_strings, test_s21_strcspn_5);
  tcase_add_test(tc_strings, test_s21_strcspn_6);
  tcase_add_test(tc_strings, test_s21_strcspn_7);
  tcase_add_test(tc_strings, test_s21_strcspn_8);
  tcase_add_test(tc_strings, test_s21_strcspn_9);
  tcase_add_test(tc_strings, test_s21_strcspn_10);
  tcase_add_test(tc_strings, test_s21_strcspn_11);
  tcase_add_test(tc_strings, test_s21_strcspn_12);
  tcase_add_test(tc_strings, test_s21_strcspn_13);
  tcase_add_test(tc_strings, test_s21_strcspn_14);
  tcase_add_test(tc_strings, test_s21_strcspn_15);
  tcase_add_test(tc_strings, test_s21_strcspn_16);
  return s;
}
