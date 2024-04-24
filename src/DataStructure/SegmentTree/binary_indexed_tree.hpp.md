---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
    title: test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SegmentTree/binary_indexed_tree.md
    document_title: Binary Indexed Tree
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree/binary_indexed_tree.hpp\"\n\
    \n\n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename T>\nclass BIT {\n\
    \    int m_sz;               // m_sz:=(\u914D\u5217\u306E\u8981\u7D20\u6570).\n\
    \    std::vector<T> m_tree;  // 1-based index.\n\n    void build() {\n       \
    \ for(int i = 1; i < size(); ++i) {\n            int j = i + (i & -i);\n     \
    \       if(j <= size()) m_tree[j] += m_tree[i];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT() : BIT(0){};\n    explicit BIT(size_t n,\
    \ T a = 0) : m_sz(n), m_tree(n + 1, a) {\n        if(a != 0) build();\n    }\n\
    \    explicit BIT(const std::vector<T> &v) : m_sz(v.size()), m_tree(v.size() +\
    \ 1) {\n        std::copy(v.begin(), v.end(), m_tree.begin() + 1);\n        build();\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\
    \u3059\u308B\uFF0EO(logN).\n    void add(int k, T a) {\n        assert(1 <= k\
    \ and k <= size());\n        for(; k <= size(); k += k & -k) m_tree[k] += a;\n\
    \    }\n    // \u533A\u9593[1,r]\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0 <= r and\
    \ r <= size());\n        T res = 0;\n        for(; r > 0; r -= r & -r) res +=\
    \ m_tree[r];\n        return res;\n    }\n    // \u533A\u9593[l,r]\u306E\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int\
    \ l, int r) const {\n        assert(1 <= l and l <= r and r <= size());\n    \
    \    return sum(r) - sum(l - 1);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\
    \u57CB\u3081\u308B\uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin()\
    \ + 1, m_tree.end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_HPP\
    \ 1\n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/DataStructure/SegmentTree/binary_indexed_tree.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// Binary Indexed Tree.\ntemplate <typename T>\nclass BIT {\n\
    \    int m_sz;               // m_sz:=(\u914D\u5217\u306E\u8981\u7D20\u6570).\n\
    \    std::vector<T> m_tree;  // 1-based index.\n\n    void build() {\n       \
    \ for(int i = 1; i < size(); ++i) {\n            int j = i + (i & -i);\n     \
    \       if(j <= size()) m_tree[j] += m_tree[i];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT() : BIT(0){};\n    explicit BIT(size_t n,\
    \ T a = 0) : m_sz(n), m_tree(n + 1, a) {\n        if(a != 0) build();\n    }\n\
    \    explicit BIT(const std::vector<T> &v) : m_sz(v.size()), m_tree(v.size() +\
    \ 1) {\n        std::copy(v.begin(), v.end(), m_tree.begin() + 1);\n        build();\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u52A0\u7B97\
    \u3059\u308B\uFF0EO(logN).\n    void add(int k, T a) {\n        assert(1 <= k\
    \ and k <= size());\n        for(; k <= size(); k += k & -k) m_tree[k] += a;\n\
    \    }\n    // \u533A\u9593[1,r]\u306E\u8981\u7D20\u306E\u7DCF\u548C\u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0 <= r and\
    \ r <= size());\n        T res = 0;\n        for(; r > 0; r -= r & -r) res +=\
    \ m_tree[r];\n        return res;\n    }\n    // \u533A\u9593[l,r]\u306E\u8981\
    \u7D20\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int\
    \ l, int r) const {\n        assert(1 <= l and l <= r and r <= size());\n    \
    \    return sum(r) - sum(l - 1);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\
    \u57CB\u3081\u308B\uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin()\
    \ + 1, m_tree.end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2024-04-13 12:34:09+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_2_B-binary_indexed_tree.test.cpp
documentation_of: src/DataStructure/SegmentTree/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree/binary_indexed_tree.hpp
- /library/src/DataStructure/SegmentTree/binary_indexed_tree.hpp.html
title: Binary Indexed Tree
---
## 概要

1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

長さ $N$ の配列 $\lbrace a_1, a_1, \ldots, a_N \rbrace$ に対して，以下のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- 一点更新 $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- 区間取得 $\operatorname{sum}(r)$：区間 $[1,r]$ の要素の総和を求める．

任意の区間 $[l,r]$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l-1)$ と計算すればよい．


## 参考文献

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 例題

1. "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
