/** @file list4602.cpp */
/** Listing 46-2. Advancing an Iterator */
#include "data.hpp"
#include "sequence.hpp"
#include <algorithm>
#include <iostream>
#include <iterator>

int
main()
{
    intvector data(10);
    // fill with even numbers
    std::generate(data.begin(), data.end(), sequence { 0, 2 });
    auto iter { data.begin() };
    std::advance(iter, 4);
    std::cout << *iter << ", ";
    iter = std::prev(iter, 2);
    std::cout << *iter << '\n';
    return 0;
}
