---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/Graph/calc_tree_diameter.hpp\"\n\n\n\n#include <cassert>\n\
    #include <queue>\n#include <tuple>\n#include <utility>\n#include <vector>\n\n\
    namespace algorithm {\n\n// \u6728\u306E\u76F4\u5F84\uFF0EO(|V|+|E|).\nstd::tuple<int,\
    \ int, int> calc_tree_diameter(const std::vector<std::vector<int> > &g) {\n  \
    \  if(g.size() == 0) return {-1, -1, -1};\n    int endpoint;\n    std::vector<int>\
    \ dist(g.size());\n    auto bfs = [&](int s) -> void {\n        endpoint = s;\n\
    \        std::fill(dist.begin(), dist.end(), -1);\n        dist[s] = 0;\n    \
    \    std::queue<int> que;\n        que.push(s);\n        while(!que.empty()) {\n\
    \            int u = que.front();\n            que.pop();\n            endpoint\
    \ = u;\n            for(int v : g[u]) {\n                if(dist[v] == -1) {\n\
    \                    dist[v] = dist[u] + 1;\n                    que.push(v);\n\
    \                }\n            }\n        }\n    };\n    bfs(0);\n    int tmp\
    \ = endpoint;\n    bfs(endpoint);\n    return {dist[endpoint], tmp, endpoint};\
    \  // tuple of (distance, endpoint1, endpoint2).\n}\n\n// \u91CD\u307F\u4ED8\u304D\
    \u6728\u306E\u76F4\u5F84\uFF0EO(|E|*log|V|).\ntemplate <typename Type>\nstd::tuple<Type,\
    \ int, int> calc_tree_diameter(const std::vector<std::vector<std::pair<int, Type>\
    \ > > &g) {\n    if(g.size() == 0) return {-1, -1, -1};\n    int endpoint;\n \
    \   std::vector<Type> dist(g.size());\n    auto bfs = [&](int s) -> void {\n \
    \       endpoint = s;\n        std::fill(dist.begin(), dist.end(), -1);\n    \
    \    dist[s] = 0;\n        std::priority_queue<std::pair<Type, int> > pque;\n\
    \        pque.emplace(0, s);\n        while(!pque.empty()) {\n            auto\
    \ [d, u] = pque.top();\n            pque.pop();\n            if(-d > dist[u])\
    \ continue;\n            endpoint = u;\n            for(const auto &[v, cost]\
    \ : g[u]) {\n                if(dist[v] == -1) {\n                    dist[v]\
    \ = dist[u] + cost;\n                    pque.emplace(-dist[v], v);\n        \
    \        }\n            }\n        }\n    };\n    bfs(0);\n    int tmp = endpoint;\n\
    \    bfs(endpoint);\n    return {dist[endpoint], tmp, endpoint};  // tuple of\
    \ (distance, endpoint1, endpoint2).\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_CALC_TREE_DIAMETER_HPP\n#define ALGORITHM_CALC_TREE_DIAMETER_HPP\
    \ 1\n\n#include <cassert>\n#include <queue>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\u76F4\u5F84\uFF0E\
    O(|V|+|E|).\nstd::tuple<int, int, int> calc_tree_diameter(const std::vector<std::vector<int>\
    \ > &g) {\n    if(g.size() == 0) return {-1, -1, -1};\n    int endpoint;\n   \
    \ std::vector<int> dist(g.size());\n    auto bfs = [&](int s) -> void {\n    \
    \    endpoint = s;\n        std::fill(dist.begin(), dist.end(), -1);\n       \
    \ dist[s] = 0;\n        std::queue<int> que;\n        que.push(s);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            endpoint\
    \ = u;\n            for(int v : g[u]) {\n                if(dist[v] == -1) {\n\
    \                    dist[v] = dist[u] + 1;\n                    que.push(v);\n\
    \                }\n            }\n        }\n    };\n    bfs(0);\n    int tmp\
    \ = endpoint;\n    bfs(endpoint);\n    return {dist[endpoint], tmp, endpoint};\
    \  // tuple of (distance, endpoint1, endpoint2).\n}\n\n// \u91CD\u307F\u4ED8\u304D\
    \u6728\u306E\u76F4\u5F84\uFF0EO(|E|*log|V|).\ntemplate <typename Type>\nstd::tuple<Type,\
    \ int, int> calc_tree_diameter(const std::vector<std::vector<std::pair<int, Type>\
    \ > > &g) {\n    if(g.size() == 0) return {-1, -1, -1};\n    int endpoint;\n \
    \   std::vector<Type> dist(g.size());\n    auto bfs = [&](int s) -> void {\n \
    \       endpoint = s;\n        std::fill(dist.begin(), dist.end(), -1);\n    \
    \    dist[s] = 0;\n        std::priority_queue<std::pair<Type, int> > pque;\n\
    \        pque.emplace(0, s);\n        while(!pque.empty()) {\n            auto\
    \ [d, u] = pque.top();\n            pque.pop();\n            if(-d > dist[u])\
    \ continue;\n            endpoint = u;\n            for(const auto &[v, cost]\
    \ : g[u]) {\n                if(dist[v] == -1) {\n                    dist[v]\
    \ = dist[u] + cost;\n                    pque.emplace(-dist[v], v);\n        \
    \        }\n            }\n        }\n    };\n    bfs(0);\n    int tmp = endpoint;\n\
    \    bfs(endpoint);\n    return {dist[endpoint], tmp, endpoint};  // tuple of\
    \ (distance, endpoint1, endpoint2).\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/calc_tree_diameter.hpp
  requiredBy: []
  timestamp: '2023-08-16 13:18:03+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/calc_tree_diameter.hpp
layout: document
redirect_from:
- /library/src/Graph/calc_tree_diameter.hpp
- /library/src/Graph/calc_tree_diameter.hpp.html
title: src/Graph/calc_tree_diameter.hpp
---
