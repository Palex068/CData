#include "test_main.h"

START_TEST(test_s21_truncate_1) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 123456;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b00000000000000110000000000000000;
  int val = s21_truncate(src1, &result_our);

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

START_TEST(test_s21_truncate_2) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 87654;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000001000000000000000000;
  int val = s21_truncate(src1, &result_our);
  result_origin.bits[0] = 8;
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

START_TEST(test_s21_truncate_3) {
  s21_decimal src1, result_our, result_origin;
  src1.bits[0] = 87654;
  src1.bits[1] = 0;
  src1.bits[2] = 0;
  src1.bits[3] = 0b10000000000001010000000000000000;
  int val = s21_truncate(src1, &result_our);
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

START_TEST(test_s21_truncate_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_truncate(src1, result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

Suite *s21_other_truncate(void) {
  Suite *s = suite_create("s21_truncate");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);

  tcase_add_test(tc, test_s21_truncate_1);
  tcase_add_test(tc, test_s21_truncate_2);
  tcase_add_test(tc, test_s21_truncate_3);
  tcase_add_test(tc, test_s21_truncate_error);

  return s;
}