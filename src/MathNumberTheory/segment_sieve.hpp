#ifndef ALGORITHM_SEGMENT_SIEVE_HPP
#define ALGORITHM_SEGMENT_SIEVE_HPP 1

#include <algorithm>
#include <cassert>
#include <cmath>
#include <map>
#include <vector>

namespace algorithm {

// 区間篩．
class SegmentSieve {
    long long l, r, m;
    std::vector<long long> small;                  // small[n]:=(範囲[2,√r)の自然数xのある素因数).
    std::vector<std::map<long long, int> > large;  // large[n-l]:=(範囲[l,r)の自然数xのいくつかの素因数).
    std::vector<long long> aux;                    // aux[n-l]:=(large[n-l]の素因数の積).

    void build() {
        m = std::sqrt(r) + 5;
        small.assign(m, -1);
        for(long long i = 2; i < m; ++i) small[i] = i;
        large.resize(r - l);
        aux.assign(r - l, 1);
        for(long long i = 2; i * i < r; ++i) {
            if(small[i] == i) {
                for(long long j = i * i; j < m; j += i) small[j] = i;
                for(long long j = std::max<long long>(2LL, (l + i - 1) / i) * i; j < r; j += i) {
                    long long tmp = j;
                    while(tmp % i == 0 and aux[j - l] * aux[j - l] <= r) {
                        large[j - l][i]++;
                        aux[j - l] *= i;
                        tmp /= i;
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
        if(n >= m) {
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
            int m = res.size();
            for(int i = 0; i < m; ++i) {
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
