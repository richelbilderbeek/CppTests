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

#ifdef DOES_NOT_WORK_AS_HOPED_FOR
constexpr const char * get(const color c) {
  static_assert(static_cast<int>(color::red  ) == 0,"");
  static_assert(static_cast<int>(color::green) == 1,"");
  static_assert(static_cast<int>(color::blue ) == 2,"");
  static_assert(create_lookup_table().size()   == 3,"");
  const unsigned int index{static_cast<unsigned int>(c)};
  assert(index < create_lookup_table().size());
  return std::get<1>(create_lookup_table()[index]);

}
#endif

#include <algorithm>
#include <sstream>
std::string color_to_str(const color c) noexcept
{
  constexpr auto lut = create_lookup_table();
  const auto i = std::find_if(
    std::begin(lut),
    std::end(lut),
    [c](const auto p) { return std::get<0>(p) == c; }
  );
  assert(i != std::end(lut));
  return std::get<1>(*i);
}

color str_to_color(const std::string& s)
{
  constexpr auto lut = create_lookup_table();
  const auto i = std::find_if(
    std::begin(lut),
    std::end(lut),
    [s](const auto p) { return std::get<1>(p) == s; }
  );

  if (i == std::end(lut)) {
    std::stringstream t;
    t << __func__ << ": cannot convert " << s << " to color";
    throw std::logic_error(t.str());

  }
  return std::get<0>(*i);
}

std::ostream& operator<<(std::ostream& os, const color c)
{
  os << color_to_str(c);
  return os;
}

#include <iostream>
#include <iterator>

int main()
{
  constexpr color colors[] = { color::red, color::green, color::blue };
  std::transform(
    std::begin(colors),
    std::end(colors),
    std::ostream_iterator<std::string>(std::cout,"\n"),
    [](const auto c) { return color_to_str(c); }
  );

  const std::string color_strs[] = { "red", "green", "blue" };
  std::transform(
    std::begin(color_strs),
    std::end(color_strs),
    std::ostream_iterator<color>(std::cout,"\n"),
    [](const auto s) { return str_to_color(s); }
  );

}
