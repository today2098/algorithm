#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include <iostream>
#include <tuple>
#include <vector>

#include "../src/DataStructure/UnionFind/rollback_union_find.hpp"

int main() {
    int n;
    int q;
    std::cin >> n >> q;

    // queries[k]:=(k番目のグラフに対するクエリ). tuple of (idx, t, u, v).
    std::vector<std::vector<std::tuple<int, int, int, int> > > queries(q + 1);
    for(int i = 1; i <= q; ++i) {
        int t;
        int k;
        int u, v;
        std::cin >> t >> k >> u >> v;
        k++;

        queries[k].emplace_back(i, t, u, v);
    }

    std::vector<int> ans(q, -1);
    algorithm::RollbackUnionFind uf(n);
    auto dfs = [&](auto self, int i, int t, int u, int v) -> void {
        if(t == 0) {
            auto flag = uf.unite(u, v);
            for(const auto &[ni, nt, nu, nv] : queries[i]) self(self, ni, nt, nu, nv);
            if(flag) uf.rollback();
        } else {
            ans[i - 1] = uf.is_same(u, v);
        }
    };
    for(const auto &[i, t, u, v] : queries[0]) dfs(dfs, i, t, u, v);

    for(auto out : ans) {
        if(out != -1) std::cout << out << "\n";
    }
}
