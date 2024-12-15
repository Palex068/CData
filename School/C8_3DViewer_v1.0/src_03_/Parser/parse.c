#include "parse.h"

void s21_parse_v_line(char *line, double **vertices, int *number_of_vertices) {
  double x, y, z;

  int matches = sscanf(line, "%lf %lf %lf", &x, &y, &z);

  if (matches == 3) {
    (*number_of_vertices)++;

    if (*number_of_vertices == 1) {
      *vertices = (double *)malloc(*number_of_vertices * 3 * sizeof(double));
    } else {
      *vertices = (double *)realloc(*vertices,
                                    *number_of_vertices * 3 * sizeof(double));
    }
    (*vertices)[(*number_of_vertices - 1) * 3] = x;
    (*vertices)[(*number_of_vertices - 1) * 3 + 1] = y;
    (*vertices)[(*number_of_vertices - 1) * 3 + 2] = z;
  }
}

void s21_parse_file(char *file_name, int **facets, int *number_of_lines,
                    int *facets_length, int *number_of_vertices,
                    double **vertices) {
  FILE *file;
  file = fopen(file_name, "r");

  char *line = (char *)calloc(1, sizeof(char));
  int len;
  *number_of_lines = 0;
  *facets_length = 0;
  *number_of_vertices = 0;

  while (1) {
    char c = fgetc(file);

    if ((c == '\n') || (c == EOF)) {
      if (*line == 'f') {
        s21_parse_f_line(line + 1, facets, number_of_lines, facets_length,
                         *number_of_vertices);
      } else if (*line == 'v') {
        s21_parse_v_line(line + 1, vertices, number_of_vertices);
      }

      free(line);

      if (c == '\n') {
        line = (char *)calloc(1, sizeof(char));
      } else {
        break;
      }
    } else {
      len = strlen(line);
      line = (char *)realloc(line, (len + 2) * sizeof(char));
      *(line + len) = c;
      *(line + len + 1) = '\0';
    }
  }

  fclose(file);
}

void s21_parse_f_line(char *line, int **facets, int *number_of_lines,
                      int *facets_length, int number_of_vertices) {
  int vertices_per_facet = 0;
  int *vertices_ids = (int *)malloc(sizeof(int));

  s21_scan_f_line(line, &vertices_per_facet, &vertices_ids);

  for (int i = 0; i < vertices_per_facet; i++) {
    if (vertices_ids[i] < 1) {
      vertices_ids[i] = number_of_vertices + vertices_ids[i] + 1;
    }

    if (vertices_ids[i] > number_of_vertices) {
      vertices_per_facet = 0;
    }
  }

  if (vertices_per_facet > 0) {
    if (*number_of_lines == 0) {
      *facets = (int *)malloc((*facets_length + 2 * vertices_per_facet) *
                              sizeof(int));
    } else {
      *facets = realloc(
          *facets, (*facets_length + 2 * vertices_per_facet) * sizeof(int));
    }

    (*number_of_lines)++;

    for (int i = 0; i < vertices_per_facet; i++) {
      (*facets)[*facets_length] = vertices_ids[i] - 1;
      (*facets_length)++;
      if (i > 0) {
        (*facets)[*facets_length] = vertices_ids[i] - 1;
        (*facets_length)++;
      }
    }
    (*facets)[*facets_length] = vertices_ids[0] - 1;
    (*facets_length)++;
  }

  free(vertices_ids);
}

void s21_scan_f_line(char *line, int *vertices_per_facet, int **vertices_ids) {
  int v_1, v_2, v_3;
  int matches;
  int len;
  int found;

  while (1) {
    while (*line == ' ') {
      line++;
    }

    found = 0;

    matches = sscanf(line, "%d/%d/%d", &v_1, &v_2, &v_3);
    if (matches == 3) {
      len = snprintf(NULL, 0, "%d/%d/%d", v_1, v_2, v_3);
      (*vertices_per_facet)++;
      *vertices_ids =
          (int *)realloc(*vertices_ids, *vertices_per_facet * sizeof(int));
      (*vertices_ids)[*vertices_per_facet - 1] = v_1;
      line += len;
      found = 1;
      continue;
    }

    matches = sscanf(line, "%d//%d", &v_1, &v_2);
    if (matches == 2) {
      len = snprintf(NULL, 0, "%d//%d", v_1, v_2);

      (*vertices_per_facet)++;
      *vertices_ids =
          (int *)realloc(*vertices_ids, *vertices_per_facet * sizeof(int));
      (*vertices_ids)[*vertices_per_facet - 1] = v_1;
      line += len;
      found = 1;
      continue;
    }

    matches = sscanf(line, "%d/%d", &v_1, &v_2);
    if (matches == 2) {
      len = snprintf(NULL, 0, "%d/%d", v_1, v_2);
      (*vertices_per_facet)++;
      *vertices_ids =
          (int *)realloc(*vertices_ids, *vertices_per_facet * sizeof(int));
      (*vertices_ids)[*vertices_per_facet - 1] = v_1;
      line += len;
      found = 1;
      continue;
    }

    matches = sscanf(line, "%d", &v_1);
    if (matches == 1) {
      len = snprintf(NULL, 0, "%d", v_1);
      (*vertices_per_facet)++;
      *vertices_ids =
          (int *)realloc(*vertices_ids, *vertices_per_facet * sizeof(int));
      (*vertices_ids)[*vertices_per_facet - 1] = v_1;
      line += len;
      found = 1;
      continue;
    }

    if (found == 0) {
      break;
    }
  }
}

void s21_center_vertices(double **vertices, int number_of_vertices) {
  double x_min, x_max, y_min, y_max, z_min, z_max;

  s21_find_max_min_values(vertices, number_of_vertices, &x_min, &x_max, &y_min,
                          &y_max, &z_min, &z_max);

  for (int i = 0; i < number_of_vertices; i++) {
    (*vertices)[i * 3] = (*vertices)[i * 3] - x_min / 2 - x_max / 2;
    (*vertices)[i * 3 + 1] = (*vertices)[i * 3 + 1] - y_min / 2 - y_max / 2;
    (*vertices)[i * 3 + 2] = (*vertices)[i * 3 + 2] - z_min / 2 - z_max / 2;
  }
}

void s21_rotate(double **vertices, int number_of_vertices, double degrees,
                int ax) {
  degrees = degrees * M_PI / 180;

  if (ax == 0) {
    for (int i = 0; i < number_of_vertices; i++) {
      double y = (*vertices)[i * 3 + 1];
      double z = (*vertices)[i * 3 + 2];

      (*vertices)[i * 3 + 1] = y * cos(degrees) - z * sin(degrees);
      (*vertices)[i * 3 + 2] = y * sin(degrees) + z * cos(degrees);
    }
  } else if (ax == 1) {
    for (int i = 0; i < number_of_vertices; i++) {
      double x = (*vertices)[i * 3];
      double z = (*vertices)[i * 3 + 2];

      (*vertices)[i * 3] = x * cos(degrees) + z * sin(degrees);
      (*vertices)[i * 3 + 2] = -x * sin(degrees) + z * cos(degrees);
    }
  } else {
    for (int i = 0; i < number_of_vertices; i++) {
      double x = (*vertices)[i * 3];
      double y = (*vertices)[i * 3 + 1];

      (*vertices)[i * 3] = x * cos(degrees) - y * sin(degrees);
      (*vertices)[i * 3 + 1] = x * sin(degrees) + y * cos(degrees);
    }
  }
}

void s21_scale(double **vertices, int number_of_vertices, double scale) {
  for (int i = 0; i < number_of_vertices; i++) {
    (*vertices)[i * 3] = (*vertices)[i * 3] * scale;
    (*vertices)[i * 3 + 1] = (*vertices)[i * 3 + 1] * scale;
    (*vertices)[i * 3 + 2] = (*vertices)[i * 3 + 2] * scale;
  }
}

void s21_shift(double **vertices, int number_of_vertices, double x, double y,
               double z) {
  for (int i = 0; i < number_of_vertices; i++) {
    (*vertices)[i * 3] = (*vertices)[i * 3] + x;
    (*vertices)[i * 3 + 1] = (*vertices)[i * 3 + 1] + y;
    (*vertices)[i * 3 + 2] = (*vertices)[i * 3 + 2] + z;
  }
}

void s21_initial_scale(double **vertices, int number_of_vertices) {
  double x_min, x_max, y_min, y_max, z_min, z_max;
  double max;

  s21_find_max_min_values(vertices, number_of_vertices, &x_min, &x_max, &y_min,
                          &y_max, &z_min, &z_max);

  max = x_max - x_min;
  if (y_max - y_min > max) {
    max = y_max - y_min;
  }
  if (z_max - z_min > max) {
    max = z_max - z_min;
  }

  double scale_number = 1.4 / max;

  s21_scale(vertices, number_of_vertices, scale_number);
}

void s21_find_max_min_values(double **vertices, int number_of_vertices,
                             double *x_min, double *x_max, double *y_min,
                             double *y_max, double *z_min, double *z_max) {
  for (int i = 0; i < number_of_vertices; i++) {
    if (i == 0) {
      *x_min = (*vertices)[0];
      *x_max = *x_min;
      *y_min = (*vertices)[1];
      *y_max = *y_min;
      *z_min = (*vertices)[2];
      *z_max = *z_min;
    } else {
      if ((*vertices)[i * 3] > *x_max) {
        *x_max = (*vertices)[i * 3];
      } else if ((*vertices)[i * 3] < *x_min) {
        *x_min = (*vertices)[i * 3];
      }

      if ((*vertices)[i * 3 + 1] > *y_max) {
        *y_max = (*vertices)[i * 3 + 1];
      } else if ((*vertices)[i * 3 + 1] < *y_min) {
        *y_min = (*vertices)[i * 3 + 1];
      }

      if ((*vertices)[i * 3 + 2] > *z_max) {
        *z_max = (*vertices)[i * 3 + 2];
      } else if ((*vertices)[i * 3 + 2] < *z_min) {
        *z_min = (*vertices)[i * 3 + 2];
      }
    }
  }
}
