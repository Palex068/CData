#ifndef S21MATRIX_OOP_H_
#define S21MATRIX_OOP_H_

#include <cmath>
#include <cstring>
#include <exception>
#include <iostream>

#define S21_EPS 1e-7

class S21Matrix {
private:
  int rows_, cols_;
  double *matrix_;

public:
  S21Matrix();                                // default constructor
  S21Matrix(int rows, int cols);              // parameterized constructor
  S21Matrix(const S21Matrix &other) noexcept; // copy constructor
  S21Matrix(S21Matrix &&other) noexcept;      // move constructor
  ~S21Matrix() noexcept;                      // destructor

  // accessor/mutators methods
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);

  // some operators overloads
  S21Matrix operator+(const S21Matrix &other) const;
  S21Matrix operator-(const S21Matrix &other) const;
  S21Matrix operator*(const S21Matrix &other) const;
  S21Matrix operator*(double a) const;

  bool operator==(const S21Matrix &other) const;

  S21Matrix &operator=(const S21Matrix &other) noexcept;
  S21Matrix &operator=(S21Matrix &&other) noexcept;
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(double a);

  // index operator overload
  double &operator()(int i, int j);
  const double &operator()(int i, int j) const;

  // some public methods
  bool EqMatrix(const S21Matrix &other) const;
  void SumMatrix(const S21Matrix &other);
  void SubMatrix(const S21Matrix &other);
  void MulNumber(double num);
  void MulMatrix(const S21Matrix &other);
  S21Matrix Transpose() const;
  S21Matrix CalcComplements() const;
  double Determinant() const;
  double DeterminantMatrix(const S21Matrix &A, int size) const;
  S21Matrix InverseMatrix() const;
  void GetMinor(S21Matrix &minor, int skip_row, int skip_col) const;

  friend S21Matrix operator*(double a, const S21Matrix &other);
};

#endif