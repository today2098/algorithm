---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/ShortestPath/floyd_warshall.hpp
    title: "Floyd\u2013Warshall Algorithm\uFF08\u5168\u70B9\u5BFE\u9593\u6700\u77ED\
      \u7D4C\u8DEF\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C
  bundledCode: "#line 1 \"test/aoj-GRL_1_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Graph/ShortestPath/floyd_warshall.hpp\"\
    \n\n\n\n/**\n * @brief Floyd\u2013Warshall Algorithm\uFF08\u5168\u70B9\u5BFE\u9593\
    \u6700\u77ED\u7D4C\u8DEF\uFF09\n * @docs docs/Graph/ShortestPath/floyd_warshall.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\ntemplate <typename T>\nclass FloydWarshall\
    \ {\n    int m_vn;                           // m_vn:=(\u30CE\u30FC\u30C9\u6570\
    ).\n    std::vector<std::vector<T> > m_dp;  // m_dp[s][t]:=(\u30CE\u30FC\u30C9\
    s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\u96E2).\n\npublic:\n    FloydWarshall()\
    \ {}\n    explicit FloydWarshall(size_t vn) : m_vn(vn), m_dp(vn, std::vector<T>(vn,\
    \ infinity())) {}\n\n    static constexpr T infinity() { return std::numeric_limits<T>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u91CD\u307F\u4ED8\u304D\u6709\u5411\u8FBA\u3092\
    \u5F35\u308B\uFF0E\n    void add_edge(int from, int to, T cost) {\n        assert(0\
    \ <= from and from < order());\n        assert(0 <= to and to < order());\n  \
    \      m_dp[from][to] = cost;\n    }\n    // \u30B0\u30E9\u30D5\u4E0A\u306E\u5168\
    \u9802\u70B9\u5BFE\u9593\u306B\u3064\u3044\u3066\u6700\u77ED\u8DDD\u96E2\u3092\
    \u6C42\u3081\u308B\uFF0EO(|V|^3).\n    void floyd_warshall() {\n        for(int\
    \ v = 0; v < order(); ++v) m_dp[v][v] = 0;\n        for(int k = 0; k < order();\
    \ ++k) {\n            for(int s = 0; s < order(); ++s) {\n                if(m_dp[s][k]\
    \ == infinity()) continue;\n                for(int t = 0; t < order(); ++t) {\n\
    \                    if(m_dp[k][t] == infinity()) continue;\n                \
    \    m_dp[s][t] = std::min(m_dp[s][t], m_dp[s][k] + m_dp[k][t]);\n           \
    \     }\n            }\n        }\n    }\n    // \u30B0\u30E9\u30D5\u5168\u4F53\
    \u304B\u3089\u8CA0\u9589\u8DEF\u3092\u691C\u51FA\u3059\u308B\uFF0EO(|V|).\n  \
    \  bool find_negative_cycle() const {\n        for(int v = 0; v < order(); ++v)\
    \ {\n            if(m_dp[v][v] < 0) return true;  // \u8CA0\u9589\u8DEF\u3042\u308A\
    \uFF0E\n        }\n        return false;  // \u8CA0\u9589\u8DEF\u306A\u3057\uFF0E\
    \n    }\n    // \u30CE\u30FC\u30C9s\u304B\u3089t\u3078\u306E\u6700\u77ED\u8DDD\
    \u96E2\u3092\u8FD4\u3059\uFF0E\n    T distance(int s, int t) const {\n       \
    \ assert(0 <= s and s < order());\n        assert(0 <= t and t < order());\n \
    \       return m_dp[s][t];\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 6 \"test/aoj-GRL_1_C.test.cpp\"\n\nint main() {\n    int vn, en;\n    std::cin\
    \ >> vn >> en;\n\n    algorithm::FloydWarshall<long long> floyd_warshall(vn);\n\
    \    for(int i = 0; i < en; ++i) {\n        int s, t;\n        long long d;\n\
    \        std::cin >> s >> t >> d;\n        floyd_warshall.add_edge(s, t, d);\n\
    \    }\n    floyd_warshall.floyd_warshall();\n\n    if(floyd_warshall.find_negative_cycle())\
    \ {\n        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n        return 0;\n\
    \    }\n\n    for(int s = 0; s < vn; ++s) {\n        for(int t = 0; t < vn; ++t)\
    \ {\n            auto d = floyd_warshall.distance(s, t);\n            if(d ==\
    \ floyd_warshall.infinity()) std::cout << \"INF\";\n            else std::cout\
    \ << d;\n            std::cout << (t == vn - 1 ? \"\\n\" : \" \");\n        }\n\
    \    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C\"\
    \n\n#include <iostream>\n\n#include \"../src/Graph/ShortestPath/floyd_warshall.hpp\"\
    \n\nint main() {\n    int vn, en;\n    std::cin >> vn >> en;\n\n    algorithm::FloydWarshall<long\
    \ long> floyd_warshall(vn);\n    for(int i = 0; i < en; ++i) {\n        int s,\
    \ t;\n        long long d;\n        std::cin >> s >> t >> d;\n        floyd_warshall.add_edge(s,\
    \ t, d);\n    }\n    floyd_warshall.floyd_warshall();\n\n    if(floyd_warshall.find_negative_cycle())\
    \ {\n        std::cout << \"NEGATIVE CYCLE\" << std::endl;\n        return 0;\n\
    \    }\n\n    for(int s = 0; s < vn; ++s) {\n        for(int t = 0; t < vn; ++t)\
    \ {\n            auto d = floyd_warshall.distance(s, t);\n            if(d ==\
    \ floyd_warshall.infinity()) std::cout << \"INF\";\n            else std::cout\
    \ << d;\n            std::cout << (t == vn - 1 ? \"\\n\" : \" \");\n        }\n\
    \    }\n}\n"
  dependsOn:
  - src/Graph/ShortestPath/floyd_warshall.hpp
  isVerificationFile: true
  path: test/aoj-GRL_1_C.test.cpp
  requiredBy: []
  timestamp: '2024-05-02 02:00:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_1_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_1_C.test.cpp
- /verify/test/aoj-GRL_1_C.test.cpp.html
title: test/aoj-GRL_1_C.test.cpp
---
