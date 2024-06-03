#ifndef CPP_S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_
#define CPP_S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_

const double eps = 1e-7;

class S21Matrix {
 public:
  S21Matrix();
  S21Matrix(int rows, int cols);
  S21Matrix(const S21Matrix& other);
  S21Matrix(S21Matrix&& other) noexcept;
  ~S21Matrix();

  double& operator()(int row, int col);
  double& operator()(int row, int col) const;

  S21Matrix& operator=(const S21Matrix& other);
  S21Matrix& operator=(S21Matrix&& other) noexcept;

  S21Matrix& operator+=(const S21Matrix& other);
  S21Matrix operator+(const S21Matrix& other);

  S21Matrix& operator-=(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);

  friend S21Matrix operator*(double, S21Matrix&);
  S21Matrix operator*(const S21Matrix& other);
  S21Matrix& operator*=(const S21Matrix& other);

  S21Matrix operator*(const double num);
  S21Matrix& operator*=(const double num);

  bool operator==(const S21Matrix& other);

  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  int GetRows() { return rows_; };
  void SetRows(const int rows);

  int GetCols() { return cols_; };
  void SetCols(const int cols);

 private:
  int rows_, cols_;
  double** matrix_;
  void Create(int rows, int cols);
  S21Matrix Minor(int row, int col);
};

#endif  // CPP_S21_MATRIX_PLUS_SRC_S21_MATRIX_OOP_H_
