---
title: 約数列挙
documentation_of: //algorithm/Math/NumberTheory/divisors.hpp
---


## 概要

与えられる自然数 $n$ の約数を列挙する．

本ライブラリでは「試し割り法 (trial division)」を用いて実装しており，計算量は $\mathcal{O}(\sqrt n)$ となる．

## Interface

| 関数                                                                              | 説明                   | 制約    | 計算量                 |
| --------------------------------------------------------------------------------- | ---------------------- | ------- | ---------------------- |
| `template <std::integral Type>`<br>`constexpr std::vector<Type> divisors(Type n)` | $n$ の約数を列挙する． | $n > 0$ | $\mathcal{O}(\sqrt n)$ |

## 参考

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
