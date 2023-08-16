#ifndef ALGORITHM_TOPOLOGICAL_SORT_HPP
#define ALGORITHM_TOPOLOGICAL_SORT_HPP 1

#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

class TopologicalSort {
    int m_n;                             // m_n:=(頂点数).
    std::vector<std::vector<int> > m_g;  // m_g[v]:=(頂点vの隣接リスト).

public:
    TopologicalSort() : TopologicalSort(0) {}
    explicit TopologicalSort(size_t n) : m_n(n), m_g(n) {}

    // 頂点数を返す．
    int order() const { return m_n; }
    // 有向辺を張る．
    void add_edge(int from, int to) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].push_back(to);
    }
    // 任意のトポロジカルソートの解を求める．O(|E|).
    std::vector<int> topological_sort() const {
        std::vector<int> res;
        std::vector<int> deg(order(), 0);  // deg[v]:=(頂点vの入次数).
        for(const std::vector<int> &edges : m_g) {
            for(int to : edges) deg[to]++;
        }
        std::queue<int> que;
        for(int i = 0; i < order(); ++i) {
            if(deg[i] == 0) que.push(i);
        }
        while(!que.empty()) {
            int u = que.front();
            que.pop();
            res.push_back(u);
            for(int v : m_g[u]) {
                if(--deg[v] == 0) que.push(v);
            }
        }
        if(res.size() != order()) return std::vector<int>(0);  // 閉路がある場合．
        return res;
    }
    // 考え得るトポロジカルソートの解を数え上げる．頂点数の上限目安は20程度．O((2^N)*N*N).
    long long count_up() const {
        bool ng[order()][order()] = {};
        for(int from = 0; from < order(); ++from) {
            for(int to : m_g[from]) ng[to][from] = true;
        }
        std::vector<long long> dp(1 << order(), 0);  // bitDP.
        dp[0] = 1;
        for(int bit = 0; bit < (1 << order()); ++bit) {
            for(int i = 0; i < order(); ++i) {
                if(!(bit >> i & 1)) {
                    bool ok = true;
                    for(int j = 0; j < order(); ++j) {
                        if(bit >> j & 1 and ng[j][i]) ok = false;
                    }
                    if(ok) dp[bit | 1 << i] += dp[bit];
                }
            }
        }
        return dp[(1 << order()) - 1];
    }
};

}  // namespace algorithm

#endif
