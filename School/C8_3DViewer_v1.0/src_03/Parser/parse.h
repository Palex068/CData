#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void s21_center_vertices(double **vertices, int number_of_vertices);
void s21_parse_file(char *file_name, int **facets, int *number_of_lines,
                    int *facets_length, int *number_of_vertices,
                    double **vertices);
void s21_parse_f_line(char *line, int **facets, int *number_of_lines,
                      int *facets_length, int number_of_vertices);
void s21_parse_v_line(char *line, double **vertices, int *number_of_vertices);
void s21_scan_f_line(char *line, int *vertices_per_facet, int **vertices_ids);
void s21_scale(double **vertices, int number_of_vertices, double scale);
void s21_rotate(double **vertices, int number_of_vertices, double degrees,
                int ax);
void s21_shift(double **vertices, int number_of_vertices, double x, double y,
               double z);
void s21_initial_scale(double **vertices, int number_of_vertices);
void s21_find_max_min_values(double **vertices, int number_of_vertices,
                             double *x_min, double *x_max, double *y_min,
                             double *y_max, double *z_min, double *z_max);
void s21_initial_scale(double **vertices, int number_of_vertices);
