#ifndef FROGGER_FRONTEND_H
#define FROGGER_FRONTEND_H

#include <string.h>
#include "defines.h"
#include "objects.h"

void print_overlay(void);
void print_levelerror(void);
void print_rectangle(int top_y, int bottom_y, int left_x, int right_x);
void print_stats(game_stats_t *stats);
void print_board(board_t *game, player_pos *frog);
void print_cars(board_t *game);
void print_finished(board_t *game);
void print_banner(game_stats_t *stats);
int read_banner(game_stats_t *stats, banner_t *banner);

#endif