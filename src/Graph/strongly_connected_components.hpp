#ifndef ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP
#define ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP 1

#include <cassert>
#include <stack>
#include <vector>

namespace algorithm {

// 強連結成分分解 (SCC:Strongly Connected Components)．
class SCC {
    int m_vn;                            // m_vn:=(ノード数).
    std::vector<std::vector<int> > m_g;  // m_g[v][]:=(ノードvの隣接リスト).

    int infinity() const { return 1e9; }

public:
    SCC() : SCC(0) {}
    explicit SCC(int vn) : m_vn(vn), m_g(vn) {}

    // ノード数を返す．
    int size() const { return m_vn; }
    // 有向辺を張る．
    void add_edge(int from, int to) {
        assert(0 <= from and from < size());
        assert(0 <= to and to < size());
        m_g[from].push_back(to);
    }
    // return pair of (# of SCCs, SCC id of each nodes).
    std::pair<int, std::vector<int> > get_scc_id() const {
        // ord[v]:=(DFS木におけるノードvの行きがけ順序), low[v]:=(DFS木におけるノードvのlowlink).
        std::vector<int> ord(m_vn, -1), low(m_vn);
        std::vector<int> ids(m_vn);  // ids[v]:=(ノードvが属するSCCのID).
        int num_sccs = 0;            // num_sccs:=(SCCsの数).
        int now_ord = 0;
        std::stack<int> visited;
        auto dfs = [&](auto self, int u) -> void {
            ord[u] = low[u] = now_ord++;
            visited.push(u);
            for(auto to : m_g[u]) {
                if(ord[to] == -1) {
                    self(self, to);
                    low[u] = std::min(low[u], low[to]);
                } else {
                    low[u] = std::min(low[u], ord[to]);
                }
            }
            if(low[u] == ord[u]) {
                while(true) {
                    auto v = visited.top();
                    visited.pop();
                    ord[v] = infinity();
                    ids[v] = num_sccs;
                    if(v == u) break;
                }
                num_sccs++;
            }
        };
        for(int v = 0; v < size(); ++v) {
            if(ord[v] == -1) dfs(dfs, v);
        }
        return {num_sccs, ids};
    }
    // 有向グラフを強連結成分分解する．O(|V|+|E|).
    std::vector<std::vector<int> > decompose() const {
        const auto &&[num_sccs, ids] = get_scc_id();
        std::vector<std::vector<int> > sccs(num_sccs);
        for(int v = 0; v < size(); ++v) sccs[ids[v]].push_back(v);
        return sccs;
    }
};

}  // namespace algorithm

#endif
