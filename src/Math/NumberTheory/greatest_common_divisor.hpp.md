---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Math/NumberTheory/least_common_multiple.hpp
    title: "Least Common Multiple\uFF08\u6700\u5C0F\u516C\u500D\u6570\uFF09"
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/greatest_common_divisor.md
    document_title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/greatest_common_divisor.hpp\"\n\n\n\
    \n/**\n * @brief Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09\
    \n * @docs docs/Math/NumberTheory/greatest_common_divisor.md\n */\n\nnamespace\
    \ algorithm {\n\n// Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\
    \uFF09. O(log(min(a,b))).\ntemplate <typename Type>\nType igcd(Type a, Type b)\
    \ { return (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GREATEST_COMMON_DIVISOR_HPP\n#define ALGORITHM_GREATEST_COMMON_DIVISOR_HPP\
    \ 1\n\n/**\n * @brief Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\
    \uFF09\n * @docs docs/Math/NumberTheory/greatest_common_divisor.md\n */\n\nnamespace\
    \ algorithm {\n\n// Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\
    \uFF09. O(log(min(a,b))).\ntemplate <typename Type>\nType igcd(Type a, Type b)\
    \ { return (b == 0) ? a : igcd(b, a % b); }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/greatest_common_divisor.hpp
  requiredBy:
  - src/Math/NumberTheory/least_common_multiple.hpp
  timestamp: '2023-10-12 15:22:35+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/greatest_common_divisor.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/greatest_common_divisor.hpp
- /library/src/Math/NumberTheory/greatest_common_divisor.hpp.html
title: "Greatest Common Divisor\uFF08\u6700\u5927\u516C\u7D04\u6570\uFF09"
---
## 概要

2つの整数 $a, b$ の最大公約数 (GCD: Greatest Common Divisor) を求める．

実装ではユークリッドの互除法を用いており，計算量は $\mathcal{O}(\log(\min(a,b)))$ となる． 


## 参考文献

1. H.H. シルヴァーマン. "第5章 割り切れる関係 —— 整除性と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.29-33.
1. "最大公約数". Wikipedia. <https://ja.wikipedia.org/wiki/最大公約数>.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. "ユークリッドの互除法の証明と不定方程式". 高校数学の美しい物語. <https://manabitimes.jp/math/672>.
