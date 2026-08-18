/** Listing 33-1. First Version of the Assignment Operator */

#include <cassert>
#include <numeric>

struct rational {
    rational() = default;
    rational(rational const &rhs) { assign(rhs); }
    rational(rational &&rhs) { assign(rhs); }
    rational &operator=(rational const &rhs) { return assign(rhs); }
    rational &operator=(rational &&rhs) { return assign(rhs); };
    rational(int num, int den): numerator { num }, denominator { den } { reduce(); }

private:
    rational &assign(rational const &rhs)
    {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
        reduce();
        return *this;
    }
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
    int numerator = 0;
    int denominator = 1;
};

int
main()
{
    rational a { 1, 2 };
    rational b { 3, 4 };
    b = a;
    return 0;
}
