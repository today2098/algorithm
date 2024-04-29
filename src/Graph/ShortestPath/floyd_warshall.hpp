#ifndef ALGORITHM_FLOYD_WARSHALL_HPP
#define ALGORITHM_FLOYD_WARSHALL_HPP 1

/**
 * @brief Floyd–Warshall Algorithm（全点対間最短経路）
 * @docs docs/Graph/ShortestPath/floyd_warshall.md
 */

#include <algorithm>
#include <cassert>
#include <limits>
#include <vector>

namespace algorithm {

template <typename T>
class FloydWarshall {
    int m_vn;                           // m_vn:=(ノード数).
    std::vector<std::vector<T> > m_dp;  // m_dp[u][v]:=(ノードu-v間の最短距離).

public:
    FloydWarshall() {}
    explicit FloydWarshall(size_t vn) : m_vn(vn), m_dp(vn, std::vector<T>(vn, infinity())) {}

    static constexpr T infinity() { return std::numeric_limits<T>::max(); }
    // ノード数を返す．
    int order() const { return m_vn; }
    // 重み付き有向辺を張る．
    void add_edge(int from, int to, T cost) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_dp[from][to] = cost;
    }
    // グラフ上の全頂点対間について最短距離を求める．O(|V|^3).
    void floyd_warshall() {
        for(int v = 0; v < order(); ++v) m_dp[v][v] = 0;
        for(int k = 0; k < order(); ++k) {
            for(int u = 0; u < order(); ++u) {
                for(int v = 0; v < order(); ++v) m_dp[u][v] = std::min(m_dp[u][v], m_dp[u][k] + m_dp[k][v]);
            }
        }
    }
    // グラフ全体から負閉路を検出する．O(|V|).
    bool find_negative_cycle() const {
        for(int v = 0; v < order(); ++v) {
            if(m_dp[v][v] < 0) return true;  // 負閉路あり．
        }
        return false;  // 負閉路なし．
    }
    // ノードsからtへの最短距離を返す．
    T distance(int s, int t) const {
        assert(0 <= s and s < order());
        assert(0 <= t and t < order());
        return m_dp[s][t];
    }
};

}  // namespace algorithm

#endif
