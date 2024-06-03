#ifndef FRONT
#define FRONT
#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/*!
 * \file front.h
 * \brief File containes frontend functions for Skibidi Kirpichi Game.
 */
#include "../../brick_game/tetris/tetris.h"

#define WIDTH 10
#define HEIGHT_WF 25

/**
 * @brief This struct keeps 3 windows of the Skibidi Kirpichi Game.
 */
typedef struct {
  WINDOW *win;
  WINDOW *nextfigure;
  WINDOW *addinfo;
} WinStruct;

void init_curses();
void draw_board(GameInfo_t *field, WINDOW *win);
void draw_next(GameInfo_t *game, WINDOW *nextfigure);
void draw_addinfo(GameInfo_t *game, WINDOW *addinfo);
void draw_gameover(WinStruct *window);
void draw_frontend(GameInfo_t *game, WinStruct *window);
void draw_pause(WinStruct *window);
WinStruct *init_windows();

#endif