---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/UnionFind/partially_persistent_union_find.md
    document_title: "Partially Persistent Union-Find\uFF08\u90E8\u5206\u6C38\u7D9A\
      Unionf-Find\uFF09"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/UnionFind/partially_persistent_union_find.hpp\"\
    \n\n\n\n/**\n * @brief Partially Persistent Union-Find\uFF08\u90E8\u5206\u6C38\
    \u7D9AUnionf-Find\uFF09\n * @docs docs/DataStructure/UnionFind/partially_persistent_union_find.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u90E8\u5206\u6C38\
    \u7D9AUnion-Find\uFF0E\nclass PartiallyPersistentUnionFind {\n    using pii =\
    \ std::pair<int, int>;\n\n    int m_now;  // m_now:=(\u73FE\u5728\u6642\u523B\
    ).\n    int m_vn;   // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;   // m_gn:=(\u30B0\
    \u30EB\u30FC\u30D7\u6570).\n    // m_par[x][](t,id):=(\u8981\u7D20x\u306B\u304A\
    \u3051\u308B\u66F4\u65B0\u6642\u9593t\u3068\u89AA\u756A\u53F7id).\n    // \u5024\
    id\u304C0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u6839\u3067\u3042\u308A\uFF0C\
    \u5024id\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<std::vector<pii>\
    \ > m_par;\n\n    static constexpr int infinity() { return std::numeric_limits<int>::max();\
    \ }\n\npublic:\n    PartiallyPersistentUnionFind() : PartiallyPersistentUnionFind(0)\
    \ {}\n    explicit PartiallyPersistentUnionFind(size_t vn)\n        : m_now(0),\
    \ m_vn(vn), m_gn(vn), m_par(vn, std::vector<pii>({{0, -1}})) {}\n\n    // \u73FE\
    \u5728\u306E\u6642\u523B\u3092\u8FD4\u3059\uFF0E\n    int now() const { return\
    \ m_now; }\n    // \u8981\u7D20\u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n  \
    \  int vn() const { return m_vn; };\n    // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n    // \u73FE\u5728\u306B\
    \u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u756A\u53F7\u3092\u8FD4\u3059\
    \uFF0EO(logN).\n    int root(int x) const {\n        assert(0 <= x and x < vn());\n\
    \        while(m_par[x].crbegin()->second >= 0) x = m_par[x].crbegin()->second;\n\
    \        return x;\n    }\n    // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\uFF08\u6839\u4ED8\u304D\u6728\
    \uFF09\u306E\u6839\u756A\u53F7\u3092\u8FD4\u3059\uFF0EO(logN).\n    int root(int\
    \ x, int t) const {\n        assert(0 <= x and x < vn());\n        assert(0 <=\
    \ t and t <= now());\n        auto itr = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(),\
    \ pii(t, -infinity()));\n        if(itr == m_par[x].cend() or itr->first > t)\
    \ itr--;\n        if(itr->second < 0) return x;\n        return root(itr->second,\
    \ t);\n    }\n    // \u73FE\u5728\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\
    \u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\
    \uFF0EO(logN).\n    int size(int x) const {\n        assert(0 <= x and x < vn());\n\
    \        return -m_par[root(x)].crbegin()->second;\n    }\n    // \u6642\u523B\
    t\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0EO(logN).\n    int size(int\
    \ x, int t) const {\n        assert(0 <= x and x < vn());\n        assert(0 <=\
    \ t and t <= now());\n        auto itr = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(),\
    \ pii(t, -infinity()));\n        if(itr == m_par[x].cend() or itr->first > t)\
    \ itr--;\n        if(itr->second < 0) return -itr->second;\n        return size(itr->second,\
    \ t);\n    }\n    // \u73FE\u5728\u306B\u304A\u3044\u3066\u8981\u7D20x, y\u304C\
    \u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0EO(logN).\n    bool is_same(int x, int y) const {\n        assert(0\
    \ <= x and x < vn());\n        assert(0 <= y and y < vn());\n        return root(x)\
    \ == root(y);\n    }\n    // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20\
    x, y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(logN).\n    bool is_same(int x, int y, int t) const\
    \ {\n        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        assert(0 <= t and t <= now());\n        return root(x, t) == root(y,\
    \ t);\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \u3068\u8981\u7D20y\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\u3092\
    \u4F75\u5408\u3057\uFF0C\u6642\u9593\u3092+1\u9032\u3081\u308B\uFF0EO(logN).\n\
    \    bool unite(int x, int y) {\n        assert(0 <= x and x < vn());\n      \
    \  assert(0 <= y and y < vn());\n        m_now++;\n        x = root(x), y = root(y);\n\
    \        if(x == y) return false;  // Already united.\n        int sz_x = -m_par[x].crbegin()->second;\n\
    \        int sz_y = -m_par[y].crbegin()->second;\n        if(sz_x < sz_y) std::swap(x,\
    \ y);  // Merge technique (unite by size).\n        m_par[x].emplace_back(now(),\
    \ -sz_x - sz_y);\n        m_par[y].emplace_back(now(), x);\n        m_gn--;\n\
    \        return true;\n    }\n    void reset() {\n        m_now = 1;\n       \
    \ m_gn = vn();\n        for(std::vector<pii> &history : m_par) history.resize(1);\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP\n#define ALGORITHM_PARTIALLY_PERSISTENT_UNION_FIND_HPP\
    \ 1\n\n/**\n * @brief Partially Persistent Union-Find\uFF08\u90E8\u5206\u6C38\u7D9A\
    Unionf-Find\uFF09\n * @docs docs/DataStructure/UnionFind/partially_persistent_union_find.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <limits>\n#include\
    \ <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u90E8\u5206\u6C38\
    \u7D9AUnion-Find\uFF0E\nclass PartiallyPersistentUnionFind {\n    using pii =\
    \ std::pair<int, int>;\n\n    int m_now;  // m_now:=(\u73FE\u5728\u6642\u523B\
    ).\n    int m_vn;   // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;   // m_gn:=(\u30B0\
    \u30EB\u30FC\u30D7\u6570).\n    // m_par[x][](t,id):=(\u8981\u7D20x\u306B\u304A\
    \u3051\u308B\u66F4\u65B0\u6642\u9593t\u3068\u89AA\u756A\u53F7id).\n    // \u5024\
    id\u304C0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u6839\u3067\u3042\u308A\uFF0C\
    \u5024id\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<std::vector<pii>\
    \ > m_par;\n\n    static constexpr int infinity() { return std::numeric_limits<int>::max();\
    \ }\n\npublic:\n    PartiallyPersistentUnionFind() : PartiallyPersistentUnionFind(0)\
    \ {}\n    explicit PartiallyPersistentUnionFind(size_t vn)\n        : m_now(0),\
    \ m_vn(vn), m_gn(vn), m_par(vn, std::vector<pii>({{0, -1}})) {}\n\n    // \u73FE\
    \u5728\u306E\u6642\u523B\u3092\u8FD4\u3059\uFF0E\n    int now() const { return\
    \ m_now; }\n    // \u8981\u7D20\u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n  \
    \  int vn() const { return m_vn; };\n    // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n    // \u73FE\u5728\u306B\
    \u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u756A\u53F7\u3092\u8FD4\u3059\
    \uFF0EO(logN).\n    int root(int x) const {\n        assert(0 <= x and x < vn());\n\
    \        while(m_par[x].crbegin()->second >= 0) x = m_par[x].crbegin()->second;\n\
    \        return x;\n    }\n    // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\uFF08\u6839\u4ED8\u304D\u6728\
    \uFF09\u306E\u6839\u756A\u53F7\u3092\u8FD4\u3059\uFF0EO(logN).\n    int root(int\
    \ x, int t) const {\n        assert(0 <= x and x < vn());\n        assert(0 <=\
    \ t and t <= now());\n        auto itr = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(),\
    \ pii(t, -infinity()));\n        if(itr == m_par[x].cend() or itr->first > t)\
    \ itr--;\n        if(itr->second < 0) return x;\n        return root(itr->second,\
    \ t);\n    }\n    // \u73FE\u5728\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\
    \u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\
    \uFF0EO(logN).\n    int size(int x) const {\n        assert(0 <= x and x < vn());\n\
    \        return -m_par[root(x)].crbegin()->second;\n    }\n    // \u6642\u523B\
    t\u306B\u304A\u3044\u3066\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\
    \u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8FD4\u3059\uFF0EO(logN).\n    int size(int\
    \ x, int t) const {\n        assert(0 <= x and x < vn());\n        assert(0 <=\
    \ t and t <= now());\n        auto itr = std::lower_bound(m_par[x].cbegin(), m_par[x].cend(),\
    \ pii(t, -infinity()));\n        if(itr == m_par[x].cend() or itr->first > t)\
    \ itr--;\n        if(itr->second < 0) return -itr->second;\n        return size(itr->second,\
    \ t);\n    }\n    // \u73FE\u5728\u306B\u304A\u3044\u3066\u8981\u7D20x, y\u304C\
    \u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0EO(logN).\n    bool is_same(int x, int y) const {\n        assert(0\
    \ <= x and x < vn());\n        assert(0 <= y and y < vn());\n        return root(x)\
    \ == root(y);\n    }\n    // \u6642\u523Bt\u306B\u304A\u3044\u3066\u8981\u7D20\
    x, y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\
    \u5B9A\u3059\u308B\uFF0EO(logN).\n    bool is_same(int x, int y, int t) const\
    \ {\n        assert(0 <= x and x < vn());\n        assert(0 <= y and y < vn());\n\
    \        assert(0 <= t and t <= now());\n        return root(x, t) == root(y,\
    \ t);\n    }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\
    \u3068\u8981\u7D20y\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\u3092\
    \u4F75\u5408\u3057\uFF0C\u6642\u9593\u3092+1\u9032\u3081\u308B\uFF0EO(logN).\n\
    \    bool unite(int x, int y) {\n        assert(0 <= x and x < vn());\n      \
    \  assert(0 <= y and y < vn());\n        m_now++;\n        x = root(x), y = root(y);\n\
    \        if(x == y) return false;  // Already united.\n        int sz_x = -m_par[x].crbegin()->second;\n\
    \        int sz_y = -m_par[y].crbegin()->second;\n        if(sz_x < sz_y) std::swap(x,\
    \ y);  // Merge technique (unite by size).\n        m_par[x].emplace_back(now(),\
    \ -sz_x - sz_y);\n        m_par[y].emplace_back(now(), x);\n        m_gn--;\n\
    \        return true;\n    }\n    void reset() {\n        m_now = 1;\n       \
    \ m_gn = vn();\n        for(std::vector<pii> &history : m_par) history.resize(1);\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind/partially_persistent_union_find.hpp
  requiredBy: []
  timestamp: '2023-09-16 12:03:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/UnionFind/partially_persistent_union_find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind/partially_persistent_union_find.hpp
- /library/src/DataStructure/UnionFind/partially_persistent_union_find.hpp.html
title: "Partially Persistent Union-Find\uFF08\u90E8\u5206\u6C38\u7D9AUnionf-Find\uFF09"
---
## 概要

部分永続 Union-Find は，通常の [Union-Find](https://today2098.github.io/algorithm/src/DataStructure/UnionFind/union_find.hpp) の機能に加え，過去の状態におけるクエリを求めることができるデータ構造．

実装では「union by size」の工夫のみ行い，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考文献

1. "やぶについて書きます". <https://camypaper.bitbucket.io/2016/12/18/adc2016/>.


## 問題

- "H - Union Sets". CODE THANKS FESTIVAL 2017(Parallel). AtCoder. <https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h>.
