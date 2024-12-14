#include "tests.h"

START_TEST(test_1) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 20;
  figure.alpha_y = 0;
  figure.alpha_z = 0;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 2.712726, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -1.40156774, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -3.16274102, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -6.028662, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          1.074091, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          1.843325, 0.000006);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_2) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 0;
  figure.alpha_y = 50;
  figure.alpha_z = 0;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -0.165766, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -2.398764, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -3.680306, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -2.829653, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          1.63977, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.495498, 0.000006);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_3) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 0;
  figure.alpha_y = 0;
  figure.alpha_z = 185;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -2.911469, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 2.153206, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.49264, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          6.148636, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -1.108097, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          1.364798, 0.000006);

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_4) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -274;
  figure.alpha_y = 216;
  figure.alpha_z = -164;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 1.298613, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -2.040332, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 3.671084, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -4.054066, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          0.134861, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -4.94395, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_5) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 333;
  figure.alpha_y = -86;
  figure.alpha_z = 240;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -3.490201, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 0.492694, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 2.627158, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          2.247393, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.268703, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -5.981079, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_6) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 306;
  figure.alpha_y = 184;
  figure.alpha_z = 257;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -2.722518, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 3.439885, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -0.285115, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.653896, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -6.360675, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.102578, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_7) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -159;
  figure.alpha_y = 74;
  figure.alpha_z = 122;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -3.161128, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 2.518557, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -1.729261, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          2.712419, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -2.374899, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.281943, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_8) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 118;
  figure.alpha_y = -146;
  figure.alpha_z = -358;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -1.834036, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 3.265004, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 2.302665, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          4.612817, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -1.814991, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -4.040299, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_9) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 62;
  figure.alpha_y = -263;
  figure.alpha_z = -180;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 3.594295, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -1.074719, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.291774, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -2.807706, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          0.43522, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.729193, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_10) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 139;
  figure.alpha_y = 91;
  figure.alpha_z = -4;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 0.499824, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 3.419152, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.717679, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.001813, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -2.138273, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          6.026945, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_11) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -186;
  figure.alpha_y = 273;
  figure.alpha_z = 264;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 2.849435, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 1.795206, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 2.825626, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -1.854544, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.678643, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -6.082466, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_12) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 254;
  figure.alpha_y = 74;
  figure.alpha_z = 69;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 2.918634, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 2.762214, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -1.782683, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -2.070924, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -2.995323, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.256957, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_13) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -113;
  figure.alpha_y = 254;
  figure.alpha_z = -18;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -4.039588, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -0.114519, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 1.730554, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          3.638075, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.534808, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -5.232081, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_14) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 56;
  figure.alpha_y = 159;
  figure.alpha_z = 16;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -3.799544, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -0.335159, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 2.185712, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          6.200553, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          1.554814, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.178846, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_15) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -220;
  figure.alpha_y = 138;
  figure.alpha_z = 252;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 3.8184, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 0.620406, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -2.088331, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -3.415207, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -3.60706, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          4.027625, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_16) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -167;
  figure.alpha_y = -60;
  figure.alpha_z = -292;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -2.102088, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -0.460377, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 3.833469, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.618642, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -1.91437, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -6.070318, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_17) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 30;
  figure.alpha_y = 103;
  figure.alpha_z = -78;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -1.620072, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 3.62461, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -1.887797, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          1.409061, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -3.08105, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.423833, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_18) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -322;
  figure.alpha_y = 259;
  figure.alpha_z = 170;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], -2.755012, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 0.846898, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 3.31947, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.804298, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.600694, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -6.315739, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_19) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 206;
  figure.alpha_y = 104;
  figure.alpha_z = 336;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 2.750937, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -0.060877, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -3.428534, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -0.748244, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -0.625244, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          6.320244, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_20) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -348;
  figure.alpha_y = -52;
  figure.alpha_z = -1;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 3.951919, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -1.897356, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 0.329521, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -5.008436, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          1.407803, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -3.718863, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_21) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = 235;
  figure.alpha_y = 300;
  figure.alpha_z = 98;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 0.879877, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -1.475413, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 4.046626, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -0.012449, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -1.186408, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          -6.283993, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_22) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -331;
  figure.alpha_y = -202;
  figure.alpha_z = -282;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 0.086799, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], -3.870145, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], 2.083422, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          0.561419, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          6.356828, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          0.414527, 0.000006);

  destroy_figure(&figure);
}
END_TEST
START_TEST(test_23) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);
  ck_assert_msg(error == OK, "init failed");

  figure.alpha_x = -177;
  figure.alpha_y = -290;
  figure.alpha_z = 35;

  rotate_figure(&figure);

  ck_assert_double_eq_tol(figure.vertex[0 * 3 + x], 1.47357, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + y], 3.796886, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[0 * 3 + z], -1.654826, 0.000006);

  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + x],
                          -1.905928, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + y],
                          -3.246394, 0.000006);
  ck_assert_double_eq_tol(figure.vertex[(figure.amount_vertex - 1) * 3 + z],
                          5.169589, 0.000006);

  destroy_figure(&figure);
}
END_TEST

Suite *test_rotate(void) {
  Suite *suite = suite_create("test_rotate");
  TCase *tcase_core = tcase_create("test_rotate");

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
  tcase_add_test(tcase_core, test_22);
  tcase_add_test(tcase_core, test_23);

  suite_add_tcase(suite, tcase_core);

  return suite;
}