#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>

bool is_invalid(const ulong &pattern_size, const std::string &curr) {
        const auto &pattern = curr.substr(0, pattern_size);

        for (auto i = 1UL; i < curr.size() / pattern_size; ++i) {
                const auto &s = curr.substr(i * pattern_size, pattern_size);

                if (s != pattern)
                        return false;
        }

        return true;
}

ulong count_invalid(ulong begin, ulong end) {
        auto invalid = 0UL;

        for (ulong i = begin; i <= end; ++i) {
                const auto &curr = std::to_string(i);
                for (auto j = curr.size() / 2; j > 0; --j) {
                        if (curr.size() % j != 0)
                                continue;

                        if (is_invalid(j, curr)) {
                                invalid += i;
                                break;
                        }
                }
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
