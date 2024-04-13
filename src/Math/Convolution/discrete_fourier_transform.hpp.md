---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/Convolution/discrete_fourier_transform.md
    document_title: "Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\
      \u30A8\u5909\u63DB\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/Convolution/discrete_fourier_transform.hpp\"\n\n\
    \n\n/**\n * @brief Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\
    \u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/Convolution/discrete_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#include <cmath>\n#include <complex>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace algorithm {\n\nnamespace dft {\n\nusing D = double;\n\
    \nconst D PI = std::acos(-1.0);\n\n// Discrete Fourier Transform\uFF08\u96E2\u6563\
    \u30D5\u30FC\u30EA\u30A8\u5909\u63DB\uFF09. O(N^2).\nvoid transform(std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    if(a.empty()) return;\n    const int n = a.size();\n\
    \    std::vector<std::complex<D> > res(n, 0.0);\n    D ang = 2 * PI / n;\n   \
    \ if(inv) ang = -ang;\n    for(int i = 0; i < n; ++i) {\n        D tmp = ang *\
    \ i;\n        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar<D>(1.0, tmp\
    \ * j);\n    }\n    if(inv) {\n        for(int i = 0; i < n; ++i) res[i] /= n;\n\
    \    }\n    a = res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217\
    a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\
    \u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type>\n\
    std::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size(), m = b.size();\n    std::vector<Type> res(n + m -\
    \ 1, 0);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j)\
    \ res[i + j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\n\
    template <typename Type, typename std::enable_if_t<std::is_integral_v<Type>, bool>\
    \ = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    std::vector<std::complex<D> >\
    \ na(n, 0.0), nb(n, 0.0);\n    std::copy(a.begin(), a.end(), na.begin());\n  \
    \  std::copy(b.begin(), b.end(), nb.begin());\n    transform(na), transform(nb);\n\
    \    for(int i = 0; i < n; ++i) na[i] *= nb[i];\n    transform(na, true);\n  \
    \  std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i] = na[i].real()\
    \ + 0.5;\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217\
    a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\
    \u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type, typename\
    \ std::enable_if_t<std::is_floating_point_v<Type>, bool> = false>\nstd::vector<Type>\
    \ convolve(const std::vector<Type> &a, const std::vector<Type> &b) {\n    if(a.size()\
    \ == 0 or b.size() == 0) return std::vector<Type>();\n    const int n = a.size()\
    \ + b.size() - 1;\n    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);\n\
    \    std::copy(a.begin(), a.end(), na.begin());\n    std::copy(b.begin(), b.end(),\
    \ nb.begin());\n    transform(na), transform(nb);\n    for(int i = 0; i < n; ++i)\
    \ na[i] *= nb[i];\n    transform(na, true);\n    std::vector<Type> res(n);\n \
    \   for(int i = 0; i < n; ++i) res[i] = na[i].real();\n    return res;\n}\n\n\
    }  // namespace dft\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP\n#define ALGORITHM_DISCRETE_FOURIER_TRANSFORM_HPP\
    \ 1\n\n/**\n * @brief Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\
    \u30EA\u30A8\u5909\u63DB\uFF09\n * @docs docs/Math/Convolution/discrete_fourier_transform.md\n\
    \ */\n\n#include <algorithm>\n#include <cmath>\n#include <complex>\n#include <type_traits>\n\
    #include <vector>\n\nnamespace algorithm {\n\nnamespace dft {\n\nusing D = double;\n\
    \nconst D PI = std::acos(-1.0);\n\n// Discrete Fourier Transform\uFF08\u96E2\u6563\
    \u30D5\u30FC\u30EA\u30A8\u5909\u63DB\uFF09. O(N^2).\nvoid transform(std::vector<std::complex<D>\
    \ > &a, bool inv = false) {\n    if(a.empty()) return;\n    const int n = a.size();\n\
    \    std::vector<std::complex<D> > res(n, 0.0);\n    D ang = 2 * PI / n;\n   \
    \ if(inv) ang = -ang;\n    for(int i = 0; i < n; ++i) {\n        D tmp = ang *\
    \ i;\n        for(int j = 0; j < n; ++j) res[i] += a[j] * std::polar<D>(1.0, tmp\
    \ * j);\n    }\n    if(inv) {\n        for(int i = 0; i < n; ++i) res[i] /= n;\n\
    \    }\n    a = res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217\
    a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\
    \u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type>\n\
    std::vector<Type> convolve_naive(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size(), m = b.size();\n    std::vector<Type> res(n + m -\
    \ 1, 0);\n    for(int i = 0; i < n; ++i) {\n        for(int j = 0; j < m; ++j)\
    \ res[i + j] += a[i] * b[j];\n    }\n    return res;\n}\n\n// \u7573\u307F\u8FBC\
    \u307F\uFF0E\n// \u6570\u5217a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i}\
    \ a[k]*b[i-k] \u3068\u306A\u308B\u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\n\
    template <typename Type, typename std::enable_if_t<std::is_integral_v<Type>, bool>\
    \ = false>\nstd::vector<Type> convolve(const std::vector<Type> &a, const std::vector<Type>\
    \ &b) {\n    if(a.size() == 0 or b.size() == 0) return std::vector<Type>();\n\
    \    const int n = a.size() + b.size() - 1;\n    std::vector<std::complex<D> >\
    \ na(n, 0.0), nb(n, 0.0);\n    std::copy(a.begin(), a.end(), na.begin());\n  \
    \  std::copy(b.begin(), b.end(), nb.begin());\n    transform(na), transform(nb);\n\
    \    for(int i = 0; i < n; ++i) na[i] *= nb[i];\n    transform(na, true);\n  \
    \  std::vector<Type> res(n);\n    for(int i = 0; i < n; ++i) res[i] = na[i].real()\
    \ + 0.5;\n    return res;\n}\n\n// \u7573\u307F\u8FBC\u307F\uFF0E\n// \u6570\u5217\
    a, b\u306B\u5BFE\u3057\u3066\uFF0Cc[i]=sum_{k=0}^{i} a[k]*b[i-k] \u3068\u306A\u308B\
    \u6570\u5217c\u3092\u6C42\u3081\u308B\uFF0EO(N^2).\ntemplate <typename Type, typename\
    \ std::enable_if_t<std::is_floating_point_v<Type>, bool> = false>\nstd::vector<Type>\
    \ convolve(const std::vector<Type> &a, const std::vector<Type> &b) {\n    if(a.size()\
    \ == 0 or b.size() == 0) return std::vector<Type>();\n    const int n = a.size()\
    \ + b.size() - 1;\n    std::vector<std::complex<D> > na(n, 0.0), nb(n, 0.0);\n\
    \    std::copy(a.begin(), a.end(), na.begin());\n    std::copy(b.begin(), b.end(),\
    \ nb.begin());\n    transform(na), transform(nb);\n    for(int i = 0; i < n; ++i)\
    \ na[i] *= nb[i];\n    transform(na, true);\n    std::vector<Type> res(n);\n \
    \   for(int i = 0; i < n; ++i) res[i] = na[i].real();\n    return res;\n}\n\n\
    }  // namespace dft\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/Convolution/discrete_fourier_transform.hpp
  requiredBy: []
  timestamp: '2023-10-07 23:19:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/Convolution/discrete_fourier_transform.hpp
layout: document
redirect_from:
- /library/src/Math/Convolution/discrete_fourier_transform.hpp
- /library/src/Math/Convolution/discrete_fourier_transform.hpp.html
title: "Discrete Fourier Transform\uFF08\u96E2\u6563\u30D5\u30FC\u30EA\u30A8\u5909\
  \u63DB\uFF09"
---
## 概要

離散フーリエ変換 (DFT: Discrete Fourier Transform) を用いた畳み込みを行う．

具体的には，長さ $N$ の数列 $\lbrace a_n \rbrace$ と長さ $M$ の数列 $\lbrace b_n \rbrace$ に対して

$$
c_i = \sum_{k=0}^{i} a_k b_{i-k}
$$

となる長さ $N + M - 1$ の数列 $\lbrace c_n \rbrace$ を $\mathcal{O} \left\lparen \left\lparen N + M \right\rparen ^2 \right\rparen$ で求める．


## 参考文献

1. "離散フーリエ変換". Wikipedia. <https://ja.wikipedia.org/wiki/離散フーリエ変換>.
1. AngrySadEight. "高速フーリエ変換・数論変換を改めて理解しようという話". Qiita. <https://qiita.com/AngrySadEight/items/0dfde26060daaf6a2fda>.
1. tatyam. "【競プロer向け】FFT を習得しよう！". 東京工業大学で活動するデジタル創作. <https://trap.jp/post/1386/>.
1. "競プロのための高速フーリエ変換". <https://www.creativ.xyz/fast-fourier-transform/>.