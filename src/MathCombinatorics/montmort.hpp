#ifndef ALGORITHM_MONTMORT_HPP
#define ALGORTIHM_MONTMORT_HPP 1

#include <cassert>
#include <cmath>
#include <vector>

namespace algorithm {

// 完全順列（mod付き）．
template <int mod>
class Montmort {
    int m_sz;
    std::vector<long long> m_montmort;  // m_montmort[k]:=(k番目のモンモール数).

public:
    Montmort() : Montmort(51e4) {}
    explicit Montmort(size_t sz) : m_sz(sz), m_montmort(sz) {
        static_assert(mod >= 1);
        assert(m_sz >= 2);
        m_montmort[0] = 1, m_montmort[1] = 0;
        for(int i = 2; i < m_sz; ++i) m_montmort[i] = (i - 1) * ((m_montmort[i - 2] + m_montmort[i - 1]) % mod) % mod;  // 隣接三項間の漸化式．
        // for(int i = 2; i < m_sz; ++i) m_montmort[i] = (i * m_montmort[i - 1] % mod + (i & 1 ? -1 : 1) + mod) % mod;  // 隣接二項間の漸化式．
    }

    static constexpr int modulus() { return mod; }
    // k個の要素を並び替えたときに完全順列となる通り数．
    long long montmort(int k) const {
        assert(1 <= k and k < m_sz);
        return m_montmort[k];
    }
    // 無限個の要素を並び替えたときに完全順列となる確率．
    static constexpr double converged_probability() { return 1.0 / std::exp(1.0); }
};

}  // namespace algorithm

#endif
