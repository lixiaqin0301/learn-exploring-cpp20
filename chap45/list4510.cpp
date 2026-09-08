/** @file list4510.cpp */
/** Listing 45-10. Using replace_if and intrange to Replace All Integers in [10, 20] with 0 */
#include "data.hpp"
#include "intrange.hpp"
#include <algorithm>

int
main()
{
    intvector data {};
    read_data(data);
    write_data(data);
    std::ranges::replace_if(data, intrange { 10, 20 }, 0);
    write_data(data);
    return 0;
}
