#include <check.h>
#include <errno.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_game_init_test1) {
  int result = 0;
  result = game_init(NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_game_init_test2) {
  int result = 0;
  game_t *game = NULL;
  memory_locked(sizeof(game_t), 1);
  result = game_init(&game);
  memory_locked(0, -1);
  if (game) game_destroy(game);
  ck_assert_int_eq(result, ENOMEM);
}
END_TEST

START_TEST(suite_game_init_test3) {
  int result = 0;
  game_t *game = NULL;
  memory_locked(sizeof(int), 1);
  result = game_init(&game);
  memory_locked(0, -1);
  if (game) game_destroy(game);
  ck_assert_int_eq(result, ENOMEM);
}
END_TEST

START_TEST(suite_game_init_test4) {
  int result = 0;
  game_t *game = NULL;
  result = game_init(&game);
  game_destroy(game);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_game_init() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_game_init=-\x1b[0m");

  tc = tcase_create("suite_game_init");
  tcase_add_test(tc, suite_game_init_test1);
  tcase_add_test(tc, suite_game_init_test2);
  tcase_add_test(tc, suite_game_init_test3);
  tcase_add_test(tc, suite_game_init_test4);

  suite_add_tcase(s, tc);

  return s;
}