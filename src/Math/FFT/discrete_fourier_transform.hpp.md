---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/FFT/discrete_fourier_transform.md
    document_title: "Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\
      \u30A8\u5909\u63DB\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/FFT/discrete_fourier_transform.hpp\"\n\n\n\n/**\n\
    \ * @brief Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\
    \u5909\u63DB\uFF09\n * @docs docs/Math/FFT/discrete_fourier_transform.md\n */\n\
    \n#include <algorithm>\n#include <cmath>\n#include <complex>\n#include <vector>\n\
    \nnamespace algorithm {\n\nnamespace dft {\n\nusing D = double;\n\nconst D PI\
    \ = std::acos(-1.0);\n\n// \u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\uFF0E\
    O(N^2).\nstd::vector<std::complex<D> > transform(const std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    const int n = a.size();\n    std::vector<std::complex<D>\
    \ > res(n, 0.0);\n    for(int i = 0; i < n; ++i) {\n        D ang = 2 * PI / n\
    \ * i;\n        if(inv) ang = -ang;\n        for(int j = 0; j < n; ++j) res[i]\
    \ += a[j] * std::polar(1.0, ang * j);\n    }\n    if(inv) {\n        for(int i\
    \ = 0; i < n; ++i) res[i] /= n;\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// k=0,1,...,N \u306B\u3064\u3044\u3066\uFF0Cc[k]=sum_{i=0}^{k}\
    \ a[i]*b[k-i] \u3092\u6C42\u3081\u308B\uFF0EO(N^2).\nstd::vector<D> convolve(const\
    \ std::vector<D> &a, const std::vector<D> &b) {\n    if(a.size() == 0 or b.size()\
    \ == 0) return std::vector<D>();\n    const int n = a.size() + b.size() - 1;\n\
    \    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    na\
    \ = transform(na), nb = transform(nb);\n    for(int i = 0; i < n; ++i) na[i] *=\
    \ nb[i];\n    na = transform(na, true);\n    std::vector<D> res(n);\n    for(int\
    \ i = 0; i < n; ++i) res[i] = na[i].real();\n    return res;\n}\n\n// \u7573\u307F\
    \u8FBC\u307F\uFF0E\n// k=0,1,...,N \u306B\u3064\u3044\u3066\uFF0Cc[k]=sum_{i=0}^{k}\
    \ a[i]*b[k-i] \u3092\u6C42\u3081\u308B\uFF0EO(N^2).\nstd::vector<long long> convolve(const\
    \ std::vector<long long> &a, const std::vector<long long> &b) {\n    if(a.size()\
    \ == 0 or b.size() == 0) return std::vector<long long>();\n    const int n = a.size()\
    \ + b.size() - 1;\n    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);\n\
    \    std::copy(a.begin(), a.end(), na.begin());\n    std::copy(b.begin(), b.end(),\
    \ nb.begin());\n    na = transform(na), nb = transform(nb);\n    for(int i = 0;\
    \ i < n; ++i) na[i] *= nb[i];\n    na = transform(na, true);\n    std::vector<long\
    \ long> res(n);\n    for(int i = 0; i < n; ++i) res[i] = na[i].real() + 0.5;\n\
    \    return res;\n}\n\n}  // namespace dft\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP\n#define ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP\
    \ 1\n\n/**\n * @brief Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/FFT/discrete_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#include <cmath>\n#include <complex>\n#include <vector>\n\
    \nnamespace algorithm {\n\nnamespace dft {\n\nusing D = double;\n\nconst D PI\
    \ = std::acos(-1.0);\n\n// \u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\u63DB\uFF0E\
    O(N^2).\nstd::vector<std::complex<D> > transform(const std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    const int n = a.size();\n    std::vector<std::complex<D>\
    \ > res(n, 0.0);\n    for(int i = 0; i < n; ++i) {\n        D ang = 2 * PI / n\
    \ * i;\n        if(inv) ang = -ang;\n        for(int j = 0; j < n; ++j) res[i]\
    \ += a[j] * std::polar(1.0, ang * j);\n    }\n    if(inv) {\n        for(int i\
    \ = 0; i < n; ++i) res[i] /= n;\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// k=0,1,...,N \u306B\u3064\u3044\u3066\uFF0Cc[k]=sum_{i=0}^{k}\
    \ a[i]*b[k-i] \u3092\u6C42\u3081\u308B\uFF0EO(N^2).\nstd::vector<D> convolve(const\
    \ std::vector<D> &a, const std::vector<D> &b) {\n    if(a.size() == 0 or b.size()\
    \ == 0) return std::vector<D>();\n    const int n = a.size() + b.size() - 1;\n\
    \    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);\n    std::copy(a.begin(),\
    \ a.end(), na.begin());\n    std::copy(b.begin(), b.end(), nb.begin());\n    na\
    \ = transform(na), nb = transform(nb);\n    for(int i = 0; i < n; ++i) na[i] *=\
    \ nb[i];\n    na = transform(na, true);\n    std::vector<D> res(n);\n    for(int\
    \ i = 0; i < n; ++i) res[i] = na[i].real();\n    return res;\n}\n\n// \u7573\u307F\
    \u8FBC\u307F\uFF0E\n// k=0,1,...,N \u306B\u3064\u3044\u3066\uFF0Cc[k]=sum_{i=0}^{k}\
    \ a[i]*b[k-i] \u3092\u6C42\u3081\u308B\uFF0EO(N^2).\nstd::vector<long long> convolve(const\
    \ std::vector<long long> &a, const std::vector<long long> &b) {\n    if(a.size()\
    \ == 0 or b.size() == 0) return std::vector<long long>();\n    const int n = a.size()\
    \ + b.size() - 1;\n    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);\n\
    \    std::copy(a.begin(), a.end(), na.begin());\n    std::copy(b.begin(), b.end(),\
    \ nb.begin());\n    na = transform(na), nb = transform(nb);\n    for(int i = 0;\
    \ i < n; ++i) na[i] *= nb[i];\n    na = transform(na, true);\n    std::vector<long\
    \ long> res(n);\n    for(int i = 0; i < n; ++i) res[i] = na[i].real() + 0.5;\n\
    \    return res;\n}\n\n}  // namespace dft\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/FFT/discrete_fourier_transform.hpp
  requiredBy: []
  timestamp: '2023-10-02 01:12:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/FFT/discrete_fourier_transform.hpp
layout: document
redirect_from:
- /library/src/Math/FFT/discrete_fourier_transform.hpp
- /library/src/Math/FFT/discrete_fourier_transform.hpp.html
title: "Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\
  \u63DB\uFF09"
---
## 概要

離散フーリエ変換 (DFT: Discrete Fourier Transform) を用いた畳み込みを行う．

具体的には，長さ $N, M$ の数列 $\left\{a_0, a_1, \ldots a_{N-1}\right\}, \left\{b_0, b_1, \ldots b_{M-1}\right\}$ に対して

$$
c_k = \sum_{i=0}^{k}{a_i b_{k-i}}
$$

を満たす長さ $N + M - 1$ の数列 $\left\{c_0, c_1, \ldots c_{N+M-2}\right\}$ を $\mathcal{O}\left(\left(N + M\right)^2\right)$ で求める．


## 参考文献

1. "離散フーリエ変換". Wikipedia. <https://ja.wikipedia.org/wiki/離散フーリエ変換>.
1. AngrySadEight. "高速フーリエ変換・数論変換を改めて理解しようという話". Qiita. <https://qiita.com/AngrySadEight/items/0dfde26060daaf6a2fda>.
1. tatyam. "【競プロer向け】FFT を習得しよう！". 東京工業大学で活動するデジタル創作. <https://trap.jp/post/1386/>.
1. "競プロのための高速フーリエ変換". <https://www.creativ.xyz/fast-fourier-transform/>.
