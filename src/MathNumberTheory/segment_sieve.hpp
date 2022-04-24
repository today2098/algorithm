#ifndef ALGORITHM_SEGMENT_SIEVE_HPP
#define ALGORITHM_SEGMENT_SIEVE_HPP 1

#include <algorithm>  // for max() and sort().
#include <cassert>
#include <cmath>  // for sqrt().
#include <map>
#include <vector>

namespace algorithm {

// 区間篩．
class SegmentSieve {
    long long l, r;
    long long sr;                                  // sr:=√r.
    std::vector<long long> small;                  // small[n]:=(範囲[2,√r)の自然数xのある素因数).
    std::vector<std::map<long long, int> > large;  // large[n-l]:=(範囲[l,r)の自然数xの範囲[2,√r)における素因数).
    std::vector<long long> aux;                    // aux[n-l]:=(large[n-l]の素因数の積).

    void build() {
        sr = std::sqrt(r) + 5;
        small.assign(sr, -1);
        for(long long p = 2; p < sr; ++p) small[p] = p;
        large.resize(r - l);
        aux.assign(r - l, 1);
        for(long long p = 2; p * p < r; ++p) {
            if(small[p] == p) {
                for(long long m = p * p; m < sr; m += p) small[m] = p;
                for(long long m = std::max<long long>(2LL, (l + p - 1) / p) * p; m < r; m += p) {
                    long long tmp = m;
                    while(tmp % p == 0 and aux[m - l] * aux[m - l] <= r) {
                        large[m - l][p]++;
                        aux[m - l] *= p;
                        tmp /= p;
                    }
                }
            }
        }
    }

public:
    // constructor. 制約の目安は大体2<=l<r<=1e12, r-l<=1e6．
    SegmentSieve() : SegmentSieve(2, 3) {}
    explicit SegmentSieve(long long l_, long long r_) : l(l_), r(r_) {  // 範囲[l,r)の自然数を篩にかける．
        assert(2 <= l and l < r);
        build();
    }

    bool is_prime(long long n) const {  // 素数判定．O(1).
        assert(l <= n and n < r);
        return large[n - l].size() == 0;
    }
    std::map<long long, int> prime_factorize(long long n) const {  // 高速素因数分解．
        assert(l <= n and n < r);
        std::map<long long, int> res = large[n - l];
        n /= aux[n - l];
        if(n >= sr) {
            res[n]++;
            return res;
        }
        while(n > 1) {
            res[small[n]]++;
            n /= small[n];
        }
        return res;
    }
    std::vector<long long> divisors(long long n) const {  // 高速約数列挙．
        assert(l <= n and n < r);
        std::vector<long long> res({1});
        if(n == 1) return res;
        const auto &&pf = prime_factorize(n);
        for(const auto &[p, cnt] : pf) {
            int sz = res.size();
            for(int i = 0; i < sz; ++i) {
                long long v = 1;
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

#endif  // ALGORITHM_SEGMENT_SIEVE_HPP
