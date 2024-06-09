---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-GRL_5_A.test.cpp
    title: test/aoj-GRL_5_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Graph/Tree/double_sweep.md
    document_title: "Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09"
    links: []
  bundledCode: "#line 1 \"src/Graph/Tree/double_sweep.hpp\"\n\n\n\n/**\n * @brief\
    \ Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09\n * @docs docs/Graph/Tree/double_sweep.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <queue>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\
    \u76F4\u5F84\u3092\u6C42\u3081\u308B\uFF0EO(|V|).\nstd::tuple<int, int, int> double_sweep(const\
    \ std::vector<std::vector<int> > &g, int rt = 0) {\n    const int vn = g.size();\n\
    \    assert(vn == 0 or (0 <= rt and rt < vn));\n    if(vn == 0) return {-1, -1,\
    \ -1};\n    int furthest_node;\n    std::vector<int> d(vn);\n    std::queue<int>\
    \ que;\n    auto bfs = [&](int s) -> void {\n        furthest_node = s;\n    \
    \    std::fill(d.begin(), d.end(), -1);\n        d[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty()) {\n            int u = que.front();\n           \
    \ que.pop();\n            furthest_node = u;\n            for(int v : g[u]) {\n\
    \                assert(0 <= v and v < vn);\n                if(d[v] != -1) continue;\n\
    \                d[v] = d[u] + 1;\n                que.push(v);\n            }\n\
    \        }\n    };\n    bfs(rt);\n    rt = furthest_node;\n    bfs(rt);\n    return\
    \ {d[furthest_node], rt, furthest_node};  // tuple of (diameter, endpoint1, endpoint2).\n\
    }\n\n// \u91CD\u307F\u4ED8\u304D\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\
    \uFF0EO(|V|).\ntemplate <typename Type>\nstd::tuple<Type, int, int> double_sweep(const\
    \ std::vector<std::vector<std::pair<int, Type> > > &g, int rt = 0) {\n    const\
    \ int vn = g.size();\n    assert(vn == 0 or (0 <= rt and rt < vn));\n    if(vn\
    \ == 0) return {-1, -1, -1};\n    int furthest_node;\n    std::vector<Type> d(vn);\n\
    \    std::queue<int> que;\n    std::vector<bool> seen(vn);\n    auto bfs = [&](int\
    \ s) -> void {\n        furthest_node = s;\n        d[s] = 0;\n        que.push(s);\n\
    \        std::fill(seen.begin(), seen.end(), false);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            seen[u]\
    \ = true;\n            if(d[u] > d[furthest_node]) furthest_node = u;\n      \
    \      for(const auto &[v, cost] : g[u]) {\n                assert(0 <= v and\
    \ v < vn);\n                if(seen[v]) continue;\n                d[v] = d[u]\
    \ + cost;\n                que.emplace(v);\n            }\n        }\n    };\n\
    \    bfs(rt);\n    rt = furthest_node;\n    bfs(rt);\n    return {d[furthest_node],\
    \ rt, furthest_node};  // tuple of (diameter, endpoint1, endpoint2).\n}\n\n} \
    \ // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_DOUBLE_SWEEP_HPP\n#define ALGORITHM_DOUBLE_SWEEP_HPP 1\n\
    \n/**\n * @brief Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09\n * @docs docs/Graph/Tree/double_sweep.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <queue>\n#include <tuple>\n\
    #include <utility>\n#include <vector>\n\nnamespace algorithm {\n\n// \u6728\u306E\
    \u76F4\u5F84\u3092\u6C42\u3081\u308B\uFF0EO(|V|).\nstd::tuple<int, int, int> double_sweep(const\
    \ std::vector<std::vector<int> > &g, int rt = 0) {\n    const int vn = g.size();\n\
    \    assert(vn == 0 or (0 <= rt and rt < vn));\n    if(vn == 0) return {-1, -1,\
    \ -1};\n    int furthest_node;\n    std::vector<int> d(vn);\n    std::queue<int>\
    \ que;\n    auto bfs = [&](int s) -> void {\n        furthest_node = s;\n    \
    \    std::fill(d.begin(), d.end(), -1);\n        d[s] = 0;\n        que.push(s);\n\
    \        while(!que.empty()) {\n            int u = que.front();\n           \
    \ que.pop();\n            furthest_node = u;\n            for(int v : g[u]) {\n\
    \                assert(0 <= v and v < vn);\n                if(d[v] != -1) continue;\n\
    \                d[v] = d[u] + 1;\n                que.push(v);\n            }\n\
    \        }\n    };\n    bfs(rt);\n    rt = furthest_node;\n    bfs(rt);\n    return\
    \ {d[furthest_node], rt, furthest_node};  // tuple of (diameter, endpoint1, endpoint2).\n\
    }\n\n// \u91CD\u307F\u4ED8\u304D\u6728\u306E\u76F4\u5F84\u3092\u6C42\u3081\u308B\
    \uFF0EO(|V|).\ntemplate <typename Type>\nstd::tuple<Type, int, int> double_sweep(const\
    \ std::vector<std::vector<std::pair<int, Type> > > &g, int rt = 0) {\n    const\
    \ int vn = g.size();\n    assert(vn == 0 or (0 <= rt and rt < vn));\n    if(vn\
    \ == 0) return {-1, -1, -1};\n    int furthest_node;\n    std::vector<Type> d(vn);\n\
    \    std::queue<int> que;\n    std::vector<bool> seen(vn);\n    auto bfs = [&](int\
    \ s) -> void {\n        furthest_node = s;\n        d[s] = 0;\n        que.push(s);\n\
    \        std::fill(seen.begin(), seen.end(), false);\n        while(!que.empty())\
    \ {\n            int u = que.front();\n            que.pop();\n            seen[u]\
    \ = true;\n            if(d[u] > d[furthest_node]) furthest_node = u;\n      \
    \      for(const auto &[v, cost] : g[u]) {\n                assert(0 <= v and\
    \ v < vn);\n                if(seen[v]) continue;\n                d[v] = d[u]\
    \ + cost;\n                que.emplace(v);\n            }\n        }\n    };\n\
    \    bfs(rt);\n    rt = furthest_node;\n    bfs(rt);\n    return {d[furthest_node],\
    \ rt, furthest_node};  // tuple of (diameter, endpoint1, endpoint2).\n}\n\n} \
    \ // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Graph/Tree/double_sweep.hpp
  requiredBy: []
  timestamp: '2024-05-08 10:38:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-GRL_5_A.test.cpp
documentation_of: src/Graph/Tree/double_sweep.hpp
layout: document
redirect_from:
- /library/src/Graph/Tree/double_sweep.hpp
- /library/src/Graph/Tree/double_sweep.hpp.html
title: "Double Sweep\uFF08\u6728\u306E\u76F4\u5F84\uFF09"
---
## 概要

木の直径を求めるアルゴリズム．
ここで木の直径とは，「与えられた木における単純パスの長さの最大値」をいう．
また，重みなし無向グラフに対しては，グラフの直径の下界となる．

アルゴリズムの流れは次の通り．
ただし，$\operatorname{d}(u,v)$ はノード $u, v$ 間の距離，$\operatorname{ecc}(v)$ は $\max_u \operatorname{d}(v,u)$ を表す（"ecc" は "eccentricity" の略）．

1. 与えられた木上の任意のノード $s$ を選択する．
1. BFS により，$\operatorname{d}(s,u) = \operatorname{ecc}(s)$ となるノード $u$ を探索する．
1. BFS により，$\operatorname{d}(u,v) = \operatorname{ecc}(u)$ となるノード $v$ を探索する．
1. ノード $u$ と $v$ を結ぶ単純パスが，求める木の直径となる．

計算量は，木のノード数を $\lvert V \rvert$ とすると，$\mathcal{O}(\lvert V \rvert)$ となる.

アルゴリズムのポイントは，「木上の任意のノードから最も遠くにあるノードは直径の端点になる」ということ．
アルゴリズムの正当性を背理法を用いて証明する．

ある木において「根 $r$ から最も遠いノード $x$ は木の直径の端点にならない」と仮定する．
また，木の直径の端点を $u, v$ とおく．

まず，(1) パス $r$-$x$ が直径と交わる場合を考える．
この交点となるノードを $h$ とおく．
ノード $h$ は直径上にあるため，$h$ から最も離れているノードは $u$ または $v$ となる．
しかし，根 $r$ から最も遠いノードは $x$ であり，$x$ は $u$ または $v$ のどちらかになるため，矛盾が生じる．

次に，(2) パス $r$-$x$ が直径と交わらない場合を考える．
直径上にある点を $h'$ とおく．
$\operatorname{d}(r,h') + \operatorname{d}(h',x) \geq \operatorname{d}(r,x)$ であることに注意すると，

$$
\begin{align}
&\operatorname{d}(r,x) \geq \operatorname{d}(r,h') + \max(\operatorname{d}(h',u), \operatorname{d}(h',v)) \notag\\
\Rightarrow &\operatorname{d}(h',x) \geq \max(\operatorname{d}(h',u), \operatorname{d}(h',v)) \notag
\end{align}
$$

となる．(1) と同様にノード $x$ は $u$ または $v$ のどちらかになるため，矛盾が生じる．

よって，木上の任意のノードから最も遠くにあるノードは直径の端点になることが示された．


## 参考文献

1. Clémence Magnien, Matthieu Latapy, and Michel Habib. 2009. Fast computation of empirically tight bounds for the diameter of massive graphs. ACM J. Exp. Algorithmics 13, Article 10 (2009), 9 pages. <https://doi.org/10.1145/1412228.1455266>.
1. "直径". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/graph/tree/diameter/main.html>.


## 例題

1. "D - 高橋くんと木の直径". AtCoder Beginner Contest 019. AtCoder. <https://atcoder.jp/contests/abc019/tasks/abc019_4>.
1. "C - ロミオとジュリエット". AtCoder Regular Contest 022. AtCoder. <https://atcoder.jp/contests/arc022/tasks/arc022_3>.
1. "C - Removing Coins". AtCoder Grand Contest 033. AtCoder. <https://atcoder.jp/contests/agc033/tasks/agc033_c>.
1. E869120. "003 - Longest Circular Road（★4）". 競プロ典型 90 問. AtCoder. <https://atcoder.jp/contests/typical90/tasks/typical90_c>.