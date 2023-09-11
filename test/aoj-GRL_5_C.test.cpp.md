---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Graph/Tree/lowest_common_ancestor.hpp
    title: "Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C
  bundledCode: "#line 1 \"test/aoj-GRL_5_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Graph/Tree/lowest_common_ancestor.hpp\"\
    \n/**\n * @brief Lowest Common Ancestor\uFF08\u6700\u8FD1\u5171\u901A\u7956\u5148\
    \uFF09\n * @docs docs/Graph/Tree/lowest_common_ancestor.md\n */\n\n#ifndef ALGORITHM_LOWEST_COMMON_ANCESTOR_HPP\n\
    #define ALGORITHM_LOWEST_COMMON_ANCESTOR_HPP 1\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <limits>\n#include <map>\n#include <stack>\n#include <utility>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// Lowest Common Ancestor\uFF08\u6700\
    \u8FD1\u5171\u901A\u7956\u5148\uFF09.\ntemplate <typename T = int>  // T:Type\
    \ of cost.\nclass LCA {\n    int m_l;                                        \
    \    // m_l:=ceiling(log2(vn)).\n    std::vector<std::vector<std::pair<int, T>\
    \ > > m_g;  // m_g[v][]:=(\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8\
    ). pair of (to, cost).\n    std::vector<std::vector<int> > m_par;            \
    \   // m_par[v][k]:=(\u30CE\u30FC\u30C9v\u304B\u30892^k\u56DE\u8FBF\u3063\u3066\
    \u5230\u9054\u3059\u308B\u89AA\u30CE\u30FC\u30C9\u756A\u53F7). \u89AA\u304C\u3044\
    \u306A\u3044\u5834\u5408\u306F-1\uFF0E\n    std::vector<int> m_depth;        \
    \                   // m_depth[v]:=(\u30CE\u30FC\u30C9v\u306E\u6DF1\u3055). \u6839\
    \u306B\u9023\u7D50\u3057\u3066\u3044\u306A\u3044\u5834\u5408\u306F-1\uFF0E\n \
    \   std::vector<T> m_dist;                              // m_dist[v]:=(\u6839\u304B\
    \u3089\u30CE\u30FC\u30C9v\u307E\u3067\u306E\u8DDD\u96E2).\n    std::vector<int>\
    \ m_ord;                             // m_ord[v]:=(DFS\u6728\u306B\u304A\u3051\
    \u308B\u30CE\u30FC\u30C9v\u306E\u884C\u304D\u304B\u3051\u9806\u5E8F).\n\n    //\
    \ \u30CE\u30FC\u30C9v\u304C\u6728\u306B\u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0EO(1).\n    bool is_included(int v) const { return m_ord[v] !=\
    \ -1; }\n    void dfs(int u, int parent, int depth, T distance, int &now) {\n\
    \        assert(m_ord[u] == -1);\n        m_ord[u] = now++;\n        m_par[u][0]\
    \ = parent;\n        m_depth[u] = depth;\n        m_dist[u] = distance;\n    \
    \    for(const auto &[v, cost] : m_g[u]) {\n            if(v == parent) continue;\n\
    \            dfs(v, u, depth + 1, distance + cost, now);\n        }\n    }\n\n\
    public:\n    LCA() : LCA(0) {}\n    explicit LCA(size_t vn) : m_l(1), m_g(vn),\
    \ m_depth(vn, -1), m_dist(vn, infinity()), m_ord(vn, -1) {\n        while(1 <<\
    \ m_l <= (int)vn - 1) m_l++;\n        m_par.assign(vn, std::vector<int>(m_l, -1));\n\
    \    }\n\n    static constexpr T infinity() { return std::numeric_limits<T>::max();\
    \ }\n    // \u30CE\u30FC\u30C9\u6570\u3092\u8FD4\u3059\uFF0E\n    int order()\
    \ const { return m_g.size(); }\n    // \u8FBA\u3092\u5F35\u308B\uFF0E\u30CE\u30FC\
    \u30C9u\u3068v\u306F\u975E\u9023\u7D50\u3067\u3042\u308B\u3053\u3068\uFF0E\n \
    \   void add_edge(int u, int v, T cost = 0) {\n        assert(0 <= u and u < order());\n\
    \        assert(0 <= v and v < order());\n        m_g[u].emplace_back(v, cost);\n\
    \        m_g[v].emplace_back(u, cost);\n    }\n    // \u7956\u5148\u6728\u3092\
    \u69CB\u7BC9\u3059\u308B\uFF0EO(|V|*log|V|).\n    void build(int root = 0) {\n\
    \        assert(0 <= root and root < order());\n        for(std::vector<int> &v\
    \ : m_par) std::fill(v.begin(), v.end(), -1);\n        std::fill(m_depth.begin(),\
    \ m_depth.end(), -1);\n        std::fill(m_dist.begin(), m_dist.end(), infinity());\n\
    \        std::fill(m_ord.begin(), m_ord.end(), -1);\n        int now = 0;\n  \
    \      dfs(root, -1, 0, 0, now);\n        for(int k = 0; k < m_l - 1; ++k) {\n\
    \            for(int v = 0; v < order(); ++v) {\n                if(m_par[v][k]\
    \ != -1) m_par[v][k + 1] = m_par[m_par[v][k]][k];\n            }\n        }\n\
    \    }\n    // \u30CE\u30FC\u30C9v\u306E\u7956\u5148\u3092k\u4EE3\u9061\u308B\uFF0E\
    O(log|V|).\n    int trace_back(int v, int k) const {\n        assert(0 <= v and\
    \ v < order());\n        assert(0 <= k and k <= order() - 1);\n        if(!is_included(v)\
    \ or k > m_depth[v]) return -1;\n        for(int i = 0; i < m_l; ++i) {\n    \
    \        if(k >> i & 1) v = m_par[v][i];\n        }\n        return v;\n    }\n\
    \    // \u6728\u4E0A\u306E\u30CE\u30FC\u30C9u\u3068v\u306E\u6700\u3082\u8FD1\u3044\
    \u5171\u901A\u306E\u7956\u5148\u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n    int\
    \ lca(int u, int v) const {\n        assert(0 <= u and u < order());\n       \
    \ assert(0 <= v and v < order());\n        if(!(is_included(u) and is_included(v)))\
    \ return -1;\n        if(m_depth[u] > m_depth[v]) std::swap(u, v);\n        v\
    \ = trace_back(v, m_depth[v] - m_depth[u]);  // \u540C\u3058\u6DF1\u3055\u306B\
    \u5408\u308F\u305B\u308B\uFF0E\n        if(u == v) return u;\n        for(int\
    \ k = m_l - 1; k >= 0; --k) {\n            if(m_par[u][k] != m_par[v][k]) u =\
    \ m_par[u][k], v = m_par[v][k];  // \u7570\u306A\u3063\u305F\u3089\u6839\u306B\
    \u8FD1\u3065\u3051\u308B\uFF0E\n        }\n        return m_par[u][0];\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u6DF1\u3055\u3092\u8FD4\u3059\uFF0EO(1).\n \
    \   T length(int v) const {\n        assert(0 <= v and v < order());\n       \
    \ return m_depth[v];\n    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u9577\u3055\
    \u3092\u6C42\u3081\u308B\uFF0EO(log|V|).\n    int length(int u, int v) const {\n\
    \        assert(0 <= u and u < order());\n        assert(0 <= v and v < order());\n\
    \        if(!(is_included(u) and is_included(v))) return -1;\n        return m_depth[u]\
    \ + m_depth[v] - 2 * m_depth[lca(u, v)];\n    }\n    // \u6839\u3068\u30CE\u30FC\
    \u30C9v\u9593\u306E\u8DDD\u96E2\u3092\u8FD4\u3059\uFF0EO(1).\n    T distance(int\
    \ v) const {\n        assert(0 <= v and v < order());\n        return m_dist[v];\n\
    \    }\n    // \u30CE\u30FC\u30C9u, v\u9593\u306E\u8DDD\u96E2\u3092\u6C42\u3081\
    \u308B\uFF0EO(log|V|).\n    T distance(int u, int v) const {\n        assert(0\
    \ <= u and u < order());\n        assert(0 <= v and v < order());\n        if(!(is_included(u)\
    \ and is_included(v))) return infinity();\n        return m_dist[u] + m_dist[v]\
    \ - 2 * m_dist[lca(u, v)];\n    }\n    // \u6728\u306E\u5EA7\u6A19\u5727\u7E2E\
    \uFF0EO(K*log|V|).\n    std::pair<int, std::map<int, std::vector<int> > > auxiliary_tree(std::vector<int>\
    \ &vs) const {\n        assert(std::find_if(vs.begin(), vs.end(), [&](int v) ->\
    \ bool { return !(0 <= v and v < order()); }) == vs.end());\n        std::map<int,\
    \ std::vector<int> > res;  // res[v][]:=(\u5727\u7E2E\u3057\u305F\u6728\u306B\u304A\
    \u3051\u308B\u30CE\u30FC\u30C9v\u306E\u96A3\u63A5\u30EA\u30B9\u30C8).\n      \
    \  const int n = vs.size();\n        if(n == 0 or std::find_if(vs.begin(), vs.end(),\
    \ [&](int v) -> bool { return !is_included(v); }) != vs.end()) return {-1, res};\n\
    \        auto comp = [&](int u, int v) -> bool { return m_ord[u] < m_ord[v]; };\n\
    \        std::sort(vs.begin(), vs.end(), comp);\n        std::stack<int> st;\n\
    \        st.push(vs[0]);\n        for(int i = 1; i < n; ++i) {\n            int\
    \ w = lca(vs[i - 1], vs[i]);\n            if(w != vs[i - 1]) {\n             \
    \   int v = st.top();\n                st.pop();\n                while(!st.empty()\
    \ and m_depth[st.top()] > m_depth[w]) {\n                    res[st.top()].push_back(v);\n\
    \                    res[v].push_back(st.top());\n                    v = st.top();\n\
    \                    st.pop();\n                }\n                if(st.empty()\
    \ or st.top() != w) {\n                    st.push(w);\n                    vs.push_back(w);\n\
    \                }\n                res[w].push_back(v);\n                res[v].push_back(w);\n\
    \            }\n            st.push(vs[i]);\n        }\n        while(st.size()\
    \ > 1) {\n            int v = st.top();\n            st.pop();\n            res[st.top()].push_back(v);\n\
    \            res[v].push_back(st.top());\n        }\n        std::sort(vs.begin(),\
    \ vs.end(), comp);\n        return {st.top(), res};  // pair of (root, tree).\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n#line 6 \"test/aoj-GRL_5_C.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::LCA lca(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        int k;\n        std::cin >> k;\n\n\
    \        for(int j = 0; j < k; ++j) {\n            int c;\n            std::cin\
    \ >> c;\n            lca.add_edge(i, c);\n        }\n    }\n    lca.build();\n\
    \n    int q;\n    std::cin >> q;\n\n    while(q--) {\n        int u, v;\n    \
    \    std::cin >> u >> v;\n        std::cout << lca.lca(u, v) << std::endl;\n \
    \   }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_C\"\
    \n\n#include <iostream>\n\n#include \"../src/Graph/Tree/lowest_common_ancestor.hpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::LCA lca(n);\n\
    \    for(int i = 0; i < n; ++i) {\n        int k;\n        std::cin >> k;\n\n\
    \        for(int j = 0; j < k; ++j) {\n            int c;\n            std::cin\
    \ >> c;\n            lca.add_edge(i, c);\n        }\n    }\n    lca.build();\n\
    \n    int q;\n    std::cin >> q;\n\n    while(q--) {\n        int u, v;\n    \
    \    std::cin >> u >> v;\n        std::cout << lca.lca(u, v) << std::endl;\n \
    \   }\n}\n"
  dependsOn:
  - src/Graph/Tree/lowest_common_ancestor.hpp
  isVerificationFile: true
  path: test/aoj-GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2023-08-31 17:50:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-GRL_5_C.test.cpp
- /verify/test/aoj-GRL_5_C.test.cpp.html
title: test/aoj-GRL_5_C.test.cpp
---