#include "../../../includes/brick_game/v1/gui/cli.h"

void CLI_createWindowWithBoard(WINDOW **window, BG_Point2D_t window_size,
                               BG_Point2D_t window_pos) {
  *window = newwin(window_size.y, window_size.x, (int)window_pos.y,
                   (int)window_pos.x);

  wclear(*window);

  wrefresh(*window);
}

void CLI_print_start_preview() {
  WINDOW *temp_win = newwin(4, 15, 10, 10);

  wmove(temp_win, 13, 13);
  wprintw(temp_win,
          "\n  Press ENTER"
          "\n   to START");

  wborder(temp_win, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(temp_win);

  delwin(temp_win);
}

void CLI_print_end_preview() {
  WINDOW *temp_win = newwin(6, 26, 10, 10);

  wmove(temp_win, 13, 13);
  wprintw(temp_win,
          "\n       !GAME OVER!"
          "\n   Press ENTER to START"
          "\n           OR"
          "\n       Esc to quit");

  wborder(temp_win, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(temp_win);

  delwin(temp_win);
}

void CLI_print_pause_preview() {
  WINDOW *temp_win = newwin(3, 9, 10, 10);

  wmove(temp_win, 13, 13);
  wprintw(temp_win, "\n  PAUSE");

  wborder(temp_win, 0, 0, 0, 0, 0, 0, 0, 0);
  wrefresh(temp_win);

  delwin(temp_win);
}

void CLI_print_full_line(WINDOW *win, size_t count, chtype symbol) {
  if (win) {
    for (size_t i = 0; i < count; i++) {
      waddch(win, symbol);
    }
  }
}

void CLI_printBoardSymbol(WINDOW *win, chtype symbol) {
  for (size_t i = 0; i < CLI_VIEW_CHAR_SIZE_Y; i++) {
    for (size_t j = 0; j < CLI_VIEW_CHAR_SIZE_X; j++) {
      waddch(win, symbol);
    }
  }
}
