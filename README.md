# algorithm
My library for kyopro.


## Overview

これは競技プログラミングでの利用を想定した，アルゴリズムやデータ構造のライブラリです．

This is library for competitive programming.


## Usage

作成した関数，クラスは VS Code 用のスニペットにしています．このスニペットファイル (.code-snippets) を自身のワークスペースにコピーし，使用してください．

```sh
$ cd algorithm
$ cp .vscode/*.code-snippets /path/to/your/workspace/.vscode/
```

またスニペット作成を簡単にするため，関数の宣言と定義，ソースとヘッダを分けず，ヘッダーファイル (.hpp) にまとめて記述しています．

I write only on header files to simplify making snippet. 


## Description

### Data Structure

#### Union-Find Tree

- UnionFind : 素集合データ構造．
- SubPersistentUnionFind : 部分永続Union-Find Tree．


#### Segment Tree

- SegmentTree : 一点更新・区間取得セグメント木．


### Graph

#### Shortest Path

- Dijkstra : 単一始点最短経路 (Single Source Shortest Path, SSSP)．


## Reference
