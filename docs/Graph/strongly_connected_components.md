## 概要

与えられる有向連結グラフを強連結成分 (SCC: Strongly Connected Components) に分解する．

ここで強連結成分とは，「ある有向グラフにおいて，互いに行き来できるノードの集合」を指す．

アルゴリズムの計算量は，グラフのノード数を $\lvert V \rvert$ ，辺の数を $\lvert E \rvert$ とおくと，$\mathcal{O}(\lvert V \rvert + \lvert E \rvert)$ となる．
