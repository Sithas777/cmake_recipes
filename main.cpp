#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;
using std::literals::string_literals::operator"" s;

string
get_greeting()
{
#ifdef IS_WINDOWS
  return "Hello, Windows!"s;
#elif IS_LINUX
  return "Hello, Linux!"s;
#elif IS_MACOS
  return "Hello, MacOS!"s;
#else
  return "Hello from unknown system!"s;
#endif
}

int
main()
{
  cout << get_greeting() << endl;

  return EXIT_SUCCESS;
}
