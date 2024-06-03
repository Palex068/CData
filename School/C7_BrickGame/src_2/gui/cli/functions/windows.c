#include "windows.h"

#include <errno.h>
#include <malloc.h>
#include <string.h>

game_windows_t *get_windows() {
  static game_windows_t windows = {0};
  return &windows;
}

int init_win(WINDOW *parent, win_t *child, win_data_t data, bool boxing) {
  if (!parent || !child) return EFAULT;

  child->win =
      derwin(parent, data.hight, data.width, data.start_y, data.start_x);
  child->data = data;
  if (boxing) box(child->win, 0, 0);

  wrefresh(child->win);
  wnoutrefresh(child->win);
  return 0;
}

int init_game_windows(game_windows_t *windows) {
  if (!windows) return EFAULT;

  // main_win
  init_win(stdscr, &(windows->main_win),
           (win_data_t){.start_x = 0,
                        .start_y = 0,
                        .hight = main_min_higth,
                        .min_hight = main_min_higth,
                        .width = main_min_width,
                        .min_width = main_min_width},
           TRUE);

  // game_win
  init_win(windows->main_win.win, &(windows->game_win),
           (win_data_t){.start_x = 1,
                        .start_y = 1,
                        .hight = game_min_higth,
                        .min_hight = game_min_higth,
                        .width = game_min_width,
                        .min_width = game_min_width},
           TRUE);

  // stat_win
  init_win(windows->main_win.win, &(windows->stat_win),
           (win_data_t){.start_x = 1 + game_min_width,
                        .start_y = 1,
                        .hight = game_min_higth,
                        .min_hight = game_min_higth,
                        .width = game_min_width,
                        .min_width = game_min_width},
           TRUE);
  return 0;
}

int del_game_windows(game_windows_t *windows) {
  if (windows == NULL) return EFAULT;

  delwin(windows->stat_win.win);
  delwin(windows->game_win.win);
  delwin(windows->main_win.win);

  return 0;
}

int add_sup_win(game_windows_t *windows, win_data_t data) {
  if (windows == NULL) return EFAULT;

  windows->stats_winds = realloc(windows->stats_winds,
                                 sizeof(win_t) * (windows->count_stat_win + 1));
  init_win(windows->stat_win.win,
           &windows->stats_winds[windows->count_stat_win], data, TRUE);
  windows->count_stat_win += 1;

  return 0;
}

int destroy_supp_win(game_windows_t *windows) {
  if (windows == NULL) return EFAULT;

  for (int i = 0; i < windows->count_stat_win; i++) {
    delwin(windows->stats_winds[i].win);
  }

  windows->count_stat_win = 0;
  free(windows->stats_winds), windows->stats_winds = NULL;

  return 0;
}

void small_win_banner(int y, int x) {
  game_windows_t *windows = get_windows();

  const char error_title[] = "SMALL TERMINAL";
  const char error_desc[] = "required %dx%d (now %dx%d)";

  clear();
  wattron(stdscr, WA_BLINK);
  mvwprintw(stdscr, y / 2, ((x - strlen(error_title)) / 2), error_title);
  mvwprintw(stdscr, y / 2 + 1, ((x - strlen(error_desc)) / 2), error_desc,
            windows->main_win.data.min_width, windows->main_win.data.min_hight,
            x, y);
  wattroff(stdscr, WA_BLINK);
  wnoutrefresh(stdscr);
}