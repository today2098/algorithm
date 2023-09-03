#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../src/DataStructure/SegmentTree/sparse_table.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    algorithm::SparseTable<int> sparse_table([](int a, int b) -> int { return std::min(a, b); }, a);
    while(q--) {
        int l, r;
        std::cin >> l >> r;

        std::cout << sparse_table.fold(l, r) << std::endl;
    }
}
