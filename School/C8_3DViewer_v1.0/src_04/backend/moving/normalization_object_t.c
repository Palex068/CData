#include "../3d_viewer.h"

double normalization_object_t(object_t *object) {
  double getX = object->positions[xAxisMAX] - object->positions[xAxisMIN];
  double getY = object->positions[yAxisMAX] - object->positions[yAxisMIN];
  double getZ = object->positions[zAxisMAX] - object->positions[zAxisMIN];
  double dmax = fmax(fmax(getX, getY), getZ);
  double scal = (0.5 - (0.5 * (-1))) / dmax;
  return scal;
}
