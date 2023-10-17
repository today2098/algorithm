---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/extgcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-2659.test.cpp
    title: test/aoj-2659.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/chinese_remainder_theorem.md
    document_title: "Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
      \u7406\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/chinese_remainder_theorem.hpp\"\n\n\
    \n\n/**\n * @brief Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\uFF09\n * @docs docs/Math/NumberTheory/chinese_remainder_theorem.md\n */\n\
    \n#include <cassert>\n#include <vector>\n\n#line 1 \"src/Math/NumberTheory/extgcd.hpp\"\
    \n\n\n\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\n * @docs docs/Math/NumberTheory/extgcd.md\n */\n\nnamespace algorithm\
    \ {\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
    \uFF0E\n// ax+by=gcd(a,b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\
    \u6C42\u3081\uFF0Cgcd(a,b)\u3092\u8FD4\u3059\uFF0EO(log(min(a,b))).\ntemplate\
    \ <typename Type>\nType extgcd(Type a, Type b, Type &x, Type &y) {\n    if(b ==\
    \ 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    Type d = extgcd(b,\
    \ a % b, y, x);\n    y -= a / b * x;\n    return d;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 13 \"src/Math/NumberTheory/chinese_remainder_theorem.hpp\"\n\nnamespace\
    \ algorithm {\n\n// Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\uFF09.\n// \u975E\u8CA0\u6574\u6570m1,b1,m2,b2\u306B\u5BFE\u3057\u3066\
    \ x\u2261b1 (mod m1) \u304B\u3064 x\u2261b2 (mod m2) \u3092\u6E80\u305F\u3059\u975E\
    \u8CA0\u6574\u6570x (0\u2266x\uFF1Clcm(m1,m2)) \u3092\u6C42\u3081\u308B\uFF0E\n\
    // \u89E3x\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\
    \ b1\u2261b2 (mod gcd(m1,m2)) \u3067\u3042\u308B\u3053\u3068\uFF0E\n// \u8FD4\u308A\
    \u5024\u306Fpair of (x, lcm(m1,m2))\uFF0E\u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C\
    (0,-1)\u3092\u8FD4\u3059\uFF0E\nstd::pair<long long, long long> crt(long long\
    \ b1, long long m1, long long b2, long long m2) {\n    long long p, q;\n    long\
    \ long d = extgcd(m1, m2, p, q);     // p is inverse of m1/d (mod m2/d).\n   \
    \ if((b2 - b1) % d != 0) return {0, -1};  // \u89E3\u306A\u3057\uFF0E\n    long\
    \ long m = m1 / d * m2;              // lcm(m1,m2).\n    long long tmp = (b2 -\
    \ b1) / d * p % (m2 / d);\n    long long r = (b1 + m1 * tmp) % m;\n    if(r <\
    \ 0) r += m;\n    return {r, m};\n}\n\n// Chinese Remainder Theorem\uFF08\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\uFF09.\n// \u5404i\u306B\u3064\u3044\u3066\uFF0C\
    \u975E\u8CA0\u6574\u6570m[i],b[i]\u306B\u5BFE\u3057\u3066 x\u2261b[i] (mod m[i])\
    \ \u3092\u6E80\u305F\u3059\u975E\u8CA0\u6574\u6570x (0\u2266x\uFF1Clcm(m[0],m[1],...,m[N-1]))\
    \ \u3092\u6C42\u3081\u308B\uFF0E\n// \u8FD4\u308A\u5024\u306Fpair of (x, lcm(m[0],m[1],...,m[N-1]))\uFF0E\
    \u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C(0,-1)\u3092\u8FD4\u3059\uFF0E\ntemplate\
    \ <typename Type>\nstd::pair<long long, long long> crt(const std::vector<Type>\
    \ &bs, const std::vector<Type> &ms) {\n    assert(bs.size() == ms.size());\n \
    \   long long r = 0, m = 1;\n    for(int i = 0, n = bs.size(); i < n; ++i) {\n\
    \        const auto &&[nr, nm] = crt(r, m, bs[i], ms[i]);\n        if(nr == 0\
    \ and nm == -1) return {0, -1};  // \u89E3\u306A\u3057\uFF0E\n        r = nr,\
    \ m = nm;\n    }\n    return {r, m};\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_CHINESE_REMAINDER_THEOREM_HPP\n#define ALGORITHM_CHINESE_REMAINDER_THEOREM_HPP\
    \ 1\n\n/**\n * @brief Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\uFF09\n * @docs docs/Math/NumberTheory/chinese_remainder_theorem.md\n */\n\
    \n#include <cassert>\n#include <vector>\n\n#include \"extgcd.hpp\"\n\nnamespace\
    \ algorithm {\n\n// Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\uFF09.\n// \u975E\u8CA0\u6574\u6570m1,b1,m2,b2\u306B\u5BFE\u3057\u3066\
    \ x\u2261b1 (mod m1) \u304B\u3064 x\u2261b2 (mod m2) \u3092\u6E80\u305F\u3059\u975E\
    \u8CA0\u6574\u6570x (0\u2266x\uFF1Clcm(m1,m2)) \u3092\u6C42\u3081\u308B\uFF0E\n\
    // \u89E3x\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\
    \ b1\u2261b2 (mod gcd(m1,m2)) \u3067\u3042\u308B\u3053\u3068\uFF0E\n// \u8FD4\u308A\
    \u5024\u306Fpair of (x, lcm(m1,m2))\uFF0E\u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C\
    (0,-1)\u3092\u8FD4\u3059\uFF0E\nstd::pair<long long, long long> crt(long long\
    \ b1, long long m1, long long b2, long long m2) {\n    long long p, q;\n    long\
    \ long d = extgcd(m1, m2, p, q);     // p is inverse of m1/d (mod m2/d).\n   \
    \ if((b2 - b1) % d != 0) return {0, -1};  // \u89E3\u306A\u3057\uFF0E\n    long\
    \ long m = m1 / d * m2;              // lcm(m1,m2).\n    long long tmp = (b2 -\
    \ b1) / d * p % (m2 / d);\n    long long r = (b1 + m1 * tmp) % m;\n    if(r <\
    \ 0) r += m;\n    return {r, m};\n}\n\n// Chinese Remainder Theorem\uFF08\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\uFF09.\n// \u5404i\u306B\u3064\u3044\u3066\uFF0C\
    \u975E\u8CA0\u6574\u6570m[i],b[i]\u306B\u5BFE\u3057\u3066 x\u2261b[i] (mod m[i])\
    \ \u3092\u6E80\u305F\u3059\u975E\u8CA0\u6574\u6570x (0\u2266x\uFF1Clcm(m[0],m[1],...,m[N-1]))\
    \ \u3092\u6C42\u3081\u308B\uFF0E\n// \u8FD4\u308A\u5024\u306Fpair of (x, lcm(m[0],m[1],...,m[N-1]))\uFF0E\
    \u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C(0,-1)\u3092\u8FD4\u3059\uFF0E\ntemplate\
    \ <typename Type>\nstd::pair<long long, long long> crt(const std::vector<Type>\
    \ &bs, const std::vector<Type> &ms) {\n    assert(bs.size() == ms.size());\n \
    \   long long r = 0, m = 1;\n    for(int i = 0, n = bs.size(); i < n; ++i) {\n\
    \        const auto &&[nr, nm] = crt(r, m, bs[i], ms[i]);\n        if(nr == 0\
    \ and nm == -1) return {0, -1};  // \u89E3\u306A\u3057\uFF0E\n        r = nr,\
    \ m = nm;\n    }\n    return {r, m};\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - src/Math/NumberTheory/extgcd.hpp
  isVerificationFile: false
  path: src/Math/NumberTheory/chinese_remainder_theorem.hpp
  requiredBy: []
  timestamp: '2023-10-17 16:54:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-2659.test.cpp
documentation_of: src/Math/NumberTheory/chinese_remainder_theorem.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/chinese_remainder_theorem.hpp
- /library/src/Math/NumberTheory/chinese_remainder_theorem.hpp.html
title: "Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\uFF09"
---
## 概要

非負整数 $m_1, m_2, b_1, b_2$ に対して，

$$
\begin{align}
x &\equiv b_1 \pmod{m_1}, \notag\\
x &\equiv b_2 \pmod{m_2} \notag
\end{align}
$$

を満たす非負整数 $x \ (0 \leq x < \operatorname{lcm}(m_1,m_2))$ を求める．

解 $x$ が存在する必要十分条件は

$$
b_1 \equiv b_2 \pmod{\gcd(m_1,m_2)}
$$

であること．
またこのときに限り，解 $x$ が $0$ 以上 $\operatorname{lcm}(m_1,m_2)$ 未満の範囲にただ1つ存在し，それを $r$ とすると

$$
x \equiv r \pmod{\operatorname{lcm}(m_1,m_2)}
$$

が成り立つ．

実装では[拡張ユークリッドの互除法](https://today2098.github.io/algorithm/src/Math/NumberTheory/extgcd.hpp)を利用し，計算量は $\mathcal{O}(\log(\min(m_1,m_2)))$ となる．


## 参考文献

1. H.H. シルヴァーマン. "第11章 オイラーの$\varphi$関数と中国の剰余定理". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.75-80.
1. "中国の剰余定理". Wikipedia. <https://ja.wikipedia.org/wiki/中国の剰余定理>.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. Sen_comp. "けんちょんさんの中国剰余定理の補足". Hatena Blog. <https://sen-comp.hatenablog.com/entry/2021/03/05/194205>.
