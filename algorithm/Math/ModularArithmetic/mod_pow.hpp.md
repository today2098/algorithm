---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modulo.hpp
    title: "\u30E2\u30B8\u30E5\u30ED\u6F14\u7B97"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/ModularArithmetic/modint.hpp
    title: "Modint\u69CB\u9020\u4F53"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/NTL_1_B.test.cpp
    title: verify/aoj/NTL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/yukicoder/no_1681.test.cpp
    title: verify/yukicoder/no_1681.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\n\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n\n#line 1 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\n\n\n#line 7 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \n#line 1 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\n\n\n\n#line 6 \"algorithm/Math/ModularArithmetic/modulo.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// Return x mod m.\ntemplate\
    \ <std::unsigned_integral Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t\
    \ m) { return x % m; }\n\n// Return x mod m.\ntemplate <std::unsigned_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::int32_t m) { return modulo(x,\
    \ static_cast<std::uint32_t>(m)); }\n\n// Return x mod m.\ntemplate <std::signed_integral\
    \ Type>\nconstexpr std::uint32_t modulo(Type x, std::uint32_t m) {\n    x %= static_cast<std::int64_t>(m);\n\
    \    if(x < 0) x += static_cast<std::int64_t>(m);\n    return x;\n}\n\n// Return\
    \ x mod m.\ntemplate <std::signed_integral Type>\nconstexpr std::uint32_t modulo(Type\
    \ x, std::int32_t m) {\n    x %= m;\n    if(x < 0) x += m;\n    return x;\n}\n\
    \n}  // namespace internal\n\n}  // namespace algorithm\n\n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\nnamespace internal {\n\n// Return pair of (x, g)\
    \ s.t. g=gcd(a,m), ax=g (mod m), 0<=x<m/g.\nconstexpr std::pair<std::uint32_t,\
    \ std::uint32_t> mod_inv(std::uint32_t a, std::uint32_t m) {\n    if(a == 0) return\
    \ {0, m};\n    std::uint32_t s = m, t = a;\n    std::uint32_t u = 0, v = 1;\n\
    \    while(true) {\n        std::uint32_t q = s / t;\n        s -= t * q, u -=\
    \ v * q;\n        if(s == 0) return {v, t};\n        q = t / s;\n        t -=\
    \ s * q, v -= u * q;\n        if(t == 0) return {u + m / s, s};  // u will be\
    \ negative.\n    }\n}\n\n}  // namespace internal\n\n// \u30E2\u30B8\u30E5\u30E9\
    \u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\
    \u3081\u308B\uFF0E\u89E3\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\
    \u6761\u4EF6\u306F\uFF0Ca\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(log a).\ntemplate <std::integral Type>\nconstexpr std::int64_t\
    \ mod_inv(Type a, std::int32_t m) {\n    assert(m >= 1);\n    auto [x, g] = internal::mod_inv(internal::modulo(a,\
    \ m), m);\n    assert(g == 1);\n    return x;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 10 \"algorithm/Math/ModularArithmetic/mod_pow.hpp\"\n\nnamespace algorithm\
    \ {\n\nnamespace internal {\n\n// Return n^k mod m.\nconstexpr std::uint32_t mod_pow(std::uint64_t\
    \ n, unsigned long long k, std::uint32_t m) {\n    std::uint64_t res = 1;\n  \
    \  for(; k > 0; k >>= 1) {\n        if(k & 1ULL) res = res * n % m;\n        n\
    \ = n * n % m;\n    }\n    return res;\n}\n\n}  // namespace internal\n\n// \u7E70\
    \u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(log k).\n\
    template <std::integral Type>\nconstexpr std::int64_t mod_pow(Type n, long long\
    \ k, std::int32_t m) {\n    assert(m >= 1);\n    auto r = internal::modulo(n,\
    \ m);\n    if(k < 0) {\n        auto [x, g] = internal::mod_inv(r, m);\n     \
    \   assert(g == 1);\n        r = x, k = -k;\n    }\n    return internal::mod_pow(r,\
    \ k, m);\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MOD_POW_HPP\n#define ALGORITHM_MOD_POW_HPP 1\n\n#include\
    \ <cassert>\n#include <concepts>\n#include <cstdint>\n\n#include \"mod_inv.hpp\"\
    \n#include \"modulo.hpp\"\n\nnamespace algorithm {\n\nnamespace internal {\n\n\
    // Return n^k mod m.\nconstexpr std::uint32_t mod_pow(std::uint64_t n, unsigned\
    \ long long k, std::uint32_t m) {\n    std::uint64_t res = 1;\n    for(; k > 0;\
    \ k >>= 1) {\n        if(k & 1ULL) res = res * n % m;\n        n = n * n % m;\n\
    \    }\n    return res;\n}\n\n}  // namespace internal\n\n// \u7E70\u308A\u8FD4\
    \u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09\uFF0EO(log k).\ntemplate <std::integral\
    \ Type>\nconstexpr std::int64_t mod_pow(Type n, long long k, std::int32_t m) {\n\
    \    assert(m >= 1);\n    auto r = internal::modulo(n, m);\n    if(k < 0) {\n\
    \        auto [x, g] = internal::mod_inv(r, m);\n        assert(g == 1);\n   \
    \     r = x, k = -k;\n    }\n    return internal::mod_pow(r, k, m);\n}\n\n}  //\
    \ namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/Math/ModularArithmetic/mod_inv.hpp
  - algorithm/Math/ModularArithmetic/modulo.hpp
  isVerificationFile: false
  path: algorithm/Math/ModularArithmetic/mod_pow.hpp
  requiredBy:
  - algorithm/Math/ModularArithmetic/modint.hpp
  timestamp: '2026-02-21 15:04:17+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/NTL_1_B.test.cpp
  - verify/yukicoder/no_1681.test.cpp
documentation_of: algorithm/Math/ModularArithmetic/mod_pow.hpp
layout: document
title: "\u7E70\u308A\u8FD4\u3057\u4E8C\u4E57\u6CD5\uFF08mod\u4ED8\u304D\uFF09"
---


## 概要

$n, k \in \mathbb{Z}, m \in \mathbb{N}$ について，$n^k \bmod m$ を求める．

本ライブラリでは「繰り返し二乗法」を用いて実装しており，計算量は $\mathcal{O}(\log k)$ である．

## Interface

| 関数                                                                                           | 説明                                        | 計算量                |
| ---------------------------------------------------------------------------------------------- | ------------------------------------------- | --------------------- |
| `template <std::integral Type>`<br>`std::int64_t mod_pow(Type n, long long k, std::int32_t m)` | 法 $m$ における整数 $n$ の $k$ 乗を求める． | $\mathcal{O}(\log k)$ |

## 関連問題

- "B - n^p mod m". AtCoder Typical Contest 002. AtCoder. <https://atcoder.jp/contests/atc002/tasks/atc002_b>.
