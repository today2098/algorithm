#ifndef ALGORITHM_DOUBLE_SWEEP_HPP
#define ALGORITHM_DOUBLE_SWEEP_HPP 1

/**
 * @brief Double Sweep（木の直径）
 * @docs docs/Graph/Tree/double_sweep.md
 */

#include <algorithm>
#include <cassert>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

// 木の直径を求める．O(|V|).
std::tuple<int, int, int> double_sweep(const std::vector<std::vector<int> > &g, int rt = 0) {
    const int vn = g.size();
    assert(vn == 0 or (0 <= rt and rt < vn));
    if(vn == 0) return {-1, -1, -1};
    int furthest_node;
    std::vector<int> d(vn);
    std::queue<int> que;
    auto bfs = [&](int s) -> void {
        furthest_node = s;
        std::fill(d.begin(), d.end(), -1);
        d[s] = 0;
        que.push(s);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            furthest_node = u;
            for(int v : g[u]) {
                assert(0 <= v and v < vn);
                if(d[v] != -1) continue;
                d[v] = d[u] + 1;
                que.push(v);
            }
        }
    };
    bfs(rt);
    rt = furthest_node;
    bfs(rt);
    return {d[furthest_node], rt, furthest_node};  // tuple of (diameter, endpoint1, endpoint2).
}

// 重み付き木の直径を求める．O(|V|).
template <typename Type>
std::tuple<Type, int, int> double_sweep(const std::vector<std::vector<std::pair<int, Type> > > &g, int rt = 0) {
    const int vn = g.size();
    assert(vn == 0 or (0 <= rt and rt < vn));
    if(vn == 0) return {-1, -1, -1};
    int furthest_node;
    std::vector<Type> d(vn);
    std::queue<int> que;
    std::vector<bool> seen(vn);
    auto bfs = [&](int s) -> void {
        furthest_node = s;
        d[s] = 0;
        que.push(s);
        std::fill(seen.begin(), seen.end(), false);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            seen[u] = true;
            if(d[u] > d[furthest_node]) furthest_node = u;
            for(const auto &[v, cost] : g[u]) {
                assert(0 <= v and v < vn);
                if(seen[v]) continue;
                d[v] = d[u] + cost;
                que.emplace(v);
            }
        }
    };
    bfs(rt);
    rt = furthest_node;
    bfs(rt);
    return {d[furthest_node], rt, furthest_node};  // tuple of (diameter, endpoint1, endpoint2).
}

}  // namespace algorithm

#endif
