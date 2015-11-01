constexpr const char * get() {
  return "Hello world";
}

#include <iostream>

int main()
{
  std::cout << get() << '\n';
}
