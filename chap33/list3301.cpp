/** Listing 33-1. First Version of the Assignment Operator */
#include <cassert>
#include <numeric>

struct rational {
public:
    rational() = default;
    rational(rational const &rhs) = default;
    rational(rational &&rhs) noexcept = default;
    rational &operator=(rational const &rhs)
    {
        numerator = rhs.numerator;
        denominator = rhs.denominator;
        reduce();
        return *this;
    }
    rational &operator=(rational &&rhs) noexcept = default;
    ~rational() = default;
    rational(int num, int den): numerator { num }, denominator { den } { reduce(); }

private:
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
    rational b;
    b = a;
    return 0;
}
