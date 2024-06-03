#include "unit_test.h"

TEST(S21MatrixUnitTest, DefaultConstructorTest) {
  S21Matrix result;
  ASSERT_EQ(result.GetRows(), 0);
  ASSERT_EQ(result.GetCols(), 0);
}

TEST(S21MatrixUnitTest, ParameterizedConstructorTest) {
  S21Matrix result(6, 6);
  ASSERT_EQ(result.GetRows(), 6);
  ASSERT_EQ(result.GetCols(), 6);
}

TEST(S21MatrixUnitTest, NegativeParameterizedConstructorTest) {
  ASSERT_THROW(S21Matrix(6, -6), std::length_error);
}

TEST(S21MatrixUnitTest, CopyConstructorTest) {
  S21Matrix matrix1(6, 6);
  S21Matrix matrix2(matrix1);
  ASSERT_EQ(matrix2.GetRows(), 6);
  ASSERT_EQ(matrix2.GetCols(), 6);
}

TEST(S21MatrixUnitTest, MoveConstructorTest) {
  S21Matrix matrix1(6, 6);
  S21Matrix matrix2(std::move(matrix1));
  ASSERT_EQ(matrix2.GetRows(), 6);
  ASSERT_EQ(matrix2.GetCols(), 6);
}

TEST(S21MatrixUnitTest, SetRowsTest) {
  S21Matrix result(6, 6);
  result.SetRows(1);
  ASSERT_EQ(result.GetRows(), 1);
  ASSERT_EQ(result.GetCols(), 6);
}

TEST(S21MatrixUnitTest, SetIncorrectRowsTest) {
  S21Matrix result(6, 6);
  ASSERT_THROW(result.SetRows(-6), std::length_error);
}

TEST(S21MatrixUnitTest, SetColsTest) {
  S21Matrix result(6, 6);
  result.SetCols(1);
  ASSERT_EQ(result.GetRows(), 6);
  ASSERT_EQ(result.GetCols(), 1);
}

TEST(S21MatrixUnitTest, SetIncorrectColsTest) {
  S21Matrix result(6, 6);
  ASSERT_THROW(result.SetCols(-6), std::length_error);
}

TEST(S21MatrixUnitTest, AddOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  S21Matrix result = matrix1 + matrix2;

  ASSERT_EQ(result(0, 0), 6);
  ASSERT_EQ(result(0, 1), 8);
  ASSERT_EQ(result(1, 0), 10);
  ASSERT_EQ(result(1, 1), 12);
}

TEST(S21MatrixUnitTest, ExceptionAddOperatorTest) {
  S21Matrix matrix1(6, 6);
  S21Matrix matrix2(1, 6);
  ASSERT_THROW(matrix1 + matrix2, std::invalid_argument);
  ASSERT_THROW(matrix1.SumMatrix(matrix2), std::invalid_argument);
}

TEST(S21MatrixUnitTest, SubOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 6;
  matrix1(1, 0) = 10;
  matrix1(1, 1) = -30;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  S21Matrix result = matrix1 - matrix2;

  ASSERT_EQ(result(0, 0), -4);
  ASSERT_EQ(result(0, 1), 0);
  ASSERT_EQ(result(1, 0), 3);
  ASSERT_EQ(result(1, 1), -38);
}

TEST(S21MatrixUnitTest, ExceptionSubOperatorTest) {
  S21Matrix matrix1(6, 6);
  S21Matrix matrix2(1, 6);
  ASSERT_THROW(matrix1 - matrix2, std::invalid_argument);
  ASSERT_THROW(matrix1.SubMatrix(matrix2), std::invalid_argument);
}

TEST(S21MatrixUnitTest, MultMatrixOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 6;
  matrix1(1, 0) = 2;
  matrix1(1, 1) = 5;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = -2;
  matrix2(0, 1) = -1;
  matrix2(1, 0) = 3;
  matrix2(1, 1) = 4;

  S21Matrix result = matrix1 * matrix2;

  ASSERT_EQ(result(0, 0), 16);
  ASSERT_EQ(result(0, 1), 23);
  ASSERT_EQ(result(1, 0), 11);
  ASSERT_EQ(result(1, 1), 18);
}

TEST(S21MatrixUnitTest, ExceptionMultMatrixOperatorTest) {
  S21Matrix matrix1(6, 6);
  S21Matrix matrix2(1, 6);
  ASSERT_THROW(matrix1 * matrix2, std::invalid_argument);
  ASSERT_THROW(matrix1.MulMatrix(matrix2), std::invalid_argument);
}

TEST(S21MatrixUnitTest, MultNumberMatrixOperatorTest_1) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 6;
  matrix1(1, 0) = 10;
  matrix1(1, 1) = -30;

  S21Matrix result = matrix1 * 10;

  ASSERT_EQ(result(0, 0), 10);
  ASSERT_EQ(result(0, 1), 60);
  ASSERT_EQ(result(1, 0), 100);
  ASSERT_EQ(result(1, 1), -300);
}

TEST(S21MatrixUnitTest, MultNumberMatrixOperatorTest_2) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 6;
  matrix1(1, 0) = 10;
  matrix1(1, 1) = -30;

  S21Matrix result = 10 * matrix1;

  ASSERT_EQ(result(0, 0), 10);
  ASSERT_EQ(result(0, 1), 60);
  ASSERT_EQ(result(1, 0), 100);
  ASSERT_EQ(result(1, 1), -300);
}

TEST(S21MatrixUnitTest, MatrixEqualityOperatorTest) {
  const int size = 100;
  S21Matrix matrix1(size, size);
  S21Matrix matrix2(size, size);

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      matrix1(i, j) = i * size + j;
      matrix2(i, j) = i * size + j;
    }
  }

  ASSERT_TRUE(matrix1 == matrix2);
}

TEST(S21MatrixUnitTest, ExceptionMatrixEqualityOperatorTest_1) {
  S21Matrix matrix1(1, 1);
  matrix1(0, 0) = 6;
  S21Matrix matrix2(1, 1);
  matrix1(0, 0) = -6;
  ASSERT_FALSE(matrix1 == matrix2);
}

TEST(S21MatrixUnitTest, ExceptionMatrixEqualityOperatorTest_2) {
  S21Matrix matrix1(0, 1);
  S21Matrix matrix2(1, 0);
  ASSERT_FALSE(matrix1 == matrix2);
  ASSERT_FALSE(matrix1.EqMatrix(matrix2));
}

TEST(S21MatrixUnitTest, MatrixPlusEqualOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1 += matrix2;

  ASSERT_EQ(matrix1(0, 0), 6);
  ASSERT_EQ(matrix1(0, 1), 8);
  ASSERT_EQ(matrix1(1, 0), 10);
  ASSERT_EQ(matrix1(1, 1), 12);
}

TEST(S21MatrixUnitTest, MatrixMinusEqualOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 5;
  matrix1(0, 1) = 6;
  matrix1(1, 0) = 7;
  matrix1(1, 1) = 8;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 1;
  matrix2(0, 1) = 2;
  matrix2(1, 0) = 3;
  matrix2(1, 1) = 4;

  matrix1 -= matrix2;

  ASSERT_EQ(matrix1(0, 0), 4);
  ASSERT_EQ(matrix1(0, 1), 4);
  ASSERT_EQ(matrix1(1, 0), 4);
  ASSERT_EQ(matrix1(1, 1), 4);
}

TEST(S21MatrixUnitTest, MatrixMultiplyEqualOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  S21Matrix matrix2(2, 2);
  matrix2(0, 0) = 5;
  matrix2(0, 1) = 6;
  matrix2(1, 0) = 7;
  matrix2(1, 1) = 8;

  matrix1 *= matrix2;

  ASSERT_EQ(matrix1(0, 0), 19);
  ASSERT_EQ(matrix1(0, 1), 22);
  ASSERT_EQ(matrix1(1, 0), 43);
  ASSERT_EQ(matrix1(1, 1), 50);
}

TEST(S21MatrixUnitTest, MatrixMultiplyEqualNumberOperatorTest) {
  S21Matrix matrix1(2, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;

  matrix1 *= 2;

  ASSERT_EQ(matrix1(0, 0), 2);
  ASSERT_EQ(matrix1(0, 1), 4);
  ASSERT_EQ(matrix1(1, 0), 6);
  ASSERT_EQ(matrix1(1, 1), 8);
}

TEST(S21MatrixUnitTest, TransposeTest) {
  S21Matrix matrix1(3, 2);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(1, 0) = 3;
  matrix1(1, 1) = 4;
  matrix1(2, 0) = 5;
  matrix1(2, 1) = 6;

  S21Matrix result = matrix1.Transpose();

  ASSERT_EQ(result.GetRows(), 2);
  ASSERT_EQ(result.GetCols(), 3);
  ASSERT_EQ(result(0, 0), 1);
  ASSERT_EQ(result(0, 1), 3);
  ASSERT_EQ(result(0, 2), 5);
  ASSERT_EQ(result(1, 0), 2);
  ASSERT_EQ(result(1, 1), 4);
  ASSERT_EQ(result(1, 2), 6);
}

TEST(S21MatrixUnitTest, CalcComplementsTest) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;
  matrix1(2, 0) = 7;
  matrix1(2, 1) = 8;
  matrix1(2, 2) = 9;

  // Вычисляем дополнительные матрицы
  S21Matrix result = matrix1.CalcComplements();

  ASSERT_EQ(result.GetRows(), 3);
  ASSERT_EQ(result.GetCols(), 3);
  // Каждый элемент дополнительной матрицы - это определитель
  // минора, вычисленный для соответствующего элемента исходной матрицы
  ASSERT_EQ(result(0, 0), -3);
  ASSERT_EQ(result(0, 1), 6);
  ASSERT_EQ(result(0, 2), -3);
  ASSERT_EQ(result(1, 0), 6);
  ASSERT_EQ(result(1, 1), -12);
  ASSERT_EQ(result(1, 2), 6);
  ASSERT_EQ(result(2, 0), -3);
  ASSERT_EQ(result(2, 1), 6);
  ASSERT_EQ(result(2, 2), -3);
}

TEST(S21MatrixUnitTest, ExceptionCalcComplementsTest) {
  S21Matrix matrix1(0, 1);
  ASSERT_THROW(matrix1.CalcComplements(), std::invalid_argument);
}

TEST(S21MatrixUnitTest, DeterminantTest) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 1;
  matrix1(0, 1) = 2;
  matrix1(0, 2) = 3;
  matrix1(1, 0) = 4;
  matrix1(1, 1) = 5;
  matrix1(1, 2) = 6;
  matrix1(2, 0) = 7;
  matrix1(2, 1) = 8;
  matrix1(2, 2) = 9;

  ASSERT_EQ(matrix1.Determinant(), 0);
}

TEST(S21MatrixUnitTest, DeterminantOneTest) {
  S21Matrix matrix1(1, 1);
  matrix1(0, 0) = 1;
  ASSERT_EQ(matrix1.Determinant(), 1);
}

TEST(S21MatrixUnitTest, ExceptionDeterminantOneTest) {
  S21Matrix matrix1(1, 0);
  ASSERT_THROW(matrix1.Determinant(), std::invalid_argument);
}

TEST(S21MatrixUnitTest, InverseMatrixTest_1) {
  S21Matrix matrix1(3, 3);
  matrix1(0, 0) = 4;
  matrix1(0, 1) = 3;
  matrix1(0, 2) = 2;
  matrix1(1, 0) = 0;
  matrix1(1, 1) = 1;
  matrix1(1, 2) = -2;
  matrix1(2, 0) = 3;
  matrix1(2, 1) = -1;
  matrix1(2, 2) = 4;

  S21Matrix matrix2 = matrix1.InverseMatrix();

  ASSERT_EQ(matrix2.GetRows(), 3);
  ASSERT_EQ(matrix2.GetCols(), 3);

  // После умножения матрицы на обратную, должна получиться единичная матрица
  S21Matrix result = matrix1 * matrix2;
  ASSERT_EQ(result(0, 0), 1);
  ASSERT_EQ(result(0, 1), 0);
  ASSERT_EQ(result(0, 2), 0);
  ASSERT_EQ(result(1, 0), 0);
  ASSERT_EQ(result(1, 1), 1);
  ASSERT_EQ(result(1, 2), 0);
  ASSERT_EQ(result(2, 0), 0);
  ASSERT_EQ(result(2, 1), 0);
  ASSERT_EQ(result(2, 2), 1);
}

TEST(S21MatrixUnitTest, InverseMatrixTest_2) {
  S21Matrix matrix1(1, 1);
  matrix1(0, 0) = 2;

  S21Matrix matrix2 = matrix1.InverseMatrix();

  ASSERT_EQ(matrix2.GetRows(), 1);
  ASSERT_EQ(matrix2.GetCols(), 1);

  S21Matrix result = matrix1 * matrix2;
  ASSERT_EQ(result(0, 0), 1);
}

TEST(S21MatrixUnitTest, ExceptionInverseMatrixTest) {
  S21Matrix matrix1(3, 2);
  ASSERT_THROW(matrix1.InverseMatrix(), std::invalid_argument);
}

int main(int argc, char *argv[]) {
  // Передаем параметры командной строки в gtest
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}