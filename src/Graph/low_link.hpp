#ifndef ALGORITHM_LOW_LINK_HPP
#define ALGORITHM_LOW_LINK_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

class LowLink {
    int m_vn;                                 // m_vn:=(頂点数).
    std::vector<std::vector<int> > m_g;       // m_g[v][]:=(頂点vの隣接リスト).
    std::vector<int> m_ord;                   // m_ord[v]:=(DFS木における頂点vの行きかけ順序).
    std::vector<int> m_low;                   // m_low[v]:=(DFS木において，頂点vから葉方向に0回以上，後退辺を高々1回用いて到達できる頂点wのord[w]の最小値).
    std::vector<int> m_aps;                   // m_aps[]:=(関節点のリスト). Articulations points.
    std::vector<std::pair<int, int> > m_brs;  // m_brs[]:=(橋のリスト). Bridges.

    void dfs(int u, int par, int &cnt) {
        m_ord[u] = m_low[u] = cnt++;
        int degree = 0;      // DFS木での頂点uにおける葉方向への出次数．
        bool is_ap = false;  // 頂点uが関節点か否か．
        for(auto v : m_g[u]) {
            if(m_ord[v] == -1) {  // 頂点vが未訪問のとき．
                degree++;
                dfs(v, u, cnt);
                m_low[u] = std::min(m_low[u], m_low[v]);
                if(m_ord[u] < m_low[v]) {  // 辺u-vが橋のとき．
                    if(u < v) m_brs.emplace_back(u, v);
                    else m_brs.emplace_back(v, u);
                }
                if(par != -1 and m_ord[u] <= m_low[v]) is_ap = true;  // 根以外で関節点のとき．
            } else if(v != par) {                                     // 辺u-vが後退辺のとき．
                m_low[u] = std::min(m_low[u], m_ord[v]);
            }
        }
        if(par == -1 and degree > 1) is_ap = true;  // 根が関節点のとき．
        if(is_ap) m_aps.push_back(u);
    }

public:
    LowLink() : LowLink(0) {}
    explicit LowLink(size_t vn) : m_vn(vn), m_g(vn), m_ord(vn), m_low(vn) {}

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
    void calc() {
        std::fill(m_ord.begin(), m_ord.end(), -1);
        m_aps.clear();
        m_brs.clear();
        int cnt = 0;
        for(int v = 0; v < size(); ++v) {
            if(m_ord[v] == -1) dfs(v, -1, cnt);
        }
        std::sort(m_aps.begin(), m_aps.end());
        std::sort(m_brs.begin(), m_brs.end());
    }
    // 関節点のリストを参照する．
    const std::vector<int> &get_aps() const { return m_aps; }
    // 橋のリストを参照する．
    const std::vector<std::pair<int, int> > &get_brs() const { return m_brs; }
};

}  // namespace algorithm

#endif

/*
参考文献
- o-treetree, グラフの関節点と橋を求めて再帰DFSを知る，HatenaBlog, https://o-treetree.hatenablog.com/entry/2020/06/08/231258（参照2022.9.13）．
*/
