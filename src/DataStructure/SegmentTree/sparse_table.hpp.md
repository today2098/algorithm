---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-staticrmq-sparse_table.test.cpp
    title: test/yosupo-staticrmq-sparse_table.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/SegmentTree/sparse_table.md
    document_title: Sparse Table
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree/sparse_table.hpp\"\n\n\n\n\
    /**\n * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3057\uFF0C\u7D50\
    \u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\u6027 A\u2022\
    A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08or, min, max, gcd, lcm\u306A\
    \u3069\uFF09\u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\
    \u308B\uFF0E\ntemplate <typename S>  // S: \u51AA\u7B49\u534A\u7FA4\u306E\u578B\
    .\nclass SparseTable {\n    using Func = std::function<S(const S &, const S &)>;\n\
    \n    Func m_op;                             // S m_op(S,S):=(\u4E8C\u9805\u6F14\
    \u7B97\u95A2\u6570).\n    int m_sz;                              // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<int> m_lb;                 // m_lb[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<S> > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\
    \u7DCF\u7A4D).\n\npublic:\n    using value_type = S;\n\n    // constructor. O(N*logN).\n\
    \    SparseTable() {}\n    explicit SparseTable(const Func &op, const std::vector<S>\
    \ &v) : m_op(op), m_sz(v.size()), m_lb(v.size() + 1, 0) {\n        for(int i =\
    \ 2; i <= size(); ++i) m_lb[i] = m_lb[i >> 1] + 1;\n        m_table.resize(m_lb[size()]\
    \ + 1);\n        m_table[0].assign(v.begin(), v.end());\n        for(int k = 1;\
    \ k <= m_lb[size()]; ++k) {\n            int n = size() - (1 << k) + 1;\n    \
    \        m_table[k].resize(n);\n            for(int i = 0; i < n; ++i) m_table[k][i]\
    \ = m_op(m_table[k - 1][i], m_table[k - 1][i + (1 << (k - 1))]);\n        }\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(1).\n    S fold(int l, int r) const {\n        assert(0 <= l and\
    \ l < r and r <= size());\n        int k = m_lb[r - l];\n        return m_op(m_table[k][l],\
    \ m_table[k][r - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SPARSE_TABLE_HPP\n#define ALGORITHM_SPARSE_TABLE_HPP 1\n\
    \n/**\n * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u9759\u7684\u306A\u6570\u5217\u306B\u5BFE\u3057\uFF0C\u7D50\
    \u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\u51AA\u7B49\u6027 A\u2022\
    A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08or, min, max, gcd, lcm\u306A\
    \u3069\uFF09\u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\
    \u308B\uFF0E\ntemplate <typename S>  // S: \u51AA\u7B49\u534A\u7FA4\u306E\u578B\
    .\nclass SparseTable {\n    using Func = std::function<S(const S &, const S &)>;\n\
    \n    Func m_op;                             // S m_op(S,S):=(\u4E8C\u9805\u6F14\
    \u7B97\u95A2\u6570).\n    int m_sz;                              // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<int> m_lb;                 // m_lb[x]:=floor(log2(x)).\n\
    \    std::vector<std::vector<S> > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\
    \u7DCF\u7A4D).\n\npublic:\n    using value_type = S;\n\n    // constructor. O(N*logN).\n\
    \    SparseTable() {}\n    explicit SparseTable(const Func &op, const std::vector<S>\
    \ &v) : m_op(op), m_sz(v.size()), m_lb(v.size() + 1, 0) {\n        for(int i =\
    \ 2; i <= size(); ++i) m_lb[i] = m_lb[i >> 1] + 1;\n        m_table.resize(m_lb[size()]\
    \ + 1);\n        m_table[0].assign(v.begin(), v.end());\n        for(int k = 1;\
    \ k <= m_lb[size()]; ++k) {\n            int n = size() - (1 << k) + 1;\n    \
    \        m_table[k].resize(n);\n            for(int i = 0; i < n; ++i) m_table[k][i]\
    \ = m_op(m_table[k - 1][i], m_table[k - 1][i + (1 << (k - 1))]);\n        }\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(1).\n    S fold(int l, int r) const {\n        assert(0 <= l and\
    \ l < r and r <= size());\n        int k = m_lb[r - l];\n        return m_op(m_table[k][l],\
    \ m_table[k][r - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree/sparse_table.hpp
  requiredBy: []
  timestamp: '2024-05-21 01:59:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-staticrmq-sparse_table.test.cpp
documentation_of: src/DataStructure/SegmentTree/sparse_table.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree/sparse_table.hpp
- /library/src/DataStructure/SegmentTree/sparse_table.hpp.html
title: Sparse Table
---
## 概要

静的な数列に対し，次の性質が成り立つ演算（$\operatorname{or}, \min, \max, \gcd, \operatorname{lcm}$など）による区間クエリを求める．

- 結合則：$(A \bullet B) \bullet C = A \bullet (B \bullet C)$
- 冪等性：$A \bullet A = A$

アルゴリズムの計算量は，数列の長さを $N$ とすると，テーブルの構築に $\mathcal{O}(N \log N),$ クエリ処理に $\mathcal{O}(1)$ かかる．


## 参考文献

- tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
- "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
