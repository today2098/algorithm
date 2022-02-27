#ifndef ALGORITHM_LOW_LINK_HPP
#define ALGORITHM_LOW_LINK_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

class LowLink {
    int vn;                                 // vn:=(頂点数).
    std::vector<std::vector<int> > g;       // g[v][]:=(頂点vの隣接リスト).
    std::vector<int> ord;                   // ord[v]:=(頂点vのDFSでの行きかけ順序).
    std::vector<int> low;                   // low[v]:=(頂点vから木を降りる，または後退辺を高々1回用いて到達できる頂点wについて，ord[w]の最小値).
    std::vector<std::pair<int, int> > brs;  // brs[]:=(橋のリスト). Bridges.
    std::vector<int> aps;                   // aps[]:=(関節点のリスト). Articulations points.

    void reset() {
        std::fill(ord.begin(), ord.end(), -1);
        brs.clear(), aps.clear();
    }
    void dfs(int u, int par, int &cnt) {
        ord[u] = low[u] = cnt++;
        int degree = 0;      // DFS木での頂点vの出次数．
        bool is_ap = false;  // 頂点uが関節点か否か．
        for(int v : g[u]) {
            if(ord[v] == -1) {  // 頂点vが未訪問のとき．
                degree++;
                dfs(v, u, cnt);
                low[u] = std::min(low[u], low[v]);
                if(ord[u] < low[v]) {  // 辺u-vが橋のとき．
                    if(u < v)
                        brs.emplace_back(u, v);
                    else
                        brs.emplace_back(v, u);
                }
                if(par != -1 and ord[u] <= low[v]) is_ap = true;  // 根以外で関節点のとき．
            } else if(v != par) {                                 // 辺u-vが後退辺のとき．
                low[u] = std::min(low[u], ord[v]);
            }
        }
        if(par == -1 and degree > 1) is_ap = true;  // 根が関節点のとき．
        if(is_ap) aps.push_back(u);
    }

public:
    // constructor.
    LowLink() : LowLink(0) {}
    explicit LowLink(std::size_t vn_) : vn(vn_), g(vn_), ord(vn_), low(vn_) {}

    int size() const { return vn; }  // 頂点数を返す．
    void add_edge(int u, int v) {    // 無向辺を張る．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    void calc() {  // グラフの橋と関節点を求める．O(|V|+|E|).
        reset();
        int cnt = 0;
        for(int v = 0; v < vn; ++v) {
            if(ord[v] == -1) dfs(v, -1, cnt);
        }
        std::sort(brs.begin(), brs.end());
        std::sort(aps.begin(), aps.end());
    }
    const std::vector<std::pair<int, int> > &get_brs() const { return brs; }
    const std::vector<int> &get_aps() const { return aps; }
};

}  // namespace algorithm

#endif  // ALGORITHM_LOW_LINK_HPP
