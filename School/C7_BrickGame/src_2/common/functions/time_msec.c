#include <time.h>

unsigned long time_msec() {
  unsigned long result = 0;

  struct timespec now = {0};
  if (timespec_get(&now, TIME_UTC) != 0)
    result = (unsigned long)now.tv_sec * 1000 + now.tv_nsec / 1000000;
  return result;
}