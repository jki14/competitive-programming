#include "bits/stdc++.h"

namespace joshu {

inline namespace {
template<int64_t token, int64_t token2>
struct token_compatible {
  constexpr static bool value
    = token2 % token == 0;
};

template<int64_t token, typename integral>
struct add_safe {
  constexpr static bool value
    = std::numeric_limits<integral>::max() - (token - 1) >= (token - 1);
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
public:
  imod_t() = default;
  imod_t(imod_t const&) = default;
  imod_t(imod_t &&) = default;

  imod_t(const foo_t rhs) {
    foo_ = rhs % token;
  }

  template<int64_t token2>
  typename std::enable_if<
    token_compatible<token, token2>::value
    && add_safe<token2, foo_t>::value
    , imod_t<token>&>::type
  imod_t<token> operator+(imod_t<token2> const& rhs) const {
    imod_t bar(*this);
    bar += rhs;
    return bar;
  }
  template<int64_t token2>
  typename std::enable_if<
    token_compatible<token, token2>::value
    && add_safe<token2, foo_t>::value
    , imod_t<token>&>::type
  operator+=(imod_t<token2> const& rhs) {
    foo_ = (foo_ + rhs.foo_) % token;
    return *this;
  }
  template<int64_t token2>
  typename std::enable_if<
    token_compatible<token, token2>::value
    && !add_safe<token2, foo_t>::value
    , imod_t<token>&>::type
  operator+=(imod_t<token2> const& rhs) {
    foo_ = ((sup_t)foo_ + (sup_t)rhs.foo_) % token;
    return *this;
  }

  imod_t operator*(imod_t const& rhs) const {
    imod_t bar(*this);
    bar *= rhs;
    return bar;
  }
  template<int64_t token2>
  typename std::enable_if<
    token_compatible<token, token2>::value
    && mul_safe<token2, foo_t>::value
    , imod_t<token>&>::type
  operator*=(imod_t<token2> const& rhs) {
    foo_ = (foo_ * rhs.foo_) % token;
    return *this;
  }
  template<int64_t token2>
  typename std::enable_if<
    token_compatible<token, token2>::value
    && !mul_safe<token2, foo_t>::value
    , imod_t<token>&>::type
  operator*=(imod_t<token2> const& rhs) {
    foo_ = ((sup_t)foo_ * (sup_t)rhs.foo_) % token;
    return *this;
  }

  long long lld() const {
    return (foo_ + token) % token;
  }
    
private:
  template<int64_t token2>
  friend class imod_t;
  foo_t foo_ = 0;
};
}

//TODO

}

int main() {
  joshu::imod_t<4> mit = -2;
  joshu::imod_t<8> mit2 = -2;
  mit += mit2;
  mit *= mit2;
  std::cout << mit.lld() << std::endl;
  joshu::imod_t<9223372036854775807LL> mit3 = -2;
  mit3 += mit3;
  mit3 *= mit3;
  mit += 3;
  return 0;
}
