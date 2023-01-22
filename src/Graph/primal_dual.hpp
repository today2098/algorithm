#ifndef ALGORITHM_PRIMAL_DUAL_HPP
#define ALGORITHM_PRIMAL_DUAL_HPP 1

#include <cassert>
#include <queue>
#include <vector>

namespace algorithm {

template <typename Flow, typename Cost>  // Flow:容量の型, Cost:コストの型.
class PrimalDual {
    template <class Type>
    using r_priority_queue = std::priority_queue<Type, std::vector<Type>, std::greater<Type> >;
    struct Edge {
        int to;          // to:=(行き先ノード).
        Flow cap, icap;  // cap:=(容量), icap:=(元の容量).
        Cost cost;       // cost:=(単位コスト).
        int rev;         // rev:=(逆辺イテレータ).
        explicit Edge(int to_, Flow cap_, Cost cost_, int rev_)
            : to(to_), cap(cap_), icap(cap_), cost(cost_), rev(rev_) {}
    };

    int m_vn;                             // m_vn:=(ノード数).
    std::vector<std::vector<Edge> > m_g;  // m_g[v][]:=(ノードvの隣接リスト).
    std::vector<Cost> m_level;            // m_level[v]:=(ノートvまでの最小費用).
    std::vector<Cost> m_p;                // m_p[v]:=(ノードvのポテンシャル).
    std::vector<int> m_prevv;             // m_prevv[v]:=(ノードvの直前に訪れるノード). 逆方向経路．
    std::vector<int> m_preve;             // m_preve[v]:=(ノードvの直前に通る辺). 逆方向経路．
    Cost m_inf;

    void init() {
        for(std::vector<Edge> &es : m_g) {
            for(Edge &e : es) e.cap = e.icap;
        }
        std::fill(m_p.begin(), m_p.end(), 0);
    }
    void dijkstra(int s) {
        std::fill(m_level.begin(), m_level.end(), m_inf);
        m_level[s] = 0;
        r_priority_queue<std::pair<Cost, int> > pque;
        pque.emplace(0, s);
        while(!pque.empty()) {
            auto [cost, v] = pque.top();
            pque.pop();
            if(m_level[v] < cost) continue;
            const int sz = m_g[v].size();
            for(int i = 0; i < sz; ++i) {
                const Edge &e = m_g[v][i];
                if(e.cap > 0 and m_level[e.to] > m_level[v] + e.cost - m_p[v] + m_p[e.to]) {
                    m_level[e.to] = m_level[v] + e.cost - m_p[v] + m_p[e.to];
                    m_prevv[e.to] = v;
                    m_preve[e.to] = i;
                    pque.emplace(m_level[e.to], e.to);
                }
            }
        }
    }

public:
    PrimalDual() : PrimalDual(0) {}
    explicit PrimalDual(size_t vn, Cost inf = 1e9)
        : m_vn(vn), m_g(vn), m_level(vn), m_p(vn), m_prevv(vn), m_preve(vn), m_inf(inf) {}

    // ノード数を返す．
    int size() const { return m_vn; }
    // 容量cap[flows]，単位コストcost[cost/flow]の有向辺を追加する．
    void add_directed_edge(int from, int to, Flow cap, Cost cost) {
        assert(0 <= from and from < m_vn);
        assert(0 <= to and to < m_vn);
        m_g[from].emplace_back(to, cap, cost, m_g[to].size());
        m_g[to].emplace_back(from, 0, -cost, m_g[from].size() - 1);
    }
    // 容量cap[flows]，単位コストcost[cost/flow]の無向辺を追加する．
    void add_undirected_edge(int u, int v, Flow cap, Cost cost) {
        assert(0 <= u and u < m_vn);
        assert(0 <= v and v < m_vn);
        m_g[u].emplace_back(v, cap, cost, m_g[v].size());
        m_g[v].emplace_back(u, cap, cost, m_g[u].size() - 1);
    }
    // ソースからシンクまでの最小費用[costs]（単位コスト[cost/flow]とフロー[flows]の積の総和）を求める．
    // 返り値は最小費用[costs]と流用[flows]．O(F*|E|*log|V|).
    std::pair<Cost, Flow> min_cost_flow(int s, int t, Flow flow) {
        assert(0 <= s and s < m_vn);
        assert(0 <= t and t < m_vn);
        Cost sum = 0;
        Flow rest = flow;
        init();
        while(rest > 0) {
            dijkstra(s);
            if(m_level[t] == m_inf) return {sum, flow - rest};  // これ以上流せない場合．
            for(int v = 0; v < m_vn; ++v) m_p[v] -= m_level[v];
            Flow tmp = rest;
            for(int v = t; v != s; v = m_prevv[v]) tmp = std::min(tmp, m_g[m_prevv[v]][m_preve[v]].cap);
            rest -= tmp;
            sum += (-m_p[t]) * tmp;
            for(int v = t; v != s; v = m_prevv[v]) {
                Edge &e = m_g[m_prevv[v]][m_preve[v]];
                e.cap -= tmp;
                m_g[v][e.rev].cap += tmp;
            }
        }
        return {sum, flow};
    }
};

}  // namespace algorithm

#endif
