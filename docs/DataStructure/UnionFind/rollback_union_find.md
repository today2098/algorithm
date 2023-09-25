## 概要

Rollback 付き Union-Find は，通常の [Union-Find](https://today2098.github.io/algorithm/src/DataStructure/UnionFind/union_find.hpp) の機能に加え，グループの併合時に親番号を保存することにより前の状態に戻せるようにしたもの．

実装では「union by size」の工夫のみ行い，各クエリの計算量は $\mathcal{O}(\log N)$ となる．


## 参考文献

1. "Union-Find木". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/union_find_tree>.
