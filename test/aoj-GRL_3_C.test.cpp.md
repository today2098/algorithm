---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/strongly_connected_components.hpp
    title: "\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C
  bundledCode: "#line 1 \"test/aoj-GRL_3_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Graph/strongly_connected_components.hpp\"\
    \n/**\n * @brief \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\n * @docs docs/Graph/strongly_connected_components.md\n\
    \ */\n\n#ifndef ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP\n#define ALGORITHM_STRONGLY_CONNECTED_COMPONENTS_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\uFF0E\nclass SCC {\n    std::vector<std::vector<int> > m_g;  // m_g[v][]:=(\u30CE\
    \u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n\npublic:\n    SCC() : SCC(0)\
    \ {}\n    explicit SCC(int vn) : m_g(vn) {}\n\n    // \u30CE\u30FC\u30C9\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int order() const { return m_g.size(); }\n    //\
    \ \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int from, int\
    \ to) {\n        assert(0 <= from and from < order());\n        assert(0 <= to\
    \ and to < order());\n        m_g[from].push_back(to);\n    }\n    // return pair\
    \ of (# of SCCs, SCC id of each nodes).\n    std::pair<int, std::vector<int> >\
    \ scc() const {\n        int num_sccs = 0;               // num_sccs:=(SCCs\u306E\
    \u6570).\n        std::vector<int> ids(order());  // ids[v]:=(\u30CE\u30FC\u30C9\
    v\u304C\u5C5E\u3059\u308BSCC\u306EID).\n        // ord[v]:=(DFS\u6728\u306B\u304A\
    \u3051\u308B\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F).\n\
    \        // low[v]:=(DFS\u6728\u306B\u304A\u3044\u3066\uFF0C\u30CE\u30FC\u30C9\
    v\u304B\u3089\u8449\u65B9\u5411\u306B0\u56DE\u4EE5\u4E0A\uFF0C\u5F8C\u9000\u8FBA\
    \u3092\u9AD8\u30051\u56DE\u7528\u3044\u3066\u5230\u9054\u3067\u304D\u308B\u30CE\
    \u30FC\u30C9w\u3067\u306Eord[w]\u306E\u6700\u5C0F\u5024).\n        std::vector<int>\
    \ ord(order(), -1), low(order());\n        int now = 0;\n        std::stack<int>\
    \ visited;\n        auto dfs = [&](auto self, int u) -> void {\n            ord[u]\
    \ = low[u] = now++;\n            visited.push(u);\n            for(int to : m_g[u])\
    \ {\n                if(ord[to] == -1) {\n                    self(self, to);\n\
    \                    low[u] = std::min(low[u], low[to]);\n                } else\
    \ {\n                    low[u] = std::min(low[u], ord[to]);\n               \
    \ }\n            }\n            if(low[u] == ord[u]) {\n                while(true)\
    \ {\n                    int v = visited.top();\n                    visited.pop();\n\
    \                    ord[v] = order();  // inf.\n                    ids[v] =\
    \ num_sccs;\n                    if(v == u) break;\n                }\n      \
    \          num_sccs++;\n            }\n        };\n        for(int v = 0, n =\
    \ order(); v < n; ++v) {\n            if(ord[v] == -1) dfs(dfs, v);\n        }\n\
    \        return {num_sccs, ids};\n    }\n    // \u6709\u5411\u30B0\u30E9\u30D5\
    \u3092\u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3059\u308B\uFF0EO(|V|+|E|).\n\
    \    std::vector<std::vector<int> > decompose() const {\n        const auto &&[num_sccs,\
    \ ids] = scc();\n        std::vector<std::vector<int> > sccs(num_sccs);\n    \
    \    for(int v = 0, n = order(); v < n; ++v) sccs[ids[v]].push_back(v);\n    \
    \    return sccs;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n#line 6 \"\
    test/aoj-GRL_3_C.test.cpp\"\n\nint main() {\n    int n, m;\n    std::cin >> n\
    \ >> m;\n\n    algorithm::SCC scc(n);\n    for(int i = 0; i < m; ++i) {\n    \
    \    int s, t;\n        std::cin >> s >> t;\n\n        scc.add_edge(s, t);\n \
    \   }\n    auto &&[_, ids] = scc.scc();\n\n    int q;\n    std::cin >> q;\n\n\
    \    while(q--) {\n        int u, v;\n        std::cin >> u >> v;\n\n        std::cout\
    \ << (ids[u] == ids[v]) << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C\"\
    \n\n#include <iostream>\n\n#include \"../src/Graph/strongly_connected_components.hpp\"\
    \n\nint main() {\n    int n, m;\n    std::cin >> n >> m;\n\n    algorithm::SCC\
    \ scc(n);\n    for(int i = 0; i < m; ++i) {\n        int s, t;\n        std::cin\
    \ >> s >> t;\n\n        scc.add_edge(s, t);\n    }\n    auto &&[_, ids] = scc.scc();\n\
    \n    int q;\n    std::cin >> q;\n\n    while(q--) {\n        int u, v;\n    \
    \    std::cin >> u >> v;\n\n        std::cout << (ids[u] == ids[v]) << std::endl;\n\
    \    }\n}\n"
  dependsOn:
  - src/Graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/aoj-GRL_3_C.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 15:05:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_3_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_3_C.test.cpp
- /verify/test/aoj-GRL_3_C.test.cpp.html
title: test/aoj-GRL_3_C.test.cpp
---
