#ifndef ALGORITHM_IS_PRIME_HPP
#define ALGORITHM_IS_PRIME_HPP 1

namespace algorithm {

bool is_prime(long long n) {  // 素数判定．O(√N).
    if(n < 2LL) return false;
    for(long long p = 2LL; p * p <= n; ++p) {
        if(n % p == 0) return false;
    }
    return true;
}

}  // namespace algorithm

#endif  // ALGORITHM_IS_PRIME_HPP
