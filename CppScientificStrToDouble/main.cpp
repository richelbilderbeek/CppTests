#include <algorithm>
#include <cassert>
#include <string>

double StrToDouble(const std::string& s)
{
  return std::stod(s);
}


int main()
{
  {
    const std::string s{"3.1415926"};
    const double d{3.1415926};
    assert(std::abs(StrToDouble(s) - d) < 0.00001);
  }
  {
    const std::string s{"1.0e6"};
    const double d{1.0e6};
    assert(std::abs(StrToDouble(s) - d) < 0.1);
  }
  {
    const std::string s{"1.0e6"};
    const double d{1.0e6};
    assert(std::abs(StrToDouble(s) - d) < 0.1);
  }
}
