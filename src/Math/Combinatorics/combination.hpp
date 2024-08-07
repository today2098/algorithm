#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

/**
 * @brief 順列，組合せ，重複組合せ
 * @docs docs/Math/Combinatorics/combination.md
 */

#include <cassert>

namespace algorithm {

// 順列．O(K).
long long nPk(long long n, int k) {
    assert(0 <= k and k <= n);
    long long res = 1;
    for(int i = 0; i < k; ++i) res = res * (n - i);
    return res;
}

// 組合せ．O(K).
long long nCk(long long n, int k) {
    assert(0 <= k and k <= n);
    long long res = 1;
    for(int i = 0; i < k; ++i) res = res * (n - i) / (i + 1);
    return res;
}

// 重複組合せ．O(N).
long long nHk(int n, long long k) { return nCk(k + n - 1, n - 1); }

}  // namespace algorithm

#endif
