#ifndef LOWEST_COMMON_ANCESTOR_HPP
#define LOWEST_COMMON_ANCESTOR_HPP 1

#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>
#include <vector>

namespace algorithm {

// 最近共通祖先 (LCA: Lowest Common Ancestor)．
template <typename T = int>  // T:Type of cost.
class LCA {
    int m_vn;                                           // m_vn:=(ノード数).
    int m_l;                                            // m_l:=ceiling(log2(m_vn)).
    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(ノードvの隣接リスト). pair of (to, cost).
    std::vector<std::vector<int> > m_par;               // m_par[v][k]:=(ノードvから2^k回辿って到達する親ノード番号). 親がいない場合は-1．
    std::vector<int> m_depth;                           // m_depth[v]:=(ノードvの深さ). 根に連結していない場合は-1．
    std::vector<T> m_dist;                              // m_dist[v]:=(根からノードvまでの距離).
    std::vector<int> m_ord;                             // m_ord[v]:=(DFS木におけるノードvの行きかけ順序).

    void dfs(int u, int parent, int depth, T distance, int &now) {
        assert(m_ord[u] == -1);
        m_ord[u] = now++;
        m_par[u][0] = parent;
        m_depth[u] = depth;
        m_dist[u] = distance;
        for(const auto &[v, cost] : m_g[u]) {
            if(v != parent) dfs(v, u, depth + 1, distance + cost, now);
        }
    }

public:
    LCA() : LCA(0) {}
    explicit LCA(size_t vn) : m_vn(vn), m_l(0), m_g(vn), m_depth(vn, -1), m_dist(vn, 0), m_ord(vn, -1) {
        while((1 << m_l) < m_vn) m_l++;
        m_par.assign(m_vn, std::vector<int>(m_l, -1));
    }

    // ノード数を返す．
    int order() const { return m_vn; }
    // ノードuとvに辺を繋げる．
    void add_edge(int u, int v, T cost = 0) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].emplace_back(v, cost);
        m_g[v].emplace_back(u, cost);
    }
    // 祖先木を構築する．O(|V|*log|V|).
    void build(int root = 0) {
        assert(0 <= root and root < order());
        for(std::vector<int> &v : m_par) std::fill(v.begin(), v.end(), -1);
        std::fill(m_depth.begin(), m_depth.end(), -1);
        std::fill(m_dist.begin(), m_dist.end(), 0);
        std::fill(m_ord.begin(), m_ord.end(), -1);
        int now = 0;
        dfs(root, -1, 0, 0, now);
        for(int k = 0; k < m_l - 1; ++k) {
            for(int v = 0; v < order(); ++v) {
                if(m_par[v][k] != -1) m_par[v][k + 1] = m_par[m_par[v][k]][k];
            }
        }
    }
    // ノードvの祖先をk代遡る．O(log|V|).
    int up(int v, int k) const {
        assert(0 <= v and v < order());
        assert(0 <= k and k <= order() - 1);
        for(int i = 0; i < m_l; ++i) {
            if(k >> i & 1) {
                v = m_par[v][i];
                if(v == -1) return -1;
            }
        }
        return v;
    }
    // 木上のノードuとvの最も近い共通の先祖を求める．O(log|V|).
    int lca(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(m_ord[u] == -1 or m_ord[v] == -1) return -1;  // 非連結．
        if(m_depth[u] > m_depth[v]) std::swap(u, v);
        v = up(v, m_depth[v] - m_depth[u]);  // 同じ深さに合わせる．
        if(u == v) return u;
        for(int k = m_l - 1; k >= 0; --k) {
            if(m_par[u][k] != m_par[v][k]) u = m_par[u][k], v = m_par[v][k];  // 異なったら根に近づける．
        }
        return m_par[u][0];
    }
    // ノードu, v間の長さを求める．O(log|V|).
    int length(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(m_ord[u] == -1 or m_ord[v] == -1) return -1;  // 非連結．
        return m_depth[u] + m_depth[v] - 2 * m_depth[lca(u, v)];
    }
    // ノードu, v間の距離を求める．O(log|V|).
    T distance(int u, int v) const {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        if(m_ord[u] == -1 or m_ord[v] == -1) return 0;  // 非連結．
        return m_dist[u] + m_dist[v] - 2 * m_dist[lca(u, v)];
    }
    // 木の座標圧縮．O(K*logN).
    std::pair<int, std::vector<std::vector<int> > > auxiliary_tree(std::vector<int> &vs) const {
        assert(std::find_if(vs.begin(), vs.end(), [&](int v) -> bool {
                   return !(0 <= v and v < order());
               }) == vs.end());
        std::vector<std::vector<int> > tree(order());
        auto comp = [&](int u, int v) -> bool {
            return m_ord[u] < m_ord[v];
        };
        std::sort(vs.begin(), vs.end(), comp);
        vs.erase(vs.begin(), std::lower_bound(vs.begin(), vs.end(), 0, [&](int lv, int rv) -> bool {
                     return m_ord[lv] < rv;
                 }));
        const int n = vs.size();
        if(n == 0) return {-1, tree};
        std::stack<int> st;
        st.push(vs[0]);
        for(int i = 1; i < n; ++i) {
            int w = lca(vs[i - 1], vs[i]);
            if(w != vs[i - 1]) {
                int v = st.top();
                st.pop();
                while(!st.empty() and m_depth[st.top()] > m_depth[w]) {
                    tree[st.top()].push_back(v);
                    tree[v].push_back(st.top());
                    v = st.top();
                    st.pop();
                }
                if(st.empty() or st.top() != w) {
                    st.push(w);
                    vs.push_back(w);
                }
                tree[w].push_back(v);
                tree[v].push_back(w);
            }
            st.push(vs[i]);
        }
        while(st.size() > 1) {
            int v = st.top();
            st.pop();
            tree[st.top()].push_back(v);
            tree[v].push_back(st.top());
        }
        std::sort(vs.begin(), vs.end(), comp);
        return {st.top(), tree};  // pair of (root, tree).
    }
};

}  // namespace algorithm

#endif
