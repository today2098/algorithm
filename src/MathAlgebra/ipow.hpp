#ifndef ALGORITHM_IPOW_HPP
#define ALGORITHM_IPOW_HPP 1

#include <cassert>

namespace algorithm {

long long ipow(long long n, long long k) {  // 繰返し二乗法．O(logK).
    assert(k >= 0);
    if(k == 0) return 1;
    long long res = ipow(n * n, k >> 1);
    if(k & 1LL) res *= n;
    return res;
}

}  // namespace algorithm

#endif  // ALGORITHM_IPOW_HPP
