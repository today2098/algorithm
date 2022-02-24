#ifndef ALGORITHM_SIEVE_HPP
#define ALGORITHM_SIEVE_HPP 1

#include <algorithm>
#include <cassert>
#include <map>
#include <vector>

namespace algorithm {

// エラトステネスの篩．
class Sieve {
    int sz;                 // sz:=(要素数).
    std::vector<int> fact;  // fact[n]:=(自然数nの任意の素因数). fact[n]=nのとき，nは素数．

public:
    // constructor.
    Sieve() : Sieve(51e4) {}
    explicit Sieve(std::size_t n) : sz(n + 1), fact(n + 1, -1) {  // n以下の自然数を篩にかける．
        for(int i = 2; i < sz; ++i) fact[i] = i;
        for(int i = 2; i * i < sz; ++i) {
            if(fact[i] == i) {
                for(int j = i * i; j < sz; j += i) fact[j] = i;
            }
        }
    }

    bool is_prime(int n) const {  // 素数判定．O(1).
        assert(0 <= n and n < sz);
        return fact[n] == n;
    }
    std::map<int, int> prime_factorize(int n) const {  // 高速素因数分解．
        assert(2 <= n and n < sz);
        std::map<int, int> res;
        while(n > 1) {
            res[fact[n]]++;
            n /= fact[n];
        }
        return res;
    }
    std::vector<int> divisors(int n) const {  // 高速約数列挙．
        assert(1 <= n and n < sz);
        std::vector<int> res({1});
        if(n == 1) return res;
        const auto &&pf = prime_factorize(n);
        for(const auto &[p, cnt] : pf) {
            int m = res.size();
            for(int i = 0; i < m; ++i) {
                int v = 1;
                for(int j = 0; j < cnt; ++j) {
                    v *= p;
                    res.push_back(res[i] * v);
                }
            }
        }
        std::sort(res.begin(), res.end());
        return res;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_SIEVE_HPP
