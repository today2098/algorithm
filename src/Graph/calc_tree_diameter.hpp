#ifndef ALGORITHM_CALC_TREE_DIAMETER_HPP
#define ALGORITHM_CALC_TREE_DIAMETER_HPP 1

#include <cassert>
#include <queue>
#include <tuple>
#include <utility>
#include <vector>

namespace algorithm {

// 木の直径．O(|V|+|E|).
std::tuple<int, int, int> calc_tree_diameter(const std::vector<std::vector<int> > &g) {
    if(g.size() == 0) return {-1, -1, -1};
    int endpoint;
    std::vector<int> dist(g.size());
    auto bfs = [&](int s) -> void {
        endpoint = s;
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            endpoint = u;
            for(int v : g[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    que.push(v);
                }
            }
        }
    };
    bfs(0);
    int tmp = endpoint;
    bfs(endpoint);
    return {dist[endpoint], tmp, endpoint};  // tuple of (distance, endpoint1, endpoint2).
}

// 重み付き木の直径．O(|E|*log|V|).
template <typename Type>
std::tuple<Type, int, int> calc_tree_diameter(const std::vector<std::vector<std::pair<int, Type> > > &g) {
    if(g.size() == 0) return {-1, -1, -1};
    int endpoint;
    std::vector<Type> dist(g.size());
    auto bfs = [&](int s) -> void {
        endpoint = s;
        std::fill(dist.begin(), dist.end(), -1);
        dist[s] = 0;
        std::priority_queue<std::pair<Type, int> > pque;
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [d, u] = pque.top();
            pque.pop();
            if(-d > dist[u]) continue;
            endpoint = u;
            for(const auto &[v, cost] : g[u]) {
                if(dist[v] == -1) {
                    dist[v] = dist[u] + cost;
                    pque.emplace(-dist[v], v);
                }
            }
        }
    };
    bfs(0);
    int tmp = endpoint;
    bfs(endpoint);
    return {dist[endpoint], tmp, endpoint};  // tuple of (distance, endpoint1, endpoint2).
}

}  // namespace algorithm

#endif
