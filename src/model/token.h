#ifndef CPP3_SMARTCALC_V_2_0_1_MODEL_TOKEN_H_
#define CPP3_SMARTCALC_V_2_0_1_MODEL_TOKEN_H_

#include <cmath>
#include <functional>
#include <string>
#include <unordered_map>
#include <variant>

namespace s21 {
enum class FunctionType {
  kNone,
  kSine,
  kCosine,
  kTangent,
  kArcCosine,
  kArcSine,
  kArcTangent,
  kSquareRoot,
  kNaturalLog,
  kCommonLog
};

enum class BracketType : char { kOpening = '(', kClosing = ')' };

struct Token {
  std::variant<double, char, BracketType, FunctionType> data{};
};
}  // namespace s21

#endif  // CPP3_SMARTCALC_V_2_0_1_MODEL_TOKEN_H_
