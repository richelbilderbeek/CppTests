#include <array>
#include <cassert>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <vector>

int main()
{
  {
    const int sz = 5;
    int v[sz];
    assert(sizeof(v) / sizeof(int) == sz);
  }
  {
    const int sz = (std::rand() % 2) - 100;
    assert(sz < 0 && "sz will always be negative, yet I can create an array of this size");
    int v[sz]; //Will be accepted

    if (static_cast<int>(sizeof(v) / sizeof(int)) == sz) {
      assert(!"Should not get here");
    }
    else {
      //Luckily, this can be detected
    }
    //v[0] = 0; //Crashes the program
  }
  {
    const int sz = (std::rand() % 2) - 100;
    assert(sz < 0 && "sz will always be negative, yet I can create an array of this size");
    try {
      std::vector<int> v(sz); //Throws std::bad_alloc
      assert(!"Should not get here");
    }
    catch (std::bad_alloc&) {
      //Thanks!
    }
  }
}

