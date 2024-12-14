#ifndef __COMMON_H__
#define __COMMON_H__

#define ERR 1
#define OK 0

#define INITIAL_SCALE 1

typedef enum { x = 0, y, z, homo } crd;

typedef struct t_math {
  double **tranformation_matrix;
  double **rotation_matrix_x;
  double **rotation_matrix_y;
  double **rotation_matrix_z;
  double move_vector[3];
} t_math;

typedef struct Polygon {
  int *vertex_p;
  int amount_p;
} Polygon;

typedef struct Figure {
  double *vertex;
  int amount_vertex;
  Polygon *polygon;
  int amount_polygon;
  int amount_polygon_edges;
  double x_max, y_max, z_max, x_min, y_min, z_min;
  double alpha_x, alpha_y, alpha_z;
  double cur_scale;
  t_math trv;
} Figure;

#ifdef __cplusplus
/// @brief loops over a file line by line, detects and parses vertexes and
/// polygons
/// @param filename file path (better to use absolute)
/// @param figure pointer to structure of type Figure
/// @return error code: 1 = error; 0 = OK
extern "C" {
#endif

int parse_obj_file(const char *filename, Figure *figure);
void destroy_figure(Figure *figure);

void align_to_center(Figure *figure);
void scale_figure(Figure *figure, double scale);
void move_figure(Figure *figure);
void rotate_figure(Figure *figure);

#ifdef __cplusplus
}
#endif

#endif
