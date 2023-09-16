## 概要

部分永続 Union-Find は，通常の [Union-Find](https://today2098.github.io/algorithm/src/DataStructure/UnionFind/union_find.hpp) の機能に加え，過去の状態におけるクエリを求めることができるデータ構造．

実装では「union by size」の工夫のみ行い，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考文献

1. "やぶについて書きます". <https://camypaper.bitbucket.io/2016/12/18/adc2016/>.


## 問題

- "H - Union Sets". CODE THANKS FESTIVAL 2017(Parallel). AtCoder. <https://atcoder.jp/contests/code-thanks-festival-2017-open/tasks/code_thanks_festival_2017_h>.
