#include "s_math_div.hpp"

namespace s_math
{
  double divide(int64_t a, int64_t b)
  {
    return static_cast<double>(a) / b;
  }
  double divide(uint64_t a, uint64_t b)
  {
    return static_cast<double>(a) / b;
  }
}
