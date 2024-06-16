---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo-sum_of_floor_of_linear.test.cpp
    title: test/yosupo-sum_of_floor_of_linear.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Math/NumberTheory/floor_sum.md
    document_title: Floor Sum
    links: []
  bundledCode: "#line 1 \"src/Math/NumberTheory/floor_sum.hpp\"\n\n\n\n/**\n * @brief\
    \ Floor Sum\n * @docs docs/Math/NumberTheory/floor_sum.md\n */\n\n#include <cassert>\n\
    \nnamespace algorithm {\n\n// sum_{x=0}^{n-1} floor((a*x+b)/m) \u3092\u6C42\u3081\
    \u308B\uFF0EO(log m).\nlong long floor_sum(long long n, long long m, long long\
    \ a, long long b) {\n    assert(0 <= n and n < 1LL << 32);\n    assert(1 <= m\
    \ and m < 1LL << 32);\n    long long res = 0;\n    if(a >= m) {\n        res +=\
    \ a / m * (n * (n - 1) / 2);\n        a %= m;\n    } else if(a < 0) {\n      \
    \  long long na = (a % m + m) % m;\n        res -= (na - a) / m * (n * (n - 1)\
    \ / 2);\n        a = na;\n    }\n    if(b >= m) {\n        res += b / m * n;\n\
    \        b %= m;\n    } else if(b < 0) {\n        long long nb = (b % m + m) %\
    \ m;\n        res -= (nb - b) / m * n;\n        b = nb;\n    }\n    long long\
    \ y_max = a * n + b;\n    if(y_max >= m) res += floor_sum(y_max / m, a, m, y_max\
    \ % m);\n    return res;\n}\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_FLOOR_SUM_HPP\n#define ALGORITHM_FLOOR_SUM_HPP 1\n\n/**\n\
    \ * @brief Floor Sum\n * @docs docs/Math/NumberTheory/floor_sum.md\n */\n\n#include\
    \ <cassert>\n\nnamespace algorithm {\n\n// sum_{x=0}^{n-1} floor((a*x+b)/m) \u3092\
    \u6C42\u3081\u308B\uFF0EO(log m).\nlong long floor_sum(long long n, long long\
    \ m, long long a, long long b) {\n    assert(0 <= n and n < 1LL << 32);\n    assert(1\
    \ <= m and m < 1LL << 32);\n    long long res = 0;\n    if(a >= m) {\n       \
    \ res += a / m * (n * (n - 1) / 2);\n        a %= m;\n    } else if(a < 0) {\n\
    \        long long na = (a % m + m) % m;\n        res -= (na - a) / m * (n * (n\
    \ - 1) / 2);\n        a = na;\n    }\n    if(b >= m) {\n        res += b / m *\
    \ n;\n        b %= m;\n    } else if(b < 0) {\n        long long nb = (b % m +\
    \ m) % m;\n        res -= (nb - b) / m * n;\n        b = nb;\n    }\n    long\
    \ long y_max = a * n + b;\n    if(y_max >= m) res += floor_sum(y_max / m, a, m,\
    \ y_max % m);\n    return res;\n}\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Math/NumberTheory/floor_sum.hpp
  requiredBy: []
  timestamp: '2023-09-25 15:34:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo-sum_of_floor_of_linear.test.cpp
documentation_of: src/Math/NumberTheory/floor_sum.hpp
layout: document
redirect_from:
- /library/src/Math/NumberTheory/floor_sum.hpp
- /library/src/Math/NumberTheory/floor_sum.hpp.html
title: Floor Sum
---
## 概要

整数 $n, m, a, b$ に対して，

$$
\operatorname{floor\_sum}(n,m,a,b) = \sum_{i=0}^{n-1}{\left\lfloor \frac{a \times i + b}{m} \right\rfloor}
$$

を $\mathcal{O}(\log \min(m,a))$ で求める（ただし，$n \geq 0, m \geq 1$）．

本アルゴリズムでは主客転倒のテクニックを用いる．

まず $a \geq m, b \geq m$ のとき，$a = q_a m + r_a, b = q_b m + r_b \ (0 \leq r < m)$ と表すと

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{i=0}^{n-1}{\left\lfloor \frac{a \times i + b}{m} \right\rfloor} \notag\\
    &= \sum_{i=0}^{n-1}(q_a \cdot i + q_b) + \sum_{i=0}^{n-1}{\left\lfloor \frac{r_a \times i + r_b}{m} \right\rfloor} \notag\\
    &= q_a \cdot \frac{n(n-1)}{2} + q_b \cdot n + \operatorname{floor\_sum}(n,m,r_a,r_b) \notag\\
\end{align}
$$

となり，$0 \leq a < m, 0 \leq b < m$ の場合に帰着できる．
$a < 0, b < 0$ のときも同様．

以下 $0 \leq a < m, 0 \leq b < m$ とする．

$y_{max} = \left\lfloor (a n + b)/m \right\rfloor$ とすると

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{i=0}^{n-1}{\left\lfloor \frac{a \times i + b}{m} \right\rfloor} \notag\\
    &= \sum_{j=1}^{y_{max}}{\sum_{\substack{0 \leq i < n \\ \left\lfloor (a i + b)/m \right\rfloor = j}}{j}} \notag\\
\end{align}
$$

ここで $k_l$ を $\left\lfloor (a k_l + b)/m \right\rfloor = l$ となる最小の自然数とおくと，$\left\lfloor (a i + b)/m \right\rfloor = l$ を満たす $i$ は $(k_{l+1} - k_l)$ 個となるので，

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{j=1}^{y_{max}}{\sum_{\substack{0 \leq i < n \\ \left\lfloor (a i + b)/m \right\rfloor = j}}{j}} \notag\\
    &= \sum_{j=1}^{y_{max}-1}{j \cdot (k_{j+1} - k_j)} + y_{max} \cdot (n - k_{y_{max}}) \notag\\
    &= \sum_{j=1}^{y_{max}-1}{j \cdot k_{j+1}} - \sum_{j=1}^{y_{max}-1}{j \cdot k_j} + y_{max} \cdot n - y_{max} \cdot k_{y_{max}} \notag\\
    &= \sum_{j=2}^{y_{max}}{(j - 1) \cdot k_j} - \sum_{j=1}^{y_{max}-1}{j \cdot k_j} + y_{max} \cdot n - y_{max} \cdot k_{y_{max}} \notag\\
    &= \sum_{j=2}^{y_{max}}{(j - 1) \cdot k_j} - \sum_{j=1}^{y_{max}}{j \cdot k_j} + y_{max} \cdot n \notag\\
    &= \sum_{j=2}^{y_{max}}{(j - 1) \cdot k_j} - \sum_{j=2}^{y_{max}}{j \cdot k_j} - 1 \cdot k_1 + y_{max} \cdot n \notag\\
    &= - \sum_{j=2}^{y_{max}}{k_j} - 1 \cdot k_1 + y_{max} \cdot n \notag\\
    &= - \sum_{j=1}^{y_{max}}{k_j} + y_{max} \cdot n \notag\\
    &= - \sum_{j=1}^{y_{max}}{\left( k_j - n \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left( n - k_j \right)} \notag\\
\end{align}
$$

$k_l$ は $\left\lfloor (a k_l + b)/m \right\rfloor = l$ より

$$
\begin{align}
& \ \frac{a \cdot k_l + b}{m} \geq l \notag\\
\Leftrightarrow& \ k_l \geq \frac{m \cdot l - b}{a} \notag\\
\end{align}
$$

であり，またこれを満たす最小の自然数なので $k_l = \left\lceil (m l - b) / a \right\rceil$ となる．

よって，

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{j=1}^{y_{max}}{\left( n - k_j \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left( n - \left\lceil \frac{m \cdot j - b}{a} \right\rceil \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left( n + \left\lfloor \frac{-m \cdot j + b}{a} \right\rfloor \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left\lfloor n + \frac{-m \cdot j + b}{a} \right\rfloor} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left\lfloor n - \frac{m \cdot j - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor n - \frac{m \cdot (y_{max} - j) - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor n - \frac{m \cdot (\left\lfloor \frac{a \cdot n + b}{m} \right\rfloor - j) - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor n - \frac{(a \cdot n + b) - (a \cdot n + b) \% m - m \cdot j - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor \frac{m \times j + (a \cdot n + b) \% m}{a} \right\rfloor} \notag\\
    &= \operatorname{floor\_sum}(y_{max},a,m,(a \cdot n + b) \% m) \notag\\
\end{align}
$$

となり，再帰的に計算できる．
またこの再帰は，$m$ と $a$ について互除法を行うようになるため，必ず停止することが分かる．

計算量は互除法と同じなので，$\mathcal{O}(\log \min(m,a))$ となる．


## 参考文献

1. HNJ. "Floor Sum (ACL Practice Contest C)". Qiita. <https://qiita.com/HNJ/items/564f15316719209df73c>.
1. rsk0315. "sum of floor of liner の解説をするよ". Hatena Blog. <https://rsk0315.hatenablog.com/entry/2020/12/13/231307>.
1. yosupo. "C - Floor Sum 解説". AtCoder. <https://atcoder.jp/contests/practice2/editorial/579>.
1. kyopro_friends. X (Twitter). <https://twitter.com/kyopro_friends/status/1304063876019793921>.


## 問題

- "C - Floor Sum". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_c>.