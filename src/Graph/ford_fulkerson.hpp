#ifndef ALGORITHM_FORD_FULKERSON_HPP
#define ALGORITHM_FORD_FULKERSON_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

template <typename T>
class FordFulkerson {
    struct Edge {
        int to;       // to:=(行き先ノード).
        T cap, rest;  // cap:=(容量), rest:=(残容量).
        int rev;      // rev:=(逆辺イテレータ).
        explicit Edge(int to_, T cap_, int rev_) : to(to_), cap(cap_), rest(cap_), rev(rev_) {}
    };

    int m_vn;                             // m_vn:=(ノード数).
    std::vector<std::vector<Edge> > m_g;  // m_g[v][]:=(ノードvが始点の有向辺リスト).
    bool *m_seen;                         // m_seen[v]:=(DFSでノードvを調べたか).
    T m_inf;

    // 増加パスを探す．
    T dfs(int v, int t, T flow) {
        if(v == t) return flow;
        m_seen[v] = true;
        for(Edge &e : m_g[v]) {
            if(!m_seen[e.to] and e.rest > 0) {
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
    FordFulkerson() : FordFulkerson(0) {}
    explicit FordFulkerson(size_t vn, T inf = 1e9) : m_vn(vn), m_g(vn), m_inf(inf) {
        m_seen = new bool[m_vn]{};
    }

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
    // ノードsからtへの最大流を調べる．O(F*|E|).
    T max_flow(int s, int t) {
        assert(0 <= s and s < size());
        assert(0 <= t and t < size());
        for(std::vector<Edge> &es : m_g) {
            for(Edge &e : es) e.rest = e.cap;
        }
        T flow = 0;
        while(flow < infinity()) {
            std::fill(m_seen, m_seen + m_vn, false);
            T tmp = dfs(s, t, infinity());
            if(tmp == 0) return flow;
            flow += tmp;
        }
        return infinity();
    }
};

}  // namespace algorithm

#endif
