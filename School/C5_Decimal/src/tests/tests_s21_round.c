#include "tests.h"

START_TEST(test_s21_round_1) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 123456;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000110000000000000000;
  int val = s21_round(src1, &result_our);

  result_origin.bits[0] = 123;
  result_origin.bits[1] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[3] = 0;
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(val, S21_OK);
}
END_TEST

START_TEST(test_s21_round_2) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 87654;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000001000000000000000000;
  int val = s21_round(src1, &result_our);
  result_origin.bits[0] = 9;
  result_origin.bits[1] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[3] = S21_MINUS;
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(val, S21_OK);
}
END_TEST

START_TEST(test_s21_round_3) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 11;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000010000000000000000;
  int val = s21_round(src1, &result_our);
  result_origin.bits[0] = 1;
  result_origin.bits[1] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[3] = S21_MINUS;
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(val, S21_OK);
}
END_TEST

START_TEST(test_s21_round_4) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 23;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000000110000000000000000;
  int val = s21_round(src1, &result_our);
  result_origin.bits[0] = 0;
  result_origin.bits[1] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[3] = 0;
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(val, S21_OK);
}
END_TEST

START_TEST(test_s21_round_5) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 53;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000100000000000000000;
  int val = s21_round(src1, &result_our);
  result_origin.bits[0] = 1;
  result_origin.bits[1] = 0;
  result_origin.bits[2] = 0;
  result_origin.bits[3] = 0;
  ck_assert_int_eq(result_origin.bits[0], result_our.bits[0]);
  ck_assert_int_eq(result_origin.bits[1], result_our.bits[1]);
  ck_assert_int_eq(result_origin.bits[2], result_our.bits[2]);
  ck_assert_int_eq(result_origin.bits[3], result_our.bits[3]);
  ck_assert_int_eq(val, S21_OK);
}
END_TEST

START_TEST(test_s21_round_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_round(src1, result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_round(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_s21_round_1);
  tcase_add_test(tcase, test_s21_round_2);
  tcase_add_test(tcase, test_s21_round_3);
  tcase_add_test(tcase, test_s21_round_4);
  tcase_add_test(tcase, test_s21_round_5);
  tcase_add_test(tcase, test_s21_round_error);

  return tcase;
}
