#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <string>

int main()
{
  std::vector<double> payoffs = {1.0, 3.0, 2.0 };
  std::mt19937 rng_engine;
  std::discrete_distribution<int> dist(std::begin(payoffs),std::end(payoffs));

  std::vector<int> tally(payoffs.size(),0);
  for (int i=0; i!=600; ++i)
  {
    const int random_index = dist(rng_engine);
    ++tally[random_index];
  }

  std::copy(
    std::begin(tally),
    std::end(tally),
    std::ostream_iterator<int>(std::cout,"\n")
  );
}

/* Screen output:

90
303
207

*/
