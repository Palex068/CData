#include "test.h"

START_TEST(TEST_1) {
  char *line = " 3/3/3";
  int vertices_per_facet = 0;
  int *vertices_ids = (int *)malloc(sizeof(int));

  s21_scan_f_line(line, &vertices_per_facet, &vertices_ids);

  ck_assert_int_eq(vertices_per_facet, 1);
  ck_assert_int_eq(vertices_ids[0], 3);
  free(vertices_ids);
}
END_TEST

START_TEST(TEST_2) {
  char *line = " 5//3 9//2";
  int vertices_per_facet = 0;
  int *vertices_ids = (int *)malloc(sizeof(int));

  s21_scan_f_line(line, &vertices_per_facet, &vertices_ids);

  ck_assert_int_eq(vertices_per_facet, 2);
  ck_assert_int_eq(vertices_ids[0], 5);
  ck_assert_int_eq(vertices_ids[1], 9);
  free(vertices_ids);
}
END_TEST

START_TEST(TEST_3) {
  char *line = " 8 4 2";
  int vertices_per_facet = 0;
  int *vertices_ids = (int *)malloc(sizeof(int));

  s21_scan_f_line(line, &vertices_per_facet, &vertices_ids);

  ck_assert_int_eq(vertices_per_facet, 3);
  ck_assert_int_eq(vertices_ids[0], 8);
  ck_assert_int_eq(vertices_ids[1], 4);
  ck_assert_int_eq(vertices_ids[2], 2);
  free(vertices_ids);
}
END_TEST

START_TEST(TEST_4) {
  char *line = " 8/2 2/5     ";
  int vertices_per_facet = 0;
  int *vertices_ids = (int *)malloc(sizeof(int));

  s21_scan_f_line(line, &vertices_per_facet, &vertices_ids);

  ck_assert_int_eq(vertices_per_facet, 2);
  ck_assert_int_eq(vertices_ids[0], 8);
  ck_assert_int_eq(vertices_ids[1], 2);
  free(vertices_ids);
}
END_TEST

START_TEST(TEST_5) {
  char *line = " 8 4 2";
  int *facets;
  int number_of_lines = 0;
  int facets_length = 0;
  int number_of_vertices = 10;

  s21_parse_f_line(line, &facets, &number_of_lines, &facets_length,
                   number_of_vertices);

  ck_assert_int_eq(number_of_lines, 1);
  ck_assert_int_eq(facets_length, 6);
  free(facets);
}
END_TEST

START_TEST(TEST_6) {
  double x_min, x_max, y_min, y_max, z_min, z_max;
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));
  vertices[0] = 1.5;
  vertices[1] = 2.5;
  vertices[2] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[6] = 7.5;
  vertices[7] = 8.5;
  vertices[8] = 9.5;

  s21_find_max_min_values(&vertices, number_of_vertices, &x_min, &x_max, &y_min,
                          &y_max, &z_min, &z_max);

  ck_assert_ldouble_eq_tol(x_min, 1.5, S21_EPS);
  ck_assert_ldouble_eq_tol(x_max, 7.5, S21_EPS);
  ck_assert_ldouble_eq_tol(y_min, 2.5, S21_EPS);
  ck_assert_ldouble_eq_tol(y_max, 8.5, S21_EPS);
  ck_assert_ldouble_eq_tol(z_min, 3.5, S21_EPS);
  ck_assert_ldouble_eq_tol(z_max, 9.5, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_7) {
  double x_min, x_max, y_min, y_max, z_min, z_max;
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));
  vertices[6] = 1.5;
  vertices[7] = 2.5;
  vertices[8] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[0] = 7.5;
  vertices[1] = 8.5;
  vertices[2] = 9.5;

  s21_find_max_min_values(&vertices, number_of_vertices, &x_min, &x_max, &y_min,
                          &y_max, &z_min, &z_max);

  ck_assert_ldouble_eq_tol(x_min, 1.5, S21_EPS);
  ck_assert_ldouble_eq_tol(x_max, 7.5, S21_EPS);
  ck_assert_ldouble_eq_tol(y_min, 2.5, S21_EPS);
  ck_assert_ldouble_eq_tol(y_max, 8.5, S21_EPS);
  ck_assert_ldouble_eq_tol(z_min, 3.5, S21_EPS);
  ck_assert_ldouble_eq_tol(z_max, 9.5, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_8) {
  double x = 0.2;
  double y = 0.3;
  double z = 0.4;
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1.5;
  vertices[1] = 2.5;
  vertices[2] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[6] = 7.5;
  vertices[7] = 8.5;
  vertices[8] = 9.5;

  s21_shift(&vertices, number_of_vertices, x, y, z);

  ck_assert_ldouble_eq_tol(vertices[0], 1.7, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 2.8, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 3.9, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 4.7, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 5.8, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 6.9, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 7.7, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 8.8, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 9.9, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_9) {
  double scale = 2.0;
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1.5;
  vertices[1] = 2.5;
  vertices[2] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[6] = 7.5;
  vertices[7] = 8.5;
  vertices[8] = 9.5;

  s21_scale(&vertices, number_of_vertices, scale);

  ck_assert_ldouble_eq_tol(vertices[0], 3.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 5.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 7.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 9.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 11.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 13.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 15.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 17.0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 19.0, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_10) {
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1.5;
  vertices[1] = 2.5;
  vertices[2] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[6] = 7.5;
  vertices[7] = 8.5;
  vertices[8] = 9.5;

  s21_initial_scale(&vertices, number_of_vertices);

  ck_assert_ldouble_eq_tol(vertices[0], 0.35, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 0.583333, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 0.816667, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 1.05, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 1.283333, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 1.516667, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 1.75, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 1.983333, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 2.216667, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_11) {
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1.5;
  vertices[1] = 2.5;
  vertices[2] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[6] = 7.5;
  vertices[7] = 20.5;
  vertices[8] = 9.5;

  s21_initial_scale(&vertices, number_of_vertices);

  ck_assert_ldouble_eq_tol(vertices[0], 0.116667, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 0.194444, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 0.272222, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 0.35, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 0.427778, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 0.505556, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 0.583333, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 1.594444, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 0.738889, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_12) {
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1.5;
  vertices[1] = 2.5;
  vertices[2] = 3.5;
  vertices[3] = 4.5;
  vertices[4] = 5.5;
  vertices[5] = 6.5;
  vertices[6] = 7.5;
  vertices[7] = 8.5;
  vertices[8] = 20.5;

  s21_initial_scale(&vertices, number_of_vertices);

  ck_assert_ldouble_eq_tol(vertices[0], 0.123529, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 0.205882, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 0.288235, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 0.370588, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 0.452941, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 0.535294, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 0.617647, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 0.7, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 1.688235, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_13) {
  int number_of_vertices = 3;
  double degrees = 90;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1;
  vertices[1] = 2;
  vertices[2] = 3;
  vertices[3] = 4;
  vertices[4] = 5;
  vertices[5] = 6;
  vertices[6] = 7;
  vertices[7] = 8;
  vertices[8] = 9;

  s21_rotate(&vertices, number_of_vertices, degrees, 0);

  ck_assert_ldouble_eq_tol(vertices[0], 1, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], -3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 2, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 4, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], -6, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 5, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 7, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], -9, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 8, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_14) {
  int number_of_vertices = 3;
  double degrees = 90;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1;
  vertices[1] = 2;
  vertices[2] = 3;
  vertices[3] = 4;
  vertices[4] = 5;
  vertices[5] = 6;
  vertices[6] = 7;
  vertices[7] = 8;
  vertices[8] = 9;

  s21_rotate(&vertices, number_of_vertices, degrees, 1);

  ck_assert_ldouble_eq_tol(vertices[0], 3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 2, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], -1, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 6, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 5, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], -4, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 9, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 8, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], -7, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_15) {
  int number_of_vertices = 3;
  double degrees = 90;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1;
  vertices[1] = 2;
  vertices[2] = 3;
  vertices[3] = 4;
  vertices[4] = 5;
  vertices[5] = 6;
  vertices[6] = 7;
  vertices[7] = 8;
  vertices[8] = 9;

  s21_rotate(&vertices, number_of_vertices, degrees, 2);

  ck_assert_ldouble_eq_tol(vertices[0], -2, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], 1, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], 3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], -5, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 4, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 6, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], -8, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 7, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 9, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_16) {
  int number_of_vertices = 3;
  double *vertices = (double *)malloc(9 * sizeof(double));

  vertices[0] = 1;
  vertices[1] = 2;
  vertices[2] = 3;
  vertices[3] = 4;
  vertices[4] = 5;
  vertices[5] = 6;
  vertices[6] = 7;
  vertices[7] = 8;
  vertices[8] = 9;

  s21_center_vertices(&vertices, number_of_vertices);

  ck_assert_ldouble_eq_tol(vertices[0], -3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[1], -3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[2], -3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[3], 0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[4], 0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[5], 0, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[6], 3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[7], 3, S21_EPS);
  ck_assert_ldouble_eq_tol(vertices[8], 3, S21_EPS);

  free(vertices);
}
END_TEST

START_TEST(TEST_17) {
  char *line = "abc5/2/3";
  int *facets;
  int number_of_lines = 0;
  int facets_length = 0;
  int number_of_vertices = 0;

  s21_parse_f_line(line, &facets, &number_of_lines, &facets_length,
                   number_of_vertices);

  ck_assert_int_eq(number_of_lines, 0);
  ck_assert_int_eq(facets_length, 0);
}
END_TEST

START_TEST(TEST_18) {
  char *file_name = "./Test/test.obj";
  int *facets;
  double *vertices;
  int number_of_lines;
  int facets_length;
  int number_of_vertices;

  s21_parse_file(file_name, &facets, &number_of_lines, &facets_length,
                 &number_of_vertices, &vertices);

  ck_assert_int_eq(number_of_lines, 12);
  ck_assert_int_eq(facets_length, 72);
  ck_assert_int_eq(number_of_vertices, 8);

  free(facets);
  free(vertices);
}
END_TEST

START_TEST(TEST_19) {
  char *line = "abc5//88";
  int *facets;
  int number_of_lines = 0;
  int facets_length = 0;
  int number_of_vertices = 0;

  s21_parse_f_line(line, &facets, &number_of_lines, &facets_length,
                   number_of_vertices);

  ck_assert_int_eq(number_of_lines, 0);
  ck_assert_int_eq(facets_length, 0);
}
END_TEST

Suite *lib_suite(void) {
  Suite *s;
  s = suite_create("Check");

  TCase *s21_scan_f_line;
  s21_scan_f_line = tcase_create("s21_scan_f_line");
  suite_add_tcase(s, s21_scan_f_line);
  tcase_add_test(s21_scan_f_line, TEST_1);
  tcase_add_test(s21_scan_f_line, TEST_2);
  tcase_add_test(s21_scan_f_line, TEST_3);
  tcase_add_test(s21_scan_f_line, TEST_4);
  tcase_add_test(s21_scan_f_line, TEST_17);
  tcase_add_test(s21_scan_f_line, TEST_19);

  TCase *s21_parse_f_line;
  s21_parse_f_line = tcase_create("s21_parse_f_line");
  suite_add_tcase(s, s21_parse_f_line);
  tcase_add_test(s21_parse_f_line, TEST_5);

  TCase *s21_find_max_min_values;
  s21_find_max_min_values = tcase_create("s21_find_max_min_values");
  suite_add_tcase(s, s21_find_max_min_values);
  tcase_add_test(s21_find_max_min_values, TEST_6);
  tcase_add_test(s21_find_max_min_values, TEST_7);

  TCase *s21_shift;
  s21_shift = tcase_create("s21_shift");
  suite_add_tcase(s, s21_shift);
  tcase_add_test(s21_shift, TEST_8);

  TCase *s21_scale;
  s21_scale = tcase_create("s21_scale");
  suite_add_tcase(s, s21_scale);
  tcase_add_test(s21_scale, TEST_9);

  TCase *s21_initial_scale;
  s21_initial_scale = tcase_create("s21_initial_scale");
  suite_add_tcase(s, s21_initial_scale);
  tcase_add_test(s21_initial_scale, TEST_10);
  tcase_add_test(s21_initial_scale, TEST_11);
  tcase_add_test(s21_initial_scale, TEST_12);

  TCase *s21_rotate;
  s21_rotate = tcase_create("s21_rotate");
  suite_add_tcase(s, s21_rotate);
  tcase_add_test(s21_rotate, TEST_13);
  tcase_add_test(s21_rotate, TEST_14);
  tcase_add_test(s21_rotate, TEST_15);

  TCase *s21_center_vertices;
  s21_center_vertices = tcase_create("s21_center_vertices");
  suite_add_tcase(s, s21_center_vertices);
  tcase_add_test(s21_center_vertices, TEST_16);

  TCase *s21_parse_file;
  s21_parse_file = tcase_create("s21_parse_file");
  suite_add_tcase(s, s21_parse_file);
  tcase_add_test(s21_parse_file, TEST_18);

  return s;
}

int main(void) {
  Suite *s;
  SRunner *sr;
  int nf = 0;

  s = lib_suite();
  sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);
  srunner_run_all(sr, CK_VERBOSE);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
