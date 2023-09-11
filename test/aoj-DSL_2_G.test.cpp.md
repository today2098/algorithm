---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree/lazy_segment_tree.hpp
    title: "Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
      \u30C8\u6728\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G
  bundledCode: "#line 1 \"test/aoj-DSL_2_G.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\
    \n\n#include <iostream>\n#include <vector>\n\n#line 1 \"src/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n/**\n * @brief Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\uFF09\n * @docs docs/DataStructure/SegmentTree/lazy_segment_tree.md\n\
    \ */\n\n#ifndef ALGORITHM_LAZY_SEGMENT_TREE_HPP\n#define ALGORITHM_LAZY_SEGMENT_TREE_HPP\
    \ 1\n\n#include <algorithm>\n#include <cassert>\n#include <functional>\n#line\
    \ 13 \"src/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\n\nnamespace algorithm\
    \ {\n\n// Lazy Segment Tree\uFF08\u9045\u5EF6\u8A55\u4FA1\u30BB\u30B0\u30E1\u30F3\
    \u30C8\u6728\uFF09.\ntemplate <class S, class F>  // S:\u30E2\u30CE\u30A4\u30C9\
    \u306E\u578B, F:\u5199\u50CF\u306E\u578B.\nclass LazySegTree {\n    using FuncO\
    \ = std::function<S(const S &, const S &)>;\n    using FuncM = std::function<S(const\
    \ F &, const S &)>;\n    using FuncC = std::function<F(const F &, const F &)>;\n\
    \n    FuncO m_op;             // S m_op(S,S):=(\u4E8C\u9805\u6F14\u7B97\u95A2\u6570\
    ). S\xD7S\u2192S\u3092\u8A08\u7B97\u3059\u308B\uFF0E\n    FuncM m_mapping;   \
    \     // S m_mapping(F f,S x):=(\u5199\u50CF). f(x)\u3092\u8FD4\u3059\uFF0E\n\
    \    FuncC m_composition;    // F m_composition(F f,F g):=(\u5199\u50CF\u306E\u5408\
    \u6210). f\u2218g\u3092\u8FD4\u3059\uFF0E\n    S m_e;                  // m_e:=(\u5358\
    \u4F4D\u5143).\n    F m_id;                 // m_id:=(\u6052\u7B49\u5199\u50CF\
    ).\n    int m_sz;               // m_sz:=(\u8981\u7D20\u6570).\n    int m_n; \
    \               // m_n:=(\u4E8C\u5206\u6728\u306E\u8449\u6570).\n    int m_depth;\
    \            // m_depth:=(\u4E8C\u5206\u6728\u306E\u6DF1\u3055).\n    std::vector<S>\
    \ m_tree;  // m_tree(2n)[]:=(\u5B8C\u5168\u4E8C\u5206\u6728). 1-based index.\n\
    \    std::vector<F> m_lazy;  // m_lazy(n)[k]:=(m_tree[k]\u306E\u5B50 (m_tree[2k],\
    \ m_tree[2k+1]) \u306B\u5BFE\u3059\u308B\u9045\u5EF6\u8A55\u4FA1).\n\n    void\
    \ apply0(int k, const F &f) {\n        assert(1 <= k and k < 2 * m_n);\n     \
    \   m_tree[k] = m_mapping(f, m_tree[k]);\n        if(k < m_n) m_lazy[k] = m_composition(f,\
    \ m_lazy[k]);\n    }\n    void push(int k) {\n        assert(1 <= k and k < m_n);\n\
    \        apply0(k << 1, m_lazy[k]);\n        apply0(k << 1 | 1, m_lazy[k]);\n\
    \        m_lazy[k] = identity_mapping();\n    }\n    void update(int k) {\n  \
    \      assert(1 <= k and k < m_n);\n        m_tree[k] = m_op(m_tree[k << 1], m_tree[k\
    \ << 1 | 1]);\n    }\n\npublic:\n    // constructor. O(N).\n    LazySegTree()\
    \ {}\n    explicit LazySegTree(const FuncO &op, const FuncM &mapping, const FuncC\
    \ &composition, const S &e, const F &id, size_t n)\n        : m_op(op), m_mapping(mapping),\
    \ m_composition(composition), m_e(e), m_id(id), m_sz(n), m_n(1), m_depth(0) {\n\
    \        while(m_n < size()) m_n <<= 1, m_depth++;\n        m_tree.assign(2 *\
    \ m_n, identity());\n        m_lazy.assign(m_n, identity_mapping());\n    }\n\
    \    explicit LazySegTree(const FuncO &op, const FuncM &mapping, const FuncC &composition,\
    \ const S &e, const F &id, const std::vector<S> &v)\n        : LazySegTree(op,\
    \ mapping, composition, e, id, v.size()) {\n        std::copy(v.begin(), v.end(),\
    \ m_tree.begin() + m_n);\n        for(int i = m_n - 1; i >= 1; --i) update(i);\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u30E2\u30CE\u30A4\u30C9\u306E\u5358\u4F4D\u5143\u3092\
    \u8FD4\u3059\uFF0E\n    S identity() const { return m_e; }\n    // \u6052\u7B49\
    \u5199\u50CF\u3092\u8FD4\u3059\uFF0E\n    F identity_mapping() const { return\
    \ m_id; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\u304D\u63DB\
    \u3048\u308B\uFF0EO(logN).\n    void set(int k, const S &a) {\n        assert(0\
    \ <= k and k < size());\n        k += m_n;\n        for(int i = m_depth; i >=\
    \ 1; --i) push(k >> i);\n        m_tree[k] = a;\n        for(int i = 1; i <= m_depth;\
    \ ++i) update(k >> i);\n    }\n    // \u533A\u9593[l,-)\u306E\u8981\u7D20\u3092\
    v[]\u306B\u7F6E\u304D\u63DB\u3048\u308B\uFF0EO(N).\n    void set(int l, const\
    \ std::vector<S> &v) {\n        assert(0 <= l and l + (int)v.size() <= size());\n\
    \        if(v.size() == 0) return;\n        l += m_n;\n        int r = l + (int)v.size();\n\
    \        for(int i = m_depth; i >= 1; --i) {\n            for(int j = l >> i,\
    \ end = (r - 1) >> i; j <= end; ++j) push(j);\n        }\n        std::copy(v.begin(),\
    \ v.end(), m_tree.begin() + l);\n        for(int i = 1; i <= m_depth; ++i) {\n\
    \            for(int j = l >> i, end = (r - 1) >> i; j <= end; ++j) update(j);\n\
    \        }\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u5199\u50CFf\u3092\
    \u7528\u3044\u3066\u66F4\u65B0\u3059\u308B\uFF0EO(logN).\n    void apply(int k,\
    \ const F &f) {\n        assert(0 <= k and k < size());\n        k += m_n;\n \
    \       for(int i = m_depth; i >= 1; --i) push(k >> i);\n        m_tree[k] = m_mapping(f,\
    \ m_tree[k]);\n        for(int i = 1; i <= m_depth; ++i) update(k >> i);\n   \
    \ }\n    // \u533A\u9593[l,r)\u3092\u5199\u50CFf\u3092\u7528\u3044\u3066\u66F4\
    \u65B0\u3059\u308B\uFF0EO(logN).\n    void apply(int l, int r, const F &f) {\n\
    \        assert(0 <= l and l <= r and r <= size());\n        if(l == r) return;\n\
    \        l += m_n, r += m_n;\n        for(int i = m_depth; i >= 1; --i) {\n  \
    \          if((l >> i) << i != l) push(l >> i);\n            if((r >> i) << i\
    \ != r) push((r - 1) >> i);\n        }\n        for(int l2 = l, r2 = r; l2 < r2;\
    \ l2 >>= 1, r2 >>= 1) {\n            if(l2 & 1) apply0(l2++, f);\n           \
    \ if(r2 & 1) apply0(--r2, f);\n        }\n        for(int i = 1; i <= m_depth;\
    \ ++i) {\n            if((l >> i) << i != l) update(l >> i);\n            if((r\
    \ >> i) << i != r) update((r - 1) >> i);\n        }\n    }\n    // \u4E00\u70B9\
    \u53D6\u5F97\uFF0EO(logN).\n    S prod(int k) {\n        assert(0 <= k and k <\
    \ size());\n        k += m_n;\n        for(int i = m_depth; i >= 1; --i) push(k\
    \ >> i);\n        return m_tree[k];\n    }\n    // \u533A\u9593[l,r)\u306E\u7DCF\
    \u7A4D v[l]\u2022v[l+1]\u2022....\u2022v[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n\
    \    S prod(int l, int r) {\n        assert(0 <= l and l <= r and r <= size());\n\
    \        if(l == r) return identity();\n        l += m_n, r += m_n;\n        for(int\
    \ i = m_depth; i >= 1; --i) {\n            if((l >> i) << i != l) push(l >> i);\n\
    \            if((r >> i) << i != r) push((r - 1) >> i);\n        }\n        S\
    \ val_l = identity(), val_r = identity();\n        for(; l < r; l >>= 1, r >>=\
    \ 1) {\n            if(l & 1) val_l = m_op(val_l, m_tree[l++]);\n            if(r\
    \ & 1) val_r = m_op(m_tree[--r], val_r);\n        }\n        return m_op(val_l,\
    \ val_r);\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u7DCF\u7A4D\u3092\u8FD4\
    \u3059\uFF0EO(1).\n    S prod_all() const { return m_tree[1]; }\n    // jud(prod(l,-))=true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\u8981\u7D20\u5217\u306B\
    \u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F jud(e)=true \u3067\
    \u3042\u308B\u3053\u3068\uFF0EO(logN).\n    int most_right(const std::function<bool(const\
    \ S &)> &jud, int l) const {\n        assert(jud(identity()));\n        assert(0\
    \ <= l and l <= size());\n        if(l == size()) return size();\n        l +=\
    \ m_n;\n        for(int i = m_depth; i >= 1; --i) push(l >> i);\n        S val\
    \ = identity();\n        do {\n            while(!(l & 1)) l >>= 1;\n        \
    \    S &&tmp = m_op(val, m_tree[l]);\n            if(!jud(tmp)) {\n          \
    \      while(l < m_n) {\n                    push(l);\n                    l <<=\
    \ 1;\n                    S &&tmp2 = m_op(val, m_tree[l]);\n                 \
    \   if(jud(tmp2)) val = tmp2, l++;\n                }\n                return\
    \ l - m_n;\n            }\n            val = tmp, l++;\n        } while((l & -l)\
    \ != l);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\
    \uFF0E\n        return size();\n    }\n    // jud(prod(-,r))=true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\u8981\u7D20\u5217\u306B\u306F\u5358\
    \u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F jud(e)=true \u3067\u3042\u308B\
    \u3053\u3068\uFF0EO(logN).\n    int most_left(const std::function<bool(const S\
    \ &)> &jud, int r) const {\n        assert(jud(identity()));\n        assert(0\
    \ <= r and r <= size());\n        if(r == 0) return 0;\n        r += m_n;\n  \
    \      for(int i = m_depth; i >= 1; --i) push((r - 1) >> i);\n        S val =\
    \ identity();\n        do {\n            r--;\n            while(r > 1 and r &\
    \ 1) r >>= 1;\n            S &&tmp = m_op(m_tree[r], val);\n            if(!jud(tmp))\
    \ {\n                while(r < m_n) {\n                    push(r);\n        \
    \            r = r << 1 | 1;\n                    S &&tmp2 = m_op(m_tree[r], val);\n\
    \                    if(jud(tmp2)) val = tmp2, r--;\n                }\n     \
    \           return r - m_n + 1;\n            }\n            val = tmp;\n     \
    \   } while((r & -r) != r);  // (x&-x)==x \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\
    \u968E\u4E57\u6570\uFF0E\n        return 0;\n    }\n    void reset() {\n     \
    \   std::fill(m_tree.begin(), m_tree.end(), identity());\n        std::fill(m_lazy.begin(),\
    \ m_lazy.end(), identity_mapping());\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n#line 7 \"test/aoj-DSL_2_G.test.cpp\"\n\nint main() {\n    int n;\n\
    \    int q;\n    std::cin >> n >> q;\n\n    using S = struct {\n        long long\
    \ val;\n        int size;\n    };\n    using F = long long;\n    constexpr S e\
    \ = (S){0, 0};\n    constexpr F id = 0;\n    auto op = [&](const S &l, const S\
    \ &r) -> S { return (S){l.val + r.val, l.size + r.size}; };\n    auto mapping\
    \ = [&](const F &f, const S &x) -> S { return (S){x.val + f * x.size, x.size};\
    \ };\n    auto composition = [&](const F &f, const F &g) -> F { return f + g;\
    \ };\n    algorithm::LazySegTree<S, F> segtree(op, mapping, composition, e, id,\
    \ std::vector<S>(n, (S){0, 1}));\n\n    while(q--) {\n        int type;\n    \
    \    std::cin >> type;\n\n        if(type == 0) {\n            int s, t;\n   \
    \         long long x;\n            std::cin >> s >> t >> x;\n            s--;\n\
    \n            segtree.apply(s, t, x);\n        } else {\n            int s, t;\n\
    \            std::cin >> s >> t;\n            s--;\n\n            std::cout <<\
    \ segtree.prod(s, t).val << \"\\n\";\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_G\"\
    \n\n#include <iostream>\n#include <vector>\n\n#include \"../src/DataStructure/SegmentTree/lazy_segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = struct {\n        long long val;\n        int size;\n    };\n    using F\
    \ = long long;\n    constexpr S e = (S){0, 0};\n    constexpr F id = 0;\n    auto\
    \ op = [&](const S &l, const S &r) -> S { return (S){l.val + r.val, l.size + r.size};\
    \ };\n    auto mapping = [&](const F &f, const S &x) -> S { return (S){x.val +\
    \ f * x.size, x.size}; };\n    auto composition = [&](const F &f, const F &g)\
    \ -> F { return f + g; };\n    algorithm::LazySegTree<S, F> segtree(op, mapping,\
    \ composition, e, id, std::vector<S>(n, (S){0, 1}));\n\n    while(q--) {\n   \
    \     int type;\n        std::cin >> type;\n\n        if(type == 0) {\n      \
    \      int s, t;\n            long long x;\n            std::cin >> s >> t >>\
    \ x;\n            s--;\n\n            segtree.apply(s, t, x);\n        } else\
    \ {\n            int s, t;\n            std::cin >> s >> t;\n            s--;\n\
    \n            std::cout << segtree.prod(s, t).val << \"\\n\";\n        }\n   \
    \ }\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree/lazy_segment_tree.hpp
  isVerificationFile: true
  path: test/aoj-DSL_2_G.test.cpp
  requiredBy: []
  timestamp: '2023-09-10 12:13:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_2_G.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_2_G.test.cpp
- /verify/test/aoj-DSL_2_G.test.cpp.html
title: test/aoj-DSL_2_G.test.cpp
---