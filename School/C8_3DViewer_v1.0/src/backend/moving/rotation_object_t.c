#include "../3d_viewer.h"

void rotation_object_t(object_t *object, double angle, int axis) {
  if (object) {
    unsigned int index_max = object->count_of_vertexes;
    if (axis == xAxis) {
      for (unsigned int index = 0; index < index_max; index += 3) {
        double temp_y = object->vertexes[index + yAxis];
        double temp_z = object->vertexes[index + zAxis];
        object->vertexes[index + yAxis] =
            cos(angle) * temp_y - sin(angle) * temp_z;
        object->vertexes[index + zAxis] =
            sin(angle) * temp_y + cos(angle) * temp_z;
      }
    } else if (axis == yAxis) {
      for (unsigned int index = 0; index < index_max; index += 3) {
        double temp_x = object->vertexes[index + xAxis];
        double temp_z = object->vertexes[index + zAxis];
        object->vertexes[index + xAxis] =
            cos(angle) * temp_x + sin(angle) * temp_z;
        object->vertexes[index + zAxis] =
            -sin(angle) * temp_x + cos(angle) * temp_z;
      }
    } else if (axis == zAxis) {
      for (unsigned int index = 0; index < index_max; index += 3) {
        double temp_x = object->vertexes[index + xAxis];
        double temp_y = object->vertexes[index + yAxis];
        object->vertexes[index + xAxis] =
            cos(angle) * temp_x - sin(angle) * temp_y;
        object->vertexes[index + yAxis] =
            sin(angle) * temp_x + cos(angle) * temp_y;
      }
    }
  }
}
