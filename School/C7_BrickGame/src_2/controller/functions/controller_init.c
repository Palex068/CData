#include <errno.h>
#include <pthread.h>
#include <stddef.h>

#include "controller.h"

int controller_init(runtime_t *data) {
  int code = 0;

  code = (data == NULL) * EFAULT;

  if (!code) code = pthread_attr_init(&data->model_attr);
  if (!code) code = pthread_attr_init(&data->gui_attr);
  if (!code) code = pthread_attr_init(&data->controller_attr);

  if (!code) code = pthread_condattr_init(&data->do_input_attr);
  if (!code) code = pthread_cond_init(&data->do_input, &data->do_input_attr);

  if (!code) code = pthread_condattr_init(&data->do_render_attr);
  if (!code) code = pthread_cond_init(&data->do_render, &data->do_render_attr);

  if (!code) code = pthread_mutexattr_init(&data->stdin_mutex_attr);
  if (!code)
    code = pthread_mutex_init(&data->stdin_mutex, &data->stdin_mutex_attr);
  if (!code) code = pthread_mutexattr_init(&data->stdout_mutex_attr);
  if (!code)
    code = pthread_mutex_init(&data->stdout_mutex, &data->stdout_mutex_attr);
  if (!code) code = pthread_mutexattr_init(&data->cond_mutex_attr);
  if (!code)
    code = pthread_mutex_init(&data->cond_mutex, &data->cond_mutex_attr);

  if (!code) code = pthread_barrierattr_init(&data->barrier_attr);
  if (!code)
    code = pthread_barrier_init(&data->barrier, &data->barrier_attr, 3);

  ATOMIC_VAR_INIT(data->game_stop);
  ATOMIC_VAR_INIT(data->model_stop);
  ATOMIC_VAR_INIT(data->gui_stop);

  return code;
}