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

imod_t f[2][64][64][1024];

class ClassRankings {
  /*
  private:
  imod_t solve(int const x, int const y, int const z, int const s,
               vector<int> const& lo, vector<int> const& hi) {
    if (v[x][y][z][s]) return f[x][y][z][s];
    v[x][y][z][s] = 1;
    imod_t& foo = f[x][y][z][s];
    if (x == 0 && y == 0 && z == 0) {
      foo = 1;
    } else if (lo[0] + x - 1 > hi[0]
                  || lo[1] + y - 1 > hi[1]
                  || lo[2] + z - 1 > hi[2]) {
      foo = 0;
    } else if ((x > 0 && s + x > hi[0])
                  || (y > 0 && s + y > hi[1])
                  || (z > 0 && s + z > hi[2])) {
      foo = 0;
    } else {
      foo = 0;
      if (x > 0) {
        foo += solve(x - 1, y, z, max(lo[0], s + 1), lo, hi);
        //fprintf(stderr, "?f[%d][%d][%d][%d] = %lld\n", x, y, z, s, foo.lld());
      }
      if (y > 0) {
        foo += solve(x, y - 1, z, max(lo[1], s + 1), lo, hi);
        //fprintf(stderr, "?f[%d][%d][%d][%d] = %lld\n", x, y, z, s, foo.lld());
      }
      if (z > 0) {
        foo += solve(x, y, z - 1, max(lo[2], s + 1), lo, hi);
        //fprintf(stderr, "?f[%d][%d][%d][%d] = %lld\n", x, y, z, s, foo.lld());
      }
    }
    //fprintf(stderr, "f[%d][%d][%d][%d] = %lld\n", x, y, z, s, foo.lld());
    return foo;
  }
  */
  public:
  int countWays(vector<int> const& amt,
                vector<int> const& lo,
                vector<int> const& hi) {
    int const s = amt[0] + amt[1] + amt[2];
    int const p = max(max(hi[0], hi[1]), hi[2]);
    for (int k = 0; k < p; ++k)
      f[0][0][0][k] = (k == 0) ? 1 : 0;
    for (int i = 0; i < s; ++i) {
      int const cur = i & 1;
      int const nxt = cur ^ 1;
      for (int x = 0; x <= amt[0] && x <= i + 1; ++x) {
        for (int y = 0; y <= amt[1] && x + y <= i + 1; ++y) {
          int const z = i + 1 - x - y;
          if (z > amt[2]) continue;
          for (int k = 0; k <= p; ++k) {
            f[nxt][x][y][k] = 0;
          }
        }
      }
      for (int x = 0; x <= amt[0] && x <= i; ++x) {
        for (int y = 0; y <= amt[1] && x + y <= i; ++y) {
          int const z = i - x - y;
          if (z > amt[2]) continue;
          for (int k = 0; k <= p; ++k) {
            if (x < amt[0] && k + 1 <= hi[0]) {
              f[nxt][x + 1][y][max(lo[0], k + 1)] += f[cur][x][y][k];
            }
            if (y < amt[1] && k + 1 <= hi[1]) {
              f[nxt][x][y + 1][max(lo[1], k + 1)] += f[cur][x][y][k];
            }
            if (z < amt[2] && k + 1 <= hi[2]) {
              f[nxt][x][y][max(lo[2], k + 1)] += f[cur][x][y][k];
            }
          }
        }
      }
    }
    imod_t bar;
    for (int k = 0; k <= p; ++k) {
      bar += f[s & 1][amt[0]][amt[1]][k];
    }
    return static_cast<int>(bar.lld());
  }
};

// CUT begin
ifstream data("ClassRankings.sample");

string next_line() {
    string s;
    getline(data, s);
    return s;
}

template <typename T> void from_stream(T &t) {
    stringstream ss(next_line());
    ss >> t;
}

void from_stream(string &s) {
    s = next_line();
}

template <typename T> void from_stream(vector<T> &ts) {
    int len;
    from_stream(len);
    ts.clear();
    for (int i = 0; i < len; ++i) {
        T t;
        from_stream(t);
        ts.push_back(t);
    }
}

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(vector<int> amt, vector<int> lo, vector<int> hi, int __expected) {
    time_t startClock = clock();
    ClassRankings *instance = new ClassRankings();
    int __result = instance->countWays(amt, lo, hi);
    double elapsed = (double)(clock() - startClock) / CLOCKS_PER_SEC;
    delete instance;

    if (__result == __expected) {
        cout << "PASSED!" << " (" << elapsed << " seconds)" << endl;
        return true;
    }
    else {
        cout << "FAILED!" << " (" << elapsed << " seconds)" << endl;
        cout << "           Expected: " << to_string(__expected) << endl;
        cout << "           Received: " << to_string(__result) << endl;
        return false;
    }
}

int run_test(bool mainProcess, const set<int> &case_set, const string command) {
    int cases = 0, passed = 0;
    while (true) {
        if (next_line().find("--") != 0)
            break;
        vector<int> amt;
        from_stream(amt);
        vector<int> lo;
        from_stream(lo);
        vector<int> hi;
        from_stream(hi);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(amt, lo, hi, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1578763492;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 500 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
    }
    return 0;
}

int main(int argc, char *argv[]) {
    cout.setf(ios::fixed, ios::floatfield);
    cout.precision(2);
    set<int> cases;
    bool mainProcess = true;
    for (int i = 1; i < argc; ++i) {
        if ( string(argv[i]) == "-") {
            mainProcess = false;
        } else {
            cases.insert(atoi(argv[i]));
        }
    }
    if (mainProcess) {
        cout << "ClassRankings (500 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
