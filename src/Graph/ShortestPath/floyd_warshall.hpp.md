---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Graph/ShortestPath/floyd_warshall.md
    document_title: "Floyd\u2013Warshall Algorithm\uFF08\u5168\u70B9\u5BFE\u9593\u6700\
      \u77ED\u7D4C\u8DEF\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Graph/ShortestPath/floyd_warshall.hpp\"\n\n\n\n/**\n\
    \ * @brief Floyd\u2013Warshall Algorithm\uFF08\u5168\u70B9\u5BFE\u9593\u6700\u77ED\
    \u7D4C\u8DEF\uFF09\n * @docs docs/Graph/ShortestPath/floyd_warshall.md\n */\n\n\
    #include <algorithm>\n#include <cassert>\n#include <limits>\n#include <vector>\n\
    \nnamespace algorithm {\n\ntemplate <typename T>\nclass FloydWarshall {\n    int\
    \ m_vn;                           // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<T>\
    \ > m_dp;  // m_dp[u][v]:=(\u30CE\u30FC\u30C9u-v\u9593\u306E\u6700\u77ED\u8DDD\
    \u96E2).\n\npublic:\n    FloydWarshall() {}\n    explicit FloydWarshall(size_t\
    \ vn) : m_vn(vn), m_dp(vn, std::vector<T>(vn, infinity())) {}\n\n    static constexpr\
    \ T infinity() { return std::numeric_limits<T>::max(); }\n    // \u30CE\u30FC\u30C9\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return m_vn; }\n    //\
    \ \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void\
    \ add_edge(int from, int to, T cost) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        m_dp[from][to] = cost;\n \
    \   }\n    // \u30B0\u30E9\u30D5\u4E0A\u306E\u5168\u9802\u70B9\u5BFE\u9593\u306B\
    \u3064\u3044\u3066\u6700\u77ED\u8DDD\u96E2\u3092\u6C42\u3081\u308B\uFF0EO(|V|^3).\n\
    \    void floyd_warshall() {\n        for(int v = 0; v < order(); ++v) m_dp[v][v]\
    \ = 0;\n        for(int k = 0; k < order(); ++k) {\n            for(int u = 0;\
    \ u < order(); ++u) {\n                for(int v = 0; v < order(); ++v) m_dp[u][v]\
    \ = std::min(m_dp[u][v], m_dp[u][k] + m_dp[k][v]);\n            }\n        }\n\
    \    }\n    // \u30B0\u30E9\u30D5\u5168\u4F53\u304B\u3089\u8CA0\u9589\u8DEF\u3092\
    \u691C\u51FA\u3059\u308B\uFF0EO(|V|).\n    bool find_negative_cycle() const {\n\
    \        for(int v = 0; v < order(); ++v) {\n            if(m_dp[v][v] < 0) return\
    \ true;  // \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n        }\n        return false;\
    \  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\n    }\n    // \u30CE\u30FC\u30C9s\u304B\
    \u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8FD4\u3059\uFF0E\n    T distance(int\
    \ s, int t) const {\n        assert(0 <= s and s < order());\n        assert(0\
    \ <= t and t < order());\n        return m_dp[s][t];\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_FLOYD_WARSHALL_HPP\n#define ALGORITHM_FLOYD_WARSHALL_HPP\
    \ 1\n\n/**\n * @brief Floyd\u2013Warshall Algorithm\uFF08\u5168\u70B9\u5BFE\u9593\
    \u6700\u77ED\u7D4C\u8DEF\uFF09\n * @docs docs/Graph/ShortestPath/floyd_warshall.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\ntemplate <typename T>\nclass FloydWarshall\
    \ {\n    int m_vn;                           // m_vn:=(\u30CE\u30FC\u30C9\u6570\
    ).\n    std::vector<std::vector<T> > m_dp;  // m_dp[u][v]:=(\u30CE\u30FC\u30C9\
    u-v\u9593\u306E\u6700\u77ED\u8DDD\u96E2).\n\npublic:\n    FloydWarshall() {}\n\
    \    explicit FloydWarshall(size_t vn) : m_vn(vn), m_dp(vn, std::vector<T>(vn,\
    \ infinity())) {}\n\n    static constexpr T infinity() { return std::numeric_limits<T>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\
    \u5F35\u308B\uFF0E\n    void add_edge(int from, int to, T cost) {\n        assert(0\
    \ <= from and from < order());\n        assert(0 <= to and to < order());\n  \
    \      m_dp[from][to] = cost;\n    }\n    // \u30B0\u30E9\u30D5\u4E0A\u306E\u5168\
    \u9802\u70B9\u5BFE\u9593\u306B\u3064\u3044\u3066\u6700\u77ED\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\uFF0EO(|V|^3).\n    void floyd_warshall() {\n        for(int\
    \ v = 0; v < order(); ++v) m_dp[v][v] = 0;\n        for(int k = 0; k < order();\
    \ ++k) {\n            for(int u = 0; u < order(); ++u) {\n                for(int\
    \ v = 0; v < order(); ++v) m_dp[u][v] = std::min(m_dp[u][v], m_dp[u][k] + m_dp[k][v]);\n\
    \            }\n        }\n    }\n    // \u30B0\u30E9\u30D5\u5168\u4F53\u304B\u3089\
    \u8CA0\u9589\u8DEF\u3092\u691C\u51FA\u3059\u308B\uFF0EO(|V|).\n    bool find_negative_cycle()\
    \ const {\n        for(int v = 0; v < order(); ++v) {\n            if(m_dp[v][v]\
    \ < 0) return true;  // \u8CA0\u9589\u8DEF\u3042\u308A\uFF0E\n        }\n    \
    \    return false;  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\n    }\n    // \u30CE\
    \u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2\u3092\u8FD4\u3059\
    \uFF0E\n    T distance(int s, int t) const {\n        assert(0 <= s and s < order());\n\
    \        assert(0 <= t and t < order());\n        return m_dp[s][t];\n    }\n\
    };\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/ShortestPath/floyd_warshall.hpp
  requiredBy: []
  timestamp: '2024-04-30 01:56:21+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/ShortestPath/floyd_warshall.hpp
layout: document
redirect_from:
- /library/src/Graph/ShortestPath/floyd_warshall.hpp
- /library/src/Graph/ShortestPath/floyd_warshall.hpp.html
title: "Floyd\u2013Warshall Algorithm\uFF08\u5168\u70B9\u5BFE\u9593\u6700\u77ED\u7D4C\
  \u8DEF\uFF09"
---
## 概要

重み付き有向グラフにおける全点対間最短経路問題を解くアルゴリズム．
名称は，考案者である Stephen Warshall と Robert W. Floyd にちなむ．

計算量は，グラフのノード数を $|V|$ とすると，$\mathcal{O}(\lvert V \rvert ^3)$ となる．


## 参考文献

1. 大槻 兼資. "14.7 全点対間最短路問題：フロイド・ワーシャル法". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉 拓哉監修. 講談社, 2020, p.264-267. 
1. "ワーシャル–フロイド法". Wikipedia. <https://ja.wikipedia.org/wiki/ワーシャル–フロイド法>.
