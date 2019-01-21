#include <iostream>
#include <string>
#include <vector>
#include <bitset>

void solution(const std::vector<std::bitset<100>> &a, const int w) {
    std::bitset<100> mask;
    for (const std::bitset<100> &row : a) {
        mask |= row;
    }
    for (const std::bitset<100> &row : a) {
        if (row.any()) {
            for (int j = 0; j < w; ++j) {
                if (!mask[j]) continue;
                if (row[j]) {
                    std::cout << '#';
                } else {
                    std::cout << '.';
                }
            }
            std::cout << std::endl;
        }
    }
}

int main() {
    std::vector<std::bitset<100>> a;
    int h, w;
    std::cin >> h >> w;
    for (int i = 0; i < h; ++i) {
        std::string buf;
        std::cin >> buf;
        std::bitset<100> row;
        for (int j = 0; j < w; ++j) {
            if (buf[j] == '#') row.set(j);
        }
        a.push_back(row);
    }
    solution(a, w);
    return 0;
}
