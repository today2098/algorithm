#ifndef ALGORITHM_FLOOR_SUM_HPP
#define ALGORITHM_FLOOR_SUM_HPP 1

#include <cassert>

namespace algorithm {

// sum_{x=0}^{n-1} floor((a*x+b)/m)を求める．O(log(n+m+a+b)).
long long floor_sum(long long n, long long m, long long a, long long b) {
    assert(0LL <= n);
    assert(1LL <= m);
    long long res = 0;
    if(a < 0LL) {
        long long a2 = (a % m + m) % m;
        res -= n * (n - 1) / 2 * ((a2 - a) / m);
        a = a2;
    }
    if(b < 0LL) {
        long long b2 = (b % m + m) % m;
        res -= n * ((b2 - b) / m);
        b = b2;
    }
    if(a >= m) {
        res += n * (n - 1) / 2 * (a / m);
        a %= m;
    }
    if(b >= m) {
        res += n * (b / m);
        b %= m;
    }
    long long y_mx = a * n + b;
    if(y_mx >= m) res += floor_sum(y_mx / m, a, m, y_mx % m);
    return res;
}

}  // namespace algorithm

#endif  // ALGORITHM_FLOOR_SUM_HPP
