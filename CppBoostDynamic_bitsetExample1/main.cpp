#include <cassert>
#include <iostream>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Weffc++"
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/dynamic_bitset.hpp>
#pragma GCC diagnostic pop

int main()
{
  boost::dynamic_bitset<> v;
  v.push_back( true); //Add 1
  v.push_back(false); //Add 0
  v.push_back( true); //Add 4
  v.push_back(false); //Add 0
  assert(v.to_ulong() == 5);
  std::cout << v << "\n";
}
