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
  bundledCode: "#line 1 \"src/String/manacher.hpp\"\n\n\n\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u6700\u9577\u56DE\u6587 (Longest Palindromic\
    \ Substring)\uFF0E\ntemplate <class Sequence>\nclass Manacher {\n    int m_sz;\
    \  // m_sz:=(\u914D\u5217\u30B5\u30A4\u30BA).\n    // m_radius[2*k]:=(k\u6587\u5B57\
    \u76EE\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\u6700\u9577\
    \u56DE\u6587\u306E\u534A\u5F84),\n    // m_radius[2*k-1]:=(k-1\u6587\u5B57\u76EE\
    \u3068k\u6587\u5B57\u76EE\u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\
    \u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84).\n    std::vector<int>\
    \ m_radius;\n\npublic:\n    // constructor. \u5F15\u6570\u306FSTL\u306E\u30B7\u30FC\
    \u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\uFF0EO(|S|).\n    Manacher() : Manacher(Sequence())\
    \ {}\n    explicit Manacher(const Sequence &s) : m_sz(s.size()), m_radius(2 *\
    \ s.size()) {\n        Sequence t(2 * size(), 0);\n        for(int i = 0; i <\
    \ size(); ++i) t[2 * i] = s[i];\n        int i = 0, j = 0;\n        while(i <\
    \ 2 * size() - 1) {\n            while(0 <= i - j and i + j < 2 * size() - 1 and\
    \ t[i - j] == t[i + j]) j++;\n            m_radius[i] = j;\n            int k\
    \ = 1;\n            while(i - k >= 0 and m_radius[i - k] + k < j) {\n        \
    \        m_radius[i + k] = m_radius[i - k];\n                k++;\n          \
    \  }\n            i += k, j -= k;\n        }\n    }\n\n    int size() const {\
    \ return m_sz; }\n    // k\u6587\u5B57\u76EE\u3092\u4E2D\u5FC3\u3068\u3059\u308B\
    \u5947\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u8FD4\
    \u3059\uFF0E\n    int get_odd(int k) const {\n        assert(0 <= k and k < size());\n\
    \        return (m_radius[2 * k] + 1) / 2;\n    }\n    // k-1\u6587\u5B57\u76EE\
    \u3068k\u6587\u5B57\u76EE\u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5076\
    \u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84\u3092\u8FD4\u3059\
    \uFF0E\n    int get_even(int k) const {\n        assert(1 <= k and k < size());\n\
    \        return m_radius[2 * k - 1] / 2;\n    }\n    // \u90E8\u5206\u5217s[l:r]\u304C\
    \u56DE\u6587\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_palindrome(int l,\
    \ int r) const {\n        assert(0 <= l and l < r and r <= size());\n        int\
    \ mid = (l + r) / 2;\n        return ((r - l) & 1 ? get_odd(mid) >= (r - l + 1)\
    \ / 2 : get_even(mid) >= (r - l) / 2);\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_MANACHER_HPP\n#define ALGORITHM_MANACHER_HPP 1\n\n#include\
    \ <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6700\u9577\u56DE\
    \u6587 (Longest Palindromic Substring)\uFF0E\ntemplate <class Sequence>\nclass\
    \ Manacher {\n    int m_sz;  // m_sz:=(\u914D\u5217\u30B5\u30A4\u30BA).\n    //\
    \ m_radius[2*k]:=(k\u6587\u5B57\u76EE\u3092\u4E2D\u5FC3\u3068\u3059\u308B\u5947\
    \u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84),\n    // m_radius[2*k-1]:=(k-1\u6587\
    \u5B57\u76EE\u3068k\u6587\u5B57\u76EE\u306E\u9593\u3092\u4E2D\u5FC3\u3068\u3059\
    \u308B\u5076\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\u534A\u5F84).\n \
    \   std::vector<int> m_radius;\n\npublic:\n    // constructor. \u5F15\u6570\u306F\
    STL\u306E\u30B7\u30FC\u30B1\u30F3\u30B9\u30B3\u30F3\u30C6\u30CA\uFF0EO(|S|).\n\
    \    Manacher() : Manacher(Sequence()) {}\n    explicit Manacher(const Sequence\
    \ &s) : m_sz(s.size()), m_radius(2 * s.size()) {\n        Sequence t(2 * size(),\
    \ 0);\n        for(int i = 0; i < size(); ++i) t[2 * i] = s[i];\n        int i\
    \ = 0, j = 0;\n        while(i < 2 * size() - 1) {\n            while(0 <= i -\
    \ j and i + j < 2 * size() - 1 and t[i - j] == t[i + j]) j++;\n            m_radius[i]\
    \ = j;\n            int k = 1;\n            while(i - k >= 0 and m_radius[i -\
    \ k] + k < j) {\n                m_radius[i + k] = m_radius[i - k];\n        \
    \        k++;\n            }\n            i += k, j -= k;\n        }\n    }\n\n\
    \    int size() const { return m_sz; }\n    // k\u6587\u5B57\u76EE\u3092\u4E2D\
    \u5FC3\u3068\u3059\u308B\u5947\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\u306E\
    \u534A\u5F84\u3092\u8FD4\u3059\uFF0E\n    int get_odd(int k) const {\n       \
    \ assert(0 <= k and k < size());\n        return (m_radius[2 * k] + 1) / 2;\n\
    \    }\n    // k-1\u6587\u5B57\u76EE\u3068k\u6587\u5B57\u76EE\u306E\u9593\u3092\
    \u4E2D\u5FC3\u3068\u3059\u308B\u5076\u6570\u9577\u306E\u6700\u9577\u56DE\u6587\
    \u306E\u534A\u5F84\u3092\u8FD4\u3059\uFF0E\n    int get_even(int k) const {\n\
    \        assert(1 <= k and k < size());\n        return m_radius[2 * k - 1] /\
    \ 2;\n    }\n    // \u90E8\u5206\u5217s[l:r]\u304C\u56DE\u6587\u304B\u5224\u5B9A\
    \u3059\u308B\uFF0E\n    bool is_palindrome(int l, int r) const {\n        assert(0\
    \ <= l and l < r and r <= size());\n        int mid = (l + r) / 2;\n        return\
    \ ((r - l) & 1 ? get_odd(mid) >= (r - l + 1) / 2 : get_even(mid) >= (r - l) /\
    \ 2);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/String/manacher.hpp
  requiredBy: []
  timestamp: '2023-04-06 12:37:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/String/manacher.hpp
layout: document
redirect_from:
- /library/src/String/manacher.hpp
- /library/src/String/manacher.hpp.html
title: src/String/manacher.hpp
---
