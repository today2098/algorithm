#include "../../../algorithm/Math/NumberTheory/greatest_common_divisor.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <format>
#include <limits>
#include <numeric>

#include "../../../algorithm/utils/random.hpp"

namespace {

TEST(GreatestCommonDivisorTest, Basic) {
    static_assert(algorithm::gcd(12, 32) == 4);
    static_assert(algorithm::gcd(32, 12) == 4);
    static_assert(algorithm::gcd(-12, 32) == 4);
    static_assert(algorithm::gcd(12, -32) == 4);
    static_assert(algorithm::gcd(-12, -32) == 4);
    static_assert(algorithm::gcd(12U, -32) == 4U);
    static_assert(algorithm::gcd(12, 32, 52) == 4);
    static_assert(algorithm::gcd(12, 32U, 52LL) == 4ULL);

    static_assert(algorithm::gcd(std::numeric_limits<std::int32_t>::min(), std::numeric_limits<std::int64_t>::min()) == 1LL << 31);
    static_assert(algorithm::gcd(9'223'372'036'854'775'783LL, 2U * 9'223'372'036'854'775'783ULL) == 9'223'372'036'854'775'783ULL);  // 2^63 - 25

    // corner cases
    static_assert(algorithm::gcd(0, 0) == 0);
    static_assert(algorithm::gcd(0, 1) == 1);
    static_assert(algorithm::gcd(1, 0) == 1);

    static_assert(algorithm::gcd(std::numeric_limits<int>::min(), std::numeric_limits<int>::min()) == std::numeric_limits<int>::min());
    static_assert(algorithm::gcd(std::numeric_limits<long long>::min(), std::numeric_limits<long long>::min()) == std::numeric_limits<long long>::min());
}

TEST(GreatestCommonDivisorTest, PropertyBased) {
    algorithm::RandomWithMt19937_64 random;

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::int32_t>(std::numeric_limits<std::int32_t>::min(), std::numeric_limits<std::int32_t>::max());
        auto y = random.uniform<std::int32_t>(std::numeric_limits<std::int32_t>::min(), std::numeric_limits<std::int32_t>::max());
        auto z = random.uniform<std::int64_t>(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());

        SCOPED_TRACE(std::format("x = {}, y = {}, z = {}", x, y, z));

        EXPECT_EQ(std::gcd(x, y), algorithm::gcd(x, y));
        EXPECT_EQ(std::gcd(y, z), algorithm::gcd(y, z));
        EXPECT_EQ(std::gcd(z, x), algorithm::gcd(z, x));
        EXPECT_EQ(std::gcd(std::gcd(x, y), z), algorithm::gcd(x, y, z));
    }
}

}  // namespace
