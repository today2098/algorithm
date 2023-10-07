#define PROBLEM "https://judge.yosupo.jp/problem/convolution_mod"

#include <iostream>
#include <vector>

#include "../src/Math/Convolution/number_theoretic_transform.hpp"
#include "../src/Math/ModularArithmetic/modint.hpp"

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<algorithm::mint998244353> a(n), b(m);
    for(auto &in : a) std::cin >> in;
    for(auto &in : b) std::cin >> in;

    auto &&c = algorithm::ntt::convolve(a, b);
    for(const auto &out : c) std::cout << out << " ";
    std::cout << std::endl;
}
