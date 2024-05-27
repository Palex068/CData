#include "test_main.h"

START_TEST(s21_add_0_simple) {
  s21_decimal dec1 = {{0, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{0, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, POSITIVE}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_1_simple) {
  s21_decimal dec1 = {{90, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{57, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{147, 0, 0, POSITIVE}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_2_simple) {
  s21_decimal dec1 = {{0, UINT32_MAX, 0, POSITIVE}};
  s21_decimal dec2 = {{0, INT32_MAX, 0, NEGATIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, scomp(2147483648), 0, POSITIVE}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_3_simple) {
  s21_decimal dec1 = {{INT16_MAX, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{UINT16_MAX, 0, 0, NEGATIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{32768, 0, 0, NEGATIVE}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_4_simple) {
  s21_decimal dec1 = {{1, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{0, 1, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{1, 1, 0, POSITIVE}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_5_simple) {
  s21_decimal dec1 = {{-1, -1, 56648, POSITIVE}};
  s21_decimal dec2 = {{44, 369, 1687, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 43);
  ck_assert_int_eq(res.bits[1], 369);
  ck_assert_int_eq(res.bits[2], 58336);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_6_simple) {
  s21_decimal dec1 = {{-1, -1, -1688, POSITIVE}};
  s21_decimal dec2 = {{44, 369, 1687, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_7_scale) {
  s21_decimal dec1 = {{101, 0, 0, POSITIVE + SCALE(3)}};
  s21_decimal dec2 = {{9, 0, 0, NEGATIVE + SCALE(2)}};
  s21_decimal res = {0};
  s21_decimal answer = {{11, 0, 0, POSITIVE + SCALE(3)}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_8_scale) {
  s21_decimal dec1 = {
      {UINT32_MAX, UINT32_MAX, UINT32_MAX, POSITIVE + SCALE(0)}};
  s21_decimal dec2 = {{6, 0, 0, NEGATIVE + SCALE(1)}};
  s21_decimal res = {0};
  s21_decimal answer = {{UINT32_MAX - 1, -1, -1, POSITIVE + SCALE(0)}};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_add_9_simple) {
  s21_decimal dec1 = {{-1, -1, 56648, NEGATIVE}};
  s21_decimal dec2 = {{44, 369, 1687, NEGATIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 43);
  ck_assert_int_eq(res.bits[1], 369);
  ck_assert_int_eq(res.bits[2], 58336);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_add_10_error) {
  s21_decimal dec1 = {{-1, -1, -1688, NEGATIVE}};
  s21_decimal dec2 = {{44, 369, 1687, NEGATIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_11_scale) {
  s21_decimal dec1 = {{45, 0, 10, NEGATIVE}};
  s21_decimal dec2 = {{67, 0, 0, scomp(SCALE(2) + NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 4567);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1000);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(2) + NEGATIVE));
}
END_TEST

START_TEST(s21_add_12_scale) {
  s21_decimal dec1 = {{45, 0, 10, SCALE(1)}};
  s21_decimal dec2 = {{67, 0, 0, SCALE(2)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 517);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 100);
  ck_assert_int_eq(res.bits[3], SCALE(2));
}
END_TEST

START_TEST(s21_add_13_scale) {
  s21_decimal dec1 = {{-2, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{5, 0, 0, SCALE(1)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -2);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], -1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_14_scale) {
  s21_decimal dec1 = {{UINT32_MAX - 2, UINT32_MAX, UINT32_MAX, NEGATIVE}};
  s21_decimal dec2 = {{7, 0, 0, scomp(SCALE(1) + NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -2);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], -1);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_add_15_scale) {
  s21_decimal dec1 = {{0, 0, 10, POSITIVE}};  // это число 184467440737095516160
  s21_decimal dec2 = {{6, 0, 0, SCALE(9)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1000000000);
  ck_assert_int_eq(res.bits[3],
                   SCALE(8));  // 184467440737095516160.00000000 i.e. (SCALE(8))
}
END_TEST

START_TEST(s21_add_16_scale) {
  s21_decimal dec1 = {{0, 0, 13, NEGATIVE}};
  s21_decimal dec2 = {{135676145, 0, 0, scomp(SCALE(9) + NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 13567614);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1300000000);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(8) + NEGATIVE));
}
END_TEST

START_TEST(s21_add_16a_scale) {
  s21_decimal dec1 = {{0, 0, 13, NEGATIVE}};
  s21_decimal dec2 = {{135676165, 0, 0, scomp(SCALE(9) + NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 13567616);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1300000000);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(8) + NEGATIVE));
}
END_TEST

START_TEST(s21_add_17_simple) {
  s21_decimal dec1 = {{6, 7, 8, 0}};
  s21_decimal dec2 = {{5, 4, 3, NEGATIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_18_simple) {
  s21_decimal dec1 = {{3, 1, 3, 0}};
  s21_decimal dec2 = {{5, 4, 8, NEGATIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_add_19_simple) {
  s21_decimal dec1 = {{6, 7, 8, scomp(NEGATIVE)}};
  s21_decimal dec2 = {{5, 4, 3, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_add_20_simple) {
  s21_decimal dec1 = {{3, 1, 3, NEGATIVE}};
  s21_decimal dec2 = {{5, 4, 8, 0}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 5);
  ck_assert_int_eq(res.bits[3], POSITIVE);
}
END_TEST

START_TEST(s21_add_21_scale) {
  s21_decimal dec1 = {{0, 0, 0, 0}};
  s21_decimal dec2 = {{5, 0, 0, SCALE(1)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 5);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(1));
}
END_TEST

START_TEST(s21_add_22_error) {
  s21_decimal dec1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_23_error) {
  s21_decimal dec1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, NEGATIVE}};
  s21_decimal dec2 = {{1, 0, 0, NEGATIVE}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_add_24_scale) {
  s21_decimal dec1 = {{0, 0, 13, NEGATIVE}};
  s21_decimal dec2 = {{135676145, 0, 0, scomp(SCALE(8) + POSITIVE)}};
  s21_decimal res = {0};
  int error = s21_add(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], scomp(4159291151));  // -135676145
  ck_assert_int_eq(res.bits[1], scomp(4294967295));  // -1
  ck_assert_int_eq(res.bits[2], 1299999999);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(8) + NEGATIVE));
}
END_TEST

Suite *s21_arithmetic_add_suite() {
  Suite *s = suite_create("s21_arithmetic_add");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_add_0_simple);
  tcase_add_test(tc, s21_add_1_simple);
  tcase_add_test(tc, s21_add_2_simple);
  tcase_add_test(tc, s21_add_3_simple);
  tcase_add_test(tc, s21_add_4_simple);
  tcase_add_test(tc, s21_add_5_simple);
  tcase_add_test(tc, s21_add_6_simple);
  tcase_add_test(tc, s21_add_7_scale);
  tcase_add_test(tc, s21_add_8_scale);
  tcase_add_test(tc, s21_add_9_simple);
  tcase_add_test(tc, s21_add_10_error);
  tcase_add_test(tc, s21_add_11_scale);
  tcase_add_test(tc, s21_add_12_scale);
  tcase_add_test(tc, s21_add_13_scale);
  tcase_add_test(tc, s21_add_14_scale);
  tcase_add_test(tc, s21_add_15_scale);
  tcase_add_test(tc, s21_add_16_scale);
  tcase_add_test(tc, s21_add_16a_scale);
  tcase_add_test(tc, s21_add_17_simple);
  tcase_add_test(tc, s21_add_18_simple);
  tcase_add_test(tc, s21_add_19_simple);
  tcase_add_test(tc, s21_add_20_simple);
  tcase_add_test(tc, s21_add_21_scale);
  tcase_add_test(tc, s21_add_22_error);
  tcase_add_test(tc, s21_add_23_error);
  tcase_add_test(tc, s21_add_24_scale);

  return s;
}