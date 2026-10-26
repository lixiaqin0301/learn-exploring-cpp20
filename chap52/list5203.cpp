#include <iostream>
#include <numeric>

class zero_denominator : public std::logic_error {
public:
    using logic_error::logic_error;
};

/** Listing 52-3. The rational Class Template */
template <class T> class rational {
public:
    using value_type = T;
    rational(): rational { 0 } { }
    rational(value_type num): numerator_ { num }, denominator_ { 1 } { }
    rational(value_type num, value_type den): numerator_ { num }, denominator_ { den } { reduce(); }

    void assign(value_type num, value_type den);

    rational const &operator+=(rational const &rhs);
    rational const &operator-=(rational const &rhs);
    rational const &operator*=(rational const &rhs);
    rational const &operator/=(rational const &rhs);

    template <class U> U convert() const { return static_cast<U>(numerator()) / static_cast<U>(denominator()); }

    value_type const &numerator() const { return numerator_; }
    value_type const &denominator() const { return denominator_; }

private:
    void reduce();
    value_type numerator_;
    value_type denominator_;
};

template <class T>
void
rational<T>::assign(value_type num, value_type den)
{
    numerator_ = num;
    denominator_ = den;
    reduce();
}

template <class T>
void
rational<T>::reduce()
{
    if (denominator() == value_type {}) {
        throw zero_denominator("divide by zero in rational");
    }
    if (denominator() < value_type {}) {
        denominator_ = -denominator();
        numerator_ = -numerator();
    }
    T div { std::gcd(numerator(), denominator()) };
    numerator_ = numerator() / div;
    denominator_ = denominator() / div;
}

template <class T>
bool
operator==(rational<T> const &a, rational<T> const &b)
{
    return a.numerator() == b.numerator() and a.denominator() == b.denominator();
}

template <class T>
inline bool
operator!=(rational<T> const &a, rational<T> const &b)
{
    return not(a == b);
}

template <class T>
std::ostream &
operator<<(std::ostream &stream, rational<T> const &r)
{
    std::cout << r.numerator() << '/' << r.denominator();
    return stream;
}

int
main()
{
    /** Code Snippet 52-3 */
    rational<short> zero {};
    rational<int> pi1 { 355, 113 };
    rational<long> pi2 { 80143857L, 25510582L };
    std::cout << zero << '\n' << pi1 << '\n' << pi2 << '\n';
}
