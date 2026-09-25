/** @file list4604.cxx */
/** Listing 46-4. Printing the Middle Item of a Series of Integers */
#include "data.hpp"
#include <iostream>
#include <iterator>

int
main()
{
    intvector data {};
    read_data(data);
    const intvector::iterator iter { data.begin() };
    std::advance(iter, data.size() / 2); // move to middle of vector
    if (not data.empty()) {
        std::cout << "middle item = " << *iter << '\n';
    }
    return 0;
}
