#include <check.h>

#include "parser.h"

#define eps 1e-7

START_TEST(test_1) {
  char file[50] = {"modl/cube.txt"};
  Point *all_points = NULL;
  int top_pointers = 0;
  int count_surfaces = 0;
  Surface *all_surfaces;
  int edge = 0;

  all_points = return_points(&top_pointers, file);
  if (all_points != NULL) {
    all_surfaces = return_surfaces(&edge, &count_surfaces, file, all_points);
  }
  double answer[8][3] = {{-1, -1, 1},  {1, -1, 1},  {1, 1, 1},  {-1, 1, 1},
                         {-1, -1, -1}, {1, -1, -1}, {1, 1, -1}, {-1, 1, -1}};

  for (int i = 0; i < 8; ++i) {
    ck_assert_double_eq_tol(all_points[i].x, answer[i][0], eps);
    ck_assert_double_eq_tol(all_points[i].y, answer[i][1], eps);
    ck_assert_double_eq_tol(all_points[i].z, answer[i][2], eps);
  }
  if (all_surfaces != NULL) {
    for (int i = 0; i < count_surfaces; ++i) {
      free(all_surfaces[i].one_point);
    }
    free(all_surfaces);
  }
  free(all_points);
}

START_TEST(test_2) {
  char file[50] = {"modl/cube.txt"};
  Point *all_points = NULL;
  int top_pointers = 0;
  int count_surfaces = 0;
  Surface *all_surfaces;
  int edge = 0;

  all_points = return_points(&top_pointers, file);
  if (all_points != NULL) {
    all_surfaces = return_surfaces(&edge, &count_surfaces, file, all_points);
  }
  double answer[8][3] = {{0.5, -1.5, 0.7071068},
                         {1.5, -0.5, -0.7071068},
                         {1.2071068, 1.2071068, 0.2928932},
                         {0.2071068, 0.2071068, 1.7071068},
                         {-1.2071068, -1.2071068, -0.2928932},
                         {-0.2071068, -0.2071068, -1.7071068},
                         {-0.5, 1.5, -0.7071068},
                         {-1.5, 0.5, 0.7071068}};
  figure_rotation(top_pointers, all_points, 45, 45, 45);
  for (int i = 0; i < 8; ++i) {
    ck_assert_double_eq_tol(all_points[i].x, answer[i][0], eps);
    ck_assert_double_eq_tol(all_points[i].y, answer[i][1], eps);
    ck_assert_double_eq_tol(all_points[i].z, answer[i][2], eps);
  }
  if (all_surfaces != NULL) {
    for (int i = 0; i < count_surfaces; ++i) {
      free(all_surfaces[i].one_point);
    }
    free(all_surfaces);
  }
  free(all_points);
}

START_TEST(test_3) {
  char file[50] = {"modl/cube.txt"};
  Point *all_points = NULL;
  int top_pointers = 0;
  int count_surfaces = 0;
  Surface *all_surfaces;
  int edge = 0;

  all_points = return_points(&top_pointers, file);
  if (all_points != NULL) {
    all_surfaces = return_surfaces(&edge, &count_surfaces, file, all_points);
  }
  double answer[8][3] = {{4, -8, 2}, {6, -8, 2}, {6, -6, 2}, {4, -6, 2},
                         {4, -8, 0}, {6, -8, 0}, {6, -6, 0}, {4, -6, 0}};

  figure_move_x(top_pointers, 5, all_points);
  figure_move_y(top_pointers, -7, all_points);
  figure_move_z(top_pointers, 1, all_points);

  for (int i = 0; i < 8; ++i) {
    ck_assert_double_eq_tol(all_points[i].x, answer[i][0], eps);
    ck_assert_double_eq_tol(all_points[i].y, answer[i][1], eps);
    ck_assert_double_eq_tol(all_points[i].z, answer[i][2], eps);
  }
  if (all_surfaces != NULL) {
    for (int i = 0; i < count_surfaces; ++i) {
      free(all_surfaces[i].one_point);
    }
    free(all_surfaces);
  }
  free(all_points);
}

START_TEST(test_4) {
  char file[50] = {"modl/cube.txt"};
  Point *all_points = NULL;
  int top_pointers = 0;
  int count_surfaces = 0;
  Surface *all_surfaces;
  int edge = 0;

  all_points = return_points(&top_pointers, file);
  if (all_points != NULL) {
    all_surfaces = return_surfaces(&edge, &count_surfaces, file, all_points);
  }
  double answer[8][3] = {{-0.5, -0.5, 0.5},  {0.5, -0.5, 0.5},
                         {0.5, 0.5, 0.5},    {-0.5, 0.5, 0.5},
                         {-0.5, -0.5, -0.5}, {0.5, -0.5, -0.5},
                         {0.5, 0.5, -0.5},   {-0.5, 0.5, -0.5}};

  figure_scaling(top_pointers, 0.5, all_points);

  for (int i = 0; i < 8; ++i) {
    ck_assert_double_eq_tol(all_points[i].x, answer[i][0], eps);
    ck_assert_double_eq_tol(all_points[i].y, answer[i][1], eps);
    ck_assert_double_eq_tol(all_points[i].z, answer[i][2], eps);
  }
  if (all_surfaces != NULL) {
    for (int i = 0; i < count_surfaces; ++i) {
      free(all_surfaces[i].one_point);
    }
    free(all_surfaces);
  }
  free(all_points);
}

START_TEST(test_5) {
  char file[50] = {"modl/nofile.txt"};
  Point *all_points = NULL;
  int top_pointers = 0;

  all_points = return_points(&top_pointers, file);

  ck_assert_ptr_null(all_points);

  free(all_points);
}

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
