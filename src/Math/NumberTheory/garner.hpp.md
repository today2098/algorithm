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
    document_title: "Garner's Algorithm\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/garner.hpp\"\n\n\n\n/**\n * @brief\
    \ Garner's Algorithm\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\uFF09\n * @docs\
    \ docs/Math/NumberTheory/garner.md\n */\n\n#include <cassert>\n#include <vector>\n\
    \n#line 1 \"src/Math/ModularArithmetic/mod_inv.hpp\"\n\n\n\n/**\n * @brief \u30E2\
    \u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\u6CD5\u9006\u5143\uFF09\n * @docs docs/Math/ModularArithmetic/mod_inv.md\n\
    \ */\n\n#line 10 \"src/Math/ModularArithmetic/mod_inv.hpp\"\n#include <utility>\n\
    \nnamespace algorithm {\n\n// \u30E2\u30B8\u30E5\u30E9\u9006\u6570\uFF08\u4E57\
    \u6CD5\u9006\u5143\uFF09\uFF0E\n// a^-1 mod m \u3092\u6C42\u3081\u308B\uFF0E\u89E3\
    \u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\uFF0C\
    a\u3068m\u304C\u4E92\u3044\u306B\u7D20\u3067\u3042\u308B\u3053\u3068\uFF0EO(log\
    \ a).\ntemplate <typename Type>\nType mod_inv(long long a, Type m) {\n    assert(m\
    \ > 1);\n    long long b = m, u = 1, v = 0;\n    while(b != 0) {\n        long\
    \ long t = a / b;\n        a -= b * t, u -= v * t;\n        std::swap(a, b), std::swap(u,\
    \ v);\n    }\n    // assert((\"a and m need to be coprime.\", a == 1));\n    if(u\
    \ < 0) u += m;\n    return u;\n}\n\n}  // namespace algorithm\n\n\n#line 13 \"\
    src/Math/NumberTheory/garner.hpp\"\n\nnamespace algorithm {\n\n// \u5404i\u306B\
    \u3064\u3044\u3066 x\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\u6700\u5C0F\
    \u306E\u975E\u8CA0\u6574\u6570x (0\u2266x\uFF1Cm[0]m[1]...m[N-1]) \u3092\u6C42\
    \u3081\u308B\uFF0E\n// \u305F\u3060\u3057\uFF0C\u4EE5\u4E0B\u306E\u5236\u7D04\u3092\
    \u6E80\u305F\u3059\u3053\u3068\uFF0E\n//   - \u4EFB\u610F\u306Ei\u306B\u3064\u3044\
    \u3066\uFF0C0\u2266b[i]<m[i].\n//   - \u4EFB\u610F\u306Ei,j (i\u2260j) \u306B\u3064\
    \u3044\u3066\uFF0Cgcd(m[i],m[j])=1.\nlong long garner(const std::vector<int> &bs,\
    \ const std::vector<int> &ms) {\n    assert(bs.size() == ms.size());\n    long\
    \ long x = 0;\n    long long m_prod = 1;\n    for(int i = 0, n = bs.size(); i\
    \ < n; ++i) {\n        long long t = (bs[i] - x) * mod_inv(m_prod, ms[i]) % ms[i];\n\
    \        if(t < 0) t += ms[i];\n        x += m_prod * t;\n        m_prod *= ms[i];\n\
    \    }\n    return x;\n}\n\n// \u5404i\u306B\u3064\u3044\u3066 x\u2261b[i] (mod\
    \ m[i]) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x (0\u2266\
    x\uFF1Cm[0]m[1]...m[N-1]) \u3092\u6C42\u3081\uFF0C\u3042\u308B\u6574\u6570M\u306B\
    \u5BFE\u3057\u3066 x mod M \u3092\u8FD4\u3059\uFF0E\n// \u305F\u3060\u3057\uFF0C\
    \u4EE5\u4E0B\u306E\u5236\u7D04\u3092\u6E80\u305F\u3059\u3053\u3068\uFF0E\n// \
    \  - \u4EFB\u610F\u306Ei\u306B\u3064\u3044\u3066\uFF0C0\u2266b[i]<m[i].\n//  \
    \ - \u4EFB\u610F\u306Ei,j (i\u2260j) \u306B\u3064\u3044\u3066\uFF0Cgcd(m[i],m[j])=1.\n\
    int garner(const std::vector<int> &bs, const std::vector<int> &ms, int mod) {\n\
    \    assert(bs.size() == ms.size());\n    const int n = bs.size();\n    std::vector<long\
    \ long> coeffs(n, 1);     // coeffs[k]:=m[0]m[1]...m[k-1].\n    std::vector<long\
    \ long> constants(n, 0);  // constants[k]:=t[0]+t[1]m[0]+...+t[k-1]m[0]m[1]...m[k-2].\n\
    \    long long x = 0;\n    long long m_prod = 1;\n    for(int i = 0; i < n; ++i)\
    \ {\n        long long t = (bs[i] - constants[i]) * mod_inv(coeffs[i], ms[i])\
    \ % ms[i];\n        if(t < 0) t += ms[i];\n        for(int j = i + 1; j < n; ++j)\
    \ {\n            constants[j] = (constants[j] + coeffs[j] * t) % ms[j];\n    \
    \        coeffs[j] = coeffs[j] * ms[i] % ms[j];\n        }\n        x = (x + m_prod\
    \ * t) % mod;\n        m_prod = m_prod * ms[i] % mod;\n    }\n    return x;\n\
    }\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_GARNER_HPP\n#define ALGORITHM_GARNER_HPP 1\n\n/**\n * @brief\
    \ Garner's Algorithm\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\uFF09\n * @docs\
    \ docs/Math/NumberTheory/garner.md\n */\n\n#include <cassert>\n#include <vector>\n\
    \n#include \"../ModularArithmetic/mod_inv.hpp\"\n\nnamespace algorithm {\n\n//\
    \ \u5404i\u306B\u3064\u3044\u3066 x\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\
    \u6700\u5C0F\u306E\u975E\u8CA0\u6574\u6570x (0\u2266x\uFF1Cm[0]m[1]...m[N-1])\
    \ \u3092\u6C42\u3081\u308B\uFF0E\n// \u305F\u3060\u3057\uFF0C\u4EE5\u4E0B\u306E\
    \u5236\u7D04\u3092\u6E80\u305F\u3059\u3053\u3068\uFF0E\n//   - \u4EFB\u610F\u306E\
    i\u306B\u3064\u3044\u3066\uFF0C0\u2266b[i]<m[i].\n//   - \u4EFB\u610F\u306Ei,j\
    \ (i\u2260j) \u306B\u3064\u3044\u3066\uFF0Cgcd(m[i],m[j])=1.\nlong long garner(const\
    \ std::vector<int> &bs, const std::vector<int> &ms) {\n    assert(bs.size() ==\
    \ ms.size());\n    long long x = 0;\n    long long m_prod = 1;\n    for(int i\
    \ = 0, n = bs.size(); i < n; ++i) {\n        long long t = (bs[i] - x) * mod_inv(m_prod,\
    \ ms[i]) % ms[i];\n        if(t < 0) t += ms[i];\n        x += m_prod * t;\n \
    \       m_prod *= ms[i];\n    }\n    return x;\n}\n\n// \u5404i\u306B\u3064\u3044\
    \u3066 x\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\u6700\u5C0F\u306E\u975E\
    \u8CA0\u6574\u6570x (0\u2266x\uFF1Cm[0]m[1]...m[N-1]) \u3092\u6C42\u3081\uFF0C\
    \u3042\u308B\u6574\u6570M\u306B\u5BFE\u3057\u3066 x mod M \u3092\u8FD4\u3059\uFF0E\
    \n// \u305F\u3060\u3057\uFF0C\u4EE5\u4E0B\u306E\u5236\u7D04\u3092\u6E80\u305F\u3059\
    \u3053\u3068\uFF0E\n//   - \u4EFB\u610F\u306Ei\u306B\u3064\u3044\u3066\uFF0C0\u2266\
    b[i]<m[i].\n//   - \u4EFB\u610F\u306Ei,j (i\u2260j) \u306B\u3064\u3044\u3066\uFF0C\
    gcd(m[i],m[j])=1.\nint garner(const std::vector<int> &bs, const std::vector<int>\
    \ &ms, int mod) {\n    assert(bs.size() == ms.size());\n    const int n = bs.size();\n\
    \    std::vector<long long> coeffs(n, 1);     // coeffs[k]:=m[0]m[1]...m[k-1].\n\
    \    std::vector<long long> constants(n, 0);  // constants[k]:=t[0]+t[1]m[0]+...+t[k-1]m[0]m[1]...m[k-2].\n\
    \    long long x = 0;\n    long long m_prod = 1;\n    for(int i = 0; i < n; ++i)\
    \ {\n        long long t = (bs[i] - constants[i]) * mod_inv(coeffs[i], ms[i])\
    \ % ms[i];\n        if(t < 0) t += ms[i];\n        for(int j = i + 1; j < n; ++j)\
    \ {\n            constants[j] = (constants[j] + coeffs[j] * t) % ms[j];\n    \
    \        coeffs[j] = coeffs[j] * ms[i] % ms[j];\n        }\n        x = (x + m_prod\
    \ * t) % mod;\n        m_prod = m_prod * ms[i] % mod;\n    }\n    return x;\n\
    }\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - src/Math/ModularArithmetic/mod_inv.hpp
  isVerificationFile: false
  path: src/Math/NumberTheory/garner.hpp
  requiredBy: []
  timestamp: '2023-10-17 16:54:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/NumberTheory/garner.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/garner.hpp
- /library/src/Math/NumberTheory/garner.hpp.html
title: "Garner's Algorithm\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\u7406\uFF09"
---
## 概要

中国剰余定理に関する問題を解くアルゴリズム．
1950年代後半に H. L. Garner によって考案された．

非負整数列 $m_1, m_2, \ldots, m_N$ と $b_1, b_2, \ldots, b_N$ に対して

$$
\begin{align}
&x \equiv b_1 \pmod{m_1}, \notag\\
&x \equiv b_2 \pmod{m_2}, \notag\\
&\ldots, \notag\\
&x \equiv b_N \pmod{m_N} \notag\\
\end{align}
$$

となる最小の非負整数 $x \ (0 \leq x < m_1 m_2 \cdots m_N)$ を求める．
ただし，以下の制約を満たすこと．

- 任意の $i$ について，$0 \leq b_i < m_i$
- 任意の $i, j \ (i \neq j)$ について，$\gcd(m_i, m_j) = 1$

また，解 $x$ の値が大きくなる場合に注意する必要がある．
その際は，任意の整数 $M$ に対して $x \bmod M$ を求めることもできる．


### アルゴリズムの説明

基本的なアイデアは，求める解 $x$ を次のような形で考える．

$$
x = t_1 + t_2 m_1 + t_3 m_1 m_2 + t_4 m_1 m_2 m_3 + \cdots + t_N m_1 m_2 \cdots m_{N-1} \tag{※}
$$

このとき

$$
\begin{align}
&t_1 = b_1 \pmod{m_1} \notag\\
&t_1 + t_2 m_1 = b_2 \pmod{m_2} \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 = b_3 \pmod{m_3} \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 + t_4 m_1 m_2 m_3 = b_4 \pmod{m_4} \notag\\
&\ldots \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 + \cdots + t_N m_1 m_2 \cdots m_{N-1} = b_N \pmod{m_N} \notag
\end{align}
$$

であり，

$$
\begin{align}
&t_1 = b_1 \pmod{m_1} \notag\\
&t_2 = (b_2 - t_1) \cdot m_1^{-1} \pmod{m_2} \notag\\
&t_3 = (b_3 - t_1 - t_2 m_1) \cdot (m_1 m_2)^{-1} \pmod{m_2} \notag\\
&t_4 = (b_4 - t_1 - t_2 m_1 - t_3 m_1 m_2) \cdot (m_1 m_2 m_3)^{-1} \pmod{m_3} \notag\\
&\ldots \notag\\
&t_N = (b_n - t_1 - t_2 m_1 - \cdots - t_{N-1} m_1 m_2 \cdots m_{N-2}) \cdot (m_1 m_2 \cdots m_{N-1})^{-1} \pmod{m_N} \notag
\end{align}
$$

と変形できる．
これらより $t_i$ を順に求めれば，式 (※) に代入することで解 $x$ が求まる．


## 参考文献

1. K.O. Geddes et al. "5.6. The Integer Chinese Remainder Algorithm". Algorithms for Computer Algebra. Kluwer Academic, 1992, p.174-183.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. "拡張互除法と中国剰余定理（Garnerのアルゴリズム）". クリエイティブなブログ. <https://www.creativ.xyz/ect-gcd-crt-garner-927/>.
