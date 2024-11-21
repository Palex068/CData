#include "controller.h"

#include <iostream>

#include "../Model/error.h"
#include "../Model/model.h"

namespace s21 {

QString Controller::ParseFile(const QString &filename) {
  QString result = "";
  try {
    model_->SetData(filename.toStdString());
  } catch (Error &err) {
    result = QString::fromUtf8(std::string(err.what()).c_str());
  }
  return result;
}

int Controller::GetCountSurfaces() const { return model_->GetCountSurfaces(); }

int Controller::GetVertexInSurface(int i) const {
  return model_->GetVertexInSurface(i);
}

int Controller::GetCountEdge() const { return model_->GetEdgesAmount(); }

int Controller::GetVertexCount() const { return model_->GetVertexesAmount(); }

double Controller::GetX(int i, int j) const { return model_->GetX(i, j); }

double Controller::GetY(int i, int j) const { return model_->GetY(i, j); }

double Controller::GetZ(int i, int j) const { return model_->GetZ(i, j); }

void Controller::Scale(double coef) {
  model_->Manipulate(Action::kScale, 0, 0, 0, coef);
}

void Controller::Rotate(double x, double y, double z) {
  model_->Manipulate(Action::kRotate, x, y, z);
}

void Controller::Move(double x, double y, double z) {
  model_->Manipulate(Action::kMove, x, y, z);
}

}  // namespace s21
