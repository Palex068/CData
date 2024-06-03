#include <check.h>
#include <errno.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_game_info_next_clean_test1) {
  int result = 0;
  result = game_info_next_clean(NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_game_info_next_clean_test2) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  memory_locked(16, 1);
  result = game_info_next_clean(game->game_info->next);
  memory_locked(0, -1);
  game_destroy(game);
  ck_assert_int_eq(result, ECANCELED);
}
END_TEST

START_TEST(suite_game_info_next_clean_test3) {
  int result = 0;
  game_t *game = NULL;
  game_init(&game);
  result = game_info_next_clean(game->game_info->next);
  game_destroy(game);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_game_info_next_clean() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_game_info_next_clean=-\x1b[0m");

  tc = tcase_create("suite_game_info_next_clean");
  tcase_add_test(tc, suite_game_info_next_clean_test1);
  tcase_add_test(tc, suite_game_info_next_clean_test2);
  tcase_add_test(tc, suite_game_info_next_clean_test3);

  suite_add_tcase(s, tc);

  return s;
}