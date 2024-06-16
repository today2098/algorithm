## 概要

二分木を用いたヒープ．
基本的な機能は `std::priority_queue` と同じ．

実装では二分木を用いて要素を管理しており，親の要素は子の要素より常に大きい（小さい）か等しくなるようにしている．

各クエリ操作の計算量は次の通り． 

|操作|計算量|
|---|---|
|最大値（最小値）の取得|$\mathcal{O}(1)$|
|要素数の取得|$\mathcal{O}(1)$|
|要素の追加|$\mathcal{O}(\log N)$|
|要素の削除|$\mathcal{O}(\log N)$|


## 参考文献

1. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
1. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
