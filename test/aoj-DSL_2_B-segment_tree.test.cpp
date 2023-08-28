#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_B"

#include <iostream>

#include "../src/DataStructure/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using T = int;
    const T e = 0;
    auto op = [](T a, T b) -> T { return a + b; };
    algorithm::SegmentTree<T> segtree(op, e, n);
    while(q--) {
        int com;
        int x;
        int y;
        std::cin >> com >> x >> y;

        if(com == 0) {
            x--;
            segtree.set(x, segtree.prod(x) + y);
        } else {
            x--;
            std::cout << segtree.prod(x, y) << std::endl;
        }
    }
}
