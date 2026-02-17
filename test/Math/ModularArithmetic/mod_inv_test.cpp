#include "../../../algorithm/Math/ModularArithmetic/mod_inv.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <numeric>
#include <utility>
#include <vector>

namespace {

TEST(InternalModInvTest, Baisc) {
    std::vector<std::pair<std::uint32_t, std::uint32_t>> args({{2, 4},
                                                               {24, 256},
                                                               {27, 45}});

    for(const auto &[a, m] : args) {
        std::stringstream ss;
        ss << "a = " << a << ", m = " << m;
        SCOPED_TRACE(ss.str());

        auto [x, g] = algorithm::internal::mod_inv(a, m);

        EXPECT_EQ(std::gcd(a, m), g);
        EXPECT_EQ(a * x % m, g);
        EXPECT_TRUE(0 <= x and x < m / g);
    }
}

TEST(ModInvTest, Positive) {
    static_assert(2 * 3 % 5 == 1);
    EXPECT_EQ(2, algorithm::mod_inv(3, 5));

    static_assert(89 * 89 % 144 == 1);
    EXPECT_EQ(89, algorithm::mod_inv(89, 144));

    static_assert(34 * 144 % 89 == 1);
    EXPECT_EQ(34, algorithm::mod_inv(144, 89));
}

TEST(ModInvTest, Negative) {
    EXPECT_DEATH(algorithm::mod_inv(12, 64), "Assertion `g == 1' failed.");
}

}  // namespace
