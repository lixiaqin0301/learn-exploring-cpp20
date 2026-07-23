/** @file list5611.cpp */
/** Listing 56-11. Move the I/O Operators into the parser Namespace */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <ranges>
#include <string>
#include <string_view>
#include <vector>

namespace parser {
class token {
public:
    token()
        : text_ {}
    {
    }
    token(std::string_view s)
        : text_ { s }
    {
    }
    token &operator=(std::string_view s)
    {
        text_ = s;
        return *this;
    }
    std::string text() const { return text_; }

private:
    std::string text_;
};

std::istream &
operator>>(std::istream &in, parser::token &tok)
{
    std::string str {};
    if (in >> str) {
        tok = str;
    }
    return in;
}

std::ostream &
operator<<(std::ostream &out, parser::token const &tok)
{
    out << tok.text();
    return out;
}
}

int
main(int argc, char *argv[])
{
    std::ifstream input;
    if (argc > 0 && argv[0] != nullptr) {
        input.open(std::string(argv[0]) + ".input");
        if (input.is_open()) {
            std::cin.rdbuf(input.rdbuf());
        }
    }

    using namespace parser;
    using namespace std;

    vector<token> tokens {};
    ranges::copy(ranges::istream_view<token>(std::cin), back_inserter(tokens));
    ranges::copy(tokens, ostream_iterator<token>(cout, "\n"));
}
