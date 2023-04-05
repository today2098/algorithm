#ifndef ALGORITHlow_LINK_HPP
#define ALGORITHlow_LINK_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

class LowLink {
    using Graph = std::vector<std::vector<int> >;

    int m_vn;                                 // m_vn:=(頂点数).
    Graph m_g;                                // m_g[v][]:=(頂点vの隣接リスト).
    std::vector<int> m_aps;                   // m_aps[]:=(関節点のリスト). Articulations points.
    std::vector<std::pair<int, int> > m_brs;  // m_brs[]:=(橋のリスト). Bridges.

    void dfs(int u, int parent, std::vector<int> &ord, std::vector<int> &low, int &now) {
        ord[u] = low[u] = now++;
        int degree = 0;      // DFS木での頂点uにおける葉方向への出次数．
        bool is_ap = false;  // 頂点uが関節点か否か．
        for(auto v : m_g[u]) {
            if(v == parent) continue;
            if(ord[v] == -1) {  // 頂点vが未訪問のとき．
                degree++;
                dfs(v, u, ord, low, now);
                low[u] = std::min(low[u], low[v]);
                if(ord[u] < low[v]) {  // 辺u-vが橋のとき．
                    if(u < v) m_brs.emplace_back(u, v);
                    else m_brs.emplace_back(v, u);
                }
                if(parent != -1 and ord[u] <= low[v]) is_ap = true;  // 根以外で関節点のとき．
            } else {                                                 // 辺u-vが後退辺のとき．
                low[u] = std::min(low[u], ord[v]);
            }
        }
        if(parent == -1 and degree > 1) is_ap = true;  // 根が関節点のとき．
        if(is_ap) m_aps.push_back(u);
    }

public:
    LowLink() : LowLink(0) {}
    explicit LowLink(size_t vn) : m_vn(vn), m_g(vn) {}
    explicit LowLink(const Graph &g) : m_vn(g.size()), m_g(g) {}

    // 頂点数を返す．
    int size() const { return m_vn; }
    // 無向辺を張る．
    void add_edge(int u, int v) {
        assert(0 <= u and u < size());
        assert(0 <= v and v < size());
        m_g[u].push_back(v);
        m_g[v].push_back(u);
    }
    // 無向グラフの橋と関節点を求める．O(|V|+|E|).
    void lowlink() {
        m_aps.clear();
        m_brs.clear();
        // ord[v]:=(DFS木における頂点vの行きかけ順序).
        // low[v]:=(DFS木において，頂点vから葉方向に0回以上，後退辺を高々1回用いて到達できる頂点wのord[w]の最小値).
        std::vector<int> ord(size(), -1), low(size());
        int now = 0;
        for(int v = 0; v < size(); ++v) {
            if(ord[v] == -1) dfs(v, -1, ord, low, now);
        }
        std::sort(m_aps.begin(), m_aps.end());
        std::sort(m_brs.begin(), m_brs.end());
    }
    // 関節点のリストを参照する．
    const std::vector<int> &get_points() const { return m_aps; }
    // 橋のリストを参照する．
    const std::vector<std::pair<int, int> > &get_bridges() const { return m_brs; }
};

}  // namespace algorithm

#endif

/*
参考文献
- o-treetree, グラフの関節点と橋を求めて再帰DFSを知る，HatenaBlog, https://o-treetree.hatenablog.com/entry/2020/06/08/231258（参照2022.9.13）．
*/
