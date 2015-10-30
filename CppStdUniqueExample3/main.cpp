#include <cassert>
#include <memory>

int main()
{
  std::unique_ptr<int> p;
  {
    //Goal: move x in p so that p acquires the value 42 and
    //when x goes out of scope p still holds a valid address
    int x = 42;

    //Does not compile
    p = std::move(x);

    //Does not compile
    assert(&x == nullptr); //Error: the address of 'x' will never be NULL
  }


}
