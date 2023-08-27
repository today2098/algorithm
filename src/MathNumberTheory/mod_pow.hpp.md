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
  bundledCode: "#line 1 \"src/MathNumberTheory/mod_pow.hpp\"\n\n\n\n#include <cassert>\n\
    #include <numeric>\n#include <utility>\n\nnamespace algorithm {\n\n// \u7E70\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0En^k (mod m)\u3092\u6C42\
    \u3081\u308B\uFF0EO(logK).\nlong long mod_pow(long long n, long long k, int m)\
    \ {\n    assert(k >= 0 and m >= 1);\n    n %= m;\n    long long res = 1;\n   \
    \ while(k > 0) {\n        if(k & 1LL) res = res * n % m;\n        n = n * n %\
    \ m;\n        k >>= 1;\n    }\n    return res;\n}\n\n// \u9006\u5143\uFF0Ea^-1\
    \ (mod m)\u3092\u6C42\u3081\u308B\uFF0E\u305F\u3060\u3057\uFF0Ca\u3068m\u306F\u4E92\
    \u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0E\nlong long mod_inv(long\
    \ long a, int m) {\n    assert(m >= 1 and std::gcd(a, m) == 1);\n    long long\
    \ b = m, u = 1, v = 0;\n    while(b) {\n        long long t = a / b;\n       \
    \ a -= t * b, u -= t * v;\n        std::swap(a, b), std::swap(u, v);\n    }\n\
    \    return (u % m + m) % m;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n#include\
    \ <cassert>\n#include <numeric>\n#include <utility>\n\nnamespace algorithm {\n\
    \n// \u7E70\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0En^k\
    \ (mod m)\u3092\u6C42\u3081\u308B\uFF0EO(logK).\nlong long mod_pow(long long n,\
    \ long long k, int m) {\n    assert(k >= 0 and m >= 1);\n    n %= m;\n    long\
    \ long res = 1;\n    while(k > 0) {\n        if(k & 1LL) res = res * n % m;\n\
    \        n = n * n % m;\n        k >>= 1;\n    }\n    return res;\n}\n\n// \u9006\
    \u5143\uFF0Ea^-1 (mod m)\u3092\u6C42\u3081\u308B\uFF0E\u305F\u3060\u3057\uFF0C\
    a\u3068m\u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0E\nlong\
    \ long mod_inv(long long a, int m) {\n    assert(m >= 1 and std::gcd(a, m) ==\
    \ 1);\n    long long b = m, u = 1, v = 0;\n    while(b) {\n        long long t\
    \ = a / b;\n        a -= t * b, u -= t * v;\n        std::swap(a, b), std::swap(u,\
    \ v);\n    }\n    return (u % m + m) % m;\n}\n\n}  // namespace algorithm\n\n\
    #endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/MathNumberTheory/mod_pow.hpp
  requiredBy: []
  timestamp: '2023-01-21 22:09:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/MathNumberTheory/mod_pow.hpp
layout: document
redirect_from:
- /library/src/MathNumberTheory/mod_pow.hpp
- /library/src/MathNumberTheory/mod_pow.hpp.html
title: src/MathNumberTheory/mod_pow.hpp
---
