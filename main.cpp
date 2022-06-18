#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#include "FizzBuzz.hpp"
#include "s_math_add.hpp"
#include "s_math_diff.hpp"
#include "s_math_mult.hpp"
#include "s_math_div.hpp"

using std::string;
using std::string_view;
using std::cout;
using std::endl;
using std::literals::string_literals::operator""s;
using std::literals::string_view_literals::operator""sv;

using s_math::add;
using s_math::diff;
using s_math::mult;
using s_math::divide;

int
main()
{
  for (size_t i = 0; i != 100; ++i)
  {
    cout << "i = "s << i + 1 << ' ' << FizzBuzz(i + 1) << endl;
  }
  int64_t a = 10;
  int64_t b = 20;

  cout
    << "s_math library is available: "s
    << "add: "s << add(a, b)
    << ", diff: "s << diff(a, b)
    << ", mult: "s << mult(a, b)
    << ", div: "s << divide(a, b)
    << endl;

  return EXIT_SUCCESS;
}
