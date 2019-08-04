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
template<typename integral_a, typename integral_b, typename superint_t =
    typename super_integral_t<integral_a, integral_b>::type>
superint_t gcd(integral_a const a, integral_b const b) {
  static std::function<superint_t(superint_t const,
                                  superint_t const)> const recursive =
      [](superint_t const a, superint_t const b) {
    if (b == 0) {
      return a;
    }
    return recursive(b, a % b);
  };
  return recursive(std::abs(a), std::abs(b));
}

template<typename integral_a, typename integral_b, typename superint_t =
    typename super_integral_t<integral_a, integral_b>::type>
std::tuple<superint_t, superint_t, superint_t>
extended_euclidean(integral_a const a, integral_b const b) {
  static std::function<superint_t(
      superint_t const, superint_t const, superint_t&, superint_t&
  )> const recursive =
      [](superint_t const a, superint_t const b, superint_t &x, superint_t &y) {
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
  superint_t g = 0, x = 0, y = 0;
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
inverse(integral_a const a, integral_b const b) {
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
  imod_t(integral const rhs) : foo_(rhs % token) { }

  imod_t& operator=(imod_t const&) = default;
  imod_t& operator=(imod_t &&) = default;

  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator=(integral const rhs) {
    foo_ = rhs % token;
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
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator+(integral const rhs) const {
    return *this + imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator+=(integral const rhs) {
    return *this += imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  friend imod_t operator+(integral const lhs, imod_t const& rhs) {
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
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator-(integral const rhs) const {
    return *this - imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator-=(integral const rhs) {
    return *this -= imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  friend imod_t operator-(integral const lhs, imod_t const& rhs) {
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
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator*(integral const rhs) const {
    return *this * imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator*=(integral const rhs) {
    return *this *= imod_t(rhs);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  friend imod_t operator*(integral const lhs, imod_t const& rhs) {
    return rhs * lhs;
  }

  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t operator/(integral const rhs) const {
    return *this * inverse(rhs, token);
  }
  template<typename integral, typename std::enable_if<
      std::is_integral<integral>::value>::type* = nullptr>
  imod_t& operator/=(integral const rhs) {
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
typedef joshu::imod_t<1000000007> imod_t;
}
