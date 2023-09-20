#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/all/DPL_1_D"

#include <iostream>
#include <vector>

#include "../src/DP/longest_increasing_subsequence.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    std::cout << algorithm::lis(a).back() << std::endl;
}
