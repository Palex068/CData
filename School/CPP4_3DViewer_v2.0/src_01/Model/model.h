#ifndef CPP4_3DVIEWER_V2_SRC_MODEL_MODEL_H_
#define CPP4_3DVIEWER_V2_SRC_MODEL_MODEL_H_
#include "points.h"
#include "strategy.h"
#include "surfaces.h"

enum class Action { kMove, kRotate, kScale };

namespace s21 {

class Model {
 public:
  static Model *GetInstance();

  void SetData(const std::string &filename);

  void Clear();

  std::size_t GetEdgesAmount() const { return s_.GetEdgesAmount(); }
  std::size_t GetVertexesAmount() const { return p_.GetSize(); }

  std::size_t GetCountSurfaces() const { return s_.GetSurfaces().size(); }
  std::size_t GetVertexInSurface(int i) const;
  const std::vector<Point> GetPoints() const { return p_.GetPoints(); };

  double GetX(int i, int j) const;
  double GetY(int i, int j) const;
  double GetZ(int i, int j) const;

  void Manipulate(Action action, double x, double y, double z, double coef = 0);

  void DEBUG_print() const;

 private:
  Model(){};
  Model(const Model &);
  Model &operator=(Model &);

  bool IsVerterx(char ch) const;
  bool IsFacets(char ch) const;
  bool IsInfoLine(const std::string &line) const;

 private:
  static Model *m_instance_;
  double scale_ = 1;
  Points p_;
  Surfaces s_;
};

};      //   namespace s21
#endif  // CPP4_3DVIEWER_V2_SRC_MODEL_MODEL_H_
