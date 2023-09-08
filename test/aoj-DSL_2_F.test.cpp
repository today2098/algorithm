#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_F"

#include <algorithm>
#include <iostream>

#include "../src/DataStructure/SegmentTree/lazy_segment_tree.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = long long;
    using F = long long;
    constexpr S e = (1LL << 31) - 1;
    constexpr F id = 2 * e;
    auto op = [&](const S &l, const S &r) -> S { return std::min(l, r); };
    auto mapping = [&](const F &f, const S &x) -> S { return (f == id ? x : f); };
    auto composition = [&](const F &f, const F &g) -> F { return (f == id ? g : f); };
    algorithm::LazySegTree<S, F> tree(op, mapping, composition, e, id, n);

    while(q--) {
        int type;
        std::cin >> type;

        if(type == 0) {
            int s, t;
            long long x;
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
