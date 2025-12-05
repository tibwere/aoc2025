#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main(void) {
        std::string l;
        std::vector<std::pair<ulong, ulong>> fresh_ranges;

        while (std::getline(std::cin, l)) {
                if (l.empty())
                        break;

                ulong begin, end;
                if (std::sscanf(l.c_str(), "%lu-%lu", &begin, &end) != 2)
                        return 1;

                std::pair r = {begin, end};
                fresh_ranges.push_back(r);
        }

        std::sort(fresh_ranges.begin(), fresh_ranges.end());

        ulong how_many = 0UL;
        std::pair<ulong, ulong> ur = fresh_ranges.front();
        for (auto i = 1U; i < fresh_ranges.size(); ++i) {
                const auto &curr = fresh_ranges[i];

                if (curr.first <= ur.second) {
                        ur.second = std::max(curr.second, ur.second);
                } else {
                        how_many += (ur.second - ur.first + 1);
                        ur = curr;
                }
        }

        how_many += (ur.second - ur.first + 1);
        std::cout << how_many << std::endl;
        return 0;
}
