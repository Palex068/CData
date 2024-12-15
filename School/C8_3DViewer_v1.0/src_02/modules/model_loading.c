#include "model_loading.h"
#include <errno.h>

int parse_obj_file(char *filename, obj_data *data) {
  if (filename == NULL || data == NULL) {
    return ERROR;
  }

  int parse_status = OK;
  FILE *file = fopen(filename, "r");
  if (file) {
    count_vertices_and_indices(file, data);
    parse_status = memory_allocation(data);
    if (parse_status != ERROR) {
      fseek(file, 0, SEEK_SET);
      parse_status = parse_vertices_and_indices(file, data);
    }
    fclose(file);
  } else {
    parse_status = ERROR;
  }

  return parse_status;
}

int memory_allocation(obj_data *data) {
  int allocate_status = OK;

  if (data->vertices_count) {
    // x, y, z vertex without [w] => multiply by 3
    data->vertices_arr = calloc(data->vertices_count * 3, sizeof(double));
  }
  if (data->vertex_indices_count) {
    // multiply by two because we will build lines that we will loop
    data->vertex_indices_arr =
        calloc(data->vertex_indices_count * 2, sizeof(int));
  }
  if (data->vertices_arr == NULL || data->vertex_indices_arr == NULL) {
    allocate_status = ERROR;
  }

  return allocate_status;
}

int my_getline(char **restrict line, size_t *restrict len, FILE *restrict fp) {
    // Check if either line, len or fp are NULL pointers
    if(line == NULL || len == NULL || fp == NULL) {
        errno = EINVAL;
        return -1;
    }
    // Use a chunk array of 128 bytes as parameter for fgets
    char chunk[128];

             // Allocate a block of memory for *line if it is NULL or smaller than the chunk array
             if(*line == NULL || *len < sizeof(chunk)) {
                 *len = sizeof(chunk);
                 if((*line = malloc(*len)) == NULL) {
                         errno = ENOMEM;
                         return -1;
                     }
             }

             // "Empty" the string
             (*line)[0] = '\0';

             while(fgets(chunk, sizeof(chunk), fp) != NULL) {
                 // Resize the line buffer if necessary
                     size_t len_used = strlen(*line);
                 size_t chunk_used = strlen(chunk);

                    if(*len - len_used < chunk_used) {
                        // Check for overflow
                             if(*len > SIZE_MAX / 2) {
                                 errno = EOVERFLOW;
                                 return -1;
                             } else {
                                 *len *= 2;
                             }

                             if((*line = realloc(*line, *len)) == NULL) {
                                 errno = ENOMEM;
                                 return -1;
                             }
                     }

                     // Copy the chunk to the end of the line buffer
                     memcpy(*line + len_used, chunk, chunk_used);
                 len_used += chunk_used;
                 (*line)[len_used] = '\0';

                     // Check if *line contains '\n', if yes, return the *line length
                     if((*line)[len_used - 1] == '\n') {
                         return len_used;
                     }
             }

             return -1;
     }

void count_vertices_and_indices(FILE *file, obj_data *data) {
  char *line = NULL;
  size_t len = 0;

  while (my_getline(&line, &len, file) != EOF) {
    if (strncmp(line, "v ", 2) == 0) {
      data->vertices_count++;
    } else if (strncmp(line, "f ", 2) == 0) {
      char *vertex_index = strtok(line + 2, " ");
      while (vertex_index != NULL) {
        if (atoi(vertex_index)) {
          data->vertex_indices_count++;
        }
        vertex_index = strtok(NULL, " ");
      }
    }
  }

  if (line) {
    free(line);
    line = NULL;
  }
}

void data_destructor(obj_data *data) {
  if (data != NULL) {
    if (data->vertices_arr != NULL) {
      free(data->vertices_arr);
      data->vertices_arr = NULL;
    }
    if (data->vertex_indices_arr != NULL) {
      free(data->vertex_indices_arr);
      data->vertex_indices_arr = NULL;
    }
  }
}

int parse_vertices_and_indices(FILE *file, obj_data *data) {
  int parse_status = OK;
  char *line = NULL;
  size_t len = 0;
  size_t i = 0;
  size_t vertex_counter = 0;
  size_t vertex_indices_counter = 0;

  while (my_getline(&line, &len, file) != EOF) {
    if (strncmp(line, "v ", 2) == 0) {
      vertex_counter++;
      double x, y, z;
      sscanf(line, "v %lf %lf %lf", &x, &y, &z);
      data->vertices_arr[i++] = x;
      data->vertices_arr[i++] = y;
      data->vertices_arr[i++] = z;
    } else if (strncmp(line, "f ", 2) == 0) {
      int first_index = 0;
      bool is_first_index = false;
      char *vertex_index = strtok(line + 2, " ");
      while (vertex_index != NULL) {
        int index_val = atoi(vertex_index);
        if (index_val) {
          // If an index is negative then it relatively refers to the end
          // of the vertex list. For example -1 referring to the last element.
          if (index_val < 0) {
            index_val += vertex_counter + 1;
          }
          data->vertex_indices_arr[vertex_indices_counter] = index_val - 1;
          if (!is_first_index) {
            first_index = index_val - 1;
            is_first_index = true;
          } else {
            data->vertex_indices_arr[++vertex_indices_counter] = index_val - 1;
          }
          vertex_indices_counter++;
        }
        vertex_index = strtok(NULL, " ");
      }
      // loop lines
      data->vertex_indices_arr[vertex_indices_counter] = first_index;
      vertex_indices_counter++;
    }
  }
  if (line) {
    free(line);
    line = NULL;
  }

  if (!data->vertices_arr[data->vertices_count * 3 - 1] ||
      !data->vertex_indices_arr[data->vertex_indices_count * 2 - 1]) {
    parse_status = ERROR;
  }

  return parse_status;
}

void print_data(obj_data *data) {
  // printing vertices
  printf("Amount of vertex: %ld\n", data->vertices_count);
  for (int i = 0; i < (int)data->vertices_count * 3; i++) {
    printf("%lf ", data->vertices_arr[i]);
    if ((i + 1) % 3 == 0) {
      printf("\n");
    }
  }
  printf("\n");
  // printing vertex_indices
  printf("Amount of vertex_indices: %ld\n", data->vertex_indices_count);
  for (int i = 0; i < (int)data->vertex_indices_count * 2; i++) {
    printf("%d ", data->vertex_indices_arr[i]);
    if ((i + 1) % 6 == 0) {
      printf("\n");
    }
  }
}
