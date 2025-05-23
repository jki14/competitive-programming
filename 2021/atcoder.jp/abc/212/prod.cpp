#include "bits/stdc++.h"

#ifdef UNITTEST
#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/ui/text/TestRunner.h"
#endif

/**            Workaround for TopCoder C++ Compliler (gcc@3.1)             **/
#ifndef _GLIBCXX14_CONSTEXPR
# if __cplusplus >= 201402L
#  define _GLIBCXX14_CONSTEXPR constexpr
# else
#  define _GLIBCXX14_CONSTEXPR
# endif
#endif

#ifndef _GLIBCXX_PREDEFINED_OPS_H
#define _GLIBCXX_PREDEFINED_OPS_H	1
namespace __gnu_cxx
{
namespace __ops
{
  struct _Iter_less_iter
  {
    template<typename _Iterator1, typename _Iterator2>
      _GLIBCXX14_CONSTEXPR
      bool
      operator()(_Iterator1 __it1, _Iterator2 __it2) const
      { return *__it1 < *__it2; }
  };
} // namespace __ops
} // namespace __gnu_cxx
#endif
/****************************************************************************/

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

template<typename Int, typename std::enable_if<
    std::is_integral<Int>::value>::type* = nullptr>
Int bitlen(Int bar) {
  Int foo = 0;
  for (; bar != 0; bar >>= 1) {
    ++foo;
  }
  return foo;
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

/* Algorithms */
inline namespace {
template<typename Int, typename Lambda, typename std::enable_if<
    std::is_signed<Int>::value>::type* = nullptr>
Int binary_search(Int lef, Int rig, Lambda check) {
  // fprintf(stderr, "search %d -> %d\n", lef, rig);
  if (!check(rig)) return rig;
  while (lef < rig) {
    Int const mid = (lef + rig) >> 1;
    if (check(mid)) {
      rig = mid;
    } else {
      lef = mid + 1;
    }
  }
  // fprintf(stderr, "get %d\n", rig);
  return rig;
}
}

/* Data Structures */
inline namespace {
template<typename T, size_t C = 1048576>
class heap_t {
public:
  class entry_t;
  using iter_t = typename std::vector<entry_t>::iterator;
  class entry_t {
  public:
    entry_t() = delete;
    entry_t(entry_t const&) = delete;

    entry_t& operator=(entry_t const&) = delete;

    bool operator==(entry_t const& rhs) const {
      return value_ == rhs.value_;
    }
    bool operator!=(entry_t const& rhs) const {
      return value_ != rhs.value_;
    }
    bool operator<(entry_t const& rhs) const {
      return value_ < rhs.value_;
    }
    bool operator>(entry_t const& rhs) const {
      return value_ > rhs.value_;
    }
    bool operator<=(entry_t const& rhs) const {
      return value_ <= rhs.value_;
    }
    bool operator>=(entry_t const& rhs) const {
      return value_ >= rhs.value_;
    }

    entry_t(T value, iter_t const& iter, heap_t& heap)
      : value_(std::move(value))
      , self_(iter)
      , meta_(iter)
      , iter_(&meta_)
      , heap_(&heap) { }

    entry_t(entry_t&& rhs)
      : value_(std::move(rhs.value_))
      , self_()
      , meta_()
      , iter_(rhs.iter_) { }

    entry_t& operator=(entry_t&& rhs) {
      value_ = std::move(rhs.value_);
      iter_ = rhs.iter_;
      *iter_ = self_;
      return *this;
    }

    T const& get() const {
      return value_;
    }

    void set(T new_value) {
      if (new_value == value_) return;
      if (new_value > value_) {
        value_ = std::move(new_value);
        std::push_heap(heap_->foo_.begin(), std::next(*iter_));
      } else {
        value_ = std::move(new_value);
        static __gnu_cxx::__ops::_Iter_less_iter __comp;
        auto __first = heap_->foo_.begin();
        auto const __pos = *iter_ - __first;
        auto const __len = heap_->foo_.end() - __first;
        std::__adjust_heap(__first, __pos, __len, std::move(**iter_), __comp);
      }
    }

    iter_t* iter_pointer() {
      return iter_;
    }

  private:
    T value_;
    iter_t const self_;
    iter_t meta_;
    iter_t* iter_;
    heap_t* heap_ = nullptr;
  };

  heap_t() {
    foo_.reserve(C);
  }
  heap_t(heap_t const&) = delete;
  heap_t(heap_t&&) = default;

  heap_t& operator=(heap_t const&) = delete;
  heap_t& operator=(heap_t&&) = delete;

  std::vector<iter_t*>
  load(std::vector<T> values) {
    size_t const inc = values.size();
    if (foo_.size() + inc > foo_.capacity()) {
      return { };
    }
    std::vector<iter_t*> bar;
    bar.reserve(inc);
    if (foo_.empty()) {
      for (auto&& val : values) {
        foo_.emplace_back(std::move(val), foo_.end(), *this);
        bar.emplace_back(foo_.back().iter_pointer());
      }
      std::make_heap(foo_.begin(), foo_.end());
    } else {
      for (auto&& val : values) {
        bar.emplace_back(push(std::move(val)));
      }
    }
    return bar;
  }

  iter_t* push(T value) {
    if (foo_.size() + 1 > foo_.capacity()) {
      return nullptr;
    }
    foo_.emplace_back(std::move(value), foo_.end(), *this);
    auto const bar = foo_.back().iter_pointer();
    std::push_heap(foo_.begin(), foo_.end());
    return bar;
  }

  size_t size() const {
    return foo_.size();
  }

  bool empty() const {
    return foo_.empty();
  }

  T const& top() const{
    return foo_.front().get();
  }

  void pop() {
    std::pop_heap(foo_.begin(), foo_.end());
    foo_.pop_back();
  }

private:
  std::vector<entry_t> foo_;
};

template<typename Ctx>
class btnctx_t {
public:
  virtual void aggregate(Ctx const& lhs, Ctx const& rhs) = 0;
  virtual void flush(Ctx& lhs, Ctx& rhs) = 0;
};

template<typename Int, typename Ctx, typename std::enable_if<
    std::is_base_of<btnctx_t<Ctx>, Ctx>::value>::type* = nullptr>
class segtree_t {
public:
  struct node_t {
    node_t* chd[2];
    Int lef, rig;
    Ctx ctx;
  };

  using ctx_handler_t = std::function<Ctx(node_t const&)>;

  segtree_t() = default;
  segtree_t(size_t const capacity) {
    node_pool_.resize(capacity << 1);
  }

  segtree_t(segtree_t const&) = delete;
  segtree_t(segtree_t&&) = delete;

  segtree_t& operator=(segtree_t const&) = delete;
  segtree_t& operator=(segtree_t&&) = delete;

  void build(Int const lef, Int const rig, ctx_handler_t const& initializer) {
    clear();
    build(&root_, lef, std::max(lef, rig), initializer);
  }

  void update(Int const pos, ctx_handler_t const& updater) {
    update(pos, pos, updater);
  }

  void update(Int const lef, Int const rig, ctx_handler_t const& updater) {
    if (lef <= rig && lef <= root_->rig && rig >= root_->lef) {
      update(*root_, lef, rig, updater);
    }
  }

  Ctx query(Int const pos, ctx_handler_t const& querier) {
    return query(pos, pos, querier);
  }

  Ctx query(Int const lef, Int const rig, ctx_handler_t const& querier) {
    if (lef <= rig && lef <= root_->rig && rig >= root_->lef) {
      return query(*root_, lef, rig, querier);
    } else {
      return { };
    }
  }

private:
  void build(node_t **hook, Int const lef, Int const rig,
             ctx_handler_t const& initializer) {
    *hook = new_node();
    node_t& node = **hook;
    node.lef = lef;
    node.rig = rig;
    node.ctx = initializer(node);
    if (lef == rig) {
      node.chd[0] = nullptr;
      node.chd[1] = nullptr;
    } else {
      Int const mid = (lef + rig) >> 1;
      build(&node.chd[0], lef, mid, initializer);
      build(&node.chd[1], mid + 1, rig, initializer);
      node.ctx.aggregate(node.chd[0]->ctx, node.chd[1]->ctx);
    }
  }

  void update(node_t &node, Int const lef, Int const rig,
              ctx_handler_t const& updater) {
    if (lef <= node.lef && node.rig <= rig) {
      node.ctx = updater(node);
    } else {
      node.ctx.flush(node.chd[0]->ctx, node.chd[1]->ctx);
      if (lef <= node.chd[0]->rig) {
        update(*node.chd[0], lef, rig, updater);
      }
      if (rig >= node.chd[1]->lef) {
        update(*node.chd[1], lef, rig, updater);
      }
      node.ctx.aggregate(node.chd[0]->ctx, node.chd[1]->ctx);
    }
  }

  Ctx query(node_t &node, Int const lef, Int const rig,
            ctx_handler_t const& querier) {
    if (lef <= node.lef && node.rig <= rig) {
      return querier(node);
    } else {
      Ctx lhs, rhs;
      if (lef <= node.chd[0]->rig) {
        lhs = query(*node.chd[0], lef, rig, querier);
      }
      if (rig >= node.chd[1]->lef) {
        rhs = query(*node.chd[1], lef, rig, querier);
      }
      Ctx foo = querier(node);
      foo.aggregate(lhs, rhs);
      return foo;
    }
  }

  void clear() {
    root_ = nullptr;
    num_ = 0;
  }

  node_t* new_node() {
    while (node_pool_.size() <= num_) {
      node_pool_.emplace_back();
    }
    return &node_pool_[num_++];
  }

  std::vector<node_t> node_pool_;
  node_t* root_ = nullptr;
  size_t num_ = 0;
};
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
  imod_t(imod_t&&) = default;

  template<typename Int, typename std::enable_if<
      std::is_integral<Int>::value>::type* = nullptr>
  imod_t(Int const rhs) : foo_(rhs % token) { }

  imod_t& operator=(imod_t const&) = default;
  imod_t& operator=(imod_t&&) = default;

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
#include "bits/stdc++.h"
using namespace std;

using lld = long long;

static int constexpr inf = 0x3f3f3f3f;

int m;
multiset<lld> s;

lld bar;

int main() {
  while (scanf("%d", &m) != EOF) {
    s.clear();
    bar = 0;

    for (int i = 0; i < m; ++i) {
      int t;
      lld x;
      scanf("%d", &t);
      if (t == 1) {
        scanf("%lld", &x);
        s.insert(x - bar);
      } else if (t == 2) {
        scanf("%lld", &x);
        bar += x;
      } else {
        auto it = s.begin();
        printf("%lld\n", *it + bar);
        s.erase(it);
      }
    }
  }
  return 0;
}
