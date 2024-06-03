#ifndef FSM_H
#define FSM_H

#include "defines.h"
#include "objects.h"
#include "frog_backend.h"
#include "frog_frontend.h"

typedef enum
{
    START = 0,
    SPAWN,
    MOVING,
    SHIFTING,
    REACH,
    COLLIDE,
    GAMEOVER,
    EXIT_STATE,
    FILE_ERROR_STATE
} frog_state;

typedef enum
{
    MOVE_UP = 0,
    MOVE_DOWN,
    MOVE_RIGHT,
    MOVE_LEFT,
    ESCAPE_BTN,
    ENTER_BTN,
    NOSIG
} signals;

signals get_signal(int user_input);
void sigact(signals sig, frog_state *state, game_stats_t *stats, board_t *map, player_pos *frog_pos);

#endif