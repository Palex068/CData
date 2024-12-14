#include "tests.h"

START_TEST(init_test) {
  int error = OK;
  Figure figure;
  init_figure(&figure);

  ck_assert_msg(error == OK, "init failed");

  ck_assert_msg(figure.vertex == NULL, "figure.vertex init failed");
  ck_assert_msg(figure.polygon == NULL, "figure.polygon init failed");

  ck_assert_msg(figure.amount_vertex == 0, "figure.amount_vertex init failed");
  ck_assert_msg(figure.amount_polygon == 0,
                "figure.amount_polygon init failed");

  ck_assert_msg(figure.x_max == 0, "figure.x_max init failed");
  ck_assert_msg(figure.y_max == 0, "figure.y_max init failed");
  ck_assert_msg(figure.z_max == 0, "figure.z_max init failed");
  ck_assert_msg(figure.x_min == 0, "figure.x_min init failed");
  ck_assert_msg(figure.y_min == 0, "figure.y_min init failed");
  ck_assert_msg(figure.z_min == 0, "figure.z_min init failed");

  ck_assert_msg(figure.cur_scale == 1, "figure.cur_scale init failed");

  ck_assert_msg(figure.trv.tranformation_matrix != NULL,
                "figure.trv.tranformation_matrix init failed");
  ck_assert_msg(figure.trv.rotation_matrix_x != NULL,
                "figure.trv.tranformation_matrix init failed");
  ck_assert_msg(figure.trv.rotation_matrix_y != NULL,
                "figure.trv.tranformation_matrix init failed");
  ck_assert_msg(figure.trv.rotation_matrix_z != NULL,
                "figure.trv.tranformation_matrix init failed");

  ck_assert_msg(figure.trv.move_vector[x] == 0,
                "figure.trv.move_vector[x] init failed");
  ck_assert_msg(figure.trv.move_vector[y] == 0,
                "figure.trv.move_vector[y] init failed");
  ck_assert_msg(figure.trv.move_vector[z] == 0,
                "figure.trv.move_vector[z] init failed");
  destroy_figure(&figure);
}
END_TEST

// GOOD FILES WITH NO ERRORS
START_TEST(test_1) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/airboat.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 5797, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 6273, "wrong polygon amount parsed");

  ck_assert_msg(figure.vertex[0 + 0] == 2.712726,
                "wrong first line vertex value [0]");
  ck_assert_msg(figure.vertex[0 + 1] == -2.398764,
                "wrong first line vertex value [1]");
  ck_assert_msg(figure.vertex[0 + 2] == -2.492640,
                "wrong first line vertex value [2]");

  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 0] == -6.028662,
                "wrong last line vertex value [0]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 1] == 1.639770,
                "wrong last line vertex value [1]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 2] == 1.364798,
                "wrong last line vertex value [2]");

  ck_assert_msg(figure.polygon[0].vertex_p[0] == 5049 - 1,
                "wrong polygon value [first][0]");
  ck_assert_msg(figure.polygon[0].vertex_p[1] == 5019 - 1,
                "wrong polygon value [first][1]");

  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 2] == 5047 - 1,
      "wrong polygon value [first][last - 1]");
  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 1] == 5049 - 1,
      "wrong polygon value [first][last]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1].vertex_p[0] == 4561 - 1,
      "wrong polygon value [last][0]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1].vertex_p[1] == 4560 - 1,
      "wrong polygon value [last][1]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        2] == 4562 - 1,
      "wrong polygon value [last][last - 1]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        1] == 4561 - 1,
      "wrong polygon value [last][last]");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_2) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/al.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 3618, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 3442, "wrong polygon amount parsed");

  ck_assert_msg(figure.vertex[0 + 0] == 0.786019,
                "wrong first line vertex value [0]");
  ck_assert_msg(figure.vertex[0 + 1] == -2.928538,
                "wrong first line vertex value [1]");
  ck_assert_msg(figure.vertex[0 + 2] == 0.601628,
                "wrong first line vertex value [2]");

  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 0] == 0.496372,
                "wrong last line vertex value [0]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 1] == -0.571387,
                "wrong last line vertex value [1]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 2] == -0.109300,
                "wrong last line vertex value [2]");

  ck_assert_msg(figure.polygon[0].vertex_p[0] == 29 - 1,
                "wrong polygon value [first][0]");
  ck_assert_msg(figure.polygon[0].vertex_p[1] == 24 - 1,
                "wrong polygon value [first][1]");

  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 2] == 48 - 1,
      "wrong polygon value [first][last - 1]");
  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 1] == 29 - 1,
      "wrong polygon value [first][last]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1].vertex_p[0] == 3477 - 1,
      "wrong polygon value [last][0]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1].vertex_p[1] == 3545 - 1,
      "wrong polygon value [last][1]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        2] == 3544 - 1,
      "wrong polygon value [last][last - 1]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        1] == 3477 - 1,
      "wrong polygon value [last][last]");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_3) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/icosahedron.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 12, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 20, "wrong polygon amount parsed");

  ck_assert_msg(figure.vertex[0 + 0] == 0, "wrong first line vertex value [0]");
  ck_assert_msg(figure.vertex[0 + 1] == -0.525731,
                "wrong first line vertex value [1]");
  ck_assert_msg(figure.vertex[0 + 2] == 0.850651,
                "wrong first line vertex value [2]");

  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 0] == 0,
                "wrong last line vertex value [0]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 1] == 0.525731,
                "wrong last line vertex value [1]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 2] == 0.850651,
                "wrong last line vertex value [2]");

  ck_assert_msg(figure.polygon[0].vertex_p[0] == 2 - 1,
                "wrong polygon value [first][0]");
  ck_assert_msg(figure.polygon[0].vertex_p[1] == 3 - 1,
                "wrong polygon value [first][1]");

  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 2] == 7 - 1,
      "wrong polygon value [first][last - 1]");
  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 1] == 2 - 1,
      "wrong polygon value [first][last]");

  ck_assert_msg(figure.polygon[figure.amount_polygon - 1].vertex_p[0] == 5 - 1,
                "wrong polygon value [last][0]");
  ck_assert_msg(figure.polygon[figure.amount_polygon - 1].vertex_p[1] == 9 - 1,
                "wrong polygon value [last][1]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        2] == 0,
      "wrong polygon value [last][last - 1]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        1] == 5 - 1,
      "wrong polygon value [last][last]");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_4) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/pyramid.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 5, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 6, "wrong polygon amount parsed");

  ck_assert_msg(figure.vertex[0 + 0] == 0, "wrong first line vertex value [0]");
  ck_assert_msg(figure.vertex[0 + 1] == 0, "wrong first line vertex value [1]");
  ck_assert_msg(figure.vertex[0 + 2] == 0, "wrong first line vertex value [2]");

  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 0] == 0.5,
                "wrong last line vertex value [0]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 1] == 0.5,
                "wrong last line vertex value [1]");
  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 2] == 1.6,
                "wrong last line vertex value [2]");

  ck_assert_msg(figure.polygon[0].vertex_p[0] == 5 - 1,
                "wrong polygon value [first][0]");
  ck_assert_msg(figure.polygon[0].vertex_p[1] == 2 - 1,
                "wrong polygon value [first][1]");

  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 2] == 3 - 1,
      "wrong polygon value [first][last - 1]");
  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 1] == 5 - 1,
      "wrong polygon value [first][last]");

  ck_assert_msg(figure.polygon[figure.amount_polygon - 1].vertex_p[0] == 6 - 1,
                "wrong polygon value [last][0]");
  ck_assert_msg(figure.polygon[figure.amount_polygon - 1].vertex_p[1] == 4 - 1,
                "wrong polygon value [last][1]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        2] == 3 - 1,
      "wrong polygon value [last][last - 1]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        1] == 6 - 1,
      "wrong polygon value [last][last]");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_5) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/trumpet.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 11908, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 11362, "wrong polygon amount parsed");

  ck_assert_msg(figure.vertex[0 + 0] == 9.804816,
                "wrong first line vertex value [0]");
  ck_assert_msg(figure.vertex[0 + 1] == -554.003418,
                "wrong first line vertex value [1]");
  ck_assert_msg(figure.vertex[0 + 2] == 228.321411,
                "wrong first line vertex value [2]");

  ck_assert_msg(figure.vertex[(figure.amount_vertex - 1) * 3 + 0] == -51.853733,
                "wrong last line vertex value [0]");
  ck_assert_msg(
      figure.vertex[(figure.amount_vertex - 1) * 3 + 1] == -403.707306,
      "wrong last line vertex value [1]");
  ck_assert_msg(
      figure.vertex[(figure.amount_vertex - 1) * 3 + 2] == -164.112930,
      "wrong last line vertex value [2]");

  ck_assert_msg(figure.polygon[0].vertex_p[0] == 40 - 1,
                "wrong polygon value [first][0]");
  ck_assert_msg(figure.polygon[0].vertex_p[1] == 38 - 1,
                "wrong polygon value [first][1]");

  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 2] == 2 - 1,
      "wrong polygon value [first][last - 1]");
  ck_assert_msg(
      figure.polygon[0].vertex_p[figure.polygon[0].amount_p - 1] == 40 - 1,
      "wrong polygon value [first][last]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1].vertex_p[0] == 11866 - 1,
      "wrong polygon value [last][0]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1].vertex_p[1] == 11900 - 1,
      "wrong polygon value [last][1]");

  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        2] == 11867 - 1,
      "wrong polygon value [last][last - 1]");
  ck_assert_msg(
      figure.polygon[figure.amount_polygon - 1]
              .vertex_p[figure.polygon[figure.amount_polygon - 1].amount_p -
                        1] == 11866 - 1,
      "wrong polygon value [last][last]");

  destroy_figure(&figure);
}
END_TEST

// WRONG OBJ FILES OR WITH ERRORS
START_TEST(test_6) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_1.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 0, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 0, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_7) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_2.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 0, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 0, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_8) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_3.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 0, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 0, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_9) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_4.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 0, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 0, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_10) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_5.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 2, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 2, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_11) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_6.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 0, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 9, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

START_TEST(test_12) {
  int error = OK;
  Figure figure;
  const char *file = "obj_files/tests_only/wr_test_7.obj";

  error = parse_obj_file(file, &figure);

  ck_assert_msg(error == OK, "init failed");
  ck_assert_msg(figure.amount_vertex == 0, "wrong vertexes amount parsed");
  ck_assert_msg(figure.amount_polygon == 3, "wrong polygon amount parsed");

  destroy_figure(&figure);
}
END_TEST

Suite *test_parser(void) {
  Suite *suite = suite_create("test_parser");
  TCase *tcase_core = tcase_create("test_parser");

  tcase_add_test(tcase_core, init_test);
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

  suite_add_tcase(suite, tcase_core);

  return suite;
}
