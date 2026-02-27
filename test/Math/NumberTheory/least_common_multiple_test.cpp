#include "../../../algorithm/Math/NumberTheory/least_common_multiple.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <format>
#include <numeric>

#include "../../../algorithm/utils/random.hpp"

namespace {

TEST(LeastCommonMultipleTest, PropertyBased) {
    algorithm::RandomWithMt19937_64 random;

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::int64_t>(-(1 << 20), 1 << 20);
        auto y = random.uniform<std::int64_t>(-(1 << 20), 1 << 20);
        auto z = random.uniform<std::int64_t>(-(1 << 20), 1 << 20);

        SCOPED_TRACE(std::format("x = {}, y = {}, z = {}", x, y, z));

        EXPECT_EQ(std::lcm(x, y), algorithm::lcm(x, y));
        EXPECT_EQ(std::lcm(y, z), algorithm::lcm(y, z));
        EXPECT_EQ(std::lcm(z, x), algorithm::lcm(z, x));
        EXPECT_EQ(std::lcm(std::lcm(x, y), z), algorithm::lcm(x, y, z));
    }
}

}  // namespace
