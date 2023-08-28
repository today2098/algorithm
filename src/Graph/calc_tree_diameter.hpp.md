---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-GRL_5_A.test.cpp
    title: test/aoj-GRL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/calc_tree_diameter.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <queue>\n#include <tuple>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\u76F4\u5F84\u3092\u6C42\
    \u3081\u308B\uFF0EO(|V|).\nstd::tuple<int, int, int> calc_tree_diameter(const\
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
    \n\n"
  code: "#ifndef ALGORITHM_CALC_TREE_DIAMETER_HPP\n#define ALGORITHM_CALC_TREE_DIAMETER_HPP\
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
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/calc_tree_diameter.hpp
  requiredBy: []
  timestamp: '2023-08-28 17:19:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-GRL_5_A.test.cpp
documentation_of: src/Graph/calc_tree_diameter.hpp
layout: document
title: "\u6728\u306E\u76F4\u5F84"
---
