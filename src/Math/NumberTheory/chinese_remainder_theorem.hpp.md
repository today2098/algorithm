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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/Math/NumberTheory/chinese_remainder_theorem.hpp: line 12: unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\n"
  code: "/**\n * @brief Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\uFF09\n * @docs docs/Math/NumberTheory/chinese_remainder_theorem.md\n */\n\
    \n#ifndef ALGORITHM_CHINESE_REMAINDER_THEOREM_HPP\n#define ALGORITHM_CHINESE_REMAINDER_THEOREM_HPP\
    \ 1\n\n#include <cassert>\n#include <vector>\n\n#include \"extgcd.hpp\"\n\nnamespace\
    \ algorithm {\n\n// Chinese Remainder Theorem\uFF08\u4E2D\u56FD\u5270\u4F59\u5B9A\
    \u7406\uFF09.\n// x\u2261b1 (mod m1) \u304B\u3064 x\u2261b2 (mod m2) \u3092\u6E80\
    \u305F\u3059\u6574\u6570x (0\u2266x\uFF1Clcm(m1,m2))\u3092\u6C42\u3081\u308B\uFF0E\
    \n// x\u304C\u5B58\u5728\u3059\u308B\u5FC5\u8981\u5341\u5206\u6761\u4EF6\u306F\
    \ b1\u2261b2 (mod gcd(m1,m2)) \u3067\u3042\u308B\u3053\u3068\uFF0E\n// \u8FD4\u308A\
    \u5024\u306Fpair of (x,lcm(m1,m2))\uFF0E\u89E3\u306A\u3057\u306E\u5834\u5408\uFF0C\
    (0,-1)\u3092\u8FD4\u3059\uFF0E\nstd::pair<long long, long long> crt(long long\
    \ b1, long long m1, long long b2, long long m2) {\n    long long p, q;\n    long\
    \ long d = extgcd(m1, m2, p, q);     // p is inverse of m1/d (mod m2/d).\n   \
    \ if((b2 - b1) % d != 0) return {0, -1};  // \u89E3\u306A\u3057\uFF0E\n    long\
    \ long m = m1 / d * m2;              // lcm(m1,m2).\n    long long tmp = (b2 -\
    \ b1) / d * p % (m2 / d);\n    long long r = (b1 + m1 * tmp) % m;\n    if(r <\
    \ 0) r += m;\n    return {r, m};\n}\n\n// Chinese Remainder Theorem\uFF08\u4E2D\
    \u56FD\u5270\u4F59\u5B9A\u7406\uFF09.\n// \u5404i\u306B\u3064\u3044\u3066\uFF0C\
    x\u2261b[i] (mod m[i]) \u3092\u6E80\u305F\u3059\u6574\u6570x (0\u2266x\uFF1Clcm(m[]))\u3092\
    \u6C42\u3081\u308B\uFF0E\n// \u8FD4\u308A\u5024\u306Fpair of (x,lcm(m[]))\uFF0E\
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
  timestamp: '2023-09-15 23:54:13+09:00'
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

整数 $m, n, b, c$ に対して，

$$
\begin{align}
x &\equiv b \pmod m, \notag\\
x &\equiv c \pmod n \notag
\end{align}
$$

を満たす $0$ 以上 $\operatorname{lcm}(m,n)$ 以下の整数 $x$ を求める．

$x$ が存在する必要十分条件は

$$
b \equiv c \pmod{\gcd(m,n)}
$$

であること．

実装では[拡張ユークリッドの互除法](https://today2098.github.io/algorithm/src/Math/NumberTheory/extgcd.hpp)を利用し，計算量は $\mathcal{O}(\log a)$ となる． 


## 参考文献

1. H.H. シルヴァーマン. "第11章 オイラーの$\varphi$関数と中国の剰余定理". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.75-80.
1. "中国の剰余定理". Wikipedia. <https://ja.wikipedia.org/wiki/中国の剰余定理>.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. Sen_comp. "けんちょんさんの中国剰余定理の補足". Hatena Blog. <https://sen-comp.hatenablog.com/entry/2021/03/05/194205>.
