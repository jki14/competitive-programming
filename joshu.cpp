#define UNITTEST

#include "joshu.hpp"

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/ui/text/TestRunner.h"

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
  CPPUNIT_TEST(TestImodT);
  CPPUNIT_TEST_SUITE_END();

private:
  template<typename Int, typename std::enable_if<
    std::is_unsigned<Int>::value>::type* = nullptr>
  size_t linear_count(Int const i) const {
    return (i == 0) ? 0 : (1 + linear_count(i & (i - 1)));
  }
  template<typename Int, typename std::enable_if<
    std::is_signed<Int>::value>::type* = nullptr>
  size_t linear_count(Int const i) const {
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
      int8_t const foo8 = static_cast<int8_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo8), joshu::popcount(foo8));
      auto const foo8u = static_cast<uint8_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo8u), joshu::popcount(foo8u));
      auto const foo16 = static_cast<int16_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo16), joshu::popcount(foo16));
      auto const foo16u = static_cast<uint16_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo16u), joshu::popcount(foo16u));
      auto const foo32 = static_cast<int32_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo32), joshu::popcount(foo32));
      auto const foo32u = static_cast<uint32_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo32u), joshu::popcount(foo32u));
      auto const foo64 = static_cast<int64_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo64), joshu::popcount(foo64));
      auto const foo64u = static_cast<uint64_t>(joshu::randint());
      CPPUNIT_ASSERT_EQUAL(linear_count(foo64u), joshu::popcount(foo64u));
    }
  }

  void TestLowbit() {
    CPPUNIT_ASSERT_EQUAL(0, joshu::lowbit(0));
    CPPUNIT_ASSERT_EQUAL(1, joshu::lowbit(1));
    CPPUNIT_ASSERT_EQUAL(2, joshu::lowbit(2));
    CPPUNIT_ASSERT_EQUAL(2147483648u, joshu::lowbit(2147483648u));
    for (int i = 0; i < 65536; ++i) {
      auto const foo = joshu::randint();
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
      auto const bar = joshu::randint();
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
      if (x < 2) return false;
      for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
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
      if (next == table.end()) break;
      CPPUNIT_ASSERT(*iter < *next);
      for (int i = *iter + 1; i < *next; ++i) {
        CPPUNIT_ASSERT(!pure_prime_check(i));
      }
    }
  }

  void TestPrimes() {
    auto const pure_prime_check = [](int const x) -> bool {
      if (x < 2) return false;
      for (int i = 2; i <= x / i; ++i) {
        if (x % i == 0) return false;
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
      if (next == table.end()) break;
      CPPUNIT_ASSERT(*iter < *next);
      for (int i = *iter + 1; i < *next; ++i) {
        CPPUNIT_ASSERT(!pure_prime_check(i));
      }
    }
  }

  void TestBinarySearch() {
    for (int i = 0; i < 65536; ++i) {
      int64_t const bar = joshu::randint() % 4611686014132420608LL + 1LL;
      auto const square_gt = [bar](int64_t const i) {
        return i * i > bar;
      };
      auto const foo = joshu::binary_search(1LL, 2147483647LL, square_gt);
      CPPUNIT_ASSERT(foo * foo > bar);
      CPPUNIT_ASSERT((foo - 1) * (foo - 1) <= bar);
    }
    auto const gt_zero = [](int64_t const i) {
      return i * i > 0;
    };
    CPPUNIT_ASSERT_EQUAL(1LL, joshu::binary_search(1LL, 65535LL, gt_zero));
    auto const gt_maxi32_sequare_minus_one = [](int64_t const i) {
      return i * i >  4611686014132420608LL;
    };
    CPPUNIT_ASSERT_EQUAL(2147483647LL,
                         joshu::binary_search(1LL,
                                              2147483647LL,
                                              gt_maxi32_sequare_minus_one)
    );
    auto const gt_maxi32_sequare = [](int64_t const i) {
      return i * i >  4611686014132420609LL;
    };
    CPPUNIT_ASSERT_EQUAL(-1LL,
                         joshu::binary_search(1LL,
                                              2147483647LL,
                                              gt_maxi32_sequare)
    );
  }

  void TestHeapT() {
    joshu::heap_t<int> foo;
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

  class segsum_t : public joshu::btnctx_t {
  public:
    segsum_t() = delete;
    segsum_t(int const len) : length_(len), modify_(0), sum_(0) { }

    void aggregate(joshu::btnctx_t const* const lhs,
                   joshu::btnctx_t const* const rhs) override {
      segsum_t const* const lhc = static_cast<segsum_t const* const>(lhs);
      segsum_t const* const rhc = static_cast<segsum_t const* const>(rhs);
      sum_ = lhc->calc() + rhc->calc();
    }
    void flush(joshu::btnctx_t* lhs, joshu::btnctx_t* rhs) override {
      segsum_t* lhc = static_cast<segsum_t*>(lhs);
      segsum_t* rhc = static_cast<segsum_t*>(rhs);
      lhc->modify_ += modify_;
      rhc->modify_ += modify_;
      sum_ += modify_ * length_;
      modify_ = 0;
    }

    int calc() const {
      return sum_ + modify_ * length_;
    }

    int const length_;
    int modify_, sum_;
  };

  void TestBTNCtxT() {
    segsum_t pnt(3), lhs(2), rhs(1);
    lhs.sum_ = 3;
    rhs.sum_ = 5;

    joshu::btnctx_t* pntctx = static_cast<joshu::btnctx_t*>(&pnt);
    joshu::btnctx_t* lhsctx = static_cast<joshu::btnctx_t*>(&lhs);
    joshu::btnctx_t* rhsctx = static_cast<joshu::btnctx_t*>(&rhs);

    CPPUNIT_ASSERT_EQUAL(0, pnt.calc());
    CPPUNIT_ASSERT_EQUAL(3, lhs.calc());
    CPPUNIT_ASSERT_EQUAL(5, rhs.calc());

    pntctx->aggregate(lhsctx, rhsctx);
    CPPUNIT_ASSERT_EQUAL(8, pnt.calc());

    pnt.modify_ = 1;
    CPPUNIT_ASSERT_EQUAL(11, pnt.calc());
    CPPUNIT_ASSERT_EQUAL(3, lhs.calc());
    CPPUNIT_ASSERT_EQUAL(5, rhs.calc());

    pntctx->flush(lhsctx, rhsctx);
    CPPUNIT_ASSERT_EQUAL(11, pnt.calc());
    CPPUNIT_ASSERT_EQUAL(5, lhs.calc());
    CPPUNIT_ASSERT_EQUAL(6, rhs.calc());
    CPPUNIT_ASSERT_EQUAL(0, pnt.modify_);
    CPPUNIT_ASSERT_EQUAL(1, lhs.modify_);
    CPPUNIT_ASSERT_EQUAL(1, rhs.modify_);
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

public:
  ~TestJoshu() = default;
  void setUp() override { }
  void tearDown() override { }
};

int main() {
  CppUnit::TextUi::TestRunner runner;
  runner.addTest(TestJoshu::suite());
  runner.run();
  return 0;
}
