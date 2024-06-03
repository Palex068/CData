#ifndef S21_TESTS_RUNNER_H
#define S21_TESTS_RUNNER_H

#include <check.h>
#include <stdint.h>
#include <stdio.h>

#include "../../includes/brick_game/v1/logic/tetris.h"

// All suites
Suite *tetromino_suite();
Suite *board_suite();
Suite *interfaces_suite();
Suite *gameplay_suite();
Suite *fsm_suite();
//

// Run tests
size_t run_all_tests();
void add_all_suites_in_runner(SRunner **runner);
//

#endif