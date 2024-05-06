##  概要

通常の Segment Tree が処理するクエリは「一点更新・区間取得」であるのに対し，Lazy Segment Tree（遅延評価セグメント木）は「**区間更新**・区間取得」のクエリを処理する．

具体的には，長さ $N$ の配列 $\lbrace a_0, a_1, \ldots, a_{n-1} \rbrace$ に対して，次のクエリを $\mathcal{O}(\log N)$ で行う．

- 区間更新：区間 $[l, r)$ の要素 $a_l, a_{l+1}, \ldots, a_{r-1}$ を作用素 $f$ を用いて更新する．
- 区間取得：区間 $[l, r)$ の要素の総積 $a_l \bullet a_{l+1} \bullet \cdots \bullet a_{r-1}$ を取得する．

本ライブラリの実装では [Segment Tree](https://today2098.github.io/algorithm/src/DataStructure/SegmentTree/segment_tree.hpp) と同様に抽象化を行っており，オブジェクト定義時にモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ と，以下の条件を満たす $S$ から $S$ への写像の集合 $F$ を定義する．

- $F$ は，$\forall x \in S$ に対して $\operatorname{id}(x)=x$ となる恒等写像 $\operatorname{id}$ を含む．
- $\forall f, \forall g \in F$ に対して $f \circ g \in F$ である（$F$ は写像の合成について閉じている）．
- $\forall f \in F, \forall x, \forall y \in S$ に対して $f(x \bullet y) = f(x) \bullet f(y)$ である． 


## 参考文献

1. "Lazy Segtree". AC Library. AtCoder. <https://atcoder.github.io/ac-library/production/document_ja/lazysegtree.html>.
1. "作用素". Wikipedia. <https://ja.wikipedia.org/wiki/作用素>.
1. betrue12. "Atcoder LibraryのLazy Segtreeの使い方". Hatena Blog. <https://betrue12.hateblo.jp/entry/2020/09/22/194541>.
1. "遅延評価セグメント木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/segment_tree/lazy_segment_tree>.


## 問題

- "K - Range Affine Range Sum". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_k>.
- "L - Lazy Segment Tree". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_l>.
