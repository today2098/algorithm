#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../src/DataStructure/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(int &in : a) std::cin >> in;

    using T = int;
    const T e = 1e9 + 1;
    auto op = [](T a, T b) -> T { return std::min(a, b); };
    algorithm::SegmentTree<T> segtree(op, e, a);
    while(q--) {
        int l, r;
        std::cin >> l >> r;

        std::cout << segtree.prod(l, r) << std::endl;
    }
}
