---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://ei1333.hateblo.jp/entry/2017/09/11/211011\uFF08\u53C2\u71672023.5.4\uFF09\
      ."
    - "https://qiita.com/ageprocpp/items/34121c58e571ea8c4023\uFF08\u53C2\u71672023.5.3\uFF09\
      \uFF0E"
    - "https://strangerxxx.hateblo.jp/entry/20230314/1678795200\uFF08\u53C2\u7167\
      2023.5.4\uFF09."
    - "https://take44444.github.io/Algorithm-Book/range/mo/main.html\uFF08\u53C2\u7167\
      2023.5.3\uFF09\uFF0E"
  bundledCode: "#line 1 \"src/Others/mos_algorithm.hpp\"\n\n\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// Mo's Algorithm.\nclass Mo {\n    int n;\n    int q;\n    std::vector<std::tuple<int,\
    \ int, int> > query;\n\n    // \u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF0E\
    \n    void sort_query() {\n        int width = std::sqrt(n);\n        std::sort(query.begin(),\
    \ query.end(), [width](const std::tuple<int, int, int> &a, const std::tuple<int,\
    \ int, int> &b) -> bool {\n            const auto &[al, ar, _] = a;\n        \
    \    const auto &[bl, br, __] = b;\n            int block_a = al / width, block_b\
    \ = bl / width;\n            if(block_a != block_b) return block_a < block_b;\n\
    \            return (block_a & 1 ? ar > br : ar < br);\n        });\n    }\n\n\
    public:\n    Mo() : Mo(0) {}\n    explicit Mo(int n_) : n(n_), q(0) {}\n\n   \
    \ void insert(int l, int r) {\n        assert(0 <= l and l < r and r <= n);\n\
    \        query.emplace_back(l, r, q++);\n    }\n    // \u5404\u30AF\u30A8\u30EA\
    \u3092\u5B9F\u884C\u3059\u308B\uFF0EF1~5\u306F\u30E9\u30E0\u30C0\u5F0F\uFF0EO((N+Q)\u221A\
    N*\u03B1).\n    template <typename F1, typename F2, typename F3, typename F4,\
    \ typename F5>\n    void execute(F1 &&add_l, F2 &&add_r, F3 &&del_l, F4 &&del_r,\
    \ F5 &&solve) {\n        sort_query();\n        int l = 0, r = 0;\n        for(const\
    \ auto &[nl, nr, idx] : query) {\n            while(nl < l) add_l(--l);\n    \
    \        while(r < nr) add_r(r++);\n            while(l < nl) del_l(l++);\n  \
    \          while(nr < r) del_r(--r);\n            solve(idx);\n        }\n   \
    \ }\n};\n\n}  // namespace algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n- Mo's\
    \ algorithm\uFF0C\u30A2\u30EB\u30B4\u30EA\u30BA\u30E0\u3068\u30C7\u30FC\u30BF\u69CB\
    \u9020\u5927\u5168\uFF0Chttps://take44444.github.io/Algorithm-Book/range/mo/main.html\uFF08\
    \u53C2\u71672023.5.3\uFF09\uFF0E\n- ageprocpp, Mo's algorithm\uFF08\u30AF\u30A8\
    \u30EA\u5E73\u65B9\u5206\u5272\uFF09\u306E\u8A71\uFF0CQiita, https://qiita.com/ageprocpp/items/34121c58e571ea8c4023\uFF08\
    \u53C2\u71672023.5.3\uFF09\uFF0E\n- ei1333, Mo's algorithm, ei1333\u306E\u65E5\
    \u8A18\uFF0CHatenaBlog, https://ei1333.hateblo.jp/entry/2017/09/11/211011\uFF08\
    \u53C2\u71672023.5.4\uFF09.\n- \u3059\u3068\u308C\u3093\u3058\u3083\u30FC\uFF0C\
    Mo's Algorithm\u306E\u30A4\u30E1\u30FC\u30B8\u3092\u8996\u899A\u7684\u306B\u7406\
    \u89E3\u3057\u305F\u3044\uFF0C\u5F92\u7136\uFF0CHatenaBlog, https://strangerxxx.hateblo.jp/entry/20230314/1678795200\uFF08\
    \u53C2\u71672023.5.4\uFF09.\n*/\n"
  code: "#ifndef ALGORITHM_MOS_ALGORITHM_HPP\n#define ALGORITHM_MOS_ALGORITHM_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// Mo's Algorithm.\nclass Mo {\n    int n;\n    int\
    \ q;\n    std::vector<std::tuple<int, int, int> > query;\n\n    // \u30AF\u30A8\
    \u30EA\u5E73\u65B9\u5206\u5272\uFF0E\n    void sort_query() {\n        int width\
    \ = std::sqrt(n);\n        std::sort(query.begin(), query.end(), [width](const\
    \ std::tuple<int, int, int> &a, const std::tuple<int, int, int> &b) -> bool {\n\
    \            const auto &[al, ar, _] = a;\n            const auto &[bl, br, __]\
    \ = b;\n            int block_a = al / width, block_b = bl / width;\n        \
    \    if(block_a != block_b) return block_a < block_b;\n            return (block_a\
    \ & 1 ? ar > br : ar < br);\n        });\n    }\n\npublic:\n    Mo() : Mo(0) {}\n\
    \    explicit Mo(int n_) : n(n_), q(0) {}\n\n    void insert(int l, int r) {\n\
    \        assert(0 <= l and l < r and r <= n);\n        query.emplace_back(l, r,\
    \ q++);\n    }\n    // \u5404\u30AF\u30A8\u30EA\u3092\u5B9F\u884C\u3059\u308B\uFF0E\
    F1~5\u306F\u30E9\u30E0\u30C0\u5F0F\uFF0EO((N+Q)\u221AN*\u03B1).\n    template\
    \ <typename F1, typename F2, typename F3, typename F4, typename F5>\n    void\
    \ execute(F1 &&add_l, F2 &&add_r, F3 &&del_l, F4 &&del_r, F5 &&solve) {\n    \
    \    sort_query();\n        int l = 0, r = 0;\n        for(const auto &[nl, nr,\
    \ idx] : query) {\n            while(nl < l) add_l(--l);\n            while(r\
    \ < nr) add_r(r++);\n            while(l < nl) del_l(l++);\n            while(nr\
    \ < r) del_r(--r);\n            solve(idx);\n        }\n    }\n};\n\n}  // namespace\
    \ algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\n- Mo's algorithm\uFF0C\u30A2\
    \u30EB\u30B4\u30EA\u30BA\u30E0\u3068\u30C7\u30FC\u30BF\u69CB\u9020\u5927\u5168\
    \uFF0Chttps://take44444.github.io/Algorithm-Book/range/mo/main.html\uFF08\u53C2\
    \u71672023.5.3\uFF09\uFF0E\n- ageprocpp, Mo's algorithm\uFF08\u30AF\u30A8\u30EA\
    \u5E73\u65B9\u5206\u5272\uFF09\u306E\u8A71\uFF0CQiita, https://qiita.com/ageprocpp/items/34121c58e571ea8c4023\uFF08\
    \u53C2\u71672023.5.3\uFF09\uFF0E\n- ei1333, Mo's algorithm, ei1333\u306E\u65E5\
    \u8A18\uFF0CHatenaBlog, https://ei1333.hateblo.jp/entry/2017/09/11/211011\uFF08\
    \u53C2\u71672023.5.4\uFF09.\n- \u3059\u3068\u308C\u3093\u3058\u3083\u30FC\uFF0C\
    Mo's Algorithm\u306E\u30A4\u30E1\u30FC\u30B8\u3092\u8996\u899A\u7684\u306B\u7406\
    \u89E3\u3057\u305F\u3044\uFF0C\u5F92\u7136\uFF0CHatenaBlog, https://strangerxxx.hateblo.jp/entry/20230314/1678795200\uFF08\
    \u53C2\u71672023.5.4\uFF09.\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Others/mos_algorithm.hpp
  requiredBy: []
  timestamp: '2023-05-04 17:14:30+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Others/mos_algorithm.hpp
layout: document
redirect_from:
- /library/src/Others/mos_algorithm.hpp
- /library/src/Others/mos_algorithm.hpp.html
title: src/Others/mos_algorithm.hpp
---
