#ifndef SNAKE_GAME_H
#define SNAKE_GAME_H

#include <chrono>
#include <fstream>
#include <list>
#include <random>

#include "../../game_params.h"

namespace s21 {

enum class State_snake { Start, Move, Pause, GameLost, GameWon };

enum class Direction { Up, Down, Left, Right };

class SnakeGame {
   public:
    SnakeGame();

    GameInfo& updateCurrentState() const;
    double get_time_left() const;

    void userInput(UserAction_t action, bool hold);

   private:
    struct Point {
        Point(int x, int y);
        Point(const Point& other);

        Point& operator=(const Point& other);

        bool operator==(const Point& other) const;
        bool operator!=(const Point& other) const;

        int x_;
        int y_;
    };

#ifdef TESTING
    friend class SnakeTest;
    FRIEND_TEST(SnakeTest, Tests);
#endif

    Point get_new_head(Direction direction) const;
    Point spawn_apple() const;
    int get_max_score() const;
    bool game_won() const;
    bool game_lost() const;

    void initialize_game();
    void turn(Direction direction);
    void update_level_and_max_score();
    void refresh_timer();
    void reset_timer();
    void move();

    std::list<Point> snake_body;
    Direction snake_direction;
    Point apple;
    State_snake state;
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