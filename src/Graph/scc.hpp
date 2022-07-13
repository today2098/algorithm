#ifndef ALGORITHM_SCC_HPP
#define ALGORITHM_SCC_HPP 1

#include <algorithm>
#include <cassert>
#include <stack>
#include <vector>

namespace algorithm {

// 強連結成分分解 (SCC:Strongly Connected Components)．
class SCC {
    int m_vn;                            // m_vn:=(ノード数).
    std::vector<std::vector<int> > m_g;  // m_g[v][]:=(頂点vの隣接リスト).

public:
    SCC() : SCC(0) {}
    explicit SCC(int vn) : m_vn(vn), m_g(vn) {}

    int size() const { return m_vn; }  // 頂点数を返す．
    void add_edge(int from, int to) {  // 有向辺を張る．
        assert(0 <= from and from < m_vn);
        assert(0 <= to and to < m_vn);
        m_g[from].push_back(to);
    }
    std::pair<int, std::vector<int> > scc_ids() {  // return pair of (# of scc, scc id).
        std::vector<int> ord(m_vn, -1), low(m_vn), ids(m_vn);
        int now_ord = 0, num_group = 0;
        std::stack<int> visited;
        auto dfs = [&](auto self, int v) -> void {
            ord[v] = low[v] = now_ord++;
            visited.push(v);
            for(auto to : m_g[v]) {
                if(ord[to] == -1) {
                    self(self, to);
                    low[v] = std::min(low[v], low[to]);
                } else {
                    low[v] = std::min(low[v], ord[to]);
                }
            }
            if(low[v] == ord[v]) {
                while(true) {
                    auto u = visited.top();
                    visited.pop();
                    ord[u] = m_vn;
                    ids[u] = num_group;
                    if(u == v) break;
                }
                num_group++;
            }
        };
        for(int v = 0; v < m_vn; ++v) {
            if(ord[v] == -1) dfs(dfs, v);
        }
        for(auto &x : ids) x = num_group - 1 - x;
        return {num_group, ids};
    }
    std::vector<std::vector<int> > scc() {  // 有向グラフを強連結成分分解する．
        const auto &&[num_group, ids] = scc_ids();
        std::vector<int> counts(num_group, 0);
        for(auto x : ids) counts[x]++;
        std::vector<std::vector<int> > groups(num_group);
        for(int i = 0; i < num_group; ++i) groups[i].reserve(counts[i]);
        for(int v = 0; v < m_vn; ++v) groups[ids[v]].push_back(v);
        return groups;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_SCC_HPP
