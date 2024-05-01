## 概要

ある木において，任意の2頂点の最も近い共通の祖先を効率的に求めるアルゴリズム．

計算量は，木のノード数を $\lvert V \rvert$ とすると，前処理が $\mathcal{O}(\lvert V \rvert \log \lvert V \rvert),$ クエリ処理が $\mathcal{O}(\log \lvert V \rvert)$ となる．


## 参考文献

1. "G - Leaf Color 解説". AtCoder. <https://atcoder.jp/contests/abc340/editorial/9249>.
1. yaketake08. "LCAをベースに構築するAuxiliary Treeのメモ". Hatena Blog. <https://smijake3.hatenablog.com/entry/2019/09/15/200200>.
1. "ダブリングによる木の最近共通祖先（LCA：Lowest Common Ancestor）を求めるアルゴリズム". アルゴリズムロジック. <https://algo-logic.info/lca/>.
1. "最小共通祖先". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/graph_theory/lowest_common_ancestor>.


## 例題

1. "G - Leaf Color". AtCoder Beginner Contest 340. AtCoder. <https://atcoder.jp/contests/abc340/tasks/abc340_g>.
