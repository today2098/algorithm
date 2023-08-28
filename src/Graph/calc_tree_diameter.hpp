#ifndef ALGORITHM_CALC_TREE_DIAMETER_HPP
#define ALGORITHM_CALC_TREE_DIAMETER_HPP 1

#include <cassert>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

// 木の直径を求める．O(|V|).
std::tuple<int, int, int> calc_tree_diameter(const std::vector<std::vector<int> > &g) {
    if(g.size() == 0) return {-1, -1, -1};
    int endpoint;
    std::vector<int> d(g.size());
    std::queue<int> que;
    auto bfs = [&](int s) -> void {
        endpoint = s;
        std::fill(d.begin(), d.end(), -1);
        d[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            endpoint = u;
            for(int v : g[u]) {
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    };
    bfs(0);
    int tmp = endpoint;
    bfs(endpoint);
    return {d[endpoint], tmp, endpoint};  // tuple of (diameter, endpoint1, endpoint2).
}

// 重み付き木の直径を求める．O(|V|).
template <typename Type>
std::tuple<Type, int, int> calc_tree_diameter(const std::vector<std::vector<std::pair<int, Type> > > &g) {
    if(g.size() == 0) return {-1, -1, -1};
    int endpoint;
    Type diameter;
    std::vector<Type> d(g.size());
    std::vector<bool> seen(g.size());
    std::queue<int> que;
    auto bfs = [&](int s) -> void {
        endpoint = s;
        diameter = d[s] = 0;
        std::fill(seen.begin(), seen.end(), false);
        que.push(s);
        while(!que.empty()) {
            int u = que.top();
            que.pop();
            seen[u] = true;
            if(d[u] > diameter) endpoint = u, diameter = d[u];
            for(const auto &[v, cost] : g[u]) {
                if(seen[v]) continue;
                d[v] = d[u] + cost;
                que.emplace(v);
            }
        }
    };
    bfs(0);
    int tmp = endpoint;
    bfs(endpoint);
    return {diameter, tmp, endpoint};  // tuple of (diameter, endpoint1, endpoint2).
}

}  // namespace algorithm

#endif
