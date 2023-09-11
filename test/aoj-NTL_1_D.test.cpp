#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/NTL_1_D"

#include <iostream>

#include "../src/Math/NumberTheory/totient.hpp"

int main() {
    int n;
    std::cin >> n;

    std::cout << algorithm::totient(n) << std::endl;
}
