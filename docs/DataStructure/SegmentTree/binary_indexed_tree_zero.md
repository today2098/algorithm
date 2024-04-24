## 概要

1994年に Peter Fenwick により提案された木構造をしたデータ構造．
別名「Fenwick Tree（フェニック木）」．

長さ $N$ の配列 $\lbrace a_0, a_1, \ldots, a_{N-1} \rbrace$ に対して，以下のクエリ処理を $\mathcal{O}(\log N)$ で行う．

- 一点更新 $\operatorname{add}(i,x)$：要素 $a_i$ に $x$ を加算する．
- 区間取得 $\operatorname{sum}(r)$：区間 $[0,r)$ の要素の総和を求める．

任意の区間 $[l,r)$ の要素の総和を取得したい場合は，$\operatorname{sum}(r)-\operatorname{sum}(l)$ と計算すればよい．


## 参考文献

1. "フェニック木". Wikipedia. <https://ja.wikipedia.org/wiki/フェニック木>.
1. "Binary Indexed Tree（Fenwick Tree）". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/binary_indexed_tree>.


## 例題

1. "B - Fenwick Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_b>.
