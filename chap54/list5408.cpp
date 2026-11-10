/** Listing 54-8. Specializing fixed for N == 0 */
#include <iomanip>
#include <iostream>

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

template<class T, int N>
class fixed {
public:
    using value_type = T;
    static constexpr int places { N };
    static constexpr int places10 { ipower(10, N) };
    fixed();
    fixed(T const &integer, T const &fraction);
    fixed &operator=(fixed const &rhs);
    fixed &operator+=(fixed const &rhs);
    fixed &operator*=(fixed const &rhs);

    void print(std::ostream &stream) const
    {
        stream << value_ / places10;
        if (auto f = value_ % places10) {
            stream << '.' << std::setw(places) << std::setfill('0') << std::right << f;
        }
    }

private:
    T value_; // scaled to N decimal places
};

template<class T, int N>
fixed<T, N>::fixed(value_type const &integer, value_type const &fraction): value_(integer * places10 + fraction)
{
}

template<class T1, int N1, class T2, int N2>
bool operator==(fixed<T1, N1> const &a, fixed<T2, N2> const &b);

template<class T>
class fixed<T, 0> {
public:
    using value_type = T;
    static constexpr T places { 0 };
    static constexpr T places10 { 1 };
    fixed(): value_ {} { }
    fixed(T const &integer, T const &);
    fixed &operator=(fixed const &rhs) { value_ = rhs; }
    fixed &operator+=(fixed const &rhs) { value_ += rhs; }
    fixed &operator*=(fixed const &rhs) { value_ *= rhs; }

    void print(std::ostream &stream) const { stream << value_; }

private:
    T value_; // no need for scaling
};

template<class T>
fixed<T, 0>::fixed(value_type const &integer, value_type const &): value_(integer)
{
}

template<class T, int N>
std::ostream &
operator<<(std::ostream &stream, fixed<T, N> const &f)
{
    f.print(stream);
    return stream;
}

int
main()
{
    fixed<long, 0> f { 12, 3450 };
    std::cout << f << '\n';
}
