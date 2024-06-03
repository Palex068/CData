// TODO: Инициализация и запуск основного цикла
#include <errno.h>
#include <malloc.h>
#include <pthread.h>
#include <stddef.h>
#include <time.h>

#include "common/common.h"
#include "common/runtime_t.h"
#include "tetris.h"

/**
 * @ingroup Thread_functions Потоковые функции
 * @brief Основная функция потока машины конечных автоматов
 * @param[in] *runtime Указатель на структуру разделяемой памяти
 * @return Код ошибки: Согласно errno
 */
void *tetris_loop(runtime_t *runtime) {
  if (!runtime) return (void *)EFAULT;

  int code = 0;
  game_t *game = NULL;

  code = signals_block();

  if (!code) code = game_init(&game);

  if (!code) {
    logo_start(game->game_info->field);
    thread_wait(10);
    pthread_cond_signal(&runtime->do_render);
    UserAction_t act = None;
    unsigned long now = 0;

    while (!atomic_load(&runtime->game_stop)) {
      // Цикл не грузит процессор
      thread_wait(100);

      // Проверяем, не завершает ли модель игру
      if (game->state == none) {
        atomic_store(&runtime->model_stop, 1);
        pthread_cond_signal(&runtime->do_render);
      }

      // Вызов функции shift_fn по таймеру
      now = time_msec();
      if (game->state == moving &&
          now - game->last_op >= (unsigned long)game->game_info->speed) {
        shift_fn(game);
      }

      // Обработка пользовательского ввода
      if (game->state &&
          (act = (UserAction_t)atomic_load(&runtime->msg_to_model)) > 0) {
        userInput(act, 0);
        atomic_store(&runtime->msg_to_model, 0);
      }

      if (game->modified) {
        game->modified = false;
        pthread_cond_signal(&runtime->do_render);
      }
    }
  }

  // Destroy the game
  if (game) game_destroy(game);

  if (!code) atomic_store(&runtime->model_stop, 1);

  if (!code) pthread_barrier_wait(&runtime->barrier);

  pthread_exit(0);
}