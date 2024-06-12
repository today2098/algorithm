---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/strongly_connected_components.hpp
    title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "#line 1 \"test/yosupo-scc.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\
    \n\n#include <iostream>\n#include <queue>\n#include <vector>\n\n#line 1 \"src/Graph/strongly_connected_components.hpp\"\
    \n\n\n\n/**\n * @brief Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\
    \u5206\u5206\u89E3\uFF09\n * @docs docs/Graph/strongly_connected_components.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <stack>\n#include <utility>\n\
    #line 14 \"src/Graph/strongly_connected_components.hpp\"\n\nnamespace algorithm\
    \ {\n\n// \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\uFF0E\nclass SCC {\n    int\
    \ m_vn;                            // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    std::vector<std::vector<int>\
    \ > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ).\n\npublic:\n    SCC() : SCC(0) {}\n    explicit SCC(int vn) : m_vn(vn), m_g(vn)\
    \ {}\n\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_vn; }\n    // \u6709\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n\
    \    void add_edge(int from, int to) {\n        assert(0 <= from and from < order());\n\
    \        assert(0 <= to and to < order());\n        m_g[from].push_back(to);\n\
    \    }\n    // \u6709\u5411\u30B0\u30E9\u30D5\u3092\u5F37\u9023\u7D50\u6210\u5206\
    \u5206\u89E3\u3059\u308B\uFF0Ereturn pair of (# of SCCs, SCC id of each nodes).\
    \ O(|V|+|E|).\n    std::pair<int, std::vector<int> > decompose() const {\n   \
    \     int num_sccs = 0;               // num_sccs:=(SCCs\u306E\u6570).\n     \
    \   std::vector<int> ids(order());  // ids[v]:=(\u30CE\u30FC\u30C9v\u304C\u5C5E\
    \u3059\u308BSCC\u306EID).\n        // ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\
    \u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304C\u3051\u9806\u5E8F).\n        // low[v]:=(DFS\u6728\
    \u306B\u304A\u3044\u3066\uFF0C\u30CE\u30FC\u30C9v\u304B\u3089\u8449\u65B9\u5411\
    \u306B0\u56DE\u4EE5\u4E0A\uFF0C\u5F8C\u9000\u8FBA\u3092\u9AD8\u30051\u56DE\u7528\
    \u3044\u3066\u5230\u9054\u3067\u304D\u308B\u30CE\u30FC\u30C9w\u3067\u306Eord[w]\u306E\
    \u6700\u5C0F\u5024).\n        std::vector<int> ord(order(), -1), low(order());\n\
    \        int now = 0;\n        std::stack<int> visited;\n        auto dfs = [&](auto\
    \ self, int u) -> void {\n            ord[u] = low[u] = now++;\n            visited.push(u);\n\
    \            for(int to : m_g[u]) {\n                if(ord[to] == -1) {\n   \
    \                 self(self, to);\n                    low[u] = std::min(low[u],\
    \ low[to]);\n                } else {\n                    low[u] = std::min(low[u],\
    \ ord[to]);\n                }\n            }\n            if(low[u] == ord[u])\
    \ {\n                while(true) {\n                    int v = visited.top();\n\
    \                    visited.pop();\n                    ord[v] = order();  //\
    \ inf.\n                    ids[v] = num_sccs;\n                    if(v == u)\
    \ break;\n                }\n                num_sccs++;\n            }\n    \
    \    };\n        for(int v = 0; v < order(); ++v) {\n            if(ord[v] ==\
    \ -1) dfs(dfs, v);\n        }\n        return {num_sccs, ids};\n    }\n    //\
    \ \u5F37\u9023\u7D50\u6210\u5206\u5206\u89E3\u3054\u3068\u306B\u5404\u30CE\u30FC\
    \u30C9\u3092\u30B0\u30EB\u30FC\u30D7\u5206\u3051\u3059\u308B\uFF0E\n    std::vector<std::vector<int>\
    \ > scc(const std::pair<int, std::vector<int> > &p) const {\n        return scc(p.first,\
    \ p.second);\n    }\n    std::vector<std::vector<int> > scc(int num, const std::vector<int>\
    \ &ids) const {\n        assert((int)ids.size() == order());\n        std::vector<std::vector<int>\
    \ > sccs(num);\n        for(int v = 0; v < order(); ++v) {\n            assert(0\
    \ <= ids[v] and ids[v] < num);\n            sccs[ids[v]].push_back(v);\n     \
    \   }\n        return sccs;\n    }\n    // \u5F37\u9023\u7D50\u6210\u5206\u304B\
    \u3089\u69CB\u6210\u3055\u308C\u308BDAG\u3092\u53D6\u5F97\u3059\u308B\uFF0E\n\
    \    std::vector<std::vector<int> > directed_acyclic_graph(const std::pair<int,\
    \ std::vector<int> > &p) const {\n        return directed_acyclic_graph(p.first,\
    \ p.second);\n    }\n    std::vector<std::vector<int> > directed_acyclic_graph(int\
    \ num, const std::vector<int> &ids) const {\n        assert((int)ids.size() ==\
    \ order());\n        std::vector<std::vector<int> > dag(num);\n        for(int\
    \ u = 0; u < order(); ++u) {\n            assert(0 <= ids[u] and ids[u] < num);\n\
    \            for(int v : m_g[u]) {\n                assert(0 <= ids[v] and ids[v]\
    \ < num);\n                if(ids[u] == ids[v]) continue;\n                dag[ids[u]].push_back(ids[v]);\n\
    \            }\n        }\n        for(auto &v : dag) {\n            std::sort(v.begin(),\
    \ v.end());\n            v.erase(std::unique(v.begin(), v.end()), v.end());\n\
    \        }\n        return dag;\n    }\n};\n\n}  // namespace algorithm\n\n\n\
    #line 8 \"test/yosupo-scc.test.cpp\"\n\nint main() {\n    int n;\n    int m;\n\
    \    std::cin >> n >> m;\n\n    algorithm::SCC scc(n);\n    for(int i = 0; i <\
    \ m; ++i) {\n        int a, b;\n        std::cin >> a >> b;\n\n        scc.add_edge(a,\
    \ b);\n    }\n\n    auto &&[num, ids] = scc.decompose();\n    auto &&sccs = scc.scc(num,\
    \ ids);\n    auto &&dag = scc.directed_acyclic_graph(num, ids);\n\n    std::cout\
    \ << num << \"\\n\";\n\n    std::vector<int> degree(num, 0);\n    for(const auto\
    \ &vs : dag) {\n        for(auto v : vs) degree[v]++;\n    }\n\n    std::queue<int>\
    \ que;\n    for(int i = 0; i < num; ++i) {\n        if(degree[i] == 0) que.push(i);\n\
    \    }\n\n    while(!que.empty()) {\n        auto id = que.front();\n        que.pop();\n\
    \n        std::cout << sccs[id].size() << \" \";\n        for(auto v : sccs[id])\
    \ std::cout << v << \" \";\n        std::cout << \"\\n\";\n\n        for(auto\
    \ id2 : dag[id]) {\n            if(--degree[id2] == 0) que.push(id2);\n      \
    \  }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include <queue>\n#include <vector>\n\n#include \"../src/Graph/strongly_connected_components.hpp\"\
    \n\nint main() {\n    int n;\n    int m;\n    std::cin >> n >> m;\n\n    algorithm::SCC\
    \ scc(n);\n    for(int i = 0; i < m; ++i) {\n        int a, b;\n        std::cin\
    \ >> a >> b;\n\n        scc.add_edge(a, b);\n    }\n\n    auto &&[num, ids] =\
    \ scc.decompose();\n    auto &&sccs = scc.scc(num, ids);\n    auto &&dag = scc.directed_acyclic_graph(num,\
    \ ids);\n\n    std::cout << num << \"\\n\";\n\n    std::vector<int> degree(num,\
    \ 0);\n    for(const auto &vs : dag) {\n        for(auto v : vs) degree[v]++;\n\
    \    }\n\n    std::queue<int> que;\n    for(int i = 0; i < num; ++i) {\n     \
    \   if(degree[i] == 0) que.push(i);\n    }\n\n    while(!que.empty()) {\n    \
    \    auto id = que.front();\n        que.pop();\n\n        std::cout << sccs[id].size()\
    \ << \" \";\n        for(auto v : sccs[id]) std::cout << v << \" \";\n       \
    \ std::cout << \"\\n\";\n\n        for(auto id2 : dag[id]) {\n            if(--degree[id2]\
    \ == 0) que.push(id2);\n        }\n    }\n}\n"
  dependsOn:
  - src/Graph/strongly_connected_components.hpp
  isVerificationFile: true
  path: test/yosupo-scc.test.cpp
  requiredBy: []
  timestamp: '2024-06-12 21:13:12+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-scc.test.cpp
- /verify/test/yosupo-scc.test.cpp.html
title: test/yosupo-scc.test.cpp
---