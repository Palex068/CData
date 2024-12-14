#include "../3d_viewer.h"

void zoom_object_t(object_t *object, double number) {
  if (object && number > EPS) {
    unsigned int index_max = object->count_of_vertexes;
    for (unsigned int index = 0; index < index_max; index++) {
      object->vertexes[index] *= number;
    }
  }
}
