#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/challenges/sources/ICPC/Regional/1276"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

#include "../src/Math/NumberTheory/sieve.hpp"

int main() {
    constexpr int MX = 1299709;
    algorithm::Sieve sieve(MX);

    std::vector<int> primes;
    primes.reserve(100000);
    for(int p = 2; p <= MX; ++p) {
        if(sieve.is_prime(p)) primes.push_back(p);
    }

    while(true) {
        int a;
        std::cin >> a;

        if(a == 0) break;

        auto itr = std::lower_bound(primes.begin(), primes.end(), a);
        std::cout << (*itr == a ? 0 : *itr - *std::prev(itr)) << std::endl;
    }
}
