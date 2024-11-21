#ifndef CPP4_3DVIEWER_V2_SRC_MODEL_POINTS_H_
#define CPP4_3DVIEWER_V2_SRC_MODEL_POINTS_H_

#include <vector>

#include "point.h"
#include "strategy.h"

namespace s21 {

class Points {
 public:
  using strategy_type = std::unique_ptr<PointStrategy>;

  Points();

  void SetPoints(std::string &line);

  void Clear();

  std::size_t GetSize() const { return points_.size(); };
  const std::vector<Point> &GetPoints() const { return points_; };

  double GetX(std::size_t i) const { return points_[i].GetX(); }
  double GetY(std::size_t i) const { return points_[i].GetY(); }
  double GetZ(std::size_t i) const { return points_[i].GetZ(); }

  void Center();
  void Manipulate(strategy_type &strategy, const Point &p);

  void DEBUG_print() const;

 private:
  void SetExtreme(Point &p);

 private:
  std::vector<Point> points_;
  Point min_;
  Point max_;
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_MODEL_POINTS_H_
