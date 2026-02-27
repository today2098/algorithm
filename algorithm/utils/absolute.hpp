#ifndef ALGORITHM_ABSOLUTE_HPP
#define ALGORITHM_ABSOLUTE_HPP 1

#include <concepts>
#include <cstdint>

namespace algorithm {

namespace internal {

// Returns the absolute value as type Res.
template <std::unsigned_integral Res, std::unsigned_integral Type>
constexpr Res abs(Type n) {
    static_assert(sizeof(Res) >= sizeof(Type));
    return static_cast<Res>(n);
}

// Returns the absolute value as type Res.
template <std::unsigned_integral Res, std::signed_integral Type>
constexpr Res abs(Type n) {
    static_assert(sizeof(Res) >= sizeof(Type));
    if(n < 0) return static_cast<Res>(-static_cast<std::uintmax_t>(n));
    return static_cast<Res>(n);
}

}  // namespace internal

}  // namespace algorithm

#endif
