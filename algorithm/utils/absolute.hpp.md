---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/greatest_common_divisor.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/NTL_1_C.test.cpp
    title: verify/aoj/NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/utils/absolute.hpp\"\n\n\n\n#include <concepts>\n\
    #include <cstdint>\n\nnamespace algorithm {\n\nnamespace internal {\n\n// Returns\
    \ the absolute value as type Res.\ntemplate <std::unsigned_integral Res, std::unsigned_integral\
    \ Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n\
    \    return static_cast<Res>(n);\n}\n\n// Returns the absolute value as type Res.\n\
    template <std::unsigned_integral Res, std::signed_integral Type>\nconstexpr Res\
    \ abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    if(n < 0)\
    \ return static_cast<Res>(-static_cast<std::uintmax_t>(n));\n    return static_cast<Res>(n);\n\
    }\n\n}  // namespace internal\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_ABSOLUTE_HPP\n#define ALGORITHM_ABSOLUTE_HPP 1\n\n#include\
    \ <concepts>\n#include <cstdint>\n\nnamespace algorithm {\n\nnamespace internal\
    \ {\n\n// Returns the absolute value as type Res.\ntemplate <std::unsigned_integral\
    \ Res, std::unsigned_integral Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res)\
    \ >= sizeof(Type));\n    return static_cast<Res>(n);\n}\n\n// Returns the absolute\
    \ value as type Res.\ntemplate <std::unsigned_integral Res, std::signed_integral\
    \ Type>\nconstexpr Res abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n\
    \    if(n < 0) return static_cast<Res>(-static_cast<std::uintmax_t>(n));\n   \
    \ return static_cast<Res>(n);\n}\n\n}  // namespace internal\n\n}  // namespace\
    \ algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/utils/absolute.hpp
  requiredBy:
  - algorithm/Math/NumberTheory/least_common_multiple.hpp
  - algorithm/Math/NumberTheory/greatest_common_divisor.hpp
  timestamp: '2026-02-27 12:03:57+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/NTL_1_C.test.cpp
documentation_of: algorithm/utils/absolute.hpp
layout: document
title: "\u6574\u6570\u578B\u306E\u7D76\u5BFE\u5024"
---


## 参考

1. lpha_z. "C++で安全に絶対値を求める". HatenaBlog. <https://lpha-z.hatenablog.com/entry/2018/08/05/231500>.
