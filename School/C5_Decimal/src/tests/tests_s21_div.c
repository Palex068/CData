#include "tests.h"

START_TEST(div_1_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 5);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_2_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 25);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147418112);
}
END_TEST

START_TEST(div_3_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{3, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);

  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 894784853);
  ck_assert_int_eq(res.bits[1], (unsigned int)-819591186);
  ck_assert_int_eq(res.bits[2], 1807003620);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_4_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{22, 0, 0, 65536}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 48806447);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1898527489);
  ck_assert_int_eq(res.bits[2], (unsigned int)-1830871450);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_5_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{1, 0, 0, 393216}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 10000000);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_6_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{6, 0, 0, 1835008}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 447392427);
  ck_assert_int_eq(res.bits[1], 1737688055);
  ck_assert_int_eq(res.bits[2], 903501810);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_7_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {{658067456, 1164, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 786432);
}
END_TEST

START_TEST(div_8_test) {
  s21_decimal num1 = {{10, 0, 0, 0}};
  s21_decimal num2 = {
      {1879048192, (unsigned int)-1291644761, (unsigned int)-500259693, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_9_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], (unsigned int)-2147483648);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_10_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1073741824);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(div_11_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{3, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1431655765);
  ck_assert_int_eq(res.bits[1], 1431655765);
  ck_assert_int_eq(res.bits[2], 1431655765);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_12_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{22, 0, 0, 65536}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1171354717);
  ck_assert_int_eq(res.bits[1], (unsigned int)-780903145);
  ck_assert_int_eq(res.bits[2], 1952257861);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(div_13_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{658067456, 1164, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 858993459);
  ck_assert_int_eq(res.bits[1], 858993459);
  ck_assert_int_eq(res.bits[2], 858993459);
  ck_assert_int_eq(res.bits[3], 786432);
}
END_TEST

START_TEST(div_14_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {
      {1879048192, (unsigned int)-1291644761, (unsigned int)-500259693, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1227133513);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1840700270);
  ck_assert_int_eq(res.bits[2], 613566756);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_15_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{805306368, (unsigned int)-1167128797, 1626303258, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1431655765);
  ck_assert_int_eq(res.bits[1], 1431655765);
  ck_assert_int_eq(res.bits[2], 1431655765);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_16_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 1835008}};
  s21_decimal num2 = {{2, 0, 0, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], (unsigned int)-2147483648);
  ck_assert_int_eq(res.bits[3], 1835008);
}
END_TEST

START_TEST(div_17_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 1835008}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1073741824);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2145648640);
}
END_TEST

START_TEST(div_18_test) {
  s21_decimal num1 = {{1, 1, 1, 1835008}};
  s21_decimal num2 = {{0, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 3);
}
END_TEST

START_TEST(div_19_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{1, 0, 0, 393216}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 1);
}
END_TEST

START_TEST(div_20_test) {
  s21_decimal num1 = {{1, 0, 0, 1835008}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_div(num1, num2, &res);
  ck_assert_int_eq(status, 2);
}
END_TEST

START_TEST(div_big_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal result_our = {{0, 0, 0, 0}};

  src1.bits[0] = 0b11111111111111111111111111111110;
  src1.bits[1] = 0b11111111111111111111111111111111;
  src1.bits[2] = 0b11111111111111111111111111111111;
  src1.bits[3] = 0b00000000000000000000000000000000;

  src2.bits[0] = 0b00000000000000000000000000000001;
  src2.bits[1] = 0b00000000000000000000000000000000;
  src2.bits[2] = 0b00000000000000000000000000000000;
  src2.bits[3] = 0b00000000000111000000000000000000;
  int val = s21_div(src1, src2, &result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

START_TEST(div_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_div(src1, src2, result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_div(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, div_1_test);
  tcase_add_test(tcase, div_2_test);
  tcase_add_test(tcase, div_3_test);
  tcase_add_test(tcase, div_4_test);
  tcase_add_test(tcase, div_5_test);
  tcase_add_test(tcase, div_6_test);
  tcase_add_test(tcase, div_7_test);
  tcase_add_test(tcase, div_8_test);
  tcase_add_test(tcase, div_9_test);
  tcase_add_test(tcase, div_10_test);
  tcase_add_test(tcase, div_11_test);
  tcase_add_test(tcase, div_12_test);
  tcase_add_test(tcase, div_13_test);
  tcase_add_test(tcase, div_14_test);
  tcase_add_test(tcase, div_15_test);
  tcase_add_test(tcase, div_16_test);
  tcase_add_test(tcase, div_17_test);
  tcase_add_test(tcase, div_18_test);
  tcase_add_test(tcase, div_19_test);
  tcase_add_test(tcase, div_20_test);
  tcase_add_test(tcase, div_big_error);
  tcase_add_test(tcase, div_error);

  return tcase;
}
