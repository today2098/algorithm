#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_10_A"

#include <iostream>

#include "../src/Math/Algebra/kitamasa.hpp"

int main() {
    int n;
    std::cin >> n;

    algorithm::Kitamasa kitamasa({1, 1}, {1, 1});
    std::cout << kitamasa[n] << std::endl;
}
