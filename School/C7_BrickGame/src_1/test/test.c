#include "test.h"

START_TEST(init_1) {
  initialize_state();
  State_t *state = get_current_state();
  ck_assert_int_eq(state->score, 0);
  finish_game();
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(init_2) {
  initialize_state();
  State_t *state = get_current_state();
  ck_assert_int_eq(state->level, 1);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(init_3) {
  initialize_state();
  State_t *state = get_current_state();
  ck_assert_int_eq(state->pause, 0);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(init_4) {
  initialize_state();
  State_t *state = get_current_state();
  ck_assert_int_eq(state->coord_x, -1);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(init_5) {
  initialize_state();
  State_t *state = get_current_state();
  ck_assert_int_eq(state->coord_y, 4);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(shift) {
  initialize_state();
  shift_block();
  State_t *state = get_current_state();
  ck_assert_int_eq(state->coord_x, 0);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(spawn) {
  initialize_state();
  State_t *state = get_current_state();
  int block_size = state->next_block_size;
  spawn_new_block();
  ck_assert_int_eq(state->block_size, block_size);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(right_1) {
  initialize_state();
  State_t *state = get_current_state();
  int coord_y = state->coord_y;
  move_block_right();
  ck_assert_int_eq(state->coord_y, coord_y + 1);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(left_1) {
  initialize_state();
  State_t *state = get_current_state();
  int coord_y = state->coord_y;
  move_block_left();
  ck_assert_int_eq(state->coord_y, coord_y - 1);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(input_start) {
  initialize_state();
  State_t *state = get_current_state();
  userInput(Start);
  ck_assert_int_eq(state->status, Spawn);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(consume_1) {
  initialize_state();
  State_t *state = get_current_state();
  int score = state->score;
  consume_rows();
  ck_assert_int_eq(state->score, score);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(pause_1) {
  initialize_state();
  State_t *state = get_current_state();
  pause_game();
  ck_assert_int_eq(state->pause, 1);
  pause_game();
  ck_assert_int_eq(state->pause, 0);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(timer_1) {
  initialize_state();
  unsigned long long time_left = process_timer();
  ck_assert_int_eq(time_left, -1);
  State_t *state = get_current_state();
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(input_left) {
  initialize_state();
  State_t *state = get_current_state();
  state->status = Moving;
  userInput(Left);
  ck_assert_int_eq(state->status, Moving);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(input_right) {
  initialize_state();
  State_t *state = get_current_state();
  state->status = Moving;
  userInput(Right);
  ck_assert_int_eq(state->status, Moving);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(consume_2) {
  initialize_state();
  State_t *state = get_current_state();
  state->score = 10000;
  consume_rows();
  ck_assert_int_eq(state->score, 10000);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(input_down) {
  initialize_state();
  State_t *state = get_current_state();
  state->status = Moving;
  userInput(Down);
  ck_assert_int_eq(state->status, Attaching);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(can_rotate_1) {
  initialize_state();
  State_t *state = get_current_state();
  rotate_block();
  ck_assert_int_eq(state->status, Moving);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(rotate_1) {
  initialize_state();
  int block_size;
  int **new_block = generate_new_block(&block_size);
  int can_rotate = can_rotate_block(new_block);
  ck_assert_int_eq(can_rotate, 1);
  State_t *state = get_current_state();
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
  free_matrix(new_block, block_size);
}
END_TEST

START_TEST(attach_1) {
  initialize_state();
  State_t *state = get_current_state();
  attach_block();
  ck_assert_int_eq(state->status, GameOver);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(input_action) {
  initialize_state();
  State_t *state = get_current_state();
  state->status = Moving;
  userInput(Action);
  ck_assert_int_eq(state->status, Moving);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(update_state) {
  initialize_state();
  State_t *state = get_current_state();
  GameInfo_t info = updateCurrentState();
  ck_assert_int_eq(state->score, info.score);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
  free_matrix(info.field, FIELD_H);
  free_matrix(info.next, 4);
}
END_TEST

START_TEST(consume_3) {
  initialize_state();
  State_t *state = get_current_state();
  for (int j = 0; j < FIELD_W; j++) {
    state->field[FIELD_H - 1][j] = 1;
  }
  consume_rows();
  ck_assert_int_eq(state->score, 100);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(consume_4) {
  initialize_state();
  State_t *state = get_current_state();
  for (int i = FIELD_H - 1; i > FIELD_H - 3; i--) {
    for (int j = 0; j < FIELD_W; j++) {
      state->field[i][j] = 1;
    }
  }
  consume_rows();
  ck_assert_int_eq(state->score, 300);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(consume_5) {
  initialize_state();
  State_t *state = get_current_state();
  for (int i = FIELD_H - 1; i > FIELD_H - 4; i--) {
    for (int j = 0; j < FIELD_W; j++) {
      state->field[i][j] = 1;
    }
  }
  consume_rows();
  ck_assert_int_eq(state->score, 700);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(consume_6) {
  initialize_state();
  State_t *state = get_current_state();
  for (int i = FIELD_H - 1; i > FIELD_H - 5; i--) {
    for (int j = 0; j < FIELD_W; j++) {
      state->field[i][j] = 1;
    }
  }
  consume_rows();
  ck_assert_int_eq(state->score, 1500);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(input_terminate) {
  initialize_state();
  State_t *state = get_current_state();
  userInput(Terminate);
  ck_assert_int_eq(state->status, Initial);
}
END_TEST

START_TEST(timer_2) {
  initialize_state();
  State_t *state = get_current_state();
  state->status = Spawn;
  unsigned long long time_left = process_timer();
  ck_assert_int_eq(state->time_left, time_left);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(attach_2) {
  initialize_state();
  State_t *state = get_current_state();
  for (int i = 0; i < state->block_size; i++) {
    for (int j = 0; j < state->block_size; j++) {
      state->block[i][j] = 0;
    }
  }
  attach_block();
  ck_assert_int_eq(state->status, Spawn);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(right_2) {
  initialize_state();
  State_t *state = get_current_state();
  int coord_y = state->coord_y;
  state->coord_y += 2;
  state->coord_x += 4;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      state->field[i][j] = 1;
    }
  }
  move_block_right();
  ck_assert_int_eq(state->coord_y, coord_y + 2);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(left_2) {
  initialize_state();
  State_t *state = get_current_state();
  int coord_y = state->coord_y;
  state->coord_y += 2;
  state->coord_x += 4;
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      state->field[i][j] = 1;
    }
  }
  move_block_left();
  ck_assert_int_eq(state->coord_y, coord_y + 2);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
}
END_TEST

START_TEST(can_rotate_2) {
  initialize_state();
  int block_size;
  int **new_block = generate_new_block(&block_size);
  State_t *state = get_current_state();
  state->coord_x = 3;
  for (int i = 0; i < block_size; i++) {
    for (int j = 0; j < block_size; j++) {
      state->block[i][j] = 1;
    }
  }
  for (int i = 0; i < FIELD_H; i++) {
    for (int j = 0; j < FIELD_W; j++) {
      state->field[i][j] = 1;
    }
  }
  int can_rotate = can_rotate_block(new_block);
  ck_assert_int_eq(can_rotate, 0);
  free_matrix(state->block, state->block_size);
  free_matrix(state->next_block, state->next_block_size);
  free_matrix(state->field, FIELD_H);
  free_matrix(new_block, block_size);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");

  TCase *tc_tetris;

  tc_tetris = tcase_create("OK");
  suite_add_tcase(s, tc_tetris);
  tcase_add_test(tc_tetris, init_1);
  tcase_add_test(tc_tetris, init_2);
  tcase_add_test(tc_tetris, init_3);
  tcase_add_test(tc_tetris, init_4);
  tcase_add_test(tc_tetris, init_5);
  tcase_add_test(tc_tetris, shift);
  tcase_add_test(tc_tetris, spawn);
  tcase_add_test(tc_tetris, right_1);
  tcase_add_test(tc_tetris, left_1);
  tcase_add_test(tc_tetris, input_start);
  tcase_add_test(tc_tetris, consume_1);
  tcase_add_test(tc_tetris, pause_1);
  tcase_add_test(tc_tetris, timer_1);
  tcase_add_test(tc_tetris, input_left);
  tcase_add_test(tc_tetris, input_right);
  tcase_add_test(tc_tetris, consume_2);
  tcase_add_test(tc_tetris, input_down);
  tcase_add_test(tc_tetris, can_rotate_1);
  tcase_add_test(tc_tetris, rotate_1);
  tcase_add_test(tc_tetris, attach_1);
  tcase_add_test(tc_tetris, input_action);
  tcase_add_test(tc_tetris, update_state);
  tcase_add_test(tc_tetris, consume_3);
  tcase_add_test(tc_tetris, consume_4);
  tcase_add_test(tc_tetris, consume_5);
  tcase_add_test(tc_tetris, consume_6);
  tcase_add_test(tc_tetris, input_terminate);
  tcase_add_test(tc_tetris, timer_2);
  tcase_add_test(tc_tetris, attach_2);
  tcase_add_test(tc_tetris, right_2);
  tcase_add_test(tc_tetris, left_2);
  tcase_add_test(tc_tetris, can_rotate_2);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;
  int nf = 0;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
