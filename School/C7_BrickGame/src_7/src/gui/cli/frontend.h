#ifndef FRONTEND_H_SENTRY
#define FRONTEND_H_SENTRY

#include <errno.h>
#include <stdio.h>

#include "../../brick_game/tetris/backend.h"

#define BUFFER 1024

void initScreen();
void initScore();
char* scorePath(char* path);
void loadScore();
void saveScore();

WINDOW* createWindow(int H, int W, int y, int x, bool frame);
void destroyWindow(WINDOW* win);

void refreshScreen(WINDOW* win, WINDOW* next);
void drawField(WINDOW* win);
void drawNext(WINDOW* win);
void drawInfo(GameInfo_t info);

#endif
