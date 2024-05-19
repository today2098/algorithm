#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/10/ALDS1_10_C"

#include <iostream>
#include <string>

#include "../src/DP/longest_common_subsequence.hpp"

int main() {
    int q;
    std::cin >> q;

    while(q--) {
        std::string x, y;
        std::cin >> x >> y;

        std::cout << algorithm::lcs(x, y).size() << "\n";
    }
}
