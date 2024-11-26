#ifndef GAME_H
#define GAME_H

#define ACTION_BUTTON 32
#define TERMINATE_BUTTON 27
#define PAUSE_BUTTON 112
#define START_BUTTON 115

#include <unistd.h>

#include "gui/cli/console_front.h"
#include "brick_game/tetris/tetris.h"
#include "common.h"

void updateUserAction();

#endif