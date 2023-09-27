## 概要

離散フーリエ変換 (DFT: Discrete Fourier Transform) を用いた畳み込みを行う．

具体的には，長さ $N, M$ の数列 $\left\{a_0, a_1, \ldots a_{N-1}\right\}, \left\{b_0, b_1, \ldots b_{M-1}\right\}$ に対して

$$
c_k = \sum_{i=0}^{k}{a_i b_{k-i}}
$$

を満たす長さ $N + M - 1$ の数列 $\left\{c_0, c_1, \ldots c_{N+M-2}\right\}$ を $\mathcal{O}\left(\left(N + M\right)^2\right)$ で求める．


## 参考文献

1. "離散フーリエ変換". Wikipedia. <https://ja.wikipedia.org/wiki/離散フーリエ変換>.
1. AngrySadEight. "高速フーリエ変換・数論変換を改めて理解しようという話". Qiita. <https://qiita.com/AngrySadEight/items/0dfde26060daaf6a2fda>.
1. tatyam. "【競プロer向け】FFT を習得しよう！". 東京工業大学で活動するデジタル創作. <https://trap.jp/post/1386/>.
1. "競プロのための高速フーリエ変換". <https://www.creativ.xyz/fast-fourier-transform/>.
