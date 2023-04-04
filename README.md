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

素集合データ構造です．

|class|summary|
|---|---|
|UnionFind|素集合データ構造．|
|PotentializedUnionFind|重み付きUnion-Find Tree．|
|SubPersistentUnionFind|部分永続Union-Find Tree．|


#### Segment Tree

区間クエリを行うデータ構造です．

|class|summary|
|---|---|
|BIT|Binary Indexed Tree. 別名「フェニック木」．一点加算，区間和取得．|
|BIT0|Binary Indexed Tree (0-based index).|
|BIT2D|2次元Binary Indexed Tree．|
|BIT2D0|2次元Binary Indexed Tree (0-based index)．|
|SegmentTree|セグメント木．一点更新・区間取得．|
|LazySegmentTree|遅延セグメント木．区間更新・区間取得．|


#### Others

|class|summary|
|---|---|
|Heap|二分ヒープ．|
|SerialSet|整数の集合を連続範囲で管理するデータ構造．ある整数集合においてMEX (Minimum EXcluded value) を求める．O(logN).|
|BinaryTrie|非負整数値を扱うTrie木．|


### Graph

#### Shortest Path

グラフにおける最短経路問題を解くアルゴリズムです．

|class|summary|
|---|---|
|BellmanFord|Bellman-Fordアルゴリズム．単一始点最短経路 (Single Source Shortest Path, SSSP) を求める．O(\|V\|*\|E\|).|
|Dijkstra|Dijkstraアルゴリズム．単一始点最短経路を求める．O(\|E\|*log\|V\|).|


#### Flow

フロー問題を解くアルゴリズムです．

|class|summary|
|---|---|
|FordFulkerson|Ford-Fulkersonアルゴリズム．O(F*\|E\|).|
|Dinic|Dinic法．O(\|E\|*(\|V\|^2)).|
|PrimalDual|最小費用流問題を求める．O(F*\|E\|*log\|V\|).|


#### Others

|class|summary|
|---|---|
|Prim|ある重み付き無向グラフにおける最小全域木のコストを求める．O(\|E\|*log\|V\|).|
|LCA|ある木における二つのノードの最近共通祖先 (Lowest Common Ancestor, LCA) を求める．O(\|V\|*log\|V\|).|
|LowLink|ある無向連結グラフにおける橋と関節点を求める．O(\|V\|+\|E\|).|
|SCC|ある有向連結グラフを強連結成分 (Strongly Connected Components, SCC) に分解する．O(\|V\|+\|E\|).|


### Math Number Theory

#### Modulo

|class|summary|
|---|---|
|Modint||
|DynamicModint|動的Modint．|
|mod_pow(n,k,m)|繰返し二乗法（mod付き）．n^k (mod m) を求める．O(logK).|
|mod_inv(a,m)|逆元．a^-1 (mod m) を求める．|


#### Prime Number

素数，約数に関するアルゴリズムです．

|class|summary|
|---|---|
|Sieve|エラトステネスの篩|
|LinerSieve|線形篩|
|SegmentSieve|区間篩|
|is_prime(n)|自然数nを素数判定する．|
|prime_factorize(n)|自然数nを素因数分解する．|
|igcd(a,b)|自然数a, bの最大公約数を求める．|
|ilcm(a,b)|自然数a, bの最小公倍数を求める．|
|calc_divisors(n)|自然数nの約数を列挙する．|
|extgcd()|拡張ユークリッド互除法．|
|crt()|中国剰余定理 (Chinese Remainder Theorem)．|


### Math Combinatorics

組合せ論に関するアルゴリズムです．

|class, function|summary|
|---|---|
|Combination|二項係数（mod付き）．|
|nPk()|順列．|
|nCK()|組み合わせ．|
|nHk()|重複組み合わせ．|


## Reference
