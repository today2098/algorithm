#ifndef ALGORITHM_PRIM_HPP
#define ALGORITHM_PRIM_HPP 1

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

namespace algorithm {

template <typename T>
class Prim {
    struct Edge {
        int to;
        T cost;
    };

    int vn, n;                             // vn:=(ノード数), n:=(葉の数).
    std::vector<std::vector<Edge> > g;     // g[v][]:=(ノードvがもつ辺のリスト).
    std::vector<std::pair<T, int> > heap;  // 1-based index.
    T inf;

    void shiht_up(int i) {
        assert(n <= i and i < 2 * n);
        i >>= 1;
        while(i > 0) {
            heap[i] = std::min(heap[2 * i], heap[2 * i + 1]);
            i >>= 1;
        }
    }
    void push(T cost, int k) {
        assert(0 <= k and k < vn);
        if(cost >= heap[k + n].first) return;
        heap[k + n] = std::pair<T, int>(cost, k);
        shiht_up(k + n);
    }
    void pop() {
        auto [ignore, k] = heap[1];
        if(k == -1) return;
        heap[k + n] = std::pair<T, int>(inf, -1);
        shiht_up(k + n);
    }
    std::pair<T, int> top() const { return heap[1]; }

public:
    // constructor.
    Prim() : Prim(0) {}
    explicit Prim(std::size_t vn_, T inf_ = 1e9) : vn(vn_), g(vn_), inf(inf_) {
        n = 1;
        while(n < vn) n <<= 1;
        heap.assign(2 * n, std::pair<T, int>(inf, -1));
    }

    int size() const { return vn; }        // ノード数を返す．
    void add_edge(int u, int v, T cost) {  // 重み付き無向辺を張る．
        assert(0 <= u and u < vn);
        assert(0 <= v and v < vn);
        g[u].push_back((Edge){v, cost});
        g[v].push_back((Edge){u, cost});
    }
    T prim(int v = 0) {  // ノードvを含む最小全域木のコストを求める．O(|E|*log|V|).
        assert(0 <= v and v < vn);
        T res = 0;
        bool seen[vn] = {};
        push(0, v);
        while(1) {
            auto &&[cost, u] = top();
            if(u == -1) break;
            pop();
            if(seen[u]) continue;
            res += cost, seen[u] = true;
            for(const Edge &e : g[u]) {
                if(!seen[e.to]) push(e.cost, e.to);
            }
        }
        return res;
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_PRIM_HPP
