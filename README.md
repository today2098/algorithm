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



#### Binary Indexed Tree

- BIT : Binary Indexed Tree. 別名「フェニック木」．
- BIT0 : Binary Indexed Tree (0-based index).



#### Segment Tree

- SegmentTree : 一点更新・区間取得セグメント木．



### Graph

#### Shortest Path

- BellmanFord : Bellman-Fordアルゴリズム．単一始点最短経路 (Single Source Shortest Path, SSSP) を求める．計算量は O(|V|*|E|)．
- Dijkstra : Dijkstraアルゴリズム．単一始点最短経路 (Single Source Shortest Path, SSSP) を求める．計算量は O(|E|*log|V|)．



#### Max Flow

- FordFulkerson : Ford-Fulkersonアルゴリズム．
- Dinic : Dinic法．



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
