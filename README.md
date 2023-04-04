# algorithm
My library for kyopro.


## Overview

これは競技プログラミングでの利用を想定した，アルゴリズムやデータ構造のライブラリです．

This is library for competitive programming.


## Usage

作成した関数，クラスは VS Code 用のスニペットにしています．
このスニペットファイル (.code-snippets) を自身のワークスペースにコピーし，使用してください．

There are snippet files (.code-snippets) for VS Code.
You can use it, copying to your workspace.

```sh
$ cd algorithm
$ cp .vscode/*.code-snippets /path/to/your/workspace/.vscode/
```

またソースコードについて，スニペット作成を簡単にするため，関数の宣言と定義を分けず，ヘッダーファイル (.hpp) にまとめて記述しています．

I write source code only on header file in order to simplify making snippet.


## Description

### Data Structure

#### Union-Find Tree

- UnionFind : 素集合データ構造．
- PotentializedUnionFind : 重み付きUnion-Find Tree.
- SubPersistentUnionFind : 部分永続Union-Find Tree．


#### Segment Tree

- BIT : Binary Indexed Tree. 別名「フェニック木」．一点加算，区間和取得．
- BIT0 : Binary Indexed Tree (0-based index).
- BIT2D : 2次元Binary Indexed Tree．
- BIT2D0 : 2次元Binary Indexed Tree (0-based index)．
- SegmentTree : セグメント木．一点更新・区間取得．
- LazySegmentTree : 遅延セグメント木．区間更新・区間取得．


#### Others

- Heap : 二分ヒープ．
- SerialSet : 整数の集合を連続範囲で管理するデータ構造．ある整数集合においてMEX (Minimum EXcluded value) を求める．O(logN).
- BinaryTrie : 非負整数値を扱うTrie木．


### Graph

#### Shortest Path

- BellmanFord : Bellman-Fordアルゴリズム．単一始点最短経路 (Single Source Shortest Path, SSSP) を求める．O(|V|*|E|).
- Dijkstra : Dijkstraアルゴリズム．単一始点最短経路を求める．O(|E|*log|V|).


#### Flow

- FordFulkerson : Ford-Fulkersonアルゴリズム．O(F*|E|).
- Dinic : Dinic法．O(|E|*(|V|^2)).
- PrimalDual : 最小費用流問題を求める．O(F*|E|*log|V|).


#### Others

- Prim : ある重み付き無向グラフにおける最小全域木のコストを求める．O(|E|*log|V|).
- LCA : ある木における二つのノードの最近共通祖先 (Lowest Common Ancestor, LCA) を求める．O(|V|*log|V|).
- LowLink : ある無向連結グラフにおける橋と関節点を求める．O(|V|+|E|).
- SCC : ある有向連結グラフを強連結成分 (Strongly Connected Components, SCC) に分解する．O(|V|+|E|).


### Math Number Theory

#### Modulo

- Modint
- DynamicModint : 動的Modint．


#### Prime Number

- Sieve : エラトステネスの篩
- SegmentSieve : 区間篩


### Math Combinatorics

- Combination : 二項係数（mod付き）．
- nPk () : 順列．
- nCK () : 組み合わせ．
- nHk () : 重複組み合わせ．


## Reference
