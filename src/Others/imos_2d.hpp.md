---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-DSL_4_A.test.cpp
    title: test/aoj-DSL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/imos_2d.md
    document_title: "\u4E8C\u6B21\u5143\u3044\u3082\u3059\u6CD5"
    links: []
  bundledCode: "#line 1 \"src/Others/imos_2d.hpp\"\n/**\n * @brief \u4E8C\u6B21\u5143\
    \u3044\u3082\u3059\u6CD5\n * @docs docs/Others/imos_2d.md\n */\n\n#ifndef ALGORITHM_IMOS_2D_HPP\n\
    #define ALGORITHM_IMOS_2D_HPP 1\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u6B21\u5143\u3044\u3082\
    \u3059\u6CD5\uFF0E\ntemplate <typename T>\nclass Imos2D {\n    int m_h, m_w;\n\
    \    std::vector<std::vector<T> > m_dat;  // 0-based index.\n\npublic:\n    Imos2D()\
    \ : Imos2D(0, 0) {}\n    explicit Imos2D(size_t h, size_t w) : m_h(h), m_w(w),\
    \ m_dat(h + 1, std::vector<T>(w + 1, 0)) {}\n\n    int height() const { return\
    \ m_h; }\n    int width() const { return m_w; }\n    void add(int ly, int lx,\
    \ int ry, int rx, T val) {\n        assert(0 <= ly and ly <= ry and ry <= height());\n\
    \        assert(0 <= lx and lx <= rx and rx <= width());\n        m_dat[ly][lx]\
    \ += val;\n        m_dat[ly][rx] -= val;\n        m_dat[ry][lx] -= val;\n    \
    \    m_dat[ry][rx] += val;\n    }\n    void build() {\n        for(int i = 0;\
    \ i < height(); ++i) {\n            for(int j = 0; j < width(); ++j) m_dat[i][j\
    \ + 1] += m_dat[i][j];\n        }\n        for(int j = 0; j < width(); ++j) {\n\
    \            for(int i = 0; i < height(); ++i) m_dat[i + 1][j] += m_dat[i][j];\n\
    \        }\n    }\n    T get(int y, int x) const {\n        assert(0 <= y and\
    \ y < height());\n        assert(0 <= x and x < width());\n        return m_dat[y][x];\n\
    \    }\n    void reset() {\n        for(std::vector<T> &v : m_dat) std::fill(v.begin(),\
    \ v.end(), 0);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief \u4E8C\u6B21\u5143\u3044\u3082\u3059\u6CD5\n * @docs docs/Others/imos_2d.md\n\
    \ */\n\n#ifndef ALGORITHM_IMOS_2D_HPP\n#define ALGORITHM_IMOS_2D_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\
    \n// \u4E8C\u6B21\u5143\u3044\u3082\u3059\u6CD5\uFF0E\ntemplate <typename T>\n\
    class Imos2D {\n    int m_h, m_w;\n    std::vector<std::vector<T> > m_dat;  //\
    \ 0-based index.\n\npublic:\n    Imos2D() : Imos2D(0, 0) {}\n    explicit Imos2D(size_t\
    \ h, size_t w) : m_h(h), m_w(w), m_dat(h + 1, std::vector<T>(w + 1, 0)) {}\n\n\
    \    int height() const { return m_h; }\n    int width() const { return m_w; }\n\
    \    void add(int ly, int lx, int ry, int rx, T val) {\n        assert(0 <= ly\
    \ and ly <= ry and ry <= height());\n        assert(0 <= lx and lx <= rx and rx\
    \ <= width());\n        m_dat[ly][lx] += val;\n        m_dat[ly][rx] -= val;\n\
    \        m_dat[ry][lx] -= val;\n        m_dat[ry][rx] += val;\n    }\n    void\
    \ build() {\n        for(int i = 0; i < height(); ++i) {\n            for(int\
    \ j = 0; j < width(); ++j) m_dat[i][j + 1] += m_dat[i][j];\n        }\n      \
    \  for(int j = 0; j < width(); ++j) {\n            for(int i = 0; i < height();\
    \ ++i) m_dat[i + 1][j] += m_dat[i][j];\n        }\n    }\n    T get(int y, int\
    \ x) const {\n        assert(0 <= y and y < height());\n        assert(0 <= x\
    \ and x < width());\n        return m_dat[y][x];\n    }\n    void reset() {\n\
    \        for(std::vector<T> &v : m_dat) std::fill(v.begin(), v.end(), 0);\n  \
    \  }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/imos_2d.hpp
  requiredBy: []
  timestamp: '2023-09-10 11:29:03+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-DSL_4_A.test.cpp
documentation_of: src/Others/imos_2d.hpp
layout: document
redirect_from:
- /library/src/Others/imos_2d.hpp
- /library/src/Others/imos_2d.hpp.html
title: "\u4E8C\u6B21\u5143\u3044\u3082\u3059\u6CD5"
---
## 参考文献

1. いもす (今城健太郎). "いもす法". Imos Lab. <https://imoz.jp/algorithms/imos_method.html>.
1. Ryo Suzuki. "Siv3D \| 「二次元いもす法」を可視化する". Zenn. <https://zenn.dev/reputeless/articles/article-2d-imos>.
1. "2次元imos法". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/range/imos2d/main.html>.