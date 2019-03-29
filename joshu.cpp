#include "bits/stdc++.h"

namespace joshu {
/* Number Theory */
inline namespace {
template<typename lhs, typename rhs
  , typename std::enable_if<std::is_integral<lhs>::value
    && std::is_signed<lhs>::value
    && std::is_integral<rhs>::value
    && std::is_signed<rhs>::value>::type* = nullptr>
struct super_integral_t {
  using type = typename std::conditional<
    std::numeric_limits<lhs>::max() >= std::numeric_limits<rhs>::max()
    , lhs, rhs>::type;
};

template<typename integral_a, typename integral_b>
std::tuple<typename super_integral_t<integral_a, integral_b>::type
  , typename super_integral_t<integral_a, integral_b>::type
  , typename super_integral_t<integral_a, integral_b>::type>
extended_euclidean(const integral_a a, const integral_b b) {
  using element_t = typename super_integral_t<integral_a, integral_b>::type;
  static const std::function<element_t(const element_t, const element_t, element_t&, element_t&)>
  recursive = [](const element_t a, const element_t b, element_t &x, element_t &y) {
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
auto inverse(const integral_a a, const integral_b b) {
  return std::get<1>(extended_euclidean(a, b));
}
}

/* Class imod_t */
inline namespace {
template<int64_t token, typename integral>
struct add_safe {
  constexpr static bool value
    = std::numeric_limits<integral>::max() - (token - 1) >= (token - 1);
};

template<int64_t token, typename integral>
struct sub_safe {
  constexpr static bool value
    = std::numeric_limits<integral>::min() - (1 - token) <= (1 - token);
};

template<int64_t token, typename integral>
struct mul_safe {
  constexpr static bool value
    = std::numeric_limits<integral>::max() / (token - 1) >= (token - 1);
};

template<int64_t token>
class imod_t {
  using foo_t = int64_t;
  using sup_t = __int128;
  static_assert(token > 0, "");
  static_assert(std::is_integral<foo_t>::value, "");
  static_assert(std::is_signed<foo_t>::value, "");
  static_assert(std::numeric_limits<foo_t>::max() > token, "");
public:
  imod_t() = default;
  imod_t(imod_t const&) = default;
  imod_t(imod_t &&) = default;

  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
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
  template<typename rtype
    , typename std::enable_if<
      std::is_same<imod_t, rtype>::value
      && add_safe<token, foo_t>::value
    >::type* = nullptr>
  imod_t& operator+=(rtype const& rhs) {
    foo_ = (foo_ + rhs.foo_) % token;
    return *this;
  }
  template<typename rtype
    , typename std::enable_if<
      std::is_same<imod_t, rtype>::value
      && !add_safe<token, foo_t>::value
    >::type* = nullptr>
  imod_t& operator+=(rtype const& rhs) {
    foo_ = ((sup_t)foo_ + (sup_t)rhs.foo_) % token;
    return *this;
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator+(const integral rhs) const {
    return *this + imod_t(rhs);
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator+=(const integral rhs) {
    return *this += imod_t(rhs);
  }

  imod_t operator-(imod_t const& rhs) const {
    imod_t bar(*this);
    bar -= rhs;
    return bar;
  }
  template<typename rtype
    , typename std::enable_if<
      std::is_same<imod_t, rtype>::value
      && sub_safe<token, foo_t>::value
    >::type* = nullptr>
  imod_t& operator-=(rtype const& rhs) {
    foo_ = (foo_ - rhs.foo_) % token;
    return *this;
  }
  template<typename rtype
    , typename std::enable_if<
      std::is_same<imod_t, rtype>::value
      && !sub_safe<token, foo_t>::value
    >::type* = nullptr>
  imod_t& operator-=(rtype const& rhs) {
    foo_ = ((sup_t)foo_ - (sup_t)rhs.foo_) % token;
    return *this;
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator-(const integral rhs) const {
    return *this - imod_t(rhs);
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator-=(const integral rhs) {
    return *this -= imod_t(rhs);
  }

  imod_t operator*(imod_t const& rhs) const {
    imod_t bar(*this);
    bar *= rhs;
    return bar;
  }
  template<typename rtype
    , typename std::enable_if<
      std::is_same<imod_t, rtype>::value
      && mul_safe<token, foo_t>::value
    >::type* = nullptr>
  imod_t& operator*=(rtype const& rhs) {
    foo_ = (foo_ * rhs.foo_) % token;
    return *this;
  }
  template<typename rtype
    , typename std::enable_if<
      std::is_same<imod_t, rtype>::value
      && !mul_safe<token, foo_t>::value
    >::type* = nullptr>
  imod_t& operator*=(rtype const& rhs) {
    foo_ = ((sup_t)foo_ * (sup_t)rhs.foo_) % token;
    return *this;
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator*(const integral rhs) const {
    return *this * imod_t(rhs);
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator*=(const integral rhs) {
    return *this *= imod_t(rhs);
  }

  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator/(const integral rhs) const {
    return *this * inverse(rhs, token);
  }
  template<typename integral
    , typename std::enable_if<std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator/=(const integral rhs) {
    return *this *= imod_t(inverse(rhs, token));
  }

  long long lld() const {
    return (foo_ + token) % token;
  }
    
private:
  foo_t foo_ = 0;
};
}
}

inline namespace newtype {
typedef joshu::imod_t<1000000007> imod_t;
}

int main() {
  imod_t foo = 65535;
  foo += foo * foo + foo - (foo + foo) * foo;
  foo /= 65535;
  std::cout << foo.lld() << std::endl;
  return 0;
}
