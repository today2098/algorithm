---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://o-treetree.hatenablog.com/entry/2020/06/08/231258\uFF08\u53C2\u7167\
      2022.9.13\uFF09\uFF0E"
  bundledCode: "#line 1 \"src/Graph/low_link.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n\
    class LowLink {\n    std::vector<std::vector<int> > m_g;       // m_g[v][]:=(\u9802\
    \u70B9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n    std::vector<int> m_aps;   \
    \                // m_aps[]:=(\u95A2\u7BC0\u70B9\u306E\u30EA\u30B9\u30C8). Articulations\
    \ points.\n    std::vector<std::pair<int, int> > m_brs;  // m_brs[]:=(\u6A4B\u306E\
    \u30EA\u30B9\u30C8). Bridges.\n\n    void dfs(int u, int parent, std::vector<int>\
    \ &ord, std::vector<int> &low, int &now) {\n        ord[u] = low[u] = now++;\n\
    \        int degree = 0;      // DFS\u6728\u3067\u306E\u9802\u70B9u\u306B\u304A\
    \u3051\u308B\u8449\u65B9\u5411\u3078\u306E\u51FA\u6B21\u6570\uFF0E\n        bool\
    \ is_ap = false;  // \u9802\u70B9u\u304C\u95A2\u7BC0\u70B9\u304B\u5426\u304B\uFF0E\
    \n        for(int v : m_g[u]) {\n            if(v == parent) continue;\n     \
    \       if(ord[v] == -1) {  // \u9802\u70B9v\u304C\u672A\u8A2A\u554F\u306E\u3068\
    \u304D\uFF0E\n                degree++;\n                dfs(v, u, ord, low, now);\n\
    \                low[u] = std::min(low[u], low[v]);\n                if(ord[u]\
    \ < low[v]) {  // \u8FBA(u,v)\u304C\u6A4B\u306E\u3068\u304D\uFF0E\n          \
    \          if(u < v) m_brs.emplace_back(u, v);\n                    else m_brs.emplace_back(v,\
    \ u);\n                }\n                if(parent != -1 and ord[u] <= low[v])\
    \ is_ap = true;  // \u6839\u4EE5\u5916\u3067\u95A2\u7BC0\u70B9\u306E\u3068\u304D\
    \uFF0E\n            } else {                                                 //\
    \ \u8FBA(u,v)\u304C\u5F8C\u9000\u8FBA\u306E\u3068\u304D\uFF0E\n              \
    \  low[u] = std::min(low[u], ord[v]);\n            }\n        }\n        if(parent\
    \ == -1 and degree > 1) is_ap = true;  // \u6839\u304C\u95A2\u7BC0\u70B9\u306E\
    \u3068\u304D\uFF0E\n        if(is_ap) m_aps.push_back(u);\n    }\n\npublic:\n\
    \    LowLink() : LowLink(0) {}\n    explicit LowLink(size_t vn) : m_g(vn) {}\n\
    \n    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return\
    \ m_g.size(); }\n    // \u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u and u < order());\n        assert(0 <= v\
    \ and v < order());\n        m_g[u].push_back(v);\n        m_g[v].push_back(u);\n\
    \    }\n    // \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6A4B\u3068\u95A2\u7BC0\u70B9\
    \u3092\u6C42\u3081\u308B\uFF0EO(|V|+|E|).\n    void lowlink() {\n        m_aps.clear();\n\
    \        m_brs.clear();\n        // ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\
    \u9802\u70B9v\u306E\u884C\u304D\u304B\u3051\u9806\u5E8F).\n        // low[v]:=(DFS\u6728\
    \u306B\u304A\u3044\u3066\uFF0C\u9802\u70B9v\u304B\u3089\u8449\u65B9\u5411\u306B\
    0\u56DE\u4EE5\u4E0A\uFF0C\u5F8C\u9000\u8FBA\u3092\u9AD8\u30051\u56DE\u7528\u3044\
    \u3066\u5230\u9054\u3067\u304D\u308B\u9802\u70B9w\u306Eord[w]\u306E\u6700\u5C0F\
    \u5024).\n        std::vector<int> ord(order(), -1), low(order());\n        int\
    \ now = 0;\n        for(int v = 0; v < order(); ++v) {\n            if(ord[v]\
    \ == -1) dfs(v, -1, ord, low, now);\n        }\n        std::sort(m_aps.begin(),\
    \ m_aps.end());\n        std::sort(m_brs.begin(), m_brs.end());\n    }\n    //\
    \ \u95A2\u7BC0\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\uFF0E\
    \n    const std::vector<int> &get_points() const { return m_aps; }\n    // \u6A4B\
    \u306E\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\uFF0E\n    const std::vector<std::pair<int,\
    \ int> > &get_bridges() const { return m_brs; }\n};\n\n}  // namespace algorithm\n\
    \n\n\n/*\n\u53C2\u8003\u6587\u732E\n- o-treetree, \u30B0\u30E9\u30D5\u306E\u95A2\
    \u7BC0\u70B9\u3068\u6A4B\u3092\u6C42\u3081\u3066\u518D\u5E30DFS\u3092\u77E5\u308B\
    \uFF0CHatenaBlog, https://o-treetree.hatenablog.com/entry/2020/06/08/231258\uFF08\
    \u53C2\u71672022.9.13\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_LOW_LINK_HPP\n#define ALGORITHM_LOW_LINK_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\nclass LowLink {\n    std::vector<std::vector<int> > m_g;    \
    \   // m_g[v][]:=(\u9802\u70B9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n    std::vector<int>\
    \ m_aps;                   // m_aps[]:=(\u95A2\u7BC0\u70B9\u306E\u30EA\u30B9\u30C8\
    ). Articulations points.\n    std::vector<std::pair<int, int> > m_brs;  // m_brs[]:=(\u6A4B\
    \u306E\u30EA\u30B9\u30C8). Bridges.\n\n    void dfs(int u, int parent, std::vector<int>\
    \ &ord, std::vector<int> &low, int &now) {\n        ord[u] = low[u] = now++;\n\
    \        int degree = 0;      // DFS\u6728\u3067\u306E\u9802\u70B9u\u306B\u304A\
    \u3051\u308B\u8449\u65B9\u5411\u3078\u306E\u51FA\u6B21\u6570\uFF0E\n        bool\
    \ is_ap = false;  // \u9802\u70B9u\u304C\u95A2\u7BC0\u70B9\u304B\u5426\u304B\uFF0E\
    \n        for(int v : m_g[u]) {\n            if(v == parent) continue;\n     \
    \       if(ord[v] == -1) {  // \u9802\u70B9v\u304C\u672A\u8A2A\u554F\u306E\u3068\
    \u304D\uFF0E\n                degree++;\n                dfs(v, u, ord, low, now);\n\
    \                low[u] = std::min(low[u], low[v]);\n                if(ord[u]\
    \ < low[v]) {  // \u8FBA(u,v)\u304C\u6A4B\u306E\u3068\u304D\uFF0E\n          \
    \          if(u < v) m_brs.emplace_back(u, v);\n                    else m_brs.emplace_back(v,\
    \ u);\n                }\n                if(parent != -1 and ord[u] <= low[v])\
    \ is_ap = true;  // \u6839\u4EE5\u5916\u3067\u95A2\u7BC0\u70B9\u306E\u3068\u304D\
    \uFF0E\n            } else {                                                 //\
    \ \u8FBA(u,v)\u304C\u5F8C\u9000\u8FBA\u306E\u3068\u304D\uFF0E\n              \
    \  low[u] = std::min(low[u], ord[v]);\n            }\n        }\n        if(parent\
    \ == -1 and degree > 1) is_ap = true;  // \u6839\u304C\u95A2\u7BC0\u70B9\u306E\
    \u3068\u304D\uFF0E\n        if(is_ap) m_aps.push_back(u);\n    }\n\npublic:\n\
    \    LowLink() : LowLink(0) {}\n    explicit LowLink(size_t vn) : m_g(vn) {}\n\
    \n    // \u9802\u70B9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order() const { return\
    \ m_g.size(); }\n    // \u7121\u5411\u8FBA\u3092\u5F35\u308B\uFF0E\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u and u < order());\n        assert(0 <= v\
    \ and v < order());\n        m_g[u].push_back(v);\n        m_g[v].push_back(u);\n\
    \    }\n    // \u7121\u5411\u30B0\u30E9\u30D5\u306E\u6A4B\u3068\u95A2\u7BC0\u70B9\
    \u3092\u6C42\u3081\u308B\uFF0EO(|V|+|E|).\n    void lowlink() {\n        m_aps.clear();\n\
    \        m_brs.clear();\n        // ord[v]:=(DFS\u6728\u306B\u304A\u3051\u308B\
    \u9802\u70B9v\u306E\u884C\u304D\u304B\u3051\u9806\u5E8F).\n        // low[v]:=(DFS\u6728\
    \u306B\u304A\u3044\u3066\uFF0C\u9802\u70B9v\u304B\u3089\u8449\u65B9\u5411\u306B\
    0\u56DE\u4EE5\u4E0A\uFF0C\u5F8C\u9000\u8FBA\u3092\u9AD8\u30051\u56DE\u7528\u3044\
    \u3066\u5230\u9054\u3067\u304D\u308B\u9802\u70B9w\u306Eord[w]\u306E\u6700\u5C0F\
    \u5024).\n        std::vector<int> ord(order(), -1), low(order());\n        int\
    \ now = 0;\n        for(int v = 0; v < order(); ++v) {\n            if(ord[v]\
    \ == -1) dfs(v, -1, ord, low, now);\n        }\n        std::sort(m_aps.begin(),\
    \ m_aps.end());\n        std::sort(m_brs.begin(), m_brs.end());\n    }\n    //\
    \ \u95A2\u7BC0\u70B9\u306E\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\uFF0E\
    \n    const std::vector<int> &get_points() const { return m_aps; }\n    // \u6A4B\
    \u306E\u30EA\u30B9\u30C8\u3092\u53C2\u7167\u3059\u308B\uFF0E\n    const std::vector<std::pair<int,\
    \ int> > &get_bridges() const { return m_brs; }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\n- o-treetree, \u30B0\u30E9\u30D5\u306E\
    \u95A2\u7BC0\u70B9\u3068\u6A4B\u3092\u6C42\u3081\u3066\u518D\u5E30DFS\u3092\u77E5\
    \u308B\uFF0CHatenaBlog, https://o-treetree.hatenablog.com/entry/2020/06/08/231258\uFF08\
    \u53C2\u71672022.9.13\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/low_link.hpp
  requiredBy: []
  timestamp: '2023-08-22 20:50:53+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Graph/low_link.hpp
layout: document
redirect_from:
- /library/src/Graph/low_link.hpp
- /library/src/Graph/low_link.hpp.html
title: src/Graph/low_link.hpp
---