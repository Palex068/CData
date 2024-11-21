#ifndef CPP3_SMARTCALC_V2_SRC_CONTROLLER_CONTROLLER_H_
#define CPP3_SMARTCALC_V2_SRC_CONTROLLER_CONTROLLER_H_

#include <QString>
#include <iostream>
#include <string>

#include "../Model/model.h"
namespace s21 {

class Controller {
 public:
  Controller(Model *model) : model_(model){};

  QString ParseFile(const QString &filename);

  int GetCountSurfaces() const;
  int GetVertexInSurface(int i) const;

  int GetCountEdge() const;
  int GetVertexCount() const;

  double GetX(int i, int j) const;
  double GetY(int i, int j) const;
  double GetZ(int i, int j) const;

  void Scale(double coef);
  void Rotate(double x, double y, double z);
  void Move(double x, double y, double z);

  ~Controller() = default;

 private:
  Model *model_;
};

}  // namespace s21

#endif  // CPP3_SMARTCALC_V2_SRC_CONTROLLER_CONTROLLER_H_
