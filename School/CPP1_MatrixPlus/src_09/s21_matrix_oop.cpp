#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  if (rows < 0 || cols < 0) {
    throw std::length_error("Incorrect size of matrix");
  }
  matrix_ = new double[rows * cols]();
}

S21Matrix::S21Matrix(const S21Matrix &other) noexcept
    : rows_(other.rows_), cols_(other.cols_) {
  matrix_ = new double[rows_ * cols_];
  std::memcpy(matrix_, other.matrix_, rows_ * cols_ * sizeof(double));
}

S21Matrix::S21Matrix(S21Matrix &&other) noexcept
    : rows_(other.rows_), cols_(other.cols_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.rows_ = 0;
  other.cols_ = 0;
}

S21Matrix::~S21Matrix() noexcept {
  if (matrix_) {
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

int S21Matrix::GetRows() const { return rows_; }

int S21Matrix::GetCols() const { return cols_; }

void S21Matrix::SetRows(int rows) {
  if (rows < 0) {
    throw std::length_error("Incorrect rows");
  }

  if (rows != rows_) {
    S21Matrix temp(rows, cols_);
    int min_rows = std::min(rows, rows_);
    for (int i = 0; i < min_rows; i++) {
      for (int j = 0; j < cols_; j++) {
        temp(i, j) = (*this)(i, j);
      }
    }

    std::swap(*this, temp);
  }
}

void S21Matrix::SetCols(int cols) {
  if (cols < 0) {
    throw std::length_error("Incorrect cols");
  }

  if (cols != cols_) {
    S21Matrix temp(rows_, cols);
    int min_cols = std::min(cols, cols_);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min_cols; j++) {
        temp(i, j) = (*this)(i, j);
      }
    }

    std::swap(*this, temp);
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix &other) const {
  S21Matrix result = (*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix &other) const {
  S21Matrix result = (*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix &other) const {
  S21Matrix result = (*this);
  result.MulMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(double a) const {
  S21Matrix result = (*this);
  result.MulNumber(a);
  return result;
}

S21Matrix operator*(double a, const S21Matrix &matrix) { return matrix * a; }

bool S21Matrix::operator==(const S21Matrix &other) const {
  return EqMatrix(other);
}

S21Matrix &S21Matrix::operator=(const S21Matrix &other) noexcept {
  if (this != &other) {
    S21Matrix temp(other);
    std::swap(rows_, temp.rows_);
    std::swap(cols_, temp.cols_);
    std::swap(matrix_, temp.matrix_);
  }

  return (*this);
}

S21Matrix &S21Matrix::operator=(S21Matrix &&other) noexcept {
  if (this != &other) {
    this->~S21Matrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    matrix_ = other.matrix_;
    other.matrix_ = nullptr;
  }

  return (*this);
}

S21Matrix &S21Matrix::operator+=(const S21Matrix &other) {
  SumMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator-=(const S21Matrix &other) {
  SubMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator*=(const S21Matrix &other) {
  MulMatrix(other);
  return (*this);
}

S21Matrix &S21Matrix::operator*=(double a) {
  MulNumber(a);
  return (*this);
}

double &S21Matrix::operator()(int i, int j) {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[i * cols_ + j];
}

const double &S21Matrix::operator()(int i, int j) const {
  if (i < 0 || j < 0 || i >= rows_ || j >= cols_) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[i * cols_ + j];
}

bool S21Matrix::EqMatrix(const S21Matrix &other) const {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    return false;
  }

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (std::abs((*this)(i, j) - other(i, j)) > S21_EPS) {
        return false;
      }
    }
  }

  return true;
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    throw std::invalid_argument("Invalid input format");
  }

  for (auto i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) += other(i, j);
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (rows_ != other.GetRows() || cols_ != other.GetCols()) {
    throw std::invalid_argument("Invalid input format");
  }

  for (auto i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) -= other(i, j);
    }
  }
}

void S21Matrix::MulNumber(double num) {
  for (auto i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  if (cols_ != other.GetRows()) {
    throw std::invalid_argument("Invalid input format");
  }

  S21Matrix result(rows_, other.GetCols());

  for (auto i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      for (int k = 0; k < cols_; k++) {
        result(i, j) += (*this)(i, k) * other(k, j);
      }
    }
  }

  (*this) = result;
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix result(cols_, rows_);

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      result(i, j) = (*this)(j, i);
    }
  }

  return result;
}

S21Matrix S21Matrix::CalcComplements() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square");
  }

  S21Matrix result(rows_, cols_);

  if (rows_ == 1) {
    result(0, 0) = 1;
  } else {
    for (int i = 0; i < result.GetRows(); i++) {
      for (int j = 0; j < result.GetCols(); j++) {
        S21Matrix minor(rows_ - 1, cols_ - 1);
        GetMinor(minor, i, j);
        result(i, j) = std::pow((-1), i + j) * minor.Determinant();
      }
    }
  }

  return result;
}

double S21Matrix::Determinant() const {
  if (rows_ != cols_) {
    throw std::invalid_argument("Matrix must be square");
  }
  return DeterminantMatrix((*this), rows_);
}

double S21Matrix::DeterminantMatrix(const S21Matrix &A, int size) const {
  double D = 0;

  if (size == 1) {
    D = A(0, 0);
  } else if (size == 2) {
    D = A(0, 0) * A(1, 1) - A(1, 0) * A(0, 1);
  } else {
    for (int i = 0; i < size; i++) {
      S21Matrix minor(size - 1, size - 1);
      // Расчет минора матрицы A с пропуском первой строки и i столбца
      A.GetMinor(minor, 0, i);

      // Вычисление определителя матрицы A со знаком (чет '+', нечет '-') и
      // аккумулирование с текущим определителем
      D += std::pow((-1), i) * A(0, i) * DeterminantMatrix(minor, size - 1);
    }
  }

  return D;
}

S21Matrix S21Matrix::InverseMatrix() const {
  double D = Determinant();
  if (std::abs(D) < S21_EPS) {
    throw std::logic_error("Invalid value");
  }

  S21Matrix complements = CalcComplements().Transpose();
  S21Matrix result(rows_, cols_);

  for (int i = 0; i < result.GetRows(); i++) {
    for (int j = 0; j < result.GetCols(); j++) {
      result(i, j) = complements(i, j) / D;
    }
  }

  return result;
}

void S21Matrix::GetMinor(S21Matrix &minor, int skip_row, int skip_col) const {
  int minor_row = 0, minor_col;

  for (int rows = 0; rows < rows_; rows++) {
    if (rows == skip_row)
      continue;

    minor_col = 0; // Сбрасываем счетчик столбцов для каждой строки минора

    for (int cols = 0; cols < cols_; cols++) {
      if (cols == skip_col)
        continue;

      minor(minor_row, minor_col++) = (*this)(rows, cols);
    }

    minor_row++; // Переходим к следующей строке минора
  }
}