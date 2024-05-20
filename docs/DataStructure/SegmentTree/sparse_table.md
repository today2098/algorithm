## 概要

静的な数列に対し，次の性質が成り立つ演算（$\operatorname{or}, \min, \max, \gcd, \operatorname{lcm}$など）による区間クエリを求める．

- 結合則：$(A \bullet B) \bullet C = A \bullet (B \bullet C)$
- 冪等性：$A \bullet A = A$

アルゴリズムの計算量は，数列の長さを $N$ とすると，テーブルの構築に $\mathcal{O}(N \log N),$ クエリ処理に $\mathcal{O}(1)$ かかる．


## 参考文献

- tookunn. "Sparse Tableを知ったので、忘れないように。". Hatena Blog. <https://tookunn.hatenablog.com/entry/2016/07/13/211148>.
- "Sparse Table". いかたこのたこつぼ. <https://ikatakos.com/pot/programming_algorithm/data_structure/sparse_table>.
