#pragma once

#include <iostream>

class FizzBuzz
{
  size_t index_;
 public:
  FizzBuzz() = delete;
  explicit FizzBuzz(size_t index);

  friend std::ostream&
  operator <<(std::ostream&, const FizzBuzz&);
};
