#ifndef CLI_VIEW_H
#define CLI_VIEW_H

#include <ncurses.h>
#undef scroll
#undef timeout
#include <string>

#include "../../game_params.h"

#define ACTION_BUTTON 32
#define TERMINATE_BUTTON 27
#define PAUSE_BUTTON 112
#define START_BUTTON 115

namespace s21 {

struct CLIInput {
    CLIInput(UserAction_t action, bool hold, bool time_finished);

    UserAction_t action_;
    bool hold_;
    bool time_finished_;
};

class CLIView {
   public:
    CLIView();
    ~CLIView();

    void render(GameInfo& game_info);
    CLIInput get_input(double time_left);

   private:
    bool check_for_hold(int c);
};

}  // namespace s21

#endif
