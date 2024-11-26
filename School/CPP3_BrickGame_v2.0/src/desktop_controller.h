#ifndef QT_GAME_CONTROLLER_H
#define QT_GAME_CONTROLLER_H

#include <QObject>
#include <QTimer>

#include "brick_game/snake/snake_game.h"
#include "brick_game/tetris/tetris_game.h"
#include "gui/desktop/desktop_view.h"

namespace s21 {

class DesktopControllerSnake : public QObject {
    Q_OBJECT

   public:
    DesktopControllerSnake(SnakeGame& game, DesktopView& view)
        : game_(game), view_(view) {
        connect(&timer_, &QTimer::timeout, this,
                &DesktopControllerSnake::move_game);
        connect(&view_, &DesktopView::key_pressed, this,
                &DesktopControllerSnake::handle_action);
        connect(&view_, &DesktopView::terminate_game_pressed, this,
                &DesktopControllerSnake::terminate_game);
    }

    ~DesktopControllerSnake() {
        game_.~SnakeGame();
        view_.~DesktopView();
        exit(0);
    }

   public slots:
    void handle_action(DesktopInput input) {
        game_.userInput(input.action_, input.hold_);
        update_game();
    }

    void move_game() {
        bool hold = false;
        DesktopInput input = view_.get_input();
        if (input.hold_ == true && input.action_ == UserAction_t::Action) {
            hold = true;
        }
        game_.userInput(UserAction_t::Action, hold);
        update_game();
    }

    void terminate_game() { this->~DesktopControllerSnake(); }

   private:
    SnakeGame& game_;
    DesktopView& view_;
    QTimer timer_;

    void update_game() {
        GameInfo& game_info = game_.updateCurrentState();
        view_.render(game_info);
        delete &game_info;

        double time_left = game_.get_time_left();
        if (time_left < 0) {
            timer_.stop();
        } else {
            timer_.start(time_left);
        }
    }
};

class DesktopControllerTetris : public QObject {
    Q_OBJECT

   public:
    DesktopControllerTetris(TetrisGame& game, DesktopView& view)
        : game_(game), view_(view) {
        connect(&timer_, &QTimer::timeout, this,
                &DesktopControllerTetris::move_game);
        connect(&view_, &DesktopView::key_pressed, this,
                &DesktopControllerTetris::handle_action);
        connect(&view_, &DesktopView::terminate_game_pressed, this,
                &DesktopControllerTetris::terminate_game);
    }

    ~DesktopControllerTetris() {
        game_.~TetrisGame();
        view_.~DesktopView();
        exit(0);
    }

   public slots:
    void handle_action(DesktopInput input) {
        game_.userInput(input.action_, input.hold_);
        update_game();
    }

    void move_game() {
        bool hold = false;
        DesktopInput input = view_.get_input();
        if (input.hold_ == true && input.action_ == UserAction_t::Down) {
            hold = true;
        }
        game_.userInput(UserAction_t::Down, hold);
        update_game();
    }

    void terminate_game() { this->~DesktopControllerTetris(); }

   private:
    TetrisGame& game_;
    DesktopView& view_;
    QTimer timer_;

    void update_game() {
        GameInfo& game_info = game_.updateCurrentState();
        view_.render(game_info);
        delete &game_info;

        double time_left = game_.get_time_left();
        if (time_left < 0) {
            timer_.stop();
        } else {
            timer_.start(time_left);
        }
    }
};

}  // namespace s21

#endif