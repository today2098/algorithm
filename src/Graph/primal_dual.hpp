#ifndef ALGORITHM_PRIMAL_DUAL_HPP
#define ALGORITHM_PRIMAL_DUAL_HPP 1

#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename Flow, typename Cost>  // Flow:容量の型, Cost:コストの型.
class PrimalDual {
    struct Edge {
        int to;          // to:=(行き先ノード).
        Flow cap, rest;  // cap:=(容量), rest:=(残容量).
        Cost cost;       // cost:=(単位コスト).
        int rev;         // rev:=(逆辺イテレータ).
        explicit Edge(int to_, Flow cap_, Cost cost_, int rev_) : to(to_), cap(cap_), rest(cap_), cost(cost_), rev(rev_) {}
    };

    int m_vn;                             // m_vn:=(ノード数).
    std::vector<std::vector<Edge> > m_g;  // m_g[v][]:=(ノードvの隣接リスト).
    Cost m_inf;

    void dijkstra(int s, const std::vector<Cost> &pot, std::vector<Cost> &d, std::vector<int> &prev_v, std::vector<int> &prev_e) {
        std::fill(d.begin(), d.end(), infinity());
        d[s] = 0;
        std::priority_queue<std::pair<Cost, int>, std::vector<std::pair<Cost, int> >, std::greater<std::pair<Cost, int> > > pque;
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [dist, v] = pque.top();
            pque.pop();
            if(d[v] < dist) continue;
            const int n = m_g[v].size();
            for(int i = 0; i < n; ++i) {
                const Edge &e = m_g[v][i];
                Cost new_dist = d[v] + e.cost + pot[v] - pot[e.to];
                if(e.rest > 0 and d[e.to] > new_dist) {
                    d[e.to] = new_dist;
                    prev_v[e.to] = v;
                    prev_e[e.to] = i;
                    pque.emplace(d[e.to], e.to);
                }
            }
        }
    }

public:
    PrimalDual() : PrimalDual(0) {}
    explicit PrimalDual(size_t vn, Cost inf = 1e9) : m_vn(vn), m_g(vn), m_inf(inf) {}

    // ノード数を返す．
    int order() const { return m_vn; }
    Cost infinity() const { return m_inf; }
    // 容量cap[flows]，単位コストcost[cost/flow]の有向辺を追加する．
    void add_directed_edge(int from, int to, Flow cap, Cost cost) {
        assert(0 <= from and from < order());
        assert(0 <= to and to < order());
        m_g[from].emplace_back(to, cap, cost, m_g[to].size());
        m_g[to].emplace_back(from, 0, -cost, m_g[from].size() - 1);
    }
    // 容量cap[flows]，単位コストcost[cost/flow]の無向辺を追加する．
    void add_undirected_edge(int u, int v, Flow cap, Cost cost) {
        assert(0 <= u and u < order());
        assert(0 <= v and v < order());
        m_g[u].emplace_back(v, cap, cost, m_g[v].size());
        m_g[v].emplace_back(u, cap, cost, m_g[u].size() - 1);
    }
    // ソースからシンクまでの最小費用[costs]（単位コスト[cost/flow]とフロー[flows]の積の総和）を求める．
    // 返り値は最小費用[costs]と流用[flows]．O(F*|E|*log|V|).
    std::pair<Cost, Flow> min_cost_flow(int s, int t, Flow flow) {
        assert(0 <= s and s < order());
        assert(0 <= t and t < order());
        for(std::vector<Edge> &es : m_g) {
            for(Edge &e : es) e.rest = e.cap;
        }
        Cost sum = 0;
        Flow rest = flow;
        std::vector<Cost> d(order());       // d[v]:=(ノートsからvまでの最小費用).
        std::vector<Cost> pot(order(), 0);  // pot[v]:=(ノードvのポテンシャル).
        std::vector<int> prev_v(order());   // prev_v[v]:=(ノードvの直前に訪れるノード). 逆方向経路．
        std::vector<int> prev_e(order());   // prev_e[v]:=(ノードvの直前に通る辺). 逆方向経路．
        while(rest > 0) {
            dijkstra(s, pot, d, prev_v, prev_e);
            if(d[t] == infinity()) return {sum, flow - rest};  // これ以上流せない場合．
            for(int v = 0; v < order(); ++v) pot[v] += d[v];
            Flow tmp = rest;
            for(int v = t; v != s; v = prev_v[v]) tmp = std::min(tmp, m_g[prev_v[v]][prev_e[v]].rest);
            rest -= tmp;
            sum += pot[t] * tmp;
            for(int v = t; v != s; v = prev_v[v]) {
                Edge &e = m_g[prev_v[v]][prev_e[v]];
                e.rest -= tmp;
                m_g[v][e.rev].rest += tmp;
            }
        }
        return {sum, flow};
    }
};

}  // namespace algorithm

#endif
