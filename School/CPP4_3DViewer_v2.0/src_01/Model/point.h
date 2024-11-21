#ifndef CPP4_3DVIEWER_V2_SRC_MODEL_POINT_H_
#define CPP4_3DVIEWER_V2_SRC_MODEL_POINT_H_

#include <memory>
#include <string>
namespace s21 {
class Point {
 private:
  double x_ = 0;
  double y_ = 0;
  double z_ = 0;

 public:
  Point() {}
  Point(double x, double y, double z);
  Point(const Point &other) : x_(other.x_), y_(other.y_), z_(other.z_) {}
  Point(Point &&other) noexcept;
  Point &operator=(const Point &other);      // Assignment operator
  Point &operator=(Point &&other) noexcept;  // Move assignment operator
  ~Point() {}

  void SetPoint(std::string &line);
  void SetMax(Point &b);
  void SetMin(Point &b);

  double GetX() const { return x_; }
  double GetY() const { return y_; }
  double GetZ() const { return z_; }

  void Scale(double coefficient);
  void Rotate(Point cos, Point sin);
  void Cos(Point degree);
  void Sin(Point degree);
  void Translate(Point &other);
  void SetData(double x, double y, double z);

  double DeltaMax() const;
  Point operator+(const Point &other) const;
  Point operator-(const Point &other) const;
  Point operator/(double num) const;
  void Print() const;

 private:
  bool IsNumber(char ch) const;
  void SetPoint(int coord, double num);
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_MODEL_POINT_H_
