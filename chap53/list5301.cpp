/** Listing 53-1. The is_void Class Template */
#include <iostream>

template<class T>
class is_void: public std::false_type { };

template<>
class is_void<void>: public std::true_type { };

int
main()
{
    std::cout << std::boolalpha << is_void<int>::value << '\n' << is_void<void>::value << '\n';
}
