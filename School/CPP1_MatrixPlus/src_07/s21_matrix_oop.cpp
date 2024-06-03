#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() : rows_(3), cols_(3) { create_matrix(); }

S21Matrix::S21Matrix(int rows, int cols)
    : rows_(rows), cols_(cols) {  // инициализация по умолчанию
  if (rows <= 0 || cols <= 0) {
    throw std::invalid_argument("rows or columns equal or less 0");
  }
  create_matrix();
}

void S21Matrix::create_matrix() {
  this->matrix_ = new double*[rows_]();  // default 0
  for (int i = 0; i < rows_; i++) {
    this->matrix_[i] = new double[cols_]();  // default 0
  }
}

// Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  for (int i = 0; i < rows_; ++i)
    for (int j = 0; j < cols_; ++j) {
      matrix_[i][j] = other.matrix_[i][j];
    }
}

// Конструктор переноса
S21Matrix::S21Matrix(S21Matrix&& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  matrix_ = other.matrix_;
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

// Деструктор
S21Matrix::~S21Matrix() { this->delete_matrix(); }

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    return false;
  } else {
    for (int i = 0; i < cols_ * rows_; i++) {
      if (matrix_[i] != other.matrix_[i]) {
        return false;
      }
    }
  }
  return true;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::exception();
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int y = 0; y < cols_; y++) {
        matrix_[i][y] += other.matrix_[i][y];
      }
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw std::exception();
  } else {
    for (int i = 0; i < rows_; i++) {
      for (int y = 0; y < cols_; y++) {
        matrix_[i][y] -= other.matrix_[i][y];
      }
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  for (int i = 0; i < rows_; i++) {
    for (int y = 0; y < cols_; y++) {
      matrix_[i][y] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_) {
    throw std::exception();
  }
  S21Matrix matrix_mul(rows_, other.cols_);
  for (int i = 0; i < matrix_mul.rows_; i++) {
    for (int y = 0; y < matrix_mul.cols_; y++) {
      for (int k = 0; k < cols_; k++) {
        matrix_mul.matrix_[i][y] = matrix_mul.matrix_[i][y] +
                                   (this->matrix_[i][k] * other.matrix_[k][y]);
      }
    }
  }
  *this = matrix_mul;
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      result.matrix_[j][i] = matrix_[i][j];
    }
  }
  return result;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_) {
    throw std::exception();
  }
  S21Matrix result(cols_, rows_);
  S21Matrix minor(cols_ - 1, rows_ - 1);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      int c1 = 0;
      int c2 = 0;
      for (int x = 0; x < rows_; x++) {
        for (int y = 0; y < cols_; y++) {
          if (x != i && y != j) {
            minor.matrix_[c1][c2] = matrix_[x][y];
            c2++;
            if (c2 == rows_ - 1) {
              c2 = 0;
              c1++;
            }
          }
        }
      }
      result.matrix_[i][j] = minor.Determinant();
      if (((i + j) % 2)) {
        result.matrix_[i][j] *= -1;
      }
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_) {
    throw std::exception();
  }
  double result = 0;
  if (rows_ == 1) {
    result = matrix_[0][0];
  } else {
    if (rows_ == 2) {
      result = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      S21Matrix other = this->CalcComplements();
      for (int i = 0; i < cols_; i++) {
        result += matrix_[0][i] * other.matrix_[0][i];
      }
    }
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double determinant = this->Determinant();
  if (fabs(determinant) < 1e-7) {
    throw std::exception();
  }
  S21Matrix result = this->Transpose().CalcComplements();
  result.MulNumber(1.0 / determinant);
  return result;
}

void S21Matrix::setValue(int x, int y, double value) { matrix_[x][y] = value; }

int S21Matrix::getRows() { return rows_; }
int S21Matrix::getCols() { return cols_; }
double** S21Matrix::getMatrix() { return matrix_; }

void S21Matrix::printm() {
  for (int i = 0; i < this->getRows(); i++) {
    for (int y = 0; y < this->getCols(); y++) {
      if (y == 0) {
        std::cout << '\n';
      }
      std::cout << this->getMatrix()[i][y] << ' ';
    }
  }
}

S21Matrix& S21Matrix::operator=(const S21Matrix& other) {
  if (this != &other) {
    this->delete_matrix();
    this->copy_matrix(other);
  }
  return *this;
}

void S21Matrix::copy_matrix(const S21Matrix& other) {
  this->rows_ = other.rows_;
  this->cols_ = other.cols_;
  this->create_matrix();
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

void S21Matrix::delete_matrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      delete[] matrix_[i];
    }
    delete[] matrix_;
  }
}

int main() {
  // S21Matrix other(3, 3);
  S21Matrix my;

  // my.setValue(0, 0, 2);
  // my.setValue(0, 1, 5);
  // my.setValue(0, 2, 7);

  // my.setValue(1, 0, 6);
  // my.setValue(1, 1, 3);
  // my.setValue(1, 2, 4);

  // my.setValue(2, 0, 5);
  // my.setValue(2, 1, -2);
  // my.setValue(2, 2, -3);
  // S21Matrix other = my.InverseMatrix();

  // double res = my.Determinant();

  // std::cout << index;

  // other.setValue(0, 0, 1);
  // other.setValue(0, 1, 2);

  // my.setValue(0, 0, 3);
  // my.setValue(0, 1, 5);

  // my.printm();
  // std::cout << "\n";
  // other.printm();

  // // bool a = my.EqMatrix(other);
  // std::cout << "\n";
  // // std::cout << a;

  // // std::cout << "\n";
  // // my.SumMatrix(other);
  // // my.printm();

  // std::cout << "\n";
  // // my.SubMatrix(other);
  // // my.printm();

  // my.MulNumber(2);
  my.printm();
  // std::cout << "\n";
  // // std::cout << res;
  // other.printm();
}