#ifndef CLI_CONTROLLER_H
#define CLI_CONTROLLER_H

#include "brick_game/snake/snake_game.h"
#include "brick_game/tetris/tetris_game.h"
#include "gui/cli/cli_view.h"

namespace s21 {

template <typename GameType>
class CLIController {
   public:
    CLIController(GameType& game, CLIView& view);
    ~CLIController();

    void run();

   private:
    GameType& game_;
    CLIView& view_;

    void render();
    CLIInput get_input();
    void process_input(CLIInput input);
    void pass_input(CLIInput input);
    void continue_game();
    void terminate_game();
};

template <typename GameType>
CLIController<GameType>::CLIController(GameType& game, CLIView& view)
    : game_(game), view_(view) {}

template <typename GameType>
CLIController<GameType>::~CLIController() {
    game_.~GameType();
    view_.~CLIView();
    exit(0);
}

template <typename GameType>
void CLIController<GameType>::run() {
    while (true) {
        render();
        CLIInput input = get_input();
        process_input(input);
    }
}

template <typename GameType>
void CLIController<GameType>::render() {
    GameInfo& game_info = game_.updateCurrentState();
    view_.render(game_info);
    delete &game_info;
}

template <>
void CLIController<SnakeGame>::continue_game() {
    game_.userInput(UserAction_t::Action, false);
}

template <>
void CLIController<TetrisGame>::continue_game() {
    game_.userInput(UserAction_t::Down, false);
}

template <typename GameType>
void CLIController<GameType>::terminate_game() {
    this->~CLIController();
}

template <typename GameType>
void CLIController<GameType>::pass_input(CLIInput input) {
    game_.userInput(input.action_, input.hold_);
}

template <typename GameType>
CLIInput CLIController<GameType>::get_input() {
    return view_.get_input(game_.get_time_left());
}

template <typename GameType>
void CLIController<GameType>::process_input(CLIInput input) {
    if (input.action_ == UserAction_t::Terminate) {
        terminate_game();
    } else if (input.time_finished_ == false) {
        pass_input(input);
    } else {
        continue_game();
    }
}

}  // namespace s21

#endif