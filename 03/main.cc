#include <iostream>
#include <string>
#include <vector>

#define MOD 100

unsigned int max_jolts(std::vector<uint> &bank) {
        uint i, j;
        uint max[2], saved_idx;

        saved_idx = 0;
        max[0] = bank[0];
        for (i = 1U; i < bank.size() - 1; ++i)
                if (bank[i] > max[0]) {
                        saved_idx = i;
                        max[0] = bank[i];
                }

        max[1] = bank[++saved_idx];
        for (j = saved_idx + 1; j < bank.size(); ++j)
                if (bank[j] > max[1]) {
                        saved_idx = j;
                        max[1] = bank[j];
                }

        return max[0] * 10 + max[1];
}

int main(void) {
        std::string l;
        std::vector<uint> bank;
        uint output = 0U;

        while (std::cin >> l) {
                bank.clear();
                for (auto c : l)
                        bank.push_back(c - '0');

                output += max_jolts(bank);
        }

        std::cout << output << std::endl;
        return 0;
}
