#include <algorithm>
#include <cassert>
#include <string>

int StrToInt(const std::string& s)
{
  return std::stoi(s);
}

int ScientificStrToInt(const std::string& s)
{
  const double d{std::stod(s)};
  return static_cast<int>(d);
}

int main()
{
  {
    const std::string s{"31415926"};
    const int i{31415926};
    assert(StrToInt(s) == i);
  }
  {
    const std::string s{"1.0e6"};
    const int i{1000000};
    assert(StrToInt(s) != i); //Bad: converts to 1
    assert(StrToInt(s) == 1); //Bad: converts to 1
    assert(ScientificStrToInt(s) == i);
  }
}
