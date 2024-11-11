#ifndef TEST_MAIN_H_SENTRY
#define TEST_MAIN_H_SENTRY

#include <check.h>
#include <math.h>

#include "../brick_game/tetris/backend.h"
#include "../brick_game/tetris/figures.h"

void runtest(Suite *make_suite, int *result);

Suite *s21_matrix_suite();
Suite *s21_figures_suite();
Suite *s21_moves_suite();
Suite *s21_logic_suite();
Suite *s21_inputs_suite();

#endif