#include "parser.h"

Surface *return_surfaces(int *edge, int *count_surfaces, char *file,
                         Point *all_points) {
  Surface *all_surfaces;
  if ((all_surfaces = (Surface *)malloc(SIZE * sizeof(Surface))) != NULL) {
    all_surfaces =
        surface_formation(edge, file, count_surfaces, all_surfaces, all_points);
  }
  (*edge) /= 2;
  return all_surfaces;
}

Point *return_points(int *top_pointers, char *file) {
  Point *all_points = NULL;
  ExtremeValues extreme_values;
  extreme_values.x_max = extreme_values.x_min = extreme_values.y_max =
      extreme_values.y_min = extreme_values.z_max = extreme_values.z_min = 0;
  all_points = point_reading(file, top_pointers, &extreme_values);
  if (all_points != NULL)
    figure_centering(*top_pointers, &extreme_values, all_points);
  return all_points;
}

void figure_centering(int top_pointers, ExtremeValues *extreme_values,
                      Point *all_points) {
  double center_x, center_y, center_z;
  double dmax, coefficient;
  center_x = extreme_values->x_min +
             ((extreme_values->x_max - extreme_values->x_min) / 2);
  center_y = extreme_values->y_min +
             ((extreme_values->y_max - extreme_values->y_min) / 2);
  center_z = extreme_values->z_min +
             ((extreme_values->z_max - extreme_values->z_min) / 2);
  double delta_x = extreme_values->x_max - extreme_values->x_min;
  double delta_y = extreme_values->y_max - extreme_values->y_min;
  double delta_z = extreme_values->z_max - extreme_values->z_min;
  dmax = delta_max(delta_x, delta_y, delta_z);
  coefficient = (1 - (1 * (-1))) / dmax;
  for (int i = 0; i <= top_pointers; ++i) {
    all_points[i].x -= center_x;
    all_points[i].x *= coefficient;
    all_points[i].y -= center_y;
    all_points[i].y *= coefficient;
    all_points[i].z -= center_z;
    all_points[i].z *= coefficient;
  }
}

double delta_max(double x, double y, double z) {
  double back = x;
  if (x < y) back = y;
  if (y < z) back = z;
  return back;
}

Point *point_reading(char *file, int *top_pointers,
                     ExtremeValues *extreme_values) {
  FILE *f = NULL;
  int size_all_points = SIZE;
  Point *all_points = (Point *)malloc(size_all_points * sizeof(Point));
  if (((f = fopen(file, "r")) != NULL) && (all_points != NULL)) {
    all_points = point_processing(f, top_pointers, &size_all_points,
                                  extreme_values, all_points);
  } else {
    if (all_points != NULL) free(all_points);
    all_points = NULL;
  }
  return all_points;
}

Point *point_processing(FILE *f, int *top_pointers, int *size_all_points,
                        ExtremeValues *extreme_values, Point *all_points) {
  char c = 0, past_char = 0;
  char buffer_str[1000];
  while (((c = fgetc(f)) != EOF) && (all_points != NULL)) {
    if ((c == ' ') && (past_char == 'v')) {
      if ((*top_pointers) == (*size_all_points)) {
        (*size_all_points) *= 2;
        all_points =
            (Point *)realloc(all_points, (*size_all_points) * sizeof(Point));
      }
      fgets(buffer_str, 99, f);
      all_points = point_search_cycle(top_pointers, buffer_str, extreme_values,
                                      all_points);
    } else if (((c == ' ') && (past_char == 'f')) ||
               ((c == ' ') && (past_char == 't')) ||
               ((c == ' ') && (past_char == 'n'))) {
      char buffer_str[1000];
      fgets(buffer_str, 999, f);
    }
    past_char = c;
  }
  if ((*top_pointers == 0) && (all_points != NULL)) {
    free(all_points);
    all_points = NULL;
  }
  fclose(f);
  (*top_pointers)--;
  return all_points;
}

Point *point_search_cycle(int *top_pointers, char *buffer_str,
                          ExtremeValues *extreme_values, Point *all_points) {
  int count_coord = 0, exp = 0;
  int flag_result = 0, flag_dot = 0, flag_mines = 0, flag_mines_exp = 0,
      flag_exp = 0;
  double result = 0;
  for (int i = 0; (count_coord < 3) && (all_points != NULL); ++i) {
    if ((buffer_str[i] != ' ') && (buffer_str[i] != '\n') &&
        (buffer_str[i] != '\0') && (buffer_str[i] != 13)) {
      if (character_check_for_points(buffer_str[i])) {
        if ((buffer_str[i] == 'e') || (buffer_str[i] == 'E')) {
          flag_exp = 1;
        }
        if (flag_exp == 0) {
          to_double(&result, buffer_str[i], &flag_dot, &flag_mines);
        } else {
          to_int(&exp, buffer_str[i], &flag_mines_exp);
        }
        flag_result = 1;
      } else {
        free(all_points);
        all_points = NULL;
      }
    } else if (flag_result != 0) {
      point_attribute_correction(flag_mines, flag_mines_exp, &exp, &result);
      finding_extreme_values(result, count_coord, *top_pointers,
                             extreme_values);
      flag_mines = flag_result = flag_dot = flag_mines_exp = 0;
      coordinate_recording_counter(&count_coord, *top_pointers, &result,
                                   all_points);
      if (count_coord == 3) {
        (*top_pointers)++;
      }
    }
  }
  return all_points;
}

int character_check_for_points(char c) {
  int back = 0;
  if (((c >= '0') && (c <= '9')) || (c == '-') || (c == 'e') || (c == 'E') ||
      (c == '.')) {
    back = 1;
  }
  return back;
}

void point_attribute_correction(int flag_mines, int flag_mines_exp, int *exp,
                                double *result) {
  if (flag_mines == 1) {
    (*result) *= -1;
  }
  if ((*exp) != 0) {
    if (flag_mines_exp == 1) {
      (*exp) *= -1;
    }
    (*result) *= pow(10, (*exp));
  }
}

void to_int(int *exp, char chr, int *flag_mines_exp) {
  if (chr != '-') {
    (*exp) = (*exp) * 10 + (chr - 48);
  } else {
    (*flag_mines_exp) = 1;
  }
}

void finding_extreme_values(double result, int count_coord, int top_pointers,
                            ExtremeValues *extreme_values) {
  if (top_pointers == 0) {
    switch (count_coord) {
      case 0:
        extreme_values->x_max = result;
        extreme_values->x_min = result;
        break;
      case 1:
        extreme_values->y_max = result;
        extreme_values->y_min = result;
        break;
      case 2:
        extreme_values->z_max = result;
        extreme_values->z_min = result;
        break;
    }
  } else {
    switch (count_coord) {
      case 0:
        if (result > extreme_values->x_max) extreme_values->x_max = result;
        if (result < extreme_values->x_min) extreme_values->x_min = result;
        break;
      case 1:
        if (result > extreme_values->y_max) extreme_values->y_max = result;
        if (result < extreme_values->y_min) extreme_values->y_min = result;
        break;
      case 2:
        if (result > extreme_values->z_max) extreme_values->z_max = result;
        if (result < extreme_values->z_min) extreme_values->z_min = result;
        break;
    }
  }
}

void to_double(double *result, char chr, int *flag_dot, int *flag_mines) {
  if ((chr != '.') && (chr != '-')) {
    if ((*flag_dot) == 0) {
      (*result) = (*result) * 10 + (chr - 48);
    } else {
      (*result) += (chr - 48) * pow(10, -(*flag_dot));
      (*flag_dot)++;
    }
  } else if (chr == '.') {
    (*flag_dot) = 1;
  } else {
    (*flag_mines) = 1;
  }
}

void coordinate_recording_counter(int *count_coord, int top_pointers,
                                  double *result, Point *all_points) {
  switch (*count_coord) {
    case 0:
      all_points[top_pointers].x = *result;
      break;
    case 1:
      all_points[top_pointers].y = *result;
      break;
    case 2:
      all_points[top_pointers].z = *result;
      break;
  }
  (*count_coord)++;
  *result = 0;
}

Surface *surface_formation(int *edge, char *file, int *count_surfaces,
                           Surface *all_surfaces, Point *all_points) {
  FILE *f;
  int size_all_surfaces = SIZE;
  if ((f = fopen(file, "r")) != NULL) {
    char c;
    char past_char = 0;
    int top_pointers_now = 0;
    while ((c = fgetc(f)) != EOF) {
      if ((c == ' ') && (past_char == 'v')) {
        top_pointers_now++;
      }
      if ((c == ' ') && (past_char == 'f')) {
        if ((*count_surfaces) == size_all_surfaces) {
          size_all_surfaces *= 2;
          all_surfaces = (Surface *)realloc(
              all_surfaces, size_all_surfaces * sizeof(Surface));
        }
        char buffer_str[1000];
        fgets(buffer_str, 999, f);
        all_surfaces =
            points_in_space(edge, buffer_str, (*count_surfaces),
                            top_pointers_now - 1, all_surfaces, all_points);
        (*count_surfaces)++;
      } else if (((c == ' ') && (past_char == 'v')) ||
                 ((c == ' ') && (past_char == 't')) ||
                 ((c == ' ') && (past_char == 'n'))) {
        char buffer_str[1000];
        fgets(buffer_str, 999, f);
      }
      past_char = c;
    }
  } else {
    all_surfaces = NULL;
  }
  return all_surfaces;
}

Surface *points_in_space(int *edge, char *buffer_str, int count_surfaces,
                         int top_pointers, Surface *all_surfaces,
                         Point *all_points) {
  int res = 0;
  int count_point_in_surface = 0;
  int number_of_points = (buffer_str[0] == ' ') ? 0 : 1;
  int flag_mines = 0;
  int flag_slash = 0;
  for (int i = 0; buffer_str[i] != 0; ++i) {
    if (!character_check_for_surfaces(buffer_str[i])) {
      free(all_surfaces);
      all_surfaces = NULL;
      break;
    }
    if ((buffer_str[i] == ' ') &&
        (((buffer_str[i + 1] >= '0') && (buffer_str[i + 1] <= '9')) ||
         (buffer_str[i + 1] == '-')))
      number_of_points++;
  }
  if (all_surfaces != NULL) {
    all_surfaces[count_surfaces].one_point =
        (Point **)malloc(number_of_points * sizeof(Point *));
    for (int i = 0; count_point_in_surface < number_of_points; ++i) {
      if ((buffer_str[i] != ' ') && (buffer_str[i] != '\n') &&
          (buffer_str[i] != '\0') && (buffer_str[i] != 13)) {
        if (buffer_str[i] == '/') {
          flag_slash = 1;
        }
        if (flag_slash == 0) {
          point_address_calculation(buffer_str[i], &res, &flag_mines);
        }
      } else if (res != 0) {
        flag_slash = 0;
        point_address_modification(&res, &flag_mines, top_pointers);
        all_surfaces[count_surfaces].one_point[count_point_in_surface] =
            all_points + res;
        count_point_in_surface++;
        res = 0;
      }
    }
    (*edge) += number_of_points;
    all_surfaces[count_surfaces].amount_of_points = number_of_points;
  }
  return all_surfaces;
}

int character_check_for_surfaces(char c) {
  int back = 0;
  if (((c >= '0') && (c <= '9')) || (c == '-') || (c == '/') || (c == ' ') ||
      (c == '\n') || (c == '\0') || (c == 13)) {
    back = 1;
  }
  return back;
}

void point_address_modification(int *res, int *flag_mines, int top_pointers) {
  if (*flag_mines) {
    (*res) *= -1;
    (*flag_mines) = 0;
  }
  if ((*res) < 0) {
    (*res) += top_pointers + 1;
  } else {
    (*res) -= 1;
  }
}

void point_address_calculation(char chr, int *res, int *flag_mines) {
  if (chr != '-') {
    (*res) = (*res) * 10 + (chr - 48);

  } else {
    (*flag_mines) = 1;
  }
}

void figure_rotation(int top_pointers, Point *all_points, double degree_x,
                     double degree_y, double degree_z) {
  double sin_x = sin(degree_x * M_PI / 180);
  double cos_x = cos(degree_x * M_PI / 180);
  double sin_y = sin(degree_y * M_PI / 180);
  double cos_y = cos(degree_y * M_PI / 180);
  double sin_z = sin(degree_z * M_PI / 180);
  double cos_z = cos(degree_z * M_PI / 180);
  for (int i = 0; i <= top_pointers; ++i) {
    double x = all_points[i].x;
    double y = all_points[i].y;
    double z = all_points[i].z;
    double temp_x, temp_y, temp_z;
    temp_y = cos_x * y - sin_x * z;
    temp_z = sin_x * y + cos_x * z;
    temp_x = cos_y * x + sin_y * temp_z;
    temp_z = -sin_y * x + cos_y * temp_z;
    all_points[i].x = cos_z * temp_x - sin_z * temp_y;
    all_points[i].y = sin_z * temp_x + cos_z * temp_y;
    all_points[i].z = temp_z;
  }
}

void figure_scaling(int top_pointers, double coefficient, Point *all_points) {
  for (int i = 0; i <= top_pointers; ++i) {
    all_points[i].x *= coefficient;
    all_points[i].y *= coefficient;
    all_points[i].z *= coefficient;
  }
}

void figure_move_x(int top_pointers, int shift, Point *all_points) {
  for (int i = 0; i <= top_pointers; ++i) {
    all_points[i].x += shift;
  }
}

void figure_move_y(int top_pointers, int shift, Point *all_points) {
  for (int i = 0; i <= top_pointers; ++i) {
    all_points[i].y += shift;
  }
}

void figure_move_z(int top_pointers, int shift, Point *all_points) {
  for (int i = 0; i <= top_pointers; ++i) {
    all_points[i].z += shift;
  }
}
