#include <cstdlib>
#include <iostream>
#include <string>
#include <string_view>

#include "FizzBuzz.hpp"

using std::string;
using std::string_view;
using std::cout;
using std::endl;
using std::literals::string_literals::operator""s;
using std::literals::string_view_literals::operator""sv;

int
main()
{
  for (size_t i = 0; i != 100; ++i)
  {
    cout << "i = "s << i + 1 << ' ' << FizzBuzz(i + 1) << endl;
  }

  return EXIT_SUCCESS;
}
