#include "../../../algorithm/Math/ModularArithmetic/mod_inv.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <format>
#include <limits>
#include <numeric>

#include "../../../algorithm/utils/random.hpp"

namespace {

TEST(InternalModInvTest, Basic) {
    {
        static_assert(2 * 1 % 4 == 2 % 4);
        constexpr auto p = algorithm::internal::mod_inv(2, 4);
        static_assert(p.first == 1);
        static_assert(p.second == 2);
    }

    {
        static_assert(24 * 11 % 256 == 8 % 256);
        constexpr auto p = algorithm::internal::mod_inv(24, 256);
        static_assert(p.first == 11);
        static_assert(p.second == 8);
    }

    {
        static_assert(27 * 2 % 45 == 9 % 45);
        constexpr auto p = algorithm::internal::mod_inv(27, 45);
        static_assert(p.first == 2);
        static_assert(p.second == 9);
    }

    {  // corner case: a = 0
        static_assert(0 * 0 % 3 == 3 % 3);
        constexpr auto p = algorithm::internal::mod_inv(0, 3);
        static_assert(p.first == 0);
        static_assert(p.second == 3);
    }
}

TEST(InternalModInvTest, PropertyBased) {
    algorithm::RandomWithMt19937 random;

    for(int i = 0; i < 1000; ++i) {
        auto a = random.uniform<std::uint32_t>(std::numeric_limits<std::uint32_t>::min(), std::numeric_limits<std::uint32_t>::max() - 1);
        auto m = random.uniform<std::uint32_t>(a + 1, std::numeric_limits<std::uint32_t>::max());

        auto [x, g] = algorithm::internal::mod_inv(a, m);

        SCOPED_TRACE(std::format("a = {}, m = {}, x = {}, g = {}", a, m, x, g));

        EXPECT_EQ(std::gcd(a, m), g);
        EXPECT_EQ((std::uint64_t)a * x % m, g);
        EXPECT_TRUE(x < m / g);
    }
}

TEST(ModInvTest, Positive) {
    static_assert(2 * 3 % 5 == 1);
    static_assert(algorithm::mod_inv(3, 5) == 2);

    static_assert(89 * 89 % 144 == 1);
    static_assert(algorithm::mod_inv(89, 144) == 89);

    static_assert(34 * 144 % 89 == 1);
    static_assert(algorithm::mod_inv(144, 89) == 34);
}

TEST(ModInvTest, Negative) {
    // Invalid modulus.
    EXPECT_DEATH(algorithm::mod_inv(1, 0), "Assertion `m >= 1' failed.");
    EXPECT_DEATH(algorithm::mod_inv(1, -2), "Assertion `m >= 1' failed.");

    // Not coprime.
    EXPECT_DEATH(algorithm::mod_inv(12, 64), "Assertion `g == 1' failed.");
}

}  // namespace
