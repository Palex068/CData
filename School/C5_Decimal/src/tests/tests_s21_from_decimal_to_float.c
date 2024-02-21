#include "tests.h"

START_TEST(test_s21_dec_to_float_003f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  float test = 0.03;

  result.bits[0] = 0b01001010111100011001001011000000;
  result.bits[1] = 0b00111001010010010101100101000000;
  result.bits[2] = 0b00000000111110000010011101111000;
  result.bits[3] = 0b00000000000111000000000000000000;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_ldouble_eq_tol(check, test, 1e-6);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_18122f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  float test = 18.122;
  result.bits[0] = 18122;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000110000000000000000;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_ldouble_eq_tol(check, test, 1e-6);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_m003f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  float test = -0.03;
  result.bits[0] = 0b01001010111100011001001011000000;
  result.bits[1] = 0b00111001010010010101100101000000;
  result.bits[2] = 0b00000000111110000010011101111000;
  result.bits[3] = 0b10000000000111000000000000000000;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_ldouble_eq_tol(check, test, 1e-6);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_18_122f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 18122;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  set_exp(&result, 3);

  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, 18.122);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_m1812) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 1812;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = S21_MINUS;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, -1812);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_16777215f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0XFFFFFF;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, 16777215);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_12345_6789f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 123456789;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0;
  set_exp(&result, 4);
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, 12345.6789);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_UNIT_MAX) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = UINT_MAX;
  result.bits[1] = UINT_MAX;
  result.bits[2] = 0;
  result.bits[3] = 0;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_m1234_5678f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 123456789;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = S21_MINUS;
  set_exp(&result, 4);
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, -12345.6789F);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_2546_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 25465;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 2546.5);
  snprintf(check_result, sizeof(result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m0_46453f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 46453;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", -0.46453);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_3_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 35;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 3.5);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_4_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 45;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b00000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 4.5);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m4_5f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0b00000000000000000000000000101101;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b10000000000000010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", -4.5);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m5_49265f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0b00000000000010000110000110010001;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 0b10000000000001010000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", -5.49265);
  snprintf(check_result, sizeof(flt2str), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_2_508f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 0b01100101111011101101100101011111;
  result.bits[1] = 0b01011100001001010100001101000110;
  result.bits[2] = 0b00000000000000000000000000000001;
  result.bits[3] = 0b00000000000100110000000000000000;
  s21_from_decimal_to_float(result, &check);
  char flt2str[1000];
  char check_result[1000];
  snprintf(flt2str, sizeof(flt2str), "%.6f", 2.50865312689741);
  snprintf(check_result, sizeof(check_result), "%f", check);
  ck_assert_str_eq(check_result, flt2str);
}
END_TEST

START_TEST(test_s21_dec_to_float_m18_122f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 18122;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147680256;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, -18.122);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_m1812f) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 1812;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = S21_MINUS;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, -1812);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_m2345_09) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = 23450987;
  result.bits[1] = 0;
  result.bits[2] = 0;
  result.bits[3] = 2147745792;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq_tol(check, -2345.09, 1e-1);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_UINT_MAX_UINT_MAX) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 0.f;
  result.bits[0] = UINT_MAX;
  result.bits[1] = UINT_MAX;
  result.bits[2] = 0;
  result.bits[3] = 0;
  int err = s21_from_decimal_to_float(result, &check);
  ck_assert_float_eq(check, 0xFFFFFFFFFFFFFFFF);
  ck_assert_int_eq(err, S21_OK);
}
END_TEST

START_TEST(test_s21_dec_to_float_scale_error) {
  s21_decimal result = {{0, 0, 0, 0}};
  float check = 1.1f;
  // float test = 0.f;
  // result.bits[0] = 0b01001010111100011001001011000000;
  // result.bits[1] = 0b00111001010010010101100101000000;
  // result.bits[2] = 0b00000000111110000010011101111000;
  result.bits[3] = 0b10000000000111010000000000000000;
  int err = s21_from_decimal_to_float(result, &check);
  // ck_assert_ldouble_eq_tol(check, test, 1e-6);
  ck_assert_int_eq(err, S21_ERROR);
}
END_TEST

START_TEST(test_s21_dec_to_float_null_error) {
  float *check = NULL;
  s21_decimal test = {{
      0,
      0,
      0,
      0,
  }};
  int val = s21_from_decimal_to_float(test, check);
  ck_assert_int_eq(val, S21_ERROR);
}
END_TEST

TCase *tests_s21_decimal_to_float(void) {
  TCase *tcase = tcase_create(TCASE_NAME);

  tcase_add_test(tcase, test_s21_dec_to_float_003f);
  tcase_add_test(tcase, test_s21_dec_to_float_18122f);
  tcase_add_test(tcase, test_s21_dec_to_float_m003f);
  tcase_add_test(tcase, test_s21_dec_to_float_18_122f);
  tcase_add_test(tcase, test_s21_dec_to_float_m1812);
  tcase_add_test(tcase, test_s21_dec_to_float_16777215f);
  tcase_add_test(tcase, test_s21_dec_to_float_12345_6789f);
  tcase_add_test(tcase, test_s21_dec_to_float_UNIT_MAX);
  tcase_add_test(tcase, test_s21_dec_to_float_m1234_5678f);
  tcase_add_test(tcase, test_s21_dec_to_float_2546_5f);
  tcase_add_test(tcase, test_s21_dec_to_float_m0_46453f);
  tcase_add_test(tcase, test_s21_dec_to_float_3_5f);
  tcase_add_test(tcase, test_s21_dec_to_float_4_5f);
  tcase_add_test(tcase, test_s21_dec_to_float_m4_5f);
  tcase_add_test(tcase, test_s21_dec_to_float_m5_49265f);
  tcase_add_test(tcase, test_s21_dec_to_float_2_508f);
  tcase_add_test(tcase, test_s21_dec_to_float_m18_122f);
  tcase_add_test(tcase, test_s21_dec_to_float_m1812f);
  tcase_add_test(tcase, test_s21_dec_to_float_16777215f);
  tcase_add_test(tcase, test_s21_dec_to_float_m2345_09);
  tcase_add_test(tcase, test_s21_dec_to_float_UINT_MAX_UINT_MAX);
  tcase_add_test(tcase, test_s21_dec_to_float_scale_error);
  tcase_add_test(tcase, test_s21_dec_to_float_null_error);

  return tcase;
}
