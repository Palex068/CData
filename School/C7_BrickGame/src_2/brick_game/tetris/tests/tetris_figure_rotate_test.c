#include <check.h>
#include <errno.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_figure_rotate_test1) {
  int result = 0;
  game_t *game = NULL;
  result = figure_rotate(game);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_rotate_test2) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  figure_destroy(game->figure_cur);
  game->figure_cur = NULL;
  result = figure_rotate(game);
  game_destroy(game);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_rotate_test3) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  game_info_destroy(game->game_info);
  game->game_info = NULL;
  result = figure_rotate(game);
  game_destroy(game);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_figure_rotate_test4) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  memory_locked(sizeof(figure_t), 1);
  result = figure_rotate(game);
  memory_locked(0, -1);
  game_destroy(game);
  ck_assert_int_eq(result, ENOMEM);
}
END_TEST

START_TEST(suite_figure_rotate_test5) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  result = figure_rotate(game);
  game_destroy(game);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(suite_figure_rotate_test6) {
  int result = 0;
  figure_t *figure = NULL;
  game_t *game = NULL;
  game_init(&game);
  game->figure_pos.x = 0;
  game->figure_pos.y = 0;
  for (int i = 1; i < 11; i++) {
    figure = figure_create(i);
    figure->size = i;
    figure_copy(figure, &game->figure_cur);
    result = figure_rotate(game);
    figure_destroy(figure);
    ck_assert_int_eq(result, 0);
  }
  game_destroy(game);
}
END_TEST

Suite *suite_figure_rotate() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_figure_rotate=-\x1b[0m");
  tc = tcase_create("suite_figure_rotate");

  if (s && tc) {
    tcase_add_test(tc, suite_figure_rotate_test1);
    tcase_add_test(tc, suite_figure_rotate_test2);
    tcase_add_test(tc, suite_figure_rotate_test3);
    tcase_add_test(tc, suite_figure_rotate_test4);
    tcase_add_test(tc, suite_figure_rotate_test5);
    tcase_add_test(tc, suite_figure_rotate_test6);
    suite_add_tcase(s, tc);
  }

  return s;
}