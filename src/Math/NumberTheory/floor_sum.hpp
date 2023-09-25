#ifndef ALGORITHM_FLOOR_SUM_HPP
#define ALGORITHM_FLOOR_SUM_HPP 1

/**
 * @brief Floor Sum
 * @docs docs/Math/NumberTheory/floor_sum.md
 */

#include <cassert>

namespace algorithm {

// sum_{x=0}^{n-1} floor((a*x+b)/m) を求める．O(log m).
long long floor_sum(long long n, long long m, long long a, long long b) {
    assert(0 <= n and n < 1LL << 32);
    assert(1 <= m and m < 1LL << 32);
    long long res = 0;
    if(a >= m) {
        res += a / m * (n * (n - 1) / 2);
        a %= m;
    } else if(a < 0) {
        long long na = (a % m + m) % m;
        res -= (na - a) / m * (n * (n - 1) / 2);
        a = na;
    }
    if(b >= m) {
        res += b / m * n;
        b %= m;
    } else if(b < 0) {
        long long nb = (b % m + m) % m;
        res -= (nb - b) / m * n;
        b = nb;
    }
    long long y_max = a * n + b;
    if(y_max >= m) res += floor_sum(y_max / m, a, m, y_max % m);
    return res;
}

}  // namespace algorithm

#endif
