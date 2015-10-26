#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  //Create a std::vector consisting of ten zeroes
  std::vector<int> v(10,0);

  //Let iota assign incrementing values to the std::vector,
  //starting from zero
  std::iota(std::begin(v),std::end(v),0);

  //Show the std::vector
  std::copy(std::begin(v),std::end(v),std::ostream_iterator<int>(std::cout," "));
}

/*

Screen output

0 1 2 3 4 5 6 7 8 9

*/
