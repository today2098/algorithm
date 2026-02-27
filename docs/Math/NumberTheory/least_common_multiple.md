---
title: Least Common Multiple（最小公倍数）
documentation_of: //algorithm/Math/NumberTheory/least_common_multiple.hpp
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
