---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "2\u6B21\u5143BIT (0-based index)"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp\"\
    \n/**\n * @brief 2\u6B21\u5143BIT (0-based index)\n */\n\n#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_ZERO_HPP\n\
    #define ALGORITHM_BINARY_INDEXED_TREE_2D_ZERO_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// 2\u6B21\u5143\
    BIT (0-based index)\uFF0E\ntemplate <typename T>\nclass BIT2D0 {\n    int m_h,\
    \ m_w;\n    std::vector<std::vector<T> > m_dat;  // 0-based index.\n\n    void\
    \ build() {\n        for(int i = 0; i < height(); ++i) {\n            for(int\
    \ j = 0; j < width(); ++j) {\n                int ni = i | i + 1, nj = j | j +\
    \ 1;\n                bool flag1 = (ni < height()), flag2 = (nj < width());\n\
    \                if(flag1) m_dat[ni][j] += m_dat[i][j];\n                if(flag2)\
    \ m_dat[i][nj] += m_dat[i][j];\n                if(flag1 and flag2) m_dat[ni][nj]\
    \ -= m_dat[i][j];\n            }\n        }\n    }\n\npublic:\n    // constructor.\
    \ O(H*W).\n    BIT2D0() : BIT2D0(0, 0) {}\n    explicit BIT2D0(size_t h, size_t\
    \ w, T a = 0) : m_h(h), m_w(w), m_dat(h, std::vector<T>(w, a)) {\n        if(a\
    \ != 0) build();\n    }\n    explicit BIT2D0(const std::vector<std::vector<T>\
    \ > &dat) : m_h(dat.size()), m_w(dat[0].size()), m_dat(dat) {\n        build();\n\
    \    }\n\n    int height() const { return m_h; }\n    int width() const { return\
    \ m_w; }\n    // \u5EA7\u6A19(x,y)\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0E\
    O((logH)*logW).\n    void add(int y, int x, T a) {\n        assert(0 <= y and\
    \ y < height());\n        assert(0 <= x and x < width());\n        for(int i =\
    \ y; i < height(); i |= i + 1) {\n            for(int j = x; j < width(); j |=\
    \ j + 1) m_dat[i][j] += a;\n        }\n    }\n    // \u533A\u9593[0,y)\u304B\u3064\
    [0,x)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n    T sum(int\
    \ y, int x) const {\n        assert(0 <= y and y <= height());\n        assert(0\
    \ <= x and x <= width());\n        T res = 0;\n        for(int i = y - 1; i >=\
    \ 0; i = (i & i + 1) - 1) {\n            for(int j = x - 1; j >= 0; j = (j & j\
    \ + 1) - 1) res += m_dat[i][j];\n        }\n        return res;\n    }\n    //\
    \ \u533A\u9593[y,yy)\u304B\u3064[x,xx)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\
    \uFF0E\n    T sum(int y, int x, int yy, int xx) const {\n        assert(0 <= y\
    \ and y <= yy and yy <= height());\n        assert(0 <= x and x <= xx and xx <=\
    \ width());\n        return sum(yy, xx) - sum(yy, x) - sum(y, xx) + sum(y, x);\n\
    \    }\n    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\uFF0EO(H*W).\n\
    \    void fill(T a = 0) {\n        for(int i = 0; i < height(); ++i) std::fill(m_dat[i].begin(),\
    \ m_dat[i].end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "/**\n * @brief 2\u6B21\u5143BIT (0-based index)\n */\n\n#ifndef ALGORITHM_BINARY_INDEXED_TREE_2D_ZERO_HPP\n\
    #define ALGORITHM_BINARY_INDEXED_TREE_2D_ZERO_HPP 1\n\n#include <algorithm>\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// 2\u6B21\u5143\
    BIT (0-based index)\uFF0E\ntemplate <typename T>\nclass BIT2D0 {\n    int m_h,\
    \ m_w;\n    std::vector<std::vector<T> > m_dat;  // 0-based index.\n\n    void\
    \ build() {\n        for(int i = 0; i < height(); ++i) {\n            for(int\
    \ j = 0; j < width(); ++j) {\n                int ni = i | i + 1, nj = j | j +\
    \ 1;\n                bool flag1 = (ni < height()), flag2 = (nj < width());\n\
    \                if(flag1) m_dat[ni][j] += m_dat[i][j];\n                if(flag2)\
    \ m_dat[i][nj] += m_dat[i][j];\n                if(flag1 and flag2) m_dat[ni][nj]\
    \ -= m_dat[i][j];\n            }\n        }\n    }\n\npublic:\n    // constructor.\
    \ O(H*W).\n    BIT2D0() : BIT2D0(0, 0) {}\n    explicit BIT2D0(size_t h, size_t\
    \ w, T a = 0) : m_h(h), m_w(w), m_dat(h, std::vector<T>(w, a)) {\n        if(a\
    \ != 0) build();\n    }\n    explicit BIT2D0(const std::vector<std::vector<T>\
    \ > &dat) : m_h(dat.size()), m_w(dat[0].size()), m_dat(dat) {\n        build();\n\
    \    }\n\n    int height() const { return m_h; }\n    int width() const { return\
    \ m_w; }\n    // \u5EA7\u6A19(x,y)\u306Ba\u3092\u52A0\u7B97\u3059\u308B\uFF0E\
    O((logH)*logW).\n    void add(int y, int x, T a) {\n        assert(0 <= y and\
    \ y < height());\n        assert(0 <= x and x < width());\n        for(int i =\
    \ y; i < height(); i |= i + 1) {\n            for(int j = x; j < width(); j |=\
    \ j + 1) m_dat[i][j] += a;\n        }\n    }\n    // \u533A\u9593[0,y)\u304B\u3064\
    [0,x)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\uFF0EO((logH)*logW).\n    T sum(int\
    \ y, int x) const {\n        assert(0 <= y and y <= height());\n        assert(0\
    \ <= x and x <= width());\n        T res = 0;\n        for(int i = y - 1; i >=\
    \ 0; i = (i & i + 1) - 1) {\n            for(int j = x - 1; j >= 0; j = (j & j\
    \ + 1) - 1) res += m_dat[i][j];\n        }\n        return res;\n    }\n    //\
    \ \u533A\u9593[y,yy)\u304B\u3064[x,xx)\u306E\u7DCF\u548C\u3092\u6C42\u3081\u308B\
    \uFF0E\n    T sum(int y, int x, int yy, int xx) const {\n        assert(0 <= y\
    \ and y <= yy and yy <= height());\n        assert(0 <= x and x <= xx and xx <=\
    \ width());\n        return sum(yy, xx) - sum(yy, x) - sum(y, xx) + sum(y, x);\n\
    \    }\n    // \u5168\u8981\u7D20\u3092a\u3067\u57CB\u3081\u308B\uFF0EO(H*W).\n\
    \    void fill(T a = 0) {\n        for(int i = 0; i < height(); ++i) std::fill(m_dat[i].begin(),\
    \ m_dat[i].end(), a);\n        if(a != 0) build();\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp
  requiredBy: []
  timestamp: '2023-09-08 19:04:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp
layout: document
redirect_from:
- /library/src/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp
- /library/src/DataStructure/SegmentTree/binary_indexed_tree_2d_zero.hpp.html
title: "2\u6B21\u5143BIT (0-based index)"
---
