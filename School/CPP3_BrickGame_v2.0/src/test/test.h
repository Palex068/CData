#ifndef S21_TEST_H
#define S21_TEST_H

#define TESTING

#include <gtest/gtest.h>

#include "../brick_game/snake/snake_game.h"
#include "../brick_game/tetris/tetris_game.h"
#include "../game_params.h"

class SnakeTest : public testing::Test {};
class TetrisTest : public testing::Test {};

#endif