---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Others/mo_algorithm.hpp
    title: "Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\u5272\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/static_range_inversions_query
    links:
    - https://judge.yosupo.jp/problem/static_range_inversions_query
  bundledCode: "#line 1 \"test/yosupo-static_range_inversions_query.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\n\n\
    #include <iostream>\n#include <vector>\n\n#line 1 \"src/Others/mo_algorithm.hpp\"\
    \n\n\n\n/**\n * @brief Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\u5206\
    \u5272\uFF09\n * @docs docs/Others/mo_algorithm.md\n */\n\n#include <algorithm>\n\
    #include <cassert>\n#include <cmath>\n#include <tuple>\n#line 14 \"src/Others/mo_algorithm.hpp\"\
    \n\nnamespace algorithm {\n\n// Mo's Algorithm\uFF08\u30AF\u30A8\u30EA\u5E73\u65B9\
    \u5206\u5272\uFF09.\nclass Mo {\n    int m_len;                              \
    \            // m_len:=(\u533A\u9593\u306E\u9577\u3055).\n    int m_q;       \
    \                                     // m_q:=(\u30AF\u30A8\u30EA\u6570).\n  \
    \  std::vector<std::tuple<int, int, int> > m_queries;  // m_queries[i]:=(i\u756A\
    \u76EE\u306E\u533A\u9593\u30AF\u30A8\u30EA). tuple of (left, right, index).\n\n\
    \    void sort_query() {\n        const int width = std::sqrt(m_len);\n      \
    \  auto comp = [&width](const std::tuple<int, int, int> &a, const std::tuple<int,\
    \ int, int> &b) -> bool {\n            const auto &[al, ar, _] = a;\n        \
    \    const auto &[bl, br, __] = b;\n            int a_block = al / width, b_block\
    \ = bl / width;\n            if(a_block == b_block) return (a_block & 1 ? ar >\
    \ br : ar < br);\n            return a_block < b_block;\n        };\n        std::sort(m_queries.begin(),\
    \ m_queries.end(), comp);\n    }\n\npublic:\n    Mo() : Mo(0) {}\n    explicit\
    \ Mo(size_t n) : m_len(n), m_q(0) {}\n    explicit Mo(size_t n, size_t q) : Mo(n)\
    \ {\n        m_queries.reserve(q);\n    }\n\n    // \u533A\u9593[l,r)\u306B\u3064\
    \u3044\u3066\u306E\u30AF\u30A8\u30EA\u3092\u8FFD\u52A0\u3059\u308B\uFF0E\n   \
    \ void insert(int l, int r) {\n        assert(0 <= l and l < r and r <= m_len);\n\
    \        m_queries.emplace_back(l, r, m_q++);\n    }\n    // \u5404\u30AF\u30A8\
    \u30EA\u3092\u5B9F\u884C\u3059\u308B\uFF0EO(Q*logQ+\u03B1*(N+Q)*\u221AN).\n  \
    \  template <class F1, class F2, class F3>\n    void execute(const F1 &add, const\
    \ F2 &del, const F3 &solve) { execute(add, del, add, del, solve); }\n    template\
    \ <class F1, class F2, class F3, class F4, class F5>\n    void execute(const F1\
    \ &add_l, const F2 &del_l, const F3 &add_r, const F4 &del_r, const F5 &solve)\
    \ {\n        sort_query();\n        int l = 0, r = 0;\n        for(const auto\
    \ &[nl, nr, idx] : m_queries) {\n            while(nl < l) add_l(--l);\n     \
    \       while(r < nr) add_r(r++);\n            while(l < nl) del_l(l++);\n   \
    \         while(nr < r) del_r(--r);\n            solve(idx);\n        }\n    }\n\
    \    void reset() {\n        m_queries.clear();\n        m_q = 0;\n    }\n};\n\
    \n}  // namespace algorithm\n\n\n#line 7 \"test/yosupo-static_range_inversions_query.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &in : a) std::cin >> in;\n\n    algorithm::Mo mo(n);\n \
    \   for(int i = 0; i < q; ++i) {\n        int l, r;\n        std::cin >> l >>\
    \ r;\n        mo.insert(l, r);\n    }\n\n    std::vector<long long> ans(q);\n\
    \    long long tmp = 0;\n    std::vector<int> v;\n    v.reserve(n);\n    auto\
    \ add_l = [&](int i) -> void {\n        auto itr = std::lower_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp += itr - v.begin();\n        v.insert(itr, a[i]);\n\
    \    };\n    auto del_l = [&](int i) -> void {\n        auto itr = std::lower_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp -= itr - v.begin();\n        v.erase(itr);\n  \
    \  };\n    auto add_r = [&](int i) -> void {\n        auto itr = std::upper_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp += v.end() - itr;\n        v.insert(itr, a[i]);\n\
    \    };\n    auto del_r = [&](int i) -> void {\n        auto itr = std::upper_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp -= v.end() - itr;\n        v.erase(itr - 1);\n\
    \    };\n    auto solve = [&](int idx) -> void { ans[idx] = tmp; };\n    mo.execute(add_l,\
    \ del_l, add_r, del_r, solve);\n\n    for(const auto &out : ans) std::cout <<\
    \ out << std::endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/static_range_inversions_query\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../src/Others/mo_algorithm.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    std::vector<int>\
    \ a(n);\n    for(auto &in : a) std::cin >> in;\n\n    algorithm::Mo mo(n);\n \
    \   for(int i = 0; i < q; ++i) {\n        int l, r;\n        std::cin >> l >>\
    \ r;\n        mo.insert(l, r);\n    }\n\n    std::vector<long long> ans(q);\n\
    \    long long tmp = 0;\n    std::vector<int> v;\n    v.reserve(n);\n    auto\
    \ add_l = [&](int i) -> void {\n        auto itr = std::lower_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp += itr - v.begin();\n        v.insert(itr, a[i]);\n\
    \    };\n    auto del_l = [&](int i) -> void {\n        auto itr = std::lower_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp -= itr - v.begin();\n        v.erase(itr);\n  \
    \  };\n    auto add_r = [&](int i) -> void {\n        auto itr = std::upper_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp += v.end() - itr;\n        v.insert(itr, a[i]);\n\
    \    };\n    auto del_r = [&](int i) -> void {\n        auto itr = std::upper_bound(v.begin(),\
    \ v.end(), a[i]);\n        tmp -= v.end() - itr;\n        v.erase(itr - 1);\n\
    \    };\n    auto solve = [&](int idx) -> void { ans[idx] = tmp; };\n    mo.execute(add_l,\
    \ del_l, add_r, del_r, solve);\n\n    for(const auto &out : ans) std::cout <<\
    \ out << std::endl;\n}\n"
  dependsOn:
  - src/Others/mo_algorithm.hpp
  isVerificationFile: true
  path: test/yosupo-static_range_inversions_query.test.cpp
  requiredBy: []
  timestamp: '2024-05-21 14:02:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-static_range_inversions_query.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-static_range_inversions_query.test.cpp
- /verify/test/yosupo-static_range_inversions_query.test.cpp.html
title: test/yosupo-static_range_inversions_query.test.cpp
---
