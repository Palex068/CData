#ifndef CPP4_3DVIEWER_V2_SRC_MODEL_ERROR_H_
#define CPP4_3DVIEWER_V2_SRC_MODEL_ERROR_H_

#include <stdexcept>
#include <string>

namespace s21 {

class Error : public std::runtime_error {
 public:
  explicit Error(const std::string &error) : std::runtime_error(error) {}
};
}  // namespace s21

#endif  // CPP4_3DVIEWER_V2_SRC_MODEL_ERROR_H_
