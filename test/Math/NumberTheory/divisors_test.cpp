#include "../../../algorithm/Math/NumberTheory/divisors.hpp"

#include <gtest/gtest.h>

#include <vector>

namespace {

TEST(DivisorsTest, Basic) {
    static_assert(algorithm::divisors(1) == std::vector({1}));
    static_assert(algorithm::divisors(2) == std::vector({1, 2}));
    static_assert(algorithm::divisors(3) == std::vector({1, 3}));
    static_assert(algorithm::divisors(4) == std::vector({1, 2, 4}));
    static_assert(algorithm::divisors(5) == std::vector({1, 5}));
    static_assert(algorithm::divisors(6) == std::vector({1, 2, 3, 6}));
    static_assert(algorithm::divisors(7) == std::vector({1, 7}));
    static_assert(algorithm::divisors(8) == std::vector({1, 2, 4, 8}));
    static_assert(algorithm::divisors(9) == std::vector({1, 3, 9}));
    static_assert(algorithm::divisors(10) == std::vector({1, 2, 5, 10}));
}

}  // namespace
