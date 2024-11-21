#ifndef CPP4_3DVIEWER_V2_SRC_MODEL_STRATEGY_H_
#define CPP4_3DVIEWER_V2_SRC_MODEL_STRATEGY_H_

#include <vector>

#include "point.h"

namespace s21 {

class PointStrategy {
 public:
  virtual ~PointStrategy() {}
  virtual void Execute(std::vector<Point> &points, const Point &add_data) = 0;
};

class Scale : public PointStrategy {
 public:
  void Execute(std::vector<Point> &points, const Point &add_data);
};

class Rotate : public PointStrategy {
 public:
  void Execute(std::vector<Point> &points, const Point &add_data);
};

class Move : public PointStrategy {
 public:
  void Execute(std::vector<Point> &points, const Point &add_data);
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_SRC_MODEL_STRATEGY_H_
