#include <ncurses.h>
#include <signal.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "common/common.h"
#include "common/game_info_t.h"
#include "gui_cli.h"

void gui_cli_resize() {
  int x = 0, y = 0;
  term_size(&y, &x);
  game_windows_t *windows = get_windows();

  clear();
  if (y < windows->main_win.data.min_hight ||
      x < windows->main_win.data.min_width) {
    small_win_banner(y, x);
  }

  wnoutrefresh(stdscr);
  set_signal_handler(gui_cli_resize);
}