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
  bundledCode: "#line 1 \"src/DataStructure/sub_persistent_union_find.hpp\"\n\n\n\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u90E8\u5206\
    \u6C38\u7D9AUnion-Find Tree\uFF0E\nclass SubPersistentUnionFind {\n    using pii\
    \ = std::pair<int, int>;\n\n    int m_now;  // m_now:=(\u6642\u523B).\n    int\
    \ m_vn;   // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int m_gn;   // m_gn:=(\u9023\
    \u7D50\u6210\u5206\u6570).\n    // m_par[v][](t,id):=(\u6642\u523Bt\u306B\u304A\
    \u3051\u308B\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7id). \u5024id\u304C0\u672A\
    \u6E80\u306E\u5834\u5408\uFF0Cv\u306F\u89AA\u3068\u306A\u308A\uFF0C\u5024id\u306E\
    \u7D76\u5BFE\u5024\u306F\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\
    \u8868\u3059\uFF0E\n    std::vector<std::vector<pii> > m_par;\n\n    static constexpr\
    \ int infinity() { return 1e9; }\n\npublic:\n    SubPersistentUnionFind() : SubPersistentUnionFind(0)\
    \ {}\n    explicit SubPersistentUnionFind(size_t vn) : m_now(1), m_vn(vn), m_gn(vn),\
    \ m_par(vn, std::vector<pii>(1, pii(0, -1))) {\n        assert((int)vn < infinity());\n\
    \    }\n\n    // \u73FE\u5728\u306E\u6642\u523B\u3092\u8FD4\u3059\uFF0E\n    int\
    \ now() const { return m_now; }\n    // \u30CE\u30FC\u30C9\u306E\u7DCF\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n    // \u9023\u7D50\u6210\
    \u5206\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n \
    \   // \u73FE\u5728\u306E\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\u3092\u8FD4\
    \u3059\uFF0E\n    int root(int v) const {\n        assert(0 <= v and v < vn());\n\
    \        auto itr = m_par[v].rbegin();\n        if(itr->second < 0) return v;\n\
    \        return root(itr->second);\n    }\n    // \u6642\u523Bt\u306B\u304A\u3051\
    \u308B\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\u3092\u8FD4\u3059\uFF0E\n  \
    \  int root(int v, int t) const {\n        assert(0 <= v and v < vn());\n    \
    \    assert(0 <= t and t < now());\n        auto itr = std::lower_bound(m_par[v].begin(),\
    \ m_par[v].end(), pii(t, -infinity()));\n        if(itr == m_par[v].end() or itr->first\
    \ > t) itr--;\n        if(itr->second < 0) return v;\n        return (itr->first\
    \ == t ? itr->second : root(itr->second, t));\n    }\n    // \u73FE\u5728\u306E\
    \u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\
    \u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int v) const {\n        assert(0\
    \ <= v and v < vn());\n        return -m_par[root(v)].rbegin()->second;\n    }\n\
    \    // \u6642\u523Bt\u306B\u304A\u3051\u308B\u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\
    \n    int size(int v, int t) const {\n        assert(0 <= v and v < vn());\n \
    \       assert(0 <= t and t < now());\n        int par = root(v, t);\n       \
    \ auto itr = std::lower_bound(m_par[par].begin(), m_par[par].end(), pii(t, -infinity()));\n\
    \        if(itr == m_par[par].end() or itr->first > t) itr--;\n        return\
    \ -itr->second;\n    }\n    // \u73FE\u5728\u30CE\u30FC\u30C9u\u3068v\u304C\u9023\
    \u7D50\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool same(int u, int v) const\
    \ {\n        assert(0 <= u and u < vn());\n        assert(0 <= v and v < vn());\n\
    \        return root(u) == root(v);\n    }\n    // \u6642\u523Bt\u306B\u304A\u3044\
    \u3066\u30CE\u30FC\u30C9u\u3068v\u304C\u9023\u7D50\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0E\n    bool same(int u, int v, int t) const {\n        assert(0 <= u and\
    \ u < vn());\n        assert(0 <= v and v < vn());\n        assert(0 <= t and\
    \ t < now());\n        return root(u, t) == root(v, t);\n    }\n    // \u30CE\u30FC\
    \u30C9u\u3068v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u3092\u7E4B\u3052\
    \u308B\uFF0E\n    bool unite(int u, int v) {\n        assert(0 <= u and u < vn());\n\
    \        assert(0 <= v and v < vn());\n        u = root(u), v = root(v);\n   \
    \     if(u == v) {\n            m_now++;\n            return false;  // Already\
    \ united.\n        }\n        int sz_u = -m_par[u].rbegin()->second;\n       \
    \ int sz_v = -m_par[v].rbegin()->second;\n        if(sz_u < sz_v) std::swap(u,\
    \ v), std::swap(sz_u, sz_v);  // Merge technique.\n        m_par[u].emplace_back(now(),\
    \ -sz_u - sz_v);\n        m_par[v].emplace_back(now(), u);\n        m_gn--;\n\
    \        m_now++;\n        return true;\n    }\n    void reset() {\n        m_now\
    \ = 1;\n        m_gn = vn();\n        for(auto &history : m_par) history.resize(1);\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SUB_PERSISTENT_UNION_FIND_HPP\n#define ALGORITHM_SUB_PERSISTENT_UNION_FIND_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u90E8\
    \u5206\u6C38\u7D9AUnion-Find Tree\uFF0E\nclass SubPersistentUnionFind {\n    using\
    \ pii = std::pair<int, int>;\n\n    int m_now;  // m_now:=(\u6642\u523B).\n  \
    \  int m_vn;   // m_vn:=(\u30CE\u30FC\u30C9\u6570).\n    int m_gn;   // m_gn:=(\u9023\
    \u7D50\u6210\u5206\u6570).\n    // m_par[v][](t,id):=(\u6642\u523Bt\u306B\u304A\
    \u3051\u308B\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7id). \u5024id\u304C0\u672A\
    \u6E80\u306E\u5834\u5408\uFF0Cv\u306F\u89AA\u3068\u306A\u308A\uFF0C\u5024id\u306E\
    \u7D76\u5BFE\u5024\u306F\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\
    \u8868\u3059\uFF0E\n    std::vector<std::vector<pii> > m_par;\n\n    static constexpr\
    \ int infinity() { return 1e9; }\n\npublic:\n    SubPersistentUnionFind() : SubPersistentUnionFind(0)\
    \ {}\n    explicit SubPersistentUnionFind(size_t vn) : m_now(1), m_vn(vn), m_gn(vn),\
    \ m_par(vn, std::vector<pii>(1, pii(0, -1))) {\n        assert((int)vn < infinity());\n\
    \    }\n\n    // \u73FE\u5728\u306E\u6642\u523B\u3092\u8FD4\u3059\uFF0E\n    int\
    \ now() const { return m_now; }\n    // \u30CE\u30FC\u30C9\u306E\u7DCF\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int vn() const { return m_vn; };\n    // \u9023\u7D50\u6210\
    \u5206\u6570\u3092\u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n \
    \   // \u73FE\u5728\u306E\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\u3092\u8FD4\
    \u3059\uFF0E\n    int root(int v) const {\n        assert(0 <= v and v < vn());\n\
    \        auto itr = m_par[v].rbegin();\n        if(itr->second < 0) return v;\n\
    \        return root(itr->second);\n    }\n    // \u6642\u523Bt\u306B\u304A\u3051\
    \u308B\u30CE\u30FC\u30C9v\u306E\u89AA\u756A\u53F7\u3092\u8FD4\u3059\uFF0E\n  \
    \  int root(int v, int t) const {\n        assert(0 <= v and v < vn());\n    \
    \    assert(0 <= t and t < now());\n        auto itr = std::lower_bound(m_par[v].begin(),\
    \ m_par[v].end(), pii(t, -infinity()));\n        if(itr == m_par[v].end() or itr->first\
    \ > t) itr--;\n        if(itr->second < 0) return v;\n        return (itr->first\
    \ == t ? itr->second : root(itr->second, t));\n    }\n    // \u73FE\u5728\u306E\
    \u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\
    \u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int v) const {\n        assert(0\
    \ <= v and v < vn());\n        return -m_par[root(v)].rbegin()->second;\n    }\n\
    \    // \u6642\u523Bt\u306B\u304A\u3051\u308B\u30CE\u30FC\u30C9v\u304C\u5C5E\u3059\
    \u308B\u9023\u7D50\u6210\u5206\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0E\
    \n    int size(int v, int t) const {\n        assert(0 <= v and v < vn());\n \
    \       assert(0 <= t and t < now());\n        int par = root(v, t);\n       \
    \ auto itr = std::lower_bound(m_par[par].begin(), m_par[par].end(), pii(t, -infinity()));\n\
    \        if(itr == m_par[par].end() or itr->first > t) itr--;\n        return\
    \ -itr->second;\n    }\n    // \u73FE\u5728\u30CE\u30FC\u30C9u\u3068v\u304C\u9023\
    \u7D50\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool same(int u, int v) const\
    \ {\n        assert(0 <= u and u < vn());\n        assert(0 <= v and v < vn());\n\
    \        return root(u) == root(v);\n    }\n    // \u6642\u523Bt\u306B\u304A\u3044\
    \u3066\u30CE\u30FC\u30C9u\u3068v\u304C\u9023\u7D50\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0E\n    bool same(int u, int v, int t) const {\n        assert(0 <= u and\
    \ u < vn());\n        assert(0 <= v and v < vn());\n        assert(0 <= t and\
    \ t < now());\n        return root(u, t) == root(v, t);\n    }\n    // \u30CE\u30FC\
    \u30C9u\u3068v\u304C\u5C5E\u3059\u308B\u9023\u7D50\u6210\u5206\u3092\u7E4B\u3052\
    \u308B\uFF0E\n    bool unite(int u, int v) {\n        assert(0 <= u and u < vn());\n\
    \        assert(0 <= v and v < vn());\n        u = root(u), v = root(v);\n   \
    \     if(u == v) {\n            m_now++;\n            return false;  // Already\
    \ united.\n        }\n        int sz_u = -m_par[u].rbegin()->second;\n       \
    \ int sz_v = -m_par[v].rbegin()->second;\n        if(sz_u < sz_v) std::swap(u,\
    \ v), std::swap(sz_u, sz_v);  // Merge technique.\n        m_par[u].emplace_back(now(),\
    \ -sz_u - sz_v);\n        m_par[v].emplace_back(now(), u);\n        m_gn--;\n\
    \        m_now++;\n        return true;\n    }\n    void reset() {\n        m_now\
    \ = 1;\n        m_gn = vn();\n        for(auto &history : m_par) history.resize(1);\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/sub_persistent_union_find.hpp
  requiredBy: []
  timestamp: '2023-04-06 23:09:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/sub_persistent_union_find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/sub_persistent_union_find.hpp
- /library/src/DataStructure/sub_persistent_union_find.hpp.html
title: src/DataStructure/sub_persistent_union_find.hpp
---
