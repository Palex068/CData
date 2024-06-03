#ifndef S21_TETRIS_OBJECTS_H
#define S21_TETRIS_OBJECTS_H

#include <stdbool.h>

#include "../constants.h"
#include "../interfaces.h"
#include "../objects.h"

typedef enum {
  TTRS_START_STATE,

  TTRS_SPAWN_STATE,
  TTRS_MOVING_STATE,
  TTRS_ATTACHING_STATE,

  TTRS_GAME_OVER_STATE,

  TTRS_EXIT_STATE,
} TTRS_tetris_state;

#define TTRS_RETURN_TYPE char
typedef enum {
  TTRS_Ok,
  TTRS_Error,
  TTRS_MemoryError,
} TTRS_ReturnError_t;

typedef struct {
  bool is_game_start;
  TTRS_tetris_state state;

  BG_GI_CEIL_TYPE **board;
  BG_GI_CEIL_TYPE **preview_board;

  BG_GI_CEIL_TYPE **cur_tetromino;

  BG_Point2D_t cur_tetromino_pos;

  BG_GI_CEIL_TYPE **next_tetromino;

  int score;
  int high_score;
  int level;
  int speed;
  int pause;

  BG_UserInput_t last_user_input;

  bool is_fall_time;

} TTRS_tetris_t;

#endif
