#include "bits/stdc++.h"

#ifdef UNITTEST
#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/ui/text/TestRunner.h"
#endif

namespace joshu {
/* Utils */
inline namespace {
template<typename Lhs, typename Rhs,
         typename std::enable_if<
             std::is_integral<Lhs>::value && std::is_signed<Lhs>::value &&
             std::is_integral<Rhs>::value && std::is_signed<Rhs>::value
         >::type* = nullptr>
struct super_integral_t {
  typedef typename std::conditional<
      std::numeric_limits<Lhs>::max() >=
      std::numeric_limits<Rhs>::max(), Lhs, Rhs
  >::type type;
};
template<typename Int>
struct is_unsigned_int {
  static constexpr bool value =
    std::is_integral<Int>::value && std::is_unsigned<Int>::value &&
    std::numeric_limits<Int>::max() <=
    std::numeric_limits<unsigned int>::max();
};
template<typename Int>
struct is_unsigned_long {
  static constexpr bool value =
    !is_unsigned_int<Int>::value &&
    std::is_integral<Int>::value && std::is_unsigned<Int>::value &&
    std::numeric_limits<Int>::max() <=
    std::numeric_limits<unsigned long>::max();
};
template<typename Int>
struct is_unsigned_long_long {
  static constexpr bool value =
    !is_unsigned_int<Int>::value && !is_unsigned_long<Int>::value &&
    std::is_integral<Int>::value && std::is_unsigned<Int>::value &&
    std::numeric_limits<Int>::max() <=
    std::numeric_limits<unsigned long long>::max();
};
}

/* Binary */
inline namespace {
template<typename Int, typename std::enable_if<
    is_unsigned_int<Int>::value>::type* = nullptr>
size_t popcount(Int const i) {
  return __builtin_popcount(i);
}
template<typename Int, typename std::enable_if<
    is_unsigned_long<Int>::value>::type* = nullptr>
size_t popcount(Int const i) {
  return __builtin_popcountl(i);
}
template<typename Int, typename std::enable_if<
    is_unsigned_long_long<Int>::value>::type* = nullptr>
size_t popcount(Int const i) {
  return __builtin_popcountll(i);
}
template<typename Int, typename std::enable_if<
    std::is_signed<Int>::value>::type* = nullptr>
size_t popcount(Int const i) {
  auto const u = static_cast<typename std::make_unsigned<Int>::type>(i);
  return popcount(u);
}

template<typename Int, typename std::enable_if<
    std::is_integral<Int>::value>::type* = nullptr>
Int lowbit(Int const i) {
  return i & (-i);
}
}

/* Random */
inline namespace {
template<typename Initializer = std::random_device,
         typename Generator = std::mt19937_64>
typename Generator::result_type randint() {
  static Initializer init;
  static Generator gen(init());
  return gen();
}
}

/* Number Theory */
inline namespace {
template<typename Lhs, typename Rhs, typename Int =
    typename super_integral_t<Lhs, Rhs>::type>
Int gcd(Lhs const a, Rhs const b) {
  static std::function<Int(Int const, Int const)> const recursive =
      [](Int const a, Int const b) {
    if (b == 0) {
      return a;
    }
    return recursive(b, a % b);
  };
  return recursive(std::abs(a), std::abs(b));
}

template<typename Lhs, typename Rhs, typename Int =
    typename super_integral_t<Lhs, Rhs>::type>
std::tuple<Int, Int, Int> extended_euclidean(Lhs const a, Rhs const b) {
  static std::function<Int(Int const, Int const, Int&, Int&)> const recursive =
      [](Int const a, Int const b, Int &x, Int &y) {
    if (b == 0) {
      x = 1;
      y = 0;
      return a;
    }
    auto foo = recursive(b, a % b, x, y);
    auto tmp = x;
    x = y;
    y = tmp - (a / b) * y;
    return foo;
  };
  Int g = 0, x = 0, y = 0;
  if (a < 0) {
    std::tie(g, x, y) = extended_euclidean(-a, b);
    return std::make_tuple(g, -x, y);
  }
  if (b < 0) {
    std::tie(g, x, y) = extended_euclidean(a, -b);
    return std::make_tuple(g, x, -y);
  }
  g = recursive(a, b, x, y);
  return std::make_tuple(g, x, y);
}

template<typename Lhs, typename Rhs>
typename super_integral_t<Lhs, Rhs>::type
inverse(Lhs const a, Rhs const b) {
  return std::get<1>(extended_euclidean(a, b));
}

template<typename Int = int>
std::vector<Int> primetable(Int const maximum) {
  std::vector<Int> table(maximum + 1, 0);
  size_t cnt = 0;
  for (Int i = 2; i <= maximum; ++i) {
    if (table[i] == 0) table[cnt++] = i;
    for (size_t p = 0; p < cnt && table[p] <= maximum / i; ++p) {
#ifdef UNITTEST
      CPPUNIT_ASSERT_EQUAL(0, table[table[p] * i]);
#endif
      table[table[p] * i] = 1;
      if (i % table[p] == 0) break;
    }
  }
  table.resize(cnt);
  return table;
}
template<typename Int = int>
std::vector<Int> const& primes(Int const maximum) {
  static std::vector<Int> lsprime;
  static std::list<std::pair<Int, size_t>> cursors;
  static Int start = 2;
  if (maximum >= start) {
    std::vector<bool> isprime(maximum - start + 1, true);
    for (Int i = start; i <= maximum; ++i) {
      cursors.emplace_back(i, 0);
    }
    for (auto iter = cursors.begin(); iter != cursors.end(); ) {
      Int const i = iter->first;
      if (i >= start && isprime[i - start]) lsprime.push_back(i);
      for (size_t& p = iter->second; ; ++p) {
        if (p >= lsprime.size() || lsprime[p] > i) {
          iter = cursors.erase(iter);
          break;
        }
        if (lsprime[p] > maximum / i) {
          ++iter;
          break;
        }
#ifdef UNITTEST
        CPPUNIT_ASSERT(lsprime[p] * i >= start);
        CPPUNIT_ASSERT(isprime[lsprime[p] * i - start]);
#endif
        isprime[lsprime[p] * i - start] = false;
        if (i % lsprime[p] == 0) {
          iter = cursors.erase(iter);
          break;
        }
      }
    }
    start = maximum + 1;
  }
  return lsprime;
}
}

/* Class imod_t */
inline namespace {
template<int_fast64_t token, typename Int>
struct add_safe {
  static constexpr bool value =
      std::numeric_limits<Int>::max() - (token - 1) >= (token - 1);
};

template<int_fast64_t token, typename Int>
struct sub_safe {
  static constexpr bool value =
      std::numeric_limits<Int>::min() - (1 - token) <= (1 - token);
};

template<int_fast64_t token, typename Int>
struct mul_safe {
  static constexpr bool value =
      std::numeric_limits<Int>::max() / (token - 1) >= (token - 1);
};

template<int_fast64_t token>
class imod_t {
  using foo_t = int_fast64_t;
  static_assert(token > 0, "");
  static_assert(std::is_integral<foo_t>::value, "");
  static_assert(std::is_signed<foo_t>::value, "");
  static_assert(std::numeric_limits<foo_t>::max() > token, "");
public:
  imod_t() = default;
  imod_t(imod_t const&) = default;
  imod_t(imod_t &&) = default;

  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t(Int const rhs) : foo_(rhs % token) { }

  imod_t& operator=(imod_t const&) = default;
  imod_t& operator=(imod_t &&) = default;

  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t& operator=(Int const rhs) {
    foo_ = rhs % token;
    return *this;
  }

  explicit operator bool() const noexcept {
    return foo_ != 0;
  }

  imod_t operator+(imod_t const& rhs) const {
    imod_t bar(*this);
    bar += rhs;
    return bar;
  }
  template<typename std::enable_if<
      add_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator+=(imod_t const& rhs) {
    foo_ = (foo_ + rhs.foo_) % token;
    return *this;
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t operator+(Int const rhs) const {
    return *this + imod_t(rhs);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t& operator+=(Int const rhs) {
    return *this += imod_t(rhs);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  friend imod_t operator+(Int const lhs, imod_t const& rhs) {
    return rhs + lhs;
  }

  imod_t operator-(imod_t const& rhs) const {
    imod_t bar(*this);
    bar -= rhs;
    return bar;
  }
  template<typename std::enable_if<
      sub_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator-=(imod_t const& rhs) {
    foo_ = (foo_ - rhs.foo_) % token;
    return *this;
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t operator-(Int const rhs) const {
    return *this - imod_t(rhs);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t& operator-=(Int const rhs) {
    return *this -= imod_t(rhs);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  friend imod_t operator-(Int const lhs, imod_t const& rhs) {
    return imod_t(lhs) - rhs;
  }

  imod_t operator*(imod_t const& rhs) const {
    imod_t bar(*this);
    bar *= rhs;
    return bar;
  }
  template<typename std::enable_if<
      mul_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator*=(imod_t const& rhs) {
    foo_ = (foo_ * rhs.foo_) % token;
    return *this;
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t operator*(Int const rhs) const {
    return *this * imod_t(rhs);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t& operator*=(Int const rhs) {
    return *this *= imod_t(rhs);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  friend imod_t operator*(Int const lhs, imod_t const& rhs) {
    return rhs * lhs;
  }

  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t operator/(Int const rhs) const {
    return *this * inverse(rhs, token);
  }
  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t& operator/=(Int const rhs) {
    return *this *= imod_t(inverse(rhs, token));
  }

  imod_t pow(uint_fast64_t rhs) const {
    imod_t foo = identity();
    imod_t bar(*this);
    for (; rhs > 0; rhs >>= 1) {
      if (rhs & 1) {
        foo *= bar * (rhs & 1);
      }
      if (rhs > 1) {
        bar *= bar;
      }
    }
    return foo;
  }

  imod_t& operator++() {
    *this += identity();
    return *this;
  }
  imod_t operator++(int) {
    imod_t foo = *this;
    operator++();
    return foo;
  }

  imod_t& operator--() {
    *this -= identity();
    return *this;
  }
  imod_t operator--(int) {
    imod_t foo = *this;
    operator--();
    return foo;
  }

  long long lld() const {
    return (foo_ + token) % token;
  }

private:
  foo_t foo_ = 0;
  static imod_t const& identity() {
    static imod_t const foo(1);
    return foo;
  }
};
}
}

inline namespace {
// typedefs
using imod_t = joshu::imod_t<1000000007>;
}

using namespace std;

int const inf = 0x3f3f3f3f;

struct seg_t {
  int x, y;
};

struct node_t {
  int lef, rig;
  int cover, shallow, stacked;
  node_t* chd[2];
};

int n, m;
list<seg_t> foo;
int ans;

node_t pool[2100000], *root, *tail;

void build(node_t** hook, int const lef, int const rig) {
  node_t* node = *hook = tail++;

  node->lef = lef;
  node->rig = rig;

  node->cover = 0;
  node->shallow = 0;
  node->stacked = 0;

  if (lef != rig) {
    int const mid = (lef + rig) >> 1;
    build(&node->chd[0], lef, mid);
    build(&node->chd[1], mid + 1, rig);
  } else {
    node->chd[0] = nullptr;
    node->chd[1] = nullptr;
  }
}

void update(node_t* node) {
  if (node->chd[0] == nullptr) {
    node->shallow = (node->cover == 1) ? 1: 0;
    node->stacked = (node->cover == 0) ? 0: 1;
    return;
  }
  if (node->cover == 0) {
    node->shallow = node->chd[0]->shallow + node->chd[1]->shallow;
    node->stacked = node->chd[0]->stacked + node->chd[1]->stacked;
  } else if (node->cover == 1) {
    int const range = node->rig - node->lef + 1;
    node->shallow = range - node->chd[0]->stacked - node->chd[1]->stacked;
    node->stacked = range;
  } else {
    int const range = node->rig - node->lef + 1;
    node->shallow = 0;
    node->stacked = range;
  }
}

void cover(node_t* node, int const lef, int const rig, int const d) {
  if (lef <= node->lef && node->rig <= rig) {
    node->cover += d;
  } else {
    if (lef <= node->chd[0]->rig) {
      cover(node->chd[0], lef, rig, d);
    }
    if (rig >= node->chd[1]->lef) {
      cover(node->chd[1], lef, rig, d);
    }
  }
  update(node);
}

pair<int, int>
query(node_t* node, int const lef, int const rig) {
  if (lef <= node->lef && node->rig <= rig) {
    return {node->shallow, node->stacked};
  } else {
    int range0 = max(
        min(node->chd[0]->rig, rig) - max(node->chd[0]->lef, lef) + 1,
        0);
    int shallow0 = 0, stacked0 = 0;
    int range1 = max(
        min(node->chd[1]->rig, rig) - max(node->chd[1]->lef, lef) + 1,
        0);
    int shallow1 = 0, stacked1 = 0;
    if (range0) {
      auto const tmp = query(node->chd[0], lef, rig);
      shallow0 = tmp.first;
      stacked0 = tmp.second;
    }
    if (range1) {
      auto const tmp = query(node->chd[1], lef, rig);
      shallow1 = tmp.first;
      stacked1 = tmp.second;
    }
    int const range = range0 + range1;
    int shallow, stacked;
    if (node->cover == 0) {
      shallow = shallow0 + shallow1;
      stacked = stacked0 + stacked1;
    } else if (node->cover == 1) {
      shallow = range - stacked0 - stacked1;
      stacked = range;
    } else {
      shallow = 0;
      stacked = range;
    }
    return {shallow, stacked};
  }
}

int handler() {
  ans = inf;
  scanf("%d%d", &m, &n);
  foo.clear();
  tail = pool;
  build(&root, 1, m);
  for (int i = 0; i < n; ++i) {
    static seg_t bar;
    scanf("%d%d", &bar.x, &bar.y);
    foo.push_back(bar);
    cover(root, bar.x, bar.y, 1);
  }
  while(!foo.empty()) {
    decltype(foo.begin()) cursor;
    int wht = -inf; 
    for (auto it = foo.begin(); it != foo.end(); ++it) {
      int const score = query(root, it->x, it->y).first;
      if (score > wht) {
        cursor = it;
        wht = score;
      }
    }
    cover(root, cursor->x, cursor->y, -1);
    foo.erase(cursor);
    ans = min(ans, wht);
  }
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    printf("Case #%d: %d\n", i + 1, handler());
  }
  return 0;
}