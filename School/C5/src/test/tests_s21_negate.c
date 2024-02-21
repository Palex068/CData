#include "../tests.h"

START_TEST(test_s21_negate_minus_1) {
  unsigned int test = 1;
  s21_decimal value = {{test, 0, 0, 0x80000000}};
  s21_decimal result = {{test, 0, 0, 0x00000000}};

  s21_negate(value, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_negate_plus_1) {
  unsigned int test = 1;
  s21_decimal value = {{test, 0, 0, 0x00000000}};
  s21_decimal result = {{test, 0, 0, 0x80000000}};

  s21_negate(value, &value);
  ck_assert_int_eq(value.bits[0], result.bits[0]);
  ck_assert_int_eq(value.bits[1], result.bits[1]);
  ck_assert_int_eq(value.bits[2], result.bits[2]);
  ck_assert_int_eq(value.bits[3], result.bits[3]);
}
END_TEST

START_TEST(test_s21_negate_error) {
  s21_decimal src1 = {{0, 0, 0, 0}};
  s21_decimal *result_our = NULL;
  int val = s21_negate(src1, result_our);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_negate(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_s21_negate_minus_1);
  tcase_add_test(tcase, test_s21_negate_plus_1);
  tcase_add_test(tcase, test_s21_negate_error);

  return tcase;
}
