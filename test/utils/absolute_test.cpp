// competitive-verifier: UNITTEST GTEST_RESULT
#include "../../algorithm/utils/absolute.hpp"

#include <gtest/gtest.h>

#include <cstdint>
#include <limits>

namespace {

TEST(AbsoluteTest, Basic) {
    static_assert(algorithm::internal::abs<std::uint8_t>(std::numeric_limits<std::int8_t>::min()) == 1U << 7);
    static_assert(algorithm::internal::abs<std::uint16_t>(std::numeric_limits<std::int16_t>::min()) == 1U << 15);
    static_assert(algorithm::internal::abs<std::uint32_t>(std::numeric_limits<std::int32_t>::min()) == 1U << 31);
    static_assert(algorithm::internal::abs<std::uint64_t>(std::numeric_limits<std::int64_t>::min()) == 1ULL << 63);

    static_assert(algorithm::internal::abs<std::uint32_t>(std::numeric_limits<std::int8_t>::min()) == 1U << 7);
    static_assert(algorithm::internal::abs<std::uint32_t>(std::numeric_limits<std::int16_t>::min()) == 1U << 15);
    static_assert(algorithm::internal::abs<std::uint64_t>(std::numeric_limits<std::int32_t>::min()) == 1ULL << 31);
}

}  // namespace
