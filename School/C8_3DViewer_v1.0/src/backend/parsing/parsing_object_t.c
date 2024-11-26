#include "../3d_viewer.h"

// 0 is ok
int parsing_object_t(object_t *data_object, char *file_name) {
  int res = 1;
  if (data_object) {
    if (!init_object_t(data_object)) {
      FILE *input_stream = NULL;
      input_stream = fopen(file_name, "r");
      if (input_stream) {
        char current_line[10000] = {0};
        res = 0;
        unsigned int countVertexesInMalloc = 9, countEdgesInMalloc = 6;
        while (!res && fgets(current_line, 10000, input_stream) != NULL) {
          if (!memcmp(current_line, "v ", 2)) {
            res = parsing_vertexes(data_object, current_line,
                                   data_object->count_of_vertexes,
                                   &countVertexesInMalloc);
          } else if (!memcmp(current_line, "f ", 2)) {
            res = parsing_edges(data_object, current_line,
                                &countEdgesInMalloc) < 6;
          }
        }
        fclose(input_stream);
      }
      if (res) {
        remove_object_t(data_object);
      }
    }
  }
  return res;
}
