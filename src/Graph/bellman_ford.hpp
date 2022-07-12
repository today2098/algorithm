#ifndef ALGORITHM_BELLMAN_FORD_HPP
#define ALGORITHM_BELLMAN_FORD_HPP 1

#include <algorithm>  // for fill() and reverse().
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
    std::vector<T> m_d;                   // m_d[v]:=(ノードsからvへの最短距離).
    std::vector<int> m_pre;               // m_pre[v]:=(ノードvを訪問する直前のノード番号). 逆方向経路．
    T m_inf;

public:
    // constructor.
    BellmanFord() : BellmanFord(0) {}
    explicit BellmanFord(size_t vn, T inf = 1e9) : m_vn(vn), m_g(vn), m_d(vn, inf), m_pre(vn, -1), m_inf(inf) {}

    int size() const { return m_vn; }  // ノード数を返す．
    T infinity() const { return m_inf; }
    void add_edge(int from, int to, T cost) {  // 重み付き有向辺を張る．
        assert(0 <= from and from < m_vn);
        assert(0 <= to and to < m_vn);
        m_g[from].push_back((Edge){to, cost});
    }
    bool find_negative_cycle() const {  // グラフ全体から負閉路を検出する．O(|V|*|E|).
        std::vector<T> nd(m_vn, 0);
        for(int i = 0; i < m_vn; ++i) {
            bool update = false;
            for(int v = 0; v < m_vn; ++v) {
                for(const Edge &e : m_g[v]) {
                    if(nd[e.to] > nd[v] + e.cost) {
                        nd[e.to] = nd[v] + e.cost;
                        update = true;
                    }
                }
            }
            if(!update) break;
            if(i == m_vn - 1) return true;  // 負閉路あり．
        }
        return false;
    }
    void bellman_ford(int s) {  // ノードsから各ノードへの最短距離を求める．O(|V|*|E|).
        assert(0 <= s and s < m_vn);
        std::fill(m_d.begin(), m_d.end(), m_inf);
        m_d[s] = 0;
        std::fill(m_pre.begin(), m_pre.end(), -1);
        for(int i = 0; i < 2 * m_vn; ++i) {
            bool update = false;
            for(int v = 0; v < m_vn; ++v) {
                if(m_d[v] == m_inf) continue;
                for(const Edge &e : m_g[v]) {
                    if(m_d[e.to] == -m_inf) continue;
                    if(m_d[e.to] > m_d[v] + e.cost) {
                        if(i < m_vn - 1) {
                            m_d[e.to] = m_d[v] + e.cost;
                            m_pre[e.to] = v;
                        } else {
                            m_d[e.to] = -m_inf;
                        }
                        update = true;
                    }
                }
            }
            if(!update) break;
        }
    }
    T distance(int v) const {  // ノードsからvへの最短距離を返す．
        assert(0 <= v and v < m_vn);
        return m_d[v];
    }
    std::vector<int> get_path(int v) const {  // ノードsからvへの最短経路を復元する．
        assert(0 <= v and v < m_vn);
        assert(-m_inf < m_d[v] and m_d[v] < m_inf);
        std::vector<int> path;
        for(; v != -1; v = m_pre[v]) path.push_back(v);
        std::reverse(path.begin(), path.end());
        return path;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_BELLMAN_FORD_HPP
