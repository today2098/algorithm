---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/extgcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/Math/ModularArithmetic/linear_congruence.md
    document_title: "\u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m)"
    links: []
  bundledCode: "#line 1 \"src/Math/ModularArithmetic/linear_congruence.hpp\"\n\n\n\
    \n/**\n * @brief \u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m)\n * @docs docs/Math/ModularArithmetic/linear_congruence.md\n\
    \ */\n\n#include <cassert>\n#include <vector>\n\n#line 1 \"src/Math/NumberTheory/extgcd.hpp\"\
    \n\n\n\n/**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\
    \u9664\u6CD5\n * @docs docs/Math/NumberTheory/extgcd.md\n */\n\nnamespace algorithm\
    \ {\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
    \uFF0E\n// ax+by=gcd(a,b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\
    \u6C42\u3081\uFF0Cgcd(a,b)\u3092\u8FD4\u3059\uFF0EO(log(min(a,b))).\ntemplate\
    \ <typename Type>\nType extgcd(Type a, Type b, Type &x, Type &y) {\n    if(b ==\
    \ 0) {\n        x = 1, y = 0;\n        return a;\n    }\n    Type d = extgcd(b,\
    \ a % b, y, x);\n    y -= a / b * x;\n    return d;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 13 \"src/Math/ModularArithmetic/linear_congruence.hpp\"\n\nnamespace\
    \ algorithm {\n\n// \u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m) \u306E\u89E3\
    \u3092\u3059\u3079\u3066\u6C42\u3081\u308B\uFF0E\nstd::vector<int> linear_congruence(long\
    \ long a, long long c, int m) {\n    assert(m >= 1);\n    int u, v;\n    int g\
    \ = extgcd<int>(a % m, m, u, v);       // g is gcd(a,m).\n    if(c % g != 0) return\
    \ std::vector<int>();  // \u89E3\u306A\u3057\uFF0E\n    std::vector<int> res(g);\n\
    \    if(u < 0) u += m;  // 0\u2266u<m.\n    res[0] = c / g % m * u % m;\n    int\
    \ dm = m / g;\n    for(int i = 1; i < g; ++i) {\n        long long tmp = (long\
    \ long)res[i - 1] + dm;\n        if(tmp >= m) tmp -= m;\n        res[i] = tmp;\n\
    \    }\n    return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_LINEAR_CONGRUENCE_HPP\n#define ALGORITHM_LINEAR_CONGRUENCE_HPP\
    \ 1\n\n/**\n * @brief \u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m)\n * @docs\
    \ docs/Math/ModularArithmetic/linear_congruence.md\n */\n\n#include <cassert>\n\
    #include <vector>\n\n#include \"../NumberTheory/extgcd.hpp\"\n\nnamespace algorithm\
    \ {\n\n// \u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m) \u306E\u89E3\u3092\u3059\
    \u3079\u3066\u6C42\u3081\u308B\uFF0E\nstd::vector<int> linear_congruence(long\
    \ long a, long long c, int m) {\n    assert(m >= 1);\n    int u, v;\n    int g\
    \ = extgcd<int>(a % m, m, u, v);       // g is gcd(a,m).\n    if(c % g != 0) return\
    \ std::vector<int>();  // \u89E3\u306A\u3057\uFF0E\n    std::vector<int> res(g);\n\
    \    if(u < 0) u += m;  // 0\u2266u<m.\n    res[0] = c / g % m * u % m;\n    int\
    \ dm = m / g;\n    for(int i = 1; i < g; ++i) {\n        long long tmp = (long\
    \ long)res[i - 1] + dm;\n        if(tmp >= m) tmp -= m;\n        res[i] = tmp;\n\
    \    }\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn:
  - src/Math/NumberTheory/extgcd.hpp
  isVerificationFile: false
  path: src/Math/ModularArithmetic/linear_congruence.hpp
  requiredBy: []
  timestamp: '2023-10-15 15:54:15+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Math/ModularArithmetic/linear_congruence.hpp
layout: document
redirect_from:
- /library/src/Math/ModularArithmetic/linear_congruence.hpp
- /library/src/Math/ModularArithmetic/linear_congruence.hpp.html
title: "\u4E00\u6B21\u5408\u540C\u5F0F ax\u2261c (mod m)"
---
## 概要

一次合同式 $ax \equiv c \pmod m$ の解をすべて求める．
解が存在する必要十分条件は，$\gcd(a,m) \mid c$ であること．


### アルゴリズムの説明

整数 $x$ で $ax - c$ が $m$ で割り切れるようなものを探す．
言い換えると，$ax - c = my$ である整数 $y$ を見つけられれば良い．
つまり，解 $x$ が存在する必要十分条件は，一次方程式 $ax - my = c$ が解をもつことだとわかる．

拡張ユークリッドの互除法により，一次方程式 $ax - my = c$ を解く．

まず，$g = \gcd(a,m)$ とおくと $ax - my$ の形をした数は $g$ の倍数であるので，$c$ が $g$ で割り切れなければ $ax - my = c$ は解をもたず，$ax \equiv c \pmod m$ も解をもたない．
以降，$g$ が $c$ を割り切るものとする．

拡張ユークリッドの互除法から，方程式 $au + mv = g$ はいつでもある整数解 $(u_0,v_0)$ をもつ．
そのとき，方程式の両辺に $c/g$ をかけると

$$
a \frac{c u_0}{g} + m \frac{c v_0}{g} = c
$$

となる．
これより

$$
a \frac{c u_0}{g} \equiv c \pmod m
$$

であるから，$c u_0 / g \bmod m$ が合同式 $ax \equiv c \pmod m$ の解となる．
これを $x_0$ とおく．

次に $x_1$ を別の解とする．
このとき $a x_0 \equiv a x_1 \pmod m$ であるので，$m$ は $a x_1 - a x_0$ を割り切る．
つまり $m/g$ は $a (x_1 - x_0) / g$ を割り切る．
ここで $m/g$ と $a/g$ は共通因子をもたないので，$m/g$ は $x_1 - x_0$ を割り切れる必要がある．

つまり，適当な整数 $k$ を用いて

$$
x_1 = x_0 + k \cdot \frac{m}{g}
$$

と表せる．
$m$ を法とするとき $m$ の倍数だけ異なるどの2解も同一の解とみなすので，ちょうど $g$ 個の相異なる解を得る．

よって，以下のことがいえる．

- $g \nmid c$ のとき，合同式 $ax \equiv c \pmod m$ は解をもたない．
- $g \mid c$ のとき，合同式 $ax \equiv c \pmod m$ のすべての解は $$\begin{align} &x_0 \equiv \frac{c u_0}{g} \pmod m , \notag\\ &x \equiv x_0 + k \cdot \frac{m}{g} \pmod m \ (k = 0, 1, \ldots, g-1) \notag \end{align} $$ で与えられる．


## 参考文献

1. H.H. シルヴァーマン. "第8章 余りを調べる —— 合同式". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.54-61.
