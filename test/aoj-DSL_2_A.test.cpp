#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <algorithm>
#include <iostream>

#include "../src/DataStructure/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using T = int;
    const T e = (1 << 31) - 1;
    auto op = [](T a, T b) -> T { return std::min(a, b); };
    algorithm::SegmentTree<T> segtree(op, e, n);
    while(q--) {
        int com;
        int x;
        int y;
        std::cin >> com >> x >> y;

        if(com == 0) segtree.set(x, y);
        else std::cout << segtree.prod(x, y + 1) << std::endl;
    }
}
