---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/ITP1_3_D.test.cpp
    title: verify/aoj/ITP1_3_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/divisors.hpp\"\n\n\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\nnamespace internal {\n\ntemplate <std::integral\
    \ Res>\nconstexpr std::vector<Res> divisors(std::uint64_t n) {\n    std::vector<Res>\
    \ divs;  // divs[]:=(list of divisors of n).\n    for(std::uint64_t p = 1; p <\
    \ 1ULL << 32 and p * p <= n; ++p) {\n        if(n % p != 0) continue;\n      \
    \  divs.push_back(p);\n        auto q = n / p;\n        if(q != p) divs.push_back(q);\n\
    \    }\n    divs.shrink_to_fit();\n    std::sort(divs.begin(), divs.end());\n\
    \    return divs;\n}\n\n}  // namespace internal\n\n// \u7D04\u6570\u5217\u6319\
    \uFF0EO(\u221An).\ntemplate <std::integral Type>\nconstexpr std::vector<Type>\
    \ divisors(Type n) {\n    assert(n > 0);\n    return internal::divisors<Type>(n);\n\
    }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DIVISORS_HPP\n#define ALGORITHM_DIVISORS_HPP 1\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <concepts>\n#include <cstdint>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\nnamespace internal {\n\ntemplate <std::integral\
    \ Res>\nconstexpr std::vector<Res> divisors(std::uint64_t n) {\n    std::vector<Res>\
    \ divs;  // divs[]:=(list of divisors of n).\n    for(std::uint64_t p = 1; p <\
    \ 1ULL << 32 and p * p <= n; ++p) {\n        if(n % p != 0) continue;\n      \
    \  divs.push_back(p);\n        auto q = n / p;\n        if(q != p) divs.push_back(q);\n\
    \    }\n    divs.shrink_to_fit();\n    std::sort(divs.begin(), divs.end());\n\
    \    return divs;\n}\n\n}  // namespace internal\n\n// \u7D04\u6570\u5217\u6319\
    \uFF0EO(\u221An).\ntemplate <std::integral Type>\nconstexpr std::vector<Type>\
    \ divisors(Type n) {\n    assert(n > 0);\n    return internal::divisors<Type>(n);\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/divisors.hpp
  requiredBy: []
  timestamp: '2026-02-28 03:24:16+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/ITP1_3_D.test.cpp
documentation_of: algorithm/Math/NumberTheory/divisors.hpp
layout: document
title: "\u7D04\u6570\u5217\u6319"
---


## 概要

与えられる自然数 $n$ の約数を列挙する．

本ライブラリでは「試し割り法 (trial division)」を用いて実装しており，計算量は $\mathcal{O}(\sqrt n)$ となる．

## Interface

| 関数                                                                              | 説明                   | 制約    | 計算量                 |
| --------------------------------------------------------------------------------- | ---------------------- | ------- | ---------------------- |
| `template <std::integral Type>`<br>`constexpr std::vector<Type> divisors(Type n)` | $n$ の約数を列挙する． | $n > 0$ | $\mathcal{O}(\sqrt n)$ |

## 参考

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
