/**
 * @file tetris.h
 * @brief Файл содержит объявления функций, объявленный в файле tetris.с
 *
 */
#ifndef TERTIS_H
#define TERTIS_H

#include "brick_game/tetris/backend.h"
#include "gui/cli/frontend.h"

void gameLoop();
void setTimer();
void setSignals();
void handler(int signum);

#endif  // TERTIS_H