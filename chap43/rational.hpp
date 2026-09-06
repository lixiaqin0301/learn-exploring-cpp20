/** @file rational.hpp */
/** Listing 43-1. The Interface Header for rational in rational.hpp */
#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_

#include <iosfwd>
class rational {
public:
    rational(int num): numerator_ { num }, denominator_ { 1 } { }
    rational(rational const &) = default;
    rational(int num, int den): numerator_ { num }, denominator_ { den } { reduce(); }
    void assign(int num, int den);
    int numerator() const { return numerator_; }
    int denominator() const { return denominator_; }
    rational &operator=(int num);

private:
    void reduce();
    int numerator_;
    int denominator_;
};

std::ostream &operator<<(std::ostream &, rational const &);

#endif // RATIONAL_HPP_
