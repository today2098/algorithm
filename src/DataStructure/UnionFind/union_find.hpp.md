---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_1_A.test.cpp
    title: test/aoj-DSL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-unionfind.test.cpp
    title: test/yosupo-unionfind.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/UnionFind/union_find.md
    document_title: "Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/UnionFind/union_find.hpp\"\n\n\n\n/**\n\
    \ * @brief Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\uFF09\
    \n * @docs docs/DataStructure/UnionFind/union_find.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nclass UnionFind {\n    int m_vn;  // m_vn:=(\u8981\u7D20\u6570).\n    int\
    \ m_gn;  // m_gn:=(\u30B0\u30EB\u30FC\u30D7\u6570).\n    // m_par[x]:=(\u8981\u7D20\
    x\u306E\u89AA\u756A\u53F7). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u6839\
    \u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\
    \u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n   \
    \ std::vector<int> m_par;\n\npublic:\n    UnionFind() : UnionFind(0) {}\n    explicit\
    \ UnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}\n\n    // \u8981\
    \u7D20\u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return\
    \ m_vn; };\n    // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\u8FD4\u3059\uFF0E\n  \
    \  int gn() const { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\
    \u30B0\u30EB\u30FC\u30D7\uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u756A\
    \u53F7\u3092\u8FD4\u3059\uFF0EO(\u03B1(N)).\n    int root(int x) {\n        assert(0\
    \ <= x and x < vn());\n        if(m_par[x] < 0) return x;\n        return m_par[x]\
    \ = root(m_par[x]);  // \u7D4C\u8DEF\u5727\u7E2E\uFF0E\n    }\n    // \u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\
    \u8FD4\u3059\uFF0E\n    int size(int x) {\n        assert(0 <= x and x < vn());\n\
    \        return -m_par[root(x)];\n    }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\
    \u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0E\n    bool is_same(int x, int y) {\n        assert(0 <= x and x < vn());\n\
    \        assert(0 <= y and y < vn());\n        return root(x) == root(y);\n  \
    \  }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\
    \u8981\u7D20y\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\u3092\u4F75\
    \u5408\u3059\u308B\uFF0E\n    bool unite(int x, int y) {\n        assert(0 <=\
    \ x and x < vn());\n        assert(0 <= y and y < vn());\n        x = root(x),\
    \ y = root(y);\n        if(x == y) return false;                // Do nothing.\n\
    \        if(size(x) < size(y)) std::swap(x, y);  // Merge technique (union by\
    \ size).\n        m_par[x] += m_par[y];\n        m_par[y] = x;\n        m_gn--;\n\
    \        return true;\n    }\n    void reset() {\n        m_gn = vn();\n     \
    \   std::fill(m_par.begin(), m_par.end(), -1);\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_UNION_FIND_HPP\n#define ALGORITHM_UNION_FIND_HPP 1\n\n\
    /**\n * @brief Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\
    \uFF09\n * @docs docs/DataStructure/UnionFind/union_find.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\nclass UnionFind {\n    int m_vn;  // m_vn:=(\u8981\u7D20\u6570).\n    int\
    \ m_gn;  // m_gn:=(\u30B0\u30EB\u30FC\u30D7\u6570).\n    // m_par[x]:=(\u8981\u7D20\
    x\u306E\u89AA\u756A\u53F7). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u6839\
    \u3067\u3042\u308A\uFF0C\u5024\u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\
    \u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n   \
    \ std::vector<int> m_par;\n\npublic:\n    UnionFind() : UnionFind(0) {}\n    explicit\
    \ UnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1) {}\n\n    // \u8981\
    \u7D20\u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n    int vn() const { return\
    \ m_vn; };\n    // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\u8FD4\u3059\uFF0E\n  \
    \  int gn() const { return m_gn; };\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\
    \u30B0\u30EB\u30FC\u30D7\uFF08\u6839\u4ED8\u304D\u6728\uFF09\u306E\u6839\u756A\
    \u53F7\u3092\u8FD4\u3059\uFF0EO(\u03B1(N)).\n    int root(int x) {\n        assert(0\
    \ <= x and x < vn());\n        if(m_par[x] < 0) return x;\n        return m_par[x]\
    \ = root(m_par[x]);  // \u7D4C\u8DEF\u5727\u7E2E\uFF0E\n    }\n    // \u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\u30BA\u3092\
    \u8FD4\u3059\uFF0E\n    int size(int x) {\n        assert(0 <= x and x < vn());\n\
    \        return -m_par[root(x)];\n    }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\
    \u30B0\u30EB\u30FC\u30D7\u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\
    \uFF0E\n    bool is_same(int x, int y) {\n        assert(0 <= x and x < vn());\n\
    \        assert(0 <= y and y < vn());\n        return root(x) == root(y);\n  \
    \  }\n    // \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\
    \u8981\u7D20y\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\u3092\u4F75\
    \u5408\u3059\u308B\uFF0E\n    bool unite(int x, int y) {\n        assert(0 <=\
    \ x and x < vn());\n        assert(0 <= y and y < vn());\n        x = root(x),\
    \ y = root(y);\n        if(x == y) return false;                // Do nothing.\n\
    \        if(size(x) < size(y)) std::swap(x, y);  // Merge technique (union by\
    \ size).\n        m_par[x] += m_par[y];\n        m_par[y] = x;\n        m_gn--;\n\
    \        return true;\n    }\n    void reset() {\n        m_gn = vn();\n     \
    \   std::fill(m_par.begin(), m_par.end(), -1);\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/UnionFind/union_find.hpp
  requiredBy: []
  timestamp: '2023-09-16 12:03:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-unionfind.test.cpp
  - test/aoj-DSL_1_A.test.cpp
documentation_of: src/DataStructure/UnionFind/union_find.hpp
layout: document
redirect_from:
- /library/src/DataStructure/UnionFind/union_find.hpp
- /library/src/DataStructure/UnionFind/union_find.hpp.html
title: "Union-Find\uFF08\u7D20\u96C6\u5408\u30C7\u30FC\u30BF\u69CB\u9020\uFF09"
---
## 概要

要素のグループ分けを効率的に管理するデータ構造．
1964年，Bernard A. Galler と Michael J. Fischer が考案した．

次のクエリ処理を高速に行う．

- $\operatorname{unite}(x, y)$ : 要素 $x$ が属するグループと要素 $y$ が属するグループとを併合する．
- $\operatorname{is\_same}(x, y)$ : 要素x, yが同じグループに属するか判定する．

実装では「union by size」と「経路圧縮」の工夫を行っている．

各クエリ処理に要する計算量は，アッカーマン関数の逆関数を $\operatorname{\alpha}(x)$ とすると，$\mathcal{O}(\operatorname{\alpha}(N))$ となる．
アッカーマン関数の逆関数は $x \leq 10^{80}$ に対し $\operatorname{\alpha}(x) \leq 4$ が成り立つため，実用上 $\mathcal{O}(1)$ とみなすことができる．


## 参考文献

1. Bernard A. Galler and Michael J. Fisher. 1964. An improved equivalence algorithm. Commun. ACM 7, 5 (May 1964), 301–303. <https://doi.org/10.1145/364099.364331>.
1. 大槻 兼資. "第11章 データ構造 (4)：Union-Find". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉 拓哉監修. 講談社, 2020, p.181-190. 
1. "素集合データ構造". Wikipedia. <https://ja.wikipedia.org/wiki/素集合データ構造>.
1. "巨大数：アッカーマン関数とは". 高校数学の美しい物語. <https://manabitimes.jp/math/1010>.