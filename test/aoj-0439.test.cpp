#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/0439"

#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <utility>
#include <vector>

#include "../src/Graph/Tree/lowest_common_ancestor.hpp"
#include "../src/Utils/convert.hpp"
#include "../src/Utils/debug.hpp"

int main() {
    int n;
    std::cin >> n;

    std::vector<int> c(n);
    std::vector<std::vector<int> > inv(n);
    for(int i = 0; i < n; ++i) {
        std::cin >> c[i];
        c[i]--;
        inv[c[i]].push_back(i);
    }

    algorithm::LCA lca(n);
    for(int i = 0; i < n - 1; ++i) {
        int s, t;
        std::cin >> s >> t;
        s--, t--;
        lca.add_edge(s, t);
    }
    lca.build();

    constexpr int INF = 1e9;
    std::vector<int> ans(n);
    for(int i = 0; i < n; ++i) {
        if(inv[i].size() == 0) continue;
        auto vs = inv[i];
        const auto &&[rt, tree] = lca.auxiliary_tree(vs);
        debug(i, rt, vs, tree);

        std::map<int, std::array<std::pair<int, int>, 2> > mp;
        for(auto v : vs) {
            auto &neighbors = mp[v];
            if(c[v] == i) {
                neighbors[0] = {0, v};
                neighbors[1] = {INF, -1};
            } else {
                neighbors[0] = {INF, -1};
                neighbors[1] = {INF, -1};
            }
        }

        auto bottom_up = [&](auto self, int u, int p) -> std::pair<int, int> {
            auto &neighbors = mp[u];
            for(auto v : tree.at(u)) {
                if(v == p) continue;
                const auto &&[d, w] = self(self, v, u);
                auto len = lca.length(u, v);
                algorithm::chmin(neighbors[1], {d + len, w});
                if(neighbors[0] > neighbors[1]) std::swap(neighbors[0], neighbors[1]);
            }
            return neighbors[0];
        };
        bottom_up(bottom_up, rt, -1);

        auto top_down = [&](auto self, int u, int p) -> void {
            const auto &neighbors_u = mp[u];
            for(auto v : tree.at(u)) {
                if(v == p) continue;
                auto &neighbors_v = mp[v];
                auto len = lca.length(u, v);
                if(neighbors_u[0].second == neighbors_v[0].second) algorithm::chmin(neighbors_v[1], {neighbors_u[1].first + len, neighbors_u[1].second});
                else algorithm::chmin(neighbors_v[1], {neighbors_u[0].first + len, neighbors_u[0].second});
                if(neighbors_v[0] > neighbors_v[1]) std::swap(neighbors_v[0], neighbors_v[1]);
                self(self, v, u);
            }
        };
        top_down(top_down, rt, -1);

        for(const auto &[u, neighbors] : mp) {
            if(c[u] == i) {
                const auto &[d, v] = (neighbors[0].second == u ? neighbors[1] : neighbors[0]);
                debug(u, v, d);
                ans[u] = d;
            }
        }
    }

    for(auto out : ans) std::cout << out << "\n";
}
