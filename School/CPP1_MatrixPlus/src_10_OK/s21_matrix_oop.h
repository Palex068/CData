#ifndef S21_MATRIX_OOP
#define S21_MATRIX_OOP

// Defines minimum value of dimention size
#define MIN_MATRIX_DIM 0

// Defines matrix values comparisson precession
#define EQ_PRECISE 1e-7

// Defines comparison result macroses
#define COMPR_EQUAL true
#define COMPR_NEQUAL false

class S21Matrix {
 private:
  int cols_, rows_;
  double** matrix_;
  // internal method for valuable matrix creation
  double** createMatrix(const int rows, const int cols);
  // internal method of freeing matrixes
  void free();

 public:
  // project functionality
  S21Matrix() noexcept;                        // default constructor +
  S21Matrix(int rows, int cols);      // Parametrized constructor +
  S21Matrix(const S21Matrix& other);  // Copy constructor +
  S21Matrix(S21Matrix&& other) noexcept;       // Move constructor +
  ~S21Matrix();
  bool EqMatrix(const S21Matrix& other);  // Matrix comparisson function +
  bool operator==(
      const S21Matrix& other);  // Overloaded matrix comparisson operator +
  void SumMatrix(const S21Matrix& other);        //Matrix summarization
  S21Matrix operator+(const S21Matrix& other);   //Overloaded summarization operator
  S21Matrix& operator+=(const S21Matrix& other); //Overloaded summarization with define operator
  void SubMatrix(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix& operator-=(const S21Matrix& other);
  void MulNumber(const double num) noexcept;
  S21Matrix operator*(const double number);
  S21Matrix& operator*=(const double num);       
  void MulMatrix(const double num);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  // accessors
  int getRows();
  int getCols();
  // mutators
  void setRows(int rows);
  void setCols(int cols);
};

#endif