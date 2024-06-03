#ifndef TETRIS
#define TETRIS

/*!
 * \mainpage
 * \author rachellt
 * \version 1.0
 * \file tetris.h
 * \brief Skibidi Kirpichi Game
 */

/*!
 * \file tetris.h
 * \brief File containes declaration of all structs and game funcs of Skibidi
 * Kirpichi Game.
 */
#include <ncurses.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT_WF 25
#define BLOCK_SIZE 5
#define OKK 0
#define COLLISION 1
#define GAME_OVER 1
extern const int figures[7][BLOCK_SIZE][BLOCK_SIZE];

/**
 * @brief Struct with statuses of the game.
 */
typedef enum {
  Start,
  Pause,
  Terminate,
  Left,
  Right,
  Up,
  Down,
  Rotation,
  Sig,
  GameOver,
} UserAction_t;

/**
 * @brief Struct for keeping the game information at the moment.
 */
typedef struct {
  int **field;
  int **next;
  int score;
  int high_score;
  int level;
  int speed;
  int pause;
  int block[BLOCK_SIZE][BLOCK_SIZE];  // текущая фигура
  int block_row;                      // положение по y
  int block_col;                      // положение по x
  int status;                         // текущий статус
} GameInfo_t;

void userInput(GameInfo_t *game, int hold);
void choose_figure(GameInfo_t *game);
void move_left(GameInfo_t *game);
void move_right(GameInfo_t *game);
void move_down(GameInfo_t *game);
void place_block(GameInfo_t *game);
void clear_block(GameInfo_t *game);
void rotate_figure(GameInfo_t *game);
void freeze_block(GameInfo_t *game);
void update_score(GameInfo_t *game, int count);
void free_gameinfo(GameInfo_t *game);
void find_fulls(GameInfo_t *game, int *count);
void update_speed(GameInfo_t *game, int **speed);
void clear_lines(GameInfo_t *game, int row_index);
void check_finish(GameInfo_t *game);
void load_record(GameInfo_t *game);
void write_record(GameInfo_t *game);
int allow_rotation(GameInfo_t *game, int temp[BLOCK_SIZE][BLOCK_SIZE]);
int update_blockcol_left(int dummy[BLOCK_SIZE][BLOCK_SIZE]);
int update_blockcol_right(int dummy[BLOCK_SIZE][BLOCK_SIZE]);
int check_square(GameInfo_t *game);
GameInfo_t *create_game();
GameInfo_t updateCurrentState(GameInfo_t *game, int *move_interval);

#endif