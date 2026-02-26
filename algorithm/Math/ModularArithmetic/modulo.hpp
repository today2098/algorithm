#ifndef ALGORITHM_MODULO_HPP
#define ALGORITHM_MODULO_HPP 1

#include <concepts>
#include <cstdint>

namespace algorithm {

namespace internal {

// Return x mod m.
template <std::unsigned_integral Type>
constexpr std::uint32_t modulo(Type x, std::uint32_t m) { return x % m; }

// Return x mod m.
template <std::unsigned_integral Type>
constexpr std::uint32_t modulo(Type x, std::int32_t m) { return x % static_cast<std::uint32_t>(m); }

// Return x mod m.
template <std::signed_integral Type>
constexpr std::uint32_t modulo(Type x, std::uint32_t m) {
    x %= static_cast<std::int64_t>(m);
    if(x < 0) x += static_cast<std::int64_t>(m);
    return x;
}

// Return x mod m.
template <std::signed_integral Type>
constexpr std::uint32_t modulo(Type x, std::int32_t m) {
    x %= m;
    if(x < 0) x += m;
    return x;
}

}  // namespace internal

}  // namespace algorithm

#endif
