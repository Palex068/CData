#include "tests.h"

START_TEST(test_center_align) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");
  double check_x = figure.vertex[x];
  double check_y = figure.vertex[y];
  double check_z = figure.vertex[z];
  double x_center = (figure.x_min + figure.x_max) / 2.0;
  double y_center = (figure.y_min + figure.y_max) / 2.0;
  double z_center = (figure.z_min + figure.z_max) / 2.0;

  align_to_center(&figure);

  ck_assert_msg(figure.vertex[x] == (check_x - x_center), "aligning failed");
  ck_assert_msg(figure.vertex[y] == (check_y - y_center), "aligning failed");
  ck_assert_msg(figure.vertex[z] == (check_z - z_center), "aligning failed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_center_align_2) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/al.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");
  double check_x = figure.vertex[x];
  double check_y = figure.vertex[y];
  double check_z = figure.vertex[z];
  double x_center = (figure.x_min + figure.x_max) / 2.0;
  double y_center = (figure.y_min + figure.y_max) / 2.0;
  double z_center = (figure.z_min + figure.z_max) / 2.0;

  align_to_center(&figure);

  ck_assert_msg(figure.vertex[x] == (check_x - x_center), "aligning failed");
  ck_assert_msg(figure.vertex[y] == (check_y - y_center), "aligning failed");
  ck_assert_msg(figure.vertex[z] == (check_z - z_center), "aligning failed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_1) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = 1.0;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x * scale, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y * scale, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z * scale, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_2) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = 2.0;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x * scale, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y * scale, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z * scale, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_3) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = 2.0;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x * scale, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y * scale, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z * scale, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_4) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = 0.9;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x * scale, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y * scale, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z * scale, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_5) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = 0.8;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x * scale, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y * scale, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z * scale, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_6) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = 0.1;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x * scale, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y * scale, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z * scale, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_7) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  double _x, _y, _z;
  _x = figure.vertex[0];
  _y = figure.vertex[1];
  _z = figure.vertex[2];
  double scale = -0.1;

  scale_figure(&figure, scale);

  ck_assert_ldouble_eq_tol(_x, figure.vertex[0], 0.000001);
  ck_assert_ldouble_eq_tol(_y, figure.vertex[1], 0.000001);
  ck_assert_ldouble_eq_tol(_z, figure.vertex[2], 0.000001);

  destroy_figure(&figure);
}
END_TEST

Suite *test_scale(void) {
  Suite *suite = suite_create("test_scale");
  TCase *tcase_core = tcase_create("test_scale");

  tcase_add_test(tcase_core, test_center_align);
  tcase_add_test(tcase_core, test_center_align_2);
  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);

  suite_add_tcase(suite, tcase_core);

  return suite;
}