#include "test_tetris.h"

int test_run(Suite *test_tetris) {
  int failed = 0;
  SRunner *sr = srunner_create(test_tetris);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_NORMAL);
  failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return failed;
}

int main() {
  int failed = 0;
  Suite *suites_list[] = {test_backend(), NULL};
  for (Suite **current = suites_list; *current != NULL; current++) {
    printf("_________________________________________\n");
    failed += test_run(*current);
  }
  return (failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
