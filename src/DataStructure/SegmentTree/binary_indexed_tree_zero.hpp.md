---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
    title: test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Binary Indexed Tree (0-based index)
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp\"\
    \n/**\n * @brief Binary Indexed Tree (0-based index)\n */\n\n#ifndef ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP\n\
    #define ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP 1\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// Binary Indexed Tree\
    \ (0-based index).\ntemplate <typename T>\nclass BIT0 {\n    int m_sz;       \
    \        // m_sz:=(\u8981\u7D20\u6570).\n    std::vector<T> m_tree;  // 0-based\
    \ index.\n\n    void build() {\n        for(int i = 0; i < size() - 1; ++i) {\n\
    \            int j = i | i + 1;\n            if(j < size()) m_tree[j] += m_tree[i];\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT0() : BIT0(0){};\n\
    \    explicit BIT0(size_t n, T a = 0) : m_sz(n), m_tree(n, a) {\n        if(a\
    \ != 0) build();\n    }\n    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()),\
    \ m_tree(v) {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0E\n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\
    \u8981\u7D20\u306Ba\u3092\u8DB3\u3059\uFF0EO(logN).\n    void add(int k, T a)\
    \ {\n        assert(0 <= k and k < size());\n        for(; k < size(); k |= k\
    \ + 1) m_tree[k] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0 <=\
    \ r and r <= size());\n        T res = 0;\n        for(r = r - 1; r >= 0; r =\
    \ (r & r + 1) - 1) res += m_tree[r];\n        return res;\n    }\n    // \u533A\
    \u9593[l,r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int\
    \ l, int r) const {\n        assert(0 <= l and l <= r and r <= size());\n    \
    \    return sum(r) - sum(l);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\
    \u3081\u308B\uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin(),\
    \ m_tree.end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "/**\n * @brief Binary Indexed Tree (0-based index)\n */\n\n#ifndef ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP\n\
    #define ALGORITHM_BINARY_INDEXED_TREE_ZERO_HPP 1\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// Binary Indexed Tree\
    \ (0-based index).\ntemplate <typename T>\nclass BIT0 {\n    int m_sz;       \
    \        // m_sz:=(\u8981\u7D20\u6570).\n    std::vector<T> m_tree;  // 0-based\
    \ index.\n\n    void build() {\n        for(int i = 0; i < size() - 1; ++i) {\n\
    \            int j = i | i + 1;\n            if(j < size()) m_tree[j] += m_tree[i];\n\
    \        }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT0() : BIT0(0){};\n\
    \    explicit BIT0(size_t n, T a = 0) : m_sz(n), m_tree(n, a) {\n        if(a\
    \ != 0) build();\n    }\n    explicit BIT0(const std::vector<T> &v) : m_sz(v.size()),\
    \ m_tree(v) {\n        build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0E\n    int size() const { return m_sz; }\n    // k\u756A\u76EE\u306E\
    \u8981\u7D20\u306Ba\u3092\u8DB3\u3059\uFF0EO(logN).\n    void add(int k, T a)\
    \ {\n        assert(0 <= k and k < size());\n        for(; k < size(); k |= k\
    \ + 1) m_tree[k] += a;\n    }\n    // \u533A\u9593[0,r)\u306E\u7DCF\u548C\u3092\
    \u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0 <=\
    \ r and r <= size());\n        T res = 0;\n        for(r = r - 1; r >= 0; r =\
    \ (r & r + 1) - 1) res += m_tree[r];\n        return res;\n    }\n    // \u533A\
    \u9593[l,r)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int\
    \ l, int r) const {\n        assert(0 <= l and l <= r and r <= size());\n    \
    \    return sum(r) - sum(l);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\
    \u3081\u308B\uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin(),\
    \ m_tree.end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
  requiredBy: []
  timestamp: '2023-09-03 16:14:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-point_add_range_sum-binary_indexed_tree_zero.test.cpp
documentation_of: src/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp
- /library/src/DataStructure/SegmentTree/binary_indexed_tree_zero.hpp.html
title: Binary Indexed Tree (0-based index)
---
