#include "list5701.hh"
#include <iostream>
int
main()
{
    rational<int> r { 1, 2 };
    std::cout << std::hash<rational<int>> {}(r) << '\n';
}
