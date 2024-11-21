#include "point.h"

#include <iostream>
#include <sstream>

#include "error.h"
#define _USE_MATH_DEFINES  // для C++
#include <cmath>
#include <memory>
#include <string>

namespace s21 {
Point::Point(double x, double y, double z) : x_(x), y_(y), z_(z) {}

void Point::SetData(double x, double y, double z) {
  x_ = x;
  y_ = y;
  z_ = z;
}

void Point::Print() const {
  std::cout << "(" << x_ << ", " << y_ << ", " << z_ << ")";
}

Point Point::operator+(const Point &other) const {
  return Point(x_ + other.x_, y_ + other.y_, z_ + other.z_);
}

Point Point::operator-(const Point &other) const {
  return Point(x_ - other.x_, y_ - other.y_, z_ - other.z_);
}

Point Point::operator/(double num) const {
  if (num != 0) {
    return Point(x_ / num, y_ / num, z_ / num);
  } else {
    throw Error("Div Zero!");
  }
}

void Point::SetPoint(std::string &line) {
  int count_coord = 0;
  std::stringstream ss(line);
  double num;
  while (ss >> num && count_coord < 3) {
    SetPoint(count_coord, num);
    count_coord++;
  }
  if (count_coord != 3) throw Error("Not enought coord!");
}

Point &Point::operator=(const Point &other) {
  if (this != &other) {
    x_ = other.x_;
    y_ = other.y_;
    z_ = other.z_;
  }
  return *this;
}

Point &Point::operator=(Point &&other) noexcept {
  if (this != &other) {
    x_ = std::exchange(other.x_, 0);
    y_ = std::exchange(other.y_, 0);
    z_ = std::exchange(other.z_, 0);
  }
  return *this;
}

Point::Point(Point &&other) noexcept
    : x_(std::exchange(other.x_, 0)),
      y_(std::exchange(other.y_, 0)),
      z_(std::exchange(other.z_, 0)) {}

void Point::Translate(Point &other) {
  x_ -= other.x_;
  y_ -= other.y_;
  z_ -= other.z_;
}

double Point::DeltaMax() const {
  double result = x_;
  if (x_ < y_) result = y_;
  if (y_ < z_) result = z_;
  return result;
}

bool Point::IsNumber(char ch) const { return (ch >= '0') && (ch <= '9'); }

void Point::Scale(double coefficient) {
  x_ *= coefficient;
  y_ *= coefficient;
  z_ *= coefficient;
}

void Point::Rotate(Point cos, Point sin) {
  Point temp;
  temp.y_ = cos.x_ * y_ - sin.x_ * z_;
  temp.z_ = sin.x_ * y_ + cos.x_ * z_;
  temp.x_ = cos.y_ * x_ + sin.y_ * temp.z_;
  temp.z_ = -sin.y_ * x_ + cos.y_ * temp.z_;
  x_ = cos.z_ * temp.x_ - sin.z_ * temp.y_;
  y_ = sin.z_ * temp.x_ + cos.z_ * temp.y_;
  z_ = temp.z_;
}

void Point::Cos(Point degree) {
  degree.Scale(M_PI);
  Point temp = degree / 180;
  x_ = cos(temp.x_);
  y_ = cos(temp.x_);
  z_ = cos(temp.x_);
}

void Point::Sin(Point degree) {
  degree.Scale(M_PI);
  Point temp = degree / 180;
  x_ = sin(temp.x_);
  y_ = sin(temp.x_);
  z_ = sin(temp.x_);
}

void Point::SetPoint(int coord, double num) {
  if (coord == 0) {
    x_ = num;
  } else if (coord == 1) {
    y_ = num;
  } else if (coord == 2) {
    z_ = num;
  }
}

void Point::SetMax(Point &b) {
  if (x_ < b.x_) x_ = b.x_;
  if (y_ < b.y_) y_ = b.y_;
  if (z_ < b.z_) z_ = b.z_;
}

void Point::SetMin(Point &b) {
  if (x_ > b.x_) x_ = b.x_;
  if (y_ > b.y_) y_ = b.y_;
  if (z_ > b.z_) z_ = b.z_;
}
}  // namespace s21
