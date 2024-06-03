#include <errno.h>
#include <sys/ioctl.h>
#include <unistd.h>

#include "gui_cli.h"

int term_size(int *y, int *x) {
  if (!y || !x) return EINVAL;

  int code = 0;

  struct winsize ws = {0};
  code = ioctl(STDIN_FILENO, TIOCGWINSZ, &ws);

  if (!code)
    *y = ws.ws_row, *x = ws.ws_col;
  else
    code = errno;

  return code;
}