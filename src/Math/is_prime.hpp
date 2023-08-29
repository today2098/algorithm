/**
 * @brief 素数判定
 */

#ifndef ALGORITHM_IS_PRIME_HPP
#define ALGORITHM_IS_PRIME_HPP 1

#include <cassert>

namespace algorithm {

// 素数判定．O(√N).
template <typename Type>
bool is_prime(Type n) {
    assert(n >= 0);
    if(n < 2) return false;
    for(Type p = 2; p * p <= n; ++p) {
        if(n % p == 0) return false;
    }
    return true;
}

}  // namespace algorithm

#endif
