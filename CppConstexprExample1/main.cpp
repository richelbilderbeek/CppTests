constexpr int get_size() { return 3; }

#include <cassert>

int main()
{
  int my_array[ get_size() ];

  assert(my_array == 0 || my_array != 0); //Just use the variable
}
