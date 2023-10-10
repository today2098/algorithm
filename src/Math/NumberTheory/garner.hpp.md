---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/Math/ModularArithmetic/mod_inv.hpp
    title: "\u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/garner.md
    document_title: Garner's Algorithm
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/garner.hpp\"\n\n\n\n/**\n * @brief\
    \ Garner's Algorithm\n * @docs docs/Math/NumberTheory/garner.md\n */\n\n#include\
    \ <cassert>\n#include <vector>\n\n#line 1 \"src/Math/ModularArithmetic/mod_inv.hpp\"\
    \n/**\n * @brief \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\
    \uFF09\n */\n\n#ifndef ALGORITHM_MOD_INV_HPP\n#define ALGORITHM_MOD_INV_HPP 1\n\
    \n#line 9 \"src/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\nnamespace\
    \ algorithm {\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\
    \u5143\uFF09\uFF0E\n// a^-1 (mod m) \u3092\u6C42\u3081\u308B\uFF0E\u305F\u3060\
    \u3057\uFF0Ca\u3068m\u306F\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\
    \uFF0E\nlong long mod_inv(long long a, int m) {\n    assert(m >= 2);\n    long\
    \ long b = m, u = 1, v = 0;\n    while(b != 0) {\n        long long t = a / b;\n\
    \        a -= b * t, u -= v * t;\n        std::swap(a, b), std::swap(u, v);\n\
    \    }\n    // assert((\"a and m need to be coprime.\", a == 1));\n    u %= m;\n\
    \    if(u < 0) u += m;\n    return u;\n}\n\n}  // namespace algorithm\n\n#endif\n\
    #line 13 \"src/Math/NumberTheory/garner.hpp\"\n\nnamespace algorithm {\n\n// \u5404\
    i\u306B\u3064\u3044\u3066\uFF0Cx\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x (0\u2266x\uFF1Cm[0]m[1]...m[N-1])\
    \ \u3092\u6C42\u3081\u308B\uFF0E\n// \u305F\u3060\u3057\uFF0C\u4EFB\u610F\u306E\
    i,j (i\u2260j) \u306B\u3064\u3044\u3066\uFF0Cgcd(m[i],m[j])=1 \u3067\u3042\u308B\
    \u3053\u3068\uFF0E\ntemplate <typename Type>\nlong long garner(const std::vector<Type>\
    \ &bs, const std::vector<Type> &ms) {\n    assert(bs.size() == ms.size());\n \
    \   long long x = 0;\n    long long m_prod = 1;\n    for(int i = 0, n = bs.size();\
    \ i < n; ++i) {\n        long long t = (bs[i] - x % ms[i]) * mod_inv(m_prod, ms[i])\
    \ % ms[i];\n        if(t < 0) t += ms[i];\n        x += m_prod * t;\n        m_prod\
    \ *= ms[i];\n    }\n    return x;\n}\n\n// \u5404i\u306B\u3064\u3044\u3066\uFF0C\
    x\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\u6574\
    \u6570x (0\u2266x\uFF1Cm[0]m[1]...m[N-1]) \u3092\u6C42\u3081\uFF0Cx%mod \u3092\
    \u8FD4\u3059\uFF0E\n// \u305F\u3060\u3057\uFF0C\u4EFB\u610F\u306Ei,j (i\u2260\
    j) \u306B\u3064\u3044\u3066\uFF0Cgcd(m[i],m[j])=1 \u3067\u3042\u308B\u3053\u3068\
    \uFF0E\ntemplate <typename Type>\nlong long garner(const std::vector<Type> &bs,\
    \ const std::vector<Type> &ms, long long mod) {\n    assert(bs.size() == ms.size());\n\
    \    const int n = bs.size();\n    std::vector<long long> coeffs(n, 1);     //\
    \ coeffs[k]:=m[0]m[1]...m[k-1].\n    std::vector<long long> constants(n, 0); \
    \ // constants[k]:=t[0]+t[1]m[0]+...+t[k-1]m[0]m[1]...m[k-2].\n    long long x\
    \ = 0;\n    long long m_prod = 1;\n    for(int i = 0; i < n; ++i) {\n        long\
    \ long t = (bs[i] - constants[i]) * mod_inv(coeffs[i], ms[i]) % ms[i];\n     \
    \   if(t < 0) t += ms[i];\n        for(int j = i + 1; j < n; ++j) {\n        \
    \    constants[j] = (constants[j] + coeffs[j] * t % ms[j]) % ms[j];\n        \
    \    coeffs[j] = coeffs[j] * ms[i] % ms[j];\n        }\n        x = (x + m_prod\
    \ * t % mod) % mod;\n        m_prod = m_prod * ms[i] % mod;\n    }\n    return\
    \ x;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GARNER_HPP\n#define ALGORITHM_GARNER_HPP 1\n\n/**\n * @brief\
    \ Garner's Algorithm\n * @docs docs/Math/NumberTheory/garner.md\n */\n\n#include\
    \ <cassert>\n#include <vector>\n\n#include \"../ModularArithmetic/mod_inv.hpp\"\
    \n\nnamespace algorithm {\n\n// \u5404i\u306B\u3064\u3044\u3066\uFF0Cx\u2261b[i]\
    \ (mod m[i]) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570\
    x (0\u2266x\uFF1Cm[0]m[1]...m[N-1]) \u3092\u6C42\u3081\u308B\uFF0E\n// \u305F\u3060\
    \u3057\uFF0C\u4EFB\u610F\u306Ei,j (i\u2260j) \u306B\u3064\u3044\u3066\uFF0Cgcd(m[i],m[j])=1\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0E\ntemplate <typename Type>\nlong long garner(const\
    \ std::vector<Type> &bs, const std::vector<Type> &ms) {\n    assert(bs.size()\
    \ == ms.size());\n    long long x = 0;\n    long long m_prod = 1;\n    for(int\
    \ i = 0, n = bs.size(); i < n; ++i) {\n        long long t = (bs[i] - x % ms[i])\
    \ * mod_inv(m_prod, ms[i]) % ms[i];\n        if(t < 0) t += ms[i];\n        x\
    \ += m_prod * t;\n        m_prod *= ms[i];\n    }\n    return x;\n}\n\n// \u5404\
    i\u306B\u3064\u3044\u3066\uFF0Cx\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x (0\u2266x\uFF1Cm[0]m[1]...m[N-1])\
    \ \u3092\u6C42\u3081\uFF0Cx%mod \u3092\u8FD4\u3059\uFF0E\n// \u305F\u3060\u3057\
    \uFF0C\u4EFB\u610F\u306Ei,j (i\u2260j) \u306B\u3064\u3044\u3066\uFF0Cgcd(m[i],m[j])=1\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0E\ntemplate <typename Type>\nlong long garner(const\
    \ std::vector<Type> &bs, const std::vector<Type> &ms, long long mod) {\n    assert(bs.size()\
    \ == ms.size());\n    const int n = bs.size();\n    std::vector<long long> coeffs(n,\
    \ 1);     // coeffs[k]:=m[0]m[1]...m[k-1].\n    std::vector<long long> constants(n,\
    \ 0);  // constants[k]:=t[0]+t[1]m[0]+...+t[k-1]m[0]m[1]...m[k-2].\n    long long\
    \ x = 0;\n    long long m_prod = 1;\n    for(int i = 0; i < n; ++i) {\n      \
    \  long long t = (bs[i] - constants[i]) * mod_inv(coeffs[i], ms[i]) % ms[i];\n\
    \        if(t < 0) t += ms[i];\n        for(int j = i + 1; j < n; ++j) {\n   \
    \         constants[j] = (constants[j] + coeffs[j] * t % ms[j]) % ms[j];\n   \
    \         coeffs[j] = coeffs[j] * ms[i] % ms[j];\n        }\n        x = (x +\
    \ m_prod * t % mod) % mod;\n        m_prod = m_prod * ms[i] % mod;\n    }\n  \
    \  return x;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - src/Math/ModularArithmetic/mod_inv.hpp
  isVerificationFile: false
  path: src/Math/NumberTheory/garner.hpp
  requiredBy: []
  timestamp: '2023-10-10 21:18:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/garner.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/garner.hpp
- /library/src/Math/NumberTheory/garner.hpp.html
title: Garner's Algorithm
---
## 概要

整数列 $m_1, m_2, \ldots, m_N$ と $b_1, b_2, \ldots, b_N$ に対して

$$
\begin{align}
&x \equiv b_1 \pmod{m_1}, \notag\\
&x \equiv b_2 \pmod{m_2}, \notag\\
&\cdots, \notag\\
&x \equiv b_N \pmod{m_N} \notag\\
\end{align}
$$

となる最小の非負整数 $x \ (0 \leq x < m_1 m_2 \cdots m_N)$ を求める．

ただし，以下の制約を満たすこと．
これを満たさない場合は未定義動作となる．

- 任意の $i, j \ (i \neq j)$ について，$\operatorname{lcm}(m_i, m_j) = 1$


### アルゴリズムの説明

基本的なアイデアは求める解 $x$ を次のような形で考える．

$$
x = t_1 + t_2 m_1 + t_3 m_1 m_2 + \cdots + t_N m_1 m_2 \cdots m_{N-1} \tag{※}
$$

このとき

$$
\begin{align}
&t_1 = b_1 \pmod{m_1} \notag\\
&t_1 + t_2 m_1 = b_2 \pmod{m_2} \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 = b_3 \pmod{m_3} \notag\\
&\cdots \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 + \cdots + t_N m_1 m_2 \cdots m_{N-1} = b_N \pmod{m_N} \notag
\end{align}
$$

となる．
ここで $m_i$ を法としたときの $m_j$ の逆元を $m_{j,i}^{-1}$ とすると

$$
\begin{align}
&t_1 = b_1 \pmod{m_1} \notag\\
&t_2 = (b_2 - t_1) m_{1,2}^{-1} \pmod{m_2} \notag\\
&t_3 = (b_3 - t_1 - t_2 m_1) m_{1,3}^{-1} m_{2,3}^{-1} = ((b_3 - t_1) m_{1,3}^{-1} - t_2) m_{2,3}^{-1} \pmod{m_2} \notag\\
&\cdots \notag\\
&t_N = (( \cdots ((b_N - t_1) m_{1,N}^{-1} - t_2) m_{2,N}^{-1} - \cdots ) m_{N-2,N}^{-1} - t_{N-1}) m_{N-1,N}^{-1} \pmod{m_N} \notag
\end{align}
$$

と変形できる．
これらより $t_i$ を順に求めれば，式 (※) に代入することで解 $x$ が求まる．


## 参考文献

1. K.O. Geddes et al. "5.6. The Integer Chinese Remainder Algorithm". Algorithms for Computer Algebra. Kluwer Academic, 1992, p.174-183.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. "拡張互除法と中国剰余定理（Garnerのアルゴリズム）". クリエイティブなブログ. <https://www.creativ.xyz/ect-gcd-crt-garner-927/>.
