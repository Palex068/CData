#ifndef __S21MATRIXOOP_H__
#define __S21MATRIXOOP_H__

#include <math.h>

#include <cstring>
#include <iostream>  // директива препроцессора

class S21Matrix {
 private:
  // Attributes
  int rows_;
  int cols_;
  double** matrix_;  // Pointer to the memory where the matrix is allocated

 public:
  S21Matrix();   // Default constructor
  ~S21Matrix();  // Destructor
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);

  void printm();

  int getRows();
  int getCols();
  double** getMatrix();
  void setValue(int x, int y, double value);
  bool EqMatrix(const S21Matrix& other);   // исправить
  void SumMatrix(const S21Matrix& other);  // +
  void SubMatrix(const S21Matrix& other);  // +
  void MulNumber(const double num);        // +
  void MulMatrix(const S21Matrix& other);  // сделать
  S21Matrix Transpose();                   // + (работает)
  S21Matrix CalcComplements();             // + (работает)
  double Determinant();                    // + (работает)
  S21Matrix InverseMatrix();               // сделать

  S21Matrix& operator=(const S21Matrix& other);
  void copy_matrix(const S21Matrix& other);
  void delete_matrix();
  void create_matrix();
};

#endif