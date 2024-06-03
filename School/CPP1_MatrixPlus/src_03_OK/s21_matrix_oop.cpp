#include "s21_matrix_oop.h"
// constructors and distructor
S21Matrix::S21Matrix() noexcept
    : rows_(DEFAULT_MATRIX_SIZE),
      cols_(DEFAULT_MATRIX_SIZE),
      matrix_(nullptr) {}

S21Matrix::S21Matrix(int r, int cols) {
  if (r < 1 || cols < 1) {
    throw std::out_of_range(
        "Incorrect input, rows and columns should be positive");
  }
  rows_ = r;
  cols_ = cols;
  matrix_ = new double[rows_ * cols_]();
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) (*this)(i, j) = 0;
  }
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_{other.rows_},
      cols_{other.cols_},
      matrix_(new double[rows_ * cols_]) {
  std ::copy(other.matrix_, other.matrix_ + rows_ * cols_, matrix_);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : rows_{other.rows_}, cols_{other.cols_}, matrix_(other.matrix_) {
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

// assignment operator overload
S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  S21Matrix tmp(other);
  *this = std::move(tmp);
  return *this;
}
S21Matrix& S21Matrix::operator=(S21Matrix&& other) noexcept {
  if (this != &other) {
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
    matrix_ = nullptr;
    std::swap(rows_, other.rows_);
    std::swap(cols_, other.cols_);
    std::swap(matrix_, other.matrix_);
  }
  return *this;
}
double& S21Matrix::operator()(int row, int col) & {
  return const_cast<double&>(getElement(row, col));
}

const double& S21Matrix::operator()(int row, int col) const& {
  return getElement(row, col);
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

S21Matrix S21Matrix::operator+(const S21Matrix& other) const {
  S21Matrix res(*this);
  res.SumMatrix(other);
  return res;
}
S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) const {
  S21Matrix res(*this);
  res.SubMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*(const double num) const noexcept {
  S21Matrix res(*this);
  res.MulNumber(num);
  return res;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) const {
  S21Matrix res(*this);
  res.MulMatrix(other);
  return res;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

// methods to perform operations with matrix
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = true;
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    result = false;
  } else {
    for (int i = 0; i < rows_; ++i) {
      for (int j = 0; j < cols_; ++j) {
        if (std::abs(other(i, j) - (*this)(i, j)) > precision) {
          result = false;
        }
      }
    }
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ == other.GetRows() && cols_ == other.GetColumns()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        (*this)(i, j) += other(i, j);
      }
    }
  } else {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
}
void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ == other.GetRows() && cols_ == other.GetColumns()) {
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        (*this)(i, j) -= other(i, j);
      }
    }
  } else {
    throw std::out_of_range(
        "Incorrect input, matrices should have the same size");
  }
}
void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      (*this)(i, j) *= num;
    }
  }
}
void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.GetRows()) {
    S21Matrix resultMatrix(rows_, other.GetColumns());
    for (int i = 0; i < resultMatrix.GetRows(); i++) {
      for (int j = 0; j < resultMatrix.GetColumns(); j++) {
        for (int k = 0; k < cols_; k++) {
          resultMatrix(i, j) += ((*this)(i, k) * other(k, j));
        }
      }
    }
    *this = std::move(resultMatrix);
  } else {
    throw std::logic_error(
        "Incorrect input, number of columns in the first matrix should be "
        "equal to number of rows in the second matrix");
  }
}

S21Matrix S21Matrix::Transpose() const {
  S21Matrix tmp(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      tmp(j, i) = (*this)(i, j);
    }
  }
  return tmp;
}

double S21Matrix::Determinant() const {
  // check for square matrix
  if (this->rows_ != this->cols_)
    throw std::out_of_range("The matrix is not square");
  // main logic
  double result = 0;
  if (this->rows_ == 1)
    result = (*this)(0, 0);
  else if (this->rows_ == 2)
    result = (*this)(0, 0) * (*this)(1, 1) - (*this)(0, 1) * (*this)(1, 0);
  else {
    for (int j = 0; j < this->cols_; j++)
      result += ((j << 31) >> 31 == 0 ? 1 : -1) *
                getMinorMatrix(0, j).Determinant() * (*this)(0, j);
  }
  return result;
}

S21Matrix S21Matrix::getMinorMatrix(int rows, int columns) const {
  if (this->rows_ == 1 && this->cols_ == 1) return *this;
  S21Matrix tmp(this->rows_ - 1, this->cols_ - 1);
  int shift_row = 0;
  int shift_col = 0;
  for (int i = 0; i < this->rows_ - 1; i++) {
    if (i == rows) {
      shift_row = 1;
    }
    shift_col = 0;
    for (int j = 0; j < this->cols_ - 1; j++) {
      if (j == columns) {
        shift_col = 1;
      }
      tmp(i, j) = (*this)(i + shift_row, j + shift_col);
    }
  }
  return tmp;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect input, matrix should be square");
  }
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; ++i) {
    for (int j = 0; j < cols_; ++j) {
      result(i, j) = (((i + j) << 31) >> 31 == 0 ? 1 : -1) *
                     getMinorMatrix(i, j).Determinant();
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() const {
  if (rows_ != cols_) {
    throw std::logic_error("Incorrect input, matrix should be square");
  }
  double det = Determinant();
  if (det == 0.0 || abs(det) < precision) {
    throw std::logic_error(
        "Incorrect input, matrix is not invertible, determinnat should be "
        "non-zero");
  }

  return Transpose().CalcComplements() * (1.0 / det);
}

// additional methods
int S21Matrix::GetRows() const noexcept { return rows_; }
int S21Matrix::GetColumns() const noexcept { return cols_; }

const double& S21Matrix::getElement(int row, int col) const {
  if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
    throw std::out_of_range("Incorrect input, index is out of range");
  }
  return matrix_[row * cols_ + col];
}

void S21Matrix::swapRows(int row1, int row2) noexcept {
  if (row1 != row2) {
    for (int i = 0; i < cols_; i++) {
      std::swap((*this)(row1, i), (*this)(row2, i));
    }
  }
}
void S21Matrix::SetRows(int new_rows) {
  if (new_rows < 1) {
    throw std::length_error(
        "Incorrect input, number of rows should be more than zero");
  }
  if (new_rows != rows_) {
    S21Matrix tmp(new_rows, cols_);
    int min = std::min(rows_, new_rows);
    for (int i = 0; i < min; i++) {
      for (int j = 0; j < cols_; j++) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}

void S21Matrix::SetColumns(int new_columns) {
  if (new_columns < 1) {
    throw std::length_error(
        "Incorrect input, number of columns should be more than zero");
  }
  if (new_columns != cols_) {
    S21Matrix tmp(rows_, new_columns);
    int min = std::min(cols_, new_columns);
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < min; j++) {
        tmp(i, j) = (*this)(i, j);
      }
    }
    *this = std::move(tmp);
  }
}
