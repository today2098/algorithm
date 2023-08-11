#ifndef ALGORITHM_PRIM_HPP
#define ALGORITHM_PRIM_HPP 1

#include <algorithm>
#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename T>
class Prim {
    int m_vn;                                           // m_vn:=(ノード数).
    std::vector<std::vector<std::pair<int, T> > > m_g;  // m_g[v][]:=(ノードvが始点である重み付き有向辺のリスト). pair of (to, cost).

public:
    Prim() : Prim(0) {}
    explicit Prim(size_t vn) : m_vn(vn), m_g(vn) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    // 重み付き無向辺を張る．
    void add_edge(int u, int v, T cost) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].emplace_back(v, cost);
        m_g[v].emplace_back(u, cost);
    }
    // 重み付き無向連結グラフにおける最小全域木のコストを求める．O(|E|*log|V|).
    T prim(int rt = 0) {
        assert(0 <= rt and rt < order());
        T res = 0;
        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int> >, std::greater<std::pair<T, int> > > pque;
        pque.emplace(0, rt);
        bool seen[order()] = {};
        while(!pque.empty()) {
            auto [cost, u] = pque.top();
            pque.pop();
            if(seen[u]) continue;
            seen[u] = true;
            res += cost;
            for(const auto &[to, cost] : m_g[u]) {
                if(!seen[to]) pque.emplace(cost, to);
            }
        }
        return res;
    }
};

}  // namespace algorithm

#endif
