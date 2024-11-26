#ifndef GAME_PARAMS_H
#define GAME_PARAMS_H

#define FIELD_H 20
#define FIELD_W 10
#define MAX_LEVEL 10
#define SPEED 500
#define MIN_SPEED 50
#define SPEED_STEP 30
#define DESKTOP_HOLD_TIMEOUT 10
#define CLI_HOLD_TIMEOUT 10
#define NEW_LEVEL_TRESHOLD_TETRIS 600
#define NEW_LEVEL_TRESHOLD_SNAKE 5

namespace s21 {

enum struct UserAction_t {
    Start,
    Pause,
    Terminate,
    Left,
    Right,
    Up,
    Down,
    Action
};

struct GameInfo {
    GameInfo()
        : field(nullptr),
          next(nullptr),
          score(0),
          pause(0),
          level(1),
          speed(SPEED),
          max_score(0) {}

    ~GameInfo() {
        if (field != nullptr) {
            for (int i = 0; i < FIELD_W; ++i) {
                delete[] field[i];
            }
            delete[] field;
        }

        if (next != nullptr) {
            for (int i = 0; i < 4; ++i) {
                delete[] next[i];
            }
            delete[] next;
        }
    }

    int** field;
    int** next;
    int score;
    int pause;
    int level;
    int speed;
    int max_score;
};

}  // namespace s21

#endif