#include "../../../algorithm/Math/NumberTheory/is_prime.hpp"

#include <gtest/gtest.h>

namespace {

TEST(IsPrimeTest, Basic) {
    static_assert(algorithm::is_prime(0) == false);
    static_assert(algorithm::is_prime(1) == false);
    static_assert(algorithm::is_prime(2) == true);
    static_assert(algorithm::is_prime(3) == true);
    static_assert(algorithm::is_prime(4) == false);
    static_assert(algorithm::is_prime(5) == true);
    static_assert(algorithm::is_prime(6) == false);
    static_assert(algorithm::is_prime(7) == true);
    static_assert(algorithm::is_prime(8) == false);
    static_assert(algorithm::is_prime(9) == false);
    static_assert(algorithm::is_prime(10) == false);
}

}  // namespace
