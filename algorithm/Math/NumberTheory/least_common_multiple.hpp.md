---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: algorithm/Math/NumberTheory/greatest_common_divisor.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: algorithm/utils/absolute.hpp
    title: "\u6574\u6570\u578B\u306E\u7D76\u5BFE\u5024"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/aoj/NTL_1_C.test.cpp
    title: verify/aoj/NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"algorithm/Math/NumberTheory/least_common_multiple.hpp\"\n\
    \n\n\n#include <concepts>\n#include <type_traits>\n\n#line 1 \"algorithm/utils/absolute.hpp\"\
    \n\n\n\n#line 5 \"algorithm/utils/absolute.hpp\"\n#include <cstdint>\n\nnamespace\
    \ algorithm {\n\nnamespace internal {\n\n// Returns the absolute value as type\
    \ Res.\ntemplate <std::unsigned_integral Res, std::unsigned_integral Type>\nconstexpr\
    \ Res abs(Type n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    return\
    \ static_cast<Res>(n);\n}\n\n// Returns the absolute value as type Res.\ntemplate\
    \ <std::unsigned_integral Res, std::signed_integral Type>\nconstexpr Res abs(Type\
    \ n) {\n    static_assert(sizeof(Res) >= sizeof(Type));\n    if(n < 0) return\
    \ static_cast<Res>(-static_cast<std::uintmax_t>(n));\n    return static_cast<Res>(n);\n\
    }\n\n}  // namespace internal\n\n}  // namespace algorithm\n\n\n#line 1 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\
    \n\n\n\n#line 6 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n\
    #line 8 \"algorithm/Math/NumberTheory/greatest_common_divisor.hpp\"\n\nnamespace\
    \ algorithm {\n\nnamespace internal {\n\ntemplate <std::integral Type>\nconstexpr\
    \ Type gcd(Type a, Type b) {\n    if(b == 0) return a;\n    return gcd(b, a %\
    \ b);\n}\n\n}  // namespace internal\n\n// Returns the greatest common divisor\
    \ (GCD) of |a| and |b|.\ntemplate <std::integral T, std::integral U>\nconstexpr\
    \ auto gcd(T a, U b) {\n    using ct = std::common_type_t<T, U>;\n    using ut\
    \ = std::make_unsigned_t<ct>;\n    ut ua = internal::abs<ut>(a);\n    ut ub =\
    \ internal::abs<ut>(b);\n    return static_cast<ct>(internal::gcd(ua, ub));\n\
    }\n\n// Returns the greatest common divisor (GCD) of all arguments.\ntemplate\
    \ <std::integral Type, std::integral... Args>\nconstexpr auto gcd(Type first,\
    \ Args... args) { return gcd(first, gcd(args...)); }\n\n}  // namespace algorithm\n\
    \n\n#line 9 \"algorithm/Math/NumberTheory/least_common_multiple.hpp\"\n\nnamespace\
    \ algorithm {\n\nnamespace internal {\n\ntemplate <std::integral Type>\nconstexpr\
    \ Type lcm(Type a, Type b) {\n    if(a == 0 or b == 0) return 0;\n    return a\
    \ / internal::gcd(a, b) * b;\n}\n\n}  // namespace internal\n\n// Returns the\
    \ least common multiple (LCM) of |a| and |b|.\ntemplate <std::integral T, std::integral\
    \ U>\nconstexpr auto lcm(T a, U b) {\n    using ct = std::common_type_t<T, U>;\n\
    \    using ut = std::make_unsigned_t<ct>;\n    ut ua = internal::abs<ut>(a);\n\
    \    ut ub = internal::abs<ut>(b);\n    return static_cast<ct>(internal::lcm(ua,\
    \ ub));\n}\n\n// Returns the least common multiple (LCM) of all arguments.\ntemplate\
    \ <std::integral Type, std::integral... Args>\nconstexpr auto lcm(Type first,\
    \ Args... args) { return lcm(first, lcm(args...)); }\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_LEAST_COMMON_MULTIPLE_HPP\n#define ALGORITHM_LEAST_COMMON_MULTIPLE_HPP\
    \ 1\n\n#include <concepts>\n#include <type_traits>\n\n#include \"../../utils/absolute.hpp\"\
    \n#include \"greatest_common_divisor.hpp\"\n\nnamespace algorithm {\n\nnamespace\
    \ internal {\n\ntemplate <std::integral Type>\nconstexpr Type lcm(Type a, Type\
    \ b) {\n    if(a == 0 or b == 0) return 0;\n    return a / internal::gcd(a, b)\
    \ * b;\n}\n\n}  // namespace internal\n\n// Returns the least common multiple\
    \ (LCM) of |a| and |b|.\ntemplate <std::integral T, std::integral U>\nconstexpr\
    \ auto lcm(T a, U b) {\n    using ct = std::common_type_t<T, U>;\n    using ut\
    \ = std::make_unsigned_t<ct>;\n    ut ua = internal::abs<ut>(a);\n    ut ub =\
    \ internal::abs<ut>(b);\n    return static_cast<ct>(internal::lcm(ua, ub));\n\
    }\n\n// Returns the least common multiple (LCM) of all arguments.\ntemplate <std::integral\
    \ Type, std::integral... Args>\nconstexpr auto lcm(Type first, Args... args) {\
    \ return lcm(first, lcm(args...)); }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - algorithm/utils/absolute.hpp
  - algorithm/Math/NumberTheory/greatest_common_divisor.hpp
  isVerificationFile: false
  path: algorithm/Math/NumberTheory/least_common_multiple.hpp
  requiredBy: []
  timestamp: '2026-02-27 12:03:57+00:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/aoj/NTL_1_C.test.cpp
documentation_of: algorithm/Math/NumberTheory/least_common_multiple.hpp
layout: document
title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
---


## 概要

2つの自然数 $a, b$ の最小公倍数 (LCM: Least Common Multiple) を求める．

次の等式が成り立つため，$a$ と $b$ の最大公約数が分かればよい．

$$
\operatorname{lcm}(a, b) \cdot \gcd(a, b) = ab \quad
\Longleftrightarrow \quad \operatorname{lcm}(a, b) = \frac{ab}{\gcd(a, b)}.
$$

アルゴリズムの計算量は，最大公約数を求めるところがボトルネックとなり，$\mathcal{O}(\log(\min(a,b)))$ となる．

## Interface

| 関数                                                                                                     | 説明                                           | 計算量                         |
| -------------------------------------------------------------------------------------------------------- | ---------------------------------------------- | ------------------------------ |
| `template <std::integral T, std::integral U>`<br>`constexpr auto lcm(T a, U b)`                          | $\|a\|, \|b\|$ の最小公倍数を求める．          | $\mathcal{O}(\log(\min(a,b)))$ |
| `template <std::integral Type, std::integral... Args>`<br>`constexpr auto lcm(Type first, Args... args)` | 複数の整数の絶対値に対する最小公倍数を求める． | -                              |

## 参考

1. "最小公倍数". Wikipedia. <https://ja.wikipedia.org/wiki/最小公倍数>.
