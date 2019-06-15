#include "bits/stdc++.h"

namespace joshu {
/* Utils */
inline namespace {
template<typename lhs, typename rhs,
         typename std::enable_if<
             std::is_integral<lhs>::value && std::is_signed<lhs>::value &&
             std::is_integral<rhs>::value && std::is_signed<rhs>::value
         >::type* = nullptr>
struct super_integral_t {
  typedef typename std::conditional<
      std::numeric_limits<lhs>::max() >= std::numeric_limits<rhs>::max(),
      lhs, rhs>::type type;
};
}

/* Number Theory */
inline namespace {
template<typename integral_a, typename integral_b, typename element_t =
    typename super_integral_t<integral_a, integral_b>::type>
std::tuple<element_t, element_t, element_t>
extended_euclidean(const integral_a a, const integral_b b) {
  static const std::function<element_t(
      const element_t, const element_t, element_t&, element_t&
  )> recursive =
      [](const element_t a, const element_t b, element_t &x, element_t &y) {
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
  element_t g = 0, x = 0, y = 0;
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

template<typename integral_a, typename integral_b>
typename super_integral_t<integral_a, integral_b>::type
inverse(const integral_a a, const integral_b b) {
  return std::get<1>(extended_euclidean(a, b));
}
}

/* Class imod_t */
inline namespace {
template<int64_t token, typename integral>
struct add_safe {
  static constexpr bool value =
      std::numeric_limits<integral>::max() - (token - 1) >= (token - 1);
};

template<int64_t token, typename integral>
struct sub_safe {
  static constexpr bool value =
      std::numeric_limits<integral>::min() - (1 - token) <= (1 - token);
};

template<int64_t token, typename integral>
struct mul_safe {
  static constexpr bool value =
      std::numeric_limits<integral>::max() / (token - 1) >= (token - 1);
};

template<int64_t token>
class imod_t {
  typedef int64_t foo_t;
  typedef __int128 sup_t;
  static_assert(token > 0, "");
  static_assert(std::is_integral<foo_t>::value, "");
  static_assert(std::is_signed<foo_t>::value, "");
  static_assert(std::numeric_limits<foo_t>::max() > token, "");
public:
  imod_t() = default;
  imod_t(imod_t const&) = default;
  imod_t(imod_t &&) = default;

  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t(const integral rhs) {
    foo_ = rhs % token;
  }

  imod_t& operator=(imod_t const&) = default;
  imod_t& operator=(imod_t &&) = default;

  imod_t operator+(imod_t const& rhs) const {
    imod_t bar(*this);
    bar += rhs;
    return bar;
  }
  template<typename rtype, typename std::enable_if<
      std::is_same<imod_t, rtype>::value &&
      add_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator+=(rtype const& rhs) {
    foo_ = (foo_ + rhs.foo_) % token;
    return *this;
  }
  template<typename rtype, typename std::enable_if<
      std::is_same<imod_t, rtype>::value &&
      !add_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator+=(rtype const& rhs) {
    foo_ = ((sup_t)foo_ + (sup_t)rhs.foo_) % token;
    return *this;
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator+(const integral rhs) const {
    return *this + imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator+=(const integral rhs) {
    return *this += imod_t(rhs);
  }

  imod_t operator-(imod_t const& rhs) const {
    imod_t bar(*this);
    bar -= rhs;
    return bar;
  }
  template<typename rtype, typename std::enable_if<
      std::is_same<imod_t, rtype>::value &&
      sub_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator-=(rtype const& rhs) {
    foo_ = (foo_ - rhs.foo_) % token;
    return *this;
  }
  template<typename rtype, typename std::enable_if<
      std::is_same<imod_t, rtype>::value &&
      !sub_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator-=(rtype const& rhs) {
    foo_ = ((sup_t)foo_ - (sup_t)rhs.foo_) % token;
    return *this;
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator-(const integral rhs) const {
    return *this - imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator-=(const integral rhs) {
    return *this -= imod_t(rhs);
  }

  imod_t operator*(imod_t const& rhs) const {
    imod_t bar(*this);
    bar *= rhs;
    return bar;
  }
  template<typename rtype, typename std::enable_if<
      std::is_same<imod_t, rtype>::value &&
      mul_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator*=(rtype const& rhs) {
    foo_ = (foo_ * rhs.foo_) % token;
    return *this;
  }
  template<typename rtype, typename std::enable_if<
      std::is_same<imod_t, rtype>::value &&
      !mul_safe<token, foo_t>::value>::type* = nullptr>
  imod_t& operator*=(rtype const& rhs) {
    foo_ = ((sup_t)foo_ * (sup_t)rhs.foo_) % token;
    return *this;
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator*(const integral rhs) const {
    return *this * imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator*=(const integral rhs) {
    return *this *= imod_t(rhs);
  }

  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator/(const integral rhs) const {
    return *this * inverse(rhs, token);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator/=(const integral rhs) {
    return *this *= imod_t(inverse(rhs, token));
  }

  imod_t pow(uint64_t rhs) const {
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
    imod_t foo(*this);
    operator++();
    return foo;
  }

  imod_t& operator--() {
    *this -= identity();
    return *this;
  }
  imod_t operator--(int) {
    imod_t foo(*this);
    operator--();
    return foo;
  }

  long long lld() const {
    return (foo_ + token) % token;
  }
    
private:
  foo_t foo_ = 0;
  static imod_t const& identity() {
    static const imod_t foo(1);
    return foo;
  }
};
}
}

inline namespace {
typedef joshu::imod_t<1000000007> imod_t;
}

using namespace std;

int64_t const mod = 1000000007;

vector<int64_t> a;
vector<int64_t> b;
vector<int64_t> c;

imod_t foo, sum, mul;

class TheUnexpectedSwap {
  public:
  int findExpectedResult(int n, string token, int seed) {
    uint64_t nn = n;
    a.clear();
    a.reserve(n);
    a.push_back(seed);
    for (int i = 1; i < n; ++i) {
      a.push_back((a.back() * 1009 + 10009) % 100019);
    }
    b.resize(n);
    b[n - 1] = 1;
    for (int i = n - 2; i >= 0; --i) {
      b[i] = b[i + 1] * 10 % mod;
    }
    c.resize(n);
    for (size_t i = 0; i < nn; ++i) {
      if (i < token.length()) {
        c[i] = token[i] - '0';
      } else {
        c[i] = c[a[i] % i];
      }
    }
    mul = nn * (nn - 1) / 2 - (nn - 1);
    sum = 0;
    for (int i = 0; i < n; ++i) {
      sum += c[i];
    }
    foo = 0;
    for (int i = 0; i < n; ++i) {
      foo += (sum - c[i]) * b[i];
      foo += mul * c[i] * b[i];
    }
    foo *= 2;
    return static_cast<int>(foo.lld());
  }
};

// CUT begin
ifstream data("TheUnexpectedSwap.sample");

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

template <typename T>
string to_string(T t) {
    stringstream s;
    s << t;
    return s.str();
}

string to_string(string t) {
    return "\"" + t + "\"";
}

bool do_test(int digits, string prefN, int seed, int __expected) {
    time_t startClock = clock();
    TheUnexpectedSwap *instance = new TheUnexpectedSwap();
    int __result = instance->findExpectedResult(digits, prefN, seed);
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
        int digits;
        from_stream(digits);
        string prefN;
        from_stream(prefN);
        int seed;
        from_stream(seed);
        next_line();
        int __answer;
        from_stream(__answer);

        cases++;
        if (case_set.size() > 0 && case_set.find(cases - 1) == case_set.end())
            continue;

        cout << "  Testcase #" << cases - 1 << " ... ";
        if ( do_test(digits, prefN, seed, __answer)) {
            passed++;
        }
    }
    if (mainProcess) {
        cout << endl << "Passed : " << passed << "/" << cases << " cases" << endl;
        int T = time(NULL) - 1560583544;
        double PT = T / 60.0, TT = 75.0;
        cout << "Time   : " << T / 60 << " minutes " << T % 60 << " secs" << endl;
        cout << "Score  : " << 1000 * (0.3 + (0.7 * TT * TT) / (10.0 * PT * PT + TT * TT)) << " points" << endl;
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
        cout << "TheUnexpectedSwap (1000 Points)" << endl << endl;
    }
    return run_test(mainProcess, cases, argv[0]);
}
// CUT end
