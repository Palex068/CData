#include <check.h>
#include <errno.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_kaboom_test1) {
  int result = 0;
  game_t *game = NULL;
  result = kaboom(game);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_kaboom_test2) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  figure_destroy(game->figure_cur);
  game->figure_cur = NULL;
  result = kaboom(game);
  game_destroy(game);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(suite_kaboom_test3) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  game_info_destroy(game->game_info);
  game->game_info = NULL;
  result = kaboom(game);
  game_destroy(game);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_kaboom_test4) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  game->figure_pos.x = 0;
  game->figure_pos.y = 0;
  for (int row = 0; row < field_height; row++) {
    for (int col = 0; col < field_width; col++)
      game->game_info->field[row][col] = 1;
  }
  memory_locked(sizeof(int), 1);
  result = kaboom(game);
  memory_locked(0, -1);
  game_destroy(game);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(suite_kaboom_test5) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  result = kaboom(game);
  game_destroy(game);
  ck_assert_int_eq(result, 0);
}
END_TEST

START_TEST(suite_kaboom_test6) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  game->figure_pos.x = 0;
  game->figure_pos.y = 0;
  for (int row = 0; row < field_height; row++) {
    for (int col = 0; col < field_width; col++)
      game->game_info->field[row][col] = 1;
  }
  result = kaboom(game);
  ck_assert_int_eq(result, 0);
  game_destroy(game);
}
END_TEST

Suite *suite_kaboom() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_kaboom=-\x1b[0m");
  tc = tcase_create("suite_kaboom");

  if (s && tc) {
    tcase_add_test(tc, suite_kaboom_test1);
    tcase_add_test(tc, suite_kaboom_test2);
    tcase_add_test(tc, suite_kaboom_test3);
    tcase_add_test(tc, suite_kaboom_test4);
    tcase_add_test(tc, suite_kaboom_test5);
    tcase_add_test(tc, suite_kaboom_test6);
    suite_add_tcase(s, tc);
  }

  return s;
}