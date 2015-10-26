#include <algorithm>
#include <cassert>
#include <vector>

int main()
{
  std::vector<int> v = {0,1,2,3,2,5,6,7};

  const auto iter =
    std::adjacent_find(
      std::begin(v),
      std::end(v),
      [](const auto& lhs, const auto& rhs) { return lhs > rhs; }
    )
  ;
  assert(*iter == 3);
}
