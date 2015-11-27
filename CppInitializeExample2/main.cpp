//initialize example 2: initializing a reference
#include <cassert>
#include <string>

class my_class
{
public:
   my_class(std::string& s) : m_s(s) {}

   //The syntax below will not work:
   //error: invalid initialization of non-const reference of type 'std::string& {aka std::basic_string<char>&}' from an rvalue of type '<brace-enclosed initializer list>'
   //my_class(std::string& s) : m_s{s} {}

  std::string& m_s;
};

#include <iostream>

int main()
{
  {
    std::string s{"Hello"};
    my_class m{s};
    assert(&s == &m.m_s);
  }
  {
    std::string s{"Hello"};
    const my_class m{s};
    assert(&s == &m.m_s);
  }
}
