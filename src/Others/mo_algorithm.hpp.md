---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-0425.test.cpp
    title: test/aoj-0425.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo-static_range_inversions_query.test.cpp
    title: test/yosupo-static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Others/mo_algorithm.md
    document_title: "Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\
      \uFF09"
    links: []
  bundledCode: "#line 1 \"src/Others/mo_algorithm.hpp\"\n\n\n\n/**\n * @brief Mo's\
    \ Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09\n * @docs docs/Others/mo_algorithm.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <tuple>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// Mo's Algorithm\uFF08\u30AF\u30A8\
    \u30EA\u5E73\u65B9\u5206\u5272\uFF09.\nclass Mo {\n    int m_len;            \
    \                              // m_len:=(\u533A\u9593\u306E\u9577\u3055).\n \
    \   int m_q;                                            // m_q:=(\u30AF\u30A8\u30EA\
    \u6570).\n    std::vector<std::tuple<int, int, int> > m_queries;  // m_queries[i]:=(i\u756A\
    \u76EE\u306E\u533A\u9593\u30AF\u30A8\u30EA). tuple of (left, right, index).\n\n\
    \    void sort_query() {\n        const int width = std::sqrt(m_len);\n      \
    \  auto comp = [&width](const std::tuple<int, int, int> &a, const std::tuple<int,\
    \ int, int> &b) -> bool {\n            const auto &[al, ar, _] = a;\n        \
    \    const auto &[bl, br, __] = b;\n            int a_block = al / width, b_block\
    \ = bl / width;\n            if(a_block == b_block) return (a_block & 1 ? ar >\
    \ br : ar < br);\n            return a_block < b_block;\n        };\n        std::sort(m_queries.begin(),\
    \ m_queries.end(), comp);\n    }\n\npublic:\n    Mo() : Mo(0) {}\n    explicit\
    \ Mo(size_t n) : m_len(n), m_q(0) {}\n\n    // \u533A\u9593[l,r)\u306E\u30AF\u30A8\
    \u30EA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    void insert(int l, int r) {\n\
    \        assert(0 <= l and l < r and r <= m_len);\n        m_queries.emplace_back(l,\
    \ r, m_q++);\n    }\n    // \u5404\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\
    \uFF0E\u5F15\u6570\u306F\u30E9\u30E0\u30C0\u5F0F\uFF0EO(\u03B1(N+Q)\u221AN).\n\
    \    template <typename F1, typename F2, typename F3>\n    void execute(const\
    \ F1 &add, const F2 &del, const F3 &solve) { execute(add, del, add, del, solve);\
    \ }\n    template <typename F1, typename F2, typename F3, typename F4, typename\
    \ F5>\n    void execute(const F1 &add_l, const F2 &del_l, const F3 &add_r, const\
    \ F4 &del_r, const F5 &solve) {\n        sort_query();\n        int l = 0, r =\
    \ 0;\n        for(const auto &[nl, nr, idx] : m_queries) {\n            while(nl\
    \ < l) add_l(--l);\n            while(r < nr) add_r(r++);\n            while(l\
    \ < nl) del_l(l++);\n            while(nr < r) del_r(--r);\n            solve(idx);\n\
    \        }\n    }\n    void reset() {\n        m_queries.clear();\n        m_q\
    \ = 0;\n    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_MO_HPP\n#define ALGORITHM_MO_HPP 1\n\n/**\n * @brief Mo's\
    \ Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09\n * @docs docs/Others/mo_algorithm.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <tuple>\n\
    #include <vector>\n\nnamespace algorithm {\n\n// Mo's Algorithm\uFF08\u30AF\u30A8\
    \u30EA\u5E73\u65B9\u5206\u5272\uFF09.\nclass Mo {\n    int m_len;            \
    \                              // m_len:=(\u533A\u9593\u306E\u9577\u3055).\n \
    \   int m_q;                                            // m_q:=(\u30AF\u30A8\u30EA\
    \u6570).\n    std::vector<std::tuple<int, int, int> > m_queries;  // m_queries[i]:=(i\u756A\
    \u76EE\u306E\u533A\u9593\u30AF\u30A8\u30EA). tuple of (left, right, index).\n\n\
    \    void sort_query() {\n        const int width = std::sqrt(m_len);\n      \
    \  auto comp = [&width](const std::tuple<int, int, int> &a, const std::tuple<int,\
    \ int, int> &b) -> bool {\n            const auto &[al, ar, _] = a;\n        \
    \    const auto &[bl, br, __] = b;\n            int a_block = al / width, b_block\
    \ = bl / width;\n            if(a_block == b_block) return (a_block & 1 ? ar >\
    \ br : ar < br);\n            return a_block < b_block;\n        };\n        std::sort(m_queries.begin(),\
    \ m_queries.end(), comp);\n    }\n\npublic:\n    Mo() : Mo(0) {}\n    explicit\
    \ Mo(size_t n) : m_len(n), m_q(0) {}\n\n    // \u533A\u9593[l,r)\u306E\u30AF\u30A8\
    \u30EA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n    void insert(int l, int r) {\n\
    \        assert(0 <= l and l < r and r <= m_len);\n        m_queries.emplace_back(l,\
    \ r, m_q++);\n    }\n    // \u5404\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\
    \uFF0E\u5F15\u6570\u306F\u30E9\u30E0\u30C0\u5F0F\uFF0EO(\u03B1(N+Q)\u221AN).\n\
    \    template <typename F1, typename F2, typename F3>\n    void execute(const\
    \ F1 &add, const F2 &del, const F3 &solve) { execute(add, del, add, del, solve);\
    \ }\n    template <typename F1, typename F2, typename F3, typename F4, typename\
    \ F5>\n    void execute(const F1 &add_l, const F2 &del_l, const F3 &add_r, const\
    \ F4 &del_r, const F5 &solve) {\n        sort_query();\n        int l = 0, r =\
    \ 0;\n        for(const auto &[nl, nr, idx] : m_queries) {\n            while(nl\
    \ < l) add_l(--l);\n            while(r < nr) add_r(r++);\n            while(l\
    \ < nl) del_l(l++);\n            while(nr < r) del_r(--r);\n            solve(idx);\n\
    \        }\n    }\n    void reset() {\n        m_queries.clear();\n        m_q\
    \ = 0;\n    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/mo_algorithm.hpp
  requiredBy: []
  timestamp: '2024-04-20 11:05:42+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-0425.test.cpp
  - test/yosupo-static_range_inversions_query.test.cpp
documentation_of: src/Others/mo_algorithm.hpp
layout: document
redirect_from:
- /library/src/Others/mo_algorithm.hpp
- /library/src/Others/mo_algorithm.hpp.html
title: "Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09"
---
## 概要

区間に対する複数のクエリをまとめて高速に処理するアルゴリズム．
特に，区間 $[l,m)$ と $[m,r)$ の結果をマージして区間 $[l,r)$ の結果を求めることが簡単にできない場合に適している．

Mo's algorithm を適用するためには，次の3つの条件を満たす必要がある．

- 配列の各要素が不変．
- クエリを先読みできる（オフラインクエリ）．
- 区間 $[l,r)$ の結果から区間 $[l-1,r), [l+1,r), [l,r-1), [l,r+1)$ の結果を容易に計算できる（1回の区間伸縮が簡単）． 

アルゴリズムの基本的なアイデアは，クエリを適切な順番に並び替えて，全体での区間の伸縮回数を抑えることにより，計算量を小さくするということである．

アルゴリズムの流れは次の通り．ただし，区間の長さを $N$, クエリの数を $Q$, $i$ 番目のクエリの区間を $[l_i, r_i)$ とおく．

1. 区間を $\sqrt{N}$ 個のブロックに分割する．
1. 各クエリを $l_i$ についてブロックごとに分け，さらにブロック内で $r_i$ についてソートする．
1. 各クエリを並び替えた順に，区間を伸縮させながら処理する．

アルゴリズムの計算量は，区間伸縮1回あたりの計算量を $O(α)$ とすると，クエリの並び替えに $O(Q\log{Q}),$ クエリの処理に $O(α(N+Q)\sqrt{N})$ かかり，全体として $O(Q\log{Q} + α(N+Q)\sqrt{N})$ となる．


## 参考文献

1. ageprocpp. "Mo's algorithm(クエリ平方分割)の話". Qiita. <https://qiita.com/ageprocpp/items/34121c58e571ea8c4023>.
1. ei1333. "Mo's algorithm". Hatena Blog. <https://ei1333.hateblo.jp/entry/2017/09/11/211011>.
1. strangerxxx. "Mo's Algorithmのイメージを視覚的に理解したい". Hatena Blog. <https://strangerxxx.hateblo.jp/entry/20230314/1678795200>.
1. "Mo's algorithm". アルゴリズムとデータ構造大全. <https://take44444.github.io/Algorithm-Book/range/mo/main.html>.


## 例題

1. "G - Range Pairing Query". AtCoder Beginner Contest 242. AtCoder. <https://atcoder.jp/contests/abc242/tasks/abc242_g>.
1. "G - Triple Index". AtCoder Beginner Contest 293. AtCoder. <https://atcoder.jp/contests/abc293/tasks/abc293_g>.
