
#include <cmath>
#include <iostream>
#define S21_EPS 1e-7

class S21Matrix {
private:
  /* private fields*/

  int rows_, cols_;
  double **matrix_;
  void memory_allocation();
  S21Matrix minor_matrix(int row, int column);

public:
  /* Setters and getters */

  void set_rows(int rows);
  void set_cols(int cols);
  int get_rows();
  int get_cols();

  /* Konstruktors and destruktor */

  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix &other);
  S21Matrix(S21Matrix &&other);
  ~S21Matrix();

  /* Overload */

  S21Matrix operator+(const S21Matrix &other);
  S21Matrix operator-(const S21Matrix &other);
  S21Matrix operator*(const S21Matrix &other);
  S21Matrix operator*(const double number);
  bool operator==(const S21Matrix &other);
  S21Matrix &operator=(const S21Matrix &other);
  S21Matrix &operator+=(const S21Matrix &other);
  S21Matrix &operator-=(const S21Matrix &other);
  S21Matrix &operator*=(const S21Matrix &other);
  S21Matrix &operator*=(const double number);
  double &operator()(int row, int col);

  /* Matrix operations */

  bool EqMatrix(const S21Matrix &other);
  void sum_matrix(const S21Matrix &other);
  void sub_matrix(const S21Matrix &other);
  void mul_matrix(const S21Matrix &other);
  void multiply_number(const double number);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();
};
