---
data:
  _extendedDependsOn:
  - icon: ':x:'
    path: src/Graph/bellman_ford.hpp
    title: src/Graph/bellman_ford.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "#line 1 \"test/yosupo-shortest_path-bellman_ford.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include <iostream>\n\
    \n#line 1 \"src/Graph/bellman_ford.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <vector>\n\nnamespace algorithm {\n\n\
    template <typename T>\nclass BellmanFord {\n    struct Edge {\n        int from,\
    \ to;\n        T cost;\n        explicit Edge(int from_, int to_, T cost_) : from(from_),\
    \ to(to_), cost(cost_) {}\n    };\n\n    int m_vn;                   // m_vn:=(\u30CE\
    \u30FC\u30C9\u6570).\n    std::vector<Edge> m_edges;  // m_edges[]:=(\u8FBA\u30EA\
    \u30B9\u30C8).\n    std::vector<T> m_d;         // m_d[t]:=(\u30CE\u30FC\u30C9\
    s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2).\n    std::vector<int> m_pre;\
    \     // m_pre[t]:=(\u30CE\u30FC\u30C9t\u3092\u8A2A\u554F\u3059\u308B\u76F4\u524D\
    \u306E\u30CE\u30FC\u30C9\u756A\u53F7). \u9006\u65B9\u5411\u7D4C\u8DEF\uFF0E\n\n\
    public:\n    BellmanFord() : BellmanFord(0) {}\n    explicit BellmanFord(size_t\
    \ vn) : m_vn(vn), m_d(vn, infinity()), m_pre(vn, -1) {}\n\n    static constexpr\
    \ T infinity() { return std::numeric_limits<T>::max(); }\n    // \u30CE\u30FC\u30C9\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return m_vn; }\n    //\
    \ \u8FBA\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_edges.size();\
    \ }\n    // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\
    \n    void add_edge(int from, int to, T cost) {\n        assert(0 <= from and\
    \ from < order());\n        assert(0 <= to and to < order());\n        m_edges.emplace_back(from,\
    \ to, cost);\n    }\n    // \u30B0\u30E9\u30D5\u5168\u4F53\u304B\u3089\u8CA0\u9589\
    \u8DEF\u3092\u691C\u51FA\u3059\u308B\uFF0EO(|V|*|E|).\n    bool find_negative_cycle()\
    \ const {\n        std::vector<T> nd(order(), 0);\n        for(int i = 0; i <\
    \ order(); ++i) {\n            bool update = false;\n            for(const auto\
    \ &[from, to, cost] : m_edges) {\n                if(nd[to] > nd[from] + cost)\
    \ {\n                    nd[to] = nd[from] + cost;\n                    update\
    \ = true;\n                }\n            }\n            if(!update) return false;\
    \  // \u8CA0\u9589\u8DEF\u7121\u3057\uFF0E\n        }\n        return true;  //\
    \ \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089\u5404\u30CE\u30FC\u30C9\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\
    \u3081\u308B\uFF0EO(|V|*|E|).\n    bool bellman_ford(int s) {\n        assert(0\
    \ <= s and s < order());\n        std::fill(m_d.begin(), m_d.end(), infinity());\n\
    \        m_d[s] = 0;\n        std::fill(m_pre.begin(), m_pre.end(), -1);\n   \
    \     for(int i = 0; i < order(); ++i) {\n            bool update = false;\n \
    \           for(const auto &[from, to, cost] : m_edges) {\n                if(m_d[from]\
    \ == infinity()) continue;\n                if(m_d[to] > m_d[from] + cost) {\n\
    \                    m_d[to] = m_d[from] + cost;\n                    m_pre[to]\
    \ = from;\n                    update = true;\n                }\n           \
    \ }\n            if(!update) return false;  // \u8CA0\u9589\u8DEF\u7121\u3057\uFF0E\
    \n        }\n        for(int i = 0; i < order(); ++i) {\n            bool update\
    \ = false;\n            for(const auto &[from, to, cost] : m_edges) {\n      \
    \          if(m_d[from] == infinity() or m_d[to] == -infinity()) continue;\n \
    \               if(m_d[from] == -infinity() or m_d[to] > m_d[from] + cost) {\n\
    \                    m_d[to] = -infinity();\n                    update = true;\n\
    \                }\n            }\n            if(!update) break;\n        }\n\
    \        return true;  // \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n    }\n    //\
    \ \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8FD4\
    \u3059\uFF0E\n    T distance(int t) const {\n        assert(0 <= t and t < order());\n\
    \        return m_d[t];\n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\
    \u6700\u77ED\u7D4C\u8DEF\u3092\u5FA9\u5143\u3059\u308B\uFF0E\n    std::vector<int>\
    \ shortest_path(int t) const {\n        assert(0 <= t and t < order());\n    \
    \    std::vector<int> path;\n        if(!(-infinity() < m_d[t] and m_d[t] < infinity()))\
    \ return path;\n        for(; t != -1; t = m_pre[t]) path.push_back(t);\n    \
    \    std::reverse(path.begin(), path.end());\n        return path;\n    }\n};\n\
    \n}  // namespace algorithm\n\n\n#line 6 \"test/yosupo-shortest_path-bellman_ford.test.cpp\"\
    \n\nint main() {\n    int n, m;\n    int s, t;\n    std::cin >> n >> m >> s >>\
    \ t;\n\n    algorithm::BellmanFord<long long> bellman_ford(n);\n    for(int i\
    \ = 0; i < m; ++i) {\n        int a, b;\n        long long c;\n        std::cin\
    \ >> a >> b >> c;\n\n        bellman_ford.add_edge(a, b, c);\n    }\n    bellman_ford.bellman_ford(s);\n\
    \n    auto x = bellman_ford.distance(t);\n    if(x == bellman_ford.infinity())\
    \ {\n        std::cout << -1 << std::endl;\n        return 0;\n    }\n\n    auto\
    \ path = bellman_ford.shortest_path(t);\n    int y = path.size() - 1;\n\n    std::cout\
    \ << x << ' ' << y << std::endl;\n    for(int i = 0; i < y; ++i) std::cout <<\
    \ path[i] << ' ' << path[i + 1] << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ <iostream>\n\n#include \"../src/Graph/bellman_ford.hpp\"\n\nint main() {\n \
    \   int n, m;\n    int s, t;\n    std::cin >> n >> m >> s >> t;\n\n    algorithm::BellmanFord<long\
    \ long> bellman_ford(n);\n    for(int i = 0; i < m; ++i) {\n        int a, b;\n\
    \        long long c;\n        std::cin >> a >> b >> c;\n\n        bellman_ford.add_edge(a,\
    \ b, c);\n    }\n    bellman_ford.bellman_ford(s);\n\n    auto x = bellman_ford.distance(t);\n\
    \    if(x == bellman_ford.infinity()) {\n        std::cout << -1 << std::endl;\n\
    \        return 0;\n    }\n\n    auto path = bellman_ford.shortest_path(t);\n\
    \    int y = path.size() - 1;\n\n    std::cout << x << ' ' << y << std::endl;\n\
    \    for(int i = 0; i < y; ++i) std::cout << path[i] << ' ' << path[i + 1] <<\
    \ std::endl;\n}\n"
  dependsOn:
  - src/Graph/bellman_ford.hpp
  isVerificationFile: true
  path: test/yosupo-shortest_path-bellman_ford.test.cpp
  requiredBy: []
  timestamp: '2023-08-28 02:10:12+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo-shortest_path-bellman_ford.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-shortest_path-bellman_ford.test.cpp
- /verify/test/yosupo-shortest_path-bellman_ford.test.cpp.html
title: test/yosupo-shortest_path-bellman_ford.test.cpp
---
