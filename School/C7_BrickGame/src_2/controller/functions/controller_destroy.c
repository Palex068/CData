#include <errno.h>
#include <pthread.h>
#include <stddef.h>

#include "controller.h"

int controller_destroy(runtime_t *runtime) {
  int code = 0;

  code = (runtime == NULL) * EFAULT;

  if (!code) {
    // Грубо, можно подождать и т.п.
    if (runtime->gui) code = pthread_cancel(runtime->gui);
    if (runtime->model) code = pthread_cancel(runtime->model);
    if (runtime->controller) code = pthread_cancel(runtime->controller);
    pthread_attr_destroy(&runtime->model_attr);
    pthread_attr_destroy(&runtime->gui_attr);
    pthread_attr_destroy(&runtime->controller_attr);
    pthread_condattr_destroy(&runtime->do_render_attr);
    pthread_cond_destroy(&runtime->do_render);
    pthread_condattr_destroy(&runtime->do_input_attr);
    pthread_cond_destroy(&runtime->do_input);
    pthread_mutexattr_destroy(&runtime->stdin_mutex_attr);
    pthread_mutex_destroy(&runtime->stdin_mutex);
    pthread_mutexattr_destroy(&runtime->stdout_mutex_attr);
    pthread_mutex_destroy(&runtime->stdout_mutex);
    pthread_mutexattr_destroy(&runtime->cond_mutex_attr);
    pthread_mutex_destroy(&runtime->cond_mutex);
    pthread_barrierattr_destroy(&runtime->barrier_attr);
    pthread_barrier_destroy(&runtime->barrier);
  }

  return code;
}