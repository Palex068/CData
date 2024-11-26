#include "cli_view.h"

namespace s21 {

void CLIView::render(GameInfo &game_info) {
    WINDOW *game_window = newwin(FIELD_H + 2, 3 * FIELD_W + 2, 0, 0);
    refresh();
    box(game_window, 0, 0);

    if (game_info.field != nullptr) {
        for (int i = 0; i < FIELD_H; ++i) {
            for (int j = 0; j < FIELD_W; ++j) {
                if (game_info.field[j][i] == 1) {
                    mvwprintw(game_window, (FIELD_H - i - 1) + 1, 3 * j + 1,
                              "[ ]");
                } else {
                    mvwprintw(game_window, (FIELD_H - i - 1) + 1, 3 * j + 1,
                              "   ");
                }
            }
        }
    }

    wrefresh(game_window);

    WINDOW *params_window =
        newwin(FIELD_H + 2, 3 * FIELD_W + 2, 0, 3 * FIELD_W + 4);
    refresh();
    box(params_window, 0, 0);

    std::string score = std::to_string(game_info.score);
    mvwprintw(params_window, 2, 5, "SCORE: ");
    mvwprintw(params_window, 2, 12, "%s", score.c_str());

    std::string max_score = std::to_string(game_info.max_score);
    mvwprintw(params_window, 4, 5, "MAX SCORE: ");
    mvwprintw(params_window, 4, 16, "%s", max_score.c_str());

    std::string level = std::to_string(game_info.level);
    mvwprintw(params_window, 6, 5, "LEVEL: ");
    mvwprintw(params_window, 6, 12, "%s", level.c_str());

    std::string speed = std::to_string(game_info.speed);
    mvwprintw(params_window, 8, 5, "SPEED: ");
    mvwprintw(params_window, 8, 12, "%s", speed.c_str());

    if (game_info.pause == 1) {
        mvwprintw(params_window, 10, 5, "GAME PAUSED");
        mvwprintw(params_window, 11, 5, "press P to resume");
    }

    if (game_info.next != nullptr) {
        mvwprintw(params_window, 14, 5, "NEXT: ");
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (game_info.next[i][j] == 1) {
                    mvwprintw(params_window, 16 + j, 5 + i * 3, "[ ]");
                } else {
                    mvwprintw(params_window, 16 + j, 5 + i * 3, "   ");
                }
            }
        }
    }

    wrefresh(params_window);

    delwin(game_window);
    delwin(params_window);
}

CLIInput CLIView::get_input(double time_left) {
    double timer = time_left;

    std::chrono::time_point<std::chrono::steady_clock> timestamp =
        std::chrono::steady_clock::now();

    while (true) {
        timeout(timer);

        flushinp();

        int c = getch();

        flushinp();

        if (c == START_BUTTON) {
            return CLIInput(UserAction_t::Start, check_for_hold(c), false);
        } else if (c == KEY_LEFT) {
            return CLIInput(UserAction_t::Left, check_for_hold(c), false);
        } else if (c == KEY_RIGHT) {
            return CLIInput(UserAction_t::Right, check_for_hold(c), false);
        } else if (c == KEY_UP) {
            return CLIInput(UserAction_t::Up, check_for_hold(c), false);
        } else if (c == KEY_DOWN) {
            return CLIInput(UserAction_t::Down, check_for_hold(c), false);
        } else if (c == TERMINATE_BUTTON) {
            return CLIInput(UserAction_t::Terminate, check_for_hold(c), false);
        } else if (c == PAUSE_BUTTON) {
            return CLIInput(UserAction_t::Pause, check_for_hold(c), false);
        } else if (c == ACTION_BUTTON) {
            return CLIInput(UserAction_t::Action, check_for_hold(c), false);
        } else if (c == ERR) {
            return CLIInput(UserAction_t::Action, false, true);
        } else {
            std::chrono::time_point<std::chrono::steady_clock> current_time =
                std::chrono::steady_clock::now();
            std::chrono::duration<double, std::milli> elapsed =
                current_time - timestamp;
            double time_passed = static_cast<double>(elapsed.count());
            timer = time_passed < time_left ? (time_left - time_passed) : 0;
        }
    }
}

bool CLIView::check_for_hold(int c) {
    flushinp();
    timeout(CLI_HOLD_TIMEOUT);
    int next_ch = getch();
    bool res = (next_ch == c);
    flushinp();
    return res;
}

CLIInput::CLIInput(UserAction_t action, bool hold, bool time_finished)
    : action_(action), hold_(hold), time_finished_(time_finished) {}

CLIView::CLIView() {
    initscr();
    noecho();
    cbreak();
    curs_set(false);
    keypad(stdscr, true);
}

CLIView::~CLIView() { endwin(); }

}  // namespace s21