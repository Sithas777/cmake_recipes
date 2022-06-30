#include <string>
#include <iostream>
#include <boost/system.hpp>
#include <boost/algorithm/algorithm.hpp>

using namespace std;
using std::string_literals::operator ""s;

class A
{
  size_t i_;
 public:
  A() = delete;

  A(const A& a_copy) : i_(a_copy.get_i())
  {
    cout << "Copy constructor called"s << endl;
  }

  A(A&& a_copy) : i_(a_copy.get_i())
  {
    cout << "Move constructor called"s << endl;
  }

  A(size_t i) : i_(i)
  {
    cout << "Transform constructor called"s << endl;
  }

  [[nodiscard]]
  size_t
  get_i() const
  {
    return i_;
  }

  A&
  operator =(const A& rhs)
  {
    cout << "Copy operator called"s << endl;
    i_ = rhs.i_;

    return *this;
  }

  A&
  operator =(A&& rhs)
  {
    cout << "Move operator called"s << endl;
    swap(*this, rhs);

    return *this;
  }

  ~A()
  {
    cout << "Destructor called"s << endl;
  }
};

int
main()
{
  size_t i = 123;
  A a = i;
  A a1 = a;
  A a2 = A(i);

  BOOST_ASSERT(true);
}
