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

|class|summary|complexity|
|---|---|---|
|UnionFind|素集合データ構造||
|PotentializedUnionFind|重み付きUnion-Find Tree||
|SubPersistentUnionFind|部分永続Union-Find Tree||


#### Segment Tree

区間クエリを行うデータ構造です．

|class|summary|complexity|
|---|---|---|
|BIT|Binary Indexed Tree. 別名「フェニック木」．一点加算，区間和取得．|O(logN)|
|BIT0|Binary Indexed Tree (0-based index)|O(logN)|
|BIT2D|2次元Binary Indexed Tree|O((logH)*logW)|
|BIT2D0|2次元Binary Indexed Tree (0-based index)|O((logH)*logW)|
|SegmentTree|セグメント木．一点更新・区間取得．|O(logN)|
|LazySegmentTree|遅延セグメント木．区間更新・区間取得．|O(logN)|
|SparseTable|区間取得のみ．結合則 ((A•B)•C=A•(B•C)) と冪等性 (A•A=A) が成り立つ演算（min, max, orなど）による区間クエリを求める．|構築: O(N*logN), クエリ: O(1)|


#### Others

|class|summary|complexity|
|---|---|---|
|BinaryTrie|非負整数値を扱うTrie木|O(B)|
|SerialSet|整数の集合を連続範囲で管理するデータ構造．ある整数集合においてMEX (Minimum EXcluded value) を求める．|O(logN)|
|Heap|二分ヒープ|O(N*logN)|


### Graph

#### Shortest Path

グラフにおける最短経路問題を解くアルゴリズムです．

|class|summary|complexity|
|---|---|---|
|BellmanFord|Bellman-Fordアルゴリズム．単一始点最短経路 (Single Source Shortest Path, SSSP) を求める．|O(\|V\|*\|E\|)|
|Dijkstra|Dijkstraアルゴリズム．単一始点最短経路を求める．|O(\|E\|*log\|V\|)|


#### Flow

フロー問題を解くアルゴリズムです．

|class|summary|complexity|
|---|---|---|
|FordFulkerson|Ford-Fulkersonアルゴリズム．最大流を求める．|O(F*\|E\|)|
|Dinic|Dinic法．最大流を求める．|O(\|E\|*(\|V\|^2))|
|PrimalDual|最小費用流を求める．|O(F*\|E\|*log\|V\|)|


#### Others

|class|summary|complexity|
|---|---|---|
|Prim|ある重み付き無向グラフにおける最小全域木のコストを求める．|O(\|E\|*log\|V\|)|
|LCA|ある木における二つのノードの最近共通祖先 (Lowest Common Ancestor, LCA) を求める．|O(\|V\|*log\|V\|)|
|LowLink|ある無向連結グラフにおける橋と関節点を求める．|O(\|V\|+\|E\|)|
|SCC|ある有向連結グラフを強連結成分 (Strongly Connected Components, SCC) に分解する．|O(\|V\|+\|E\|)|
|TopologicalSort|任意のトポロジカルソートの解を求め，また考え得る解を数え上げる．|O(\|E\|)|
|calc_tree_diameter(g)|木の直径|O(\|V\|+\|E\|)|


### Math Number Theory

#### Modulo

|class|summary|complexity|
|---|---|---|
|Modint|||
|DynamicModint|動的Modint||
|mod_pow(n,k,m)|繰返し二乗法（mod付き）．n^k (mod m) を求める．|O(logK)|
|mod_inv(a,m)|逆元．a^-1 (mod m) を求める．||


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
|Montmort|完全順列（mod付き）|O(N)|
|nPk(n,k)|順列|O(K)|
|nCK(n,k)|組合せ|O(K)|
|nHk(n,k)|重複組合せ|O(N)|


### Math Algebra

代数学に関するアルゴリズムです．


#### Matrix

|class, function|summary|complexity|
|---|---|---|
|Matrix|行列クラス||
|Permutation|置換クラス||
|Pivot|置換行列クラス||
|transposed_matrix(A)|転置行列||
|rotation_matrix(arg)|回転行列||
|pow(A,k,right_side)|行列累乗|O((logK)*N^3)|
|inv_permutation(P)|逆置換||
|inv_pivot(pivot)|逆置換行列||
|lu_decomposition(A)|PLU分解|O(N^3)|
|sarrus(A)|サラスの方法|O(N^2)|
|det(A)|行列式||
|gaussian_elimination(sweep)|掃き出し法．ガウス・ジョルダンの消去法．|O(N^3)|
|inv_matrix(A)|逆行列|O(N^3)|
|solve_lse(A,b)|連立一次方程式を解く．||


#### Others

|class|summary|complexity|
|---|---|---|
|Kitamasa|きたまさ法|O((K^2)*logN)|
|ipow(n,k)|繰返し二乗法|O(logK)|
|isqrt(x)|平方根（ニュートン法）||


### DP

動的計画法を用いたアルゴリズムです．

|function|summary|complexity|
|---|---|---|
|lis(a)|最長増加部分列 (LIS: Longest Increasing Subsequence)|O(\|A\|*log\|A\|)|
|lcs(a,b)|最長共通部分列 (LCS: Longest Common Subsequence)|O(\|A\|*\|B\|)|
|edit_distance(s,t)|編集距離 (edit distance)|O(\|S\|*\|T\|)|


### String

文字列に関するアルゴリズムです．

|class, function|summary|complexity|
|---|---|---|
|Manacher|最長回文 (Longest Palindromic Substring)|O(\|S\|)|
|z_algorithm(s)|最長共通接頭辞 (LCP: Longest Common Prefix)|O(\|S\|)|
|string_modulo(s,mod)|文字列剰余|O(\|S\|)|
|run_length_encoding(s)|ランレングス圧縮（連長圧縮）||
|split(s,delim)|文字列分割．指定の文字delimで分割する．||


### Others 

その他アルゴリズムです．

|class, function|summary|complexity|
|---|---|---|
|Imos2D|二次元いもす法||
|Mo|Mo's Algorithm|O((N+Q)√N*α)|
|bit_count32(n)|32bitsの数値のビット数をカウントする．||
|bit_count64(n)|64bitsの数値のビット数をカウントする．||
|calc_viewing_range(h)|見晴らし範囲|O(N)|


## Reference
