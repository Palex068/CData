#include <errno.h>
#include <poll.h>
#include <pthread.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

#include "common/common.h"
#include "controller.h"

void* controller_loop(runtime_t* runtime) {
  int code = 0;

  code = (runtime == NULL) * EFAULT;

  // if (!code) {
  //   pthread_t self_tid = pthread_self();
  //   code = pthread_detach(self_tid);
  // }

  if (!code) code = canonical_mode(1);

  if (!code) {
    signals_block();
    char key[4] = {0};
    int len = 0;
    UserAction_t action = 0;
    int poll_code = 0;
    struct pollfd event = {0};
    event.events = POLLIN;
    event.fd = STDIN_FILENO;

    // Основной цикл
    pthread_mutex_lock(&runtime->stdin_mutex);
    while (!code && !atomic_load(&runtime->game_stop)) {
      poll_code = poll(&event, 1, 1);
      if (poll_code > 0 && event.revents & POLLIN) {
        event.revents = 0;
        len = read(STDIN_FILENO, key, 4);
        key[len] = 0;
        code = get_action(&action, key);
        if (!code && action) atomic_store(&runtime->msg_to_model, (int)action);
      }
    }
    pthread_mutex_unlock(&runtime->stdin_mutex);
  }

  pthread_barrier_wait(&runtime->barrier);
  canonical_mode(0);

  pthread_exit(0);
}
