#include "test_main.h"

START_TEST(s21_logic_00_ok) {
  Figures *figure = updateCurrentFigure(true);
  delFigure();
  figure->y = HEIGHT;
  ck_assert_int_eq(isCollision(), COLLIDE);
  figure->y = 1;

  figure->x = WIDTH;
  ck_assert_int_eq(isCollision(), R_BOUNCE);
  figure->x = 3;

  figure->y = 20;
  ck_assert_int_eq(isCollision(), COLLIDE);
  figure->y = 1;

  figure->x = -2;
  ck_assert_int_eq(isCollision(), L_BOUNCE);
  figure->x = 3;

  ck_assert_int_eq(isCollision(), OK);
}
END_TEST

START_TEST(s21_logic_01_ok) {
  GameInfo_t *state = stateWrapper();
  for (int x = 0; x < WIDTH; x++) {
    state->field[19][x] = 1;
  }
  lineElimination();

  state->level = 10;
  lineElimination();
}
END_TEST

START_TEST(s21_logic_02_ok) { promptNewGame(); }
END_TEST

Suite *s21_logic_suite() {
  Suite *s = suite_create("s21_logic");
  TCase *tc = tcase_create("s21_tetris");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_logic_00_ok);
  tcase_add_test(tc, s21_logic_01_ok);
  tcase_add_test(tc, s21_logic_02_ok);
  return s;
}