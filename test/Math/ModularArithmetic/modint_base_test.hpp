#ifndef ALGORITHM_MODINT_BASE_TEST_HPP
#define ALGORITHM_MODINT_BASE_TEST_HPP 1

#include <gtest/gtest.h>

#include <cstdint>
#include <format>
#include <sstream>
#include <string>

#include "../../../algorithm/Math/ModularArithmetic/mod_inv.hpp"
#include "../../../algorithm/Math/ModularArithmetic/modint_base.hpp"

namespace algorithm {

namespace test {

template <algorithm::modint Type>
void test_modint_base_positive(std::int64_t x, std::int32_t m) {
    assert(m >= 1);
    SCOPED_TRACE(std::format("x = {}, m = {}", x, m));
    ASSERT_EQ(m, Type::modulus());

    Type a(x);
    x = internal::modulo(x, m);
    ASSERT_EQ(x, a.value());

    EXPECT_EQ(x, (+a).value());
    EXPECT_EQ(m - x, (-a).value());

    EXPECT_EQ((x + 1) % m, (++a).value());
    EXPECT_EQ(x, (--a).value());
    EXPECT_EQ(x, (a++).value());
    EXPECT_EQ((x + 1) % m, (a--).value());

    EXPECT_TRUE(a == x);

    std::stringstream ss;
    ss << x;
    ss >> a;
    EXPECT_EQ(x, a.value());

    ss.str("");
    ss.clear();
    ss << a;
    EXPECT_EQ(std::format("{}", x), ss.view());

    EXPECT_EQ(x, Type::raw(x).value());

    EXPECT_EQ(mod_inv(x, m), a.inv().value());
    EXPECT_EQ(mod_pow(x, 63, m), a.pow(63).value());
    EXPECT_EQ(mod_pow(x, 64, m), a.pow(64).value());

    EXPECT_EQ(mod_inv(x, m), mod_inv(a).value());
    EXPECT_EQ(mod_pow(x, 63, m), mod_pow(a, 63).value());
    EXPECT_EQ(mod_pow(x, 64, m), mod_pow(a, 64).value());
}

template <algorithm::modint Type>
void test_modint_base_positive(std::int64_t x, std::int64_t y, std::int32_t m) {
    assert(m >= 1);
    ASSERT_EQ(m, Type::modulus());

    Type a(x);
    Type b = y;
    x = internal::modulo(x, m);
    y = internal::modulo(y, m);
    ASSERT_EQ(x, a.value());
    ASSERT_EQ(y, b.value());

    EXPECT_EQ(x == y, a == b);
    EXPECT_EQ(x != y, a != b);
    EXPECT_EQ((x + y) % m, (a + b).value());
    EXPECT_EQ((x - y + m) % m, (a - b).value());
    EXPECT_EQ((x * y) % m, (a * b).value());
    EXPECT_EQ(x * mod_inv(y, m) % m, (a / b).value());
}

}  // namespace test

}  // namespace algorithm

#endif
