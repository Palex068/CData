#ifndef TETRIS_GAME_H
#define TETRIS_GAME_H

#include <chrono>
#include <fstream>
#include <list>
#include <map>
#include <random>

#include "../../game_params.h"

namespace s21 {

enum State { Start, Move, Attaching, Pause, GameLost };

enum Block_type { ALPHA, BETA, GAMMA, DELTA, OMEGA, PSI, ZETA };

class TetrisGame {
   public:
    TetrisGame();

    GameInfo& updateCurrentState() const;
    double get_time_left() const;

    void userInput(UserAction_t action, bool hold);

   private:
    struct Point {
        Point();
        Point(int x, int y);
        Point(const Point& other);

        Point& operator=(const Point& other);
        bool operator==(const Point& other) const;

        int x_;
        int y_;
    };

    struct Block {
        Block();
        Block(const Block& other);

        Block& operator=(const Block& other);

        void rotate();
        void shift(int shift_x, int shift_y);

        std::list<Point> points_;
        int size_;
        Point coordinates_;
    };

#ifdef TESTING
    friend class TetrisTest;
    FRIEND_TEST(TetrisTest, Tests);
#endif

    bool valid_coordinate(int x, int y) const;
    bool block_is_attached() const;
    bool can_move_block() const;
    bool game_lost() const;
    int get_max_score() const;

    void initialize_game();
    void update_level_and_max_score();
    void refresh_timer();
    void reset_timer();
    void attach_block();
    void consume_rows();

    std::list<Point> field_points;
    Block block;
    Block next_block;
    State state;
    int score;
    int level;
    int speed;
    int normal_speed;
    int max_score;
    std::chrono::time_point<std::chrono::steady_clock> timestamp;
    double time_left;
};

}  // namespace s21

#endif