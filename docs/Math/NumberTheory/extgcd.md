## 概要

2つの整数 $a, b$ に対して，

$$
ax + by = \gcd(a, b)
$$

を満たす整数の組 $(x, y)$ を，ユークリッドの互除法を応用して求める．
ただし，解は複数存在するが，このうち $\lvert x \rvert + \lvert y \rvert$ が最小となるものとする．

この解を $(x_1, y_1)$ とすると，他のすべての解は 

$$
\left( x_1 + k \cdot \frac{b}{\gcd(a, b)}, \ y_1 - k \cdot \frac{a}{\gcd(a, b)} \right)
$$

から求められる（ただし，$k$ は整数）．

アルゴリズムの計算量は $\mathcal{O}(\log(\min(a,b)))$ となる． 


## 参考文献

1. H.H. シルヴァーマン. "第6章 一次方程式と最大公約数". はじめての数論. 鈴木治郎訳. 原著第4版, 丸善出版, 2022, p.36-43.
1. "ユークリッドの互除法". Wikipedia. <https://ja.wikipedia.org/wiki/ユークリッドの互除法>.
1. drken. "拡張ユークリッドの互除法 〜 一次不定方程式 ax + by = c の解き方 〜". Qiita. <https://qiita.com/drken/items/b97ff231e43bce50199a>.
