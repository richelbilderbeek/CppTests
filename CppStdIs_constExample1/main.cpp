#include <type_traits>

int main()
{
  static_assert(!std::is_const<     int >::value,"int is not const");
  static_assert( std::is_const<const int>::value,"const int is const");
}
