#include "../3d_viewer.h"

void centralize_object_t(object_t *object) {
  double centerX =
      object->positions[xAxisMIN] +
      (object->positions[xAxisMAX] - object->positions[xAxisMIN]) / 2;
  double centerY =
      object->positions[yAxisMIN] +
      (object->positions[yAxisMAX] - object->positions[yAxisMIN]) / 2;
  double centerZ =
      object->positions[zAxisMIN] +
      (object->positions[zAxisMAX] - object->positions[zAxisMIN]) / 2;
  for (unsigned int index = 0; index < object->count_of_vertexes; index += 3) {
    object->vertexes[index] -= centerX;
    object->vertexes[index + 1] -= centerY;
    object->vertexes[index + 2] -= centerZ;
  }
}
