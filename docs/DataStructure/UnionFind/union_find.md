---
title: Union-Find（素集合データ構造）
documentation_of: //algorithm/DataStructure/UnionFind/union_find.hpp
---


## 概要

「素集合データ構造 (disjoint-set data structure)」とは，互いに素な動的集合の族を管理する．
言い換えると，要素のグループ分けを管理するデータ構造といえる．

そして，素集合データ構造に対する次の操作のアルゴリズムを「Union-Find」という．

- $\operatorname{Union}(x,y)$：2つの要素 $x, y$ がそれぞれ属する集合を1つに合併する
- $\operatorname{Find}(x)$：要素 $x$ が属する集合の代表元を求める

本実装では「素集合森 (disjoint-set forest)」を作成しており，「union by size」と「経路圧縮」の工夫を適用している．

各操作に要する計算量は，アッカーマン関数の逆関数を $\alpha(n)$ とすると，$\mathcal{O}(\alpha(N))$ となる．
アッカーマン関数の逆関数は，増加が非常に遅く，$n \leq 10^{80}$ に対し $\alpha(n) \leq 4$ が成り立つため，実用上 $\mathcal{O}(1)$ とみなすことができる．

## Interface

### algorithm::UnionFind

| コンストラクタ     | 説明                                                                   | 計算量      |
| ------------------ | ---------------------------------------------------------------------- | ----------- |
| `UnionFind()`      | 要素が空の `UnionFind` オブジェクトを構築する．                        | $\Theta(1)$ |
| `UnionFind(int n)` | 互いに独立した `n` 個の要素をもつ `UnionFind` オブジェクトを構築する． | $\Theta(N)$ |

| メンバ関数                   | 説明                                             | 計算量                   |
| ---------------------------- | ------------------------------------------------ | ------------------------ |
| `int vn() const`             | 要素数を取得する．                               | $\Theta(1)$              |
| `int gn() const`             | 集合の数を取得する．                             | $\Theta(1)$              |
| `int root(int x)`            | 要素 `x` が属する集合の代表元を求める．          | $\mathcal{O}(\alpha(N))$ |
| `int size(int x)`            | 要素 `x` が属する集合のサイズを求める．          | $\mathcal{O}(\alpha(N))$ |
| `bool is_same(int x, int y)` | 要素 `x` と `y` が同じ集合に属するかを判定する． | $\mathcal{O}(\alpha(N))$ |
| `bool unite(int x, int y)`   | 要素 `x`, `y` を含むそれぞれの集合を合併する．   | $\mathcal{O}(\alpha(N))$ |
| `void reset()`               | 初期化する．                                     | $\Theta(N)$              |

## 参考

1. Bernard A. Galler and Michael J. Fisher. 1964. An improved equivalence algorithm. Commun. ACM 7, 5 (May 1964), 301–303. <https://doi.org/10.1145/364099.364331>.
1. 大槻兼資著. "第11章 データ構造 (4)：Union-Find". 問題解決力を鍛える！ アルゴリズムとデータ構造. 秋葉拓哉監修. 講談社, 2020, pp.181-190.
1. "19 互いに素な集合族のためのデータ構造". アルゴリズムイントロダクション 第4版 総合版. 近代科学社, 2024, pp.439-460.
1. "素集合データ構造". Wikipedia. <https://ja.wikipedia.org/wiki/素集合データ構造>.
1. "ロバート・タージャン". Wikipedia. <https://ja.wikipedia.org/wiki/ロバート・タージャン>.
1. "観測可能な宇宙". Wikipedia. <https://ja.wikipedia.org/wiki/観測可能な宇宙>.
1. kopricky. "Union Find の計算量の話". Qiita. <https://qiita.com/kopricky/items/3e5847ab1451fe990367>.
1. rsk0315. "α(n) とお近づきになりたい人のための記事". HatenaBlog. <https://rsk0315.hatenablog.com/entry/2020/11/14/170423>.
1. "巨大数：アッカーマン関数とは". 高校数学の美しい物語. <https://manabitimes.jp/math/1010>.

## 関連問題

- "B - Union Find". AtCoder Typical Contest 001. AtCoder. <https://atcoder.jp/contests/atc001/tasks/unionfind_a>.
