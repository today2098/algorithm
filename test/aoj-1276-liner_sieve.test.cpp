#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1276"

#include <algorithm>
#include <iostream>
#include <iterator>

#include "../src/Math/NumberTheory/liner_sieve.hpp"

int main() {
    constexpr int MX = 1299709;
    algorithm::LinearSieve sieve(MX);

    while(true) {
        int a;
        std::cin >> a;

        if(a == 0) break;

        auto itr = std::lower_bound(sieve.primes().cbegin(), sieve.primes().cend(), a);
        std::cout << (*itr == a ? 0 : *itr - *std::prev(itr)) << "\n";
    }
}
