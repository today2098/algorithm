#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include <iostream>
#include <vector>

#include "../src/DataStructure/SegmentTree/lazy_segment_tree.hpp"
#include "../src/Math/ModularArithmetic/modint.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    using S = struct {
        algorithm::mint998244353 val;
        int size;
    };
    using F = struct {
        algorithm::mint998244353 a;
        algorithm::mint998244353 b;
    };
    const S e = (S){0, 0};
    const F id = (F){1, 0};
    auto op = [&](const S &lhs, const S &rhs) -> S { return (S){lhs.val + rhs.val, lhs.size + rhs.size}; };
    auto mapping = [&](const F &f, const S &x) -> S { return (S){f.a * x.val + f.b * x.size, x.size}; };
    auto composition = [&](const F &f, const F &g) -> F { return (F){f.a * g.a, f.a * g.b + f.b}; };

    std::vector<S> a(n, (S){0, 1});
    for(auto &elem : a) std::cin >> elem.val;

    algorithm::LazySegTree<S, F> segtree(op, mapping, composition, e, id, a);

    while(q--) {
        int t;
        int l, r;
        std::cin >> t >> l >> r;

        if(t == 0) {
            algorithm::mint998244353 b, c;
            std::cin >> b >> c;

            segtree.apply(l, r, (F){b, c});
        } else {
            std::cout << segtree.prod(l, r).val << std::endl;
        }
    }
}
