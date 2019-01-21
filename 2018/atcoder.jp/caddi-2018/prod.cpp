#include <iostream>
#include <vector>

struct square_t {
  int x, y, v;
  square_t() : x(0), y(0), v(0) {}
};

class modint {
  private:
  static const int mod = 998244353;
  int foo;
};

int solution(const int m, const std::vector<square_t> &squares) {
  return 0;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<square_t> squares(m, square_t());
  for (int i = 0; i < m; ++i) {
    std::cin >> squares[i].x >> squares[i].y >> squares[i].v;
  }
  std::cout << solution(n, squares) << std::endl;
  return 0;
}
