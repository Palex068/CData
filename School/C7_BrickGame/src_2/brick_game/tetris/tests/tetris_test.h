#ifndef TETRIS_TEST_H
#define TETRIS_TEST_H

#include <check.h>

Suite* suite_logo_start();
Suite* suite_logo_game_over();

Suite* suite_tetris_loop();
Suite* suite_game_locate();
Suite* suite_game_init();
Suite* suite_game_destroy();
Suite* suite_game_info_init();
Suite* suite_game_info_clean();
Suite* suite_game_info_destroy();
Suite* suite_game_info_next_init();
Suite* suite_game_info_next_clean();
Suite* suite_game_info_next_destroy();
Suite* suite_figure_db_load();
Suite* suite_figure_db_insert();
Suite* suite_figure_db_destroy();
Suite* suite_figure_create();
Suite* suite_figure_destroy();
Suite* suite_figure_load();
Suite* suite_figure_copy();
Suite* suite_figure_copy_body();
Suite* suite_figure_set();
Suite* suite_figure_unset();
Suite* suite_figure_rotate();
Suite* suite_figure_check();
Suite* suite_kaboom();

Suite* suite_hi_scores_load();
Suite* suite_hi_scores_save();

Suite* suite_fsm();
Suite* suite_start_fn();
Suite* suite_pause_fn();
Suite* suite_spawn_fn();
Suite* suite_move_fn();
Suite* suite_shift_fn();
Suite* suite_connect_fn();
Suite* suite_game_over_fn();
Suite* suite_terminate_fn();
Suite* suite_left_fn();
Suite* suite_right_fn();
Suite* suite_up_fn();
Suite* suite_down_fn();
Suite* suite_action_fn();

Suite* suite_userInput();
Suite* suite_update_current_state();

void run_tests();
void run_test_case(Suite*);

int memory_locked(size_t, int);

#endif