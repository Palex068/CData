#include <errno.h>
#include <pthread.h>
#include <stddef.h>
#include <sys/time.h>

int thread_wait(int msec) {
  int code = 0;
  pthread_mutex_t mutex;
  pthread_cond_t condition;
  struct timespec how_much = {0};

  code = (msec < 1) * EINVAL;

  if (!code) code = pthread_mutex_init(&mutex, NULL);
  if (!code) code = pthread_cond_init(&condition, NULL);
  if (!code) code = !timespec_get(&how_much, TIME_UTC);

  if (!code) {
    long sec = msec / 1000;
    msec -= sec * 1000;
    long nsec = msec * 1000000;
    how_much.tv_sec += sec;
    how_much.tv_nsec += nsec;
  }
  // Сон в ожидании
  if (!code) code = pthread_cond_timedwait(&condition, &mutex, &how_much);

  if (!code || code == ETIMEDOUT) code = pthread_mutex_destroy(&mutex);
  if (!code || code == ETIMEDOUT) code = pthread_cond_destroy(&condition);

  return code;
}