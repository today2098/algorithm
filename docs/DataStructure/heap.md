## 概要

二分木を用いたヒープ．
基本的な機能は 'std::priority_queue' と同じ．

要素の最大値（最小値）の取得を $\mathcal{O}(1)$ ，要素の挿入を $\mathcal{O}(\log N)$ ，最大値（最小値）の要素の削除を $\mathcal{O}(\log N)$ で行う． 

実装では二分木を用いて要素を管理しており，親の要素は子の要素より常に大きい（小さい）か等しいようにしている．


## 参考文献

1. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
1. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
