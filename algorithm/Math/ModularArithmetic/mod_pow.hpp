#ifndef ALGORITHM_MOD_POW_HPP
#define ALGORITHM_MOD_POW_HPP 1

#include <cassert>
#include <concepts>
#include <cstdint>

#include "mod_inv.hpp"
#include "modulo.hpp"

namespace algorithm {

namespace internal {

// Returns n^k mod m.
constexpr std::uint32_t mod_pow(std::uint64_t n, unsigned long long k, std::uint32_t m) {
    std::uint64_t res = 1;
    for(; k > 0; k >>= 1) {
        if(k & 1ULL) res = res * n % m;
        n = n * n % m;
    }
    return res;
}

}  // namespace internal

// 繰り返し二乗法（mod付き）．
// n^k mod m を求める．O(log k).
template <std::integral Type>
constexpr std::int64_t mod_pow(Type n, long long k, std::int32_t m) {
    assert(m >= 1);
    if(k >= 0) return internal::mod_pow(internal::modulo(n, m), k, m);
    auto [x, g] = internal::mod_inv(internal::modulo(n, m), m);
    assert(g == 1);
    return internal::mod_pow(x, -k, m);
}

}  // namespace algorithm

#endif
