/** Listing 54-7. Computing a Power of 10 at Compile Time */
#include <iostream>
#include <stdexcept>

/// Compute base to the exp-th power at compile time.
template<class Base, class Exp>
Base constexpr ipower(Base base, Exp exp)
{
    if (exp < Exp {}) {
        throw std::domain_error("No negative powers of 10");
    }
    if (exp == Exp {}) {
        if (base == Base {}) {
            throw std::domain_error("0 to 0th power is not allowed");
        }
        return Base { 1 };
    }

    Base power { base };
    for (Exp e { 1 }; e != exp;) {
        // invariant(power == base ** e)
        if (e + e < exp) {
            power *= power;
            e += e;
        } else {
            power *= base;
            ++e;
        }
    }
    return power;
}

int
main()
{
    constexpr int x1 { ipower(0, 10) };
    constexpr int x2 { ipower(10, 0) };
    constexpr int x3 { ipower(10, 3) };
    constexpr int x4 { ipower(2, 3) };
    constexpr int x5 { ipower(3, 4) };

    std::cout << x1 << '\n' << x2 << '\n' << x3 << '\n' << x4 << '\n' << x5 << '\n';
}
