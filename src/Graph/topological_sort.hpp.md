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
  bundledCode: "#line 1 \"src/Graph/topological_sort.hpp\"\n\n\n\n#include <cassert>\n\
    #include <queue>\n#include <vector>\n\nnamespace algorithm {\n\nclass TopologicalSort\
    \ {\n    std::vector<std::vector<int> > m_g;  // m_g[v]:=(\u9802\u70B9v\u306E\u96A3\
    \u63A5\u30EA\u30B9\u30C8).\n\npublic:\n    TopologicalSort() : TopologicalSort(0)\
    \ {}\n    explicit TopologicalSort(size_t vn) : m_g(vn) {}\n\n    // \u9802\u70B9\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return m_g.size(); }\n\
    \    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int from,\
    \ int to) {\n        assert(0 <= from and from < order());\n        assert(0 <=\
    \ to and to < order());\n        m_g[from].push_back(to);\n    }\n    // \u4EFB\
    \u610F\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\u89E3\
    \u3092\u6C42\u3081\u308B\uFF0EO(|E|).\n    std::vector<int> topological_sort()\
    \ const {\n        std::vector<int> res;\n        res.reserve(order());\n    \
    \    std::vector<int> deg(order(), 0);  // deg[v]:=(\u9802\u70B9v\u306E\u5165\u6B21\
    \u6570).\n        for(const std::vector<int> &edges : m_g) {\n            for(int\
    \ to : edges) deg[to]++;\n        }\n        std::queue<int> que;\n        for(int\
    \ i = 0; i < order(); ++i) {\n            if(deg[i] == 0) que.push(i);\n     \
    \   }\n        while(!que.empty()) {\n            int u = que.front();\n     \
    \       que.pop();\n            res.push_back(u);\n            for(int v : m_g[u])\
    \ {\n                if(--deg[v] == 0) que.push(v);\n            }\n        }\n\
    \        if(res.size() != order()) return std::vector<int>();  // \u9589\u8DEF\
    \u304C\u3042\u308B\u5834\u5408\uFF0E\n        return res;\n    }\n    // \u8003\
    \u3048\u5F97\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\
    \u89E3\u3092\u6570\u3048\u4E0A\u3052\u308B\uFF0E\u9802\u70B9\u6570\u306E\u4E0A\
    \u9650\u76EE\u5B89\u306F20\u7A0B\u5EA6\uFF0EO(N*(2^N)).\n    template <typename\
    \ Type = long long>\n    Type count_up() const {\n        std::vector<int> b(order(),\
    \ 0);\n        for(int v = 0; v < order(); ++v) {\n            for(int to : m_g[v])\
    \ b[v] |= (1 << to);\n        }\n        std::vector<Type> dp(1 << order(), 0);\
    \  // dp[S]:=(\u9802\u70B9\u96C6\u5408S\u306B\u304A\u3051\u308B\u89E3\u306E\u901A\
    \u308A\u6570).\n        dp[0] = 1;\n        for(int bit = 0; bit < (1 << order());\
    \ ++bit) {\n            for(int i = 0; i < order(); ++i) {\n                if(!(bit\
    \ >> i & 1) and !(bit & b[i])) dp[bit | 1 << i] += dp[bit];\n            }\n \
    \       }\n        return dp[(1 << order()) - 1];\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_TOPOLOGICAL_SORT_HPP\n#define ALGORITHM_TOPOLOGICAL_SORT_HPP\
    \ 1\n\n#include <cassert>\n#include <queue>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nclass TopologicalSort {\n    std::vector<std::vector<int> > m_g;  // m_g[v]:=(\u9802\
    \u70B9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n\npublic:\n    TopologicalSort()\
    \ : TopologicalSort(0) {}\n    explicit TopologicalSort(size_t vn) : m_g(vn) {}\n\
    \n    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return\
    \ m_g.size(); }\n    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int\
    \ from, int to) {\n        assert(0 <= from and from < order());\n        assert(0\
    \ <= to and to < order());\n        m_g[from].push_back(to);\n    }\n    // \u4EFB\
    \u610F\u306E\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\u89E3\
    \u3092\u6C42\u3081\u308B\uFF0EO(|E|).\n    std::vector<int> topological_sort()\
    \ const {\n        std::vector<int> res;\n        res.reserve(order());\n    \
    \    std::vector<int> deg(order(), 0);  // deg[v]:=(\u9802\u70B9v\u306E\u5165\u6B21\
    \u6570).\n        for(const std::vector<int> &edges : m_g) {\n            for(int\
    \ to : edges) deg[to]++;\n        }\n        std::queue<int> que;\n        for(int\
    \ i = 0; i < order(); ++i) {\n            if(deg[i] == 0) que.push(i);\n     \
    \   }\n        while(!que.empty()) {\n            int u = que.front();\n     \
    \       que.pop();\n            res.push_back(u);\n            for(int v : m_g[u])\
    \ {\n                if(--deg[v] == 0) que.push(v);\n            }\n        }\n\
    \        if(res.size() != order()) return std::vector<int>();  // \u9589\u8DEF\
    \u304C\u3042\u308B\u5834\u5408\uFF0E\n        return res;\n    }\n    // \u8003\
    \u3048\u5F97\u308B\u30C8\u30DD\u30ED\u30B8\u30AB\u30EB\u30BD\u30FC\u30C8\u306E\
    \u89E3\u3092\u6570\u3048\u4E0A\u3052\u308B\uFF0E\u9802\u70B9\u6570\u306E\u4E0A\
    \u9650\u76EE\u5B89\u306F20\u7A0B\u5EA6\uFF0EO(N*(2^N)).\n    template <typename\
    \ Type = long long>\n    Type count_up() const {\n        std::vector<int> b(order(),\
    \ 0);\n        for(int v = 0; v < order(); ++v) {\n            for(int to : m_g[v])\
    \ b[v] |= (1 << to);\n        }\n        std::vector<Type> dp(1 << order(), 0);\
    \  // dp[S]:=(\u9802\u70B9\u96C6\u5408S\u306B\u304A\u3051\u308B\u89E3\u306E\u901A\
    \u308A\u6570).\n        dp[0] = 1;\n        for(int bit = 0; bit < (1 << order());\
    \ ++bit) {\n            for(int i = 0; i < order(); ++i) {\n                if(!(bit\
    \ >> i & 1) and !(bit & b[i])) dp[bit | 1 << i] += dp[bit];\n            }\n \
    \       }\n        return dp[(1 << order()) - 1];\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/topological_sort.hpp
  requiredBy: []
  timestamp: '2023-08-23 12:19:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/topological_sort.hpp
layout: document
redirect_from:
- /library/src/Graph/topological_sort.hpp
- /library/src/Graph/topological_sort.hpp.html
title: src/Graph/topological_sort.hpp
---
