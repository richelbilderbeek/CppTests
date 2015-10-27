#include <vector>
#include <iterator>
#include <iostream>
#include <ostream>

template<class T>
struct is_container
{
    static const bool value = false;
};

template<>
template<class T, class Alloc>
struct is_container<std::vector<T, Alloc>>
{
    static const bool value = true;
};

//From http://www.richelbilderbeek.nl/CppCoutContainer.htm
template <class Container>
void CoutContainer(const Container& c)
{
  static_assert(is_container<Container>::value,"Container must be a container");
  std::copy(
    std::begin(c),
    std::end(c),
    std::ostream_iterator<typename Container::value_type>(std::cout,"\n")
  );
}

int main()
{
  //Create a vector
  std::vector<int> v;
  v.push_back(1);
  v.push_back(4);
  v.push_back(9);
  v.push_back(16);
  v.push_back(25);

  //Show it on screen using CoutContainer
  CoutContainer(v);
}

