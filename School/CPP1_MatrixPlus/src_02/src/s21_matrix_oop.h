#ifndef CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_
#define CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_

#define EPS 10E-9

class S21Matrix {
 public:
  // CONSTRUCTORS:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other);
  ~S21Matrix();

  // OPERTATORS:
  double& operator()(int i, int j);
  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix operator*(const double& num);
  bool operator==(const S21Matrix& other) const;
  void operator+=(const S21Matrix& other);
  void operator-=(const S21Matrix& other);
  void operator*=(const S21Matrix& other);
  void operator*=(const double& num);

  // OPERATIONS:
  bool EqMatrix(const S21Matrix& other) const;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix Minor(int iRow, int jCol);
  S21Matrix CalcComplements();
  S21Matrix InverseMatrix();
  double Determinant();

  // ADDITIONAL METHODS:
  void AlocMatrix(double*** matrix, int rows, int cols);
  void DelMatrix(double** matrix);
  void CheckIndexes(int i, int j);
  void SwapMaxRows(double** matrix, int maxRow, int j);
  double GaussDet();
  int CheckZero();

  // ACCESSOR AND MUTATOR:
  int GetRows() const;
  int GetCols() const;
  void SetRows(int rows);
  void SetCols(int cols);

 private:
  int rows_, cols_;
  double** matrix_;
};

#endif  // CPP1_S21_MATRIXPLUS_S21_MATRIX_OOP_H_