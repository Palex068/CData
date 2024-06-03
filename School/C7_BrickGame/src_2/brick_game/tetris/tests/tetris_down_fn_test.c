#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_down_fn_test1) {
  game_t *game = NULL;
  down_fn(game);
}
END_TEST

START_TEST(suite_down_fn_test2) {
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  for (int i = 0; i < field_height - game->figure_cur->size - 1; i++)
    down_fn(game);
  ck_assert(game->figure_pos.y == field_height - game->figure_cur->size - 1);
  game_destroy(game);
}
END_TEST

START_TEST(suite_down_fn_test3) {
  game_t *game = NULL;
  game_init(&game);
  spawn_fn(game);
  game->game_info->field[10][3] = 1;
  game->game_info->field[10][4] = 1;
  game->game_info->field[10][5] = 1;
  game->game_info->field[10][6] = 1;
  for (int i = 0; i < 10; i++) down_fn(game);
  ck_assert(game->figure_pos.y <= 10);
  ck_assert(game->modified == 1);
  game_destroy(game);
}
END_TEST

Suite *suite_down_fn() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_down_fn=-\x1b[0m");
  tc = tcase_create("suite_down_fn");

  if (s && tc) {
    tcase_add_test(tc, suite_down_fn_test1);
    tcase_add_test(tc, suite_down_fn_test2);
    tcase_add_test(tc, suite_down_fn_test3);

    suite_add_tcase(s, tc);
  }

  return s;
}