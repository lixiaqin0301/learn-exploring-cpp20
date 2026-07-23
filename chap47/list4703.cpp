/** @file list4703.cpp */
/** Listing 47-3. Computing Scores By Using Views */
#include <algorithm>
#include <fstream>
#include <iostream>
#include <ranges>
#include <string>
#include <vector>

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

    std::cout << "Enter the scores: ";
    std::vector<int> scores {};
    std::ranges::copy(std::ranges::istream_view<int>(std::cin), std::back_inserter(scores));
    std::ranges::sort(scores);
    auto drop_high { scores | std::ranges::views::take(scores.size() - 1) };
    auto remaining_scores { drop_high | std::ranges::views::drop(1) };

    int sum { 0 };
    int count { 0 };
    for (int score : remaining_scores) {
        ++count;
        sum += score;
    }
    std::cout << "mean score is " << sum / count << '\n';
}
