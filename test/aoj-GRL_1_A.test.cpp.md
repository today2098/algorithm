---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/dijkstra.hpp
    title: "Dijkstra's Algorithm\uFF08\u5358\u4E00\u59CB\u70B9\u6700\u77ED\u7D4C\u8DEF\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A
  bundledCode: "#line 1 \"test/aoj-GRL_1_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Graph/dijkstra.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <limits>\n#include <queue>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// Dijkstra's Algorithm.\n\
    template <typename T>\nclass Dijkstra {\n    std::vector<std::vector<std::pair<int,\
    \ T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\
    \u30C8). pair of (to, cost).\n    std::vector<T> m_d;                        \
    \         // m_d[t]:=(\u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\
    \u8DDD\u96E2).\n    std::vector<int> m_pre;                             // m_pre[t]:=(\u30CE\
    \u30FC\u30C9t\u3092\u8A2A\u554F\u3059\u308B\u76F4\u524D\u306E\u30CE\u30FC\u30C9\
    \u756A\u53F7). \u9006\u65B9\u5411\u7D4C\u8DEF\uFF0E\n\npublic:\n    Dijkstra()\
    \ : Dijkstra(0) {}\n    explicit Dijkstra(size_t vn) : m_g(vn), m_d(vn, infinity()),\
    \ m_pre(vn, -1) {}\n\n    static constexpr T infinity() { return std::numeric_limits<T>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_g.size(); }\n    // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\
    \u3092\u5F35\u308B\uFF0E\n    void add_edge(int from, int to, T cost) {\n    \
    \    assert(0 <= from and from < order());\n        assert(0 <= to and to < order());\n\
    \        m_g[from].emplace_back(to, cost);\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089\u5404\u30CE\u30FC\u30C9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308B\uFF0EO(|E|*log|V|).\n    void dijkstra(int s) {\n        assert(0\
    \ <= s and s < order());\n        std::fill(m_d.begin(), m_d.end(), infinity());\n\
    \        m_d[s] = 0;\n        std::fill(m_pre.begin(), m_pre.end(), -1);\n   \
    \     std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int> >,\
    \ std::greater<std::pair<T, int> > > pque;\n        pque.emplace(0, s);\n    \
    \    while(!pque.empty()) {\n            auto [dist, v] = pque.top();\n      \
    \      pque.pop();\n            if(m_d[v] < dist) continue;\n            for(const\
    \ auto &[to, cost] : m_g[v]) {\n                if(m_d[to] > m_d[v] + cost) {\n\
    \                    m_d[to] = m_d[v] + cost;\n                    m_pre[to] =\
    \ v;\n                    pque.emplace(m_d[to], to);\n                }\n    \
    \        }\n        }\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\
    \u6700\u77ED\u8DDD\u96E2\u3092\u8FD4\u3059\uFF0E\n    T distance(int t) const\
    \ {\n        assert(0 <= t and t < order());\n        return m_d[t];\n    }\n\
    \    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u7D4C\u8DEF\u3092\
    \u5FA9\u5143\u3059\u308B\uFF0E\n    std::vector<int> shortest_path(int t) const\
    \ {\n        assert(0 <= t and t < order());\n        std::vector<int> path;\n\
    \        if(distance(t) == infinity()) return path;\n        for(; t != -1; t\
    \ = m_pre[t]) path.push_back(t);\n        std::reverse(path.begin(), path.end());\n\
    \        return path;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"\
    test/aoj-GRL_1_A.test.cpp\"\n\nint main() {\n    int n, m;\n    int r;\n    std::cin\
    \ >> n >> m >> r;\n\n    algorithm::Dijkstra<int> dijkstra(n);\n    for(int i\
    \ = 0; i < m; ++i) {\n        int s, t;\n        int d;\n        std::cin >> s\
    \ >> t >> d;\n        dijkstra.add_edge(s, t, d);\n    }\n    dijkstra.dijkstra(r);\n\
    \n    for(int i = 0; i < n; ++i) {\n        auto ans = dijkstra.distance(i);\n\
    \        if(ans == dijkstra.infinity()) std::cout << \"INF\" << std::endl;\n \
    \       else std::cout << ans << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A\"\
    \n\n#include <iostream>\n\n#include \"../src/Graph/dijkstra.hpp\"\n\nint main()\
    \ {\n    int n, m;\n    int r;\n    std::cin >> n >> m >> r;\n\n    algorithm::Dijkstra<int>\
    \ dijkstra(n);\n    for(int i = 0; i < m; ++i) {\n        int s, t;\n        int\
    \ d;\n        std::cin >> s >> t >> d;\n        dijkstra.add_edge(s, t, d);\n\
    \    }\n    dijkstra.dijkstra(r);\n\n    for(int i = 0; i < n; ++i) {\n      \
    \  auto ans = dijkstra.distance(i);\n        if(ans == dijkstra.infinity()) std::cout\
    \ << \"INF\" << std::endl;\n        else std::cout << ans << std::endl;\n    }\n\
    }\n"
  dependsOn:
  - src/Graph/dijkstra.hpp
  isVerificationFile: true
  path: test/aoj-GRL_1_A.test.cpp
  requiredBy: []
  timestamp: '2023-08-28 11:58:01+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_1_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_1_A.test.cpp
- /verify/test/aoj-GRL_1_A.test.cpp.html
title: test/aoj-GRL_1_A.test.cpp
---
