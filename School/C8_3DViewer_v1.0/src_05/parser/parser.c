#include "parser.h"

#include <errno.h>

int parse_vertex(char* line, Figure* figure);
int fill_correct_vertex(Figure* figure, double _x, double _y, double _z);
int parse_polygon(char* line, Figure* figure);
void remove_comment(const char* line);
int has_wrong_pattern(int* prev_pattern, int cur_pattern);
int fill_vertex_p(Figure* figure, int* signal_to_fill, int v);

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

int parse_obj_file(const char* filename, Figure* figure) {
  setlocale(LC_NUMERIC, "C");
  init_figure(figure);
  int error = OK;
  FILE* file = fopen(filename, "r");
  if (!file) error = ERR;
  if (!error) {
    size_t line_size = 0;
    char* line = NULL;
    while (my_getline(&line, &line_size, file) != -1 && !error) {
      remove_comment(line);
      if (strncmp(line, "v ", 2) == 0) {
        error = parse_vertex(line, figure);
      } else if (strncmp(line, "f ", 2) == 0) {
        error = parse_polygon(line, figure);
      }
    }
    if (line) free(line);
    fclose(file);
  }
  return error;
}

/// @brief if a line consists of a comment - removes comment
/// @param line file line as a string
void remove_comment(const char* line) {
  char* comment = strchr(line, '#');
  if (comment) *comment = '\0';
}

/// @brief reads vertexes from line and saves them to figure
/// @param line file line as a string
/// @param figure pointer to structure of type Figure
/// @return error code: 1 = error; 0 = OK
int parse_vertex(char* line, Figure* figure) {
  int error = OK, signal_to_fill = 0, num_token = 0;
  double _x = 0, _y = 0, _z = 0;
  const char* token = NULL;
  token = strtok(line, " ");

  while (token != NULL && signal_to_fill != -1) {
    char* endptr;
    errno = 0;
    double value = strtod(token, &endptr);

    if (endptr != token && errno == 0 &&
        (*endptr == '\0' || *endptr == ' ' || *endptr == '\n')) {
      if (num_token == 1) {
        _x = value;
        ++signal_to_fill;
      } else if (num_token == 2) {
        _y = value;
        ++signal_to_fill;
      } else if (num_token == 3) {
        _z = value;
        ++signal_to_fill;
      } else if (num_token == 4) {
        ;
      } else if (num_token > 0) {
        signal_to_fill = -1;
      }
    } else if (num_token > 0) {
      signal_to_fill = -1;
    }
    ++num_token;
    token = strtok(NULL, " ");
  }

  if (signal_to_fill == 3) {
    fill_correct_vertex(figure, _x, _y, _z);
  }

  return error;
}

/// @brief fills figure with the parsed values
/// @param figure
/// @param _x
/// @param _y
/// @param _z
/// @return error code: 1 = error; 0 = OK
int fill_correct_vertex(Figure* figure, double _x, double _y, double _z) {
  int error = 0;
  error = realloc_vertex(figure);
  if (!error) {
    figure->vertex[(figure->amount_vertex - 1) * 3 + x] = _x;
    figure->vertex[(figure->amount_vertex - 1) * 3 + y] = _y;
    figure->vertex[(figure->amount_vertex - 1) * 3 + z] = _z;

    if (figure->amount_vertex == 1) {
      figure->x_max = figure->x_min = _x;
      figure->y_max = figure->y_min = _y;
      figure->z_max = figure->z_min = _z;
    } else {
      figure->x_max = _x > figure->x_max ? _x : figure->x_max;
      figure->y_max = _y > figure->y_max ? _y : figure->y_max;
      figure->z_max = _z > figure->z_max ? _z : figure->z_max;
      figure->x_min = _x < figure->x_min ? _x : figure->x_min;
      figure->y_min = _y < figure->y_min ? _y : figure->y_min;
      figure->z_min = _z < figure->z_min ? _z : figure->z_min;
    }
  } else {
    error = ERR;
  }
  return error;
}

/// @brief reads polygons from line and saves them to figure.polygon
/// @param line file line as a string
/// @param figure pointer to structure of type Figure
/// @return error code: 1 = error; 0 = OK
int parse_polygon(char* line, Figure* figure) {
  int error = OK, v, signal_to_fill = 0;

  error = realloc_polygon(figure);

  const char* token = NULL;
  token = strtok(line, " ");
  int num_token = 0, prev_pattern = -1, pattern;
  while (token != NULL && *token != '\n' && !error && signal_to_fill != -1) {
    signal_to_fill = 0;
    char* endptr;
    errno = 0;

    if (num_token) {
      v = strtol(token, &endptr, 10);
      pattern = 0;
      if (endptr != token && errno == 0 &&
          (*endptr == '\0' || *endptr == ' ' || *endptr == '\n' ||
           *endptr == '/')) {
        int countdash = 0;
        while (*endptr == '/' && errno == 0 && countdash <= 2) {
          pattern += 1;
          const char* ptr = NULL;
          if (*(endptr + 1) == '/') {
            pattern = 3;
            ptr = endptr + 2;
          } else {
            ptr = endptr + 1;
          }
          strtol(ptr, &endptr, 10);
          ++countdash;
        }
        if (countdash > 2 || errno != 0 ||
            has_wrong_pattern(&prev_pattern, pattern))
          signal_to_fill = -1;
        else {
          signal_to_fill = 1;
        }
      } else {
        signal_to_fill = -1;
      }
      error = fill_vertex_p(figure, &signal_to_fill, v);
    }
    ++num_token;
    token = strtok(NULL, " ");
  }
  if (num_token == 1) realloc_down_polygon(figure);

  return error;
}

/// @brief fills polygon line in a format:
/// point_1 point_2 point_2 point_3 point_3 point_1
/// @param figure
/// @param signal_to_fill
/// @param v current parsed vertex
/// @return error code: 1 = error; 0 = OK
int fill_vertex_p(Figure* figure, int* signal_to_fill, int v) {
  int error = OK;
  if (v < 1) *signal_to_fill = -1;
  if (*signal_to_fill == 1) {
    error = realloc_vertex_p(&figure->polygon[figure->amount_polygon - 1]);
    if (!error) {
      if (figure->polygon[figure->amount_polygon - 1].amount_p - 1 != 0) {
        figure->polygon[figure->amount_polygon - 1]
            .vertex_p[figure->polygon[figure->amount_polygon - 1].amount_p -
                      2] = v - 1;
      }
      figure->polygon[figure->amount_polygon - 1]
          .vertex_p[figure->polygon[figure->amount_polygon - 1].amount_p - 1] =
          v - 1;
      error = realloc_vertex_p(&figure->polygon[figure->amount_polygon - 1]);
      if (!error) {
        figure->polygon[figure->amount_polygon - 1]
            .vertex_p[figure->polygon[figure->amount_polygon - 1].amount_p -
                      1] =
            figure->polygon[figure->amount_polygon - 1].vertex_p[0];
        figure->amount_polygon_edges += 1;
      }
    } else
      error = ERR;
  } else if (*signal_to_fill == -1) {
    if (figure->polygon[figure->amount_polygon - 1].vertex_p)
      free(figure->polygon[figure->amount_polygon - 1].vertex_p);
    error = realloc_down_polygon(figure);
  }
  return error;
}

/// @brief checks if a current pattern is the same as general line pattern
/// @param num_token number of processed token
/// @param pattern polygon line pattern
/// @param current_pattern pattern of a current token
/// @param signal_to_fill
int has_wrong_pattern(int* prev_pattern, int cur_pattern) {
  int is_pattern_wrong = 0;
  if (*prev_pattern != -1 && *prev_pattern != cur_pattern) {
    is_pattern_wrong = 1;
  } else {
    *prev_pattern = cur_pattern;
  }
  return is_pattern_wrong;
}
