---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/Math/ModularArithmetic/linear_congruence.hpp
    title: "\u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m)"
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/chinese_remainder_theorem.hpp
    title: "Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\uFF09"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2659.test.cpp
    title: test/aoj-2659.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj-NTL_1_E.test.cpp
    title: test/aoj-NTL_1_E.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/extgcd.md
    document_title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
      \u6CD5"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/extgcd.hpp\"\n\n\n\n/**\n * @brief\
    \ \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n *\
    \ @docs docs/Math/NumberTheory/extgcd.md\n */\n\nnamespace algorithm {\n\n// \u62E1\
    \u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF0E\n// ax+by=gcd(a,b)\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\u6C42\u3081\uFF0C\
    gcd(a,b)\u3092\u8FD4\u3059\uFF0EO(log(min(a,b))).\ntemplate <typename Type>\n\
    Type extgcd(Type a, Type b, Type &x, Type &y) {\n    if(b == 0) {\n        x =\
    \ 1, y = 0;\n        return a;\n    }\n    Type d = extgcd(b, a % b, y, x);\n\
    \    y -= a / b * x;\n    return d;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_EXTGCD_HPP\n#define ALGORITHM_EXTGCD_HPP 1\n\n/**\n * @brief\
    \ \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\n *\
    \ @docs docs/Math/NumberTheory/extgcd.md\n */\n\nnamespace algorithm {\n\n// \u62E1\
    \u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\uFF0E\n// ax+by=gcd(a,b)\
    \ \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\u6C42\u3081\uFF0C\
    gcd(a,b)\u3092\u8FD4\u3059\uFF0EO(log(min(a,b))).\ntemplate <typename Type>\n\
    Type extgcd(Type a, Type b, Type &x, Type &y) {\n    if(b == 0) {\n        x =\
    \ 1, y = 0;\n        return a;\n    }\n    Type d = extgcd(b, a % b, y, x);\n\
    \    y -= a / b * x;\n    return d;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/extgcd.hpp
  requiredBy:
  - src/Math/ModularArithmetic/linear_congruence.hpp
  - src/Math/NumberTheory/chinese_remainder_theorem.hpp
  timestamp: '2023-10-12 14:57:01+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-2659.test.cpp
  - test/aoj-NTL_1_E.test.cpp
documentation_of: src/Math/NumberTheory/extgcd.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/extgcd.hpp
- /library/src/Math/NumberTheory/extgcd.hpp.html
title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
---
## 概要

2つの整数 $a, b$ に対して，

$$
ax + by = \gcd(a, b)
$$

を満たす整数の組 $(x, y)$ をユークリッドの互除法を応用して求める．
ただし，解が複数存在する場合は $\lvert x \rvert + \lvert y \rvert$ が最小となるものとする．
また，さらに最小のものが複数存在する場合は $x \leq y$ であるものとする．

この解を $(x_1, y_1)$ とすると，他の解は 

$$
\left( x_1 + k \cdot \frac{b}{\gcd(a,b)}, \ y_1 - k \cdot \frac{a}{\gcd(a,b)} \right)
$$

から求められる（ただし，$k$ は整数）．

アルゴリズムの計算量は $\mathcal{O}(\log(\min(a,b)))$ となる．


## 参考文献

1. H.H. シルヴァーマン. "第6章 一次方程式と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.36-43.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. drken. "拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜". Qiita. <https://qiita.com/drken/items/b97ff231e43bce50199a>.
1. "拡張ユークリッドの互除法の解の範囲". HatenaBlog. <https://satashun.hatenablog.com/entry/2019/12/30/231319>.