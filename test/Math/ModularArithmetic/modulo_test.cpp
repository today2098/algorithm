#include "../../../algorithm/Math/ModularArithmetic/modulo.hpp"

#include <gtest/gtest.h>

#include <format>

#include "../../../algorithm/utils/random.hpp"

namespace {

TEST(InternalModuloTest, Basic) {
    // unsigned integral
    static_assert(algorithm::internal::modulo(5U, 3U) == 2);
    static_assert(algorithm::internal::modulo(5U, 3) == 2);

    // signed integral
    static_assert(algorithm::internal::modulo(5, 3U) == 2);
    static_assert(algorithm::internal::modulo(5, 3) == 2);

    // negative
    static_assert(algorithm::internal::modulo(-5, 3U) == 1);
    static_assert(algorithm::internal::modulo(-5, 3) == 1);
}

TEST(InternalModuloTest, PropertyBased) {
    algorithm::RandomWithMt19937_64 random;

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::uint32_t>(std::numeric_limits<std::uint32_t>::min(), std::numeric_limits<std::uint32_t>::max());
        auto m = random.uniform<std::uint32_t>(1U, std::numeric_limits<std::uint32_t>::max());
        SCOPED_TRACE(std::format("x = {}, m = {}", x, m));
        EXPECT_EQ(x % m, algorithm::internal::modulo(x, m));
    }

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::int32_t>(0, std::numeric_limits<std::int32_t>::max());
        auto m = random.uniform<std::uint32_t>(1U, std::numeric_limits<std::uint32_t>::max());
        SCOPED_TRACE(std::format("x = {}, m = {}", x, m));
        EXPECT_EQ(x % m, algorithm::internal::modulo(x, m));
    }

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::int32_t>(std::numeric_limits<std::int32_t>::min() + 1, -1);
        auto m = random.uniform<std::uint32_t>(1U, std::numeric_limits<std::uint32_t>::max());
        SCOPED_TRACE(std::format("x = {}, m = {}", x, m));
        EXPECT_EQ(m - (-x % m), algorithm::internal::modulo(x, m));
    }

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::uint64_t>(std::numeric_limits<std::uint64_t>::min(), std::numeric_limits<std::uint64_t>::max());
        auto m = random.uniform<std::int32_t>(1, std::numeric_limits<std::int32_t>::max());
        SCOPED_TRACE(std::format("x = {}, m = {}", x, m));
        EXPECT_EQ(x % m, algorithm::internal::modulo(x, m));
    }

    for(int i = 0; i < 100; ++i) {
        auto x = random.uniform<std::int64_t>(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());
        auto m = random.uniform<std::int32_t>(1, std::numeric_limits<std::int32_t>::max());
        SCOPED_TRACE(std::format("x = {}, m = {}", x, m));
        EXPECT_EQ((x % m + m) % m, algorithm::internal::modulo(x, m));
    }
}

}  // namespace
