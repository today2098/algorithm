/**
 * @brief 素因数分解
 */

#ifndef ALGORITHM_PRIME_FACTORIZATION_HPP
#define ALGORITHM_PRIME_FACTORIZATION_HPP 1

#include <cassert>
#include <map>

namespace algorithm {

// 素因数分解．O(√N).
template <typename Type>
std::map<Type, int> prime_factorization(Type n) {
    assert(n >= 2);
    std::map<Type, int> res;  // res[p]:=(自然数nに含まれる素因数pの個数).
    for(Type p = 2; p * p <= n; ++p) {
        if(n % p != 0) continue;
        while(n % p == 0) res[p]++, n /= p;
    }
    if(n != 1) res[n]++;
    return res;
}

}  // namespace algorithm

#endif
