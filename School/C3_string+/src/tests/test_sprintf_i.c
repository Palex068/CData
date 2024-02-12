#include "test_me.h"

// One parameter signed_i
START_TEST(sprintf_1_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "Test %d Test";
  int val = -12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three signed_i parameters
START_TEST(sprintf_2_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%d Test %d Test %d";
  int val = 012;
  int val2 = -017;
  int val3 = 07464;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%i Test %i Test %i";
  int val = 3015;
  int val2 = 712;
  int val3 = 99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%li Test %li Test %hi GOD %hi";
  long int val = 3088675747373646;
  signed long val2 = -125;
  short int val3 = -22600;
  short val4 = 120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_signed_i) {
  char str1[100];
  char str2[100];
  char *str3 = "%3i Test %5i Test %10i";
  int val = -3015;
  int val2 = -11234;
  int val3 = -99;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%6.5i Test %.23i Test %3.i TEST %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -38;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%-10.5i Test %-.8i Test %-7i TEST %-.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0i Test %0.i Test %0.0i TEST %0i GOD %.i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  int val5 = -0123;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i";
  int val = -3015;
  int val2 = -712;
  int val3 = -99;
  int val4 = -2939;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zero vals
START_TEST(sprintf_10_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%i Test %3.i Test %5.7i TEST %10i %#i %-i %+i %.i % .i";
  int val = 0;
  ck_assert_int_eq(
      sprintf(str1, str3, val, val, val, val, val, val, val, val, val),
      s21_sprintf(str2, str3, val, val, val, val, val, val, val, val, val,
                  val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "% i Test % 3.i Test % 5.7i TEST % 10i GOD %.i";
  int val = -32;
  int val2 = -8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -23;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%+i Test %+3.i Test %+5.7i TEST %+10i GOD %+.i";
  int val = -32;
  int val2 = -8899;
  int val3 = 91918;
  int val4 = -32311;
  int val5 = 3261;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%#i Test %#3i Test %#5.7i TEST %#.7i Oof %#.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = 32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%0d Test %06i Test %05.7i TEST %0.7i Oof %0.i";
  int val = -32;
  int val2 = 8899;
  int val3 = -91918;
  int val4 = -32311;
  int val5 = -8894;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%*i Test %-*i Test %*.*i TEST %.*i";
  int val = 32;
  int val2 = 8899;
  int val3 = -919;
  int val4 = 32311;
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  ck_assert_int_eq(
      sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5, val4),
      s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4, val3, ast5,
                  val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Simple extra test
START_TEST(sprintf_16_signed_i) {
  char str1[100] = "";
  char str2[100] = "";
  char *str3 = "%i";
  int val = 12;
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

START_TEST(sprintf_17_signed_i) {
  char str1[200];
  char str2[200];
  char *str3 = "%- i Test %- 15i sdasda %- 15i sdsad %- i";
  int val = -3231;
  int val2 = -3231;
  int val3 = 3231;
  int val4 = 3231;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite *test_sprintf_signed_i(void) {
  Suite *s = suite_create("\033[45m-=S21_SPRINTF_SIGNED_I=-\033[0m");
  TCase *tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_signed_i);
  tcase_add_test(tc, sprintf_2_signed_i);
  tcase_add_test(tc, sprintf_3_signed_i);
  tcase_add_test(tc, sprintf_4_signed_i);
  tcase_add_test(tc, sprintf_5_signed_i);
  tcase_add_test(tc, sprintf_6_signed_i);
  tcase_add_test(tc, sprintf_7_signed_i);
  tcase_add_test(tc, sprintf_8_signed_i);
  tcase_add_test(tc, sprintf_9_signed_i);
  tcase_add_test(tc, sprintf_10_signed_i);
  tcase_add_test(tc, sprintf_11_signed_i);
  tcase_add_test(tc, sprintf_12_signed_i);
  tcase_add_test(tc, sprintf_13_signed_i);
  tcase_add_test(tc, sprintf_14_signed_i);
  tcase_add_test(tc, sprintf_15_signed_i);
  tcase_add_test(tc, sprintf_16_signed_i);
  tcase_add_test(tc, sprintf_17_signed_i);

  suite_add_tcase(s, tc);
  return s;
}
