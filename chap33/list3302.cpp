/** Listing 33-2. Assignment Operator with Explicit Use of this-> */
#include <cassert>
#include <numeric>

class rational {
public:
    rational() = default;
    rational(rational const &rhs) = default;
    rational(rational &&rhs) noexcept = default;
    rational &operator=(rational const &rhs)
    {
        this->numerator = rhs.numerator;
        this->denominator = rhs.denominator;
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
    rational a { 3, 3 };
    rational b;
    b = a;
    return 0;
}
