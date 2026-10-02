/** @file list4808.hh */
/** Listing 48-8. Checking for a Zero Denominator in reduce() */
#include <numeric>
#include <stdexcept>
class rational {
public:
    class zero_denominator : public std::logic_error {
    public:
        using std::logic_error::logic_error;
    };
    rational(): numerator_ {}, denominator_ {} { reduce(); }

private:
    void reduce();
    int numerator_;
    int denominator_;
};

inline void
rational::reduce()
{
    if (denominator_ == 0) {
        throw zero_denominator { "denominator is zero" };
    }
    if (denominator_ < 0) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    int div { std::gcd(numerator_, denominator_) };
    numerator_ = numerator_ / div;
    denominator_ = denominator_ / div;
    return;
}
