#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <termios.h>

/* Переключение канонического режима
1: включить 0: выключить */
int canonical_mode(int mode) {
  int code = 0;
  struct termios t;
  code = (mode != 0 && mode != 1) * EINVAL;

  if (!code) code = tcgetattr(0, &t);

  if (!code) {
    if (mode == 1)
      t.c_lflag &= (int16_t) ~(ISIG | ICANON | ECHO);
    else
      t.c_lflag |= (int16_t)(ISIG | ICANON | ECHO);
    // t.c_cc[VMIN] = 1;
    // t.c_cc[VTIME] = 0;
    code = tcsetattr(0, TCSANOW, &t);
  }
  return code;
}
