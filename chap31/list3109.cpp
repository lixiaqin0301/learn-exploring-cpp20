/** Listing 31-9. Constructing a Rational Number from a Floating-Point Argument */
#include <cassert>
#include <iostream>
#include <numeric>

struct rational {
    rational(int num, int den): numerator { num }, denominator { den } { reduce(); }

    rational(double r): rational { static_cast<int>(r * 100000), 100000 } { }

    //   ... omitted for brevity ...

    /// Reduces the numerator and denominator by their GCD.
    void reduce()
    {
        assert(denominator != 0);
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        int div { std::gcd(numerator, denominator) };
        numerator = numerator / div;
        denominator = denominator / div;
    }

    int numerator;
    int denominator;
};

int
main()
{
    rational pi(3.1415926535897932);
    std::cout << pi.numerator << '/' << pi.denominator << '\n';
    return 0;
}
