---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/SegmentTree/dynamic_segment_tree.hpp
    title: "Dynamic Segment Tree\uFF08\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\
      \uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_range_sum
  bundledCode: "#line 1 \"test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp\"\
    \n#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\n\
    #include <iostream>\n\n#line 1 \"src/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n\n\n\n/**\n * @brief Dynamic Segment Tree\uFF08\u52D5\u7684\u30BB\u30B0\u30E1\
    \u30F3\u30C8\u6728\uFF09\n * @docs docs/DataStructure/SegmentTree/dynamic_segment_tree.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#line 12 \"src/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n#include <memory>\n#include <utility>\n\nnamespace algorithm {\n\n// Dynamic\
    \ Segment Tree\uFF08\u52D5\u7684\u30BB\u30B0\u30E1\u30F3\u30C8\u6728\uFF09.\n\
    template <typename S>\nclass DynamicSegTree {\npublic:\n    using value_type =\
    \ S;\n    using size_type = size_t;\n\nprivate:\n    struct Node;\n    using node_ptr\
    \ = std::unique_ptr<Node>;\n\n    struct Node {\n        size_type index;\n  \
    \      S value;\n        S product;\n        node_ptr left, right;\n        explicit\
    \ Node(size_type index_, const S &value_)\n            : index(index_), value(value_),\
    \ product(value_), left(nullptr), right(nullptr) {}\n    };\n\n    using Op =\
    \ std::function<S(const S &, const S &)>;\n\n    Op m_op;          // S m_op(S,S):=(\u4E8C\
    \u9805\u6F14\u7B97\u95A2\u6570).\n    S m_e;            // m_e:=(\u5358\u4F4D\u5143\
    ).\n    size_type m_sz;   // m_sz:=(\u8981\u7D20\u6570).\n    node_ptr m_root;\
    \  // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\n    void update(const\
    \ node_ptr &p) const {\n        assert(p);\n        const S &lhs = (p->left ?\
    \ p->left->product : identity());\n        const S &rhs = (p->right ? p->right->product\
    \ : identity());\n        p->product = m_op(m_op(lhs, p->value), rhs);\n    }\n\
    \    void set(node_ptr &p, size_type l, size_type r, size_type k, S a) {\n   \
    \     assert(0 <= l and l <= k and k < r and r <= size());\n        if(!p) {\n\
    \            p = std::make_unique<Node>(k, a);\n            return;\n        }\n\
    \        if(p->index == k) {\n            p->value = a;\n            update(p);\n\
    \            return;\n        }\n        size_type mid = (l + r) / 2;\n      \
    \  if(k < mid) {\n            if(p->index < k) std::swap(p->index, k), std::swap(p->value,\
    \ a);\n            set(p->left, l, mid, k, a);\n        } else {\n           \
    \ if(k < p->index) std::swap(k, p->index), std::swap(a, p->value);\n         \
    \   set(p->right, mid, r, k, a);\n        }\n        update(p);\n    }\n    S\
    \ get(const node_ptr &p, size_type l, size_type r, size_type k) const {\n    \
    \    assert(0 <= l and l <= k and k < r and r <= size());\n        if(!p) return\
    \ identity();\n        if(p->index == k) return p->value;\n        size_type mid\
    \ = (l + r) / 2;\n        if(k < mid) return get(p->left, l, mid, k);\n      \
    \  return get(p->right, mid, r, k);\n    }\n    S prod(const node_ptr &p, size_type\
    \ l, size_type r, size_type nl, size_type nr) const {\n        assert(0 <= l and\
    \ l <= r and r <= size());\n        assert(0 <= nl and nl <= nr and nr <= size());\n\
    \        if(!p or nr <= l or r <= nl) return identity();\n        if(nl <= l and\
    \ r <= nr) return p->product;\n        size_type mid = (l + r) / 2;\n        S\
    \ &&res = prod(p->left, l, mid, nl, nr);\n        if(nl <= p->index and p->index\
    \ < nr) res = m_op(res, p->value);\n        res = m_op(res, prod(p->right, mid,\
    \ r, nl, nr));\n        return res;\n    }\n    template <class Func>\n    size_type\
    \ most_right(const node_ptr &p, size_type l, size_type r, const Func &jud, size_type\
    \ nl, S &product) const {\n        assert(0 <= l and l <= r and r <= size());\n\
    \        assert(0 <= nl and nl <= size());\n        if(!p or r <= nl) return r;\n\
    \        if(nl <= l and jud(m_op(product, p->product))) {\n            product\
    \ = m_op(product, p->product);\n            return r;\n        }\n        size_type\
    \ mid = (l + r) / 2;\n        size_type res = most_right(p->left, l, mid, jud,\
    \ nl, product);\n        if(res != mid) return res;\n        if(nl <= p->index)\
    \ {\n            product = m_op(product, p->value);\n            if(!jud(product))\
    \ return p->index;\n        }\n        return most_right(p->right, mid, r, jud,\
    \ nl, product);\n    }\n    template <class Func>\n    size_type most_left(const\
    \ node_ptr &p, size_type l, size_type r, const Func &jud, size_type nr, S &product)\
    \ const {\n        assert(0 <= l and l <= r and r <= size());\n        assert(0\
    \ <= nr and nr <= size());\n        if(!p or nr <= l) return l;\n        if(r\
    \ <= nr and jud(m_op(p->product, product))) {\n            product = m_op(p->product,\
    \ product);\n            return l;\n        }\n        size_type mid = (l + r)\
    \ / 2;\n        size_type res = most_left(p->right, mid, r, jud, nr, product);\n\
    \        if(res != mid) return res;\n        if(p->index < nr) {\n           \
    \ product = m_op(p->value, product);\n            if(!jud(product)) return p->index\
    \ + 1;\n        }\n        return most_left(p->left, l, mid, jud, nr, product);\n\
    \    }\n    void reset(node_ptr &p, size_type l, size_type r, size_type nl, size_type\
    \ nr) {\n        assert(0 <= l and l <= r and r <= size());\n        assert(0\
    \ <= nl and nl <= nr and nr <= size());\n        if(!p or nr <= l or r <= nl)\
    \ return;\n        if(nl <= l and r <= nr) {\n            p.reset();\n       \
    \     return;\n        }\n        size_type mid = (l + r) / 2;\n        reset(p->left,\
    \ l, mid, nl, nr);\n        reset(p->right, mid, r, nl, nr);\n        if(nl <=\
    \ p->index and p->index < nr) p->value = identity();\n        if(!p->left and\
    \ !p->right and p->value == identity()) {\n            p.reset();\n          \
    \  return;\n        }\n        update(p);\n    }\n\npublic:\n    // constructor.\
    \ O(N).\n    DynamicSegTree(){};\n    explicit DynamicSegTree(const Op &op, const\
    \ S &e, size_type n)\n        : m_op(op), m_e(e), m_sz(n), m_root(nullptr) {}\n\
    \n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    size_type size() const\
    \ { return m_sz; }\n    // \u5358\u4F4D\u5143\u3092\u8FD4\u3059\uFF0E\n    S identity()\
    \ const { return m_e; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\
    \u304D\u63DB\u3048\u308B\uFF0EO(logN).\n    void set(size_type k, const S &a)\
    \ {\n        assert(0 <= k and k < size());\n        set(m_root, 0, size(), k,\
    \ a);\n    }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092\u8FD4\u3059\uFF0EO(logN).\n\
    \    S prod(size_type k) const {\n        assert(0 <= k and k < size());\n   \
    \     return get(m_root, 0, size(), k);\n    }\n    // \u533A\u9593[l,r)\u306E\
    \u8981\u7D20\u306E\u7DCF\u7A4D v[l]\u2022v[l+1]\u2022...\u2022v[r-1] \u3092\u6C42\
    \u3081\u308B\uFF0EO(logN).\n    S prod(size_type l, size_type r) const {\n   \
    \     assert(0 <= l and l <= r and r <= size());\n        return prod(m_root,\
    \ 0, size(), l, r);\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\u8981\u7D20\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\uFF0EO(1).\n    S prod_all() const { return (m_root\
    \ ? m_root->product : identity()); }\n    // jud(prod(l,-))==true \u3068\u306A\
    \u308B\u533A\u9593\u306E\u6700\u53F3\u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\
    \u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\u306B\u306F\
    \u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F jud(e)==true \u3067\u3042\
    \u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    size_type most_right(const Func &jud, int l) const {\n        assert(jud(identity()));\n\
    \        assert(0 <= l and l <= size());\n        S product = identity();\n  \
    \      return most_right(m_root, 0, size(), jud, l, product);\n    }\n    // jud(prod(-,r))==true\
    \ \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u5DE6\u4F4D\u5024\u3092\u4E8C\u5206\
    \u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\u3057\uFF0C\u8981\u7D20\u5217\
    \u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\u307E\u305F jud(e)==true\
    \ \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    template <class Func = std::function<bool(const\
    \ S &)> >\n    size_type most_left(const Func &jud, int r) const {\n        assert(jud(identity()));\n\
    \        assert(0 <= r and r <= size());\n        S product = identity();\n  \
    \      return most_left(m_root, 0, size(), jud, r, product);\n    }\n    void\
    \ reset() { m_root.reset(); }\n    void reset(size_type l, size_type r) {\n  \
    \      assert(0 <= l and l <= r and r <= size());\n        reset(m_root, 0, size(),\
    \ l, r);\n    }\n\n    friend std::ostream &operator<<(std::ostream &os, const\
    \ DynamicSegTree &segtree) {\n        os << \"[\";\n        bool first = true;\n\
    \        auto dfs = [&](auto self, const node_ptr &p) -> void {\n            if(!p)\
    \ return;\n            self(self, p->left);\n            os << (first ? \"\" :\
    \ \" \") << \"{\" << p->index << \", \" << p->value << \"}\";\n            first\
    \ = false;\n            self(self, p->right);\n        };\n        dfs(dfs, segtree.m_root);\n\
    \        os << \"]\";\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n#line 6 \"test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp\"\n\
    \nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using S\
    \ = long long;\n    constexpr S e = 0;\n    auto op = [](const S &lhs, const S\
    \ &rhs) -> S { return lhs + rhs; };\n    algorithm::DynamicSegTree<S> segtree(op,\
    \ e, n);\n\n    for(int i = 0; i < n; ++i) {\n        long long a;\n        std::cin\
    \ >> a;\n\n        segtree.set(i, a);\n    }\n\n    while(q--) {\n        int\
    \ t;\n        std::cin >> t;\n\n        if(t == 0) {\n            int p;\n   \
    \         long long x;\n            std::cin >> p >> x;\n\n            segtree.set(p,\
    \ segtree.prod(p) + x);\n        } else {\n            int l, r;\n           \
    \ std::cin >> l >> r;\n\n            std::cout << segtree.prod(l, r) << \"\\n\"\
    ;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_range_sum\"\n\
    \n#include <iostream>\n\n#include \"../src/DataStructure/SegmentTree/dynamic_segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ S = long long;\n    constexpr S e = 0;\n    auto op = [](const S &lhs, const\
    \ S &rhs) -> S { return lhs + rhs; };\n    algorithm::DynamicSegTree<S> segtree(op,\
    \ e, n);\n\n    for(int i = 0; i < n; ++i) {\n        long long a;\n        std::cin\
    \ >> a;\n\n        segtree.set(i, a);\n    }\n\n    while(q--) {\n        int\
    \ t;\n        std::cin >> t;\n\n        if(t == 0) {\n            int p;\n   \
    \         long long x;\n            std::cin >> p >> x;\n\n            segtree.set(p,\
    \ segtree.prod(p) + x);\n        } else {\n            int l, r;\n           \
    \ std::cin >> l >> r;\n\n            std::cout << segtree.prod(l, r) << \"\\n\"\
    ;\n        }\n    }\n}\n"
  dependsOn:
  - src/DataStructure/SegmentTree/dynamic_segment_tree.hpp
  isVerificationFile: true
  path: test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp
  requiredBy: []
  timestamp: '2024-06-17 00:08:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp
- /verify/test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp.html
title: test/yosupo-point_add_range_sum-dynamic_segment_tree.test.cpp
---