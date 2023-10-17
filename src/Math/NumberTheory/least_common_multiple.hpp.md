---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/greatest_common_divisor.hpp
    title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_C.test.cpp
    title: test/aoj-NTL_1_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/least_common_multiple.md
    document_title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/least_common_multiple.hpp\"\n\n\n\n\
    /**\n * @brief Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09\
    \n * @docs docs/Math/NumberTheory/least_common_multiple.md\n */\n\n#line 1 \"\
    src/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n\n\n/**\n * @brief Greatest\
    \ Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09\n * @docs docs/Math/NumberTheory/greatest_common_divisor.md\n\
    \ */\n\nnamespace algorithm {\n\n// Greatest Common Divisor\uFF08\u6700\u5927\u516C\
    \u7D04\u6570\uFF09. O(log(min(a,b))).\ntemplate <typename Type>\nType igcd(Type\
    \ a, Type b) { return (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace algorithm\n\
    \n\n#line 10 \"src/Math/NumberTheory/least_common_multiple.hpp\"\n\nnamespace\
    \ algorithm {\n\n// Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09\
    . O(log(min(a,b))).\ntemplate <typename Type>\nType ilcm(Type a, Type b) { return\
    \ a / igcd(a, b) * b; }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LEAST_COMMON_MULTIPLE_HPP\n#define ALGORITHM_LEAST_COMMON_MULTIPLE_HPP\
    \ 1\n\n/**\n * @brief Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\
    \uFF09\n * @docs docs/Math/NumberTheory/least_common_multiple.md\n */\n\n#include\
    \ \"greatest_common_divisor.hpp\"\n\nnamespace algorithm {\n\n// Least Common\
    \ Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09. O(log(min(a,b))).\ntemplate\
    \ <typename Type>\nType ilcm(Type a, Type b) { return a / igcd(a, b) * b; }\n\n\
    }  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - src/Math/NumberTheory/greatest_common_divisor.hpp
  isVerificationFile: false
  path: src/Math/NumberTheory/least_common_multiple.hpp
  requiredBy: []
  timestamp: '2023-10-12 16:30:38+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-NTL_1_C.test.cpp
documentation_of: src/Math/NumberTheory/least_common_multiple.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/least_common_multiple.hpp
- /library/src/Math/NumberTheory/least_common_multiple.hpp.html
title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
---
## 概要

2つの整数 $a, b$ の最小公倍数 (LCM: Least Common Multiple) を求める．

以下の等式が成り立つため，$a$ と $b$ の最大公約数が分かればよい．

$$
\begin{align}
&\operatorname{lcm}(a,b) \times \gcd(a,b) = a \times b \notag\\
&\Leftrightarrow \operatorname{lcm}(a,b) = \frac{a \times b}{\gcd(a,b)} \notag
\end{align}
$$

アルゴリズムの計算量は，最大公約数を求めるところがネックとなり，$\mathcal{O}(\log(\min(a,b)))$ となる． 


## 参考文献

1. "最小公倍数". Wikipedia. <https://ja.wikipedia.org/wiki/最小公倍数>.
