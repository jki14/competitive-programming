#include <algorithm>
#include <iostream>

int solution(const int a, const int b, const int c) {
    int s = a + b + c;
    int p = std::max(a, std::max(b, c));
    return s - p + p * 10;
}

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << solution(a, b, c) << std::endl;
    return 0;
}
