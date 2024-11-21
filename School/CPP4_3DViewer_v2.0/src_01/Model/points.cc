#include "points.h"

#include <iostream>
#include <vector>

#include "error.h"

namespace s21 {

Points::Points() : points_() {
  min_.SetData(0, 0, 0);
  max_.SetData(0, 0, 0);
}

void Points::DEBUG_print() const {
  for (const Point &p : points_) {
    p.Print();
    std::cerr << "\n";
  }
  std::cerr << std::endl;
  std::cout << "\nMAX ";
  max_.Print();
  std::cout << std::endl;

  std::cout << "\nMIN ";
  min_.Print();
  std::cout << std::endl;
}

void Points::SetPoints(std::string &buffer) {
  Point p;
  p.SetPoint(buffer);
  SetExtreme(p);
  points_.push_back(p);
}

void Points::Clear() { points_.clear(); }

void Points::SetExtreme(Point &p) {
  if (points_.empty()) {
    max_ = p;
    min_ = p;
  } else {
    max_.SetMax(p);
    min_.SetMin(p);
  }
}

void Points::Center() {
  Point center = min_ + ((max_ - min_) / 2);
  Point delta = max_ - min_;
  double dmax = delta.GetX();
  if (dmax < delta.GetY()) dmax = delta.GetY();
  if (delta.GetY() < delta.GetZ()) dmax = delta.GetZ();

  double coef = 2 / dmax;
  for (std::size_t i = 0; i < points_.size(); ++i) {
    points_[i].Translate(center);
    points_[i].Scale(coef);
  }
}

void Points::Manipulate(strategy_type &strategy, const Point &p) {
  strategy->Execute(points_, p);
}

}  // namespace s21
