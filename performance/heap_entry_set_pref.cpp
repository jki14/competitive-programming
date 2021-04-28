#include "../joshu.hpp"

void solution(int const n, int const m) {
  std::mt19937 gen(14);

  joshu::heap_t<int> foo(n);

  std::vector<int> bar;
  bar.reserve(n);
  for (int i = 0; i < n; ++i) {
    bar.emplace_back(gen());
  }

  auto entries = foo.load(bar);

  for (int i = 0; i < m; ++i) {
    (*entries[gen() % n])->set(gen());
  }
}

int main() {
  solution(1048576, 16777216);
  return 0;
}
