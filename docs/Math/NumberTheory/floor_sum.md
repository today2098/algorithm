## 概要

整数 $n, m, a, b$ に対して，

$$
\operatorname{floor\_sum}(n,m,a,b) = \sum_{i=0}^{n-1}{\left\lfloor \frac{a \times i + b}{m} \right\rfloor}
$$

を $\mathcal{O}(\log \min(m,a))$ で求める（ただし，$n \geq 0, m \geq 1$）．

本アルゴリズムでは主客転倒のテクニックを用いる．

まず $a \geq m, b \geq m$ のとき，$a = q_a m + r_a, b = q_b m + r_b \ (0 \leq r < m)$ と表すと

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{i=0}^{n-1}{\left\lfloor \frac{a \times i + b}{m} \right\rfloor} \notag\\
    &= \sum_{i=0}^{n-1}(q_a \cdot i + q_b) + \sum_{i=0}^{n-1}{\left\lfloor \frac{r_a \times i + r_b}{m} \right\rfloor} \notag\\
    &= q_a \cdot \frac{n(n-1)}{2} + q_b \cdot n + \operatorname{floor\_sum}(n,m,r_a,r_b) \notag\\
\end{align}
$$

となり，$0 \leq a < m, 0 \leq b < m$ の場合に帰着できる．
$a < 0, b < 0$ のときも同様．

以下 $0 \leq a < m, 0 \leq b < m$ とする．

$y_{max} = \left\lfloor (a n + b)/m \right\rfloor$ とすると

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{i=0}^{n-1}{\left\lfloor \frac{a \times i + b}{m} \right\rfloor} \notag\\
    &= \sum_{j=1}^{y_{max}}{\sum_{\substack{0 \leq i < n \\ \left\lfloor (a i + b)/m \right\rfloor = j}}{j}} \notag\\
\end{align}
$$

ここで $k_l$ を $\left\lfloor (a k_l + b)/m \right\rfloor = l$ となる最小の自然数とおくと，$\left\lfloor (a i + b)/m \right\rfloor = l$ を満たす $i$ は $(k_{l+1} - k_l)$ 個となるので，

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{j=1}^{y_{max}}{\sum_{\substack{0 \leq i < n \\ \left\lfloor (a i + b)/m \right\rfloor = j}}{j}} \notag\\
    &= \sum_{j=1}^{y_{max}-1}{j \cdot (k_{j+1} - k_j)} + y_{max} \cdot (n - k_{y_{max}}) \notag\\
    &= \sum_{j=1}^{y_{max}-1}{j \cdot k_{j+1}} - \sum_{j=1}^{y_{max}-1}{j \cdot k_j} + y_{max} \cdot n - y_{max} \cdot k_{y_{max}} \notag\\
    &= \sum_{j=2}^{y_{max}}{(j - 1) \cdot k_j} - \sum_{j=1}^{y_{max}-1}{j \cdot k_j} + y_{max} \cdot n - y_{max} \cdot k_{y_{max}} \notag\\
    &= \sum_{j=2}^{y_{max}}{(j - 1) \cdot k_j} - \sum_{j=1}^{y_{max}}{j \cdot k_j} + y_{max} \cdot n \notag\\
    &= \sum_{j=2}^{y_{max}}{(j - 1) \cdot k_j} - \sum_{j=2}^{y_{max}}{j \cdot k_j} - 1 \cdot k_1 + y_{max} \cdot n \notag\\
    &= - \sum_{j=2}^{y_{max}}{k_j} - 1 \cdot k_1 + y_{max} \cdot n \notag\\
    &= - \sum_{j=1}^{y_{max}}{k_j} + y_{max} \cdot n \notag\\
    &= - \sum_{j=1}^{y_{max}}{\left( k_j - n \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left( n - k_j \right)} \notag\\
\end{align}
$$

$k_l$ は $\left\lfloor (a k_l + b)/m \right\rfloor = l$ より

$$
\begin{align}
& \ \frac{a \cdot k_l + b}{m} \geq l \notag\\
\Leftrightarrow& \ k_l \geq \frac{m \cdot l - b}{a} \notag\\
\end{align}
$$

であり，またこれを満たす最小の自然数なので $k_l = \left\lceil (m l - b) / a \right\rceil$ となる．

よって，

$$
\begin{align}
\operatorname{floor\_sum}(n,m,a,b) &= \sum_{j=1}^{y_{max}}{\left( n - k_j \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left( n - \left\lceil \frac{m \cdot j - b}{a} \right\rceil \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left( n + \left\lfloor \frac{-m \cdot j + b}{a} \right\rfloor \right)} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left\lfloor n + \frac{-m \cdot j + b}{a} \right\rfloor} \notag\\
    &= \sum_{j=1}^{y_{max}}{\left\lfloor n - \frac{m \cdot j - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor n - \frac{m \cdot (y_{max} - j) - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor n - \frac{m \cdot (\left\lfloor \frac{a \cdot n + b}{m} \right\rfloor - j) - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor n - \frac{(a \cdot n + b) - (a \cdot n + b) \% m - m \cdot j - b}{a} \right\rfloor} \notag\\
    &= \sum_{j=0}^{y_{max}-1}{\left\lfloor \frac{m \times j + (a \cdot n + b) \% m}{a} \right\rfloor} \notag\\
    &= \operatorname{floor\_sum}(y_{max},a,m,(a \cdot n + b) \% m) \notag\\
\end{align}
$$

となり，再帰的に計算できる．
またこの再帰は，$m$ と $a$ について互除法を行うようになるため，必ず停止することが分かる．

計算量は互除法と同じなので，$\mathcal{O}(\log \min(m,a))$ となる．


## 参考文献

1. HNJ. "Floor Sum (ACL Practice Contest C)". Qiita. <https://qiita.com/HNJ/items/564f15316719209df73c>.
1. rsk0315. "sum of floor of liner の解説をするよ". Hatena Blog. <https://rsk0315.hatenablog.com/entry/2020/12/13/231307>.
1. yosupo. "C - Floor Sum 解説". AtCoder. <https://atcoder.jp/contests/practice2/editorial/579>.
1. kyopro_friends. X (Twitter). <https://twitter.com/kyopro_friends/status/1304063876019793921>.


## 問題

- "C - Floor Sum". AtCoder Library Practice Contest. AtCoder. <https://atcoder.jp/contests/practice2/tasks/practice2_c>.
