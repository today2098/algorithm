---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/Tree/calc_tree_diameter.hpp
    title: "\u6728\u306E\u76F4\u5F84"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A
  bundledCode: "#line 1 \"test/aoj-GRL_5_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Graph/Tree/calc_tree_diameter.hpp\"\n\
    /**\n * @brief \u6728\u306E\u76F4\u5F84\n * @docs docs/Graph/Tree/calc_tree_diameter.md\n\
    \ */\n\n#ifndef ALGORITHM_CALC_TREE_DIAMETER_HPP\n#define ALGORITHM_CALC_TREE_DIAMETER_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <queue>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\
    \u76F4\u5F84\u3092\u6C42\u3081\u308B\uFF0EO(|V|).\nstd::tuple<int, int, int> calc_tree_diameter(const\
    \ std::vector<std::vector<int> > &g) {\n    if(g.size() == 0) return {-1, -1,\
    \ -1};\n    int endpoint;\n    std::vector<int> d(g.size());\n    std::queue<int>\
    \ que;\n    auto bfs = [&](int s) -> void {\n        endpoint = s;\n        std::fill(d.begin(),\
    \ d.end(), -1);\n        d[s] = 0;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            endpoint\
    \ = u;\n            for(int v : g[u]) {\n                if(d[v] != -1) continue;\n\
    \                d[v] = d[u] + 1;\n                que.push(v);\n            }\n\
    \        }\n    };\n    bfs(0);\n    int tmp = endpoint;\n    bfs(endpoint);\n\
    \    return {d[endpoint], tmp, endpoint};  // tuple of (diameter, endpoint1, endpoint2).\n\
    }\n\n// \u91CD\u307F\u4ED8\u304D\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\
    \uFF0EO(|V|).\ntemplate <typename Type>\nstd::tuple<Type, int, int> calc_tree_diameter(const\
    \ std::vector<std::vector<std::pair<int, Type> > > &g) {\n    if(g.size() == 0)\
    \ return {-1, -1, -1};\n    int endpoint;\n    Type diameter;\n    std::vector<Type>\
    \ d(g.size());\n    std::vector<bool> seen(g.size());\n    std::queue<int> que;\n\
    \    auto bfs = [&](int s) -> void {\n        endpoint = s;\n        diameter\
    \ = d[s] = 0;\n        std::fill(seen.begin(), seen.end(), false);\n        que.push(s);\n\
    \        while(!que.empty()) {\n            int u = que.front();\n           \
    \ que.pop();\n            seen[u] = true;\n            if(d[u] > diameter) endpoint\
    \ = u, diameter = d[u];\n            for(const auto &[v, cost] : g[u]) {\n   \
    \             if(seen[v]) continue;\n                d[v] = d[u] + cost;\n   \
    \             que.emplace(v);\n            }\n        }\n    };\n    bfs(0);\n\
    \    int tmp = endpoint;\n    bfs(endpoint);\n    return {diameter, tmp, endpoint};\
    \  // tuple of (diameter, endpoint1, endpoint2).\n}\n\n}  // namespace algorithm\n\
    \n#endif\n#line 6 \"test/aoj-GRL_5_A.test.cpp\"\n\nint main() {\n    int n;\n\
    \    std::cin >> n;\n\n    std::vector<std::vector<std::pair<int, int> > > g(n);\n\
    \    for(int i = 0; i < n - 1; ++i) {\n        int s, t;\n        int w;\n   \
    \     std::cin >> s >> t >> w;\n\n        g[s].emplace_back(t, w);\n        g[t].emplace_back(s,\
    \ w);\n    }\n\n    auto &&[ans, _, __] = algorithm::calc_tree_diameter(g);\n\
    \    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A\"\
    \n\n#include <iostream>\n\n#include \"../src/Graph/Tree/calc_tree_diameter.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<std::vector<std::pair<int,\
    \ int> > > g(n);\n    for(int i = 0; i < n - 1; ++i) {\n        int s, t;\n  \
    \      int w;\n        std::cin >> s >> t >> w;\n\n        g[s].emplace_back(t,\
    \ w);\n        g[t].emplace_back(s, w);\n    }\n\n    auto &&[ans, _, __] = algorithm::calc_tree_diameter(g);\n\
    \    std::cout << ans << std::endl;\n}\n"
  dependsOn:
  - src/Graph/Tree/calc_tree_diameter.hpp
  isVerificationFile: true
  path: test/aoj-GRL_5_A.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 14:17:44+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_5_A.test.cpp
- /verify/test/aoj-GRL_5_A.test.cpp.html
title: test/aoj-GRL_5_A.test.cpp
---
