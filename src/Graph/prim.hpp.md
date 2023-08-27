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
  bundledCode: "#line 1 \"src/Graph/prim.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename T>\nclass Prim {\n    std::vector<std::vector<std::pair<int,\
    \ T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\
    \u30C8). pair of (to, cost).\n\npublic:\n    Prim() : Prim(0) {}\n    explicit\
    \ Prim(size_t vn) : m_g(vn) {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\
    \uFF0E\n    int order() const { return m_g.size(); }\n    // \u91CD\u307F\u4ED8\
    \u304D\u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int u, int\
    \ v, T cost) {\n        assert(0 <= u and u < order());\n        assert(0 <= v\
    \ and v < order());\n        m_g[u].emplace_back(v, cost);\n        m_g[v].emplace_back(u,\
    \ cost);\n    }\n    // \u91CD\u307F\u4ED8\u304D\u7121\u5411\u9023\u7D50\u30B0\
    \u30E9\u30D5\u306B\u304A\u3051\u308B\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8\u3092\u6C42\u3081\u308B\uFF0EO(|E|*log|V|).\n    T prim(int root\
    \ = 0) {\n        assert(0 <= root and root < order());\n        T res = 0;\n\
    \        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>\
    \ >, std::greater<std::pair<T, int> > > pque;\n        pque.emplace(0, root);\n\
    \        bool seen[order()] = {};\n        while(!pque.empty()) {\n          \
    \  auto [cost, u] = pque.top();\n            pque.pop();\n            if(seen[u])\
    \ continue;\n            seen[u] = true;\n            res += cost;\n         \
    \   for(const auto &[v, cost] : m_g[u]) {\n                if(!seen[v]) pque.emplace(cost,\
    \ v);\n            }\n        }\n        return res;\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PRIM_HPP\n#define ALGORITHM_PRIM_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <queue>\n#include <utility>\n#include <vector>\n\n\
    namespace algorithm {\n\ntemplate <typename T>\nclass Prim {\n    std::vector<std::vector<std::pair<int,\
    \ T> > > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\
    \u30C8). pair of (to, cost).\n\npublic:\n    Prim() : Prim(0) {}\n    explicit\
    \ Prim(size_t vn) : m_g(vn) {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\
    \uFF0E\n    int order() const { return m_g.size(); }\n    // \u91CD\u307F\u4ED8\
    \u304D\u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int u, int\
    \ v, T cost) {\n        assert(0 <= u and u < order());\n        assert(0 <= v\
    \ and v < order());\n        m_g[u].emplace_back(v, cost);\n        m_g[v].emplace_back(u,\
    \ cost);\n    }\n    // \u91CD\u307F\u4ED8\u304D\u7121\u5411\u9023\u7D50\u30B0\
    \u30E9\u30D5\u306B\u304A\u3051\u308B\u6700\u5C0F\u5168\u57DF\u6728\u306E\u30B3\
    \u30B9\u30C8\u3092\u6C42\u3081\u308B\uFF0EO(|E|*log|V|).\n    T prim(int root\
    \ = 0) {\n        assert(0 <= root and root < order());\n        T res = 0;\n\
    \        std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>\
    \ >, std::greater<std::pair<T, int> > > pque;\n        pque.emplace(0, root);\n\
    \        bool seen[order()] = {};\n        while(!pque.empty()) {\n          \
    \  auto [cost, u] = pque.top();\n            pque.pop();\n            if(seen[u])\
    \ continue;\n            seen[u] = true;\n            res += cost;\n         \
    \   for(const auto &[v, cost] : m_g[u]) {\n                if(!seen[v]) pque.emplace(cost,\
    \ v);\n            }\n        }\n        return res;\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/prim.hpp
  requiredBy: []
  timestamp: '2023-08-22 20:50:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/prim.hpp
layout: document
redirect_from:
- /library/src/Graph/prim.hpp
- /library/src/Graph/prim.hpp.html
title: src/Graph/prim.hpp
---
