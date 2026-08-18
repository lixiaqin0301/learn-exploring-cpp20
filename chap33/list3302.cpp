/** Listing 33-2. Assignment Operator with Explicit Use of this-> */

#include <cassert>
#include <numeric>

class rational {
public:
    rational(int num, int den): numerator { num }, denominator { den } { }
    rational &operator=(rational const &that)
    {
        this->numerator = that.numerator;
        this->denominator = that.denominator;
        reduce();
        return *this;
    }

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
    int numerator;
    int denominator;
};

int
main()
{
    rational a { 1, 1 };
    rational b { 2, 1 };
    b = a;
    return 0;
}
