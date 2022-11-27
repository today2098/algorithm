#ifndef ALGORITHM_BELLMAN_FORD_HPP
#define ALGORITHM_BELLMAN_FORD_HPP 1

#include <algorithm>
#include <cassert>
#include <vector>

namespace algorithm {

template <typename T>
class BellmanFord {
    struct Edge {
        int to;
        T cost;
    };

    int m_vn;                             // m_vn:=(ノード数).
    std::vector<std::vector<Edge> > m_g;  // m_g[v][]:=(ノードvが始点である有向辺のリスト).
    std::vector<T> m_d;                   // m_d[t]:=(ノードsからtへの最短距離).
    std::vector<int> m_pre;               // m_pre[t]:=(ノードtを訪問する直前のノード番号). 逆方向経路．
    T m_inf;

public:
    BellmanFord() : BellmanFord(0) {}
    explicit BellmanFord(size_t vn, T inf = 1e9) : m_vn(vn), m_g(vn), m_d(vn, inf), m_pre(vn, -1), m_inf(inf) {}

    // ノード数を返す．
    int size() const { return m_vn; }
    T infinity() const { return m_inf; }
    // 重み付き有向辺を張る．
    void add_edge(int from, int to, T cost) {
        assert(0 <= from and from < size());
        assert(0 <= to and to < size());
        m_g[from].push_back((Edge){to, cost});
    }
    // グラフ全体から負閉路を検出する．O(|V|*|E|).
    bool find_negative_cycle() const {
        std::vector<T> nd(size(), 0);
        for(int i = 0; i < size(); ++i) {
            bool update = false;
            for(int v = 0; v < size(); ++v) {
                for(const Edge &e : m_g[v]) {
                    if(nd[e.to] > nd[v] + e.cost) {
                        nd[e.to] = nd[v] + e.cost;
                        update = true;
                    }
                }
            }
            if(!update) break;
            if(i == size() - 1) return true;  // 負閉路あり．
        }
        return false;
    }
    // ノードsから各ノードへの最短距離を求める．O(|V|*|E|).
    void bellman_ford(int s) {
        assert(0 <= s and s < size());
        std::fill(m_d.begin(), m_d.end(), infinity());
        m_d[s] = 0;
        std::fill(m_pre.begin(), m_pre.end(), -1);
        for(int i = 0; i < 2 * size(); ++i) {
            bool update = false;
            for(int v = 0; v < size(); ++v) {
                if(m_d[v] == infinity()) continue;
                for(const Edge &e : m_g[v]) {
                    if(m_d[e.to] == -infinity()) continue;
                    if(m_d[e.to] > m_d[v] + e.cost) {
                        if(i < size() - 1) {
                            m_d[e.to] = m_d[v] + e.cost;
                            m_pre[e.to] = v;
                        } else {
                            m_d[e.to] = -infinity();
                        }
                        update = true;
                    }
                }
            }
            if(!update) break;
        }
    }
    // ノードsからtへの最短距離を返す．
    T distance(int t) const {
        assert(0 <= t and t < size());
        return m_d[t];
    }
    // ノードsからtへの最短経路を復元する．
    std::vector<int> get_path(int t) const {
        assert(0 <= t and t < size());
        assert(-infinity() < m_d[t] and m_d[t] < infinity());
        std::vector<int> path;
        for(; t != -1; t = m_pre[t]) path.push_back(t);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

}  // namespace algorithm

#endif
