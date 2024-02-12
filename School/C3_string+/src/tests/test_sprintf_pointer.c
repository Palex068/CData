#include "test_me.h"

// One parameter pointer
START_TEST(sprintf_1_pointer) {
  char str1[100] = "";
  char str2[100] = "";
  char* str3 = "Test %p Test";
  char* val = "0p32";
  ck_assert_int_eq(sprintf(str1, str3, val), s21_sprintf(str2, str3, val));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three pointer parameters
START_TEST(sprintf_2_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%p Test %p Test %p";
  char* val = "0p7a4";
  char* val2 = "0p91ba123f";
  char* val3 = "0p3123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Three decimal parameters
START_TEST(sprintf_3_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%p Test %p Test %p";
  char* val = "0p3015";
  char* val2 = "0p712";
  char* val3 = "0p99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different sizes
START_TEST(sprintf_4_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%p Test %p Test %p GOD %p";
  long int* val = (void*)3088675747373646;
  long long int* val2 = (void*)33030030303;
  unsigned short int* val3 = (void*)22600;
  unsigned char* val4 = (void*)120;
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different width
START_TEST(sprintf_5_pointer) {
  char str1[100];
  char str2[100];
  char* str3 = "%3p Test %5p Test %12p";
  char* val = "3015";
  char* val2 = "01234";
  char* val3 = "99";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3),
                   s21_sprintf(str2, str3, val, val2, val3));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Different precision and width
START_TEST(sprintf_6_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%6.5p Test %.23p Test %3.p TEST %.p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "38";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Minus flag
START_TEST(sprintf_7_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%-10.5p Test %-.4p Test %-16p TEST %-.5p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Zeroes
START_TEST(sprintf_8_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%0p Test %0.p Test %0.0p TEST %0p GOD %.p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  char* val5 = "0123";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Pluses
START_TEST(sprintf_9_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%p Test %3.p Test %5.7p TEST %10p";
  char* val = "3015";
  char* val2 = "712";
  char* val3 = "99";
  char* val4 = "2939";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4),
                   s21_sprintf(str2, str3, val, val2, val3, val4));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Spaces
START_TEST(sprintf_11_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%p Test %3.p Test %5.7p TEST %10p GOD %.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "23";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Plus
START_TEST(sprintf_12_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%p Test %3.p Test %5.7p TEST %10p GOD %.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "3261";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Hash
START_TEST(sprintf_13_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%#p Test %#3p Test %#5.7p TEST %#.7p Oof %#.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// ZERO flag
START_TEST(sprintf_14_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%0p Test %06p Test %05.7p TEST %0.7p Oof %0.p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "91918";
  char* val4 = "32311";
  char* val5 = "8894";
  ck_assert_int_eq(sprintf(str1, str3, val, val2, val3, val4, val5),
                   s21_sprintf(str2, str3, val, val2, val3, val4, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

// Asterisk
START_TEST(sprintf_15_pointer) {
  char str1[200];
  char str2[200];
  char* str3 = "%*p Test %-*p Test %*.*p TEST %.*p Lololol %.*p";
  char* val = "32";
  char* val2 = "8899";
  char* val3 = "9193112312312";
  char* val4 = "32311";
  char* val5 = "WTF cmon";
  int ast = 2;
  int ast2 = 5;
  int ast3 = 4;
  int ast4 = 10;
  int ast5 = 7;
  int ast6 = 18;
  ck_assert_int_eq(sprintf(str1, str3, ast, val, ast2, val2, ast3, ast4, val3,
                           ast5, val4, ast6, val5),
                   s21_sprintf(str2, str3, ast, val, ast2, val2, ast3, ast4,
                               val3, ast5, val4, ast6, val5));
  ck_assert_pstr_eq(str1, str2);
}
END_TEST

Suite* test_sprintf_pointer(void) {
  Suite* s = suite_create("\033[45m-=S21_SPRINTF_POINTER=-\033[0m");
  TCase* tc = tcase_create("sprintf_tc");

  tcase_add_test(tc, sprintf_1_pointer);
  tcase_add_test(tc, sprintf_2_pointer);
  tcase_add_test(tc, sprintf_3_pointer);
  tcase_add_test(tc, sprintf_4_pointer);
  tcase_add_test(tc, sprintf_5_pointer);
  tcase_add_test(tc, sprintf_6_pointer);
  tcase_add_test(tc, sprintf_7_pointer);
  tcase_add_test(tc, sprintf_8_pointer);
  tcase_add_test(tc, sprintf_9_pointer);
  tcase_add_test(tc, sprintf_11_pointer);
  tcase_add_test(tc, sprintf_12_pointer);
  tcase_add_test(tc, sprintf_13_pointer);
  tcase_add_test(tc, sprintf_14_pointer);
  tcase_add_test(tc, sprintf_15_pointer);

  suite_add_tcase(s, tc);
  return s;
}
