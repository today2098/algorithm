---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Math/NumberTheory/garner.hpp
    title: Garner's Algorithm
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/mod_inv.hpp\"\n/**\n * @brief\
    \ \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\n */\n\
    \n#ifndef ALGORITHM_MOD_INV_HPP\n#define ALGORITHM_MOD_INV_HPP 1\n\n#include <cassert>\n\
    #include <utility>\n\nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\
    \u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 (mod m) \u3092\u6C42\
    \u3081\u308B\uFF0E\u305F\u3060\u3057\uFF0Ca\u3068m\u306F\u4E92\u3044\u306B\u7D20\
    \u3067\u3042\u308B\u3053\u3068\uFF0E\nlong long mod_inv(long long a, int m) {\n\
    \    assert(m >= 2);\n    long long b = m, u = 1, v = 0;\n    while(b != 0) {\n\
    \        long long t = a / b;\n        a -= b * t, u -= v * t;\n        std::swap(a,\
    \ b), std::swap(u, v);\n    }\n    // assert((\"a and m need to be coprime.\"\
    , a == 1));\n    u %= m;\n    if(u < 0) u += m;\n    return u;\n}\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  code: "/**\n * @brief \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\
    \u5143\uFF09\n */\n\n#ifndef ALGORITHM_MOD_INV_HPP\n#define ALGORITHM_MOD_INV_HPP\
    \ 1\n\n#include <cassert>\n#include <utility>\n\nnamespace algorithm {\n\n// \u30E2\
    \u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1\
    \ (mod m) \u3092\u6C42\u3081\u308B\uFF0E\u305F\u3060\u3057\uFF0Ca\u3068m\u306F\
    \u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0E\nlong long mod_inv(long\
    \ long a, int m) {\n    assert(m >= 2);\n    long long b = m, u = 1, v = 0;\n\
    \    while(b != 0) {\n        long long t = a / b;\n        a -= b * t, u -= v\
    \ * t;\n        std::swap(a, b), std::swap(u, v);\n    }\n    // assert((\"a and\
    \ m need to be coprime.\", a == 1));\n    u %= m;\n    if(u < 0) u += m;\n   \
    \ return u;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/ModularArithmetic/mod_inv.hpp
  requiredBy:
  - src/Math/NumberTheory/garner.hpp
  timestamp: '2023-08-30 16:00:58+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/ModularArithmetic/mod_inv.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/mod_inv.hpp
- /library/src/Math/ModularArithmetic/mod_inv.hpp.html
title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
---
