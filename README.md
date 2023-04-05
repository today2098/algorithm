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

|class|summary|complexity|
|---|---|---|
|Prim|ある重み付き無向グラフにおける最小全域木のコストを求める．|O(\|E\|*log\|V\|)|
|LowLink|ある無向連結グラフにおける橋と関節点を求める．|O(\|V\|+\|E\|)|
|SCC|ある有向連結グラフを強連結成分 (Strongly Connected Components, SCC) に分解する．|O(\|V\|+\|E\|)|
|LCA|ある木における二つのノードの最近共通祖先 (Lowest Common Ancestor, LCA) を求める．|O(\|V\|*log\|V\|)|


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

|class, function|summary|complexity|
|---|---|---|
|Sieve|エラトステネスの篩|O(N*loglogN)|
|LinerSieve|線形篩|O(N)|
|SegmentSieve|区間篩||
|is_prime(n)|素数判定|O(√N)|
|prime_factorize(n)|素因数分解|O(√N)|
|igcd(a,b)|最大公約数|O(logN)|
|ilcm(a,b)|最小公倍数|O(logN)|
|divisors(n)|約数列挙|O(√N)|
|extgcd(a,b,x,y)|拡張ユークリッド互除法|O(logN)|
|crt(b1,m1,b2,m2)|中国剰余定理 (Chinese Remainder Theorem)||


### Math Combinatorics

組合せ論に関するアルゴリズムです．

|class, function|summary|complexity|
|---|---|---|
|Combination|二項係数（mod付き）|O(N)|
|nPk(n,k)|順列|O(K)|
|nCK(n,k)|組合せ|O(K)|
|nHk(n,k)|重複組合せ|O(N)|


## Reference
