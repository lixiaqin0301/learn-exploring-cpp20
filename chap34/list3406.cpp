/** @file list3406.cpp */
/** Listing 34-6. Visual Constructors */
#include <iostream>

struct demo {
    demo(): demo { 0 } { std::cout << "default constructor\n"; }
    demo(demo const &that): x_ { that.x_ } { std::cout << "copy constructor(" << x_ << ")\n"; }
    demo(demo &&that) noexcept: x_ { that.x_ } { std::cout << "move constructor(" << x_ << ")\n"; }
    demo &operator=(demo const &that)
    {
        x_ = that.x_;
        std::cout << "copy operator=(" << x_ << ")\n";
        return *this;
    }
    demo &operator=(demo &&that) noexcept
    {
        x_ = that.x_;
        std::cout << "move operator=(" << x_ << ")\n";
        return *this;
    }
    ~demo() { std::cout << "deconstructor(" << x_ << ")\n"; }
    explicit demo(int x): x_ { x } { std::cout << "constructor(" << x << ")\n"; }
    int x_;
};

demo
addone(demo d)
{
    ++d.x_;
    return d;
}

int
main()
{
    demo d1 {};
    demo d2 { d1 };
    demo d3 { 42 };
    demo d4 { addone(d3) };
    return 0;
}
