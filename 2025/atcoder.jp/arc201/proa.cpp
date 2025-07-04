#ifndef __clang__
#include "bits/stdc++.h"
#else
#include <algorithm>
#include <any>
#include <array>
#include <atomic>
#include <bit>
#include <bitset>
#include <cassert>
#include <ccomplex>
#include <cctype>
#include <cerrno>
#include <cfenv>
#include <cfloat>
#include <charconv>
#include <chrono>
#include <cinttypes>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <codecvt>
#include <compare>
#include <complex>
#include <condition_variable>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstdbool>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctgmath>
#include <ctime>
#include <cwchar>
#include <cwctype>
#include <deque>
#include <exception>
#include <filesystem>
#include <forward_list>
#include <fstream>
#include <functional>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <mutex>
#include <new>
#include <numeric>
#include <optional>
#include <ostream>
#include <queue>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <shared_mutex>
#include <span>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <string_view>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <variant>
#include <vector>
#include <version>
#endif

#ifdef UNITTEST
template <typename T> static std::ostream& operator<<(std::ostream& ost, std::vector<T> const& rhs) {
  ost << "[";
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i)
      ost << ", ";
    ost << rhs[i];
  }
  ost << "]";
  return ost;
}

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/ui/text/TestRunner.h"
#endif

namespace joshu {
/* Utils */
inline namespace {
template <typename Lhs, typename Rhs,
          typename std::enable_if<std::is_integral<Lhs>::value && std::is_signed<Lhs>::value && std::is_integral<Rhs>::value &&
                                  std::is_signed<Rhs>::value>::type* = nullptr>
struct super_integral_t {
  typedef typename std::conditional<std::numeric_limits<Lhs>::max() >= std::numeric_limits<Rhs>::max(), Lhs, Rhs>::type type;
};
template <typename Int> struct is_unsigned_int {
#if defined(__GNUC__) && (__GNUC__ == 9)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif
  static constexpr bool value = std::is_integral<Int>::value && std::is_unsigned<Int>::value &&
                                std::numeric_limits<Int>::max() <= std::numeric_limits<unsigned int>::max();
#if defined(__GNUC__) && (__GNUC__ == 9)
#pragma GCC diagnostic pop
#endif
};
template <typename Int> struct is_unsigned_long {
#if defined(__GNUC__) && (__GNUC__ == 9)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif
  static constexpr bool value = !is_unsigned_int<Int>::value && std::is_integral<Int>::value && std::is_unsigned<Int>::value &&
                                std::numeric_limits<Int>::max() <= std::numeric_limits<unsigned long>::max();
#if defined(__GNUC__) && (__GNUC__ == 9)
#pragma GCC diagnostic pop
#endif
};
template <typename Int> struct is_unsigned_long_long {
#if defined(__GNUC__) && (__GNUC__ == 9)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif
  static constexpr bool value = !is_unsigned_int<Int>::value && !is_unsigned_long<Int>::value && std::is_integral<Int>::value &&
                                std::is_unsigned<Int>::value &&
                                std::numeric_limits<Int>::max() <= std::numeric_limits<unsigned long long>::max();
#if defined(__GNUC__) && (__GNUC__ == 9)
#pragma GCC diagnostic pop
#endif
};

template <typename T> void setmax(T& foo, T const& bar) { foo = std::max(foo, bar); }
template <typename T> void setmin(T& foo, T const& bar) { foo = std::min(foo, bar); }

[[maybe_unused]] struct placeholder_t {
} placeholder;
} // namespace

/* Binary */
inline namespace {
template <typename Int, typename std::enable_if<is_unsigned_int<Int>::value>::type* = nullptr> size_t popcount(Int const i) {
  return __builtin_popcount(i);
}
template <typename Int, typename std::enable_if<is_unsigned_long<Int>::value>::type* = nullptr> size_t popcount(Int const i) {
  return __builtin_popcountl(i);
}
template <typename Int, typename std::enable_if<is_unsigned_long_long<Int>::value>::type* = nullptr> size_t popcount(Int const i) {
  return __builtin_popcountll(i);
}
template <typename Int, typename std::enable_if<std::is_signed<Int>::value>::type* = nullptr> size_t popcount(Int const i) {
  auto const u = static_cast<typename std::make_unsigned<Int>::type>(i);
  return popcount(u);
}

template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> Int lowbit(Int const i) { return i & (-i); }

template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> Int bitlen(Int bar) {
  Int foo = 0;
  for (; bar != 0; bar >>= 1) {
    ++foo;
  }
  return foo;
}
} // namespace

/* Random */
inline namespace {
template <typename Initializer = std::random_device, typename Generator = std::mt19937_64,
          typename std::enable_if<std::is_same<typename Generator::result_type, uint64_t>::value>::type* = nullptr>
uint64_t randllu() {
  static Initializer init;
  static Generator gen(init());
  return gen();
}
} // namespace

/* Number Theory */
inline namespace {
template <typename Lhs, typename Rhs, typename Int = typename super_integral_t<Lhs, Rhs>::type> Int gcd(Lhs const a, Rhs const b) {
  static std::function<Int(Int const, Int const)> const recursive = [](Int const a, Int const b) {
    if (b == 0) {
      return a;
    }
    return recursive(b, a % b);
  };
  return recursive(std::abs(a), std::abs(b));
}

template <typename Lhs, typename Rhs, typename Int = typename super_integral_t<Lhs, Rhs>::type>
std::tuple<Int, Int, Int> extended_euclidean(Lhs const a, Rhs const b) {
  static std::function<Int(Int const, Int const, Int&, Int&)> const recursive = [](Int const a, Int const b, Int& x, Int& y) {
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

template <typename Lhs, typename Rhs> typename super_integral_t<Lhs, Rhs>::type inverse(Lhs const a, Rhs const b) {
  return std::get<1>(extended_euclidean(a, b));
}

template <typename Int = int> std::vector<Int> primetable(Int const maximum) {
  std::vector<Int> table(maximum + 1, 0);
  size_t cnt = 0;
  for (Int i = 2; i <= maximum; ++i) {
    if (table[i] == 0)
      table[cnt++] = i;
    for (size_t p = 0; p < cnt && table[p] <= maximum / i; ++p) {
#ifdef UNITTEST
      CPPUNIT_ASSERT_EQUAL(0, table[table[p] * i]);
#endif
      table[table[p] * i] = 1;
      if (i % table[p] == 0)
        break;
    }
  }
  table.resize(cnt);
  return table;
}
template <typename Int = int> std::vector<Int> const& primes(Int const maximum) {
  static std::vector<Int> lsprime;
  static std::list<std::pair<Int, size_t>> cursors;
  static Int start = 2;
  if (maximum >= start) {
    std::vector<bool> isprime(maximum - start + 1, true);
    for (Int i = start; i <= maximum; ++i) {
      cursors.emplace_back(i, 0);
    }
    for (auto iter = cursors.begin(); iter != cursors.end();) {
      Int const i = iter->first;
      if (i >= start && isprime[i - start])
        lsprime.push_back(i);
      for (size_t& p = iter->second;; ++p) {
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
} // namespace

/* Algorithms */
inline namespace {
template <typename Int, typename Lambda, typename std::enable_if<std::is_signed<Int>::value>::type* = nullptr>
Int constexpr bsearch_first_pass(Int lef, Int rig, Lambda check) noexcept {
  if (!check(rig))
    return rig + 1;
  while (lef < rig) {
    Int const mid = (lef + rig) >> 1;
    if (check(mid)) {
      rig = mid;
    } else {
      lef = mid + 1;
    }
  }
  return rig;
}

template <typename Int, typename Lambda, typename std::enable_if<std::is_signed<Int>::value>::type* = nullptr>
Int constexpr bsearch_last_pass(Int lef, Int rig, Lambda check) noexcept {
  auto const cb = [&check](Int const r) -> bool {
    return check(-r);
  };
  return -bsearch_first_pass(-rig, -lef, cb);
}
} // namespace

/* Data Structures */
inline namespace {
template <typename TX, typename TY> struct tuple2d_t {
  TX x;
  TY y;

  bool operator==(tuple2d_t const& rhs) const { return x == rhs.x && y == rhs.y; }
  bool operator<(tuple2d_t const& rhs) const { return x < rhs.x || (!(rhs.x < x) && y < rhs.y); }
};
template <typename TX, typename TY> static std::ostream& operator<<(std::ostream& ost, tuple2d_t<TX, TY> const& t) {
  return ost << "(" << t.x << ", " << t.y << ")";
}

template <typename TX, typename TY, typename TZ> struct tuple3d_t {
  TX x;
  TY y;
  TZ z;

  bool operator==(tuple3d_t const& rhs) const { return x == rhs.x && y == rhs.y && z == rhs.z; }
  bool operator<(tuple3d_t const& rhs) const {
    return (x < rhs.x) || (!(rhs.x < x) && (y < rhs.y)) || (!(rhs.x < x) && !(rhs.y < y) && (z < rhs.z));
  }
};
template <typename TX, typename TY, typename TZ> static std::ostream& operator<<(std::ostream& ost, tuple3d_t<TX, TY, TZ> const& t) {
  return ost << "(" << t.x << ", " << t.y << ", " << t.z << ")";
}

template <typename T> class heap_t {
public:
  class entry_t;
  using iter_t = typename std::vector<entry_t>::iterator;
  class entry_t {
  public:
    entry_t() = delete;
    entry_t(entry_t const&) = delete;

    entry_t& operator=(entry_t const&) = delete;

    bool operator==(entry_t const& rhs) const { return value_ == rhs.value_; }
    bool operator!=(entry_t const& rhs) const { return value_ != rhs.value_; }
    bool operator<(entry_t const& rhs) const { return value_ < rhs.value_; }
    bool operator>(entry_t const& rhs) const { return value_ > rhs.value_; }
    bool operator<=(entry_t const& rhs) const { return value_ <= rhs.value_; }
    bool operator>=(entry_t const& rhs) const { return value_ >= rhs.value_; }

    entry_t(T value, iter_t const& iter, heap_t& heap) : value_(std::move(value)), self_(iter), meta_(iter), iter_(&meta_), heap_(&heap) {}

    entry_t(entry_t&& rhs) : value_(std::move(rhs.value_)), self_(), meta_(), iter_(rhs.iter_) {}

    entry_t& operator=(entry_t&& rhs) {
      value_ = std::move(rhs.value_);
      iter_ = rhs.iter_;
      *iter_ = self_;
      return *this;
    }

    T const& get() const { return value_; }

    void set(T new_value) {
      if (new_value == value_)
        return;
      if (new_value > value_) {
        value_ = std::move(new_value);
        std::push_heap(heap_->foo_.begin(), std::next(*iter_));
      } else {
        value_ = std::move(new_value);
        auto first = heap_->foo_.begin();
        auto pos = std::distance(first, *iter_);
        auto len = std::distance(first, heap_->foo_.end());
        auto value = std::move(**iter_);
        auto cursor = pos;
        while (cursor < (len - 1) / 2) {
          cursor = 2 * (cursor + 1);
          if (*(first + cursor) < *(first + (cursor - 1))) {
            --cursor;
          }
          if (*(first + cursor) <= value) {
            *(first + pos) = std::move(value);
            return;
          }
          *(first + pos) = std::move(*(first + cursor));
          pos = cursor;
        }
        if ((len & 1) == 0 && cursor == (len - 2) / 2) {
          cursor = 2 * (cursor + 1) - 1;
          if (*(first + cursor) <= value) {
            *(first + pos) = std::move(value);
            return;
          }
          *(first + pos) = std::move(*(first + cursor));
          pos = cursor;
        }
        *(first + pos) = std::move(value);
      }
    }

    iter_t* iter_pointer() { return iter_; }

  private:
    T value_;
    iter_t const self_;
    iter_t meta_;
    iter_t* iter_;
    heap_t* heap_ = nullptr;
  };

  heap_t() = delete;
  heap_t(size_t const capacity) { foo_.reserve(capacity); }

  heap_t(heap_t const&) = delete;
  heap_t(heap_t&&) = default;

  heap_t& operator=(heap_t const&) = delete;
  heap_t& operator=(heap_t&&) = delete;

  std::vector<iter_t*> load(std::vector<T> values) {
    size_t const inc = values.size();
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
    foo_.emplace_back(std::move(value), foo_.end(), *this);
    auto const bar = foo_.back().iter_pointer();
    std::push_heap(foo_.begin(), foo_.end());
    return bar;
  }

  size_t size() const { return foo_.size(); }

  bool empty() const { return foo_.empty(); }

  T const& top() const { return foo_.front().get(); }

  void pop() {
    std::pop_heap(foo_.begin(), foo_.end());
    foo_.pop_back();
  }

private:
  std::vector<entry_t> foo_;
};

template <typename Ctx> class btnctx_t {
public:
  virtual void aggregate(Ctx const& lhs, Ctx const& rhs) = 0;
  virtual void flush(Ctx& lhs, Ctx& rhs) = 0;
};

template <typename Int, typename Ctx, typename std::enable_if<std::is_base_of<btnctx_t<Ctx>, Ctx>::value>::type* = nullptr>
class segtree_t {
public:
  struct node_t {
    node_t* chd[2];
    Int lef, rig;
    Ctx ctx;
  };

  using ctx_modifier_t = std::function<void(node_t&)>;
  using ctx_collector_t = std::function<Ctx(node_t const&)>;

  segtree_t() = delete;
  segtree_t(size_t const capacity) { node_pool_.resize(capacity << 1); }

  segtree_t(segtree_t const&) = delete;
  segtree_t(segtree_t&&) = delete;

  segtree_t& operator=(segtree_t const&) = delete;
  segtree_t& operator=(segtree_t&&) = delete;

  void build(Int const lef, Int const rig, ctx_modifier_t const& initializer) {
    clear();
    build(&root_, lef, std::max(lef, rig), initializer);
  }

  void update(Int const pos, ctx_modifier_t const& updater) { update(pos, pos, updater); }

  void update(Int const lef, Int const rig, ctx_modifier_t const& updater) {
    if (lef <= rig && lef <= root_->rig && rig >= root_->lef) {
      update(*root_, lef, rig, updater);
    }
  }

  Ctx query(Int const pos, ctx_collector_t const& querier = default_collector()) { return query(pos, pos, querier); }

  Ctx query(Int const lef, Int const rig, ctx_collector_t const& querier = default_collector()) {
    if (lef <= rig && lef <= root_->rig && rig >= root_->lef) {
      return query(*root_, lef, rig, querier);
    } else {
      return {};
    }
  }

private:
  void build(node_t** hook, Int const lef, Int const rig, ctx_modifier_t const& initializer) {
    *hook = new_node();
    node_t& node = **hook;
    node.lef = lef;
    node.rig = rig;
    initializer(node);
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

  void update(node_t& node, Int const lef, Int const rig, ctx_modifier_t const& updater) {
    if (lef <= node.lef && node.rig <= rig) {
      updater(node);
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

  Ctx query(node_t& node, Int const lef, Int const rig, ctx_collector_t const& querier) {
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

  node_t* new_node() { return &node_pool_[num_++]; }

  static ctx_collector_t const& default_collector() {
    static ctx_collector_t collector = [](node_t const& node) -> Ctx { return node.ctx; };
    return collector;
  }

  std::vector<node_t> node_pool_;
  node_t* root_ = nullptr;
  size_t num_ = 0;
};
} // namespace

/* Graph Algorithms */
inline namespace {

template <typename TypeW, typename TypeU = void> struct edge_t {
  using vid_t = std::size_t;

  vid_t v;
  [[no_unique_address]] std::conditional_t<std::is_void_v<TypeW>, placeholder_t, TypeW> w;
  [[no_unique_address]] std::conditional_t<std::is_void_v<TypeU>, placeholder_t, vid_t> u;
  edge_t* next = nullptr;
};

template <std::size_t I, typename TypeW, typename TypeU> decltype(auto) get(edge_t<TypeW, TypeU>& e) {
  if constexpr (I == 0)
    return (e.v);
  else if constexpr (I == 1 && !std::is_void_v<TypeW>)
    return (e.w);
  else
    static_assert(I < 2, "edge_t only decomposes into [v] or [v, w]");
}

template <std::size_t I, typename TypeW, typename TypeU> decltype(auto) get(edge_t<TypeW, TypeU> const& e) {
  if constexpr (I == 0)
    return e.v;
  else if constexpr (I == 1 && !std::is_void_v<TypeW>)
    if constexpr (sizeof(TypeW) <= sizeof(void*)) {
      return e.w;
    } else {
      return (e.w);
    }
  else
    static_assert(I < 2, "edge_t only decomposes into [v] or [v, w]");
}

template <typename TypeW, typename TypeU = void> class adjlist_t {
public:
  using vid_t = std::size_t;
  using edge_t = edge_t<TypeW, TypeU>;

private:
  std::vector<edge_t*> heads_;
  std::vector<edge_t> pool_;
  edge_t* tail_ = nullptr;

public:
  adjlist_t(std::size_t v_num, std::size_t e_num) : heads_(v_num, nullptr), pool_(e_num), tail_(pool_.data()) {}

  void clear() noexcept {
    std::fill(heads_.begin(), heads_.end(), nullptr);
    tail_ = pool_.data();
  }

  template <typename T = TypeW> std::enable_if_t<!std::is_void_v<T>, void> add_edge(vid_t u, vid_t v, T w) noexcept {
    *tail_ = edge_t{v, w, convert_u(u), heads_[u]};
    heads_[u] = tail_++;
  }

  template <typename T = TypeW> std::enable_if_t<std::is_void_v<T>, void> add_edge(vid_t u, vid_t v) noexcept {
    *tail_ = edge_t{v, placeholder, convert_u(u), heads_[u]};
    heads_[u] = tail_++;
  }

private:
  static constexpr auto convert_u(vid_t u) {
    if constexpr (std::is_void_v<TypeU>)
      return placeholder;
    else
      return u;
  }

  struct vid_iter {
    edge_t* cur;

    vid_t& operator*() const { return cur->v; }
    vid_iter& operator++() {
      cur = cur->next;
      return *this;
    }
    bool operator!=(vid_iter const& o) const { return cur != o.cur; }
  };

  struct vid_range {
    edge_t* head;
    auto begin() const { return vid_iter{head}; }
    auto end() const { return vid_iter{nullptr}; }
  };

  struct edge_iter {
    edge_t* cur;

    edge_t& operator*() const { return *cur; }
    edge_iter& operator++() {
      cur = cur->next;
      return *this;
    }
    bool operator!=(edge_iter const& o) const { return cur != o.cur; }
  };

  struct edge_range {
    edge_t* head;
    auto begin() const { return edge_iter{head}; }
    auto end() const { return edge_iter{nullptr}; }
  };

public:
  auto operator[](vid_t u) const noexcept {
    if constexpr (std::is_void_v<TypeW>) {
      return vid_range{heads_[u]};
    } else {
      return edge_range{heads_[u]};
    }
  }

  auto operator[](vid_t u) noexcept {
    if constexpr (std::is_void_v<TypeW>) {
      return vid_range{heads_[u]};
    } else {
      return edge_range{heads_[u]};
    }
  }
};
} // namespace

/* Class imod_t */
inline namespace {
template <int_fast64_t token, typename Int> struct add_safe {
  static constexpr bool value = std::numeric_limits<Int>::max() - (token - 1) >= (token - 1);
};

template <int_fast64_t token, typename Int> struct sub_safe {
  static constexpr bool value = std::numeric_limits<Int>::min() - (1 - token) <= (1 - token);
};

template <int_fast64_t token, typename Int> struct mul_safe {
  static constexpr bool value = std::numeric_limits<Int>::max() / (token - 1) >= (token - 1);
};

template <int_fast64_t token> class imod_t {
  using foo_t = int_fast64_t;
  static_assert(token > 0, "");
  static_assert(std::is_integral<foo_t>::value, "");
  static_assert(std::is_signed<foo_t>::value, "");
  static_assert(std::numeric_limits<foo_t>::max() > token, "");

public:
  imod_t() = default;
  imod_t(imod_t const&) = default;
  imod_t(imod_t&&) = default;

  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr>
  imod_t(Int const rhs) : foo_(rhs % token) {}

  imod_t& operator=(imod_t const&) = default;
  imod_t& operator=(imod_t&&) = default;

  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t& operator=(Int const rhs) {
    foo_ = rhs % token;
    return *this;
  }

  explicit operator bool() const noexcept { return foo_ != 0; }

  static int_fast64_t mod() { return token; }

  imod_t operator+(imod_t const& rhs) const {
    imod_t bar(*this);
    bar += rhs;
    return bar;
  }
  template <typename std::enable_if<add_safe<token, foo_t>::value>::type* = nullptr> imod_t& operator+=(imod_t const& rhs) {
    foo_ = (foo_ + rhs.foo_) % token;
    return *this;
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t operator+(Int const rhs) const {
    return *this + imod_t(rhs);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t& operator+=(Int const rhs) {
    return *this += imod_t(rhs);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr>
  friend imod_t operator+(Int const lhs, imod_t const& rhs) {
    return rhs + lhs;
  }

  imod_t operator-(imod_t const& rhs) const {
    imod_t bar(*this);
    bar -= rhs;
    return bar;
  }
  template <typename std::enable_if<sub_safe<token, foo_t>::value>::type* = nullptr> imod_t& operator-=(imod_t const& rhs) {
    foo_ = (foo_ - rhs.foo_) % token;
    return *this;
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t operator-(Int const rhs) const {
    return *this - imod_t(rhs);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t& operator-=(Int const rhs) {
    return *this -= imod_t(rhs);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr>
  friend imod_t operator-(Int const lhs, imod_t const& rhs) {
    return imod_t(lhs) - rhs;
  }

  imod_t operator*(imod_t const& rhs) const {
    imod_t bar(*this);
    bar *= rhs;
    return bar;
  }
  template <typename std::enable_if<mul_safe<token, foo_t>::value>::type* = nullptr> imod_t& operator*=(imod_t const& rhs) {
    foo_ = (foo_ * rhs.foo_) % token;
    return *this;
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t operator*(Int const rhs) const {
    return *this * imod_t(rhs);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t& operator*=(Int const rhs) {
    return *this *= imod_t(rhs);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr>
  friend imod_t operator*(Int const lhs, imod_t const& rhs) {
    return rhs * lhs;
  }

  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t operator/(Int const rhs) const {
    return *this * inverse(rhs, token);
  }
  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> imod_t& operator/=(Int const rhs) {
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

  long long lld() const { return (foo_ + token) % token; }

private:
  foo_t foo_ = 0;
  static imod_t const& identity() {
    static imod_t const foo(1);
    return foo;
  }
};
} // namespace

/* Class matrix_t */
inline namespace {
template <typename Type> class matrix_t {
public:
  matrix_t() = default;
  matrix_t(matrix_t const&) = default;
  matrix_t(matrix_t&&) = default;

  matrix_t(size_t const r, size_t const c) : foo_(r, std::vector<Type>(c, 0)) {}

  matrix_t(std::vector<std::vector<Type>>&& bar) : foo_(bar) {
    size_t width = 0;
    for (auto const& row : foo_) {
      width = std::max(row.size(), width);
    }
    for (auto& row : foo_) {
      row.resize(width, 0);
    }
  }

  matrix_t& operator=(matrix_t const&) = default;
  matrix_t& operator=(matrix_t&&) = default;

  size_t height() const { return foo_.size(); }

  size_t width() const { return foo_.empty() ? 0 : foo_.front().size(); }

  Type at(size_t const r, size_t const c) const {
    if (r >= height() || c >= width()) {
      return 0;
    }
    return foo_[r][c];
  }

  static matrix_t one(size_t const r, size_t const c) {
    matrix_t ret(r, c);
    auto const d = std::min(r, c);
    for (size_t i = 0; i < d; ++i) {
      ret[i][i] = 1;
    }
    return ret;
  }

  matrix_t operator+(matrix_t const& rhs) const {
    auto const h = std::max(height(), rhs.height());
    auto const w = std::max(width(), rhs.width());
    matrix_t ret(h, w);
    for (size_t r = 0; r < h; ++r) {
      for (size_t c = 0; c < w; ++c) {
        ret[r][c] = at(r, c) + rhs.at(r, c);
      }
    }
    return ret;
  }

  matrix_t operator-(matrix_t const& rhs) const {
    auto const h = std::max(height(), rhs.height());
    auto const w = std::max(width(), rhs.width());
    matrix_t ret(h, w);
    for (size_t r = 0; r < h; ++r) {
      for (size_t c = 0; c < w; ++c) {
        ret[r][c] = at(r, c) - rhs.at(r, c);
      }
    }
    return ret;
  }

  matrix_t operator*(matrix_t const& rhs) const {
    auto const h = height();
    auto const w = rhs.width();
    auto const d = std::min(width(), rhs.height());
    matrix_t ret(h, w);
    for (size_t r = 0; r < h; ++r) {
      for (size_t c = 0; c < w; ++c) {
        for (size_t i = 0; i < d; ++i) {
          ret[r][c] += at(r, i) * rhs.at(i, c);
        }
      }
    }
    return ret;
  }

  matrix_t& operator+=(matrix_t const& rhs) {
    *this = *this + rhs;
    return *this;
  }

  matrix_t& operator-=(matrix_t const& rhs) {
    *this = *this - rhs;
    return *this;
  }

  matrix_t& operator*=(matrix_t const& rhs) {
    *this = *this * rhs;
    return *this;
  }

  template <typename Int, typename std::enable_if<std::is_integral<Int>::value>::type* = nullptr> matrix_t pow(Int const p) const {
    matrix_t ret{matrix_t::one(height(), width())};
    matrix_t cur(*this);
    if (p > 0) {
      for (Int i = 1;; i <<= 1) {
        if (p & i) {
          ret *= cur;
        }
        cur *= cur;
        if (i > (p >> 1)) {
          break;
        }
      }
    }
    return ret;
  }

  std::vector<Type>& operator[](size_t const r) { return foo_[r]; }

  std::vector<Type> const& operator[](size_t const r) const { return foo_[r]; }

  std::vector<std::vector<Type>> const& data() const { return foo_; }

private:
  std::vector<std::vector<Type>> foo_;
};
} // namespace
} // namespace joshu

namespace std {
// joshu::tuple2d_t
template <typename TX, typename TY> struct hash<joshu::tuple2d_t<TX, TY>> {
  size_t operator()(joshu::tuple2d_t<TX, TY> const& c) const {
    size_t const lhs = hash<TX>{}(c.x);
    size_t const rhs = hash<TY>{}(c.y);
    return lhs ^ (rhs + 0x9e3779b9 + (lhs << 6) + (lhs >> 2));
  }
};

// joshu::tuple3d_t
template <typename TX, typename TY, typename TZ> struct hash<joshu::tuple3d_t<TX, TY, TZ>> {
  size_t operator()(joshu::tuple3d_t<TX, TY, TZ> const& c) const {
    size_t const hx = hash<TX>{}(c.x);
    size_t const hy = hash<TY>{}(c.y);
    size_t const hz = hash<TZ>{}(c.z);
    return hx ^ (hy + 0x9e3779b9 + (hx << 6) + (hx >> 2)) ^ (hz + 0x9e3779b9 + (hy << 6) + (hy >> 2));
  }
};

// joshu::edge_t
template <typename TypeW, typename TypeU>
struct tuple_size<joshu::edge_t<TypeW, TypeU>> : std::integral_constant<std::size_t, std::is_void_v<TypeW> ? 1 : 2> {};
template <typename TypeW, typename TypeU> struct tuple_element<0, joshu::edge_t<TypeW, TypeU>> {
  using type = std::size_t;
};
template <typename TypeW, typename TypeU>
  requires(!std::is_void_v<TypeW>)
struct tuple_element<1, joshu::edge_t<TypeW, TypeU>> {
  using type = TypeW;
};
template <typename TypeW, typename TypeU> struct tuple_element<0, joshu::edge_t<TypeW, TypeU> const> {
  using type = std::size_t const;
};
template <typename TypeW, typename TypeU>
  requires(!std::is_void_v<TypeW>)
struct tuple_element<1, joshu::edge_t<TypeW, TypeU> const> {
  using type = TypeW const;
};
} // namespace std

inline namespace {
// typedefs
using lld = long long;
using i80 = __int128_t;
using llf = long double;
using pii = joshu::tuple2d_t<int, int>;
using pil = joshu::tuple2d_t<int, lld>;
using pli = joshu::tuple2d_t<lld, int>;
using pll = joshu::tuple2d_t<lld, lld>;
using mod_t = joshu::imod_t<1000000007>;
// constant defs
// [[maybe_unused]] int constexpr inf = 0x3f3f3f3f;
// [[maybe_unused]] double constexpr inf = 1.3e154;
[[maybe_unused]] lld constexpr inf = 0x3f3f3f3f3f3f3f3fLL;
[[maybe_unused]] double constexpr eps = 1e-22;
} // namespace

#ifndef UNITTEST

using namespace std;
using namespace joshu;

int n;
lld a[210000], b[210000], c[210000];
tuple3d_t<lld, lld, lld> f[210000];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  // std::cout << std::fixed;
  std::cout << std::setprecision(14);
  
  int case_num;
  while (cin >> case_num) {
    while (case_num--) {
      cin >> n;
      for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
        f[i].x = min(a[i], b[i]);
        f[i].y = min(b[i] - f[i].x, c[i]);
        f[i].z = min(b[i], c[i]) - f[i].y;
        // cerr << "f[" << i << "] = (" << f[i].x << " " << f[i].y << " " << f[i].z << ")\n";
      }

      lld x = 0, y = 0, z = 0;
      for (int i = 0; i < n; ++i) {
        x += f[i].x;
        y += f[i].y;
        z += f[i].z;
      }

      // cerr << "xyz = (" << x << " " << y << " " << z << ")\n";

      auto const pass = [&](lld const t) -> bool {
        lld i = x, j = y;
        if (i < t) return false;
        lld const d = min(i - t, z);
        i -= d;
        j += d;
        // cerr << "pass ? " << i << ", " << j << " >= " << t << endl;
        return i >= t && j >= t;
      };
      auto const res = bsearch_last_pass(min(x, y), max(x, y), pass);

      // cerr << "xyz = (" << x << " " << y << " " << z << ")\n";

      cout << res << endl;
    }
  }

  return 0;
}
#endif
