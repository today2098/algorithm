---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_1_A.test.cpp
    title: test/aoj-DSL_1_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/union_find.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7D20\u96C6\u5408\u30C7\u30FC\
    \u30BF\u69CB\u9020\uFF0E\nclass UnionFind {\n    int m_vn;                // m_vn:=(\u30CE\
    \u30FC\u30C9\u6570).\n    int m_gn;                // m_gn:=(\u9023\u7D50\u6210\
    \u5206\u6570).\n    std::vector<int> m_par;  // m_par[v]:=(\u30CE\u30FC\u30C9\
    v\u306E\u89AA\u756A\u53F7). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cv\u306F\u6839\
    \u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n\npublic:\n    UnionFind()\
    \ : UnionFind(0) {}\n    explicit UnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn,\
    \ -1) {}\n\n    // \u30CE\u30FC\u30C9\u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\
    \n    int vn() const { return m_vn; };\n    // \u9023\u7D50\u6210\u5206\u306E\u6570\
    \u3092\u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n    // \u30CE\u30FC\
    \u30C9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u6839\u756A\u53F7\
    \u3092\u8FD4\u3059\uFF0E\n    int root(int v) {\n        assert(0 <= v and v <\
    \ vn());\n        if(m_par[v] < 0) return v;\n        return m_par[v] = root(m_par[v]);\n\
    \    }\n    // \u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int v) {\n    \
    \    assert(0 <= v and v < vn());\n        return -m_par[root(v)];\n    }\n  \
    \  // \u30CE\u30FC\u30C9u\u3068v\u304C\u9023\u7D50\u3057\u3066\u3044\u308B\u304B\
    \u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_same(int u, int v) {\n        assert(0\
    \ <= u and u < vn());\n        assert(0 <= v and v < vn());\n        return root(u)\
    \ == root(v);\n    }\n    // \u30CE\u30FC\u30C9u\u3068v\u306E\u5C5E\u3059\u308B\
    \u9023\u7D50\u6210\u5206\u3092\u7E4B\u3052\u308B\uFF0E\n    bool unite(int u,\
    \ int v) {\n        assert(0 <= u and u < vn());\n        assert(0 <= v and v\
    \ < vn());\n        u = root(u), v = root(v);\n        if(u == v) return false;\
    \                // Do nothing.\n        if(size(u) < size(v)) std::swap(u, v);\
    \  // Merge technique.\n        m_par[u] += m_par[v];\n        m_par[v] = u;\n\
    \        m_gn--;\n        return true;\n    }\n    void reset() {\n        m_gn\
    \ = vn();\n        std::fill(m_par.begin(), m_par.end(), -1);\n    }\n};\n\n}\
    \  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_UNION_FIND_HPP\n#define ALGORITHM_UNION_FIND_HPP 1\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D20\u96C6\
    \u5408\u30C7\u30FC\u30BF\u69CB\u9020\uFF0E\nclass UnionFind {\n    int m_vn; \
    \               // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int m_gn;          \
    \      // m_gn:=(\u9023\u7D50\u6210\u5206\u6570).\n    std::vector<int> m_par;\
    \  // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7). 0\u672A\u6E80\u306E\
    \u5834\u5408\uFF0Cv\u306F\u6839\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\
    \u5024\u306F\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\
    \uFF0E\n\npublic:\n    UnionFind() : UnionFind(0) {}\n    explicit UnionFind(size_t\
    \ vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}\n\n    // \u30CE\u30FC\u30C9\u306E\
    \u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n \
    \   // \u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn()\
    \ const { return m_gn; };\n    // \u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\u308B\u9023\
    \u7D50\u6210\u5206\u306E\u6839\u756A\u53F7\u3092\u8FD4\u3059\uFF0E\n    int root(int\
    \ v) {\n        assert(0 <= v and v < vn());\n        if(m_par[v] < 0) return\
    \ v;\n        return m_par[v] = root(m_par[v]);\n    }\n    // \u30CE\u30FC\u30C9\
    v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\
    \u8FD4\u3059\uFF0E\n    int size(int v) {\n        assert(0 <= v and v < vn());\n\
    \        return -m_par[root(v)];\n    }\n    // \u30CE\u30FC\u30C9u\u3068v\u304C\
    \u9023\u7D50\u3057\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n   \
    \ bool is_same(int u, int v) {\n        assert(0 <= u and u < vn());\n       \
    \ assert(0 <= v and v < vn());\n        return root(u) == root(v);\n    }\n  \
    \  // \u30CE\u30FC\u30C9u\u3068v\u306E\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\
    \u3092\u7E4B\u3052\u308B\uFF0E\n    bool unite(int u, int v) {\n        assert(0\
    \ <= u and u < vn());\n        assert(0 <= v and v < vn());\n        u = root(u),\
    \ v = root(v);\n        if(u == v) return false;                // Do nothing.\n\
    \        if(size(u) < size(v)) std::swap(u, v);  // Merge technique.\n       \
    \ m_par[u] += m_par[v];\n        m_par[v] = u;\n        m_gn--;\n        return\
    \ true;\n    }\n    void reset() {\n        m_gn = vn();\n        std::fill(m_par.begin(),\
    \ m_par.end(), -1);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/union_find.hpp
  requiredBy: []
  timestamp: '2023-03-02 14:32:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_1_A.test.cpp
documentation_of: src/DataStructure/union_find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/union_find.hpp
- /library/src/DataStructure/union_find.hpp.html
title: src/DataStructure/union_find.hpp
---
