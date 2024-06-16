## 概要

通常の Segment Tree に対し，扱う配列の長さ $N$ の制約が大きい場合に適する．
特に「クエリを先読みし，座標圧縮する」ということができないオンラインクエリの場合に用いられる．

本ライブラリの実装では [Segment Tree](https://today2098.github.io/algorithm/src/DataStructure/SegmentTree/segment_tree.hpp) と同様に抽象化を行っており，オブジェクト定義時にモノイド $(S, \bullet : S \times S \rightarrow S, e \in S)$ を定義する．

制約は，配列のすべての要素が単位元 $e$ で初期化されていること．

各クエリ操作の計算量は次の通りとなる．

|クエリ操作|計算量|
|---|---|
|一点更新|$\mathcal{O}(\log N)$|
|一点取得|$\mathcal{O}(\log N)$|
|区間取得|$\mathcal{O}(\log N)$|
|全区間の取得|$\mathcal{O}(1)$|
|二分探索|$\mathcal{O}(\log N)$|


## 参考文献

1. "Dynamic Segment Tree の ACL 風実装". <https://lorent-kyopro.hatenablog.com/entry/2021/03/12/025644>.
