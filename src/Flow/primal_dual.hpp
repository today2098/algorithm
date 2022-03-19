#ifndef ALGORITHM_PRIMAL_DUAL_HPP
#define ALGORITHM_PRIMAL_DUAL_HPP 1

#include <algorithm>  // for fill() and min().
#include <cassert>
#include <functional>  // for greater.
#include <queue>       // for priority_queue.
#include <utility>     // for pair.
#include <vector>

namespace algorithm {

template <typename T, typename U>  // T:容量の型, U:コストの型.
class PrimalDual {
    template <class Type>
    using r_priority_queue = std::priority_queue<Type, std::vector<Type>, std::greater<Type> >;
    struct Edge {
        int to;       // to:=(行き先ノード).
        T cap, icap;  // cap:=(容量), icap:=(元の容量).
        U cost;       // cost:=(単位コスト).
        int rev;      // rev:=(逆辺イテレータ).
        explicit Edge(int to_, T cap_, U cost_, int rev_) : to(to_), cap(cap_), icap(cap_), cost(cost_), rev(rev_) {}
    };

    int vn;                             // vn:=(ノード数).
    std::vector<std::vector<Edge> > g;  // g[v][]:=(ノードvの隣接リスト).
    std::vector<U> level, p;            // level[v]:=(ノートvまでの最短距離), p[v]:=(ノードvのポテンシャル).
    std::vector<int> prevv, preve;      // prevv[v]:=(ノードvの直前に訪れるノード), preve[v]:=(ノードvの直前に通る辺). 逆方向経路．
    U inf;

    void reset() {
        for(std::vector<Edge> &es : g)
            for(Edge &e : es) e.cap = e.icap;
        std::fill(p.begin(), p.end(), 0);
    }
    void dijkstra(int s) {
        std::fill(level.begin(), level.end(), inf);
        level[s] = 0;
        r_priority_queue<std::pair<U, int> > pque;
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [cost, v] = pque.top();
            pque.pop();
            if(level[v] < cost) continue;
            for(int i = 0; i < g[v].size(); ++i) {
                const Edge &e = g[v][i];
                if(e.cap > 0 and level[e.to] > level[v] + e.cost - p[v] + p[e.to]) {
                    level[e.to] = level[v] + e.cost - p[v] + p[e.to];
                    prevv[e.to] = v;
                    preve[e.to] = i;
                    pque.emplace(level[e.to], e.to);
                }
            }
        }
    }

public:
    // constructor.
    PrimalDual() : PrimalDual(0) {}
    explicit PrimalDual(size_t vn_, U inf_ = 1e9) : vn(vn_), g(vn_), level(vn_), p(vn_), prevv(vn_), preve(vn_), inf(inf_) {}

    int size() const { return vn; }                   // ノード数を返す．
    void add_egde(int from, int to, T cap, U cost) {  // 容量cap，コストcostの有向辺を追加する．
        assert(0 <= from and from < vn);
        assert(0 <= to and to < vn);
        g[from].emplace_back(to, cap, cost, g[to].size());
        g[to].emplace_back(from, 0, -cost, g[from].size() - 1);
    }
    // ソースからシンクまでの最小費用（単位コストとフローの積の総和）を求める．返り値は流量とコスト．O(F*|E|*log|V|).
    std::pair<T, U> min_cost_flow(int s, int t, T flow) {
        assert(0 <= s and s < vn);
        assert(0 <= t and t < vn);
        reset();
        T rest = flow;
        U sum = 0;
        while(rest > 0) {
            dijkstra(s);
            if(level[t] == inf) return std::pair<U, T>(flow - rest, sum);  // これ以上流せない場合．
            for(int v = 0; v < vn; ++v) p[v] -= level[v];
            T tmp = rest;
            for(int v = t; v != s; v = prevv[v]) tmp = std::min(tmp, g[prevv[v]][preve[v]].cap);
            rest -= tmp;
            sum += (-p[t]) * tmp;
            for(int v = t; v != s; v = prevv[v]) {
                Edge &e = g[prevv[v]][preve[v]];
                e.cap -= tmp;
                g[v][e.rev].cap += tmp;
            }
        }
        return std::pair<U, T>(flow, sum);
    }
};

}  // namespace algorithm

#endif  // ALGORITHM_PRIMAL_DUAL_HPP
