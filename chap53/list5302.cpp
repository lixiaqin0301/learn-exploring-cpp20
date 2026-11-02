/** Listing 53-2. Specializing rational<void> */
#include <iostream>

#include "rational.hpp"

template<>
class rational<void> {
public:
    using value_type = void;
    rational() { }

    int numerator() const { return 0; }
    int denominator() const { return 1; }
};

int
main()
{
    rational<void> r;
    std::cout << r << '\n';
}
