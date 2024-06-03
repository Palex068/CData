#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "s21_matrix_oop.h"

TEST(S21MatrixTest, Test_Equal_1) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 3;
  matrix_2(1, 1) = 4;

  ASSERT_TRUE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixTest, Test_Equal_2) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 8;
  matrix_2(1, 1) = 4;

  ASSERT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixTest, Test_Equal_3) {
  S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;
  matrix_1(2, 0) = 3;
  matrix_1(2, 1) = 4;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 8;
  matrix_2(1, 1) = 4;

  ASSERT_FALSE(matrix_1.EqMatrix(matrix_2));
}

TEST(S21MatrixTest, Test_SumMatrix_1) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  matrix_1.SumMatrix(matrix_2);
  ASSERT_EQ(matrix_1(0, 0), 6);
  ASSERT_EQ(matrix_1(0, 1), 8);
  ASSERT_EQ(matrix_1(1, 0), 10);
  ASSERT_EQ(matrix_1(1, 1), 12);
}

TEST(S21MatrixTest, Test_SumMatrix_2) {
  S21Matrix matrix_1(5, 5);
  matrix_1(0, 4) = 3;
  matrix_1(1, 1) = 75;
  matrix_1(1, 3) = 9;
  matrix_1(3, 1) = 12;
  matrix_1(4, 2) = 4;

  S21Matrix matrix_2(5, 5);
  matrix_2(0, 4) = 5;
  matrix_2(0, 2) = 9;
  matrix_2(1, 1) = 30;
  matrix_2(1, 3) = 1;
  matrix_2(3, 1) = 100;
  matrix_2(4, 2) = 5;

  matrix_1.SumMatrix(matrix_2);
  ASSERT_EQ(matrix_1(0, 4), 8);
  ASSERT_EQ(matrix_1(0, 2), 9);
  ASSERT_EQ(matrix_1(1, 1), 105);
  ASSERT_EQ(matrix_1(1, 3), 10);
  ASSERT_EQ(matrix_1(3, 1), 112);
  ASSERT_EQ(matrix_1(4, 2), 9);
}

TEST(S21MatrixTest, Test_SumMatrix_Error_1) {
  S21Matrix matrix_1(2, 7);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;

  ASSERT_THROW(matrix_1.SumMatrix(matrix_2), std::out_of_range);
}

TEST(S21MatrixTest, Test_SumMatrix_Error_2) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(1, 2);
  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;

  ASSERT_THROW(matrix_1.SumMatrix(matrix_2), std::out_of_range);
}

TEST(S21MatrixTest, Test_SubMatrix_1) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  matrix_1.SubMatrix(matrix_2);

  ASSERT_EQ(matrix_1(0, 0), -4);
  ASSERT_EQ(matrix_1(0, 1), -4);
  ASSERT_EQ(matrix_1(1, 0), -4);
  ASSERT_EQ(matrix_1(1, 1), -4);
}

TEST(S21MatrixTest, Test_SubMatrix_2) {
  S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;
  matrix_1(2, 0) = 5;
  matrix_1(2, 1) = 6;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  EXPECT_ANY_THROW(matrix_1.SubMatrix(matrix_2));
}

TEST(S21MatrixTest, Test_MulNumber_1) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  matrix_1.MulNumber(2);

  ASSERT_EQ(matrix_1(0, 0), 2);
  ASSERT_EQ(matrix_1(0, 1), 4);
  ASSERT_EQ(matrix_1(1, 0), 6);
}

TEST(S21MatrixTest, Test_MulNumber_2) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 5;
  matrix_1(1, 1) = 4;

  matrix_1.MulNumber(0.1);
  ASSERT_EQ(matrix_1(0, 0), 0.1);
  ASSERT_EQ(matrix_1(0, 1), 0.2);
  ASSERT_EQ(matrix_1(1, 0), 0.5);
  ASSERT_EQ(matrix_1(1, 1), 0.4);
}

TEST(S21MatrixTest, Test_MulMatrix_1) {
  S21Matrix matrix_1(5, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(2, 5);

  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  matrix_1.MulMatrix(matrix_2);

  ASSERT_EQ(matrix_1(0, 0), 19);
  ASSERT_EQ(matrix_1(0, 1), 22);
  ASSERT_EQ(matrix_1(1, 0), 43);
  ASSERT_EQ(matrix_1(1, 1), 50);
}

TEST(S21MatrixTest, Test_MulMatrix_2) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  matrix_1.MulMatrix(matrix_2);

  ASSERT_EQ(matrix_1(0, 0), 19);
  ASSERT_EQ(matrix_1(0, 1), 22);
  ASSERT_EQ(matrix_1(1, 0), 43);
  ASSERT_EQ(matrix_1(1, 1), 50);
}

TEST(S21MatrixTest, Test_MulMatrix_3) {
  S21Matrix matrix_1(2, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 5;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;
  matrix_1(1, 2) = 6;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 5;
  matrix_2(0, 1) = 6;
  matrix_2(1, 0) = 7;
  matrix_2(1, 1) = 8;

  EXPECT_ANY_THROW(matrix_1.MulMatrix(matrix_2));
}

TEST(S21MatrixTest, Test_Transpose_1) {
  S21Matrix matrix_1(3, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 3;
  matrix_1(1, 1) = 4;
  matrix_1(2, 0) = 5;
  matrix_1(2, 1) = 6;

  S21Matrix matrix_2 = matrix_1.Transpose();

  ASSERT_EQ(matrix_2(0, 0), 1);
  ASSERT_EQ(matrix_2(0, 1), 3);
  ASSERT_EQ(matrix_2(0, 2), 5);
  ASSERT_EQ(matrix_2(1, 0), 2);
  ASSERT_EQ(matrix_2(1, 1), 4);
  ASSERT_EQ(matrix_2(1, 2), 6);
}

TEST(S21MatrixTest, Test_CalcComlements_1) {
  S21Matrix matrix_1(3, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  S21Matrix matrix_2 = matrix_1.CalcComplements();

  ASSERT_EQ(matrix_2(0, 0), -3);
  ASSERT_EQ(matrix_2(0, 1), 6);
  ASSERT_EQ(matrix_2(0, 2), -3);
}

TEST(S21MatrixTest, Test_CalcComlements_2) {
  S21Matrix matrix_1(2, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;

  EXPECT_ANY_THROW(matrix_1.CalcComplements());
}

TEST(S21MatrixTest, Test_Determinant_1) {
  S21Matrix matrix_1(3, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;
  matrix_1(2, 0) = 7;
  matrix_1(2, 1) = 8;
  matrix_1(2, 2) = 9;

  double matrix_2 = matrix_1.Determinant();

  ASSERT_EQ(matrix_2, 0);
}

TEST(S21MatrixTest, Test_Determinant_2) {
  S21Matrix matrix_1(2, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;

  EXPECT_ANY_THROW(matrix_1.Determinant());
}

TEST(S21MatrixTest, Test_Determinant_3) {
  S21Matrix matrix_1(1, 1);
  matrix_1(0, 0) = 1;
  ASSERT_EQ(matrix_1.Determinant(), 1);
}

TEST(S21MatrixTest, Test_Constructor_Default) {
  S21Matrix matrix_1;
  EXPECT_EQ(matrix_1.GetColumns(), 3);
  EXPECT_EQ(matrix_1.GetRows(), 3);
}

TEST(S21MatrixTest, Test_Constructor_Parametrized) {
  S21Matrix matrix_1(100, 200);
  EXPECT_EQ(matrix_1.GetRows(), 100);
  EXPECT_EQ(matrix_1.GetColumns(), 200);
}

TEST(S21MatrixTest, Test_Constructor_Parametrized_2) {
  EXPECT_ANY_THROW(S21Matrix matrix_1(-1, -1));
}

TEST(S21MatrixTest, Test_Constructor_Copy) {
  S21Matrix matrix_1(12, 12);
  S21Matrix matrix_2(matrix_1);

  EXPECT_EQ(matrix_2.GetColumns(), 12);
  EXPECT_EQ(matrix_2.GetRows(), 12);
}

TEST(S21MatrixTest, Test_Constructor_Move) {
  S21Matrix matrix_1(12, 12);
  S21Matrix matrix_2(std::move(matrix_1));

  EXPECT_EQ(matrix_1.GetColumns(), 0);
  EXPECT_EQ(matrix_1.GetRows(), 0);
  EXPECT_EQ(matrix_2.GetColumns(), 12);
  EXPECT_EQ(matrix_2.GetRows(), 12);
}

TEST(S21MatrixTest, Test_SetRows_More) {
  S21Matrix matrix_1(2, 2);
  matrix_1(1, 1) = 6.9;

  matrix_1.SetRows(5);

  EXPECT_EQ(matrix_1.GetRows(), 5);
  EXPECT_EQ(matrix_1(1, 1), 6.9);
}

TEST(S21MatrixTest, Test_SetRows_Less) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 6.9;

  matrix_1.SetRows(1);
  EXPECT_EQ(matrix_1.GetRows(), 1);
  EXPECT_EQ(matrix_1(0, 0), 6.9);
}

TEST(S21MatrixTest, Test_SetRows_Zero) {
  S21Matrix matrix_1;

  EXPECT_ANY_THROW(matrix_1.SetRows(0));
}

TEST(S21MatrixTest, Test_SetColumns_More) {
  S21Matrix matrix_1(2, 2);
  matrix_1(1, 1) = 6.9;

  matrix_1.SetColumns(5);
  EXPECT_EQ(matrix_1.GetColumns(), 5);
  EXPECT_EQ(matrix_1(1, 1), 6.9);
}

TEST(S21MatrixTest, Test_SetColumns_Less) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 6.9;

  matrix_1.SetColumns(1);

  EXPECT_EQ(matrix_1.GetColumns(), 1);
  EXPECT_EQ(matrix_1(0, 0), 6.9);
}

TEST(S21MatrixTest, Test_SetColumns_Zero) {
  S21Matrix matrix_1;

  EXPECT_ANY_THROW(matrix_1.SetColumns(0));
}

TEST(S21MatrixTest, Test_OperatorOverload_Add) {
  S21Matrix matrix_1(2, 2);

  matrix_1(0, 0) = 1;
  matrix_1(1, 1) = 1;

  S21Matrix matrix_2(2, 2);

  matrix_2(0, 0) = 1;
  matrix_2(1, 1) = 1;

  S21Matrix result = matrix_1 + matrix_2;

  EXPECT_EQ(result(0, 0), 2);
  EXPECT_EQ(result(1, 1), 2);
}

TEST(S21MatrixTest, Test_OperatorOverload_EqAdd) {
  S21Matrix matrix_1(2, 2);

  matrix_1(0, 0) = 1;
  matrix_1(1, 1) = 1;

  S21Matrix matrix_2(2, 2);

  matrix_2(0, 0) = 1;
  matrix_2(1, 1) = 1;

  matrix_1 += matrix_2;

  EXPECT_EQ(matrix_1(0, 0), 2);
  EXPECT_EQ(matrix_1(1, 1), 2);
}

TEST(S21MatrixTest, Test_SubMatrix_3) {
  S21Matrix matrix_1(2, 2);

  matrix_1(0, 0) = 1;
  matrix_1(1, 1) = 1;

  S21Matrix matrix_2(2, 2);
  matrix_2(0, 0) = 1;
  matrix_2(1, 1) = 1;

  matrix_1.SubMatrix(matrix_2);

  EXPECT_EQ(matrix_1(0, 0), 0);
  EXPECT_EQ(matrix_1(1, 1), 0);
}

TEST(S21MatrixTest, Test_OperatorOverload_EqSub) {
  S21Matrix matrix_1(2, 2);

  matrix_1(0, 0) = 1;
  matrix_1(1, 1) = 1;

  S21Matrix matrix_2(2, 2);

  matrix_2(0, 0) = 1;
  matrix_2(1, 1) = 1;

  matrix_1 -= matrix_2;

  EXPECT_EQ(matrix_1(0, 0), 0);
  EXPECT_EQ(matrix_1(1, 1), 0);
}

TEST(S21MatrixTest, Test_OperatorOverload_Sub) {
  S21Matrix matrix_1(2, 2);

  matrix_1(0, 0) = 1;
  matrix_1(1, 1) = 1;

  S21Matrix matrix_2(2, 2);

  matrix_2(0, 0) = 1;
  matrix_2(1, 1) = 1;

  S21Matrix result = matrix_1 - matrix_2;

  EXPECT_EQ(result(0, 0), 0);
  EXPECT_EQ(result(1, 1), 0);
}

TEST(S21MatrixTest, Test_Inverse_1) {
  const int size = 3;
  S21Matrix matrix_1(size, size);
  S21Matrix matrix_2(size, size);

  matrix_2(0, 0) = 44300.0 / 367429.0;
  matrix_2(0, 1) = -236300.0 / 367429.0;
  matrix_2(0, 2) = 200360.0 / 367429.0;
  matrix_2(1, 0) = 20600.0 / 367429.0;
  matrix_2(1, 1) = 56000.0 / 367429.0;
  matrix_2(1, 2) = -156483.0 / 367429.0;
  matrix_2(2, 0) = 30900.0 / 367429.0;
  matrix_2(2, 1) = 84000.0 / 367429.0;
  matrix_2(2, 2) = -51010.0 / 367429.0;

  matrix_1(0, 0) = 2.8;
  matrix_1(0, 1) = 1.3;
  matrix_1(0, 2) = 7.01;
  matrix_1(1, 0) = -1.03;
  matrix_1(1, 1) = -2.3;
  matrix_1(1, 2) = 3.01;
  matrix_1(2, 0) = 0;
  matrix_1(2, 1) = -3;
  matrix_1(2, 2) = 2;
  S21Matrix result = matrix_1.InverseMatrix();
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      EXPECT_EQ(1, fabs(result(i, j) - matrix_2(i, j)) < 10e-6);
    }
  }
}

TEST(S21MatrixTest, Test_Inverse_2) {
  S21Matrix matrix_1(2, 3);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(1, 0) = 4;
  matrix_1(1, 1) = 5;
  matrix_1(1, 2) = 6;

  EXPECT_ANY_THROW(matrix_1.InverseMatrix());
}

TEST(S21MatrixTest, Test_Inverse_3) {
  S21Matrix matrix_1(2, 2);
  matrix_1(0, 0) = 2;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 2;
  matrix_1(1, 1) = 2;

  EXPECT_ANY_THROW(matrix_1.InverseMatrix());
}

TEST(S21MatrixTest, Test_OperatorOverload_Mul) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  S21Matrix expected(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 5;
  matrix_1(1, 1) = 6;

  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 5;
  matrix_2(1, 1) = 6;

  expected(0, 0) = 11;
  expected(0, 1) = 14;
  expected(1, 0) = 35;
  expected(1, 1) = 46;

  S21Matrix result = matrix_1 * matrix_2;
  EXPECT_EQ(1, result == expected);
}

TEST(S21MatrixTest, Test_OperatorOverload_EqMulNum) {
  S21Matrix matrix_1(3, 4);
  S21Matrix matrix_2(3, 4);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(0, 2) = 3;
  matrix_1(0, 3) = 4;
  matrix_1(1, 0) = 5;
  matrix_1(1, 1) = 6;
  matrix_1(1, 2) = 7;
  matrix_1(1, 3) = 8;
  matrix_1(2, 0) = 9;
  matrix_1(2, 1) = 10;
  matrix_1(2, 2) = 11;
  matrix_1(2, 3) = 12;

  matrix_2(0, 0) = 2;
  matrix_2(0, 1) = 4;
  matrix_2(0, 2) = 6;
  matrix_2(0, 3) = 8;
  matrix_2(1, 0) = 10;
  matrix_2(1, 1) = 12;
  matrix_2(1, 2) = 14;
  matrix_2(1, 3) = 16;
  matrix_2(2, 0) = 18;
  matrix_2(2, 1) = 20;
  matrix_2(2, 2) = 22;
  matrix_2(2, 3) = 24;

  matrix_1 *= 2;
  EXPECT_EQ(1, matrix_1 == matrix_2);
}

TEST(S21MatrixTest, Test_OperatorOverload_EqMul) {
  S21Matrix matrix_1(2, 2);
  S21Matrix matrix_2(2, 2);
  S21Matrix result(2, 2);
  matrix_1(0, 0) = 1;
  matrix_1(0, 1) = 2;
  matrix_1(1, 0) = 5;
  matrix_1(1, 1) = 6;

  matrix_2(0, 0) = 1;
  matrix_2(0, 1) = 2;
  matrix_2(1, 0) = 5;
  matrix_2(1, 1) = 6;

  result(0, 0) = 11;
  result(0, 1) = 14;
  result(1, 0) = 35;
  result(1, 1) = 46;

  matrix_1 *= matrix_2;
  EXPECT_EQ(1, matrix_1 == result);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}