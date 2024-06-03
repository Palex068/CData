#include "s21_tests_runner.h"

int main() {
  run_all_tests();

  return 0;
}

size_t run_all_tests() {
  SRunner *runner = srunner_create(NULL);

  add_all_suites_in_runner(&runner);

  srunner_run_all(runner, CK_NORMAL);

  size_t failed_count = srunner_ntests_failed(runner);

  srunner_free(runner);

  return failed_count;
}

void add_all_suites_in_runner(SRunner **runner) {
  /////

  srunner_add_suite(*runner, tetromino_suite());
  srunner_add_suite(*runner, board_suite());
  srunner_add_suite(*runner, interfaces_suite());
  srunner_add_suite(*runner, gameplay_suite());
  srunner_add_suite(*runner, fsm_suite());
}