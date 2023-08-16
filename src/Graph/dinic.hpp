#ifndef ALGORITHM_DINIC_HPP
#define ALGORITHM_DINIC_HPP 1

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename T>  // T:Type of capacity.
class Dinic {
    struct Edge {
        int to;       // to:=(行き先ノード).
        T cap, rest;  // cap:=(容量), rest:=(残容量).
        int rev;      // rev:=(逆辺イテレータ).
        explicit Edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), rest(cap_), rev(rev_) {}
    };

    int m_vn;                             // m_vn:=(ノード数).
    std::vector<std::vector<Edge> > m_g;  // m_g[v][]:=(ノードvの隣接リスト).
    T m_inf;

    // ノードsと各ノード間の長さを求める．
    void bfs(int s, std::vector<int> &d) const {
        std::fill(d.begin(), d.end(), -1);
        d[s] = 0;
        std::queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(const Edge &e : m_g[v]) {
                if(e.rest > 0 and d[e.to] == -1) {
                    d[e.to] = d[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    // 増加パスを探す．
    T dfs(int v, int t, T flow, const std::vector<int> &d, std::vector<int> &iter) {
        if(v == t) return flow;
        const int n = m_g[v].size();
        for(int &i = iter[v]; i < n; ++i) {
            Edge &e = m_g[v][i];
            if(e.rest > 0 and d[e.to] > d[v]) {
                T res = dfs(e.to, t, std::min(flow, e.rest), d, iter);
                if(res > 0) {
                    e.rest -= res;
                    m_g[e.to][e.rev].rest += res;
                    return res;
                }
            }
        }
        return 0;
    }

public:
    Dinic() : Dinic(0) {}
    explicit Dinic(size_t vn, T inf = 1e9) : m_vn(vn), m_g(vn), m_inf(inf) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    T infinity() const { return m_inf; }
    // 容量capの有向辺を追加する．
    void add_directed_edge(int from, int to, T cap) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        assert(from != to);
        m_g[from].emplace_back(to, cap, m_g[to].size());
        m_g[to].emplace_back(from, 0, m_g[from].size() - 1);
    }
    // 容量capの無向辺を追加する．
    void add_undirected_edge(int u, int v, T cap) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        assert(u != v);
        m_g[u].emplace_back(v, cap, m_g[v].size());
        m_g[v].emplace_back(u, cap, m_g[u].size() - 1);
    }
    // ノードsからtへの最大流を求める．O(|E|*(|V|^2)).
    T max_flow(int s, int t) {
        assert(0 <= s and s < order());
        assert(0 <= t and t < order());
        for(std::vector<Edge> &es : m_g) {
            for(Edge &e : es) e.rest = e.cap;
        }
        T flow = 0;
        std::vector<int> d(order());     // d[v]:=(ノードsからvまでの長さ).
        std::vector<int> iter(order());  // iter[v]:=(m_g[v][]の次に調べるべきイテレータ).
        while(flow < infinity()) {
            bfs(s, d);
            if(d[t] == -1) return flow;
            std::fill(iter.begin(), iter.end(), 0);
            T tmp;
            while((tmp = dfs(s, t, infinity(), d, iter)) > 0) flow += tmp;
        }
        return infinity();
    }
};

}  // namespace algorithm

#endif
