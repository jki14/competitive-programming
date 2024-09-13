#define UNITTEST

#include "joshu.hpp"

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/ui/text/TestRunner.h"

template <typename Type> static std::ostream& operator<<(std::ostream& ost, std::vector<Type> const& rhs) {
  ost << "[";
  for (size_t i = 0; i < rhs.size(); ++i) {
    if (i)
      ost << ", ";
    ost << rhs[i];
  }
  ost << "]";
  return ost;
}

class TestJoshu : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(TestJoshu);
  CPPUNIT_TEST(TestPopcount);
  CPPUNIT_TEST(TestLowbit);
  CPPUNIT_TEST(TestBitlen);
  CPPUNIT_TEST(TestGcd);
  CPPUNIT_TEST(TestPrimetable);
  CPPUNIT_TEST(TestPrimes);
  CPPUNIT_TEST(TestBinarySearch);
  CPPUNIT_TEST(TestHeapT);
  CPPUNIT_TEST(TestBTNCtxT);
  CPPUNIT_TEST(TestSegTreeT);
  CPPUNIT_TEST(TestImodT);
  CPPUNIT_TEST(TestMatrixT);
  CPPUNIT_TEST_SUITE_END();

private:
  template <typename Int, typename std::enable_if<std::is_unsigned<Int>::value>::type* = nullptr> size_t linear_count(Int const i) const {
    return (i == 0) ? 0 : (1 + linear_count(i & (i - 1)));
  }
  template <typename Int, typename std::enable_if<std::is_signed<Int>::value>::type* = nullptr> size_t linear_count(Int const i) const {
    auto const u = static_cast<typename std::make_unsigned<Int>::type>(i);
    return linear_count(u);
  }

protected:
  void TestPopcount() {
    CPPUNIT_ASSERT_EQUAL(3lu, linear_count(42));
    CPPUNIT_ASSERT_EQUAL(3lu, joshu::popcount(42));

    CPPUNIT_ASSERT_EQUAL(0lu, linear_count(0));
    CPPUNIT_ASSERT_EQUAL(0lu, joshu::popcount(0));

    CPPUNIT_ASSERT_EQUAL(8lu, linear_count(int8_t(-1)));
    CPPUNIT_ASSERT_EQUAL(8lu, linear_count(uint8_t(-1)));
    CPPUNIT_ASSERT_EQUAL(16lu, linear_count(int16_t(-1)));
    CPPUNIT_ASSERT_EQUAL(16lu, linear_count(uint16_t(-1)));
    CPPUNIT_ASSERT_EQUAL(32lu, linear_count(int32_t(-1)));
    CPPUNIT_ASSERT_EQUAL(32lu, linear_count(uint32_t(-1)));
    CPPUNIT_ASSERT_EQUAL(64lu, linear_count(int64_t(-1)));
    CPPUNIT_ASSERT_EQUAL(64lu, linear_count(uint64_t(-1)));

    CPPUNIT_ASSERT_EQUAL(8lu, joshu::popcount(int8_t(-1)));
    CPPUNIT_ASSERT_EQUAL(8lu, joshu::popcount(uint8_t(-1)));
    CPPUNIT_ASSERT_EQUAL(16lu, joshu::popcount(int16_t(-1)));
    CPPUNIT_ASSERT_EQUAL(16lu, joshu::popcount(uint16_t(-1)));
    CPPUNIT_ASSERT_EQUAL(32lu, joshu::popcount(int32_t(-1)));
    CPPUNIT_ASSERT_EQUAL(32lu, joshu::popcount(uint32_t(-1)));
    CPPUNIT_ASSERT_EQUAL(64lu, joshu::popcount(int64_t(-1)));
    CPPUNIT_ASSERT_EQUAL(64lu, joshu::popcount(uint64_t(-1)));

    for (int i = 0; i < 65536; ++i) {
      int8_t const foo8 = static_cast<int8_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo8), joshu::popcount(foo8));
      auto const foo8u = static_cast<uint8_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo8u), joshu::popcount(foo8u));
      auto const foo16 = static_cast<int16_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo16), joshu::popcount(foo16));
      auto const foo16u = static_cast<uint16_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo16u), joshu::popcount(foo16u));
      auto const foo32 = static_cast<int32_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo32), joshu::popcount(foo32));
      auto const foo32u = static_cast<uint32_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo32u), joshu::popcount(foo32u));
      auto const foo64 = static_cast<int64_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo64), joshu::popcount(foo64));
      auto const foo64u = static_cast<uint64_t>(joshu::randllu());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo64u), joshu::popcount(foo64u));
    }
  }

  void TestLowbit() {
    CPPUNIT_ASSERT_EQUAL(0, joshu::lowbit(0));
    CPPUNIT_ASSERT_EQUAL(1, joshu::lowbit(1));
    CPPUNIT_ASSERT_EQUAL(2, joshu::lowbit(2));
    CPPUNIT_ASSERT_EQUAL(2147483648u, joshu::lowbit(2147483648u));
    for (int i = 0; i < 65536; ++i) {
      auto const foo = joshu::randllu();
      auto const bar = joshu::lowbit(foo);
      CPPUNIT_ASSERT_EQUAL(1lu, joshu::popcount(bar));
      CPPUNIT_ASSERT_EQUAL(bar, foo & bar);
      for (auto k = bar >> 1; k > 0; k >>= 1) {
        CPPUNIT_ASSERT_EQUAL(static_cast<decltype(k)>(0), foo & k);
      }
    }
  }

  void TestBitlen() {
    CPPUNIT_ASSERT_EQUAL(0, joshu::bitlen(0));
    CPPUNIT_ASSERT_EQUAL(1, joshu::bitlen(1));
    CPPUNIT_ASSERT_EQUAL(2, joshu::bitlen(2));
    CPPUNIT_ASSERT_EQUAL(32u, joshu::bitlen(2147483648u));
    for (int i = 0; i < 65536; ++i) {
      auto const bar = joshu::randllu();
      auto const foo = joshu::bitlen(bar);
      auto const low = static_cast<__int128>(1) << foo >> 1;
      auto const hig = static_cast<__int128>(1) << foo;
      CPPUNIT_ASSERT(low <= bar && bar < hig);
    }
  }

  void TestGcd() {
    CPPUNIT_ASSERT_EQUAL(0, joshu::gcd(0, 0));
    CPPUNIT_ASSERT_EQUAL(42, joshu::gcd(42, 0));
    CPPUNIT_ASSERT_EQUAL(42, joshu::gcd(0, 42));

    CPPUNIT_ASSERT_EQUAL(1, joshu::gcd(4, 7));
    CPPUNIT_ASSERT_EQUAL(2, joshu::gcd(4, 2));
    CPPUNIT_ASSERT_EQUAL(6, joshu::gcd(12, 66));
    CPPUNIT_ASSERT_EQUAL(2, joshu::gcd(-2, 4));
    CPPUNIT_ASSERT_EQUAL(4, joshu::gcd(12, -44));
    CPPUNIT_ASSERT_EQUAL(4, joshu::gcd(-444, -44));
  }

  void TestPrimetable() {
    auto const pure_prime_check = [](int const x) -> bool {
      if (x < 2)
        return false;
      for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0)
          return false;
      }
      return true;
    };
    CPPUNIT_ASSERT(!pure_prime_check(0));
    CPPUNIT_ASSERT(!pure_prime_check(1));
    CPPUNIT_ASSERT(pure_prime_check(2));

    auto const table = joshu::primetable(65536);
    CPPUNIT_ASSERT_EQUAL(2, table.front());

    for (auto iter = table.begin(); iter != table.end(); ++iter) {
      CPPUNIT_ASSERT(pure_prime_check(*iter));
      auto next = std::next(iter);
      if (next == table.end())
        break;
      CPPUNIT_ASSERT(*iter < *next);
      for (int i = *iter + 1; i < *next; ++i) {
        CPPUNIT_ASSERT(!pure_prime_check(i));
      }
    }
  }

  void TestPrimes() {
    auto const pure_prime_check = [](int const x) -> bool {
      if (x < 2)
        return false;
      for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0)
          return false;
      }
      return true;
    };
    CPPUNIT_ASSERT(!pure_prime_check(0));
    CPPUNIT_ASSERT(!pure_prime_check(1));
    CPPUNIT_ASSERT(pure_prime_check(2));

    joshu::primes(256);
    for (int i = 256; i < 512; ++i) {
      joshu::primes(i);
    }
    joshu::primes(1024);
    joshu::primes(512);
    auto const& table = joshu::primes(65536);
    CPPUNIT_ASSERT_EQUAL(2, table.front());

    for (auto iter = table.begin(); iter != table.end(); ++iter) {
      CPPUNIT_ASSERT(pure_prime_check(*iter));
      auto next = std::next(iter);
      if (next == table.end())
        break;
      CPPUNIT_ASSERT(*iter < *next);
      for (int i = *iter + 1; i < *next; ++i) {
        CPPUNIT_ASSERT(!pure_prime_check(i));
      }
    }
  }

  void TestBinarySearch() {
    for (int i = 0; i < 65536; ++i) {
      int64_t const bar = joshu::randllu() % 4611686014132420608LL + 1LL;
      auto const square_gt = [bar](int64_t const i) { return i * i > bar; };
      auto const foo = joshu::binary_search(1LL, 2147483647LL, square_gt);
      CPPUNIT_ASSERT(foo * foo > bar);
      CPPUNIT_ASSERT((foo - 1) * (foo - 1) <= bar);
    }
    auto const gt_zero = [](int64_t const i) { return i * i > 0; };
    CPPUNIT_ASSERT_EQUAL(1LL, joshu::binary_search(1LL, 65535LL, gt_zero));
    auto const gt_maxi32_sequare_minus_one = [](int64_t const i) { return i * i > 4611686014132420608LL; };
    CPPUNIT_ASSERT_EQUAL(2147483647LL, joshu::binary_search(1LL, 2147483647LL, gt_maxi32_sequare_minus_one));
    auto const gt_maxi32_sequare = [](int64_t const i) { return i * i > 4611686014132420609LL; };
    CPPUNIT_ASSERT_EQUAL(-1LL, joshu::binary_search(1LL, 2147483647LL, gt_maxi32_sequare));
  }

  void TestHeapT() {
    joshu::heap_t<int> foo(1048576);
    std::vector<int> bar = {3, 1, 4, 1, 5, 9};
    auto entries = foo.load(bar);
    CPPUNIT_ASSERT_EQUAL(6lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[2])->set(6);
    CPPUNIT_ASSERT_EQUAL(6, (*entries[2])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[2])->set(1);
    CPPUNIT_ASSERT_EQUAL(1, (*entries[2])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[0])->set(4);
    CPPUNIT_ASSERT_EQUAL(4, (*entries[0])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[0])->set(5);
    CPPUNIT_ASSERT_EQUAL(5, (*entries[0])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[0])->set(6);
    CPPUNIT_ASSERT_EQUAL(6, (*entries[0])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[0])->set(7);
    CPPUNIT_ASSERT_EQUAL(7, (*entries[0])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[0])->set(8);
    CPPUNIT_ASSERT_EQUAL(8, (*entries[0])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(5lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(8, foo.top());

    (*entries[0])->set(9);
    CPPUNIT_ASSERT_EQUAL(9, (*entries[0])->get());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    (*entries[1])->set(11);
    CPPUNIT_ASSERT_EQUAL(11, (*entries[1])->get());
    CPPUNIT_ASSERT_EQUAL(11, foo.top());

    entries.emplace_back(foo.push(4));
    CPPUNIT_ASSERT_EQUAL(6lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(11, foo.top());

    auto const extra = foo.load({5, 6, 7});
    std::copy(extra.begin(), extra.end(), std::back_inserter(entries));
    CPPUNIT_ASSERT_EQUAL(9lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(11, foo.top());

    (*entries[7])->set(8);
    CPPUNIT_ASSERT_EQUAL(8, (*entries[7])->get());
    CPPUNIT_ASSERT_EQUAL(11, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(8lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(9, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(7lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(8, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(6lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(7, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(5lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(6, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(4lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(5, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(3lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(4, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(2lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(1, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(1lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(false, foo.empty());
    CPPUNIT_ASSERT_EQUAL(1, foo.top());

    foo.pop();
    CPPUNIT_ASSERT_EQUAL(0lu, foo.size());
    CPPUNIT_ASSERT_EQUAL(true, foo.empty());
  }

  class segsum_t : public joshu::btnctx_t<segsum_t> {
  public:
    segsum_t() = default;
    segsum_t(int const len, int const sum = 0) : length_(len), modify_(0), sum_(sum) {}

    segsum_t(segsum_t const&) = default;
    segsum_t(segsum_t&&) = default;

    segsum_t& operator=(segsum_t const&) = default;
    segsum_t& operator=(segsum_t&&) = default;

    void aggregate(segsum_t const& lhs, segsum_t const& rhs) override { sum_ = lhs.calc() + rhs.calc(); }
    void flush(segsum_t& lhs, segsum_t& rhs) override {
      lhs.modify_ += modify_;
      rhs.modify_ += modify_;
      sum_ += modify_ * length_;
      modify_ = 0;
    }

    int calc() const { return sum_ + modify_ * length_; }

    int length_ = 0;
    int modify_ = 0, sum_ = 0;
  };

  void TestBTNCtxT() {
    segsum_t pnt(3), lhs(2, 3), rhs(1, 5);

    CPPUNIT_ASSERT_EQUAL(0, pnt.calc());
    CPPUNIT_ASSERT_EQUAL(3, lhs.calc());
    CPPUNIT_ASSERT_EQUAL(5, rhs.calc());

    pnt.aggregate(lhs, rhs);
    CPPUNIT_ASSERT_EQUAL(8, pnt.calc());

    pnt.modify_ = 1;
    CPPUNIT_ASSERT_EQUAL(11, pnt.calc());
    CPPUNIT_ASSERT_EQUAL(3, lhs.calc());
    CPPUNIT_ASSERT_EQUAL(5, rhs.calc());

    pnt.flush(lhs, rhs);
    CPPUNIT_ASSERT_EQUAL(11, pnt.calc());
    CPPUNIT_ASSERT_EQUAL(5, lhs.calc());
    CPPUNIT_ASSERT_EQUAL(6, rhs.calc());
    CPPUNIT_ASSERT_EQUAL(0, pnt.modify_);
    CPPUNIT_ASSERT_EQUAL(1, lhs.modify_);
    CPPUNIT_ASSERT_EQUAL(1, rhs.modify_);
  }

  void TestSegTreeT() {
    joshu::segtree_t<int, segsum_t> segtree(5);
    segsum_t ctx;

    std::vector<int> init{1, 2, 3, 4, 5};
    int delta;
    auto const initializer = [&init](joshu::segtree_t<int, segsum_t>::node_t const& node) -> segsum_t {
      if (node.lef == node.rig) {
        return {1, init[node.lef - 1]};
      } else {
        return {0, 0};
      }
    };
    auto const updater = [&delta](joshu::segtree_t<int, segsum_t>::node_t const& node) -> segsum_t {
      auto bar = node.ctx;
      bar.modify_ += delta;
      return bar;
    };
    auto const querier = [](joshu::segtree_t<int, segsum_t>::node_t const& node) -> segsum_t { return node.ctx; };

    segtree.build(1, 5, initializer);
    // [1, 2, 3, 4, 5]
    ctx = segtree.query(1, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(2, querier);
    CPPUNIT_ASSERT_EQUAL(2, ctx.calc());
    ctx = segtree.query(3, querier);
    CPPUNIT_ASSERT_EQUAL(3, ctx.calc());
    ctx = segtree.query(4, querier);
    CPPUNIT_ASSERT_EQUAL(4, ctx.calc());
    ctx = segtree.query(5, querier);
    CPPUNIT_ASSERT_EQUAL(5, ctx.calc());

    delta = 2;
    segtree.update(2, updater);
    // [1, 4, 3, 4, 5]
    ctx = segtree.query(1, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(2, querier);
    CPPUNIT_ASSERT_EQUAL(4, ctx.calc());
    ctx = segtree.query(3, querier);
    CPPUNIT_ASSERT_EQUAL(3, ctx.calc());
    ctx = segtree.query(4, querier);
    CPPUNIT_ASSERT_EQUAL(4, ctx.calc());
    ctx = segtree.query(5, querier);
    CPPUNIT_ASSERT_EQUAL(5, ctx.calc());

    delta = -3;
    segtree.update(2, 4, updater);
    // [1, 1, 0, 1, 5]
    ctx = segtree.query(1, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(2, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(3, querier);
    CPPUNIT_ASSERT_EQUAL(0, ctx.calc());
    ctx = segtree.query(4, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(5, querier);
    CPPUNIT_ASSERT_EQUAL(5, ctx.calc());

    ctx = segtree.query(1, 1, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(1, 2, querier);
    CPPUNIT_ASSERT_EQUAL(2, ctx.calc());
    ctx = segtree.query(1, 3, querier);
    CPPUNIT_ASSERT_EQUAL(2, ctx.calc());
    ctx = segtree.query(1, 4, querier);
    CPPUNIT_ASSERT_EQUAL(3, ctx.calc());
    ctx = segtree.query(1, 5, querier);
    CPPUNIT_ASSERT_EQUAL(8, ctx.calc());

    ctx = segtree.query(2, 2, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(2, 3, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(2, 4, querier);
    CPPUNIT_ASSERT_EQUAL(2, ctx.calc());
    ctx = segtree.query(2, 5, querier);
    CPPUNIT_ASSERT_EQUAL(7, ctx.calc());

    ctx = segtree.query(3, 3, querier);
    CPPUNIT_ASSERT_EQUAL(0, ctx.calc());
    ctx = segtree.query(3, 4, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(3, 5, querier);
    CPPUNIT_ASSERT_EQUAL(6, ctx.calc());

    ctx = segtree.query(4, 4, querier);
    CPPUNIT_ASSERT_EQUAL(1, ctx.calc());
    ctx = segtree.query(4, 5, querier);
    CPPUNIT_ASSERT_EQUAL(6, ctx.calc());

    ctx = segtree.query(5, 5, querier);
    CPPUNIT_ASSERT_EQUAL(5, ctx.calc());
  }

  void TestImodT() {
    auto foo = 65535 + 65535 * imod_t(65535) + 65535 - (imod_t(65535) + 65535) * 65535;
    CPPUNIT_ASSERT_EQUAL(705294880LL, foo.lld());
    foo /= 65535;
    CPPUNIT_ASSERT_EQUAL(999934474LL, foo.lld());
    foo = foo.pow(7);
    CPPUNIT_ASSERT_EQUAL(71832005LL, foo.lld());
    CPPUNIT_ASSERT_EQUAL(71832005LL, (foo++).lld());
    CPPUNIT_ASSERT_EQUAL(71832007LL, (++foo).lld());
    CPPUNIT_ASSERT_EQUAL(71832007LL, (foo--).lld());
    CPPUNIT_ASSERT_EQUAL(71832005LL, (--foo).lld());
    CPPUNIT_ASSERT(foo);
    foo -= 71832005;
    CPPUNIT_ASSERT(!foo);
    foo = -1;
    imod_t bar = 65535;
    foo += bar;
    CPPUNIT_ASSERT_EQUAL(65534LL, foo.lld());
  }

  void TestMatrixT() {
    // test constructors
    joshu::matrix_t<int> const matrix_empty;
    CPPUNIT_ASSERT_EQUAL(std::vector<std::vector<int>>(), matrix_empty.data());

    joshu::matrix_t<int> const matrix_zero23(2, 3);
    std::vector<std::vector<int>> const raw_zero23{{0, 0, 0}, {0, 0, 0}};
    CPPUNIT_ASSERT_EQUAL(raw_zero23, matrix_zero23.data());

    joshu::matrix_t<int> const matrix_fib23({{1, 1}, {2, 3, 5}});
    std::vector<std::vector<int>> const raw_fib23{{1, 1, 0}, {2, 3, 5}};
    CPPUNIT_ASSERT_EQUAL(raw_fib23, matrix_fib23.data());

    // test size
    CPPUNIT_ASSERT_EQUAL(0lu, matrix_empty.height());
    CPPUNIT_ASSERT_EQUAL(0lu, matrix_empty.width());
    CPPUNIT_ASSERT_EQUAL(2lu, matrix_zero23.height());
    CPPUNIT_ASSERT_EQUAL(3lu, matrix_zero23.width());

    // test access
    CPPUNIT_ASSERT_EQUAL(0, matrix_fib23.at(0, 3));
    CPPUNIT_ASSERT_EQUAL(0, matrix_fib23.at(2, 0));
    CPPUNIT_ASSERT_EQUAL(0, matrix_fib23.at(2, 3));
    CPPUNIT_ASSERT_EQUAL(5, matrix_fib23.at(1, 2));
    CPPUNIT_ASSERT_EQUAL(3, matrix_fib23[1][1]);

    joshu::matrix_t<int> matrix_odd23({{1, 3, 5}, {7, 9, 11}});
    CPPUNIT_ASSERT_EQUAL(11, matrix_odd23[1][2]);
    matrix_odd23[1][2] = -1;
    CPPUNIT_ASSERT_EQUAL(-1, matrix_odd23[1][2]);
    CPPUNIT_ASSERT_EQUAL(-1, matrix_odd23.at(1, 2));

    // test static one
    std::vector<std::vector<int>> const raw_one23{{1, 0, 0}, {0, 1, 0}};
    CPPUNIT_ASSERT_EQUAL(raw_one23, joshu::matrix_t<int>::one(2, 3).data());

    // test arithmetic
    joshu::matrix_t<int> const matrix_fib32({{1, 1}, {2, 3}, {5, 8}});

    std::vector<std::vector<int>> const expected_add{{2, 2, 0}, {4, 6, 5}, {5, 8, 0}};
    CPPUNIT_ASSERT_EQUAL(expected_add, (matrix_fib32 + matrix_fib23).data());
    auto actual_add = matrix_fib32;
    actual_add += matrix_fib23;
    CPPUNIT_ASSERT_EQUAL(expected_add, actual_add.data());

    std::vector<std::vector<int>> const expected_sub{{0, 0, 0}, {0, 0, -5}, {5, 8, 0}};
    CPPUNIT_ASSERT_EQUAL(expected_sub, (matrix_fib32 - matrix_fib23).data());
    auto actual_sub = matrix_fib32;
    actual_sub -= matrix_fib23;
    CPPUNIT_ASSERT_EQUAL(expected_sub, actual_sub.data());

    std::vector<std::vector<int>> const expected_mul{{3, 4, 5}, {8, 11, 15}, {21, 29, 40}};
    CPPUNIT_ASSERT_EQUAL(expected_mul, (matrix_fib32 * matrix_fib23).data());
    auto actual_mul = matrix_fib32;
    actual_mul *= matrix_fib23;
    CPPUNIT_ASSERT_EQUAL(expected_mul, actual_mul.data());

    // test pow
    joshu::matrix_t<int> const fib_lhs({{1, 0}});
    joshu::matrix_t<int> const fib_rhs({{1, 1}, {1, 0}});
    CPPUNIT_ASSERT_EQUAL(1, (fib_lhs * fib_rhs.pow(0)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(1, (fib_lhs * fib_rhs.pow(1)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(2, (fib_lhs * fib_rhs.pow(2)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(3, (fib_lhs * fib_rhs.pow(3)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(5, (fib_lhs * fib_rhs.pow(4)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(8, (fib_lhs * fib_rhs.pow(5)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(13, (fib_lhs * fib_rhs.pow(6)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(21, (fib_lhs * fib_rhs.pow(7)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(34, (fib_lhs * fib_rhs.pow(8)).at(0, 0));
    CPPUNIT_ASSERT_EQUAL(55, (fib_lhs * fib_rhs.pow(9)).at(0, 0));
  }

public:
  ~TestJoshu() = default;
  void setUp() override {}
  void tearDown() override {}
};

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestJoshu::suite());
  runner.run();
  return 0;
}
