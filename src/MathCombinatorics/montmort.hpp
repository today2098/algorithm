#ifndef ALGORITHM_MONTMORT_HPP
#define ALGORTIHM_MONTMORT_HPP 1

#include <cassert>
#include <cmath>  // for exp().
#include <vector>

namespace algorithm {

// 完全順列（mod付き）．
template <int mod>
class Montmort {
    int sz;
    std::vector<long long> a;  // a[k]:=(k番目のモンモール数).

public:
    Montmort() : Montmort(51e4) {}
    explicit Montmort(size_t sz_) : sz(sz_), a(sz_) {
        static_assert(mod >= 1);
        assert(sz >= 2);
        a[0] = 1, a[1] = 0;
        for(int i = 2; i <= sz; ++i) a[i] = (i - 1) * ((a[i - 2] + a[i - 1]) % mod) % mod;  // 隣接三項間の漸化式．
        // for(int i = 2; i <= sz; ++i) a[i] = (i * a[i - 1] % mod + (i & 1 ? -1 : 1) + mod) % mod;  // 隣接二項間の漸化式．
    }

    int modulus() const { return mod; }
    int montmort(int k) const {
        assert(1 <= k and k < sz);
        return a[k];
    }
    double convergence_probability() const { return 1.0 / std::exp(1.0); }
};

}  // namespace algorithm

#endif  // ALGORITHM_MONTMORT_HPP
