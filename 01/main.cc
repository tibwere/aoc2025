#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

#define MOD 100

constexpr void update(int &cursor, int &psw, int length, char direction) {
        if (direction != 'L' && direction != 'R')
                throw std::invalid_argument(
                    "direction must be either 'L' or 'R'");

        auto step = (((direction == 'L') ? -1 : 1) * length);
        cursor = (((cursor + step) % MOD) + MOD) % MOD;
        if (!cursor)
                psw++;
}

int main(void) {
        int length, psw = 0, cursor = 50;
        std::string l;
        char direction;

        while (std::cin >> l) {
                if (std::sscanf(l.c_str(), "%c%u", &direction, &length) != 2)
                        return 1;

                update(cursor, psw, length, direction);
        }

        std::cout << psw << std::endl;
        return 0;
}
