#include "model.h"

#include <fstream>
#include <iostream>

#include "error.h"

namespace s21 {

Model *Model::m_instance_ = 0;

Model *Model::GetInstance() {
  if (!m_instance_) {
    m_instance_ = new Model();
  }
  return m_instance_;
}

void Model::SetData(const std::string &filename) {
  Clear();
  std::ifstream fin;
  fin.open(filename);
  if (fin.is_open()) {
    std::string line;
    while (std::getline(fin, line)) {
      if (IsInfoLine(line)) {
        std::string buffer = line.substr(2);
        if (IsVerterx(line[0])) {
          p_.SetPoints(buffer);
        }
        if (IsFacets(line[0])) {
          s_.SetSurfaces(buffer, p_.GetPoints());
        }
      }
    }
  } else {
    throw Error("File isn't opening");
  }
  if (p_.GetSize() == 0) throw Error("Trash file");
  p_.Center();
  fin.close();
}

std::size_t Model::GetVertexInSurface(int i) const {
  return s_.GetSurfaces()[i].GetPointsCount();
}

double Model::GetX(int i, int j) const {
  return p_.GetPoints()[s_.GetSurfaces()[i].GetIndex(j)].GetX();
}

double Model::GetY(int i, int j) const {
  return p_.GetPoints()[s_.GetSurfaces()[i].GetIndex(j)].GetY();
}

double Model::GetZ(int i, int j) const {
  return p_.GetPoints()[s_.GetSurfaces()[i].GetIndex(j)].GetZ();
}

void Model::Manipulate(Action action, double x, double y, double z,
                       double coef) {
  std::unique_ptr<PointStrategy> strategy;
  Point add_data(x, y, z);
  switch (action) {
    case Action::kMove:
      strategy = std::make_unique<Move>();
      break;
    case Action::kRotate:
      strategy = std::make_unique<Rotate>();
      break;
    case Action::kScale:
      scale_ = (coef / 100) / scale_;
      add_data.SetData(scale_, 0, 0);
      scale_ = coef / 100;
      strategy = std::make_unique<Scale>();
      break;
    default:
      break;
  }

  if (strategy) {
    p_.Manipulate(strategy, add_data);
  } else {
    throw Error("No strategy");
  }
}

void Model::Clear() {
  if (m_instance_) {
    s_.Clear();
    p_.Clear();
  }
}

void Model::DEBUG_print() const {
  if (m_instance_) {
    std::cout << "SCALE   " << scale_ << std::endl;
    // s_.DEBUG_print();
    p_.DEBUG_print();
  }
}

bool Model::IsVerterx(char ch) const { return ch == 'v'; }

bool Model::IsFacets(char ch) const { return ch == 'f'; }

bool Model::IsInfoLine(const std::string &line) const {
  return line.size() > 2 &&
         (line.substr(0, 2) == "v " || line.substr(0, 2) == "f ");
}

}  // namespace s21
