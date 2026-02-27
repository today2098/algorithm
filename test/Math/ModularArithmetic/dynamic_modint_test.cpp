#include "../../../algorithm/Math/ModularArithmetic/dynamic_modint.hpp"

#include <gtest/gtest.h>

#include "../../../algorithm/utils/random.hpp"
#include "modint_base_test.hpp"

namespace {

TEST(DynamicModintTest, Basic) {
    constexpr std::int32_t MOD = 1'000'000'007;
    using mint = algorithm::DynamicModint<0>;
    mint::set_modulus(MOD);

    algorithm::RandomWithMt19937_64 random;
    for(int i = 0; i < 1000; ++i) {
        auto x = random.uniform<std::int64_t>(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());
        auto y = random.uniform<std::int64_t>(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());

        algorithm::test::test_modint_base_positive<mint>(x, MOD);
        algorithm::test::test_modint_base_positive<mint>(y, MOD);
        algorithm::test::test_modint_base_positive<mint>(x, y, MOD);
    }
}

}  // namespace
