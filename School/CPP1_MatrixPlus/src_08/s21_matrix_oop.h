#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <cmath>
#include <iostream>

class S21Matrix {
 public:
  int getRows() { return rows_; }
  int getCols() { return cols_; }
  double** getMatrix() { return matrix_; }
  // void setElement(int row, int col, double value) { matrix_[row][col] =
  // value; }
  void SetRows(int rows);
  void SetColumns(int cols);

  S21Matrix();  // Default constructor
  S21Matrix(int rows, int columns);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();  // Destructor

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);

  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const S21Matrix& other);
  S21Matrix operator*=(const double num);

  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double num);

  S21Matrix& operator=(const S21Matrix& other);
  bool operator==(const S21Matrix& other);
  double& operator()(int i, int j);
  double& operator()(int i, int j) const;

 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double** matrix_;  // Pointer to the memory where the matrix is allocated
  void RemoveMatrix();
  void NullingHandler();
  double GetDeterminant();
  void Copy(const S21Matrix& other);
  void CreateMatrix(int rows, int columns);
  void GetMatrix(int row, int col, const S21Matrix& tmp);
};

#endif  // SRC_MATRIX_H_