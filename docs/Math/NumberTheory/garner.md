## 概要

非負整数列 $m_1, m_2, \ldots, m_N$ と $b_1, b_2, \ldots, b_N$ に対して

$$
\begin{align}
&x \equiv b_1 \pmod{m_1}, \notag\\
&x \equiv b_2 \pmod{m_2}, \notag\\
&\cdots, \notag\\
&x \equiv b_N \pmod{m_N} \notag\\
\end{align}
$$

となる最小の非負整数 $x \ (0 \leq x < m_1 m_2 \cdots m_N)$ を求める．

ただし，以下の制約を満たすこと．
これを満たさない場合は未定義動作となる．

- 任意の $i$ について，$0 \leq b_i < m_i$
- 任意の $i, j \ (i \neq j)$ について，$\gcd(m_i, m_j) = 1$


### アルゴリズムの説明

基本的なアイデアは，求める解 $x$ を次のような形で考える．

$$
x = t_1 + t_2 m_1 + t_3 m_1 m_2 + t_4 m_1 m_2 m_3 + \cdots + t_N m_1 m_2 \cdots m_{N-1} \tag{※}
$$

このとき

$$
\begin{align}
&t_1 = b_1 \pmod{m_1} \notag\\
&t_1 + t_2 m_1 = b_2 \pmod{m_2} \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 = b_3 \pmod{m_3} \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 + t_4 m_1 m_2 m_3 = b_4 \pmod{m_4} \notag\\
&\cdots \notag\\
&t_1 + t_2 m_1 + t_3 m_1 m_2 + \cdots + t_N m_1 m_2 \cdots m_{N-1} = b_N \pmod{m_N} \notag
\end{align}
$$

であり，

$$
\begin{align}
&t_1 = b_1 \pmod{m_1} \notag\\
&t_2 = (b_2 - t_1) \cdot m_1^{-1} \pmod{m_2} \notag\\
&t_3 = (b_3 - t_1 - t_2 m_1) \cdot (m_1 m_2)^{-1} \pmod{m_2} \notag\\
&t_4 = (b_4 - t_1 - t_2 m_1 - t_3 m_1 m_2) \cdot (m_1 m_2 m_3)^{-1} \pmod{m_3} \notag\\
&\cdots \notag\\
&t_N = (b_n - t_1 - t_2 m_1 - \cdots - t_{N-1} m_1 m_2 \cdots m_{N-2}) \cdot (m_1 m_2 \cdots m_{N-1})^{-1} \pmod{m_N} \notag
\end{align}
$$

と変形できる．
これらより $t_i$ を順に求めれば，式 (※) に代入することで解 $x$ が求まる．


## 参考文献

1. K.O. Geddes et al. "5.6. The Integer Chinese Remainder Algorithm". Algorithms for Computer Algebra. Kluwer Academic, 1992, p.174-183.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. "拡張互除法と中国剰余定理（Garnerのアルゴリズム）". クリエイティブなブログ. <https://www.creativ.xyz/ect-gcd-crt-garner-927/>.
