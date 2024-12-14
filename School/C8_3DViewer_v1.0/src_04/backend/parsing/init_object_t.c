#include "../3d_viewer.h"

int init_object_t(object_t *data_object) {
  int res = 1;
  if (data_object != NULL) {
    data_object->edges = NULL;
    data_object->vertexes = NULL;
    data_object->count_of_edges = 0;
    data_object->count_of_vertexes = 0;
    data_object->edges = (unsigned int *)calloc(6, sizeof(unsigned int));
    if (data_object->edges) {
      data_object->vertexes = (double *)calloc(9, sizeof(double));
      if (!data_object->vertexes) {
        free(data_object->edges);
      } else {
        res = 0;
      }
    }
    data_object->positions[xAxisMIN] = data_object->positions[yAxisMIN] =
        data_object->positions[zAxisMIN] = __DBL_MAX__;
    data_object->positions[xAxisMAX] = data_object->positions[yAxisMAX] =
        data_object->positions[zAxisMAX] = -__DBL_MAX__;
  }
  return res;
}
