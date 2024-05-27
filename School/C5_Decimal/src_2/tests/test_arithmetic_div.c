#include "test_main.h"

START_TEST(s21_div_0_simple) {
  s21_decimal dec1 = {{7, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{7, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{1, 0, 0, POSITIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_1_simple) {
  s21_decimal dec1 = {{0, 6500, 0, NEGATIVE}};
  s21_decimal dec2 = {{0, 6500, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{1, 0, 0, NEGATIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_2_simple) {
  s21_decimal dec1 = {{0, 0, UINT32_MAX, POSITIVE}};
  s21_decimal dec2 = {{0, 0, UINT32_MAX, NEGATIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{1, 0, 0, NEGATIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_3_simple) {
  s21_decimal dec1 = {{20, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{10, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{2, 0, 0, POSITIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_4_simple) {
  s21_decimal dec1 = {{21, 0, 0, POSITIVE + SCALE(2)}};
  s21_decimal dec2 = {{21, 0, 0, POSITIVE + SCALE(2)}};
  s21_decimal res = {0};
  s21_decimal answer = {{1, 0, 0, POSITIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_5_fraction) {
  s21_decimal dec1 = {{9, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{5, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{18, 0, 0, POSITIVE + SCALE(1)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_6_fraction) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{-2, -1, -1, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {
      {268435456, 1042612833, 542101086, POSITIVE + SCALE(28)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_7_fraction) {
  s21_decimal dec1 = {{49, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{50, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{98, 0, 0, POSITIVE + SCALE(2)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_8_fraction) {
  s21_decimal dec1 = {{35, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{8, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{4375, 0, 0, POSITIVE + SCALE(3)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_9_fraction) {
  s21_decimal dec1 = {{2, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{3, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {
      {178956971, 695075222, 361400724, POSITIVE + SCALE(28)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_10_error_zero) {
  s21_decimal dec1 = {{-2, -1, -3, POSITIVE}};
  s21_decimal dec2 = {{0, 0, 0, NEGATIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 3);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_11_scale) {
  s21_decimal dec1 = {{4, 0, 0, POSITIVE + SCALE(1)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE + SCALE(2)}};
  s21_decimal res = {0};
  s21_decimal answer = {{20, 0, 0, POSITIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_12_scale_fraction) {
  s21_decimal dec1 = {{5, 0, 0, POSITIVE + SCALE(2)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE + SCALE(1)}};
  s21_decimal res = {0};
  s21_decimal answer = {{25, 0, 0, POSITIVE + SCALE(2)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_13_scale) {
  s21_decimal dec1 = {{8, 0, 0, POSITIVE + SCALE(3)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE + SCALE(1)}};
  s21_decimal res = {0};
  s21_decimal answer = {{4, 0, 0, POSITIVE + SCALE(2)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_14_simple) {
  s21_decimal dec1 = {{72, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{8, 0, 0, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  s21_decimal answer = {{9, 0, 0, scomp(NEGATIVE)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_15_scale_fraction) {
  s21_decimal dec1 = {{8, 0, 0, scomp(NEGATIVE)}};
  s21_decimal dec2 = {{72, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {
      {1461481927, 115845870, 60233454, scomp(NEGATIVE + SCALE(28))}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}

START_TEST(s21_div_16_scale_fraction) {
  s21_decimal dec1 = {{7, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, POSITIVE + SCALE(28)}};
  s21_decimal res = {0};
  s21_decimal answer = {
      {1879048192, scomp(3003322535), scomp(3794707603), POSITIVE}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_17_error) {
  s21_decimal dec1 = {{8, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, POSITIVE + SCALE(28)}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_18_error) {
  s21_decimal dec1 = {{80, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{3, 0, 0, POSITIVE + SCALE(28)}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);

  ck_assert_int_eq(error, 1);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_19_error) {
  s21_decimal dec1 = {{1, 0, 0, POSITIVE + SCALE(28)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 2);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_20_simple) {
  s21_decimal dec1 = {{3, 0, 0, POSITIVE + SCALE(1)}};
  s21_decimal dec2 = {{5, 0, 0, POSITIVE + SCALE(3)}};
  s21_decimal res = {0};
  s21_decimal answer = {{60, 0, 0, SCALE(0)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_21_simple) {
  s21_decimal dec1 = {{1, 0, 0, POSITIVE + SCALE(0)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE + SCALE(1)}};
  s21_decimal res = {0};
  s21_decimal answer = {{5, 0, 0, SCALE(0)}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_22_simple) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 5);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_div_23_fraction) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{4, 0, 0, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 25);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], scomp(SCALE(1) + NEGATIVE));
}
END_TEST

START_TEST(s21_div_24_fraction) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{3, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 894784853);
  ck_assert_int_eq(res.bits[1], -819591186);
  ck_assert_int_eq(res.bits[2], 1807003620);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_25_fraction) {
  s21_decimal dec1 = {{10, 0, 0, SCALE(0)}};
  s21_decimal dec2 = {{22, 0, 0, SCALE(1)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  // NOTE: тут используется математическое округление
  // ck_assert_int_eq(res.bits[0], 48806447);
  ck_assert_int_eq(res.bits[0], 48806446);
  ck_assert_int_eq(res.bits[1], -1898527489);
  ck_assert_int_eq(res.bits[2], -1830871450);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_26_fraction) {
  s21_decimal dec1 = {{10, 0, 0, SCALE(2)}};
  s21_decimal dec2 = {{22, 0, 0, SCALE(0)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 957826513);
  ck_assert_int_eq(res.bits[1], -659028524);
  ck_assert_int_eq(res.bits[2], 2464095);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_27_simple) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, SCALE(6)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 10000000);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_div_28_fraction) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{6, 0, 0, SCALE(28)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 447392427);
  ck_assert_int_eq(res.bits[1], 1737688055);
  ck_assert_int_eq(res.bits[2], 903501810);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_div_29_fraction) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{658067456, 1164, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 2);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(12));
}
END_TEST

START_TEST(s21_div_30_fraction) {
  s21_decimal dec1 = {{10, 0, 0, POSITIVE}};
  s21_decimal dec2 = {{1879048192, -1291644761, -500259693, POSITIVE}};  // 7e28
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  // print_decimal(dec1);
  // print_decimal(dec2);
  // print_decimal(res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 0);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_31_test) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], scomp(2147483648));
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_div_32_test) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{4, 0, 0, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1073741824);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE));
}
END_TEST

START_TEST(s21_div_33_overflow) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{3, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1431655765);
  ck_assert_int_eq(res.bits[1], 1431655765);
  ck_assert_int_eq(res.bits[2], 1431655765);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_div_34_overflow) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{22, 0, 0, SCALE(1)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1171354717);
  ck_assert_int_eq(res.bits[1], -780903145);
  ck_assert_int_eq(res.bits[2], 1952257861);
  ck_assert_int_eq(res.bits[3], 0);
}
END_TEST

START_TEST(s21_div_35_fraction) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{658067456, 1164, 0, POSITIVE}};  // 5e12
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 858993459);
  ck_assert_int_eq(res.bits[1], 858993459);
  ck_assert_int_eq(res.bits[2], 858993459);
  ck_assert_int_eq(res.bits[3], SCALE(12));
}
END_TEST

START_TEST(s21_div_36_overflow) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{1879048192, -1291644761, -500259693, POSITIVE}};  // 7e28
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1227133513);
  ck_assert_int_eq(res.bits[1], -1840700270);
  ck_assert_int_eq(res.bits[2], 613566756);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_37_overflow) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{805306368, -1167128797, 1626303258, POSITIVE}};  // 3e28
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 1431655765);
  ck_assert_int_eq(res.bits[1], 1431655765);
  ck_assert_int_eq(res.bits[2], 1431655765);
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_38_overflow) {
  s21_decimal dec1 = {{-1, -1, -1, SCALE(28)}};
  s21_decimal dec2 = {{2, 0, 0, POSITIVE}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], scomp(2147483648));
  ck_assert_int_eq(res.bits[3], SCALE(28));
}
END_TEST

START_TEST(s21_div_39_overflow) {
  s21_decimal dec1 = {{-1, -1, -1, SCALE(28)}};
  s21_decimal dec2 = {{4, 0, 0, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 0);
  ck_assert_int_eq(res.bits[0], 0);
  ck_assert_int_eq(res.bits[1], 0);
  ck_assert_int_eq(res.bits[2], 1073741824);
  ck_assert_int_eq(res.bits[3], scomp(NEGATIVE + SCALE(28)));
}
END_TEST

START_TEST(s21_div_40_error) {
  s21_decimal dec1 = {{1, 1, 1, SCALE(28)}};
  s21_decimal dec2 = {{0, 0, 0, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 3);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_41_error) {
  s21_decimal dec1 = {{-1, -1, -1, POSITIVE}};
  s21_decimal dec2 = {{1, 0, 0, SCALE(6)}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 1);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

START_TEST(s21_div_42_error) {
  s21_decimal dec1 = {{1, 0, 0, SCALE(28)}};
  s21_decimal dec2 = {{4, 0, 0, scomp(NEGATIVE)}};
  s21_decimal res = {0};
  s21_decimal answer = {{0, 0, 0, 0}};
  int error = s21_div(dec1, dec2, &res);
  ck_assert_int_eq(error, 2);
  for (int i = 0; i <= 3; i++) ck_assert_int_eq(res.bits[i], answer.bits[i]);
}
END_TEST

Suite *s21_arithmetic_div_suite() {
  Suite *s = suite_create("s21_arithmetic_div");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_div_0_simple);
  tcase_add_test(tc, s21_div_1_simple);
  tcase_add_test(tc, s21_div_2_simple);
  tcase_add_test(tc, s21_div_3_simple);
  tcase_add_test(tc, s21_div_4_simple);
  tcase_add_test(tc, s21_div_5_fraction);
  tcase_add_test(tc, s21_div_6_fraction);
  tcase_add_test(tc, s21_div_7_fraction);
  tcase_add_test(tc, s21_div_8_fraction);
  tcase_add_test(tc, s21_div_9_fraction);
  tcase_add_test(tc, s21_div_10_error_zero);
  tcase_add_test(tc, s21_div_11_scale);
  tcase_add_test(tc, s21_div_12_scale_fraction);
  tcase_add_test(tc, s21_div_13_scale);
  tcase_add_test(tc, s21_div_14_simple);
  tcase_add_test(tc, s21_div_15_scale_fraction);
  tcase_add_test(tc, s21_div_16_scale_fraction);
  tcase_add_test(tc, s21_div_17_error);
  tcase_add_test(tc, s21_div_18_error);
  tcase_add_test(tc, s21_div_19_error);
  tcase_add_test(tc, s21_div_20_simple);
  tcase_add_test(tc, s21_div_21_simple);
  tcase_add_test(tc, s21_div_22_simple);
  tcase_add_test(tc, s21_div_23_fraction);
  tcase_add_test(tc, s21_div_24_fraction);
  tcase_add_test(tc, s21_div_25_fraction);
  tcase_add_test(tc, s21_div_26_fraction);
  tcase_add_test(tc, s21_div_27_simple);
  tcase_add_test(tc, s21_div_28_fraction);
  tcase_add_test(tc, s21_div_29_fraction);
  tcase_add_test(tc, s21_div_30_fraction);
  tcase_add_test(tc, s21_div_31_test);
  tcase_add_test(tc, s21_div_32_test);
  tcase_add_test(tc, s21_div_33_overflow);
  tcase_add_test(tc, s21_div_34_overflow);
  tcase_add_test(tc, s21_div_35_fraction);
  tcase_add_test(tc, s21_div_36_overflow);
  tcase_add_test(tc, s21_div_37_overflow);
  tcase_add_test(tc, s21_div_38_overflow);
  tcase_add_test(tc, s21_div_39_overflow);
  tcase_add_test(tc, s21_div_40_error);
  tcase_add_test(tc, s21_div_41_error);
  tcase_add_test(tc, s21_div_42_error);
  return s;
}
