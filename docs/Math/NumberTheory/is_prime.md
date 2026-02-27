---
title: 素数判定
documentation_of: //algorithm/Math/NumberTheory/is_prime.hpp
---


## 概要

与えられる自然数 $n$ が素数かどうか判定する．

本ライブラリでは「試し割り法 (trial division)」を用いて実装しており，計算量は $\mathcal{O}(\sqrt n)$ となる．

## Interface

| 関数                                                                                                                                                           | 説明                   | 制約      | 計算量                 |
| -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------------- | --------- | ---------------------- |
| `template <std::unsigned_integral Type>`<br>`constexpr bool is_prime(Type n)` /<br>`template <std::signed_integral Type>`<br>`constexpr bool is_prime(Type n)` | $n$ が素数か判定する． | $n \ge 0$ | $\mathcal{O}(\sqrt n)$ |

## 参考

1. "試し割り法". Wikipedia. <https://ja.wikipedia.org/wiki/試し割り法>.
