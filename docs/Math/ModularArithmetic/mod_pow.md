---
title: 繰り返し二乗法（mod付き）
documentation_of: //algorithm/Math/ModularArithmetic/mod_pow.hpp
---


## 概要

$n, k \in \mathbb{Z}, m \in \mathbb{N}$ について，$n^k \bmod m$ を求める．

本ライブラリでは「繰り返し二乗法」を用いて実装しており，計算量は $\mathcal{O}(\log k)$ である．

## Interface

| 関数                                                                                                     | 説明                    | 制約      | 計算量                |
| -------------------------------------------------------------------------------------------------------- | ----------------------- | --------- | --------------------- |
| `template <std::integral Type>`<br>`constexpr std::int64_t mod_pow(Type n, long long k, std::int32_t m)` | $n^k \mod m$ を求める． | $m \ge 1$ | $\mathcal{O}(\log k)$ |

## 関連問題

- "B - n^p mod m". AtCoder Typical Contest 002. AtCoder. <https://atcoder.jp/contests/atc002/tasks/atc002_b>.
