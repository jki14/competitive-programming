#include "bits/stdc++.h"

namespace joshu {

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

  long long lld() const {
    return (foo_ + token) % token;
  }
    
private:
  foo_t foo_ = 0;
};
}

//TODO

}

typedef joshu::imod_t<1000000007> imod_t;

int main() {
  imod_t foo = 1;
  foo = foo + 1;
  foo = foo + foo;
  foo += 1;
  foo += foo;
  std::cout << foo.lld() << std::endl;
  return 0;
}
