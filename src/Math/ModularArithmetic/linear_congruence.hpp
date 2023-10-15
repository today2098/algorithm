#ifndef ALGORITHM_LINEAR_CONGRUENCE_HPP
#define ALGORITHM_LINEAR_CONGRUENCE_HPP 1

/**
 * @brief 一次合同式 ax≡c (mod m)
 * @docs docs/Math/ModularArithmetic/linear_congruence.md
 */

#include <cassert>
#include <vector>

#include "../NumberTheory/extgcd.hpp"

namespace algorithm {

// 一次合同式 ax≡c (mod m) の解をすべて求める．
std::vector<int> linear_congruence(long long a, long long c, int m) {
    assert(m >= 1);
    int u, v;
    int g = extgcd<int>(a % m, m, u, v);       // g is gcd(a,m).
    if(c % g != 0) return std::vector<int>();  // 解なし．
    std::vector<int> res(g);
    if(u < 0) u += m;  // 0≦u<m.
    res[0] = c / g % m * u % m;
    int dm = m / g;
    for(int i = 1; i < g; ++i) {
        long long tmp = (long long)res[i - 1] + dm;
        if(tmp >= m) tmp -= m;
        res[i] = tmp;
    }
    return res;
}

}  // namespace algorithm

#endif
