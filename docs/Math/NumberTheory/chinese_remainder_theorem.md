## 概要

整数 $m, n, b, c$ に対して，

$$
\begin{align}
x &\equiv b \pmod m, \notag\\
x &\equiv c \pmod n \notag
\end{align}
$$

を満たす $0$ 以上 $\operatorname{lcm}(m,n)$ 以下の整数 $x$ を求める．

$x$ が存在する必要十分条件は

$$
b \equiv c \pmod{\gcd(m,n)}
$$

であること．

実装では[拡張ユークリッドの互除法](https://today2098.github.io/algorithm/src/Math/NumberTheory/extgcd.hpp)を利用し，計算量は $\mathcal{O}(\log a)$ となる． 


## 参考文献

1. H.H. シルヴァーマン. "第11章 オイラーの$\varphi$関数と中国の剰余定理". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.75-80.
1. "中国の剰余定理". Wikipedia. <https://ja.wikipedia.org/wiki/中国の剰余定理>.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. Sen_comp. "けんちょんさんの中国剰余定理の補足". Hatena Blog. <https://sen-comp.hatenablog.com/entry/2021/03/05/194205>.
