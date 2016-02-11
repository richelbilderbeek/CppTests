#include <iostream>
#include <cassert>
#include <typeindex>

#include <string>
#include <cstdlib>
#include <cxxabi.h>

//From http://stackoverflow.com/questions/1055452/c-get-name-of-type-in-template
//Thanks to m-dudley ( http://stackoverflow.com/users/111327/m-dudley )
template<typename T>
std::string get_type_name()
{
  std::string tname = typeid(T).name();
  int status = -1;
  char * const demangled_name{
    abi::__cxa_demangle(tname.c_str(), NULL, NULL, &status)
  };
  if(status == 0) {
      tname = demangled_name;
      std::free(demangled_name);
  }
  return tname;
}

template<typename T>
void cout_type()
{
  std::cout << get_type_name<T>() << std::endl;
}

#include <vector>
#include <list>
#include <cassert>
int main()
{
  assert(get_type_name<double>() == "double");
  assert(get_type_name<int>() == "int");
  assert(get_type_name<std::vector<int>>()
    == "std::vector<int, std::allocator<int> >"
  );


  cout_type<double>();

  cout_type<std::vector<int>>();
  cout_type<std::vector<std::list<int>>>();

}


