#include <errno.h>
#include <stddef.h>
#include <string.h>

#include "common/useraction_t.h"

int get_action(UserAction_t *action, char *array) {
  int code = 0;
  UserAction_t result = {0};

  code = (action == NULL || array == NULL) * EINVAL;

  if (!code) {
    if (strcmp(array, "\033[A") == 0)
      result = Up;
    else if (strcmp(array, "\033[B") == 0)
      result = Down;
    else if (strcmp(array, "\033[C") == 0)
      result = Right;
    else if (strcmp(array, "\033[D") == 0)
      result = Left;
    else if (array[0] == ' ')
      result = Action;
    else if (array[0] == 's')
      result = Start;
    else if (array[0] == 'p')
      result = Pause;
    else if (array[0] == 'q')
      result = Terminate;

    *action = result;
  }

  return code;
}
