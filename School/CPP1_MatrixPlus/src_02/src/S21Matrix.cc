#include <cmath>
#include <iostream>

#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(1), cols_(1) {
  AlocMatrix(&matrix_, rows_, cols_);
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  AlocMatrix(&matrix_, rows_, cols_);
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : S21Matrix(other.rows_, other.cols_) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  matrix_ = other.matrix_;
  rows_ = other.rows_;
  cols_ = other.cols_;
  other.matrix_ = nullptr;
  other.cols_ = 0;
  other.rows_ = 0;
}

S21Matrix::~S21Matrix() {
  if (matrix_) {
    DelMatrix(matrix_);
  }
}
// Additional functions
void S21Matrix::AlocMatrix(double*** matrix, int rows, int cols) {
  if (rows < 1) {
    throw std::invalid_argument("Invalid number of rows " +
                                std::to_string(rows));
  }
  if (cols < 1) {
    throw std::invalid_argument("Invalid number of cols " +
                                std::to_string(cols));
  }
  *matrix = new double*[rows]();
  for (int i = 0; i < rows; i++) {
    (*matrix)[i] = new double[cols]();
  }
}

void S21Matrix::DelMatrix(double** matrix) {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix[i];
  }
  delete[] matrix;
}

void S21Matrix::CheckIndexes(int i, int j) {
  if (i < 0 || i > rows_ - 1) {
    throw std::out_of_range(
        "Invalid argument i - number of rows out of range [0:" +
        std::to_string(rows_ - 1) + "]");
  }
  if (j < 0 || j > cols_ - 1) {
    throw std::out_of_range(
        "Invalid argument j - number of cols out of range [0:" +
        std::to_string(cols_ - 1) + "]");
  }
}

// Accessor and mutator (Getters and setters)
int S21Matrix::GetRows() const { return rows_; }
int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows == rows_) return;
  double** newMatrix;
  AlocMatrix(&newMatrix, rows, cols_);
  for (int i = 0; i < rows && i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      newMatrix[i][j] = (*this)(i, j);
    }
  }
  DelMatrix(matrix_);
  rows_ = rows;
  matrix_ = newMatrix;
}

void S21Matrix::SetCols(int cols) {
  if (cols == cols_) return;
  double** newMatrix;
  AlocMatrix(&newMatrix, rows_, cols);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols && j < cols_; j++) {
      newMatrix[i][j] = (*this)(i, j);
    }
  }
  DelMatrix(matrix_);
  cols_ = cols;
  matrix_ = newMatrix;
}

// Ariphmetic operations
bool S21Matrix::EqMatrix(const S21Matrix& other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) return false;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (fabs(other.matrix_[i][j] - matrix_[i][j]) > EPS) return false;
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid argument different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] += other.matrix_[i][j];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::invalid_argument("Invalid argument different matrix dimensions");
  }
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] -= other.matrix_[i][j];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = (*this)(i, j) * num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (other.rows_ != cols_) {
    throw std::invalid_argument(
        "Invalid argument the number of columns of the first matrix is not "
        "equal to the number of rows of the second matrix");
  }
  S21Matrix res(rows_, other.cols_);
  for (int i = 0; i < res.rows_; i++) {
    for (int j = 0; j < res.cols_; j++) {
      for (int k = 0; k < cols_; k++) {
        res.matrix_[i][j] += (*this)(i, k) * other.matrix_[k][j];
      }
    }
  }
  *this = res;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix transp(cols_, rows_);
  for (int i = 0; i < transp.rows_; i++) {
    for (int j = 0; j < transp.cols_; j++) {
      transp.matrix_[i][j] = matrix_[j][i];
    }
  }
  return transp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::runtime_error(
        "Invalid argument of rows or cols the matrix is not square");
  }
  S21Matrix calc(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      calc.matrix_[i][j] = Minor(i, j).Determinant() * pow(-1, i + j);
    }
  }
  return calc;
}

// Minor method can to apply all size matrix not only square
S21Matrix S21Matrix::Minor(int iRow, int jCol) {
  CheckIndexes(iRow, jCol);
  int rows = rows_ - 1, cols = cols_ - 1;
  if (rows_ == 1) rows = 1;
  if (cols_ == 1) cols = 1;
  S21Matrix minor(rows, cols);
  int k = 0, l;
  for (int r = 0; r < rows_; r++) {
    if (iRow == r && rows_ != 1) continue;
    l = 0;
    for (int c = 0; c < cols_; c++) {
      if (jCol == c && cols_ != 1) continue;
      minor.matrix_[k][l] = (*this)(r, c);
      if (cols_ != 1) l++;
    }
    if (rows_ != 1) k++;
  }
  return minor;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::runtime_error(
        "Invalid argument of rows or cols the matrix is not square");
  }
  double result = 0;
  if (CheckZero() == 1) {
    return 0.0;
  } else if (rows_ == 1) {
    result = (*this)(0, 0);
  } else if (rows_ == 2) {
    result = (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  } else if (rows_ < 6) {
    for (int j = 0; j < cols_; j++) {
      result += (*this)(0, j) * Minor(0, j).Determinant() * pow(-1, j);
    }
  } else {
    result = GaussDet();
  }
  return result;
}

void S21Matrix::SwapMaxRows(double** matrix, int maxRow, int j) {
  for (int c = 0; c < cols_; c++) {
    double temp = matrix[j][c];
    matrix[j][c] = matrix[maxRow][c];
    matrix[maxRow][c] = temp;
  }
}

// Check rows or cols with only zero's
int S21Matrix::CheckZero() {
  int zero = 0;

  for (int i = 0; i < rows_; i++) {
    if ((*this)(i, 0) == 0) {
      for (int j = 1; j < cols_; j++) {
        for (int k = 1; k < rows_; k++) {
          // Check loop for column
          if ((*this)(k, i)) break;
          if ((k + 1) == rows_) zero = 1;
        }
        // Check loop for row
        if ((*this)(i, j)) break;
        if ((j + 1) == cols_) zero = 1;
      }
    }
  }
  return zero;
}

// Uses the Gauss method for determinant
double S21Matrix::GaussDet() {
  S21Matrix gauss(*this);
  int n = rows_;
  double res = 1.0;
  for (int i = 0; i < n; i++) {
    // Finds the maximum element in a column(i)
    int maxRow = i;
    for (int j = i + 1; j < n; j++) {
      if (fabs(gauss(j, i)) > fabs(gauss(maxRow, i))) {
        maxRow = j;
      }
    }
    // Swaps i-row and maxRow
    if (i != maxRow) {
      SwapMaxRows(gauss.matrix_, maxRow, i);
      res *= -1.0;
    }
    // Set zero for all elements below then main diagonal
    for (int j = i + 1; j < n; j++) {
      double factor = gauss(j, i) / gauss(i, i);
      for (int k = i + 1; k < n; k++) {
        gauss.matrix_[j][k] -= factor * gauss(i, k);
      }
      gauss.matrix_[j][i] = 0.0;
    }
    res *= gauss(i, i);
  }
  return res;
}

S21Matrix S21Matrix::InverseMatrix() {
  const double det = Determinant();
  if (fabs(det) < EPS) {
    throw std::runtime_error("Error: matrix GaussDet is 0");
  }
  S21Matrix inverse(cols_, rows_);
  inverse = CalcComplements().Transpose();
  inverse.MulNumber(1 / det);
  return inverse;
}

// Operators () + - * = == *= -= +=
double& S21Matrix::operator()(int i, int j) {
  CheckIndexes(i, j);
  return matrix_[i][j];
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix(other.rows_, other.cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix res = *this;
  res.SumMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix res = *this;
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix res = *this;
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*(const double& num) {
  S21Matrix res = *this;
  MulNumber(num);
  return res;
}

bool S21Matrix::operator==(const S21Matrix& other) const {
  return EqMatrix(other);
}

void S21Matrix::operator+=(const S21Matrix& other) { SumMatrix(other); }
void S21Matrix::operator-=(const S21Matrix& other) { SubMatrix(other); }
void S21Matrix::operator*=(const S21Matrix& other) { MulMatrix(other); }
void S21Matrix::operator*=(const double& num) { MulNumber(num); }
