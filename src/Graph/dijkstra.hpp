#ifndef ALGORITHM_DIJKSTRA_HPP
#define ALGORITHM_DIJKSTRA_HPP 1

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename T>
class Dijkstra {
    int m_vn;                                           // m_vn:=(ノード数).
    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(ノードvが始点である重み付き有向辺のリスト). pair of (to, cost).
    std::vector<T> m_d;                                 // m_d[t]:=(ノードsからtへの最短距離).
    std::vector<int> m_pre;                             // m_pre[t]:=(ノードtを訪問する直前のノードの番号). 逆方向経路．
    T m_inf;

public:
    Dijkstra() : Dijkstra(0) {}
    explicit Dijkstra(size_t vn, T inf = 1e9) : m_vn(vn), m_g(vn), m_d(vn, inf), m_pre(vn, -1), m_inf(inf) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    T infinity() const { return m_inf; }
    // 重み付き有向辺を張る．
    void add_edge(int from, int to, T cost) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].emplace_back(to, cost);
    }
    // ノードsから各ノードへの最短距離を求める．O(|E|*log|V|).
    void dijkstra(int s) {
        assert(0 <= s and s < order());
        std::fill(m_d.begin(), m_d.end(), infinity());
        m_d[s] = 0;
        std::fill(m_pre.begin(), m_pre.end(), -1);
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int> >, std::greater<std::pair<T, int> > > pque;
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [dist, v] = pque.top();
            pque.pop();
            if(m_d[v] < dist) continue;
            for(const auto &[to, cost] : m_g[v]) {
                if(m_d[to] > m_d[v] + cost) {
                    m_d[to] = m_d[v] + cost;
                    m_pre[to] = v;
                    pque.emplace(m_d[to], to);
                }
            }
        }
    }
    // ノードsからtへの最短距離を返す．
    T distance(int t) const {
        assert(0 <= t and t < order());
        return m_d[t];
    }
    // ノードsからtへの最短経路を復元する．
    std::vector<int> shortest_path(int t) const {
        assert(0 <= t and t < order());
        std::vector<int> path;
        if(distance(t) == infinity()) return path;
        for(; t != -1; t = m_pre[t]) path.push_back(t);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

}  // namespace algorithm

#endif
