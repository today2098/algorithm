#ifndef ALGORITHM_DINIC_HPP
#define ALGORITHM_DINIC_HPP 1

#include <algorithm>  // for fill() and min().
#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename T>
class Dinic {
    struct Edge {
        int to;       // to:=(行き先ノード).
        T cap, icap;  // cap:=(容量), icap:=(元の容量).
        int rev;      // rev:=(逆辺イテレータ).
        explicit Edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), icap(cap_), rev(rev_) {}
    };

    int vn;                             // vn:=(ノード数).
    std::vector<std::vector<Edge> > g;  // g[v][]:=(ノードvがもつ辺のリスト).
    std::vector<int> level;             // level[v]:=(ノードsからvまでの距離).
    std::vector<int> iter;              // iter[v]:=(ノードvがもつ辺リストの次に調べるべきイテレータ).
    T inf;

    void reset() {
        for(std::vector<Edge> &es : g)
            for(Edge &e : es) e.cap = e.icap;
    }
    void bfs(int s) {  // ノードsから各ノードへの最短距離を計算する．
        std::fill(level.begin(), level.end(), -1);
        level[s] = 0;
        std::queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(const Edge &e : g[v]) {
                if(e.cap > 0 and level[e.to] == -1) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    T dfs(int v, int t, T f) {  // 増加パスを探す．
        if(v == t) return f;
        int n = g[v].size();
        for(int &i = iter[v]; i < n; ++i) {
            Edge &e = g[v][i];
            if(e.cap > 0 and level[v] < level[e.to]) {
                T res = dfs(e.to, t, std::min(f, e.cap));
                if(res > 0) {
                    e.cap -= res;
                    g[e.to][e.rev].cap += res;
                    return res;
                }
            }
        }
        return 0;
    }

public:
    // constructor.
    Dinic() : Dinic(0) {}
    explicit Dinic(size_t vn_, T inf_ = 1e9) : vn(vn_), g(vn_), level(vn_), iter(vn_), inf(inf_) {}

    int size() const { return vn; }  // ノード数を返す．
    T infinity() const { return inf; }
    void add_directed_egde(int from, int to, T cap) {  // 容量capの有向辺を追加する．
        assert(0 <= from and from < vn);
        assert(0 <= to and to < vn);
        assert(from != to);
        g[from].emplace_back(to, cap, g[to].size());
        g[to].emplace_back(from, 0, g[from].size() - 1);
    }
    void add_undirected_edge(int u, int v, T cap) {  // 容量capの無向辺を追加する．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        assert(u != v);
        g[u].emplace_back(v, cap, g[v].size());
        g[v].emplace_back(u, cap, g[u].size() - 1);
    }
    T max_flow(int s, int t) {  // ノードsからtへの最大流を求める．O(|E|*(|V|^2)).
        assert(0 <= s and s < vn);
        assert(0 <= t and t < vn);
        reset();
        T flow = 0;
        while(flow < inf) {
            bfs(s);
            if(level[t] == -1) return flow;
            std::fill(iter.begin(), iter.end(), 0);
            T tmp;
            while((tmp = dfs(s, t, inf)) > 0) flow += tmp;
        }
        return inf;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_DINIC_HPP
