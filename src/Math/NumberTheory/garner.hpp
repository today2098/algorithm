#ifndef ALGORITHM_GARNER_HPP
#define ALGORITHM_GARNER_HPP 1

/**
 * @brief Garner's Algorithm（中国剰余定理）
 * @docs docs/Math/NumberTheory/garner.md
 */

#include <cassert>
#include <vector>

#include "../ModularArithmetic/mod_inv.hpp"

namespace algorithm {

// 各iについて x≡b[i] (mod m[i]) を満たす最小の非負整数x (0≦x＜m[0]m[1]...m[N-1]) を求める．
// ただし，以下の制約を満たすこと．
//   - 任意のiについて，0≦b[i]<m[i].
//   - 任意のi,j (i≠j) について，gcd(m[i],m[j])=1.
long long garner(const std::vector<int> &bs, const std::vector<int> &ms) {
    assert(bs.size() == ms.size());
    long long x = 0;
    long long m_prod = 1;
    for(int i = 0, n = bs.size(); i < n; ++i) {
        long long t = (bs[i] - x) * mod_inv(m_prod, ms[i]) % ms[i];
        if(t < 0) t += ms[i];
        x += m_prod * t;
        m_prod *= ms[i];
    }
    return x;
}

// 各iについて x≡b[i] (mod m[i]) を満たす最小の非負整数x (0≦x＜m[0]m[1]...m[N-1]) を求め，ある整数Mに対して x mod M を返す．
// ただし，以下の制約を満たすこと．
//   - 任意のiについて，0≦b[i]<m[i].
//   - 任意のi,j (i≠j) について，gcd(m[i],m[j])=1.
int garner(const std::vector<int> &bs, const std::vector<int> &ms, int mod) {
    assert(bs.size() == ms.size());
    const int n = bs.size();
    std::vector<long long> coeffs(n, 1);     // coeffs[k]:=m[0]m[1]...m[k-1].
    std::vector<long long> constants(n, 0);  // constants[k]:=t[0]+t[1]m[0]+...+t[k-1]m[0]m[1]...m[k-2].
    long long x = 0;
    long long m_prod = 1;
    for(int i = 0; i < n; ++i) {
        long long t = (bs[i] - constants[i]) * mod_inv(coeffs[i], ms[i]) % ms[i];
        if(t < 0) t += ms[i];
        for(int j = i + 1; j < n; ++j) {
            constants[j] = (constants[j] + coeffs[j] * t) % ms[j];
            coeffs[j] = coeffs[j] * ms[i] % ms[j];
        }
        x = (x + m_prod * t) % mod;
        m_prod = m_prod * ms[i] % mod;
    }
    return x;
}

}  // namespace algorithm

#endif
