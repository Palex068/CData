// TODO: Инициализация и запуск основного цикла
#include <errno.h>
#include <locale.h>
#include <ncurses.h>
#include <pthread.h>
#include <signal.h>
#include <stddef.h>

#include "common/common.h"
#include "common/game_info_t.h"
#include "common/runtime_t.h"
#include "gui_cli.h"

void* gui_cli_loop(runtime_t* runtime) {
  extern game_info_t update_current_state();

  int code = 0;
  code = (runtime == NULL) * EFAULT;

  if (!code) {
    int x = 0, y = 0;
    signals_block();
    signals_unblock();
    set_signal_handler(gui_cli_resize);
    pthread_mutex_lock(&runtime->stdout_mutex);

    setlocale(LC_CTYPE, "");  // Стоит перенести в init
    initscr();                // Стоит перенести в init
    start_color();            // Цвета
    curs_set(0);              // мерцание курсора

    game_windows_t* windows = get_windows();
    init_game_windows(windows);
    doupdate();

    game_info_t game_info = {0};
    while (!atomic_load(&runtime->game_stop)) {
      term_size(&y, &x);
      pthread_mutex_lock(&runtime->cond_mutex);
      pthread_cond_wait(&runtime->do_render, &runtime->cond_mutex);

      game_info = update_current_state();
      if (game_info.field && y > 24 && x > 46)
        gui_cli_render(windows, &game_info);

      pthread_mutex_unlock(&runtime->cond_mutex);
    }

    del_game_windows(windows);
    endwin();
    pthread_mutex_unlock(&runtime->stdout_mutex);
  }

  atomic_store(&runtime->gui_stop, 1);

  pthread_barrier_wait(&runtime->barrier);

  pthread_exit(0);
}