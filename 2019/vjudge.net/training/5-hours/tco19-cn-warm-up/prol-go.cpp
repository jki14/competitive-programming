#include <iostream>

constexpr int foo[] = [1, 2, 3];

int main() {
  std::ios_base::sync_with_stdio(0);
  int n;
  while (std::cin >> n) {
    for (int i = 0; i < n; ++i) {
      int x;
      std::cin >> x;
      std::cout << foo[x] << std::endl;
    }
  }
  return 0;
}
