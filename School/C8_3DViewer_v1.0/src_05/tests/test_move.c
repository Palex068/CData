#include "tests.h"

START_TEST(test_1) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 10;
  figure.trv.move_vector[y] = 2;
  figure.trv.move_vector[z] = 1.5;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 12.712726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -0.398764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -0.99264, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          3.971338, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          3.63977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          2.864798, 0.000006);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_2) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 0.667;
  figure.trv.move_vector[y] = -8.0;
  figure.trv.move_vector[z] = 2.6;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 3.379726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -10.398764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 0.10736, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -5.361662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -6.36023, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          3.964798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_3) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 3.75;
  figure.trv.move_vector[y] = -3.667;
  figure.trv.move_vector[z] = -0.875;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 6.462726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -6.065764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -3.36764, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -2.278662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -2.02723, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.489798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_4) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 2.75;
  figure.trv.move_vector[y] = 1.667;
  figure.trv.move_vector[z] = -0.8;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 5.462726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -0.731764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -3.29264, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -3.278662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          3.30677, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.564798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_5) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 1.5;
  figure.trv.move_vector[y] = -6.0;
  figure.trv.move_vector[z] = 3.2;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 4.212726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -8.398764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 0.70736, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -4.528662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -4.36023, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          4.564798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_6) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 0.667;
  figure.trv.move_vector[y] = 1.0;
  figure.trv.move_vector[z] = 2.429;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 3.379726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -1.398764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -0.06364, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -5.361662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          2.63977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          3.793798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_7) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 2.333;
  figure.trv.move_vector[y] = 8.0;
  figure.trv.move_vector[z] = 9.0;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 5.045726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 5.601236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 6.50736, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -3.695662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          9.63977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          10.364798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_8) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 6.5;
  figure.trv.move_vector[y] = -4.286;
  figure.trv.move_vector[z] = -2.833;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 9.212726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -6.684764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -5.32564, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.471338, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -2.64623, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -1.468202, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_9) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -1.667;
  figure.trv.move_vector[y] = -2.5;
  figure.trv.move_vector[z] = -0.429;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 1.045726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -4.898764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.92164, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -7.695662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.86023, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.935798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_10) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -3.0;
  figure.trv.move_vector[y] = -10.333;
  figure.trv.move_vector[z] = -0.25;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -0.287274, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -12.731764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.74264, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -9.028662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -8.69323, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          1.114798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_11) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 3.5;
  figure.trv.move_vector[y] = 14.333;
  figure.trv.move_vector[z] = -0.143;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 6.212726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 11.934236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.63564, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -2.528662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          15.97277, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          1.221798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_12) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -2.667;
  figure.trv.move_vector[y] = 12.667;
  figure.trv.move_vector[z] = 9.0;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 0.045726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 10.268236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 6.50736, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -8.695662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          14.30677, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          10.364798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_13) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 0.8;
  figure.trv.move_vector[y] = -1.25;
  figure.trv.move_vector[z] = -2.833;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 3.512726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -3.648764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -5.32564, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -5.228662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          0.38977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -1.468202, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_14) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 2.0;
  figure.trv.move_vector[y] = 15.0;
  figure.trv.move_vector[z] = -0.625;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 4.712726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 12.601236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -3.11764, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -4.028662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          16.63977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.739798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_15) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 6.5;
  figure.trv.move_vector[y] = 8.25;
  figure.trv.move_vector[z] = 3.714;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 9.212726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 5.851236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 1.22136, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.471338, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          9.88977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.078798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_16) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -1.25;
  figure.trv.move_vector[y] = -2.5;
  figure.trv.move_vector[z] = 6.0;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 1.462726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -4.898764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 3.50736, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -7.278662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.86023, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          7.364798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_17) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -0.6;
  figure.trv.move_vector[y] = 5.167;
  figure.trv.move_vector[z] = -2.5;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 2.112726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 2.768236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -4.99264, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -6.628662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          6.80677, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -1.135202, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_18) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -1.75;
  figure.trv.move_vector[y] = -1.75;
  figure.trv.move_vector[z] = 3.714;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 0.962726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -4.148764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 1.22136, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -7.778662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.11023, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.078798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_19) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = -1.0;
  figure.trv.move_vector[y] = 6.333;
  figure.trv.move_vector[z] = 1.75;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 1.712726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 3.934236, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -0.74264, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -7.028662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          7.97277, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          3.114798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_20) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 5.0;
  figure.trv.move_vector[y] = -19.0;
  figure.trv.move_vector[z] = 1.167;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 7.712726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -21.398764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -1.32564, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -1.028662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -17.36023, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          2.531798, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_21) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.trv.move_vector[x] = 3.2;
  figure.trv.move_vector[y] = -0.4;
  figure.trv.move_vector[z] = 6.0;

  move_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 5.912726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -2.798764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 3.50736, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -2.828662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          1.23977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          7.364798, 0.000006);

  destroy_figure(&figure);
}
END_TEST

Suite *test_move(void) {
  Suite *suite = suite_create("test_move");
  TCase *tcase_core = tcase_create("test_move");

  tcase_add_test(tcase_core, test_1);
  tcase_add_test(tcase_core, test_2);
  tcase_add_test(tcase_core, test_3);
  tcase_add_test(tcase_core, test_4);
  tcase_add_test(tcase_core, test_5);
  tcase_add_test(tcase_core, test_6);
  tcase_add_test(tcase_core, test_7);
  tcase_add_test(tcase_core, test_8);
  tcase_add_test(tcase_core, test_9);
  tcase_add_test(tcase_core, test_10);
  tcase_add_test(tcase_core, test_11);
  tcase_add_test(tcase_core, test_12);
  tcase_add_test(tcase_core, test_13);
  tcase_add_test(tcase_core, test_14);
  tcase_add_test(tcase_core, test_15);
  tcase_add_test(tcase_core, test_16);
  tcase_add_test(tcase_core, test_17);
  tcase_add_test(tcase_core, test_18);
  tcase_add_test(tcase_core, test_19);
  tcase_add_test(tcase_core, test_20);
  tcase_add_test(tcase_core, test_21);

  suite_add_tcase(suite, tcase_core);

  return suite;
}