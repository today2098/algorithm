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
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree/sparse_table.hpp\"\n/**\n\
    \ * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#ifndef ALGORITHM_SPARSE_TABLE_HPP\n#define ALGORITHM_SPARSE_TABLE_HPP\
    \ 1\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u7D50\u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\
    \u51AA\u7B49\u6027 A\u2022A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08\
    or, min, max, gcd, lcm\u306A\u3069\uFF09\u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\
    \u30EA\u3092\u6C42\u3081\u308B\uFF0E\ntemplate <typename S>  // S:\u51AA\u7B49\
    \u534A\u7FA4\u306E\u578B.\nclass SparseTable {\n    using Func = std::function<S(const\
    \ S &, const S &)>;\n\n    Func m_op;                             // S m_op(S,S):=(\u4E8C\
    \u9805\u6F14\u7B97\u95A2\u6570).\n    int m_sz;                              //\
    \ m_sz:=(\u8981\u7D20\u6570).\n    std::vector<int> m_l;                  // m_l[x]:=(2^k<=x\
    \ \u3068\u306A\u308B\u6700\u5927\u306E\u6574\u6570k).\n    std::vector<std::vector<S>\
    \ > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\u7DCF\u7A4D).\n\n\
    public:\n    // constructor. O(N*logN).\n    SparseTable() {}\n    explicit SparseTable(const\
    \ Func &op, const std::vector<S> &v) : m_op(op), m_sz(v.size()), m_l(v.size()\
    \ + 1, 0) {\n        for(int i = 2; i <= size(); ++i) m_l[i] = m_l[i >> 1] + 1;\n\
    \        m_table.resize(m_l[size()] + 1);\n        m_table[0].assign(v.begin(),\
    \ v.end());\n        for(int k = 1; k <= m_l[size()]; ++k) {\n            m_table[k].resize(size()\
    \ - (1 << k) + 1);\n            for(int i = 0; i <= size() - (1 << k); ++i) m_table[k][i]\
    \ = m_op(m_table[k - 1][i], m_table[k - 1][i + (1 << (k - 1))]);\n        }\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(1).\n    S fold(int l, int r) const {\n        assert(0 <= l and\
    \ l < r and r <= size());\n        int k = m_l[r - l];\n        return m_op(m_table[k][l],\
    \ m_table[k][r - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief Sparse Table\n * @docs docs/DataStructure/SegmentTree/sparse_table.md\n\
    \ */\n\n#ifndef ALGORITHM_SPARSE_TABLE_HPP\n#define ALGORITHM_SPARSE_TABLE_HPP\
    \ 1\n\n#include <cassert>\n#include <functional>\n#include <vector>\n\nnamespace\
    \ algorithm {\n\n// \u7D50\u5408\u5247 (A\u2022B)\u2022C=A\u2022(B\u2022C) \u3068\
    \u51AA\u7B49\u6027 A\u2022A=A \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08\
    or, min, max, gcd, lcm\u306A\u3069\uFF09\u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\
    \u30EA\u3092\u6C42\u3081\u308B\uFF0E\ntemplate <typename S>  // S:\u51AA\u7B49\
    \u534A\u7FA4\u306E\u578B.\nclass SparseTable {\n    using Func = std::function<S(const\
    \ S &, const S &)>;\n\n    Func m_op;                             // S m_op(S,S):=(\u4E8C\
    \u9805\u6F14\u7B97\u95A2\u6570).\n    int m_sz;                              //\
    \ m_sz:=(\u8981\u7D20\u6570).\n    std::vector<int> m_l;                  // m_l[x]:=(2^k<=x\
    \ \u3068\u306A\u308B\u6700\u5927\u306E\u6574\u6570k).\n    std::vector<std::vector<S>\
    \ > m_table;  // m_table[k][i]:=(\u533A\u9593[i,i+2^k)\u306E\u7DCF\u7A4D).\n\n\
    public:\n    // constructor. O(N*logN).\n    SparseTable() {}\n    explicit SparseTable(const\
    \ Func &op, const std::vector<S> &v) : m_op(op), m_sz(v.size()), m_l(v.size()\
    \ + 1, 0) {\n        for(int i = 2; i <= size(); ++i) m_l[i] = m_l[i >> 1] + 1;\n\
    \        m_table.resize(m_l[size()] + 1);\n        m_table[0].assign(v.begin(),\
    \ v.end());\n        for(int k = 1; k <= m_l[size()]; ++k) {\n            m_table[k].resize(size()\
    \ - (1 << k) + 1);\n            for(int i = 0; i <= size() - (1 << k); ++i) m_table[k][i]\
    \ = m_op(m_table[k - 1][i], m_table[k - 1][i + (1 << (k - 1))]);\n        }\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u7DCF\u7A4D\u3092\u6C42\u3081\
    \u308B\uFF0EO(1).\n    S fold(int l, int r) const {\n        assert(0 <= l and\
    \ l < r and r <= size());\n        int k = m_l[r - l];\n        return m_op(m_table[k][l],\
    \ m_table[k][r - (1 << k)]);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree/sparse_table.hpp
  requiredBy: []
  timestamp: '2023-09-03 21:48:20+09:00'
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
## 参考文献

- tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
- "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
