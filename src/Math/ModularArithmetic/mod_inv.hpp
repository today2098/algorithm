/**
 * @brief モジュラ逆数（乗法逆元）
 */

#ifndef ALGORITHM_MOD_INV_HPP
#define ALGORITHM_MOD_INV_HPP 1

#include <cassert>
#include <utility>

namespace algorithm {

// モジュラ逆数（乗法逆元）．
// a^-1 (mod m) を求める．ただし，aとmは互いに素であること．
long long mod_inv(long long a, int m) {
    assert(m >= 2);
    long long b = m, u = 1, v = 0;
    while(b != 0) {
        long long t = a / b;
        a -= b * t, u -= v * t;
        std::swap(a, b), std::swap(u, v);
    }
    // assert(("a and m need to be coprime.", a == 1));
    u %= m;
    if(u < 0) u += m;
    return u;
}

}  // namespace algorithm

#endif
