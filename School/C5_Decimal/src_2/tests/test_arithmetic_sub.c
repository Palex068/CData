#include "test_main.h"

START_TEST(s21_sub_0_simple) {
  s21_decimal dec1 = {{0, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{0, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, POSITIVE}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_1_simple) {
  s21_decimal dec1 = {{0, 0, INT16_MAX, NEGATIVE}};
  s21_decimal dec2 = {{0, 0, INT32_MAX, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 2147516414, NEGATIVE}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_2_simple) {
  s21_decimal dec1 = {{0, 0, INT16_MAX, POSITIVE}};
  s21_decimal dec2 = {{0, 0, INT32_MAX, NEGATIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 2147516414, POSITIVE}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_3_simple) {
  s21_decimal dec1 = {{0b1011010, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{0b111001, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0b100001, 0, 0, POSITIVE}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_4_simple) {
  s21_decimal dec1 = {{101, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{1001, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{900, 0, 0, NEGATIVE}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_5_error) {
  s21_decimal dec1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, NEGATIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, POSITIVE}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 1);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_6_error) {
  s21_decimal dec1 = {{UINT32_MAX, UINT32_MAX, UINT32_MAX, NEGATIVE}};
  s21_decimal dec2 = {{1, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 2);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_7_scale) {
  s21_decimal dec1 = {{9, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, POSITIVE + SCALE(1)}};
  s21_decimal res = {0};
  s21_decimal answer = {{89, 0, 0, POSITIVE + SCALE(1)}};
  int error = s21_sub(dec1, dec2, &res);

  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_sub_8_scale) {
  s21_decimal dec1 = {{0, 0, 10, POSITIVE}};  // 184467440737095516160
  s21_decimal num2 = {{6, 0, 0, POSITIVE + SCALE(9)}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -1);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], 999999999);
  ck_assert_int_eq(res.bits[3], SCALE(8));  // 184467440737095516159.99999999
}
END_TEST

START_TEST(s21_sub_9_scale) {
  s21_decimal dec1 = {{0, 0, 13, NEGATIVE}};  // -239807672958224171008
  s21_decimal num2 = {
      {135676145, 0, 0, scomp(SCALE(9) + NEGATIVE)}};  // 0.135676145
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], scomp(4281399682));
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], 1299999999);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(8) + NEGATIVE));
}
END_TEST

START_TEST(s21_sub_9a_scale) {
  s21_decimal dec1 = {{0, 0, 13, NEGATIVE}};  // -239807672958224171008
  s21_decimal num2 = {
      {135676155, 0, 0, scomp(SCALE(9) + NEGATIVE)}};  // 0.135676155
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], scomp(4281399680));
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], 1299999999);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(8) + NEGATIVE));
}
END_TEST

START_TEST(s21_sub_10_error) {
  s21_decimal dec1 = {{-1, -1, -1688, NEGATIVE}};  // -1688 = 4294965608
  s21_decimal num2 = {{44, 369, 1687, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_11_scale) {
  s21_decimal dec1 = {
      {-1, -1, -1, POSITIVE + SCALE(1)}};  // 7922816251426433759354395033.5
  s21_decimal num2 = {{-1, -1, -1, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1717986917);
  ck_assert_int_eq(res.bits[1], 1717986918);
  ck_assert_int_eq(res.bits[2], scomp(3865470566));
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_sub_12_error) {
  s21_decimal dec1 = {{-1, -1, -1688, POSITIVE}};  // -1688 = 4294965608
  s21_decimal num2 = {{0, 0, 1688, NEGATIVE}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_13_scale) {
  s21_decimal dec1 = {
      {-1, -1, -1, POSITIVE + SCALE(0)}};  // 7 9228162514264337593543950335
  s21_decimal num2 = {
      {1550960413, 463383481, 240933816,
       POSITIVE + SCALE(28)}};  // 0.4444444444444444444444444445
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -1);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], -1);
  ck_assert_int_eq(res.bits[3], POSITIVE);
}
END_TEST

START_TEST(s21_sub_14_simple) {
  s21_decimal dec1 = {{5, 4, 3, 0}};
  s21_decimal num2 = {{3, 1, 2, 0}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 3);
  ck_assert_int_eq(res.bits[2], 1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_15_error) {
  s21_decimal dec1 = {{-1, -1, -1688, NEGATIVE}};
  s21_decimal num2 = {{44, 369, 1687, 0}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 2);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_16_simple) {
  s21_decimal dec1 = {{10, 11, 12, scomp(NEGATIVE)}};
  s21_decimal num2 = {{11, 13, 15, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 2);
  ck_assert_int_eq(res.bits[2], 3);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_17_simple) {
  s21_decimal dec1 = {{-1, -1, -1688, 0}};
  s21_decimal num2 = {{44, 369, 1687, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 1);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_18_scale) {
  s21_decimal dec1 = {{45, 0, 10, scomp(NEGATIVE)}};
  s21_decimal num2 = {{67, 0, 1, scomp(NEGATIVE + SCALE(2))}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 4433);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 999);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE + SCALE(2)));
}
END_TEST

START_TEST(s21_sub_19_scale) {
  s21_decimal dec1 = {{45, 0, 10, SCALE(1)}};  // 18446744073709551620.50
  s21_decimal num2 = {{67, 0, 0, SCALE(2)}};   //                    0.67
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 383);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 100);
  ck_assert_int_eq(res.bits[3], SCALE(2));  // 1844674407370955161983
}
END_TEST

START_TEST(s21_sub_20_scale) {
  s21_decimal dec1 = {{-2, -1, -1, 0}};      // 79228162514264337593543950334
  s21_decimal num2 = {{5, 0, 0, SCALE(1)}};  // 0.5
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -2);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], -1);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_21_scale) {
  s21_decimal dec1 = {{-3, -1, -1, scomp(NEGATIVE)}};
  s21_decimal num2 = {
      {7, 0, 0, scomp(SCALE(1) + NEGATIVE)}};  // это SCALE(1) и NEGATIVE
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -4);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], -1);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_sub_22_scale) {
  s21_decimal dec1 = {{0, 0, 10, 0}};
  s21_decimal num2 = {{6, 0, 0, SCALE(9)}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], -1);
  ck_assert_int_eq(res.bits[1], -1);
  ck_assert_int_eq(res.bits[2], 999999999);
  ck_assert_int_eq(res.bits[3], SCALE(8));
}
END_TEST

START_TEST(s21_sub_23_scale) {
  s21_decimal dec1 = {{0, 0, 13, scomp(NEGATIVE)}};
  s21_decimal num2 = {{4, 0, 0, scomp(NEGATIVE + SCALE(9))}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1300000000);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE + SCALE(8)));
}
END_TEST

START_TEST(s21_sub_24_simple) {
  s21_decimal dec1 = {{6, 7, 8, POSITIVE}};
  s21_decimal num2 = {{5, 4, 3, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 11);
  ck_assert_int_eq(res.bits[1], 11);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_25_simple) {
  s21_decimal dec1 = {{3, 1, 3, POSITIVE}};
  s21_decimal num2 = {{5, 4, 8, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 8);
  ck_assert_int_eq(res.bits[1], 5);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_sub_26_simple) {
  s21_decimal dec1 = {{6, 7, 8, scomp(NEGATIVE)}};
  s21_decimal num2 = {{5, 4, 3, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 11);
  ck_assert_int_eq(res.bits[1], 11);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_sub_27_simple) {
  s21_decimal dec1 = {{3, 1, 3, scomp(NEGATIVE)}};
  s21_decimal num2 = {{5, 4, 8, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 8);
  ck_assert_int_eq(res.bits[1], 5);
  ck_assert_int_eq(res.bits[2], 11);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_sub_28_simple) {
  s21_decimal dec1 = {{32, 0, 0, POSITIVE}};
  s21_decimal num2 = {{19, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_sub(dec1, num2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 13);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], POSITIVE);
}
END_TEST

Suite *s21_arithmetic_sub_suite() {
  Suite *s = suite_create("s21_arithmetic_sub");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_sub_0_simple);
  tcase_add_test(tc, s21_sub_1_simple);
  tcase_add_test(tc, s21_sub_2_simple);
  tcase_add_test(tc, s21_sub_3_simple);
  tcase_add_test(tc, s21_sub_4_simple);
  tcase_add_test(tc, s21_sub_5_error);
  tcase_add_test(tc, s21_sub_6_error);
  tcase_add_test(tc, s21_sub_7_scale);
  tcase_add_test(tc, s21_sub_8_scale);
  tcase_add_test(tc, s21_sub_9_scale);
  tcase_add_test(tc, s21_sub_9a_scale);
  tcase_add_test(tc, s21_sub_10_error);
  tcase_add_test(tc, s21_sub_11_scale);
  tcase_add_test(tc, s21_sub_12_error);
  tcase_add_test(tc, s21_sub_13_scale);
  tcase_add_test(tc, s21_sub_14_simple);
  tcase_add_test(tc, s21_sub_15_error);
  tcase_add_test(tc, s21_sub_16_simple);
  tcase_add_test(tc, s21_sub_17_simple);
  tcase_add_test(tc, s21_sub_18_scale);
  tcase_add_test(tc, s21_sub_19_scale);
  tcase_add_test(tc, s21_sub_20_scale);
  tcase_add_test(tc, s21_sub_21_scale);
  tcase_add_test(tc, s21_sub_22_scale);
  tcase_add_test(tc, s21_sub_23_scale);
  tcase_add_test(tc, s21_sub_24_simple);
  tcase_add_test(tc, s21_sub_25_simple);
  tcase_add_test(tc, s21_sub_26_simple);
  tcase_add_test(tc, s21_sub_27_simple);
  tcase_add_test(tc, s21_sub_28_simple);

  return s;
}