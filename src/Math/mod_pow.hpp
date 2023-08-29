#ifndef ALGORITHM_MOD_POW_HPP
#define ALGORITHM_MOD_POW_HPP 1

#include <cassert>
#include <numeric>
#include <utility>

namespace algorithm {

// 繰返し二乗法（mod付き）．n^k (mod m)を求める．O(logK).
long long mod_pow(long long n, long long k, int m) {
    assert(k >= 0 and m >= 1);
    n %= m;
    long long res = 1;
    while(k > 0) {
        if(k & 1LL) res = res * n % m;
        n = n * n % m;
        k >>= 1;
    }
    return res;
}

// 逆元．a^-1 (mod m)を求める．ただし，aとmは互いに素であること．
long long mod_inv(long long a, int m) {
    assert(m >= 1 and std::gcd(a, m) == 1);
    long long b = m, u = 1, v = 0;
    while(b) {
        long long t = a / b;
        a -= t * b, u -= t * v;
        std::swap(a, b), std::swap(u, v);
    }
    return (u % m + m) % m;
}

}  // namespace algorithm

#endif
