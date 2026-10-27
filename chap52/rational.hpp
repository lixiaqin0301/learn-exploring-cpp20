#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iostream>
#include <numeric>
#include <stdexcept>

class zero_denominator: public std::logic_error {
public:
    using logic_error::logic_error;
};

template<class T> class rational {
public:
    using value_type = T;
    rational(): rational { 0 } { }
    rational(value_type num): numerator_ { num }, denominator_ { 1 } { }
    rational(value_type num, value_type den);

    void assign(value_type num, value_type den);

    rational const &operator+=(rational const &rhs);
    rational const &operator-=(rational const &rhs);
    rational const &operator*=(rational const &rhs);
    rational const &operator/=(rational const &rhs);

    template<class U> U convert() const { return static_cast<U>(numerator()) / static_cast<U>(denominator()); }

    value_type const &numerator() const { return numerator_; }
    value_type const &denominator() const { return denominator_; }

private:
    void reduce();
    value_type numerator_;
    value_type denominator_;
};

template<class T>
rational<T>::rational(value_type num, value_type den): numerator_ { num }, denominator_ { den }
{
    reduce();
}

template<class T>
void
rational<T>::assign(value_type num, value_type den)
{
    numerator_ = num;
    denominator_ = den;
    reduce();
}

template<class T>
bool
operator==(rational<T> const &a, rational<T> const &b)
{
    return a.numerator() == b.numerator() and a.denominator() == b.denominator();
}

template<class T>
inline bool
operator!=(rational<T> const &a, rational<T> const &b)
{
    return not(a == b);
}

template<class T>
std::ostream &
operator<<(std::ostream &stream, rational<T> const &r)
{
    std::cout << r.numerator() << '/' << r.denominator();
    return stream;
}

template<class T>
std::istream &
operator>>(std::istream &in, rational<T> &rat)
{
    T n {}, d {};
    char sep {};
    if (not(in >> n >> sep)) {
        // Error reading the numerator or the separator character.
        in.setstate(in.failbit);
    } else if (sep != '/') {
        // Push sep back into the input stream, so the next input operation will read it.
        in.unget();
        rat.assign(n, 1);
    } else if (in >> d) {
        // Successfully read numerator, separator, and denominator.
        rat.assign(n, d);
    } else {
        // Error reading denominator.
        in.setstate(in.failbit);
    }

    return in;
}

template<class T>
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

template<class T>
rational<T> const &
rational<T>::operator/=(rational const &rhs)
{
    if (rhs.numerator() == T {}) {
        throw zero_denominator("divide by zero");
    }
    numerator_ *= rhs.denominator();
    denominator_ *= rhs.numerator();
    if (denominator_ < T {}) {
        denominator_ = -denominator_;
        numerator_ = -numerator_;
    }
    reduce();
    return *this;
}

template<class T> inline const rational<T> pi { 31416, 10000 };

#endif
