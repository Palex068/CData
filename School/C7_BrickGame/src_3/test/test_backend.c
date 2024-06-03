#include "test_tetris.h"

START_TEST(getInstance_GameInfo) {
  GameInfo_t* g = getInstance_GameInfo_t();
  ck_assert_int_eq(g->level, 0);
  ck_assert_int_eq(g->high_score, 0);
  ck_assert_int_eq(g->score, 0);
  ck_assert_int_eq(g->speed, 0);
  ck_assert_int_eq(g->pause, 0);
  ck_assert(g->field == NULL);
  ck_assert(g->next == NULL);
}
END_TEST

START_TEST(getInstance_UserAction) {
  UserAction_t* a = getInstance_UserAction_t();
  ck_assert(*a == Start);
}
END_TEST

START_TEST(getInstance_cur) {
  matrix* m = getInstance_cur_fig();
  ck_assert(m->cur_fig == NULL);
}
END_TEST

START_TEST(getInstance_h) {
  int* h = getInstance_hold();
  ck_assert_int_eq(*h, 1);
}
END_TEST

START_TEST(getInstance_c) {
  int* ch = getInstance_ch();
  ck_assert_int_eq(*ch, 0);
}
END_TEST

START_TEST(getInstance_x_) {
  int* x = getInstance_x();
  ck_assert_int_eq(*x, 3);
}
END_TEST

START_TEST(getInstance_y_) {
  int* y = getInstance_y();
  ck_assert_int_eq(*y, -1);
}
END_TEST

START_TEST(init_gameinfo) {
  GameInfo_t* g = getInstance_GameInfo_t();
  int h_score = 0;
  init_gameinfo_t();
  char* filename = "brick_game/tetris/high_score.txt";
  char buffer[256] = {'\0'};
  FILE* fp = fopen(filename, "r");
  if (fp) {
    fgets(buffer, 256, fp);
    sscanf(buffer, "%d", &h_score);
  }
  fclose(fp);
  ck_assert_int_eq(g->level, 1);
  ck_assert_int_eq(g->high_score, h_score);
  ck_assert_int_eq(g->score, 0);
  ck_assert_int_eq(g->speed, 1);
  ck_assert_int_eq(g->pause, 0);
  ck_assert_int_eq(g->field[0][0], 0);
  ck_assert_int_eq(g->next[0][0], 0);
}
END_TEST

START_TEST(create_field_n) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  ck_assert_int_eq(g->field[0][0], 0);
  ck_assert_int_eq(g->next[0][0], 0);
}
END_TEST

START_TEST(delete_field_n) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  delete_field_next(g);
  ck_assert(g->field != NULL);
  ck_assert(g->next != NULL);
}
END_TEST

START_TEST(testlin) {
  int line[FIELD_W] = {0};
  int t = testline(line);
  int line_1[FIELD_W] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
  int f = testline(line_1);
  ck_assert_int_eq(t, 0);
  ck_assert_int_eq(f, 1);
}
END_TEST

START_TEST(dellin) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  for (int i = 0; i < 10; i++) g->field[19][i] = 1;
  delline(g->field, 19);
  for (int i = 0; i < 10; i++) ck_assert_int_eq(g->field[19][i], 0);
}
END_TEST

START_TEST(fill_tes) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  fill_test(g->field, &(g->score));
  ck_assert_int_eq(g->score, 0);

  for (int i = 0; i < 10; i++) g->field[19][i] = 1;
  fill_test(g->field, &(g->score));
  ck_assert_int_eq(g->score, 100);

  g->score = 0;
  for (int i = 0; i < 10; i++) {
    g->field[18][i] = 1;
    g->field[19][i] = 1;
  }
  fill_test(g->field, &(g->score));
  ck_assert_int_eq(g->score, 300);

  g->score = 0;
  for (int i = 0; i < 10; i++) {
    g->field[17][i] = 1;
    g->field[18][i] = 1;
    g->field[19][i] = 1;
  }
  fill_test(g->field, &(g->score));
  ck_assert_int_eq(g->score, 700);

  g->score = 0;
  for (int i = 0; i < 10; i++) {
    g->field[16][i] = 1;
    g->field[17][i] = 1;
    g->field[18][i] = 1;
    g->field[19][i] = 1;
  }
  fill_test(g->field, &(g->score));
  ck_assert_int_eq(g->score, 1500);
}
END_TEST

START_TEST(save_high_scor) {
  GameInfo_t* g = getInstance_GameInfo_t();
  int h_score = 0;
  save_high_score(h_score);
  g->high_score = 0;
  create_field_next(g);
  ck_assert_int_eq(g->high_score, h_score);
}
END_TEST

START_TEST(rotate_fi) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  matrix* matr = getInstance_cur_fig();
  init_matrix();
  int* x = getInstance_x();
  int* y = getInstance_y();
  matr->cur_fig[2][3] = 1;
  matr->cur_fig[3][3] = 1;
  g->field[5][6] = 1;
  g->field[6][6] = 1;
  rotate_fig(g->field, matr->cur_fig, x, y, R_R);
  ck_assert_int_eq(*x, 3);
  uninit_matrix(matr);
}
END_TEST

START_TEST(copy_data_1_) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  int from[FIGURE_SIZE][FIGURE_SIZE] = {0};
  copy_data_1(g->next, from);
  ck_assert_int_eq(from[0][0], 0);
}
END_TEST

START_TEST(copy_data_2_) {
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  GameInfo_t* from = getInstance_GameInfo_t();
  create_field_next(from);
  copy_data_2(g->next, from->next);
  ck_assert_int_eq(g->next[0][0], 0);
}
END_TEST

START_TEST(check_the_end_) {
  UserAction_t* action = getInstance_UserAction_t();
  check_the_end();
  ck_assert(*action == Terminate);
}
END_TEST

START_TEST(set_high_score_) {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  create_field_next(gameInfo_t);
  set_high_score();
  GameInfo_t* g = getInstance_GameInfo_t();
  create_field_next(g);
  ck_assert_int_eq(g->high_score, gameInfo_t->high_score);
}
END_TEST

START_TEST(set_speed_) {
  double delay = 0;
  init_gameinfo_t();
  set_speed(&delay);
  ck_assert_double_eq(delay, 0);
}
END_TEST

START_TEST(go_to_) {
  UserAction_t* action = getInstance_UserAction_t();
  *action = Start;
  int hold = 0;
  int pause = 1;
  go_to(action, &hold, pause);
  ck_assert(*action == Down);
}
END_TEST

START_TEST(userInput_) {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  init_gameinfo_t();
  init_matrix();
  UserAction_t* action = getInstance_UserAction_t();
  int* ch = getInstance_ch();
  *ch = '\n';
  *action = Start;
  int hold = 0;
  userInput(*action, hold);
  ck_assert_int_eq(gameInfo_t->pause, 1);

  *action = Pause;
  *ch = 'p';
  userInput(*action, hold);
  ck_assert_int_eq(gameInfo_t->pause, 1);

  int* x = getInstance_x();
  gameInfo_t->pause = 0;
  hold = 1;
  *action = Left;
  userInput(*action, hold);
  ck_assert_int_eq(*x, 2);

  *action = Right;
  userInput(*action, hold);
  ck_assert_int_eq(*x, 3);

  int* y = getInstance_x();
  *action = Down;
  userInput(*action, hold);
  ck_assert_int_eq(*y, 3);

  *action = Action;
  userInput(*action, hold);
  ck_assert_int_eq(*y, 3);
  ck_assert_int_eq(*x, 3);
}
END_TEST

START_TEST(updateCurrentState_) {
  GameInfo_t* gameInfo_t = getInstance_GameInfo_t();
  init_gameinfo_t();
  UserAction_t* action = getInstance_UserAction_t();
  int* ch = getInstance_ch();
  int* hold = getInstance_hold();
  *hold = 0;

  *ch = 'Q';
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Terminate);

  *hold = 0;
  *ch = KEY_UP;
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Up);

  *hold = 0;
  *ch = KEY_LEFT;
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Left);

  *hold = 0;
  *ch = KEY_RIGHT;
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Right);

  *hold = 0;
  *ch = KEY_DOWN;
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Down);

  *hold = 0;
  *ch = ' ';
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Action);

  *hold = 0;
  *ch = 'P';
  *gameInfo_t = updateCurrentState();
  ck_assert(*action == Pause);
  ck_assert_int_eq(*ch, 0);
  ck_assert_int_eq(*hold, 1);
}
END_TEST

Suite* test_backend(void) {
  Suite* s = suite_create("test_backend");
  TCase* tc = tcase_create("backend");

  tcase_add_test(tc, getInstance_GameInfo);
  tcase_add_test(tc, getInstance_UserAction);
  tcase_add_test(tc, getInstance_cur);
  tcase_add_test(tc, getInstance_h);
  tcase_add_test(tc, getInstance_c);
  tcase_add_test(tc, getInstance_x_);
  tcase_add_test(tc, getInstance_y_);
  tcase_add_test(tc, init_gameinfo);
  tcase_add_test(tc, create_field_n);
  tcase_add_test(tc, delete_field_n);
  tcase_add_test(tc, testlin);
  tcase_add_test(tc, dellin);
  tcase_add_test(tc, fill_tes);
  tcase_add_test(tc, save_high_scor);
  tcase_add_test(tc, rotate_fi);
  tcase_add_test(tc, copy_data_1_);
  tcase_add_test(tc, copy_data_2_);
  tcase_add_test(tc, check_the_end_);
  tcase_add_test(tc, set_high_score_);
  tcase_add_test(tc, set_speed_);
  tcase_add_test(tc, go_to_);
  tcase_add_test(tc, userInput_);
  tcase_add_test(tc, updateCurrentState_);

  suite_add_tcase(s, tc);
  return s;
}