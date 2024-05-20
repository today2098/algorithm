#define PROBLEM "https://judge.yosupo.jp/problem/zalgorithm"

#include <iostream>
#include <string>

#include "../src/String/z_algorithm.hpp"

int main() {
    std::string s;
    std::cin >> s;

    auto &&z = algorithm::z_algorithm(s);

    for(int i = 0, n = s.size(); i < n; ++i) std::cout << z[i] << " ";
    std::cout << std::endl;
}
