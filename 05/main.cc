#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(void) {
        std::string l;
        std::vector<std::pair<ulong, ulong>> fresh;
        auto counter = 0UL;

        while (std::getline(std::cin, l)) {
                if (l.empty())
                        break;

                ulong begin, end;
                if (std::sscanf(l.c_str(), "%lu-%lu", &begin, &end) != 2)
                        return 1;

                std::pair r = {begin, end};
                fresh.push_back(r);
        }

        std::sort(fresh.begin(), fresh.end());

        while (std::getline(std::cin, l)) {
                ulong id = std::strtoul(l.c_str(), NULL, 10);

                for (const auto &p : fresh) {
                        if (p.first <= id && id <= p.second) {
                                counter++;
                                break;
                        }
                }
        }

        std::cout << counter << std::endl;
        return 0;
}
