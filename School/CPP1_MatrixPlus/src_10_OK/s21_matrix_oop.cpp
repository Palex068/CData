#include "s21_matrix_oop.h"

#include <cmath>
#include <new>

#include "s21_matrix_err.h"

//Базовый конструктор.
S21Matrix::S21Matrix() noexcept : cols_(0), rows_(0), matrix_(nullptr) {}

//Конструктор создания матрицы с определенными размерами.
S21Matrix::S21Matrix(int rows, int cols) : cols_(cols), rows_(rows) {
  if (this->getRows() < 0 || this->getCols() < 0)
    throw MSG_WRONG_DIMENTION_SIZE;
  this->matrix_ = createMatrix(rows, cols);
}

//Конструктор копирования
S21Matrix::S21Matrix(const S21Matrix& other)
    : cols_(other.cols_),
      rows_(other.rows_),
      matrix_(createMatrix(rows_, cols_)) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

//Конструктор переноса
S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : cols_(other.cols_), rows_(other.rows_), matrix_(other.matrix_) {
  other.matrix_ = nullptr;
  other.setRows(0);
  other.setCols(0);
  //  delete &other;
}

//Деструктор
S21Matrix::~S21Matrix() noexcept { this->free(); }

//Внутренняя функция для создания матрицы
double** S21Matrix::createMatrix(const int rows, const int cols) {
  double** pmatrix = nullptr;
  if (rows && cols) {
    pmatrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
      try {
        pmatrix[i] = new double[cols];
      } catch (std::bad_alloc&) {
        for (int j = 0; j < i; j++) {
          delete[] pmatrix[j];
        }
        delete[] pmatrix;
        throw MSG_ALLOCATION_ERROR;
      }
    }
  }
  return pmatrix;
}

//внутрення функция удаления матрицы
void S21Matrix::free() {
  for (int i = 0; i < this->rows_; i++) {
    delete[] this->matrix_[i];
  }
  delete[] this->matrix_;
  setRows(0);
  setCols(0);
}

bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result_code = COMPR_EQUAL;

  if (this->matrix_ != nullptr && other.matrix_ != nullptr && this->rows_ > 0 &&
      other.rows_ > 0 && this->cols_ > 0 && other.cols_ > 0 &&
      this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int row = 0; row < this->getRows(); row++) {
      for (int col = 0; col < this->getCols(); col++) {
        if (fabs(this->matrix_[row][col] - other.matrix_[row][col]) >=
            EQ_PRECISE) {
          result_code = COMPR_NEQUAL;
          break;
        }
      }
      if (result_code == COMPR_NEQUAL) break;
    }
  } else {
    result_code = COMPR_NEQUAL;
  }

  return result_code;
};

bool S21Matrix::operator==(const S21Matrix& other) {
  return this->EqMatrix(other);
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (this->getRows() != other.rows_ && this->getCols() != other.cols_) {
    throw MSG_NEQ_MATRIX_SIZE;
  }
  if (this->matrix_ == nullptr || other.matrix_ == nullptr) {
    throw MSG_EMPTY_MATRIX;
  }
  if (this->getRows() > 0 && this->getCols() > 0) {
    for (int i = 0; i < this->getRows(); i++) {
      for (int j = 0; j < this->getCols(); j++) {
        this->matrix_[i][j] += other.matrix_[i][j];
      }
    }
  }
}

S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix tmp{*this};
  tmp.SumMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator+=(const S21Matrix& other) {
  this->SumMatrix(other);
  return *this;
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (this->getRows() != other.rows_ && this->getCols() != other.cols_) {
    throw MSG_NEQ_MATRIX_SIZE;
  }
  if (this->matrix_ == nullptr || other.matrix_ == nullptr) {
    throw MSG_EMPTY_MATRIX;
  }
  if (this->getRows() > 0 && this->getCols() > 0) {
    for (int i = 0; i < this->getRows(); i++) {
      for (int j = 0; j < this->getCols(); j++) {
        this->matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  }
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix tmp{*this};
  tmp.SubMatrix(other);
  return tmp;
}

S21Matrix& S21Matrix::operator-=(const S21Matrix& other) {
  this->SubMatrix(other);
  return *this;
}

void S21Matrix::MulNumber(const double num) noexcept {
  for (int i = 0; i < this->getRows(); i++) {
    for (int j = 0; j < this->getCols(); j++) {
      this->matrix_[i][j] *= num;
    }
  }
}

S21Matrix S21Matrix::operator*(const double num) {
  S21Matrix tmp{*this};
  tmp.MulNumber(num);
  return tmp;
}

S21Matrix& S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

//void S21Matrix::MulMatrix(const S21Matrix& other) {}

// S21Matrix S21Matrix::Transpose() {
//   // int err_code = RES_OK;
//   const int colcount = this->getCols(), rowcount = this->getRows();

//   if (this->matrix_ && rowcount >= MIN_MATRIX_DIM &&
//       colcount > MIN_MATRIX_DIM) {
//     double** transposedMatrix = new double*[rowcount];
//     for (int i = 0; i < rowcount; i++) {
//       transposedMatrix[i] = new double[colcount];
//     }
//     for (int rawPosition = 0; rawPosition < rowcount; rawPosition++) {
//       for (int colPosition = 0; colPosition < colcount; colPosition++) {
//         transposedMatrix[rawPosition][colPosition] =
//             this->matrix_[colPosition][rawPosition];
//       }
//     }
//     for (int i = 0; i < rowcount; i++) {
//       delete[] this->matrix_[i];
//     }
//     delete[] this->matrix_;
//     this->matrix_ = transposedMatrix;
//   }
//   // err_code = RES_INCORRECT_MATRIX;

//   // return err_code;
// }

//S21Matrix S21Matrix::CalcComplements() {}
//double S21Matrix::Determinant() { return 0.0; };
//S21Matrix S21Matrix::InverseMatrix(){};

int S21Matrix::getRows() { return this->rows_; };

int S21Matrix::getCols() { return this->cols_; };
void S21Matrix::setRows(int rows) { this->rows_ = rows; };

void S21Matrix::setCols(int cols) { this->cols_ = cols; };