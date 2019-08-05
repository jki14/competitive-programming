#include "joshu.hpp"

#include "cppunit/extensions/HelperMacros.h"
#include "cppunit/ui/text/TestRunner.h"

class TestJoshu : public CppUnit::TestFixture {
  CPPUNIT_TEST_SUITE(TestJoshu);
  CPPUNIT_TEST(TestGcd);
  CPPUNIT_TEST(TestImodT);
  CPPUNIT_TEST_SUITE_END();

protected:
  void TestGcd() {
    CPPUNIT_ASSERT_EQUAL(1, joshu::gcd(4, 7));
    CPPUNIT_ASSERT_EQUAL(2, joshu::gcd(4, 2));
    CPPUNIT_ASSERT_EQUAL(6, joshu::gcd(12, 66));
    CPPUNIT_ASSERT_EQUAL(2, joshu::gcd(-2, 4));
    CPPUNIT_ASSERT_EQUAL(4, joshu::gcd(12, -44));
    CPPUNIT_ASSERT_EQUAL(4, joshu::gcd(-444, -44));
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
