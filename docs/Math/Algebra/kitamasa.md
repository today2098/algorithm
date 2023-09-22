## 概要

初めの $k$ 項 $\{a_0, a_1, \cdots, a_{k-1}\}$ と $k$ 階線形漸化式

$$
a_n = d_0 \cdot a_{n-k} + d_1 \cdot a_{n-(k-1)} + \cdots + d_{k-1} \cdot a_{n-1}
$$

によって定まる数列 $\{a_i\}$ の任意の項 $a_n$ を $\mathcal{O}(k^2 \log n)$ で求める．

アルゴリズムの主な方針は，

$$
a_n = x_0 \cdot a_0 + x_1 \cdot a_1 + \cdots + x_{k-1} \cdot a_{k-1}
$$

となる $f(n) = \{x_0, x_1, \cdots, x_{k-1}\}$ を求めることである．

アルゴリズムの詳細について説明する．

まず前提として $f(i)$ が分かっていると仮定する．このとき

$$
\begin{align}
a_i &= x_0 \cdot a_0 + x_1 \cdot a_1 + \cdots + x_{k-2} \cdot a_{k-2} + x_{k-1} \cdot a_{k-1} \notag
\end{align}
$$

とすると

$$
\begin{align}
a_{i+1} &= x_0 \cdot a_1 + x_1 \cdot a_2 + \cdots + x_{k-2} \cdot a_{k-1} + x_{k-1} \cdot a_{k} \notag\\
a_{i+1} &= x_0 \cdot a_1 + x_1 \cdot a_2 + \cdots + x_{k-2} \cdot a_{k-1} + x_{k-1} \cdot \{ d_0 \cdot a_0 + d_1 \cdot a_1 + \cdots + d_{k-1} \cdot a_{k-1}  \} \notag\\
a_{i+1} &= x_{k-1} \cdot d_0 \cdot a_0 + (x_0 + x_{k-1} \cdot d_1) \cdot a_1 + (x_1 + x_{k-1} \cdot d_2) \cdot a_2 + \cdots + (x_{k-2} + x_{k-1} \cdot d_{k-1}) \cdot a_{k-1} \notag\\
\end{align}
$$

より，$f(i+1)$ が $\mathcal{O}(k)$ で求められる．

また，先の方法で $f(i), f(i+1), \cdots, f(i+k-1)$ が$\mathcal{O}(k^2)$ で列挙できるとする．このとき，$x_{(j)k}$ を $f(i+j)$ の $k$ 項目とすると

$$
\begin{align}
a_{2i} &= x_0 \cdot a_{i+0} + x_1 \cdot a_{i+1} + \cdots + x_{k-1} \cdot a_{i+k-1} \notag\\
a_{2i} &= x_0 \cdot (x_{(0)0} \cdot a_0 + x_{(0)1} \cdot a_1 + \cdots + x_{(0)k-1} \cdot a_{k-1}) \notag\\
    &\quad + x_1 \cdot (x_{(1)0} \cdot a_0 + x_{(1)1} \cdot a_1 + \cdots + x_{(1)k-1} \cdot a_{k-1}) + \cdots \notag\\
    &\quad + x_{k-1} \cdot (x_{(k-1)0} \cdot a_0 + x_{(k-1)1} \cdot a_1 + \cdots + x_{(k-1)k-1} \cdot a_{k-1}) \notag\\
a_{2i} &= (x_0 \cdot x_{(0)0} + x_1 \cdot x_{(1)0} + \cdots + x_{k-1} \cdot x_{(k-1)0}) \cdot a_0 \notag\\
    &\quad + (x_0 \cdot x_{(0)1} + x_1 \cdot x_{(1)1} + \cdots + x_{k-1} \cdot x_{(k-1)1}) \cdot a_1 + \cdots \notag\\
    &\quad + (x_0 \cdot x_{(0)k-1} + x_1 \cdot x_{(1)k-1} + \cdots + x_{k-1} \cdot x_{(k-1)k-1}) \cdot a_{k-1} \notag
\end{align}
$$

となり，$f(2i)$ が $\mathcal{O}(k^2)$ で求められる．

よって，全体の計算量は $\mathcal{O}(k^2 \log n)$ となる．


## 参考文献

1. yosupo. "きたまさ法メモ". Hatena Blog. <https://yosupo.hatenablog.com/entry/2015/03/27/025132>.


## 問題

- "T - フィボナッチ". Typical DP Contest. AtCoder. <https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci>.
