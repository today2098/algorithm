## 概要

区間に対する複数のクエリをまとめて高速に処理するアルゴリズム．
特に，区間 $[l,m)$ と $[m,r)$ の結果をマージして区間 $[l,r)$ の結果を求めることが簡単にできない場合に適している．

Mo's algorithm を適用するためには，次の3つの条件を満たす必要がある．

- クエリを先読みできる（オフラインクエリ）．
- 配列の各要素が不変．
- 区間 $[l,r)$ の結果から区間 $[l-1,r), [l+1,r), [l,r-1), [l,r+1)$ の結果を容易に計算できる（1回の区間伸縮が簡単）． 

アルゴリズムの基本的なアイデアは，クエリを適切な順番に並び替えて，全体での区間の伸縮回数を抑えることにより，計算量を小さくするということである．

アルゴリズムの流れは次の通り．ただし，区間の長さを $N$, クエリの数を $Q$, $i$ 番目のクエリの区間を $[l_i, r_i)$ とおく．

1. 区間を $\sqrt{N}$ 個のブロックに分割する．
1. 各クエリを $l_i$ についてブロックごとに分け，さらにブロック内で $r_i$ についてソートする．
1. 各クエリを並び替えた順に，区間を伸縮させながら処理する．

アルゴリズムの計算量は，区間伸縮1回あたりの計算量を $O(α)$ とすると，クエリの並び替えに $O(Q\log{Q})$, クエリの処理に $O(α(N+Q)\sqrt{N})$ かかり，全体として $O(Q\log{Q} + α(N+Q)\sqrt{N})$ となる．


## 参考文献

1. ageprocpp. "Mo's algorithm(クエリ平方分割)の話". Qiita. <https://qiita.com/ageprocpp/items/34121c58e571ea8c4023>.
1. ei1333. "Mo's algorithm". Hatena Blog. <https://ei1333.hateblo.jp/entry/2017/09/11/211011>.
1. strangerxxx. "Mo's Algorithmのイメージを視覚的に理解したい". Hatena Blog. <https://strangerxxx.hateblo.jp/entry/20230314/1678795200>.
1. "Mo's algorithm". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/range/mo/main.html>.