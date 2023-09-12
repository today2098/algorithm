/**
 * @brief オイラーのファイ関数
 * @docs docs/Math/NumberTheory/totient.md
 */

#ifndef ALGORITHM_TOTIENT_HPP
#define ALGORITHM_TOTIENT_HPP 1

#include <cassert>

namespace algorithm {

// オイラーのファイ関数．
// n以下でnと互いに素な自然数の個数を求める．O(√N).
template <typename Type>
Type totient(Type n) {
    assert(n >= 1);
    Type res = n;
    for(Type p = 2; p * p <= n; ++p) {
        if(n % p == 0) {
            res -= res / p;
            while(n % p == 0) n /= p;
        }
    }
    if(n > 1) res -= res / n;
    return res;
}

};  // namespace algorithm

#endif
