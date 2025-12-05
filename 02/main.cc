#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

ulong count_invalid(ulong begin, ulong end) {
        auto invalid = 0UL;

        for (ulong i = begin; i <= end; ++i) {
                auto curr = std::to_string(i);
                if (curr.size() % 2 != 0)
                        continue;

                auto f = curr.substr(0, curr.size() / 2);
                auto s = curr.substr(curr.size() / 2, curr.size() / 2);

                if (f != s)
                        continue;

                invalid += i;
        }

        return invalid;
}

int main(void) {
        std::string l, range;
        std::cin >> l;
        ulong invalid = 0UL;

        std::stringstream st(l);
        while (std::getline(st, range, ',')) {
                ulong begin, end;
                std::sscanf(range.c_str(), "%lu-%lu", &begin, &end);
                invalid += count_invalid(begin, end);
        }

        std::cout << invalid << std::endl;
        return 0;
}
