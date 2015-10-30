#include <algorithm>
#include <cassert>
#include <memory>
#include <vector>

int main()
{
  std::unique_ptr<int> a(new int(42));
  std::unique_ptr<int> b(new int(314));

  assert(a && *a ==  42);
  assert(b && *b == 314);

  std::vector<std::unique_ptr<int>> v;
  v.push_back(std::move(a));
  v.push_back(std::move(b));

  assert(!a);
  assert(!b);

  assert(v[0] && *v[0] ==  42);
  assert(v[1] && *v[1] == 314);

  //Shuffle the vector
  const int rng_seed{1234};
  std::mt19937 rng_generator(rng_seed);
  std::shuffle(std::begin(v),std::end(v),rng_generator);

  assert(v[0] && *v[0] == 314);
  assert(v[1] && *v[1] ==  42);
}
