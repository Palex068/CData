#include <check.h>
#include <errno.h>

#include "tetris.h"

START_TEST(suite_update_current_state_test1) {
  game_info_t game_info = update_current_state();
  ck_assert(game_info.field == NULL);
  ck_assert(game_info.next == NULL);
  ck_assert_int_eq(game_info.score, 0);
  ck_assert_int_eq(game_info.high_score, 0);
  ck_assert_int_eq(game_info.level, 0);
  ck_assert_int_eq(game_info.speed, 0);
  ck_assert_int_eq(game_info.pause, 0);
}
END_TEST

START_TEST(suite_update_current_state_test2) {
  game_t *game = NULL;
  game_init(&game);
  game_info_t game_info = update_current_state();
  ck_assert(game_info.field != NULL);
  ck_assert(game_info.next != NULL);
  game_destroy(game);
}
END_TEST

START_TEST(suite_update_current_state_test3) {
  game_t *game = NULL;
  game_init(&game);
  game->game_info->level = 10;
  game_info_t game_info = update_current_state();
  ck_assert(game_info.field != NULL);
  ck_assert(game_info.next != NULL);
  ck_assert_int_eq(game_info.level, 10);
  game_destroy(game);
}
END_TEST

START_TEST(suite_update_current_state_test4) {
  game_t *game = NULL;
  game_init(&game);
  game->game_info->high_score = 1000;
  game_info_t game_info = update_current_state();
  ck_assert(game_info.field != NULL);
  ck_assert(game_info.next != NULL);
  ck_assert_int_eq(game_info.high_score, 1000);
  game_destroy(game);
}
END_TEST

START_TEST(suite_update_current_state_test5) {
  game_t *game = NULL;
  game_init(&game);
  game->game_info->high_score = 1000;
  game->game_info->level = 10;
  game_destroy(game);
  game_info_t game_info = update_current_state();
  ck_assert(game_info.field == NULL);
  ck_assert(game_info.next == NULL);
  ck_assert_int_eq(game_info.high_score, 0);
  ck_assert_int_eq(game_info.level, 0);
}
END_TEST

Suite *suite_update_current_state() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_update_current_state=-\x1b[0m");
  tc = tcase_create("suite_update_current_state");

  if (s && tc) {
    tcase_add_test(tc, suite_update_current_state_test1);
    tcase_add_test(tc, suite_update_current_state_test2);
    tcase_add_test(tc, suite_update_current_state_test3);
    tcase_add_test(tc, suite_update_current_state_test4);
    tcase_add_test(tc, suite_update_current_state_test5);

    suite_add_tcase(s, tc);
  }

  return s;
}