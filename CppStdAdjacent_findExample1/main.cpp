#include <algorithm>
#include <cassert>
#include <vector>

int main()
{
  std::vector<int> v = {0,1,2,2,3,4};

  assert(std::adjacent_find(std::begin(v),std::end(v))!=std::end(v));
  assert(*std::adjacent_find(std::begin(v),std::end(v))==2);

  //Remove duplicate
  v[2]=5;

  assert(std::adjacent_find(std::begin(v),std::end(v))==std::end(v));
}
