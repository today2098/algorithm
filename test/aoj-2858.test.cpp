#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2858"

#include <iostream>

#include "../src/Math/NumberTheory/is_prime.hpp"
#include "../src/Math/NumberTheory/segment_sieve.hpp"

int main() {
    int l, r;
    std::cin >> l >> r;
    if(l == 1) l = 2;

    algorithm::SegmentSieve sieve(l, r + 1);

    int ans = 0;
    for(int i = l; i <= r; ++i) {
        const auto &&pf = sieve.prime_factorize(i);

        int cnt = 0;
        for(const auto &[key, elem] : pf) cnt += elem;

        if(algorithm::is_prime(cnt)) ans++;
    }

    std::cout << ans << std::endl;
}
