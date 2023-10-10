#ifndef ALGORITHM_CHINESE_REMAINDER_THEOREM_HPP
#define ALGORITHM_CHINESE_REMAINDER_THEOREM_HPP 1

/**
 * @brief Chinese Remainder Theorem（中国剰余定理）
 * @docs docs/Math/NumberTheory/chinese_remainder_theorem.md
 */

#include <cassert>
#include <vector>

#include "extgcd.hpp"

namespace algorithm {

// Chinese Remainder Theorem（中国剰余定理）.
// x≡b1 (mod m1) かつ x≡b2 (mod m2) を満たす整数x (0≦x＜lcm(m1,m2)) を求める．
// 解xが存在する必要十分条件は b1≡b2 (mod gcd(m1,m2)) であること．
// 返り値はpair of (x, lcm(m1,m2))．解なしの場合，(0,-1)を返す．
std::pair<long long, long long> crt(long long b1, long long m1, long long b2, long long m2) {
    long long p, q;
    long long d = extgcd(m1, m2, p, q);     // p is inverse of m1/d (mod m2/d).
    if((b2 - b1) % d != 0) return {0, -1};  // 解なし．
    long long m = m1 / d * m2;              // lcm(m1,m2).
    long long tmp = (b2 - b1) / d * p % (m2 / d);
    long long r = (b1 + m1 * tmp) % m;
    if(r < 0) r += m;
    return {r, m};
}

// Chinese Remainder Theorem（中国剰余定理）.
// 各iについて，x≡b[i] (mod m[i]) を満たす整数x (0≦x＜lcm(m[0],m[1],...,m[N-1])) を求める．
// 返り値はpair of (x, lcm(m[0],m[1],...,m[N-1]))．解なしの場合，(0,-1)を返す．
template <typename Type>
std::pair<long long, long long> crt(const std::vector<Type> &bs, const std::vector<Type> &ms) {
    assert(bs.size() == ms.size());
    long long r = 0, m = 1;
    for(int i = 0, n = bs.size(); i < n; ++i) {
        const auto &&[nr, nm] = crt(r, m, bs[i], ms[i]);
        if(nr == 0 and nm == -1) return {0, -1};  // 解なし．
        r = nr, m = nm;
    }
    return {r, m};
}

}  // namespace algorithm

#endif
