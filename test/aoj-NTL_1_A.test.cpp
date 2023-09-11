#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_A"

#include <iostream>

#include "../src/Math/NumberTheory/prime_factorize.hpp"

int main() {
    int n;
    std::cin >> n;

    const auto &&mp = algorithm::prime_factorize(n);

    std::cout << n << ":";
    for(const auto &[p, cnt] : mp) {
        for(int i = 0; i < cnt; ++i) std::cout << " " << p;
    }
    std::cout << std::endl;
}
