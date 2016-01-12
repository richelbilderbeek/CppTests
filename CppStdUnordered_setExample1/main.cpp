#include <cassert>
#include <unordered_set>

struct my_data
{
  std::string m_s;
  int m_x;
};

bool operator==(const my_data& lhs, const my_data& rhs) noexcept
{
  return lhs.m_s == rhs.m_s
    && lhs.m_x == rhs.m_x;
}

bool operator!=(const my_data& lhs, const my_data& rhs) noexcept
{
  return !(lhs == rhs);
}

///Define the hash function
///Note: this is a clumsy hash function
struct my_data_hash
{
  std::size_t operator()(const my_data& d) const
  {
    std::size_t seed = 0;
    seed += d.m_s.size();
    seed += d.m_x;
    return seed;
  }
};

int main()
{
  std::unordered_set<my_data, my_data_hash> v;
  v.insert(my_data{"x",42});
  v.insert(my_data{"ax",43});
  v.insert(my_data{"b x",44});
  v.insert(my_data{"c  x",45});
  assert(v.size() == 4);
}

