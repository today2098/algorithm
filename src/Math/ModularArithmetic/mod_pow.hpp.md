---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_B.test.cpp
    title: test/aoj-NTL_1_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/ModularArithmetic/mod_pow.md
    document_title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n/**\n *\
    \ @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\
    \n * @docs docs/Math/ModularArithmetic/mod_pow.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0E\n// a^k mod m \u3092\u6C42\u3081\u308B\uFF0EO(logK).\n\
    int mod_pow(long long a, long long k, int m) {\n    assert(k >= 0);\n    assert(m\
    \ >= 1);\n    long long res = 1;\n    a %= m;\n    while(k > 0) {\n        if(k\
    \ & 1LL) res = res * a % m;\n        a = a * a % m;\n        k >>= 1;\n    }\n\
    \    return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n/**\n *\
    \ @brief \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\
    \n * @docs docs/Math/ModularArithmetic/mod_pow.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// \u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08\
    mod\u4ED8\u304D\uFF09\uFF0E\n// a^k mod m \u3092\u6C42\u3081\u308B\uFF0EO(logK).\n\
    int mod_pow(long long a, long long k, int m) {\n    assert(k >= 0);\n    assert(m\
    \ >= 1);\n    long long res = 1;\n    a %= m;\n    while(k > 0) {\n        if(k\
    \ & 1LL) res = res * a % m;\n        a = a * a % m;\n        k >>= 1;\n    }\n\
    \    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/mod_pow.hpp
  requiredBy: []
  timestamp: '2023-10-15 15:49:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_B.test.cpp
documentation_of: src/Math/ModularArithmetic/mod_pow.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/mod_pow.hpp
- /library/src/Math/ModularArithmetic/mod_pow.hpp.html
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
---
## 概要

整数 $a, k, m$ に対して

$$
a^k \bmod m
$$

を繰り返し二乗法を用いて求める．

アルゴリズムの計算量は $\mathcal{O}(\log k)$．
