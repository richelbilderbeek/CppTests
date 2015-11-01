#include <array>
#include <cassert>
#include <tuple>
#include <utility>

//From http://stackoverflow.com/questions/27490858/how-can-you-compare-two-character-strings-statically-at-compile-time
constexpr bool strings_equal(char const * const a, char const * const b) {
    return *a == *b && (*a == '\0' || strings_equal(a + 1, b + 1));
}

enum class color { red, green, blue };

constexpr std::array<std::tuple<color,const char *>,3>
create_lookup_table() {
  return {
    std::make_tuple(color::red,"red"),
    std::make_tuple(color::green,"green"),
    std::make_tuple(color::blue,"blue"),
  };
}

#include <iostream>
#include <algorithm>
#include <iterator>

int main()
{
  static_assert(create_lookup_table().size() == 3,"");
  static_assert(std::get<0>(std::get<0>(create_lookup_table())) == color::red,"");
  static_assert(std::get<0>(std::get<1>(create_lookup_table())) == color::green,"");
  static_assert(std::get<0>(std::get<2>(create_lookup_table())) == color::blue,"");
  static_assert( strings_equal("red","red"),"");
  static_assert(!strings_equal("red","green"),"");
  static_assert(strings_equal("red"  ,std::get<1>(std::get<0>(create_lookup_table()))),"");
  static_assert(strings_equal("green",std::get<1>(std::get<1>(create_lookup_table()))),"");
  static_assert(strings_equal("blue" ,std::get<1>(std::get<2>(create_lookup_table()))),"");

  constexpr auto lut = create_lookup_table();

  std::transform(
    std::begin(lut),
    std::end(lut),
    std::ostream_iterator<const char*>(std::cout,"\n"),
    [](const auto p) { return std::get<1>(p); }
  );

}
