#include <iostream>
#include <string>
#include <vector>

#define MOD 100

ulong get_joltage(std::vector<uint> &bank) {
        std::vector<uint> st;
        auto to_be_removed = bank.size() - 12;

        for (auto d : bank) {
                while (to_be_removed > 0 && !st.empty() && st.back() < d) {
                        st.pop_back();
                        to_be_removed--;
                }

                st.push_back(d);
        }

        std::string output;
        for (auto i = 0U; i < 12; ++i)
                output += std::to_string(st[i]);

        return std::stoull(output, nullptr, 0);
}

int main(void) {
        std::string l;
        std::vector<uint> bank;
        ulong output = 0UL;

        while (std::cin >> l) {
                bank.clear();
                for (auto c : l)
                        bank.push_back(c - '0');

                output += get_joltage(bank);
        }

        std::cout << output << std::endl;
        return 0;
}
