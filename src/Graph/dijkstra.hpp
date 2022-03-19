#ifndef ALGORITHM_DIJKSTRA_HPP
#define ALGORITHM_DIJKSTRA_HPP 1

#include <algorithm>  // for fill() and reverse().
#include <cassert>
#include <functional>  // for greater.
#include <queue>       // for priority_queue.
#include <utility>     // for pair.
#include <vector>

namespace algorithm {

template <typename T>
class Dijkstra {
    template <typename Type>
    using r_priority_queue = std::priority_queue<Type, std::vector<Type>, std::greater<Type> >;
    struct Edge {
        int to;
        T cost;
    };

    int vn;                             // vn:=(ノード数).
    std::vector<std::vector<Edge> > g;  // g[v][]:=(ノードvがもつ辺のリスト).
    std::vector<T> d;                   // d[v]:=(ノードsからvへの最短距離).
    std::vector<int> pre;               // pre[v]:=(ノードvを訪問する直前のノード番号). 逆方向経路．
    T inf;

public:
    // constructor.
    Dijkstra() : Dijkstra(0) {}
    explicit Dijkstra(size_t vn_, T inf_ = 1e9) : vn(vn_), g(vn_), d(vn_, inf_), pre(vn_, -1), inf(inf_) {}

    int size() const { return vn; }  // ノード数を返す．
    T infinity() const { return inf; }
    void add_edge(int from, int to, T cost) {  // 重み付き有向辺を張る．
        assert(0 <= from and from < vn);
        assert(0 <= to and to < vn);
        g[from].push_back((Edge){to, cost});
    }
    void dijkstra(int s) {  // ノードsから各ノードへの最短距離を求める．O(|E|*log|V|).
        assert(0 <= s and s < vn);
        std::fill(d.begin(), d.end(), inf);
        d[s] = 0;
        std::fill(pre.begin(), pre.end(), -1);
        r_priority_queue<std::pair<T, int> > pque;  // pair(dt,v).
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [dt, v] = pque.top();
            pque.pop();
            if(d[v] < dt) continue;
            for(const Edge &e : g[v]) {
                if(d[e.to] > d[v] + e.cost) {
                    d[e.to] = d[v] + e.cost;
                    pre[e.to] = v;
                    pque.emplace(d[e.to], e.to);
                }
            }
        }
    }
    T distance(int v) const {  // ノードsからvへの最短距離を返す．
        assert(0 <= v and v < vn);
        return d[v];
    }
    std::vector<int> get_path(int v) const {  // ノードsからvへの最短経路を復元する．
        assert(0 <= v and v < vn);
        std::vector<int> path;
        for(; v != -1; v = pre[v]) path.push_back(v);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_DIJKSTRA_HPP
