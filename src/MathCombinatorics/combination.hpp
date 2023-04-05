#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 二項係数（mod付き）．
template <int mod>
class Combination {
    int m_sz;                       // m_sz:=(要素数). 制約は m_sz<=mod．
    std::vector<long long> m_fact;  // m_fact[n]:=(nの階乗).
    std::vector<long long> m_inv;   // m_inv[n]:=(nの逆元).
    std::vector<long long> m_finv;  // m_finv[n]:=(nの階乗の逆元).

public:
    // constructor. O(N).
    Combination() : Combination(51e4) {}
    explicit Combination(size_t sz) : m_sz(sz), m_fact(sz), m_inv(sz), m_finv(sz) {
        static_assert(mod >= 1);
        assert(2 <= m_sz and m_sz <= mod);
        m_fact[0] = m_fact[1] = 1;
        m_inv[1] = 1;
        m_finv[0] = m_finv[1] = 1;
        for(int n = 2; n < m_sz; ++n) {
            m_fact[n] = m_fact[n - 1] * n % mod;
            m_inv[n] = mod - m_inv[mod % n] * (mod / n) % mod;
            m_finv[n] = m_finv[n - 1] * m_inv[n] % mod;
        }
    }

    static constexpr int modulus() { return mod; }
    // 階乗．
    long long factorial(int n) const {
        assert(0 <= n and n < m_sz);
        return m_fact[n];
    }
    // 逆元．
    long long inverse(int n) const {
        assert(1 <= n and n < m_sz);
        return m_inv[n];
    }
    // 階乗の逆元．
    long long inverse_fact(int n) const {
        assert(0 <= n and n < m_sz);
        return m_finv[n];
    }
    // 順列．
    long long nPk(int n, int k) const {
        assert(0 <= k and k <= n and n < m_sz);
        return m_fact[n] * m_finv[n - k] % mod;
    }
    // 組合せ．
    long long nCk(int n, int k) const {
        assert(0 <= k and k <= n and n < m_sz);
        return m_fact[n] * m_finv[n - k] % mod * m_finv[k] % mod;
    }
    // 重複組合せ．
    long long nHk(int n, int k) const { return nCk(k + n - 1, n - 1); }
};

using Combination998244353 = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

// 順列．
inline long long nPk(long long n, int k) {
    assert(0 <= k and k <= n);
    long long res = 1;
    for(int i = 0; i < k; ++i) res = res * (n - i);
    return res;
}

// 組合せ．
inline long long nCk(long long n, int k) {
    assert(0 <= k and k <= n);
    long long res = 1;
    for(int i = 0; i < k; ++i) res = res * (n - i) / (i + 1);
    return res;
}

// 重複組合せ．
inline long long nHk(int n, long long k) { return nCk(k + n - 1, n - 1); }

}  // namespace algorithm

#endif
