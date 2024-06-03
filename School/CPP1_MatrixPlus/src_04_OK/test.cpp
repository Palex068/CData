#include "s21_matrix_oop.h"
#include "gtest/gtest.h"

TEST(Test, constructor) {
  S21Matrix A;
  int i = A.get_rows();
  int j = A.get_cols();
  EXPECT_EQ(i, j);
}

TEST(Test, constructor_move) {
  S21Matrix A(2, 2);
  S21Matrix B(std::move(A));
  EXPECT_EQ(2, B.get_rows());
  EXPECT_EQ(2, B.get_cols());
  EXPECT_EQ(0, A.get_rows());
}

TEST(Test, transfer_konstruktor) {
  S21Matrix a(2, 2);
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(1, 0) = 3;
  a(1, 1) = 2;
  S21Matrix b(a);
  ASSERT_TRUE(b == a);
}

TEST(Test, transfer_konstruktor2) {
  S21Matrix a(2, 2);
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(1, 0) = 3;
  a(1, 1) = 2;
  a *= a;
  S21Matrix b(a);
  ASSERT_TRUE(b == a);
}

TEST(Test, transfer_konstruktor3) {
  S21Matrix a(2, 2);
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(1, 0) = 3;
  a(1, 1) = 2;
  a = a * a;
  S21Matrix b(a);
  ASSERT_TRUE(b == a);
}

TEST(Test, set_rows) {
  S21Matrix A(3, 3);
  A.set_rows(4);
  EXPECT_EQ(4, A.get_rows());
}

TEST(Test, set_cols) {
  S21Matrix A(3, 3);
  A.set_cols(7);
  EXPECT_EQ(7, A.get_cols());
}

TEST(Test, get_rows) {
  S21Matrix A(3, 4);
  EXPECT_EQ(3, A.get_rows());
}
TEST(Test, constructor_3_5) {
  S21Matrix A(3, 5);
  EXPECT_EQ(3, A.get_rows());
  EXPECT_EQ(5, A.get_cols());
}

TEST(Test, equality) {
  S21Matrix A(4, 4);
  S21Matrix D(4, 4);
  ASSERT_TRUE(A == D);
}

TEST(EqMatrix, False) {
  S21Matrix matrix_a(3, 3);
  S21Matrix matrix_b(2, 2);
  ASSERT_FALSE(matrix_a == matrix_b);
}

TEST(OperatorsOverload, MulNumberTwo) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(1, 0) = 3;
  a(1, 1) = 2;
  b(0, 0) = -5;
  b(0, 1) = -4;
  b(1, 0) = -3;
  b(1, 1) = -2;
  S21Matrix c = b * -1;
  ASSERT_TRUE(c == a);
}

TEST(OperatorsOverload, PlusThree) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a(i, j) = i * j * 3.5;
      b(i, j) = i * j * 2.5;
      c(i, j) = i * j * (3.5 + 2.5);
    }
  }
  ASSERT_TRUE(a + b == c);
}

TEST(AccessorMutator, get_rowsTest) {
  S21Matrix a(3, 4);
  EXPECT_EQ(a.get_rows(), 3);
  a.~S21Matrix();
}

TEST(Test, mul_mtx) {
  S21Matrix a(2, 2);
  a(0, 0) = 5;
  a(0, 1) = 4;
  a(1, 0) = 3;
  a(1, 1) = 2;
  a = a * 2;
  S21Matrix b(a);
  ASSERT_TRUE(b == a);
}

TEST(AccessorMutator, get_colsTest) {
  S21Matrix a(3, 4);
  EXPECT_EQ(a.get_cols(), 4);
}

TEST(AccessorMutator, SetRowsTwo) {
  S21Matrix a(4, 3);
  a.set_rows(3);
  EXPECT_EQ(a.get_rows(), 3);
  EXPECT_FALSE(a.get_rows() == 4);
}

TEST(OperatorsOverload, assignment) {
  S21Matrix a(3, 3);
  S21Matrix c(4, 4);
  a = c;
  EXPECT_TRUE(a == c);
}

TEST(EqMatrix, True) {
  S21Matrix matrix_a(2, 2);
  S21Matrix matrix_b(2, 2);
  ASSERT_TRUE(matrix_a == matrix_b);
}

TEST(OperatorsOverload, notEqual) {
  S21Matrix a(3, 3);
  S21Matrix b(4, 4);
  int z = a == b;
  ASSERT_TRUE(z == 0);
}

TEST(OperatorsOverload, MinusTwo) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  a(0, 0) = 7.7;
  a(0, 1) = 6.7;
  a(1, 0) = 5.7;
  a(1, 1) = 4.7;
  b(0, 0) = 2.3;
  b(0, 1) = 3.3;
  b(1, 0) = 4.3;
  b(1, 1) = 5.3;
  c(0, 0) = 5.4;
  c(0, 1) = 3.4;
  c(1, 0) = 1.4;
  c(1, 1) = -0.6;
  ASSERT_TRUE(a - b == c);
}
TEST(OperatorsOverload, MinusThree) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      a(i, j) = i * j * 2.5;
      b(i, j) = i * j * 2.3;
      c(i, j) = i * j * (2.5 - 2.3);
    }
  }
  ASSERT_TRUE(a - b == c);
}

TEST(OperatorsOverload, PlusEqualTwo) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  a(0, 0) = 7.7;
  a(0, 1) = 6.7;
  a(1, 0) = 5.7;
  a(1, 1) = 4.7;
  b(0, 0) = 2.3;
  b(0, 1) = 3.3;
  b(1, 0) = 4.3;
  b(1, 1) = 5.3;
  c(0, 0) = 10;
  c(0, 1) = 10;
  c(1, 0) = 10;
  c(1, 1) = 10;
  a += b;
  ASSERT_TRUE(a == c);
}
TEST(OperatorsOverload, PlusEqualThree) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      a(i, j) = i * j * 2.2;
      b(i, j) = i * j * 3.3;
      c(i, j) = i * j * (2.2 + 3.3);
    }
  }
  a += b;
  ASSERT_TRUE(a == c);
}

TEST(OperatorsOverload, MinusEqualTwo) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  a(0, 0) = 7.7;
  a(0, 1) = 6.7;
  a(1, 0) = 5.7;
  a(1, 1) = 4.7;
  b(0, 0) = 2.3;
  b(0, 1) = 3.3;
  b(1, 0) = 4.3;
  b(1, 1) = 5.3;
  c(0, 0) = 5.4;
  c(0, 1) = 3.4;
  c(1, 0) = 1.4;
  c(1, 1) = -0.6;
  a -= b;
  ASSERT_TRUE(a == c);
}

TEST(OperatorsOverload, MinusEqualThree) {
  S21Matrix a(2, 2);
  S21Matrix b(2, 2);
  S21Matrix c(2, 2);
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < 2; ++j) {
      a(i, j) = i * j * 2.2;
      b(i, j) = i * j * 1.7;
      c(i, j) = i * j * (2.2 - 1.7);
    }
  }
  a -= b;
  ASSERT_TRUE(a == c);
}
TEST(OperatorsOverload, MultNumberOne) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a(i, j) = 2;
      b(i, j) = 2 * 2.25;
    }
  }
  S21Matrix c = a * 2.25;
  ASSERT_TRUE(c == b);
}

TEST(OperatorsOverload, MultNumberEqualOne) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a(i, j) = 2;
      b(i, j) = 2 * 3.14;
    }
  }
  a *= 3.14;
  ASSERT_TRUE(a == b);
}
TEST(OperatorsOverload, MulNumberEqualTwo) {
  S21Matrix e(2, 2);
  S21Matrix f(2, 2);
  e(0, 0) = 10;
  e(0, 1) = 8;
  e(1, 0) = 6;
  e(1, 1) = 4;
  f(0, 0) = -5;
  f(0, 1) = -4;
  f(1, 0) = -3;
  f(1, 1) = -2;
  e *= -0.5;
  ASSERT_TRUE(e == f);
}

TEST(OperatorsOverload, IndexTwo) {
  S21Matrix a(34, 36);
  a(21, 21) = 21;
  ASSERT_TRUE(a(21, 21) == 21);
}

TEST(MatrixOperations, SumOne) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  S21Matrix c(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a(i, j) = i * j * 4;
      b(i, j) = i * j * 5;
      c(i, j) = i * j * (4 + 5);
    }
  }
  a.sum_matrix(b);
  ASSERT_TRUE(a == c);
}

TEST(MatrixOperations, SumThree) {
  S21Matrix e(2, 2);
  S21Matrix f(2, 2);
  S21Matrix g(2, 2);
  e(0, 0) = 1;
  e(0, 1) = 2;
  e(1, 0) = 3;
  e(1, 1) = 4;
  f(0, 0) = 5;
  f(0, 1) = 6;
  f(1, 0) = 7;
  f(1, 1) = -4;
  g(0, 0) = 6;
  g(0, 1) = 8;
  g(1, 0) = 10;
  g(1, 1) = 0;
  e.sum_matrix(f);
  ASSERT_TRUE(e == g);
}
TEST(MatrixOperations, SubOne) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  S21Matrix c(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a(i, j) = i * j * 2;
      b(i, j) = i * j * 3;
      c(i, j) = i * j * (2 - 3);
    }
  }
  a.sub_matrix(b);
  ASSERT_TRUE(a == c);
}

TEST(MatrixOperations, SubThree) {
  S21Matrix e(2, 2);
  S21Matrix f(2, 2);
  S21Matrix g(2, 2);
  e(0, 0) = 10;
  e(0, 1) = 8;
  e(1, 0) = 6;
  e(1, 1) = 4;
  f(0, 0) = 5;
  f(0, 1) = 6;
  f(1, 0) = 7;
  f(1, 1) = -4;
  g(0, 0) = 5;
  g(0, 1) = 2;
  g(1, 0) = -1;
  g(1, 1) = 8;
  e.sub_matrix(f);
  ASSERT_TRUE(e == g);
}
TEST(MatrixOperations, MulNumberOne) {
  S21Matrix a(3, 3);
  S21Matrix b(3, 3);
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      a(i, j) = 2;
      b(i, j) = 2 * 3.14;
    }
  }
  a.multiply_number(3.14);
  ASSERT_TRUE(a == b);
}
TEST(MatrixOperations, MulNumberTwo) {
  S21Matrix e(2, 2);
  S21Matrix f(2, 2);
  e(0, 0) = 10;
  e(0, 1) = 8;
  e(1, 0) = 6;
  e(1, 1) = 4;
  f(0, 0) = -5;
  f(0, 1) = -4;
  f(1, 0) = -3;
  f(1, 1) = -2;
  e.multiply_number(-0.5);
  ASSERT_TRUE(e == f);
}

// /*techet*/
// TEST(MatrixOperations, SumTwo) {
//   S21Matrix a(3, 3);
//   S21Matrix d(2, 3);
//   EXPECT_THROW(a.sum_matrix(d), std::out_of_range);
// }
// /*techet*/
// TEST(MatrixOperations, SubTwo) {
//   S21Matrix a(3, 3);
//   S21Matrix d(2, 3);
//   EXPECT_THROW(a.sub_matrix(d), std::out_of_range);
// }
// /*techet*/
// TEST(MatrixOperations, MulMatrixOne) {
//   S21Matrix a(3, 9);
//   S21Matrix b(3, 9);
//   EXPECT_THROW(a.mul_matrix(b), std::out_of_range);
// }
// /*techet*/
// TEST(MatrixOperations, CalcComplementsOne) {
//   S21Matrix a(2, 4);
//   ASSERT_THROW(a.CalcComplements(), std::out_of_range);
// }
// /*techet*/
// TEST(MatrixOperations, DeterminantOne) {
//   S21Matrix a(23, 3);
//   ASSERT_THROW(a.Determinant(), std::out_of_range);
// }
// /*techet*/
// TEST(MatrixOperations, InverseTwo) {
//   S21Matrix a(2, 4);
//   ASSERT_THROW(a.InverseMatrix(), std::out_of_range);
// }
// /*techet*/
// TEST(OperatorsOverload, MulMatrixEqualOne) {
//   S21Matrix a(3, 9);
//   S21Matrix b(3, 9);
//   EXPECT_THROW(a *= b, std::out_of_range);
// }
// /*techet*/
// TEST(OperatorsOverload, MulMatrixOne) {
//   S21Matrix a(3, 9);
//   S21Matrix b(3, 9);
//   EXPECT_THROW(a * b, std::out_of_range);
// }
// /*techet*/
// TEST(OperatorsOverload, MinusEqualOne) {
//   S21Matrix a(22, 32);
//   S21Matrix b(24, 43);
//   EXPECT_THROW(a -= b, std::out_of_range);
// }
// /*techet*/
// TEST(OperatorsOverload, PlusEqualOne) {
//   S21Matrix a(22, 32);
//   S21Matrix b(24, 43);
//   EXPECT_THROW(a += b, std::out_of_range);
// }
// /*techet*/
// TEST(OperatorsOverload, MinusOne) {
//   S21Matrix a(22, 32);
//   S21Matrix b(24, 43);
//   EXPECT_THROW(a - b, std::out_of_range);
// }

// TEST(OperatorsOverload, zero) {
//   EXPECT_THROW(S21Matrix a(0, 0), std::out_of_range);
// }

TEST(Test, inverst_test) {
  S21Matrix result(3, 3);
  result(0, 0) = 0;
  result(0, 1) = 1;
  result(0, 2) = -0.75;
  result(1, 0) = -0.5;
  result(1, 1) = 3;
  result(1, 2) = -2;
  result(2, 0) = 0.5;
  result(2, 1) = -3.5;
  result(2, 2) = 2.5;

  S21Matrix R(3, 3);
  R(0, 0) = 8;
  R(0, 1) = 2;
  R(0, 2) = 4;
  R(1, 0) = 4;
  R(1, 1) = 6;
  R(1, 2) = 6;
  R(2, 0) = 4;
  R(2, 1) = 8;
  R(2, 2) = 8;

  S21Matrix result_inverse(3, 3);
  result_inverse = R.InverseMatrix();
  EXPECT_EQ(1, result == result_inverse);
}

int main() {
  testing::InitGoogleTest();
  return RUN_ALL_TESTS();
}