#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_3_D"

#include <algorithm>
#include <iostream>

#include "../src/Math/NumberTheory/divisors.hpp"

int main() {
    int a, b, c;
    std::cin >> a >> b >> c;

    const auto &&divs = algorithm::divisors(c);
    std::cout << std::upper_bound(divs.begin(), divs.end(), b) - std::lower_bound(divs.begin(), divs.end(), a) << std::endl;
}
