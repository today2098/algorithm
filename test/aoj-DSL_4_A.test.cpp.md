---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Others/compress.hpp
    title: "\u5EA7\u6A19\u5727\u7E2E"
  - icon: ':heavy_check_mark:'
    path: src/Others/imos_2d.hpp
    title: "\u4E8C\u6B21\u5143\u3044\u3082\u3059\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_4_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_4_A
  bundledCode: "#line 1 \"test/aoj-DSL_4_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_4_A\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Others/compress.hpp\"\n/**\n * @brief\
    \ \u5EA7\u6A19\u5727\u7E2E\n */\n\n#ifndef ALGORITHM_COMPRESS_HPP\n#define ALGORITHM_COMPRESS_HPP\
    \ 1\n\n#include <algorithm>\n#include <vector>\n\nnamespace algorithm {\n\n//\
    \ \u5EA7\u6A19\u5727\u7E2E\uFF0E\ntemplate <typename Type>\nstd::vector<Type>\
    \ compress(std::vector<Type> &v) {\n    const int n = v.size();\n    std::vector<Type>\
    \ key = v;\n    std::sort(key.begin(), key.end());\n    key.erase(std::unique(key.begin(),\
    \ key.end()), key.end());\n    for(int i = 0; i < n; ++i) v[i] = std::lower_bound(key.begin(),\
    \ key.end(), v[i]) - key.begin();\n    return key;\n}\n\n}  // namespace algorithm\n\
    \n#endif\n#line 1 \"src/Others/imos_2d.hpp\"\n/**\n * @brief \u4E8C\u6B21\u5143\
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
    \ v.end(), 0);\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n#line 7 \"test/aoj-DSL_4_A.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    std::vector<int> ys(2\
    \ * n), xs(2 * n);\n    for(int i = 0; i < n; ++i) std::cin >> xs[2 * i] >> ys[2\
    \ * i] >> xs[2 * i + 1] >> ys[2 * i + 1];\n\n    auto key_y = algorithm::compress(ys);\n\
    \    auto key_x = algorithm::compress(xs);\n\n    const int h = key_y.size(),\
    \ w = key_x.size();\n    algorithm::Imos2D<int> imos(h - 1, w - 1);\n    for(int\
    \ i = 0; i < n; ++i) imos.add(ys[2 * i], xs[2 * i], ys[2 * i + 1], xs[2 * i +\
    \ 1], 1);\n    imos.build();\n\n    long long ans = 0;\n    for(int i = 0; i <\
    \ h - 1; ++i) {\n        for(int j = 0; j < w - 1; ++j) {\n            if(imos.get(i,\
    \ j) > 0) {\n                auto tmp = (long long)(key_y[i + 1] - key_y[i]) *\
    \ (key_x[j + 1] - key_x[j]);\n                ans += tmp;\n            }\n   \
    \     }\n    }\n\n    std::cout << ans << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_4_A\"\
    \n\n#include <iostream>\n\n#include \"../src/Others/compress.hpp\"\n#include \"\
    ../src/Others/imos_2d.hpp\"\n\nint main() {\n    int n;\n    std::cin >> n;\n\n\
    \    std::vector<int> ys(2 * n), xs(2 * n);\n    for(int i = 0; i < n; ++i) std::cin\
    \ >> xs[2 * i] >> ys[2 * i] >> xs[2 * i + 1] >> ys[2 * i + 1];\n\n    auto key_y\
    \ = algorithm::compress(ys);\n    auto key_x = algorithm::compress(xs);\n\n  \
    \  const int h = key_y.size(), w = key_x.size();\n    algorithm::Imos2D<int> imos(h\
    \ - 1, w - 1);\n    for(int i = 0; i < n; ++i) imos.add(ys[2 * i], xs[2 * i],\
    \ ys[2 * i + 1], xs[2 * i + 1], 1);\n    imos.build();\n\n    long long ans =\
    \ 0;\n    for(int i = 0; i < h - 1; ++i) {\n        for(int j = 0; j < w - 1;\
    \ ++j) {\n            if(imos.get(i, j) > 0) {\n                auto tmp = (long\
    \ long)(key_y[i + 1] - key_y[i]) * (key_x[j + 1] - key_x[j]);\n              \
    \  ans += tmp;\n            }\n        }\n    }\n\n    std::cout << ans << std::endl;\n\
    }\n"
  dependsOn:
  - src/Others/compress.hpp
  - src/Others/imos_2d.hpp
  isVerificationFile: true
  path: test/aoj-DSL_4_A.test.cpp
  requiredBy: []
  timestamp: '2023-09-10 11:41:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_4_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_4_A.test.cpp
- /verify/test/aoj-DSL_4_A.test.cpp.html
title: test/aoj-DSL_4_A.test.cpp
---