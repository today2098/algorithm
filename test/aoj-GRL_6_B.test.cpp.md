---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/Flow/primal_dual.hpp
    title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B
  bundledCode: "#line 1 \"test/aoj-GRL_6_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Graph/Flow/primal_dual.hpp\"\n\n\n\n\
    /**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41\n * @docs docs/Graph/Flow/primal_dual.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#include\
    \ <limits>\n#include <queue>\n#include <tuple>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\ntemplate <typename Flow, typename Cost>  // Flow:\u5BB9\
    \u91CF\u306E\u578B, Cost:\u30B3\u30B9\u30C8\u306E\u578B.\nclass PrimalDual {\n\
    \    struct Edge {\n        int to;     // to:=(\u884C\u304D\u5148\u30CE\u30FC\
    \u30C9).\n        Flow cap;   // cap:=(\u5BB9\u91CF).\n        Cost cost;  //\
    \ cost:=(\u5358\u4F4D\u30B3\u30B9\u30C8).\n        int rev;    // rev:=(\u9006\
    \u8FBA\u30A4\u30C6\u30EC\u30FC\u30BF).\n        explicit Edge(int to_, Flow cap_,\
    \ Cost cost_, int rev_) : to(to_), cap(cap_), cost(cost_), rev(rev_) {}\n    };\n\
    \n    std::vector<std::vector<Edge> > m_g;      // m_g[v][]:=(\u30CE\u30FC\u30C9\
    v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n    std::vector<std::pair<int, int> >\
    \ m_pos;  // m_pos[i]:=(i\u756A\u76EE\u306E\u8FBA\u60C5\u5831). pair of (from,\
    \ index).\n\n    static constexpr Cost infinity_cost() { return std::numeric_limits<Cost>::max();\
    \ }\n    void dijkstra(int s, const std::vector<Cost> &pot, std::vector<Cost>\
    \ &d, std::vector<int> &prev_v, std::vector<int> &prev_e) {\n        std::fill(d.begin(),\
    \ d.end(), infinity_cost());\n        d[s] = 0;\n        std::priority_queue<std::pair<Cost,\
    \ int>, std::vector<std::pair<Cost, int> >, std::greater<std::pair<Cost, int>\
    \ > > pque;\n        pque.emplace(0, s);\n        while(!pque.empty()) {\n   \
    \         auto [dist, v] = pque.top();\n            pque.pop();\n            if(d[v]\
    \ < dist) continue;\n            for(int i = 0, n = m_g[v].size(); i < n; ++i)\
    \ {\n                const Edge &e = m_g[v][i];\n                Cost new_cost\
    \ = e.cost + pot[v] - pot[e.to];\n                if(e.cap > 0 and d[e.to] > d[v]\
    \ + new_cost) {\n                    d[e.to] = d[v] + new_cost;\n            \
    \        prev_v[e.to] = v;\n                    prev_e[e.to] = i;\n          \
    \          pque.emplace(d[e.to], e.to);\n                }\n            }\n  \
    \      }\n    }\n\npublic:\n    PrimalDual() : PrimalDual(0) {}\n    explicit\
    \ PrimalDual(size_t vn) : m_g(vn) {}\n\n    static constexpr Flow infinity_flow()\
    \ { return std::numeric_limits<Flow>::max(); }\n    // \u30CE\u30FC\u30C9\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int order() const { return m_g.size(); }\n    //\
    \ \u8FBA\u6570\u3092\u8FD4\u3059.\n    int size() const { return m_pos.size();\
    \ }\n    // \u5BB9\u91CFcap[flows]\uFF0C\u5358\u4F4D\u30B3\u30B9\u30C8cost[cost/flow]\u306E\
    \u6709\u5411\u8FBA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    int add_edge(int from,\
    \ int to, Flow cap, Cost cost) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        assert(cap >= 0);\n      \
    \  assert(cost >= 0);\n        int idx_from = m_g[from].size(), idx_to = m_g[to].size();\n\
    \        if(from == to) idx_to++;\n        m_g[from].emplace_back(to, cap, cost,\
    \ idx_to);\n        m_g[to].emplace_back(from, 0, -cost, idx_from);\n        m_pos.emplace_back(from,\
    \ idx_from);\n        return size() - 1;\n    }\n    // \u30BD\u30FC\u30B9\u304B\
    \u3089\u30B7\u30F3\u30AF\u307E\u3067\u306E\u6700\u5C0F\u8CBB\u7528[costs]\uFF08\
    \u5358\u4F4D\u30B3\u30B9\u30C8[cost/flow]\u3068\u30D5\u30ED\u30FC[flows]\u306E\
    \u7A4D\u306E\u7DCF\u548C\uFF09\u3092\u6C42\u3081\u308B\uFF0E\n    // \u8FD4\u308A\
    \u5024\u306F\u6D41\u91CF[flows]\u3068\u6700\u5C0F\u8CBB\u7528[costs]\uFF0EO(F*|E|*log|V|).\n\
    \    std::pair<Flow, Cost> min_cost_flow(int s, int t) { return slope(s, t, infinity_flow()).back();\
    \ }\n    std::pair<Flow, Cost> min_cost_flow(int s, int t, Flow flow) { return\
    \ slope(s, t, flow).back(); }\n    std::vector<std::pair<Flow, Cost> > slope(int\
    \ s, int t) { return slope(s, t, infinity_flow()); }\n    std::vector<std::pair<Flow,\
    \ Cost> > slope(int s, int t, Flow flow) {\n        assert(0 <= s and s < order());\n\
    \        assert(0 <= t and t < order());\n        Flow rest = flow;          \
    \                         // rest:=(\u6B8B\u6D41\u91CF).\n        Cost sum = 0;\
    \                                       // sum:=(\u5408\u8A08\u8CBB\u7528).\n\
    \        Cost prev_cost = -1;                                // prev_cost:=(\u76F4\
    \u524D\u306E\u30D5\u30ED\u30FC\u306B\u304A\u3051\u308B\u5358\u4F4D\u30B3\u30B9\
    \u30C8[cost/flow]).\n        std::vector<std::pair<Flow, Cost> > res({{0, 0}});\
    \  // res[]:=(\u6D41\u91CF\u3068\u30B3\u30B9\u30C8\u306E\u95A2\u4FC2\u306E\u6298\
    \u308C\u7DDA). \u5024\u306F\u72ED\u7FA9\u5358\u8ABF\u5897\u52A0\uFF0E\n      \
    \  std::vector<Cost> d(order());                       // d[v]:=(\u30CE\u30FC\u30C8\
    s\u304B\u3089v\u307E\u3067\u306E\u6700\u5C0F\u5358\u4F4D\u30B3\u30B9\u30C8).\n\
    \        std::vector<Cost> pot(order(), 0);                  // pot[v]:=(\u30CE\
    \u30FC\u30C9v\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB).\n        std::vector<int>\
    \ prev_v(order());                   // prev_v[v]:=(\u30CE\u30FC\u30C9v\u306E\u76F4\
    \u524D\u306B\u8A2A\u308C\u308B\u30CE\u30FC\u30C9). \u9006\u65B9\u5411\u7D4C\u8DEF\
    \uFF0E\n        std::vector<int> prev_e(order());                   // prev_e[v]:=(\u30CE\
    \u30FC\u30C9v\u306E\u76F4\u524D\u306B\u901A\u308B\u8FBA). \u9006\u65B9\u5411\u7D4C\
    \u8DEF\uFF0E\n        while(rest > 0) {\n            dijkstra(s, pot, d, prev_v,\
    \ prev_e);\n            if(d[t] == infinity_cost()) break;  // \u3053\u308C\u4EE5\
    \u4E0A\u6D41\u305B\u306A\u3044\u5834\u5408\uFF0E\n            for(int v = 0, n\
    \ = order(); v < n; ++v) pot[v] += d[v];\n            Flow tmp = rest;\n     \
    \       for(int v = t; v != s; v = prev_v[v]) tmp = std::min(tmp, m_g[prev_v[v]][prev_e[v]].cap);\n\
    \            rest -= tmp;\n            sum += pot[t] * tmp;\n            if(pot[t]\
    \ == prev_cost) res.pop_back();\n            res.emplace_back(flow - rest, sum);\n\
    \            for(int v = t; v != s; v = prev_v[v]) {\n                Edge &e\
    \ = m_g[prev_v[v]][prev_e[v]];\n                e.cap -= tmp;\n              \
    \  m_g[v][e.rev].cap += tmp;\n            }\n            prev_cost = pot[t];\n\
    \        }\n        return res;\n    }\n    // \u8FBA\u306E\u60C5\u5831\u3092\u8FD4\
    \u3059\uFF0E\n    std::tuple<int, int, Flow, Cost, Flow> get_edge(int i) const\
    \ {\n        assert(0 <= i and i < size());\n        const auto &[from, idx] =\
    \ m_pos[i];\n        const Edge &e = m_g[from][idx];\n        return {from, e.to,\
    \ e.cap + m_g[e.to][e.rev].cap, e.cost, m_g[e.to][e.rev].cap};  // tuple of (from,\
    \ to, cap, cost, flow).\n    }\n    void reset() {\n        for(const auto &[from,\
    \ idx] : m_pos) {\n            Edge &e = m_g[from][idx];\n            e.cap =\
    \ e.cap + m_g[e.to][e.rev].cap;\n            m_g[e.to][e.rev].cap = 0;\n     \
    \   }\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"test/aoj-GRL_6_B.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    int f;\n    std::cin >> n >> m >> f;\n\n\
    \    algorithm::PrimalDual<int, int> primal_dual(n);\n    for(int i = 0; i < m;\
    \ ++i) {\n        int u, v;\n        int c;\n        int d;\n        std::cin\
    \ >> u >> v >> c >> d;\n\n        primal_dual.add_edge(u, v, c, d);\n    }\n\n\
    \    auto &&[flow, cost] = primal_dual.min_cost_flow(0, n - 1, f);\n    if(flow\
    \ < f) std::cout << -1 << std::endl;\n    else std::cout << cost << std::endl;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_6_B\"\
    \n\n#include <iostream>\n\n#include \"../src/Graph/Flow/primal_dual.hpp\"\n\n\
    int main() {\n    int n, m;\n    int f;\n    std::cin >> n >> m >> f;\n\n    algorithm::PrimalDual<int,\
    \ int> primal_dual(n);\n    for(int i = 0; i < m; ++i) {\n        int u, v;\n\
    \        int c;\n        int d;\n        std::cin >> u >> v >> c >> d;\n\n   \
    \     primal_dual.add_edge(u, v, c, d);\n    }\n\n    auto &&[flow, cost] = primal_dual.min_cost_flow(0,\
    \ n - 1, f);\n    if(flow < f) std::cout << -1 << std::endl;\n    else std::cout\
    \ << cost << std::endl;\n}\n"
  dependsOn:
  - src/Graph/Flow/primal_dual.hpp
  isVerificationFile: true
  path: test/aoj-GRL_6_B.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 12:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_6_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_6_B.test.cpp
- /verify/test/aoj-GRL_6_B.test.cpp.html
title: test/aoj-GRL_6_B.test.cpp
---