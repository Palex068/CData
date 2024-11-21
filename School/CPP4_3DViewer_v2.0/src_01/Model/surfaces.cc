#include "surfaces.h"

#include <iostream>
#include <sstream>
#include <vector>

#include "error.h"
namespace s21 {

void Surfaces::SetSurfaces(std::string &line,
                           const std::vector<Point> &points) {
  Surface s;

  std::istringstream iss(line);
  std::string token;
  int num = 0;

  while (iss >> token) {
    size_t pos = token.find('/');
    if (pos != std::string::npos) {
      num = std::stoi(token.substr(0, pos));
    } else {
      num = std::stoi(token);
    }
    s.SetSuface(num, points.size());
  }

  surfaces_.push_back(s);
  edges_amount_ += s.GetEdgesCount();
}

void Surfaces::Clear() {
  if (!surfaces_.empty()) {
    for (std::size_t i = 0; i < surfaces_[i].GetPointsCount(); ++i) {
      surfaces_[i].Clear();
    }
  }
  surfaces_.resize(0);
  edges_amount_ = 0;
}

void Surfaces::DEBUG_print() const {
  std::cerr << "Surface size " << surfaces_.size() << "\n";

  for (std::size_t i = 0; i < GetSurfaces().size(); ++i) {
    std::cerr << "Facet " << i << "\n";

    for (std::size_t j = 0; j < GetSurfaces()[i].GetPointsCount(); ++j) {
      std::cerr << "PointsCount " << GetSurfaces()[i].GetPointsCount();

      std::cerr << "|\n";
    }
    std::cerr << "\n";
  }
}

void Surface::SetSuface(double num, std::size_t points_amount) {
  num = (num < 0) ? points_amount + num : num - 1;
  if (num > points_amount) throw Error("Index isn't exists!");
  surface_.push_back(num);
}

void Surface::Clear() { surface_.clear(); }

bool Surface::IsSurface(char ch) const {
  return ((ch >= '0') && (ch <= '9')) || ch == '-';
}

bool Surface::IsEmpty(char ch) const {
  return (ch == ' ') || (ch == '\n') || (ch == '\0') || (ch == 13);
}

}  // namespace s21
