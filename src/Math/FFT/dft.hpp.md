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
  bundledCode: "#line 1 \"src/Math/FFT/dft.hpp\"\n\n\n\n#include <algorithm>\n#include\
    \ <cmath>\n#include <complex>\n#include <vector>\n\nnamespace algorithm {\n\n\
    namespace dft {\n\nusing D = double;\n\nconst D PI = std::acos(-1.0);\n\n// \u96E2\
    \u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\uFF0EO(N^2).\nstd::vector<std::complex<D>\
    \ > transform(const std::vector<std::complex<D> > &a, bool inv = false) {\n  \
    \  const int n = a.size();\n    std::vector<std::complex<D> > res(n, 0.0);\n \
    \   for(int i = 0; i < n; ++i) {\n        D ang = 2 * PI / n * i;\n        if(inv)\
    \ ang = -ang;\n        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar(1.0,\
    \ ang * j);\n    }\n    if(inv) {\n        for(int i = 0; i < n; ++i) res[i] /=\
    \ n;\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// c[k]=sum_{i=0}^{k}\
    \ a[i]*b[k-i] \u3092\u6C42\u3081\u308B\uFF0EO(N^2).\nstd::vector<long long> convolution(const\
    \ std::vector<long long> &a, const std::vector<long long> &b) {\n    if(a.size()\
    \ == 0 or b.size() == 0) return std::vector<long long>();\n    const int n = a.size()\
    \ + b.size() - 1;\n    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0), c(n);\n\
    \    std::copy(a.begin(), a.end(), na.begin());\n    std::copy(b.begin(), b.end(),\
    \ nb.begin());\n    na = transform(na), nb = transform(nb);\n    for(int i = 0;\
    \ i < n; ++i) c[i] = na[i] * nb[i];\n    c = transform(c, true);\n    std::vector<long\
    \ long> res(n);\n    for(int i = 0; i < n; ++i) res[i] = c[i].real() + 0.5;\n\
    \    return res;\n}\n\n}  // namespace dft\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DISCRETE_FOURIER_TRANSFORMATION_HPP\n#define ALGORITHM_DISCRETE_FOURIER_TRANSFORMATION_HPP\
    \ 1\n\n#include <algorithm>\n#include <cmath>\n#include <complex>\n#include <vector>\n\
    \nnamespace algorithm {\n\nnamespace dft {\n\nusing D = double;\n\nconst D PI\
    \ = std::acos(-1.0);\n\n// \u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\uFF0E\
    O(N^2).\nstd::vector<std::complex<D> > transform(const std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    const int n = a.size();\n    std::vector<std::complex<D>\
    \ > res(n, 0.0);\n    for(int i = 0; i < n; ++i) {\n        D ang = 2 * PI / n\
    \ * i;\n        if(inv) ang = -ang;\n        for(int j = 0; j < n; ++j) res[i]\
    \ += a[j] * std::polar(1.0, ang * j);\n    }\n    if(inv) {\n        for(int i\
    \ = 0; i < n; ++i) res[i] /= n;\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// c[k]=sum_{i=0}^{k} a[i]*b[k-i] \u3092\u6C42\u3081\u308B\uFF0E\
    O(N^2).\nstd::vector<long long> convolution(const std::vector<long long> &a, const\
    \ std::vector<long long> &b) {\n    if(a.size() == 0 or b.size() == 0) return\
    \ std::vector<long long>();\n    const int n = a.size() + b.size() - 1;\n    std::vector<std::complex<D>\
    \ > na(n, 0.0), nb(n, 0.0), c(n);\n    std::copy(a.begin(), a.end(), na.begin());\n\
    \    std::copy(b.begin(), b.end(), nb.begin());\n    na = transform(na), nb =\
    \ transform(nb);\n    for(int i = 0; i < n; ++i) c[i] = na[i] * nb[i];\n    c\
    \ = transform(c, true);\n    std::vector<long long> res(n);\n    for(int i = 0;\
    \ i < n; ++i) res[i] = c[i].real() + 0.5;\n    return res;\n}\n\n}  // namespace\
    \ dft\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/FFT/dft.hpp
  requiredBy: []
  timestamp: '2023-09-27 20:19:54+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/FFT/dft.hpp
layout: document
redirect_from:
- /library/src/Math/FFT/dft.hpp
- /library/src/Math/FFT/dft.hpp.html
title: src/Math/FFT/dft.hpp
---
