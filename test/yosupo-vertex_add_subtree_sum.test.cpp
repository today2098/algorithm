#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include <vector>

#include "../src/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp"
#include "../src/Graph/Tree/heavy_light_decomposition.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    std::vector<int> a(n);
    for(auto &in : a) std::cin >> in;

    algorithm::HLD hld(n);
    for(int i = 1; i < n; ++i) {
        int p;
        std::cin >> p;
        hld.add_edge(p, i);
    }
    hld.build();

    algorithm::BIT0<long long> bitree(n);
    for(int i = 0; i < n; ++i) bitree.add(hld.vid(i), a[i]);

    while(q--) {
        int t;
        int u;
        std::cin >> t >> u;

        if(t == 0) {
            int x;
            std::cin >> x;
            bitree.add(hld.vid(u), x);
        } else {
            const auto &&[l, r] = hld.subtree_vertex_query_range(u);
            long long ans = bitree.sum(l, r);
            std::cout << ans << "\n";
        }
    }
}
