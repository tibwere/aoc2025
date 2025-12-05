#include <deque>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

#define MOD 100

uint remove_valid(std::deque<std::string> &paper_rolls) {
        std::stack<std::pair<uint, uint>> indexes;
        uint valid = 0U;

        for (auto i = 1U; i < paper_rolls.size() - 1; ++i) {
                for (auto j = 1U; j < paper_rolls[i].size() - 1; ++j) {
                        uint how_many = 0U;

                        if (paper_rolls[i][j] == '.')
                                continue;

                        if (paper_rolls[i - 1][j - 1] == '@')
                                how_many++;

                        if (paper_rolls[i - 1][j] == '@')
                                how_many++;

                        if (paper_rolls[i - 1][j + 1] == '@')
                                how_many++;

                        if (paper_rolls[i + 1][j - 1] == '@')
                                how_many++;

                        if (paper_rolls[i + 1][j] == '@')
                                how_many++;

                        if (paper_rolls[i + 1][j + 1] == '@')
                                how_many++;

                        if (paper_rolls[i][j - 1] == '@')
                                how_many++;

                        if (paper_rolls[i][j + 1] == '@')
                                how_many++;

                        if (how_many < 4) {
                                indexes.push({i, j});
                                valid++;
                        }
                }
        }

        while (!indexes.empty()) {
                auto coord = indexes.top();
                indexes.pop();

                paper_rolls[coord.first][coord.second] = '.';
        }

        return valid;
}

int main(void) {
        std::string l;
        std::deque<std::string> paper_rolls;
        uint count = 0, c = 0;

        while (std::cin >> l) {
                l.insert(0, ".");
                l.insert(l.size(), ".");
                paper_rolls.push_back(l);
        }

        std::string dummy_row(paper_rolls[0].size(), '.');
        paper_rolls.push_front(dummy_row);
        paper_rolls.push_back(dummy_row);

        for (;;) {
                c = remove_valid(paper_rolls);
                if (!c)
                        break;

                count += c;
        }

        std::cout << count << std::endl;
        return 0;
}
