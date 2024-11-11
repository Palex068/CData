#ifndef FROGGER_BACKEND_H
#define FROGGER_BACKEND_H

#include <ncurses.h>
#include "defines.h"
#include "objects.h"
#include "string.h"

int lvlproc(board_t *map, game_stats_t *stats);
void add_proggress(board_t *map);
void stats_init(game_stats_t *stats);
void frogpos_init(player_pos *frog);
void fill_finish(char *finish_line);
void shift_map(board_t *map);

bool check_collide(player_pos *frog, board_t *map);
bool check_finish_state(player_pos *frog, board_t *map);
bool check_level_compl(board_t *map);

#endif