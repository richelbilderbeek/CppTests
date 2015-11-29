#include <cassert>
#include <vector>

int main()
{
  //Copying a statically allocated array
  {
    //Cannot copy an array
    const int v[] = {1,4,9,16};
    //const int w[] = v;

    //Can easily copy a std::vector
    const std::vector<int> a{1,4,9,16};
    const std::vector<int> b{a};
    assert(a == b);
  }
  //Copying a dynamically allocated array
  {
    //Create v
    const int sz{4};
    int * v{new int[sz]};
    for (int i{0}; i!=sz; ++i) { v[i] = i*i; }

    //Copy
    //int * const w{v}; //Only copies the pointer
    int * w{new int[sz]}; //Create new dynamic memory
    for (int i{0}; i!=sz; ++i) { w[i] = v[i]; }

    delete[] v;
    delete[] w;

    //Can easily copy a std::vector
    const std::vector<int> a{1,4,9,16};
    const std::vector<int> b{a};
    assert(a == b);
  }
  //Check for equality
  {
    //Create v
    const int sz{4};
    int * const v{new int[sz]};
    for (int i{0}; i!=sz; ++i) { v[i] = i*i; }

    //Copy
    //int * const w{v}; //Only copies the pointer
    int * const w{new int[sz]}; //Only copies the pointer
    for (int i{0}; i!=sz; ++i) { w[i] = v[i]; }
    //assert(v == w); //This what you would like. It fails because it compares the pointers

    delete[] v;
    delete[] w;

    //Can easily copy a std::vector
    const std::vector<int> a{1,4,9,16};
    const std::vector<int> b{a};
    assert(a == b);
  }
}

