#define PROBLEM "https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence"

#include <iostream>
#include <vector>

#include "../src/Math/Algebra/kitamasa.hpp"
#include "../src/Math/ModularArithmetic/modint.hpp"

int main() {
    int d;
    long long k;
    std::cin >> d >> k;

    std::vector<algorithm::mint998244353> a(d), c(d);
    for(auto &in : a) std::cin >> in;
    for(auto &in : c) std::cin >> in;

    algorithm::Kitamasa<algorithm::mint998244353> kitamasa(a, c);

    std::cout << kitamasa[k] << std::endl;
}
