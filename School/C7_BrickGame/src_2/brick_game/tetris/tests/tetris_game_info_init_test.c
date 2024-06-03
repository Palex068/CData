#include <check.h>
#include <errno.h>

#include "tetris.h"
#include "tetris_test.h"

START_TEST(suite_game_info_init_test1) {
  int result = 0;
  result = game_info_init(NULL);
  ck_assert_int_eq(result, EINVAL);
}
END_TEST

START_TEST(suite_game_info_init_test2) {
  int result = 0;
  game_info_t *game_info = NULL;
  memory_locked(sizeof(game_info_t), 1);
  result = game_info_init(&game_info);
  memory_locked(0, -1);
  game_info_destroy(game_info);
  ck_assert_int_eq(result, ENOMEM);
}
END_TEST

START_TEST(suite_game_info_init_test3) {
  int result = 0;
  game_info_t *game_info = NULL;
  result = game_info_init(&game_info);
  game_info_destroy(game_info);
  ck_assert_int_eq(result, 0);
}
END_TEST

Suite *suite_game_info_init() {
  Suite *s = NULL;
  TCase *tc = NULL;

  s = suite_create("\x1b[1;33m-=suite_game_info_init=-\x1b[0m");

  tc = tcase_create("suite_game_info_init");
  tcase_add_test(tc, suite_game_info_init_test1);
  tcase_add_test(tc, suite_game_info_init_test2);
  tcase_add_test(tc, suite_game_info_init_test3);

  suite_add_tcase(s, tc);

  return s;
}