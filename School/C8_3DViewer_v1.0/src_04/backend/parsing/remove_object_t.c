#include "../3d_viewer.h"

void remove_object_t(object_t *data_object) {
  if (data_object) {
    if (data_object->edges != NULL) {
      free(data_object->edges);
      data_object->edges = NULL;
    }
    if (data_object->vertexes != NULL) {
      free(data_object->vertexes);
      data_object->vertexes = NULL;
    }
    data_object->count_of_edges = 0;
    data_object->count_of_vertexes = 0;
  }
}
