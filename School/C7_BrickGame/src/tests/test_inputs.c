#include "test_main.h"

START_TEST(s21_inputs_00_ok) {
  for (int action = Terminate; action < 8; action++) {
    userInput(action, false);
  }

  userInput(8, false);
  userInput(0, true);

  GameInfo_t *state = stateWrapper();
  state->speed = -1;
  userInput(1000, false);
}
END_TEST

START_TEST(s21_inputs_01_ok) {
  int key[7] = {KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN, 'q', 'p', ' '};
  UserAction_t val[7] = {Left, Right, Up, Down, Terminate, Pause, Action};
  for (size_t i = 0; i < sizeof(key) / sizeof(int); i++) {
    if (isPress(key[i]) != val[i]) printf("ERROR");
  }

  isPress(KEY_BACKSPACE);

  clearMatrix();
}
END_TEST

Suite *s21_inputs_suite() {
  Suite *s = suite_create("s21_inputs");
  TCase *tc = tcase_create("s21_tetris");
  suite_add_tcase(s, tc);
  tcase_add_test(tc, s21_inputs_00_ok);
  tcase_add_test(tc, s21_inputs_01_ok);

  return s;
}