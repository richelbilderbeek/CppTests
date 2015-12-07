//ERROR: Cannot be found
//#include <boost/type_index.hpp>

#include <boost/type_traits.hpp>
#include <boost/typeof/typeof.hpp>

#include <iostream>

template <class T>
void foo(T) {
    std::cout << "\n Short name: " << boost::typeindex::type_id<T>().raw_name();
    std::cout << "\n Readable name: " << boost::typeindex::type_id<T>().pretty_name();
}

struct user_defined_type{};

namespace ns1 { namespace ns2 {
    struct user_defined_type{};
}} // namespace ns1::ns2

namespace {
    struct in_anon_type{};
} // anonymous namespace

int main() {
    // Call to
    foo(1);
    // will output something like this:
    //
    // (RTTI on)                                            (RTTI off)
    // Short name: i                                        Short name: int]
    // Readable name: int                                   Readable name: int

    user_defined_type t;
    foo(t);
    // Will output:
    //
    // (RTTI on)                                            (RTTI off)
    // Short name: 17user_defined_type                      user_defined_type]
    // Readable name: user_defined_type                     user_defined_type

    ns1::ns2::user_defined_type t_in_ns;
    foo(t_in_ns);
    // Will output:
    //
    // (RTTI on)                                            (RTTI off)
    // Short name: N3ns13ns217user_defined_typeE            ns1::ns2::user_defined_type]
    // Readable name: ns1::ns2::user_defined_type           ns1::ns2::user_defined_type

    in_anon_type anon_t;
    foo(anon_t);
    // Will output:
    //
    // (RTTI on)                                            (RTTI off)
    // Short name: N12_GLOBAL__N_112in_anon_typeE           {anonymous}::in_anon_type]
    // Readable name: (anonymous namespace)::in_anon_type   {anonymous}::in_anon_type
}
