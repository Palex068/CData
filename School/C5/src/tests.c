#include "tests.h"

int main() {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tests_s21_int_to_decimal());
  suite_add_tcase(suite, tcase);
  suite_add_tcase(suite, tests_s21_add());
  suite_add_tcase(suite, tests_s21_sub());
  suite_add_tcase(suite, tests_s21_mul());
  suite_add_tcase(suite, tests_s21_comparison());
  suite_add_tcase(suite, tests_s21_div());
  suite_add_tcase(suite, tests_s21_decimal_to_int());
  suite_add_tcase(suite, tests_s21_negate());
  suite_add_tcase(suite, tests_s21_truncate());
  suite_add_tcase(suite, tests_s21_floor());
  suite_add_tcase(suite, tests_s21_round());
  suite_add_tcase(suite, tests_s21_float_to_decimal());
  suite_add_tcase(suite, tests_s21_decimal_to_float());

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
