#include "../3d_viewer.h"

void moving_object_t(object_t *object, double number, int axis) {
  if (object && axis > -1 && axis < 3) {
    unsigned int index_max = object->count_of_vertexes;
    for (unsigned int index = axis; index < index_max; index += 3) {
      object->vertexes[index] += number;
    }
  }
}
