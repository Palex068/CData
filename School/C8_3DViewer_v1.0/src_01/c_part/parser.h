#ifndef PARSER_H
#define PARSER_H
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 50

typedef struct {
  double x;
  double y;
  double z;
} Point;

typedef struct {
  Point **one_point;
  int amount_of_points;
} Surface;

typedef struct {
  double x_max, x_min;
  double y_max, y_min;
  double z_max, z_min;
} ExtremeValues;

Point *point_reading(char *file, int *top_pointers,
                     ExtremeValues *extreme_values);
void coordinate_recording_counter(int *count_coord, int top_pointers,
                                  double *result, Point *all_points);
Surface *points_in_space(int *edge, char *buffer_str, int count_surfaces,
                         int top_pointers, Surface *all_surfaces,
                         Point *all_points);
Surface *surface_formation(int *edge, char *file, int *count_surfaces,
                           Surface *all_surfaces, Point *all_points);
void point_address_calculation(char chr, int *res, int *flag_mines);
void point_address_modification(int *res, int *flag_mines, int top_pointers);
Point *point_processing(FILE *f, int *top_pointers, int *size_all_points,
                        ExtremeValues *extreme_values, Point *all_points);
void to_double(double *result, char chr, int *flag_dot, int *flag_mines);
void finding_extreme_values(double result, int count_coord, int top_pointers,
                            ExtremeValues *extreme_values);
void figure_centering(int top_pointers, ExtremeValues *extreme_values,
                      Point *all_points);
double delta_max(double x, double y, double z);
void figure_rotation(int top_pointers, Point *all_points, double degree_x,
                     double degree_y, double degree_z);
void figure_move_x(int top_pointers, int shift, Point *all_points);
void figure_move_y(int top_pointers, int shift, Point *all_points);
void figure_move_z(int top_pointers, int shift, Point *all_points);
void figure_scaling(int top_pointers, double coefficient, Point *all_points);
void to_int(int *exp, char chr, int *flag_mines_exp);
void point_attribute_correction(int flag_mines, int flag_mines_exp, int *exp,
                                double *result);
int character_check_for_points(char c);
Point *point_search_cycle(int *top_pointers, char *buffer_str,
                          ExtremeValues *extreme_values, Point *all_points);
int character_check_for_surfaces(char c);
Point *return_points(int *top_pointers, char *file);
Surface *return_surfaces(int *edge, int *count_surfaces, char *file,
                         Point *all_points);
void figure_rotation(int top_pointers, Point *all_points, double degree_x,
                     double degree_y, double degree_z);
void figure_move_x(int top_pointers, int shift, Point *all_points);
void figure_move_y(int top_pointers, int shift, Point *all_points);
void figure_move_z(int top_pointers, int shift, Point *all_points);
void figure_scaling(int top_pointers, double coefficient, Point *all_points);

#endif  // PARSER_H
