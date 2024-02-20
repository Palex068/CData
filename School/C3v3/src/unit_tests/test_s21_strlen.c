#include "unit_tests.h"

START_TEST(test_s21_strlen_1) {
  char str_1[50] = "Hello";
  ck_assert_int_eq(s21_strlen(str_1), strlen(str_1));
}
END_TEST

START_TEST(test_s21_strlen_2) {
  char str_1[50] = "\0dlks;ldk;ldskf";
  ck_assert_int_eq(s21_strlen(str_1), strlen(str_1));
}
END_TEST

START_TEST(test_s21_strlen_3) {
  char str_1[50] = "";
  ck_assert_int_eq(s21_strlen(str_1), strlen(str_1));
}
END_TEST

START_TEST(test_s21_strlen_4) {
  char str[] = "\0";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_5) {
  char str[] =
      "I hate doing tests, it's not funny at all!!!!!!!!!!!!!!!!!!!!!!!!!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_6) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_7) {
  char str[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_8) {
  char str[] = "          00000000           ......  ";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_9) {
  char str[] = "\n\n\n\n\n\n\n\n\nlololol\n\n\n\n\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_10) {
  char str[] = "\0\0\0\0\n";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_11) {
  char str[] = "";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_12) {
  char str[] = "\t\t";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_13) {
  char str[] = "\0test";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_14) {
  char str[] = "wtf \0 wtf";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_15) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_16) {
  char str[] =
      "213145346758697808-9704=3524-1309876289403-5=6576=432=-31044253=60931 "
      "21";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

START_TEST(test_s21_strlen_17) {
  char str[] = "Hello, world!";
  ck_assert_int_eq(strlen(str), s21_strlen(str));
}
END_TEST

Suite *make_strlen_suite(void) {
  Suite *s = suite_create("strlen");
  TCase *tc_strings = tcase_create("strings");
  suite_add_tcase(s, tc_strings);
  tcase_add_test(tc_strings, test_s21_strlen_1);
  tcase_add_test(tc_strings, test_s21_strlen_2);
  tcase_add_test(tc_strings, test_s21_strlen_3);
  tcase_add_test(tc_strings, test_s21_strlen_4);
  tcase_add_test(tc_strings, test_s21_strlen_5);
  tcase_add_test(tc_strings, test_s21_strlen_6);
  tcase_add_test(tc_strings, test_s21_strlen_7);
  tcase_add_test(tc_strings, test_s21_strlen_8);
  tcase_add_test(tc_strings, test_s21_strlen_9);
  tcase_add_test(tc_strings, test_s21_strlen_10);
  tcase_add_test(tc_strings, test_s21_strlen_11);
  tcase_add_test(tc_strings, test_s21_strlen_12);
  tcase_add_test(tc_strings, test_s21_strlen_13);
  tcase_add_test(tc_strings, test_s21_strlen_14);
  tcase_add_test(tc_strings, test_s21_strlen_15);
  tcase_add_test(tc_strings, test_s21_strlen_16);
  tcase_add_test(tc_strings, test_s21_strlen_17);
  return s;
}
