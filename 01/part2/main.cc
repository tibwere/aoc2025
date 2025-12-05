#include <cstdio>
#include <iostream>
#include <stdexcept>
#include <string>

#define MOD 100

void update(int &cursor, int &psw, int length, char direction) {
        if (direction != 'L' && direction != 'R')
                throw std::invalid_argument(
                    "direction must be either 'L' or 'R'");

        auto step = (direction == 'L') ? -length : length;
        auto part = (direction == 'L') ? cursor : MOD - cursor;

        // first of all we increment psw a time for each full loop
        psw += (length - part) / MOD;
        cursor = (((cursor + step) % MOD) + MOD) % MOD;

        // if we are arrived on 0, then +1 is required
        // if length is bigger than part but we have not started by 0, then
        // +1 is required
        //
        // 0      7 9
        // |      * |
        //        `--------- suppose we started here
        // R5 is issued then:
        //	- part is 2
        //	- lenght is 5
        //	- no full loop is made
        //	- a single partial loop is made
        //
        // 0      7 9
        // *        |
        // `---------------- suppose we started here now
        //
        // L5 is issued then:
        // - part is 0
        // - lenght is 5
        // - no full loop is made
        // - no single partial loop is made either (indeed we need part != 0)
        //
        if (!cursor || (part && (length > part)))
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
