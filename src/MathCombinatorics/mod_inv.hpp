#ifndef ALGORITHM_MOD_INV_HPP
#define ALGORITHM_MOD_INV_HPP 1

#include <cassert>
#include <utility>  // for swap().

namespace algorithm {

long long mod_inv(long long a, int m) {  // 逆元．a^-1 (mod m)を求める（ただし，aとmは互いに素）．O(logA).
    assert(m >= 1);
    long long b = m, u = 1, v = 0;
    while(b) {
        long long t = a / b;
        a -= t * b, u -= t * v;
        std::swap(a, b), std::swap(u, v);
    }
    return u = (u % m + m) % m;
}

}  // namespace algorithm

#endif  // ALGORITHM_MOD_INV_HPP
