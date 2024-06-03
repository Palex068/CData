#include "controller.h"

#include <errno.h>
#include <pthread.h>
#include <stddef.h>
#include <unistd.h>

#include "common/common.h"

int main() {
  int code = 0;
  runtime_t runtime = {0};

  // Model
  extern void* tetris_loop(runtime_t*);
  void* (*model_loop)(void*) = (void* (*)(void*))tetris_loop;

  // GUI
  extern void* gui_cli_loop(runtime_t*);
  void* (*gui_loop)(void*) = (void* (*)(void*))gui_cli_loop;

  // Controller
  void* (*input_controller)(void*) = (void* (*)(void*))controller_loop;

  code = controller_init(&runtime);

  if (!code)
    code = pthread_create(&runtime.model, &runtime.model_attr, model_loop,
                          (void*)&runtime);
  if (!code)
    code = pthread_create(&runtime.gui, &runtime.gui_attr, gui_loop,
                          (void*)&runtime);
  if (!code)
    code = pthread_create(&runtime.controller, &runtime.controller_attr,
                          input_controller, (void*)&runtime);

  if (!code) {
    signals_block();
    while (!atomic_load(&runtime.model_stop) &&
           !atomic_load(&runtime.gui_stop) &&
           !atomic_load(&runtime.controller_stop))
      // thread_wait(500); // грузит процессор (
      sleep(1);
    atomic_store(&runtime.game_stop, 1);
  }

  // Ожидание выхода всех дочерних потоков
  pthread_join(runtime.gui, (void*)&code);
  pthread_join(runtime.controller, (void*)&code);
  pthread_join(runtime.model, (void*)&code);

  // Деструктор
  controller_destroy(&runtime);

  return code;
}
