#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_H"

#include <algorithm>
#include <iostream>
#include <vector>

#include "../src/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = int;
    using F = int;
    constexpr S e = 1e8;
    constexpr F id = 0;
    auto op = [&](const S &l, const S &r) -> S { return std::min(l, r); };
    auto mapping = [&](const F &f, const S &x) -> S { return x + f; };
    auto composition = [&](const F &f, const F &g) -> F { return f + g; };
    algorithm::LazySegTree<S, F> tree(op, mapping, composition, e, id, std::vector<int>(n, 0));

    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            int x;
            std::cin >> s >> t >> x;
            t++;

            tree.apply(s, t, x);
        } else {
            int s, t;
            std::cin >> s >> t;
            t++;

            std::cout << tree.prod(s, t) << "\n";
        }
    }
}
