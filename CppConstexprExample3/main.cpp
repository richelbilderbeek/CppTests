#include <cassert>

enum class color { red, green, blue };

constexpr const char * get(const color c) {
  switch (c) {
    case color::red: return "red";
    case color::green: return "green";
    case color::blue: return "blue";
  }
  return nullptr;
}

#include <iostream>

int main()
{
  std::cout
    << get(color::red) << '\n'
    << get(color::green) << '\n'
    << get(color::blue) << '\n'
  ;
}
