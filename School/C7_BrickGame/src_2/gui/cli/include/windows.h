#ifndef WINDOWS_H
#define WINDOWS_H

#include <ncurses.h>
#include <panel.h>

enum window_setting {
  main_min_higth = 24,
  main_min_width = 46,
  game_min_higth = 22,
  game_min_width = 22,
};

typedef struct __win_data {
  int start_x, start_y;
  int min_hight, min_width;
  int hight, width;

  char *label;
  bool show;
} win_data_t;

typedef struct __windows {
  WINDOW *win;
  win_data_t data;
} win_t;

typedef struct __game_windows {
  win_t main_win;
  win_t game_win;
  win_t stat_win;
  win_t *stats_winds;

  int count_stat_win;
} game_windows_t;

game_windows_t *get_windows();
void small_win_banner(int y, int x);

int init_win(WINDOW *parent, win_t *child, win_data_t data, bool boxing);
int init_game_windows(game_windows_t *windows);
int del_game_windows(game_windows_t *windows);

int add_sup_win(game_windows_t *windows, win_data_t data);
int destroy_supp_win(game_windows_t *windows);

#endif