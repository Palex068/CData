#ifndef CPP4_3DVIEWER_V2_SRC_MODEL_SURFACES_H_
#define CPP4_3DVIEWER_V2_SRC_MODEL_SURFACES_H_

#include "points.h"
namespace s21 {

class Surface {
 public:
  using strategy_type = std::unique_ptr<PointStrategy>;

  Surface(){};

  void SetSuface(double num, std::size_t points_amount);
  void Clear();

  std::size_t GetEdgesCount() const { return GetPointsCount(); }
  std::size_t GetPointsCount() const { return surface_.size(); }
  double GetIndex(int j) const { return surface_[j]; }

  bool IsSurface(char ch) const;
  bool IsEmpty(char ch) const;

 private:
  std::vector<double> surface_;
};

class Surfaces {
 public:
  Surfaces(){};

  const std::vector<Surface> &GetSurfaces() const { return surfaces_; };

  std::size_t GetEdgesAmount() const { return edges_amount_ / 2; }  // ????!!!!

  void SetSurfaces(std::string &line, const std::vector<Point> &points);
  void Clear();
  void DEBUG_print() const;

 private:
  std::size_t edges_amount_ = 0;
  std::vector<Surface> surfaces_;
};
}  // namespace s21
#endif  // CPP4_3DVIEWER_V2_SRC_MODEL_SURFACES_H_
