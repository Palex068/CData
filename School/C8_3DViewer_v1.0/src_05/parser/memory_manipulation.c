#include "parser.h"

int malloc_matrix(double*** matrix, int size);
void free_matrix(double*** matrix, int size);

/// @brief initializes structure Figure (NULL / 0)
/// @param figure pointer to structure of type Figure
int init_figure(Figure* figure) {
  int error = OK;
  figure->vertex = NULL;
  figure->polygon = NULL;
  figure->amount_vertex = 0;
  figure->amount_polygon = 0;
  figure->amount_polygon_edges = 0;
  figure->x_max = figure->y_max = figure->z_max = 0;
  figure->x_min = figure->y_min = figure->z_min = 0;
  figure->cur_scale = 1;

  figure->trv.tranformation_matrix = NULL;
  figure->trv.rotation_matrix_x = NULL;
  figure->trv.rotation_matrix_y = NULL;
  figure->trv.rotation_matrix_z = NULL;
  error = malloc_matrix(&figure->trv.tranformation_matrix, 4);
  if (!error) error = malloc_matrix(&figure->trv.rotation_matrix_x, 3);
  if (!error) error = malloc_matrix(&figure->trv.rotation_matrix_y, 3);
  if (!error) error = malloc_matrix(&figure->trv.rotation_matrix_z, 3);
  figure->trv.move_vector[x] = 0;
  figure->trv.move_vector[y] = 0;
  figure->trv.move_vector[z] = 0;
  return error;
}

/// @brief deallocates memory for figure
/// @param figure pointer to structure of type Figure
void destroy_figure(Figure* figure) {
  if (figure->polygon) {
    for (int i = 0; i < figure->amount_polygon; ++i) {
      if (figure->polygon[i].vertex_p) free(figure->polygon[i].vertex_p);
    }
    free(figure->polygon);
    figure->polygon = NULL;
    figure->amount_polygon = 0;
  }

  if (figure->vertex) {
    free(figure->vertex);
    figure->vertex = NULL;
    figure->amount_vertex = 0;
  }
  free_matrix(&figure->trv.tranformation_matrix, 4);
  free_matrix(&figure->trv.rotation_matrix_x, 3);
  free_matrix(&figure->trv.rotation_matrix_y, 3);
  free_matrix(&figure->trv.rotation_matrix_z, 3);
}

/// @brief allocates memory for new vertex
/// @param figure pointer to structure of type Figure
/// @return error code: 1 = error; 0 = OK
int realloc_vertex(Figure* figure) {
  int error = OK;
  if (figure->amount_vertex == 0) {
    figure->vertex = calloc(3, sizeof(double));
    if (!figure->vertex) error = ERR;
    if (!error) {
      ++figure->amount_vertex;
    }
  } else {
    double* row_tmp = NULL;
    row_tmp = realloc(figure->vertex,
                      (figure->amount_vertex * 3 + 3) * sizeof(double));
    if (!row_tmp) error = ERR;
    if (!error) {
      figure->vertex = row_tmp;
      ++figure->amount_vertex;
    }
  }
  return error;
}

/// @brief allocates memory for new polygon line
/// @param figure pointer to structure of type Figure
/// @return error code: 1 = error; 0 = OK
int realloc_polygon(Figure* figure) {
  int error = OK;
  if (figure->amount_polygon == 0) {
    figure->polygon = malloc(sizeof(Polygon));
    if (!figure->polygon)
      error = ERR;
    else
      figure->amount_polygon = 1;
  } else {
    Polygon* tmp = realloc(figure->polygon,
                           (figure->amount_polygon + 1) * sizeof(Polygon));
    if (!tmp)
      error = ERR;
    else {
      figure->polygon = tmp;
      ++figure->amount_polygon;
    }
  }

  if (!error) {
    figure->polygon[figure->amount_polygon - 1].vertex_p = NULL;
    figure->polygon[figure->amount_polygon - 1].amount_p = 0;
  }

  return error;
}

/// @brief deallocates memory for the last polygon line
/// @param figure pointer to structure of type Figure
/// @return error code: 1 = error; 0 = OK
int realloc_down_polygon(Figure* figure) {
  int error = OK;
  if (figure->amount_polygon > 1 && figure->polygon) {
    Polygon* tmp = realloc(figure->polygon,
                           (figure->amount_polygon - 1) * sizeof(Polygon));
    if (!tmp)
      error = ERR;
    else {
      figure->polygon = tmp;
      --figure->amount_polygon;
    }
  } else if (figure->amount_polygon == 1 && figure->polygon) {
    free(figure->polygon);
    figure->polygon = NULL;
    figure->amount_polygon = 0;
  }
  return error;
}

/// @brief allocates memory for a new single polygon vertex
/// @param polygon pointer to structure of type Polygon
/// @return error code: 1 = error; 0 = OK
int realloc_vertex_p(Polygon* polygon) {
  int error = OK;
  if (polygon->amount_p == 0) {
    polygon->vertex_p = malloc(sizeof(int));
    if (!polygon->vertex_p)
      error = ERR;
    else
      ++polygon->amount_p;
  } else {
    int* tmp = NULL;
    tmp = realloc(polygon->vertex_p, (polygon->amount_p + 1) * sizeof(int));
    if (!tmp)
      error = ERR;
    else {
      polygon->vertex_p = tmp;
      ++polygon->amount_p;
    }
  }
  return error;
}

/// @brief allocates memory for a square matrix
/// @param matrix
/// @param size
/// @return error code: 1 = error; 0 = OK
int malloc_matrix(double*** matrix, int size) {
  int error = OK;
  if (*matrix == NULL) {
    *matrix = (double**)calloc(size, sizeof(double*));
    if (*matrix == NULL) error = ERR;
    if (!error) {
      for (int i = 0; i < size && !error; ++i) {
        (*matrix)[i] = (double*)calloc(size, sizeof(double));
        if ((*matrix)[i] == NULL) error = ERR;
      }
    }
  }
  return error;
}

/// @brief frees matrix memory
/// @param matrix
/// @param size
void free_matrix(double*** matrix, int size) {
  if (*matrix != NULL) {
    for (int i = 0; i < size; ++i) {
      if ((*matrix)[i]) free((*matrix)[i]);
    }
    free(*matrix);
    *matrix = NULL;
  }
}