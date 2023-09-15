---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_D.test.cpp
    title: test/aoj-NTL_1_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/totient.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/totient.hpp\"\n/**\n * @brief \u30AA\
    \u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\n * @docs docs/Math/NumberTheory/totient.md\n\
    \ */\n\n#ifndef ALGORITHM_TOTIENT_HPP\n#define ALGORITHM_TOTIENT_HPP 1\n\n#include\
    \ <cassert>\n\nnamespace algorithm {\n\n// \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\
    \u30A1\u30A4\u95A2\u6570\uFF0E\n// n\u4EE5\u4E0B\u3067n\u3068\u4E92\u3044\u306B\
    \u7D20\u306A\u81EA\u7136\u6570\u306E\u500B\u6570\u3092\u6C42\u3081\u308B\uFF0E\
    O(\u221AN).\ntemplate <typename Type>\nType totient(Type n) {\n    assert(n >=\
    \ 1);\n    Type res = n;\n    for(Type p = 2; p * p <= n; ++p) {\n        if(n\
    \ % p == 0) {\n            res -= res / p;\n            while(n % p == 0) n /=\
    \ p;\n        }\n    }\n    if(n > 1) res -= res / n;\n    return res;\n}\n\n\
    };  // namespace algorithm\n\n#endif\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\
    \n * @docs docs/Math/NumberTheory/totient.md\n */\n\n#ifndef ALGORITHM_TOTIENT_HPP\n\
    #define ALGORITHM_TOTIENT_HPP 1\n\n#include <cassert>\n\nnamespace algorithm {\n\
    \n// \u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570\uFF0E\n// n\u4EE5\
    \u4E0B\u3067n\u3068\u4E92\u3044\u306B\u7D20\u306A\u81EA\u7136\u6570\u306E\u500B\
    \u6570\u3092\u6C42\u3081\u308B\uFF0EO(\u221AN).\ntemplate <typename Type>\nType\
    \ totient(Type n) {\n    assert(n >= 1);\n    Type res = n;\n    for(Type p =\
    \ 2; p * p <= n; ++p) {\n        if(n % p == 0) {\n            res -= res / p;\n\
    \            while(n % p == 0) n /= p;\n        }\n    }\n    if(n > 1) res -=\
    \ res / n;\n    return res;\n}\n\n};  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/totient.hpp
  requiredBy: []
  timestamp: '2023-09-13 00:24:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_D.test.cpp
documentation_of: src/Math/NumberTheory/totient.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/totient.hpp
- /library/src/Math/NumberTheory/totient.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u306E\u30D5\u30A1\u30A4\u95A2\u6570"
---
## 概要

正の整数 $n$ に対して，$n$ と互いに素である $1$ 以上 $n$ 以下の自然数の個数 $\varphi(n)$ を求める．

$$
\varphi(n) = \#\{a:1 \leq a \leq n, \gcd(a, n) = 1 \}
$$

$\varphi(n)$ は次式から求められる．

$$
\varphi(n) = n \prod_{k=1}^d (1 - \frac{1}{p_k}) \text{ (ただし，$p_k$ は $n$ の素因数)}
$$


## 参考文献

1. "オイラーのφ関数". Wikipedia. <https://ja.wikipedia.org/wiki/オイラーのφ関数>.
