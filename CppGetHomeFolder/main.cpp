#include <cassert>
#include <string>


#include <iostream>

std::string GetHome() noexcept {
  return std::getenv("HOME");
}

int main()
{
  std::cout << GetHome() << std::endl;
}
