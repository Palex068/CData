#ifndef OBJECTS_H
#define OBJECTS_H

#include <ncurses.h>
#include "defines.h"

typedef struct
{
    int x;
    int y;
} player_pos;

typedef struct
{
    char finish[BOARD_M + 2];
    char ways[ROWS_MAP + 2][COLS_MAP + 2];
} board_t;

typedef struct
{
    int score;
    int level;
    int speed;
    int lives;
    int won;
} game_stats_t;

typedef struct
{
    char matrix[BANNER_N + 1][BANNER_M + 1];
} banner_t;

#endif