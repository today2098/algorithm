#include "../../../algorithm/Math/ModularArithmetic/mod_pow.hpp"

#include <gtest/gtest.h>

namespace {

TEST(ModPowTest, Positive) {
    EXPECT_EQ(1, algorithm::mod_pow(2, 0, 3));
    EXPECT_EQ(2, algorithm::mod_pow(2, 1, 3));
    EXPECT_EQ(1, algorithm::mod_pow(2, 2, 3));
    EXPECT_EQ(2, algorithm::mod_pow(2, 3, 3));
    EXPECT_EQ(1, algorithm::mod_pow(2, 4, 3));

    EXPECT_EQ(4, algorithm::mod_pow(3, 4, 7));
    EXPECT_EQ(5, algorithm::mod_pow(3, -1, 7));
}

TEST(ModPowTest, Negative) {
    EXPECT_DEATH(algorithm::mod_pow(6, -1, 4), "Assertion `g == 1' failed.");
}

}  // namespace
