#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_palindromes"

#include <iostream>
#include <string>

#include "../src/String/manacher.hpp"

int main() {
    std::string s;
    std::cin >> s;

    algorithm::Manacher manacher(s);

    for(int i = 0, n = s.size(); i < n; ++i) {
        std::cout << 2 * manacher.odd_radius(i) - 1 << " ";
        if(i < n - 1) std::cout << 2 * manacher.even_radius(i) << " ";
    }
    std::cout << std::endl;
}
