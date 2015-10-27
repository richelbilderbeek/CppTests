#include <vector>
#include <list>
#include <iterator>
#include <iostream>
#include <ostream>

template <typename Container>
struct is_container : std::false_type { };

template <typename... Ts> struct is_container<std::list<Ts...> > : std::true_type { };
template <typename... Ts> struct is_container<std::vector<Ts...> > : std::true_type { };

int main()
{
  static_assert(!is_container< int >::value,"");

  static_assert(is_container< std::vector<int> >::value,"");
  static_assert(is_container< std::list<int> >::value,"");
}

