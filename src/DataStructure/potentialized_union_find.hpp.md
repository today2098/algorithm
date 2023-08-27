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
  bundledCode: "#line 1 \"src/DataStructure/potentialized_union_find.hpp\"\n\n\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u91CD\u307F\
    \u4ED8\u304DUnion-Find Tree\uFF0E\ntemplate <typename T>\nclass PotentializedUnionFind\
    \ {\n    int m_vn;                // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int\
    \ m_gn;                // m_gn:=(\u9023\u7D50\u6210\u5206\u6570).\n    std::vector<int>\
    \ m_par;  // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7). 0\u672A\u6E80\
    \u306E\u5834\u5408\uFF0Cv\u306F\u6839\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\
    \u5BFE\u5024\u306F\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8868\
    \u3059\uFF0E\n    std::vector<T> m_p;      // m_p[v]:=(\u30CE\u30FC\u30C9v\u306E\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB).\n\npublic:\n    PotentializedUnionFind()\
    \ : PotentializedUnionFind(0) {}\n    explicit PotentializedUnionFind(size_t vn)\
    \ : m_vn(vn), m_gn(vn), m_par(vn, -1), m_p(vn, 0) {}\n\n    // \u30CE\u30FC\u30C9\
    \u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn;\
    \ };\n    // \u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u8FD4\u3059\uFF0E\n  \
    \  int gn() const { return m_gn; };\n    // \u30CE\u30FC\u30C9v\u306E\u89AA\u756A\
    \u53F7\u3092\u8FD4\u3059\uFF0E\n    int root(int v) {\n        assert(0 <= v and\
    \ v < vn());\n        if(m_par[v] < 0) return v;\n        auto res = root(m_par[v]);\
    \  // recrusion.\n        m_p[v] += m_p[m_par[v]];\n        return m_par[v] =\
    \ res;\n    }\n    // \u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int v) {\n\
    \        assert(0 <= v and v < vn());\n        return -m_par[root(v)];\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\
    \u3059\uFF0E\n    T potential(int v) {\n        assert(0 <= v and v < vn());\n\
    \        root(v);\n        return m_p[v];\n    }\n    // \u30CE\u30FC\u30C9u\u3068\
    v\u304C\u9023\u7D50\u3057\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\
    \n    bool same(int u, int v) {\n        assert(0 <= u and u < vn());\n      \
    \  assert(0 <= v and v < vn());\n        return root(u) == root(v);\n    }\n \
    \   // \u30CE\u30FC\u30C9u\u306B\u5BFE\u3059\u308Bv\u306E\u76F8\u5BFE\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\uFF0E\n    T difference(int u, int\
    \ v) {\n        assert(0 <= u and u < vn());\n        assert(0 <= v and v < vn());\n\
    \        return potential(v) - potential(u);\n    }\n    // difference(u,v)=d\u3068\
    \u306A\u308B\u3088\u3046\u306B\u30CE\u30FC\u30C9u\u3068v\u305D\u308C\u305E\u308C\
    \u306E\u89AA\u30CE\u30FC\u30C9\u3092\u9023\u7D50\u3059\u308B\uFF0E\n    bool unite(int\
    \ u, int v, T d) {\n        assert(0 <= u and u < vn());\n        assert(0 <=\
    \ v and v < vn());\n        d = d + potential(u) - potential(v);\n        u =\
    \ root(u), v = root(v);\n        if(u == v) return false;  // Do nothing.\n  \
    \      if(size(u) < size(v)) {   // Merge technique.\n            std::swap(u,\
    \ v);\n            d = -d;\n        }\n        m_par[u] += m_par[v];\n       \
    \ m_par[v] = u;\n        m_p[v] = d;\n        m_gn--;\n        return true;\n\
    \    }\n    void reset() {\n        m_gn = vn();\n        std::fill(m_par.begin(),\
    \ m_par.end(), -1);\n        std::fill(m_p.begin(), m_p.end(), 0);\n    }\n};\n\
    \n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_POTENTIALIZED_UNION_FIND_HPP\n#define ALGORITHM_POTENTIALIZED_UNION_FIND_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u91CD\
    \u307F\u4ED8\u304DUnion-Find Tree\uFF0E\ntemplate <typename T>\nclass PotentializedUnionFind\
    \ {\n    int m_vn;                // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int\
    \ m_gn;                // m_gn:=(\u9023\u7D50\u6210\u5206\u6570).\n    std::vector<int>\
    \ m_par;  // m_par[v]:=(\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7). 0\u672A\u6E80\
    \u306E\u5834\u5408\uFF0Cv\u306F\u6839\u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\
    \u5BFE\u5024\u306F\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8868\
    \u3059\uFF0E\n    std::vector<T> m_p;      // m_p[v]:=(\u30CE\u30FC\u30C9v\u306E\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB).\n\npublic:\n    PotentializedUnionFind()\
    \ : PotentializedUnionFind(0) {}\n    explicit PotentializedUnionFind(size_t vn)\
    \ : m_vn(vn), m_gn(vn), m_par(vn, -1), m_p(vn, 0) {}\n\n    // \u30CE\u30FC\u30C9\
    \u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return m_vn;\
    \ };\n    // \u9023\u7D50\u6210\u5206\u306E\u6570\u3092\u8FD4\u3059\uFF0E\n  \
    \  int gn() const { return m_gn; };\n    // \u30CE\u30FC\u30C9v\u306E\u89AA\u756A\
    \u53F7\u3092\u8FD4\u3059\uFF0E\n    int root(int v) {\n        assert(0 <= v and\
    \ v < vn());\n        if(m_par[v] < 0) return v;\n        auto res = root(m_par[v]);\
    \  // recrusion.\n        m_p[v] += m_p[m_par[v]];\n        return m_par[v] =\
    \ res;\n    }\n    // \u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\
    \u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int v) {\n\
    \        assert(0 <= v and v < vn());\n        return -m_par[root(v)];\n    }\n\
    \    // \u30CE\u30FC\u30C9v\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\
    \u3059\uFF0E\n    T potential(int v) {\n        assert(0 <= v and v < vn());\n\
    \        root(v);\n        return m_p[v];\n    }\n    // \u30CE\u30FC\u30C9u\u3068\
    v\u304C\u9023\u7D50\u3057\u3066\u3044\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\
    \n    bool same(int u, int v) {\n        assert(0 <= u and u < vn());\n      \
    \  assert(0 <= v and v < vn());\n        return root(u) == root(v);\n    }\n \
    \   // \u30CE\u30FC\u30C9u\u306B\u5BFE\u3059\u308Bv\u306E\u76F8\u5BFE\u30DD\u30C6\
    \u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\uFF0E\n    T difference(int u, int\
    \ v) {\n        assert(0 <= u and u < vn());\n        assert(0 <= v and v < vn());\n\
    \        return potential(v) - potential(u);\n    }\n    // difference(u,v)=d\u3068\
    \u306A\u308B\u3088\u3046\u306B\u30CE\u30FC\u30C9u\u3068v\u305D\u308C\u305E\u308C\
    \u306E\u89AA\u30CE\u30FC\u30C9\u3092\u9023\u7D50\u3059\u308B\uFF0E\n    bool unite(int\
    \ u, int v, T d) {\n        assert(0 <= u and u < vn());\n        assert(0 <=\
    \ v and v < vn());\n        d = d + potential(u) - potential(v);\n        u =\
    \ root(u), v = root(v);\n        if(u == v) return false;  // Do nothing.\n  \
    \      if(size(u) < size(v)) {   // Merge technique.\n            std::swap(u,\
    \ v);\n            d = -d;\n        }\n        m_par[u] += m_par[v];\n       \
    \ m_par[v] = u;\n        m_p[v] = d;\n        m_gn--;\n        return true;\n\
    \    }\n    void reset() {\n        m_gn = vn();\n        std::fill(m_par.begin(),\
    \ m_par.end(), -1);\n        std::fill(m_p.begin(), m_p.end(), 0);\n    }\n};\n\
    \n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/potentialized_union_find.hpp
  requiredBy: []
  timestamp: '2023-04-06 23:09:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/potentialized_union_find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/potentialized_union_find.hpp
- /library/src/DataStructure/potentialized_union_find.hpp.html
title: src/DataStructure/potentialized_union_find.hpp
---
