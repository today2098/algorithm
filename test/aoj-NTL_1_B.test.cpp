#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_B"

#include <iostream>

#include "../src/Math/ModularArithmetic/mod_pow.hpp"

int main() {
    constexpr int MOD = 1e9 + 7;

    int m, n;
    std::cin >> m >> n;

    std::cout << algorithm::mod_pow(m, n, MOD) << std::endl;
}
