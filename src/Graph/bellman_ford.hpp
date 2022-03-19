#ifndef ALGORITHM_BELLMAN_FORD_HPP
#define ALGORITHM_BELLMAN_FORD_HPP 1

#include <algorithm>  // for fill() and reverse().
#include <cassert>
#include <vector>

namespace algorithm {

template <typename T>
class BellmanFord {
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
    BellmanFord() : BellmanFord(0) {}
    explicit BellmanFord(size_t vn_, T inf_ = 1e9) : vn(vn_), g(vn_), d(vn_, inf_), pre(vn_, -1), inf(inf_) {}

    int size() const { return vn; }  // ノード数を返す．
    T infinity() const { return inf; }
    void add_edge(int from, int to, T cost) {  // 重み付き有向辺を張る．
        assert(0 <= from and from < vn);
        assert(0 <= to and to < vn);
        g[from].push_back((Edge){to, cost});
    }
    bool find_negative_cycle() const {  // グラフ全体から負閉路を検出する．O(|V|*|E|).
        std::vector<T> nd(vn, 0);
        for(int i = 0; i < vn; ++i) {
            bool update = false;
            for(int v = 0; v < vn; ++v) {
                for(const Edge &e : g[v]) {
                    if(nd[e.to] > nd[v] + e.cost) {
                        nd[e.to] = nd[v] + e.cost;
                        update = true;
                    }
                }
            }
            if(!update) break;
            if(i == vn - 1) return true;  // 負閉路あり．
        }
        return false;
    }
    void bellman_ford(int s) {  // ノードsから各ノードへの最短距離を求める．O(|V|*|E|).
        assert(0 <= s and s < vn);
        std::fill(d.begin(), d.end(), inf);
        d[s] = 0;
        std::fill(pre.begin(), pre.end(), -1);
        for(int i = 0; i < 2 * vn; ++i) {
            bool update = false;
            for(int v = 0; v < vn; ++v) {
                if(d[v] == inf) continue;
                for(const Edge &e : g[v]) {
                    if(d[e.to] == -inf) continue;
                    if(d[e.to] > d[v] + e.cost) {
                        if(i < vn - 1) {
                            d[e.to] = d[v] + e.cost;
                            pre[e.to] = v;
                        } else {
                            d[e.to] = -inf;
                        }
                        update = true;
                    }
                }
            }
            if(!update) break;
        }
    }
    T distance(int v) const {  // ノードsからvへの最短距離を返す．
        assert(0 <= v and v < vn);
        return d[v];
    }
    std::vector<int> get_path(int v) const {  // ノードsからvへの最短経路を復元する．
        assert(0 <= v and v < vn);
        assert(-inf < d[v] and d[v] < inf);
        std::vector<int> path;
        for(; v != -1; v = pre[v]) path.push_back(v);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_BELLMAN_FORD_HPP
