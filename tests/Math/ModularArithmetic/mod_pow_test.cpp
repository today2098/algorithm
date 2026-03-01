// competitive-verifier: UNITTEST GTEST_RESULT
#include "../../../algorithm/Math/ModularArithmetic/mod_pow.hpp"

#include <gtest/gtest.h>

namespace {

TEST(ModPowTest, Positive) {
    static_assert(algorithm::mod_pow(2, 0, 3) == 1);
    static_assert(algorithm::mod_pow(2, 1, 3) == 2);
    static_assert(algorithm::mod_pow(2, 2, 3) == 1);
    static_assert(algorithm::mod_pow(2, 3, 3) == 2);
    static_assert(algorithm::mod_pow(2, 4, 3) == 1);
    static_assert(algorithm::mod_pow(2, 5, 3) == 2);

    static_assert(algorithm::mod_pow(3, -2, 4) == 1);  // 3^(-2) mod 4 = 1 because 3^2 * 1 mod 4 = 1.
    static_assert(algorithm::mod_pow(3, -1, 4) == 3);  // 3^(-1) mod 4 = 3 because 3 * 3 mod 4 = 1.
    static_assert(algorithm::mod_pow(3, 0, 4) == 1);
    static_assert(algorithm::mod_pow(3, 1, 4) == 3);
    static_assert(algorithm::mod_pow(3, 2, 4) == 1);
    static_assert(algorithm::mod_pow(3, 3, 4) == 3);

    static_assert(algorithm::mod_pow(7, -2, 4) == 1);  // 7^(-2) mod 4 = 1 because 7^2 * 1 mod 4 = 1.
    static_assert(algorithm::mod_pow(7, -1, 4) == 3);  // 7^(-1) mod 4 = 3 because 7 * 3 mod 4 = 1.
    static_assert(algorithm::mod_pow(7, 0, 4) == 1);
    static_assert(algorithm::mod_pow(7, 1, 4) == 3);
    static_assert(algorithm::mod_pow(7, 2, 4) == 1);
    static_assert(algorithm::mod_pow(7, 3, 4) == 3);

    static_assert(algorithm::mod_pow(3, -8, 7) == 4);  // 3^(-8) mod 7 = 4 because 3^8 * 4 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -7, 7) == 5);  // 3^(-7) mod 7 = 5 because 3^7 * 5 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -6, 7) == 1);  // 3^(-6) mod 7 = 1 because 3^6 * 1 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -5, 7) == 3);  // 3^(-5) mod 7 = 3 because 3^5 * 3 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -4, 7) == 2);  // 3^(-4) mod 7 = 2 because 3^4 * 2 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -3, 7) == 6);  // 3^(-3) mod 7 = 6 because 3^3 * 6 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -2, 7) == 4);  // 3^(-2) mod 7 = 4 because 3^2 * 4 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, -1, 7) == 5);  // 3^(-1) mod 7 = 5 because 3 * 5 mod 7 = 1.
    static_assert(algorithm::mod_pow(3, 0, 7) == 1);
    static_assert(algorithm::mod_pow(3, 1, 7) == 3);
    static_assert(algorithm::mod_pow(3, 2, 7) == 2);
    static_assert(algorithm::mod_pow(3, 3, 7) == 6);
    static_assert(algorithm::mod_pow(3, 4, 7) == 4);
    static_assert(algorithm::mod_pow(3, 5, 7) == 5);
    static_assert(algorithm::mod_pow(3, 6, 7) == 1);
    static_assert(algorithm::mod_pow(3, 7, 7) == 3);
}

TEST(ModPowTest, Negative) {
    // Invalid modulus.
    EXPECT_DEATH(algorithm::mod_pow(1, 1, 0), "Assertion `m >= 1' failed.");
    EXPECT_DEATH(algorithm::mod_pow(1, 1, -2), "Assertion `m >= 1' failed.");

    // Not coprime.
    EXPECT_DEATH(algorithm::mod_pow(6, -1, 4), "Assertion `g == 1' failed.");
}

}  // namespace
