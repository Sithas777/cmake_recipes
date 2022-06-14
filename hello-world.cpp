#include <cstdlib>
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::literals::string_literals::operator"" s;

string
get_hello_world()
{
  return "Hello, World!"s;
}

int
main()
{
  cout << get_hello_world() << endl;

  return EXIT_SUCCESS;
}
