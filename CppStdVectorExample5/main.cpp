//std::vector example 5: returning a member std::vector that is not a copy
#include <cassert>
#include <vector>

class my_class
{
public:
  my_class() : m_v{1,2,3,4,5} {}

  const std::vector<int>& get() const noexcept { return m_v; }

  std::vector<int> m_v;
};

#include <iostream>

int main()
{
  my_class m;

  const std::vector<int>& a = m.get();
  const std::vector<int>& b = m.m_v;
  assert(&a == &b);
  assert(&a[0] == &b[0]);
  std::cout << &a << " " << &b << " " << &m.m_v << std::endl;
  std::cout << &a[0] << " " << &b[0] << " " << &m.m_v[0] <<  std::endl;

  const std::vector<int>& c{m.get()};
  const std::vector<int>& d{m.m_v};
  assert(&c != &d);
  assert(&c[0] != &d[0]);
  std::cout << &c << " " << &d << " " << &m.m_v << std::endl;
  std::cout << &c[0] << " " << &d[0] << " " << &m.m_v[0] <<  std::endl;


}

/* Screen output:

0x7ffe607350a0 0x7ffe607350a0 0x7ffe607350a0
0x246a010 0x246a010 0x246a010
0x7ffe607350c0 0x7ffe607350e0 0x7ffe607350a0
0x246a030 0x246a050 0x246a010

*/
