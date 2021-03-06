#ifndef ALGORITHM_COMBINATION_HPP
#define ALGORITHM_COMBINATION_HPP 1

#include <cassert>
#include <vector>

namespace algorithm {

// 二項係数（mod付き）．
template <int mod>
class Combination {
    int sz;                                  // sz:=(要素数). ただし，sz<mod．
    std::vector<long long> fact, inv, finv;  // fact[n]:=(nの階乗), inv[n]:=(nの逆元), finv[n]:=(nの階乗の逆元).

    void build() {
        fact[0] = fact[1] = 1;
        inv[1] = 1;
        finv[0] = finv[1] = 1;
        for(int a = 2; a < sz; ++a) {
            fact[a] = fact[a - 1] * a % mod;
            inv[a] = mod - inv[mod % a] * (mod / a) % mod;
            finv[a] = finv[a - 1] * inv[a] % mod;
        }
    }

public:
    // constructor. O(N).
    Combination() : Combination(51e4) {}
    explicit Combination(size_t sz_) : sz(sz_), fact(sz_), inv(sz_), finv(sz_) {
        static_assert(mod >= 1);
        assert(2 <= sz and sz < mod);
        build();
    }

    int modulus() const { return mod; }
    long long factorial(int n) const {  // 階乗.
        assert(0 <= n and n < sz);
        return fact[n];
    }
    long long inverse(int n) const {  // 逆元.
        assert(1 <= n and n < sz);
        return inv[n];
    }
    long long inverse_fact(int n) const {  // 階乗の逆元.
        assert(0 <= n and n < sz);
        return finv[n];
    }
    long long nPk(int n, int k) const {  // 順列．
        assert(0 <= k and k <= n and n < sz);
        return fact[n] * finv[n - k] % mod;
    }
    long long nCk(int n, int k) const {  // 組み合わせ．
        assert(0 <= k and k <= n and n < sz);
        return fact[n] * finv[n - k] % mod * finv[k] % mod;
    }
    long long nHk(int n, int k) const { return nCk(k + n - 1, n - 1); }  // 重複組み合わせ．
};

using Combination998244353 = Combination<998'244'353>;
using Combination1000000007 = Combination<1'000'000'007>;

}  // namespace algorithm

#endif  // ALGORITHM_COMBINATION_HPP
