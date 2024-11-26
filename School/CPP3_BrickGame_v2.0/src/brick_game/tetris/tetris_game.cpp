#include "tetris_game.h"

namespace s21 {

TetrisGame::TetrisGame()
    : field_points({}),
      block(Block()),
      next_block(Block()),
      state(State::Start),
      score(0),
      level(1),
      speed(SPEED),
      normal_speed(SPEED),
      max_score(get_max_score()),
      time_left(-1) {}

TetrisGame::Point::Point() : x_(0), y_(0) {}

TetrisGame::Point::Point(int x, int y) : x_(x), y_(y) {}

TetrisGame::Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {}

TetrisGame::Point& TetrisGame::Point::operator=(const Point& other) {
    if (this != &other) {
        x_ = other.x_;
        y_ = other.y_;
    }
    return *this;
}

bool TetrisGame::Point::operator==(const Point& other) const {
    return (x_ == other.x_ && y_ == other.y_);
}

TetrisGame::Block::Block() {
    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib_gen(0, 6);

    int type = distrib_gen(gen);

    if (type == Block_type::ALPHA) {
        size_ = 4;
    } else if (type == Block_type::DELTA) {
        size_ = 2;
    } else {
        size_ = 3;
    }

    coordinates_ = Point((FIELD_W - size_) / 2, FIELD_H);

    if (type == Block_type::ALPHA) {
        points_ = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
    } else if (type == Block_type::BETA) {
        points_ = {{1, 0}, {0, 0}, {0, 1}, {0, 2}};
    } else if (type == Block_type::GAMMA) {
        points_ = {{1, 2}, {0, 0}, {0, 1}, {0, 2}};
    } else if (type == Block_type::DELTA) {
        points_ = {{0, 0}, {0, 1}, {1, 0}, {1, 1}};
    } else if (type == Block_type::OMEGA) {
        points_ = {{0, 0}, {0, 1}, {1, 1}, {1, 2}};
    } else if (type == Block_type::PSI) {
        points_ = {{0, 0}, {0, 1}, {0, 2}, {1, 1}};
    } else {
        points_ = {{1, 0}, {1, 1}, {0, 1}, {0, 2}};
    }

    std::uniform_int_distribution<> distrib_rot(0, 3);

    int rotations = distrib_rot(gen);

    for (int i = 0; i < rotations; ++i) {
        rotate();
    }
}

TetrisGame::Block::Block(const Block& other)
    : points_(other.points_),
      size_(other.size_),
      coordinates_(other.coordinates_) {}

void TetrisGame::Block::rotate() {
    std::list<Point> new_points;

    if (size_ == 4) {
        if (*(points_.begin()) == Point(0, 0)) {
            new_points = {{0, 1}, {1, 1}, {2, 1}, {3, 1}};
        } else {
            new_points = {{0, 0}, {0, 1}, {0, 2}, {0, 3}};
        }
    } else {
        for (auto it = points_.begin(); it != points_.end(); ++it) {
            new_points.push_back({(*it).y_, size_ - 1 - (*it).x_});
        }
    }

    points_ = new_points;
}

void TetrisGame::Block::shift(int shift_x, int shift_y) {
    coordinates_.x_ += shift_x;
    coordinates_.y_ += shift_y;
}

TetrisGame::Block& TetrisGame::Block::operator=(const Block& other) {
    if (this != &other) {
        points_ = other.points_;
        size_ = other.size_;
        coordinates_ = other.coordinates_;
    }
    return *this;
}

bool TetrisGame::valid_coordinate(int x, int y) const {
    if (x < 0 || y < 0 || x >= FIELD_W || y >= FIELD_H) {
        return false;
    } else {
        return true;
    }
}

bool TetrisGame::block_is_attached() const {
    for (auto block_it = block.points_.begin(); block_it != block.points_.end();
         ++block_it) {
        for (auto field_it = field_points.begin();
             field_it != field_points.end(); ++field_it) {
            if ((((*block_it).x_ + block.coordinates_.x_) == (*field_it).x_) &&
                (((*block_it).y_ + block.coordinates_.y_ - 1) ==
                 (*field_it).y_)) {
                return true;
            }
        }
        if ((*block_it).y_ + block.coordinates_.y_ <= 0) {
            return true;
        }
    }

    return false;
}

bool TetrisGame::can_move_block() const {
    for (auto block_it = block.points_.begin(); block_it != block.points_.end();
         ++block_it) {
        if ((((*block_it).x_ + block.coordinates_.x_) < 0) ||
            (((*block_it).x_ + block.coordinates_.x_) >= FIELD_W) ||
            (((*block_it).y_ + block.coordinates_.y_) < 0)) {
            return false;
        }

        for (auto field_it = field_points.begin();
             field_it != field_points.end(); ++field_it) {
            if ((((*block_it).x_ + block.coordinates_.x_) == (*field_it).x_) &&
                (((*block_it).y_ + block.coordinates_.y_) == (*field_it).y_)) {
                return false;
            }
        }
    }

    return true;
}

bool TetrisGame::game_lost() const {
    for (auto it = field_points.begin(); it != field_points.end(); ++it) {
        if ((*it).y_ > FIELD_H - 1) {
            return true;
        }
    }

    return false;
}

int TetrisGame::get_max_score() const {
    int max_score = 0;

    std::ifstream file("max_score_tetris.txt");

    if (file.is_open()) {
        file >> max_score;
        file.close();
    }

    return max_score;
}

void TetrisGame::initialize_game() {
    field_points = {};
    block = Block();
    next_block = Block();
    state = State::Start;
    score = 0;
    level = 1;
    speed = SPEED;
    normal_speed = SPEED;
    max_score = get_max_score();
    time_left = -1;
}

void TetrisGame::update_level_and_max_score() {
    int new_level = score / NEW_LEVEL_TRESHOLD_TETRIS + 1;
    if (new_level > MAX_LEVEL) {
        new_level = MAX_LEVEL;
    }

    normal_speed -= (new_level - level) * SPEED_STEP;
    level = new_level;

    if (score > max_score) {
        max_score = score;
        std::ofstream file("max_score_tetris.txt");

        if (file.is_open()) {
            file << max_score;
            file.close();
        }
    }
}

void TetrisGame::refresh_timer() {
    std::chrono::time_point<std::chrono::steady_clock> current_time =
        std::chrono::steady_clock::now();
    std::chrono::duration<double, std::milli> elapsed =
        current_time - timestamp;
    timestamp = current_time;
    double time_passed = static_cast<double>(elapsed.count());

    if (time_passed < time_left) {
        time_left -= time_passed;
    } else {
        time_left = 0;
    }
}

void TetrisGame::reset_timer() {
    timestamp = std::chrono::steady_clock::now();
    time_left = speed;
}

void TetrisGame::attach_block() {
    for (auto it = block.points_.begin(); it != block.points_.end(); ++it) {
        field_points.push_back({(*it).x_ + block.coordinates_.x_,
                                (*it).y_ + block.coordinates_.y_});
    }

    block = next_block;
    next_block = Block();

    if (game_lost() == true) {
        state = State::GameLost;
        time_left = -1;
    } else {
        consume_rows();
        state = State::Move;
        reset_timer();
    }
}

void TetrisGame::consume_rows() {
    std::map<int, int> rows;

    int consumed_rows = 0;

    for (auto it = field_points.begin(); it != field_points.end(); ++it) {
        ++(rows[FIELD_H - (*it).y_ - 1]);
    }

    for (auto rows_it = rows.begin(); rows_it != rows.end(); ++rows_it) {
        if ((*rows_it).second == FIELD_W) {
            ++consumed_rows;

            auto field_it = field_points.begin();
            while (field_it != field_points.end()) {
                if ((*rows_it).first == FIELD_H - (*field_it).y_ - 1) {
                    field_it = field_points.erase(field_it);
                } else if ((*rows_it).first >= FIELD_H - (*field_it).y_ &&
                           (*field_it).y_ > 0) {
                    --((*field_it).y_);
                    ++field_it;
                } else {
                    ++field_it;
                }
            }
        }
    }

    if (consumed_rows == 1) {
        score += 100;
    } else if (consumed_rows == 2) {
        score += 300;
    } else if (consumed_rows == 3) {
        score += 700;
    } else if (consumed_rows == 4) {
        score += 1500;
    }

    update_level_and_max_score();
}

GameInfo& TetrisGame::updateCurrentState() const {
    GameInfo* game_info = new GameInfo;

    game_info->score = score;
    game_info->level = level;
    game_info->speed = speed;
    game_info->max_score = max_score;
    game_info->pause = (state == State::Pause) ? 1 : 0;
    game_info->field = nullptr;
    game_info->next = nullptr;

    if ((state == State::Move || state == State::Pause ||
         state == State::Attaching)) {
        game_info->field = new int*[FIELD_W];

        for (int i = 0; i < FIELD_W; ++i) {
            game_info->field[i] = new int[FIELD_H]();
        }

        for (auto it = field_points.begin(); it != field_points.end(); ++it) {
            game_info->field[(*it).x_][(*it).y_] = 1;
        }

        for (auto it = block.points_.begin(); it != block.points_.end(); ++it) {
            int new_x = (*it).x_ + block.coordinates_.x_;
            int new_y = (*it).y_ + block.coordinates_.y_;

            if (valid_coordinate(new_x, new_y) == true) {
                game_info->field[new_x][new_y] = 1;
            }
        }

        game_info->next = new int*[4];

        for (int i = 0; i < 4; ++i) {
            game_info->next[i] = new int[4]();
        }

        for (auto it = next_block.points_.begin();
             it != next_block.points_.end(); ++it) {
            game_info->next[(*it).x_][(*it).y_] = 1;
        }
    }

    return *game_info;
}

void TetrisGame::userInput(UserAction_t action, bool hold) {
    if (state == State::Pause) {
        if (action == UserAction_t::Pause) {
            state = State::Move;
            reset_timer();
        }

    } else if (state == State::Start || state == State::GameLost) {
        if (action == UserAction_t::Start) {
            initialize_game();
            state = State::Move;
            reset_timer();
        }
    } else if (state == State::Attaching) {
        attach_block();
    } else if (state == State::Move) {
        if (action == UserAction_t::Pause) {
            state = State::Pause;
            time_left = -1;
            return;
        }

        Block old_block = block;

        if (action == UserAction_t::Left) {
            block.shift(-1, 0);
            refresh_timer();
        } else if (action == UserAction_t::Right) {
            block.shift(1, 0);
            refresh_timer();
        } else if (action == UserAction_t::Action) {
            block.rotate();
            refresh_timer();
        } else if (action == UserAction_t::Down) {
            block.shift(0, -1);
            speed = (hold == true) ? MIN_SPEED : normal_speed;
            reset_timer();
        }

        if (can_move_block() == false) {
            block = old_block;
            if (block_is_attached() == true && action == UserAction_t::Down) {
                state = State::Attaching;
            }
        }
    }
}

double TetrisGame::get_time_left() const { return time_left; }

}  // namespace s21
