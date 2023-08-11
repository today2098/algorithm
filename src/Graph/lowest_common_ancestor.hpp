#ifndef LOWEST_COMMON_ANCESTOR_HPP
#define LOWEST_COMMON_ANCESTOR_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

// 最近共通祖先 (LCA: Lowest Common Ancestor)．
class LCA {
    int m_vn;                              // m_vn:=(ノード数).
    int m_h;                               // m_h:=ceiling(log2(m_vn)).
    std::vector<std::vector<int> > m_g;    // m_g[v][]:=(ノードvの隣接リスト).
    std::vector<std::vector<int> > m_par;  // m_par[v][k]:=(ノードvから2^k回辿って到達する親ノード番号). 親がいない場合は-1．
    std::vector<int> m_depth;              // m_depth[v]:=(ノードvの深さ). 根に連結していない場合は-1．

    void dfs(int u, int parent, int d) {
        assert(m_depth[u] == -1);
        m_par[u][0] = parent;
        m_depth[u] = d;
        for(int v : m_g[u]) {
            if(v != parent) dfs(v, u, d + 1);
        }
    }

public:
    LCA() : LCA(0) {}
    explicit LCA(size_t vn) : m_vn(vn), m_h(1), m_g(vn), m_depth(vn, -1) {
        while((1 << m_h) < m_vn) m_h++;
        m_par.assign(m_vn, std::vector<int>(m_h, -1));
    }

    // ノード数を返す．
    int order() const { return m_vn; }
    // ノードuとvに辺を繋げる．
    void add_edge(int u, int v) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].push_back(v);
        m_g[v].push_back(u);
    }
    // 祖先木を構築する．O(|V|*log|V|).
    void build(int rt = 0) {
        assert(0 <= rt and rt < order());
        for(std::vector<int> &v : m_par) std::fill(v.begin(), v.end(), -1);
        std::fill(m_depth.begin(), m_depth.end(), -1);
        dfs(rt, -1, 0);
        for(int k = 1; k < m_h; ++k) {
            for(int v = 0; v < order(); ++v) {
                if(m_par[v][k - 1] != -1) m_par[v][k] = m_par[m_par[v][k - 1]][k - 1];
            }
        }
    }
    // 木上のノードuとvの最も近い共通の先祖を求める．O(log|V|).
    int lca(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(depth(u) == -1 or depth(v) == -1) return -1;  // 非連結．
        if(depth(u) > depth(v)) std::swap(u, v);
        for(int k = 0; k < m_h; ++k) {
            if((depth(v) - depth(u)) & (1 << k)) v = m_par[v][k];  // 同じ深さに合わせる．
        }
        if(u == v) return u;
        for(int k = m_h - 1; k >= 0; --k) {
            if(m_par[u][k] != m_par[v][k]) u = m_par[u][k], v = m_par[v][k];  // 異なったら根に近づける．
        }
        return m_par[u][0];
    }
    // ノードvの深さを返す．
    int depth(int v) const {
        assert(0 <= v and v < order());
        return m_depth[v];
    }
    // ノードuとvの距離を求める．O(log|V|).
    int distance(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(depth(u) == -1 or depth(v) == -1) return -1;  // 非連結．
        return depth(u) + depth(v) - 2 * depth(lca(u, v));
    }
};

}  // namespace algorithm

#endif
