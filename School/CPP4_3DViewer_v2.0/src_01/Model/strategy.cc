#include "strategy.h"

namespace s21 {

void Scale::Execute(std::vector<Point> &points, const Point &add_data) {
  for (size_t i = 0; i < points.size(); ++i) {
    points[i].Scale(add_data.GetX());
  }
}

void Rotate::Execute(std::vector<Point> &points, const Point &add_data) {
  Point cos;
  cos.Cos(add_data);
  Point sin;
  sin.Sin(add_data);
  for (size_t i = 0; i < points.size(); ++i) {
    points[i].Rotate(cos, sin);
  };
}

void Move::Execute(std::vector<Point> &points, const Point &add_data) {
  for (size_t i = 0; i < points.size(); ++i) {
    points[i] = points[i] + add_data;
  }
}
}  // namespace s21
