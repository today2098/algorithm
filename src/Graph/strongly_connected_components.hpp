/**
 * @brief 強連結成分分解
 * @docs docs/Graph/strongly_connected_components.md
 */

#ifndef ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP
#define ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP 1

#include <algorithm>
#include <cassert>
#include <stack>
#include <utility>
#include <vector>

namespace algorithm {

// 強連結成分分解．
class SCC {
    std::vector<std::vector<int> > m_g;  // m_g[v][]:=(ノードvの隣接リスト).

public:
    SCC() : SCC(0) {}
    explicit SCC(int vn) : m_g(vn) {}

    // ノード数を返す．
    int order() const { return m_g.size(); }
    // 有向辺を張る．
    void add_edge(int from, int to) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].push_back(to);
    }
    // return pair of (# of SCCs, SCC id of each nodes).
    std::pair<int, std::vector<int> > scc() const {
        int num_sccs = 0;               // num_sccs:=(SCCsの数).
        std::vector<int> ids(order());  // ids[v]:=(ノードvが属するSCCのID).
        // ord[v]:=(DFS木におけるノードvの行きがけ順序).
        // low[v]:=(DFS木において，ノードvから葉方向に0回以上，後退辺を高々1回用いて到達できるノードwでのord[w]の最小値).
        std::vector<int> ord(order(), -1), low(order());
        int now = 0;
        std::stack<int> visited;
        auto dfs = [&](auto self, int u) -> void {
            ord[u] = low[u] = now++;
            visited.push(u);
            for(int to : m_g[u]) {
                if(ord[to] == -1) {
                    self(self, to);
                    low[u] = std::min(low[u], low[to]);
                } else {
                    low[u] = std::min(low[u], ord[to]);
                }
            }
            if(low[u] == ord[u]) {
                while(true) {
                    int v = visited.top();
                    visited.pop();
                    ord[v] = order();  // inf.
                    ids[v] = num_sccs;
                    if(v == u) break;
                }
                num_sccs++;
            }
        };
        for(int v = 0, n = order(); v < n; ++v) {
            if(ord[v] == -1) dfs(dfs, v);
        }
        return {num_sccs, ids};
    }
    // 有向グラフを強連結成分分解する．O(|V|+|E|).
    std::vector<std::vector<int> > decompose() const {
        const auto &&[num_sccs, ids] = scc();
        std::vector<std::vector<int> > sccs(num_sccs);
        for(int v = 0, n = order(); v < n; ++v) sccs[ids[v]].push_back(v);
        return sccs;
    }
};

}  // namespace algorithm

#endif
