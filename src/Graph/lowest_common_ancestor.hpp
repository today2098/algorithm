#ifndef LOWEST_COMMON_ANCESTOR_HPP
#define LOWEST_COMMON_ANCESTOR_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 最近共通祖先 (LCA: Lowest Common Ancestor)．
class LCA {
    using Graph = std::vector<std::vector<int> >;

    int m_vn;                              // m_vn:=(ノード数).
    int m_h;                               // m_h:=ceiling(log2(m_vn)).
    int m_rt;                              // m_rt:=(根番号).
    Graph m_g;                             // m_g[v][]:=(ノードvの隣接リスト).
    std::vector<std::vector<int> > m_par;  // m_par[v][k]:=(ノードvから2^k回辿って到達する親ノード番号). 親がいない場合は-1．
    std::vector<int> m_depth;              // m_depth[v]:=(ノードvの深さ). 根に連結していない場合は-1．
    bool m_update;

    void dfs(int u, int p, int d) {
        assert(m_depth[u] == -1);
        m_par[u][0] = p;
        m_depth[u] = d;
        for(auto v : m_g[u]) {
            if(v != p) dfs(v, u, d + 1);
        }
    }
    // 祖先木を構築する．O(|V|*log|V|).
    void build() {
        for(auto &a : m_par) std::fill(a.begin(), a.end(), -1);
        std::fill(m_depth.begin(), m_depth.end(), -1);
        dfs(m_rt, -1, 0);
        for(int k = 1; k < m_h; ++k) {
            for(int v = 0; v < size(); ++v) {
                if(m_par[v][k - 1] != -1) m_par[v][k] = m_par[m_par[v][k - 1]][k - 1];
            }
        }
        m_update = false;
    }

public:
    LCA() : LCA(0) {}
    explicit LCA(size_t vn, int rt = 0) : LCA(Graph(vn), rt) {}
    explicit LCA(const Graph &g, int rt = 0) : m_vn(g.size()), m_h(1), m_rt(rt), m_g(g), m_depth(g.size()), m_update(true) {
        assert(0 <= rt and rt < m_vn);
        while((1 << m_h) < m_vn) m_h++;
        m_par.assign(m_vn, std::vector<int>(m_h));
    }

    // ノード数を返す．
    int size() const { return m_vn; }
    // 根番号にアクセスする．
    int root(int rt = -1) {
        if(rt == -1) return m_rt;
        assert(0 <= rt and rt < size());
        m_update = true;
        return m_rt = rt;
    }
    // ノードuとvに辺を繋げる．
    void add_edge(int u, int v) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        m_g[u].push_back(v);
        m_g[v].push_back(u);
        m_update = true;
    }
    // 木上のノードuとvの最も近い共通の先祖を求める．O(log|V|).
    int lca(int u, int v) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        if(m_update) build();
        if(m_depth[u] == -1 or m_depth[v] == -1) return -1;  // 非連結．
        if(m_depth[u] > m_depth[v]) std::swap(u, v);
        for(int k = 0; k < m_h; ++k) {
            if((m_depth[v] - m_depth[u]) & (1 << k)) v = m_par[v][k];  // 同じ深さに合わせる．
        }
        if(u == v) return u;
        for(int k = m_h - 1; k >= 0; --k) {
            if(m_par[u][k] != m_par[v][k]) u = m_par[u][k], v = m_par[v][k];  // 異なったら根に近づける．
        }
        return m_par[u][0];
    }
    // ノードvの深さを返す．
    int depth(int v) {
        assert(0 <= v and v < size());
        if(m_update) build();
        return m_depth[v];
    }
    // ノードuとvの距離を求める．O(log|V|).
    int distance(int u, int v) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        if(m_update) build();
        if(m_depth[u] == -1 or m_depth[v] == -1) return -1;  // 非連結．
        return m_depth[u] + m_depth[v] - 2 * m_depth[lca(u, v)];
    }
};

}  // namespace algorithm

#endif
