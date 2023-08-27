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
  bundledCode: "#line 1 \"src/DataStructure/sparse_table.hpp\"\n\n\n\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u7D50\u5408\u5247 ((A\u2022\
    B)\u2022C=A\u2022(B\u2022C)) \u3068\u51AA\u7B49\u6027 (A\u2022A=A) \u304C\u6210\
    \u308A\u7ACB\u3064\u6F14\u7B97\uFF08min, max, or\u306A\u3069\uFF09\u306B\u3088\
    \u308B\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\u308B\uFF0E\ntemplate <typename\
    \ S>\nclass SparseTable {\n    using F = std::function<S(const S &, const S &)>;\n\
    \n    F m_op;                                // S m_op(S,S):=(\u4E8C\u9805\u6F14\
    \u7B97\u95A2\u6570).\n    int m_sz;                              // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<int> m_log;                // m_log[x]:=(2^k<=x\
    \ \u3068\u306A\u308B\u6700\u5927\u306E\u6574\u6570k).\n    std::vector<std::vector<S>\
    \ > m_table;  // m_table[k][i]:=(\u9577\u3055\u304C2^k\u3067\uFF0C\u5DE6\u7AEF\
    \u304Ci\u3067\u3042\u308B\u533A\u9593\u306E\u30AF\u30A8\u30EA).\n\npublic:\n \
    \   // constructor. O(N*logN).\n    SparseTable() {}\n    explicit SparseTable(const\
    \ F &op, const std::vector<S> &v) : m_op(op), m_sz(v.size()), m_log(v.size() +\
    \ 1, 0) {\n        for(int i = 2; i <= size(); ++i) m_log[i] = m_log[i >> 1] +\
    \ 1;\n        m_table.assign(m_log[size()] + 1, std::vector<S>(size()));\n   \
    \     std::copy(v.begin(), v.end(), m_table[0].begin());\n        for(int i =\
    \ 1; i <= m_log[size()]; ++i) {\n            for(int j = 0; j <= size() - (1 <<\
    \ i) + 1; ++j) m_table[i][j] = m_op(m_table[i - 1][j], m_table[i - 1][j + (1 <<\
    \ (i - 1))]);\n        }\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\
    \uFF0E\n    int size() const { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u30AF\
    \u30A8\u30EA\u3092\u8FD4\u3059\uFF0EO(1).\n    S query(int l, int r) const {\n\
    \        assert(0 <= l and l < r and r <= size());\n        int length = r - l;\n\
    \        return m_op(m_table[m_log[length]][l], m_table[m_log[length]][r - (1\
    \ << m_log[length])]);\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_SPARSE_TABLE_HPP\n#define ALGORITHM_SPARSE_TABLE_HPP 1\n\
    \n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u7D50\u5408\
    \u5247 ((A\u2022B)\u2022C=A\u2022(B\u2022C)) \u3068\u51AA\u7B49\u6027 (A\u2022\
    A=A) \u304C\u6210\u308A\u7ACB\u3064\u6F14\u7B97\uFF08min, max, or\u306A\u3069\uFF09\
    \u306B\u3088\u308B\u533A\u9593\u30AF\u30A8\u30EA\u3092\u6C42\u3081\u308B\uFF0E\
    \ntemplate <typename S>\nclass SparseTable {\n    using F = std::function<S(const\
    \ S &, const S &)>;\n\n    F m_op;                                // S m_op(S,S):=(\u4E8C\
    \u9805\u6F14\u7B97\u95A2\u6570).\n    int m_sz;                              //\
    \ m_sz:=(\u8981\u7D20\u6570).\n    std::vector<int> m_log;                // m_log[x]:=(2^k<=x\
    \ \u3068\u306A\u308B\u6700\u5927\u306E\u6574\u6570k).\n    std::vector<std::vector<S>\
    \ > m_table;  // m_table[k][i]:=(\u9577\u3055\u304C2^k\u3067\uFF0C\u5DE6\u7AEF\
    \u304Ci\u3067\u3042\u308B\u533A\u9593\u306E\u30AF\u30A8\u30EA).\n\npublic:\n \
    \   // constructor. O(N*logN).\n    SparseTable() {}\n    explicit SparseTable(const\
    \ F &op, const std::vector<S> &v) : m_op(op), m_sz(v.size()), m_log(v.size() +\
    \ 1, 0) {\n        for(int i = 2; i <= size(); ++i) m_log[i] = m_log[i >> 1] +\
    \ 1;\n        m_table.assign(m_log[size()] + 1, std::vector<S>(size()));\n   \
    \     std::copy(v.begin(), v.end(), m_table[0].begin());\n        for(int i =\
    \ 1; i <= m_log[size()]; ++i) {\n            for(int j = 0; j <= size() - (1 <<\
    \ i) + 1; ++j) m_table[i][j] = m_op(m_table[i - 1][j], m_table[i - 1][j + (1 <<\
    \ (i - 1))]);\n        }\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\
    \uFF0E\n    int size() const { return m_sz; }\n    // \u533A\u9593[l,r)\u306E\u30AF\
    \u30A8\u30EA\u3092\u8FD4\u3059\uFF0EO(1).\n    S query(int l, int r) const {\n\
    \        assert(0 <= l and l < r and r <= size());\n        int length = r - l;\n\
    \        return m_op(m_table[m_log[length]][l], m_table[m_log[length]][r - (1\
    \ << m_log[length])]);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/sparse_table.hpp
  requiredBy: []
  timestamp: '2023-08-16 14:54:01+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/sparse_table.hpp
layout: document
redirect_from:
- /library/src/DataStructure/sparse_table.hpp
- /library/src/DataStructure/sparse_table.hpp.html
title: src/DataStructure/sparse_table.hpp
---
