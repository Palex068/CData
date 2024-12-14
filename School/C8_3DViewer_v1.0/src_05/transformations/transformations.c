#include "transformations.h"

#include <stdio.h>
/// @brief Changes coordinates' values so, the figure center is 0,0,0 and max
/// crd no more than 0.5
/// @param figure
void align_to_center(Figure* figure) {
  double x_center = (figure->x_min + figure->x_max) / 2.0;
  double y_center = (figure->y_min + figure->y_max) / 2.0;
  double z_center = (figure->z_min + figure->z_max) / 2.0;
  for (int i = 0; i < figure->amount_vertex; ++i) {
    figure->vertex[i * 3 + x] = (figure->vertex[i * 3 + x] - x_center);
    figure->vertex[i * 3 + y] = (figure->vertex[i * 3 + y] - y_center);
    figure->vertex[i * 3 + z] = (figure->vertex[i * 3 + z] - z_center);
  }
}

/// @brief Scales figure relatively, current figure scale is always 1.0
/// @param figure
/// @param scale e.g. 1.1 means increase coordinates values so, the figure is
/// bigger at 10%
void scale_figure(Figure* figure, double scale) {
  if (scale < 0.000001) scale = figure->cur_scale;
  double scale_coef = scale / figure->cur_scale;
  figure->cur_scale = scale;
  for (int i = 0; i < figure->amount_vertex; ++i) {
    figure->vertex[i * 3 + x] *= scale_coef;
    figure->vertex[i * 3 + y] *= scale_coef;
    figure->vertex[i * 3 + z] *= scale_coef;
  }
}

/// @brief fills transformation matrix according to set move_vector values
/// @param figure
void fill_transformation_matrix(Figure* figure) {
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      figure->trv.tranformation_matrix[i][j] = i == j ? 1 : 0;
    }
  }
  figure->trv.tranformation_matrix[0][homo] = figure->trv.move_vector[x];
  figure->trv.tranformation_matrix[1][homo] = figure->trv.move_vector[y];
  figure->trv.tranformation_matrix[2][homo] = figure->trv.move_vector[z];
}

/// @brief Transposes a square matrix, result rewrites the original
/// @param t_matrix
void matrix_transpose(double** t_matrix) {
  double temp;
  for (int i = 0; i < 4; ++i) {
    for (int j = i + 1; j < 4; ++j) {
      temp = t_matrix[i][j];
      t_matrix[i][j] = t_matrix[j][i];
      t_matrix[j][i] = temp;
    }
  }
}

/// @brief Changes coordinates so, the figure is about to move relative to 0,0,0
/// at move_vector[3] values
/// @param figure
void move_figure(Figure* figure) {
  fill_transformation_matrix(figure);
  matrix_transpose(figure->trv.tranformation_matrix);
  for (int i = 0; i < figure->amount_vertex; ++i) {
    for (int j = 0; j < 4; ++j) {
      double temp = 0;
      for (int k = 0; k < 4; ++k) {
        double value = k == 3 ? 1.0 : figure->vertex[i * 3 + k];
        temp += value * figure->trv.tranformation_matrix[k][j];
      }
      if (j < 3) figure->vertex[i * 3 + j] = temp;
    }
  }
}

/// @brief Changes coordinates so, the figure is about to rotate relative to
/// 0,0,0 at alpha_x, alpha_y, alpha_z values. Alpha - should be set as degree
/// @param figure
void rotate_figure(Figure* figure) {
  double alpha_x = figure->alpha_x * M_PI / 180.0;
  double alpha_y = figure->alpha_y * M_PI / 180.0;
  double alpha_z = figure->alpha_z * M_PI / 180.0;
  fill_rotation_matrix_crd(figure->trv.rotation_matrix_x, alpha_x, x);
  fill_rotation_matrix_crd(figure->trv.rotation_matrix_y, alpha_y, y);
  fill_rotation_matrix_crd(figure->trv.rotation_matrix_z, alpha_z, z);
  rotate_helper(figure, x);
  rotate_helper(figure, y);
  rotate_helper(figure, z);
}

/// @brief Fills rotation matrixes
/// @param matrix
/// @param alpha radians
/// @param crd x, y, z
void fill_rotation_matrix_crd(double** matrix, double alpha, int crd) {
  matrix[0][0] = crd == x ? 1.0 : cos(alpha);
  matrix[0][1] = crd == z ? -sin(alpha) : 0;
  matrix[0][2] = crd == y ? sin(alpha) : 0;
  matrix[1][0] = crd == z ? sin(alpha) : 0;
  matrix[1][1] = crd == y ? 1 : cos(alpha);
  matrix[1][2] = crd == x ? -sin(alpha) : 0;
  matrix[2][0] = crd == y ? -sin(alpha) : 0;
  matrix[2][1] = crd == x ? sin(alpha) : 0;
  matrix[2][2] = crd == z ? 1 : cos(alpha);
}

/// @brief Multiplies vertex on rotation matrix
/// @param figure
/// @param crd x, y, z
void rotate_helper(Figure* figure, int crd) {
  for (int i = 0; i < figure->amount_vertex; ++i) {
    double tmp[3] = {0, 0, 0};
    for (int j = 0; j < 3; ++j) {
      for (int k = 0; k < 3; ++k) {
        double value = 0;
        if (crd == x) value = figure->trv.rotation_matrix_x[j][k];
        if (crd == y) value = figure->trv.rotation_matrix_y[j][k];
        if (crd == z) value = figure->trv.rotation_matrix_z[j][k];
        tmp[j] += value * figure->vertex[i * 3 + k];
      }
    }
    for (int j = 0; j < 3; ++j) {
      figure->vertex[i * 3 + j] = tmp[j];
    }
  }
}
