#include "../3d_viewer.h"

// 0 is ok
int parsing_vertexes(object_t *data_object, char *input_line,
                     unsigned int current_vertex,
                     unsigned int *countVertexesInMalloc) {
  int res = 0;
  if (3 + current_vertex > *countVertexesInMalloc) {
    double *tmp = NULL;
    *countVertexesInMalloc *= 1.5;
    tmp = (double *)malloc(*countVertexesInMalloc * sizeof(double));
    if (tmp) {
      for (unsigned int i = 0; i < current_vertex; i++) {
        tmp[i] = data_object->vertexes[i];
      }
      free(data_object->vertexes);
      data_object->vertexes = NULL;
      data_object->vertexes = tmp;
    } else {
      res = 2;
    }
  }
  if (!res) {
    res = 1;
    data_object->count_of_vertexes += 3;
    double xAxis_val = 0.0, yAxis_val = 0.0, zAxis_val = 0.0;
    if (sscanf(input_line, __format_vertexes, &xAxis_val, &yAxis_val,
               &zAxis_val) == 3) {
      data_object->vertexes[current_vertex + xAxis] = xAxis_val;
      data_object->vertexes[current_vertex + yAxis] = yAxis_val;
      data_object->vertexes[current_vertex + zAxis] = zAxis_val;
      res = 0;
      if (data_object->positions[xAxisMIN] > xAxis_val) {
        data_object->positions[xAxisMIN] = xAxis_val;
      }
      if (data_object->positions[yAxisMIN] > yAxis_val) {
        data_object->positions[yAxisMIN] = yAxis_val;
      }
      if (data_object->positions[zAxisMIN] > zAxis_val) {
        data_object->positions[zAxisMIN] = zAxis_val;
      }
      if (data_object->positions[xAxisMAX] < xAxis_val) {
        data_object->positions[xAxisMAX] = xAxis_val;
      }
      if (data_object->positions[yAxisMAX] < yAxis_val) {
        data_object->positions[yAxisMAX] = yAxis_val;
      }
      if (data_object->positions[zAxisMAX] < zAxis_val) {
        data_object->positions[zAxisMAX] = zAxis_val;
      }
    }
  }
  return res;
}
