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
  bundledCode: "#line 1 \"src/DataStructure/binary_indexed_tree.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// Binary Indexed Tree.\n\
    template <typename T>\nclass BIT {\n    int m_sz;               // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<T> m_tree;  // 1-based index.\n\n    void build()\
    \ {\n        for(int i = 1; i < size(); ++i) {\n            int j = i + (i & -i);\n\
    \            if(j <= size()) m_tree[j] += m_tree[i];\n        }\n    }\n\npublic:\n\
    \    // constructor. O(N).\n    BIT() : BIT(0){};\n    explicit BIT(size_t n)\
    \ : m_sz(n), m_tree(n + 1, 0) {}\n    explicit BIT(const std::vector<T> &v) :\
    \ m_sz(v.size()), m_tree(v.size() + 1) {\n        std::copy(v.begin(), v.end(),\
    \ m_tree.begin() + 1);\n        build();\n    }\n\n    // \u8981\u7D20\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    // k\u756A\u76EE\
    \u306E\u8981\u7D20\u306Ba\u3092\u8DB3\u3059\uFF0EO(logN).\n    void add(int k,\
    \ T a) {\n        assert(1 <= k and k <= size());\n        for(; k <= size();\
    \ k += (k & -k)) m_tree[k] += a;\n    }\n    // \u533A\u9593[1,r]\u306E\u7DCF\u548C\
    \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n        assert(0\
    \ <= r and r <= size());\n        T res = 0;\n        for(; r > 0; r -= (r & -r))\
    \ res += m_tree[r];\n        return res;\n    }\n    // \u533A\u9593[l,r]\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int l, int r) const\
    \ {\n        assert(1 <= l and l <= r and r <= size());\n        return sum(r)\
    \ - sum(l - 1);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\
    \uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin() + 1, m_tree.end(),\
    \ a);\n        if(a == 0) return;\n        build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n\n"
  code: "#ifndef ALGORITHM_BINARY_INDEXED_TREE_HPP\n#define ALGORITHM_BINARY_INDEXED_TREE_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// Binary\
    \ Indexed Tree.\ntemplate <typename T>\nclass BIT {\n    int m_sz;           \
    \    // m_sz:=(\u8981\u7D20\u6570).\n    std::vector<T> m_tree;  // 1-based index.\n\
    \n    void build() {\n        for(int i = 1; i < size(); ++i) {\n            int\
    \ j = i + (i & -i);\n            if(j <= size()) m_tree[j] += m_tree[i];\n   \
    \     }\n    }\n\npublic:\n    // constructor. O(N).\n    BIT() : BIT(0){};\n\
    \    explicit BIT(size_t n) : m_sz(n), m_tree(n + 1, 0) {}\n    explicit BIT(const\
    \ std::vector<T> &v) : m_sz(v.size()), m_tree(v.size() + 1) {\n        std::copy(v.begin(),\
    \ v.end(), m_tree.begin() + 1);\n        build();\n    }\n\n    // \u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const { return m_sz; }\n    //\
    \ k\u756A\u76EE\u306E\u8981\u7D20\u306Ba\u3092\u8DB3\u3059\uFF0EO(logN).\n   \
    \ void add(int k, T a) {\n        assert(1 <= k and k <= size());\n        for(;\
    \ k <= size(); k += (k & -k)) m_tree[k] += a;\n    }\n    // \u533A\u9593[1,r]\u306E\
    \u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int r) const {\n\
    \        assert(0 <= r and r <= size());\n        T res = 0;\n        for(; r\
    \ > 0; r -= (r & -r)) res += m_tree[r];\n        return res;\n    }\n    // \u533A\
    \u9593[l,r]\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    T sum(int\
    \ l, int r) const {\n        assert(1 <= l and l <= r and r <= size());\n    \
    \    return sum(r) - sum(l - 1);\n    }\n    // \u5168\u8981\u7D20\u3092a\u3067\
    \u57CB\u3081\u308B\uFF0EO(N).\n    void fill(T a = 0) {\n        std::fill(m_tree.begin()\
    \ + 1, m_tree.end(), a);\n        if(a == 0) return;\n        build();\n    }\n\
    };\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/binary_indexed_tree.hpp
  requiredBy: []
  timestamp: '2023-04-02 20:40:44+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/binary_indexed_tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/binary_indexed_tree.hpp
- /library/src/DataStructure/binary_indexed_tree.hpp.html
title: src/DataStructure/binary_indexed_tree.hpp
---