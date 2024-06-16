#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include <iostream>

#include "../src/DataStructure/SegmentTree/dynamic_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = long long;
    constexpr S e = 0;
    auto op = [](const S &lhs, const S &rhs) -> S { return lhs + rhs; };
    algorithm::DynamicSegTree<S> segtree(op, e, n);

    for(int i = 0; i < n; ++i) {
        long long a;
        std::cin >> a;

        segtree.set(i, a);
    }

    while(q--) {
        int t;
        std::cin >> t;

        if(t == 0) {
            int p;
            long long x;
            std::cin >> p >> x;

            segtree.set(p, segtree.prod(p) + x);
        } else {
            int l, r;
            std::cin >> l >> r;

            std::cout << segtree.prod(l, r) << "\n";
        }
    }
}
