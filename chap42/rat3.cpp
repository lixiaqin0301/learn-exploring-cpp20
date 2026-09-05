#include "rat3.hpp"
#include <cassert>
#include <numeric>

void
rational::assign(int num, int den)
{
    numerator_ = num;
    denominator_ = den;
    reduce();
    return;
}

void
rational::reduce()
{
    assert(denominator_ != 0);
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div { std::gcd(numerator_, denominator_) };
    numerator_ = numerator_ / div;
    denominator_ = denominator_ / div;
    return;
}

rational &
rational::operator=(int num)
{
    numerator_ = num;
    denominator_ = 1;
    return *this;
}
