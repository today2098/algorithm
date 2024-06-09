## 概要

与えられる有向連結グラフを強連結成分 (SCC: Strongly Connected Components) に分解する．

ここで強連結とは，「あるグラフにおける任意の2ノード $u, v$ について，ノード $u$ から $v$ へのパスが存在すること」をいう．
つまり，どの2ノードも互いに行き来できるグラフを指す．

アルゴリズムの計算量は，グラフのノード数を $\lvert V \rvert$ ，辺の数を $\lvert E \rvert$ とおくと，$\mathcal{O}(\lvert V \rvert + \lvert E \rvert)$ となる．
