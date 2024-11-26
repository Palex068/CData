#ifndef TETRIS_H
#define TETRIS_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>

#include "../../common.h"

#define SPEED 500
#define SPEED_STEP 30
#define NEW_LEVEL_TRESHOLD 600
#define MAX_LEVEL 10




typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Action
} UserAction_t;


typedef enum { Initial, Spawn, Moving, Shifting, Attaching, GameOver } Status_t;

typedef struct {
  int status;
  int **field;
  int **block;
  int block_size;
  int **next_block;
  int next_block_size;
  int coord_x;
  int coord_y;
  int score;
  int level;
  int speed;
  int pause;
  unsigned long long start_time;
  unsigned long long time_left;
} State_t;

typedef enum { ALPHA, BETA, GAMMA, DELTA, OMEGA, PSI, ZETA } Block;

GameInfo_t updateCurrentState();
void spawn_new_block();
void move_block_left();
void move_block_right();
void shift_block();
void attach_block();
int block_is_attached();
void rotate_block();
void initialize_state();
void userInput(UserAction_t action);
State_t *get_current_state();
int can_rotate_block(int **new_block);
void rotate(int **new, int **old, int size);
void consume_rows();
void copy_matrix(int **dest, int **src, int H, int W);
int **generate_new_block(int *block_size);
void finish_game();
unsigned long long process_timer();
int **create_matrix(int H, int W);
void save_max_score();
void update_level();
void start_game();
unsigned long long current_time_millis();
void pause_game();
void free_matrix(int **matrix, int H);

#endif
