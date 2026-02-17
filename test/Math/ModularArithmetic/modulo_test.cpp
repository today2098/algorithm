#include "../../../algorithm/Math/ModularArithmetic/modulo.hpp"

#include <gtest/gtest.h>

namespace {

TEST(ModuloTest, Basic) {
    // unsigned integral
    EXPECT_EQ(2, algorithm::internal::modulo(5U, 3U));
    EXPECT_EQ(2, algorithm::internal::modulo(5U, 3));

    // signed integral
    EXPECT_EQ(2, algorithm::internal::modulo(5, 3U));
    EXPECT_EQ(2, algorithm::internal::modulo(5, 3));

    // negative
    EXPECT_EQ(1, algorithm::internal::modulo(-5, 3U));
    EXPECT_EQ(1, algorithm::internal::modulo(-5, 3));
}

}  // namespace
