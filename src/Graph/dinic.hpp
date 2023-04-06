#ifndef ALGORITHM_DINIC_HPP
#define ALGORITHM_DINIC_HPP 1

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename T>
class Dinic {
    struct Edge {
        int to;       // to:=(行き先ノード).
        T cap, rest;  // cap:=(容量), rest:=(残容量).
        int rev;      // rev:=(逆辺イテレータ).
        explicit Edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), rest(cap_), rev(rev_) {}
    };

    int m_vn;                             // m_vn:=(ノード数).
    std::vector<std::vector<Edge> > m_g;  // m_g[v][]:=(ノードvが始点の隣接辺リスト).
    std::vector<int> m_hop;               // m_hop[v]:=(ノードsからvまでのホップ数).
    std::vector<int> m_iter;              // m_iter[v]:=(m_g[v][]の次に調べるべきイテレータ).
    T m_inf;

    // ノードsから各ノードへのホップ数を計算する．
    void bfs(int s) {
        std::fill(m_hop.begin(), m_hop.end(), -1);
        m_hop[s] = 0;
        std::queue<int> que;
        que.push(s);
        while(!que.empty()) {
            int v = que.front();
            que.pop();
            for(const Edge &e : m_g[v]) {
                if(e.rest > 0 and m_hop[e.to] == -1) {
                    m_hop[e.to] = m_hop[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    // 増加パスを探す．
    T dfs(int v, int t, T flow) {
        if(v == t) return flow;
        const int n = m_g[v].size();
        for(int &i = m_iter[v]; i < n; ++i) {
            Edge &e = m_g[v][i];
            if(e.rest > 0 and m_hop[v] < m_hop[e.to]) {
                T res = dfs(e.to, t, std::min(flow, e.rest));
                if(res > 0) {
                    e.rest -= res;
                    m_g[e.to][e.rev].cap += res;
                    return res;
                }
            }
        }
        return 0;
    }

public:
    Dinic() : Dinic(0) {}
    explicit Dinic(size_t vn, T inf = 1e9) : m_vn(vn), m_g(vn), m_hop(vn), m_iter(vn), m_inf(inf) {}

    // ノード数を返す．
    int size() const { return m_vn; }
    T infinity() const { return m_inf; }
    // 容量capの有向辺を追加する．
    void add_directed_edge(int from, int to, T cap) {
        assert(0 <= from and from < size());
        assert(0 <= to and to < size());
        assert(from != to);
        m_g[from].emplace_back(to, cap, m_g[to].size());
        m_g[to].emplace_back(from, 0, m_g[from].size() - 1);
    }
    // 容量capの無向辺を追加する．
    void add_undirected_edge(int u, int v, T cap) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        assert(u != v);
        m_g[u].emplace_back(v, cap, m_g[v].size());
        m_g[v].emplace_back(u, cap, m_g[u].size() - 1);
    }
    // ノードsからtへの最大流を求める．O(|E|*(|V|^2)).
    T max_flow(int s, int t) {
        assert(0 <= s and s < size());
        assert(0 <= t and t < size());
        for(std::vector<Edge> &es : m_g) {
            for(Edge &e : es) e.rest = e.cap;
        }
        T flow = 0;
        while(flow < infinity()) {
            bfs(s);
            if(m_hop[t] == -1) return flow;
            std::fill(m_iter.begin(), m_iter.end(), 0);
            T tmp;
            while((tmp = dfs(s, t, infinity())) > 0) flow += tmp;
        }
        return infinity();
    }
};

}  // namespace algorithm

#endif
