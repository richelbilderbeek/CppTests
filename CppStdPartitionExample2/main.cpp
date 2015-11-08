#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iterator>
#include <vector>

int main()
{
  std::vector<int> v = {5,4,3,2,1};

  const auto p_end = std::partition(
    std::begin(v),
    std::end(v),
    [](const int i) { return i < 3; }
  );

  std::cout << "Less than three: ";
  std::copy(std::begin(v),p_end,std::ostream_iterator<int>(std::cout," "));
  std::cout << "\nThree of more: ";
  std::copy(p_end,std::end(v),std::ostream_iterator<int>(std::cout," "));
  std::cout << "\n";
}

/* Screen output:

Less than three: 1 2
Three of more: 3 4 5
Press <RETURN> to close this window...

*/
