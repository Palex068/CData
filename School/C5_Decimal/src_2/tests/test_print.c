#include "test_main.h"

START_TEST(s21_print_1) {
  s21_decimal dec = {{10, 20, 30, SCALE(3) + NEGATIVE}};
  print_decimal(dec);
  printf("scale: %d\n", get_scale(dec));

  set_bit(&dec, 95, bitone);
  printf("\n");
  print_decimal(dec);

  toggle_bit(&dec, 95);
  printf("\n");
  print_decimal(dec);

  for (int i = 127; i >= 0; i--) {
    printf("%d", get_bit(dec, i));
    if (i % 32 == 0) printf("\n");
  }
  printf("\n");
}
END_TEST

Suite *s21_print_suite() {
  Suite *s = suite_create("s21_print");
  TCase *tc = tcase_create("s21_decimal");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_print_1);
  return s;
}