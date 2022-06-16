#include <iostream>
#include <string>

#include "FizzBuzz.hpp"

using std::ostream;
using std::cout;
using std::endl;
using std::literals::string_literals::operator""s;

FizzBuzz::FizzBuzz(size_t index): index_(index)
{}

ostream&
operator <<(ostream& os, const FizzBuzz& fizz_buzz)
{
  if (!(fizz_buzz.index_ % 3)) cout << "Fizz"s;
  if (!(fizz_buzz.index_ % 5)) cout << "Buzz"s;

  return os;
}
