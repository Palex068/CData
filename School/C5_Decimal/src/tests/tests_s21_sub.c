#include "tests.h"

START_TEST(sub_1_test) {
  s21_decimal num1 = {{5, 4, 3, 0}};
  s21_decimal num2 = {{3, 1, 2, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_2_test) {
  s21_decimal num1 = {{(unsigned int)-1, (unsigned int)-1, (unsigned int)-1688,
                       (unsigned int)-2147483648}};
  s21_decimal num2 = {{44, 369, 1687, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_3_test) {
  s21_decimal num1 = {{10, 11, 12, (unsigned int)-2147483648}};
  s21_decimal num2 = {{11, 13, 15, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 2);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_4_test) {
  s21_decimal num1 = {
      {(unsigned int)-1, (unsigned int)-1, (unsigned int)-1688, 0}};
  s21_decimal num2 = {{44, 369, 1687, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_5_test) {
  s21_decimal num1 = {{45, 0, 10, (unsigned int)-2147483648}};
  s21_decimal num2 = {{67, 0, 1, (unsigned int)-2147352576}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 4433);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 999);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147352576);
}
END_TEST

START_TEST(sub_6_test) {
  s21_decimal num1 = {{45, 0, 10, 65536}};
  s21_decimal num2 = {{67, 0, 0, 131072}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 383);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 100);
  ck_assert_int_eq(res.bits[3], 131072);
}
END_TEST

START_TEST(sub_7_test) {
  s21_decimal num1 = {
      {(unsigned int)-2, (unsigned int)-1, (unsigned int)-1, 0}};
  s21_decimal num2 = {{5, 0, 0, 65536}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-2);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1);
  ck_assert_int_eq(res.bits[2], (unsigned int)-1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_8_test) {
  s21_decimal num1 = {{(unsigned int)-3, (unsigned int)-1, (unsigned int)-1,
                       (unsigned int)-2147483648}};
  s21_decimal num2 = {{7, 0, 0, (unsigned int)-2147418112}};
  s21_decimal res = {{2, 1, 4, 65536}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-4);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1);
  ck_assert_int_eq(res.bits[2], (unsigned int)-1);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(sub_9_test) {
  s21_decimal num1 = {{0, 0, 10, 0}};
  s21_decimal num2 = {{6, 0, 0, 589824}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], (unsigned int)-1);
  ck_assert_int_eq(res.bits[1], (unsigned int)-1);
  ck_assert_int_eq(res.bits[2], 999999999);
  ck_assert_int_eq(res.bits[3], 524288);
}
END_TEST

START_TEST(sub_10_test) {
  s21_decimal num1 = {{0, 0, 13, (unsigned int)-2147483648}};
  s21_decimal num2 = {{4, 0, 0, (unsigned int)-2146893824}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1300000000);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2146959360);
}
END_TEST

START_TEST(sub_11_test) {
  s21_decimal num1 = {{6, 7, 8, 0}};
  s21_decimal num2 = {{5, 4, 3, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 11);
  ck_assert_int_eq(res.bits[1], 11);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_12_test) {
  s21_decimal num1 = {{3, 1, 3, 0}};
  s21_decimal num2 = {{5, 4, 8, (unsigned int)-2147483648}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 8);
  ck_assert_int_eq(res.bits[1], 5);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(sub_13_test) {
  s21_decimal num1 = {{6, 7, 8, (unsigned int)-2147483648}};
  s21_decimal num2 = {{5, 4, 3, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 11);
  ck_assert_int_eq(res.bits[1], 11);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(sub_14_test) {
  s21_decimal num1 = {{3, 1, 3, (unsigned int)-2147483648}};
  s21_decimal num2 = {{5, 4, 8, 0}};
  s21_decimal res = {{0, 0, 0, 0}};
  int status = s21_sub(num1, num2, &res);
  ck_assert_int_eq(status, 0);
  ck_assert_int_eq(res.bits[0], 8);
  ck_assert_int_eq(res.bits[1], 5);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], (unsigned int)-2147483648);
}
END_TEST

START_TEST(sub_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal src2 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_sub(src1, src2, result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_sub(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, sub_1_test);
  tcase_add_test(tcase, sub_2_test);
  tcase_add_test(tcase, sub_3_test);
  tcase_add_test(tcase, sub_4_test);
  tcase_add_test(tcase, sub_5_test);
  tcase_add_test(tcase, sub_6_test);
  tcase_add_test(tcase, sub_7_test);
  tcase_add_test(tcase, sub_8_test);
  tcase_add_test(tcase, sub_9_test);
  tcase_add_test(tcase, sub_10_test);
  tcase_add_test(tcase, sub_11_test);
  tcase_add_test(tcase, sub_12_test);
  tcase_add_test(tcase, sub_13_test);
  tcase_add_test(tcase, sub_14_test);
  tcase_add_test(tcase, sub_error);

  return tcase;
}
