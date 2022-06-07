#ifndef ALGORITHM_LINEAR_SIEVE_HPP
#define ALGORITHM_LINEAR_SIEVE_HPP 1

#include <algorithm>  // for sort().
#include <cassert>
#include <map>
#include <vector>

namespace algorithm {

// 線形篩．
class LinearSieve {
public:
    int mx;                   // mx:=(篩にかける最大の自然数).
    std::vector<int> lpf;     // lpf[n]:=(自然数nの最小の素因数). Least prime factor. lpf[n]=nのとき，nは素数．
    std::vector<int> primes;  // primes[]:=(素数のリスト).

public:
    // constructor.
    LinearSieve() : LinearSieve(51e4) {}
    explicit LinearSieve(int n) : mx(n), lpf(n + 1, -1) {  // n以下の自然数を篩にかける．O(N).
        assert(n >= 0);
        for(int p = 2; p <= n; ++p) {
            if(lpf[p] == -1) {
                lpf[p] = p;
                primes.push_back(p);
            }
            int sz = primes.size();
            for(int i = 0; i < sz and primes[i] <= lpf[p] and primes[i] * p <= n; ++i) lpf[primes[i] * p] = primes[i];
        }
    }

    bool is_prime(int n) const {  // 素数判定．O(1).
        assert(0 <= n and n <= mx);
        return lpf[n] == n;
    }
    int get_lpf(int n) const {  // 自然数nの最小の素因数を返す．O(1).
        assert(2 <= n and n <= mx);
        return lpf[n];
    }
    std::map<int, int> prime_factorize(int n) const {  // 高速素因数分解．O(logN).
        assert(1 <= n and n <= mx);
        std::map<int, int> res;
        while(n > 1) {
            res[lpf[n]]++;
            n /= lpf[n];
        }
        return res;
    }
    std::vector<int> divisors(int n) const {  // 高速約数列挙．
        assert(1 <= n and n <= mx);
        std::vector<int> res({1});
        const auto &&pf = prime_factorize(n);
        for(const auto &[p, cnt] : pf) {
            int sz = res.size();
            int v = 1;
            for(int i = 0; i < cnt; ++i) {
                v *= p;
                for(int j = 0; j < sz; ++j) res.push_back(res[i] * v);
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
    const std::vector<int> &get_primes() const { return primes; }
};

}  // namespace algorithm

#endif  // ALGORITHM_LINEAR_SIEVE_HPP
