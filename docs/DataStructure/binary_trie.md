## 概要

非負整数値を要素とする多重集合．

データ構造は $0$ と $1$ をキーとする Trie 木であり，次のクエリ処理を $\mathcal{O}(B)$ で行う（ただし，$B$ は扱う非負整数値の最大ビット長）．

- 多重集合 $S$ に非負整数 $x$ を $c$ 個挿入する．
- 多重集合 $S$ から非負整数 $x$ を $c$ 個削除する．
- 多重集合 $S$ に含まれる非負整数 $x$ の個数を求める．
- 多重集合 $S$ 内で $k$ 番目に小さい要素値を取得する．

また，本データ構造のキモでもあるが，多重集合内の全ての要素値に対し，任意の値で排他的論理和の操作を行うこともできる．
このときの計算量も $\mathcal{O}(B)$（実用上は $\mathcal{O}(1)$ ）となる．

- 多重集合 $S$ に含まれる全ての要素値に対して，非負整数 $x$ で排他的論理和の操作を行う．


## 例題

1. "C - データ構造". AtCoder Regular Contest 033. AtCoder. <https://atcoder.jp/contests/arc033/tasks/arc033_3>.


## 参考文献

1. "トライ (データ構造)". Wikipedia. <https://ja.wikipedia.org/wiki/トライ_(データ構造)>.
1. kazuma8128. "非負整数値を扱う Trie について". Hatena Blog. <https://kazuma8128.hatenablog.com/entry/2018/05/06/022654>.
1. "Trie木 (Binary Trie)". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/trie>.
