#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include <algorithm>
#include <iostream>

#include "../src/DataStructure/SegmentTree/segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = long long;
    constexpr S e = (1LL << 31) - 1;
    auto op = [](const S &lhs, const S &rhs) -> S { return std::min(lhs, rhs); };
    algorithm::SegmentTree<S> segtree(op, e, n);

    while(q--) {
        int com;
        int x;
        int y;
        std::cin >> com >> x >> y;

        if(com == 0) segtree.set(x, y);
        else std::cout << segtree.prod(x, y + 1) << "\n";
    }
}
