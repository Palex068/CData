#ifndef RUNTIME_T
#define RUNTIME_T

#include <pthread.h>
#include <stdatomic.h>
#include <stdbool.h>

#include "pthread_barrier.h"

/**
 * @brief Структура разделяемой между потоками памяти
 */
typedef struct {
  // TIDs
  pthread_t model;
  pthread_t gui;
  pthread_t controller;
  // Threads attributes
  pthread_attr_t model_attr;
  pthread_attr_t gui_attr;
  pthread_attr_t controller_attr;
  // Conditional variable
  pthread_cond_t do_render;
  pthread_cond_t do_input;
  // Cond. attributes
  pthread_condattr_t do_render_attr;
  pthread_condattr_t do_input_attr;
  // Mutexes
  pthread_mutex_t stdin_mutex;
  pthread_mutex_t stdout_mutex;
  pthread_mutex_t cond_mutex;
  // Mutexes attributes
  pthread_mutexattr_t stdin_mutex_attr;
  pthread_mutexattr_t stdout_mutex_attr;
  pthread_mutexattr_t cond_mutex_attr;
  // Barriers
  pthread_barrier_t barrier;
  pthread_barrierattr_t barrier_attr;
  // Flags
  atomic_bool game_stop;
  atomic_bool model_stop;
  atomic_bool gui_stop;
  atomic_bool controller_stop;
  // Message boxes
  atomic_int msg_to_model;
  atomic_int msg_to_gui;
  atomic_int msg_to_controller;

} runtime_t;

#endif