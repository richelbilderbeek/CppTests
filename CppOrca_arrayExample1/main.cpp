#include <cassert>
#include "orca_array.hpp"

int main() {
  const int maxx{3};
  const int maxy{4};
  const orca_array::array2d<double> v(maxx,maxy);
  assert(v.length1() == maxx);
  assert(v.length2() == maxy);

}
