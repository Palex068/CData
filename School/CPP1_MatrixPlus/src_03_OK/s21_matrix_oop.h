#ifndef S21_MATRIX_OOP_H_
#define S21_MATRIX_OOP_H_

#include <algorithm>  // std::copy
#include <cmath>
#include <iostream>
#include <stdexcept>  // length_error, out_of_range, logic_error
#include <utility>    // std::move

#define DEFAULT_MATRIX_SIZE 3

class S21Matrix {
 private:
  int rows_;
  int cols_;
  double* matrix_;
  double precision = 1e-7;
  const double& getElement(int row, int col) const;
  void swapRows(int row1, int row2) noexcept;

 public:
  S21Matrix() noexcept;                   // default constructor
  S21Matrix(int r, int cols);             // parameterized constructor
  S21Matrix(const S21Matrix& other);      // copy constructor
  S21Matrix(S21Matrix&& other) noexcept;  // move constructor
  ~S21Matrix() noexcept;                  // destructor

  // assignment operator overload
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;
  double& operator()(int row, int col) &;
  double& operator()(int row, int col) && = delete;
  const double& operator()(int row, int col) const&;
  const double& operator()(int row, int col) const&& = delete;
  bool operator==(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other) const;
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other) const;
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*(const double num) const noexcept;
  S21Matrix operator*=(const double num);
  S21Matrix operator*(const S21Matrix& other) const;
  S21Matrix operator*=(const S21Matrix& other);

  // methods to perform operations with matrix
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose() const;
  double Determinant() const;
  // S21Matrix getMinorMatrix(const int skip_rows, const int skip_columns)
  // const;
  S21Matrix getMinorMatrix(int rows, int columns) const;
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix() const;

  // additional methods
  int GetRows() const noexcept;
  int GetColumns() const noexcept;
  void SetRows(int new_rows);
  void SetColumns(int new_columns);

  // void printMatrix();
};

#endif