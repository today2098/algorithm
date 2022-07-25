#ifndef ALGORITHM_SIEVE_HPP
#define ALGORITHM_SIEVE_HPP 1

#include <algorithm>  // for sort().
#include <cassert>
#include <map>
#include <vector>

namespace algorithm {

// エラトステネスの篩．
class Sieve {
    int m_mx;                // m_mx:=(篩にかける最大の自然数).
    std::vector<int> m_lpf;  // m_lpf[n]:=(自然数nの最小の素因数). Least prime factor. m_lpf[n]=nのとき，nは素数．

    int internal_pow(int n, unsigned int k) const {
        if(k == 0) return 1;
        auto &&res = internal_pow(n * n, k >> 1);
        if(k & 1U) res *= n;
        return res;
    }

public:
    // constructor.
    Sieve() : Sieve(51e4) {}
    explicit Sieve(int n) : m_mx(n), m_lpf(n + 1, -1) {  // n以下の自然数を篩にかける．O(N*loglogN).
        assert(n >= 0);
        for(int p = 2; p <= m_mx; ++p) m_lpf[p] = p;
        for(int p = 2; p * p <= m_mx; ++p) {
            if(m_lpf[p] == p) {
                for(int m = p * p; m <= m_mx; m += p) {
                    if(m_lpf[m] == m) m_lpf[m] = p;
                }
            }
        }
    }

    bool is_prime(int n) const {  // 素数判定．O(1).
        assert(0 <= n and n <= m_mx);
        return m_lpf[n] == n;
    }
    int get_lpf(int n) const {  // 自然数nの最小の素因数を返す．O(1).
        assert(0 <= n and n <= m_mx);
        return m_lpf[n];
    }
    std::map<int, int> prime_factorize(int n) const {  // 高速素因数分解．O(logN).
        assert(1 <= n and n <= m_mx);
        std::map<int, int> res;
        while(n > 1) {
            res[m_lpf[n]]++;
            n /= m_lpf[n];
        }
        return res;
    }
    std::vector<int> divisors(int n) const {  // 高速約数列挙．
        assert(1 <= n and n <= m_mx);
        std::vector<int> res({1});
        const auto &&pf = prime_factorize(n);
        for(const auto &[p, cnt] : pf) {
            const int sz = res.size();
            int v = 1;
            for(int i = 0; i < cnt; ++i) {
                v *= p;
                for(int j = 0; j < sz; ++j) res.push_back(res[i] * v);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
    int totient(int n) const {  // オイラーのファイ関数．n以下でnと互いに素な自然数の個数．
        assert(1 <= n and n <= m_mx);
        const auto &&pf = prime_factorize(n);
        int res = 1;
        for(const auto &[p, cnt] : pf) res *= internal_pow(p, cnt - 1) * (p - 1);
        return res;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_SIEVE_HPP
