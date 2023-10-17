## 概要

非負整数 $m_1, m_2, b_1, b_2$ に対して，

$$
\begin{align}
x &\equiv b_1 \pmod{m_1}, \notag\\
x &\equiv b_2 \pmod{m_2} \notag
\end{align}
$$

を満たす非負整数 $x \ (0 \leq x < \operatorname{lcm}(m_1,m_2))$ を求める．

解 $x$ が存在する必要十分条件は

$$
b_1 \equiv b_2 \pmod{\gcd(m_1,m_2)}
$$

であること．
またこのときに限り，解 $x$ が $0$ 以上 $\operatorname{lcm}(m_1,m_2)$ 未満の範囲にただ1つ存在し，それを $r$ とすると

$$
x \equiv r \pmod{\operatorname{lcm}(m_1,m_2)}
$$

が成り立つ．

実装では[拡張ユークリッドの互除法](https://today2098.github.io/algorithm/src/Math/NumberTheory/extgcd.hpp)を利用し，計算量は $\mathcal{O}(\log(\min(m_1,m_2)))$ となる．


## 参考文献

1. H.H. シルヴァーマン. "第11章 オイラーの$\varphi$関数と中国の剰余定理". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.75-80.
1. "中国の剰余定理". Wikipedia. <https://ja.wikipedia.org/wiki/中国の剰余定理>.
1. drken. "中国剰余定理 (CRT) の解説と、それを用いる問題のまとめ". Qiita. <https://qiita.com/drken/items/ae02240cd1f8edfc86fd>.
1. Sen_comp. "けんちょんさんの中国剰余定理の補足". Hatena Blog. <https://sen-comp.hatenablog.com/entry/2021/03/05/194205>.
