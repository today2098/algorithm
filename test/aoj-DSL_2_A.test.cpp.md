---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/segment_tree.hpp
    title: Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A
  bundledCode: "#line 1 \"test/aoj-DSL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#line 1 \"src/DataStructure/segment_tree.hpp\"\
    \n\n\n\n#line 5 \"src/DataStructure/segment_tree.hpp\"\n#include <cassert>\n#include\
    \ <functional>\n#include <vector>\n\nnamespace algorithm {\n\ntemplate <typename\
    \ S>\nclass SegmentTree {\n    using Func = std::function<S(const S &, const S\
    \ &)>;\n\n    Func m_op;              // S m_op(S,S):=(\u4E8C\u9805\u6F14\u7B97\
    \u95A2\u6570).\n    S m_e;                  // m_e:=(\u5358\u4F4D\u5143).\n  \
    \  int m_sz;               // m_sz:=(\u8981\u7D20\u6570).\n    int m_n;      \
    \          // m_n:=(\u8449\u306E\u6570).\n    std::vector<S> m_tree;  // m_tree[]:=(\u5B8C\
    \u5168\u4E8C\u5206\u6728). 1-based index.\n\npublic:\n    // constructor. O(N).\n\
    \    SegmentTree(){};\n    explicit SegmentTree(const Func &op, const S &e, size_t\
    \ n) : m_op(op), m_e(e), m_sz(n), m_n(1) {\n        while(m_n < size()) m_n <<=\
    \ 1;\n        m_tree.assign(2 * m_n, identity());\n    }\n    explicit SegmentTree(const\
    \ Func &op, const S &e, const std::vector<S> &v) : SegmentTree(op, e, v.size())\
    \ {\n        std::copy(v.begin(), v.end(), m_tree.begin() + m_n);\n        for(int\
    \ i = m_n - 1; i >= 1; --i) m_tree[i] = m_op(m_tree[i << 1], m_tree[i << 1 | 1]);\n\
    \    }\n\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0E\n    int size() const\
    \ { return m_sz; }\n    // \u5358\u4F4D\u5143\u3092\u8FD4\u3059\uFF0E\n    S identity()\
    \ const { return m_e; }\n    // k\u756A\u76EE\u306E\u8981\u7D20\u3092a\u306B\u7F6E\
    \u304D\u63DB\u3048\u308B\uFF0EO(logN).\n    void set(int k, const S &a) {\n  \
    \      assert(0 <= k and k < size());\n        k += m_n;\n        m_tree[k] =\
    \ a;\n        while(k >>= 1) m_tree[k] = m_op(m_tree[k << 1], m_tree[k << 1 |\
    \ 1]);\n    }\n    // \u4E00\u70B9\u53D6\u5F97\uFF0EO(1).\n    S prod(int k) const\
    \ {\n        assert(0 <= k and k < size());\n        return m_tree[k + m_n];\n\
    \    }\n    // \u533A\u9593[l,r)\u306E\u7DCF\u7A4D v[l]\u2022v[l+1]\u2022....\u2022\
    v[r-1] \u3092\u6C42\u3081\u308B\uFF0EO(logN).\n    S prod(int l, int r) const\
    \ {\n        assert(0 <= l and l <= r and r <= size());\n        S val_l = identity(),\
    \ val_r = identity();\n        l += m_n, r += m_n;\n        while(l < r) {\n \
    \           if(l & 1) val_l = m_op(val_l, m_tree[l++]);\n            if(r & 1)\
    \ val_r = m_op(m_tree[--r], val_r);\n            l >>= 1, r >>= 1;\n        }\n\
    \        return m_op(val_l, val_r);\n    }\n    // \u533A\u9593\u5168\u4F53\u306E\
    \u7DCF\u7A4D\u3092\u8FD4\u3059\uFF0EO(1).\n    S prod_all() const { return m_tree[1];\
    \ }\n    // jud(prod(l,-))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u53F3\
    \u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\u8981\u7D20\u5217\u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\
    \u307E\u305F jud(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    int\
    \ most_right(const std::function<bool(const S &)> &jud, int l) const {\n     \
    \   assert(jud(identity()) == true);\n        assert(0 <= l and l <= size());\n\
    \        if(l == size()) return size();\n        S val = identity();\n       \
    \ l += m_n;\n        do {\n            while(!(l & 1)) l >>= 1;\n            S\
    \ &&tmp = m_op(val, m_tree[l]);\n            if(!jud(tmp)) {\n               \
    \ while(l < m_n) {\n                    l <<= 1;\n                    S &&tmp2\
    \ = m_op(val, m_tree[l]);\n                    if(jud(tmp2)) val = tmp2, l++;\n\
    \                }\n                return l - m_n;\n            }\n         \
    \   val = tmp, l++;\n        } while((l & -l) != l);  // (x&-x)==x \u306E\u3068\
    \u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return size();\n \
    \   }\n    // jud(prod(-,r))==true \u3068\u306A\u308B\u533A\u9593\u306E\u6700\u5DE6\
    \u4F4D\u5024\u3092\u4E8C\u5206\u63A2\u7D22\u3059\u308B\uFF0E\n    // \u305F\u3060\
    \u3057\u8981\u7D20\u5217\u306B\u306F\u5358\u8ABF\u6027\u304C\u3042\u308A\uFF0C\
    \u307E\u305F jud(e)==true \u3067\u3042\u308B\u3053\u3068\uFF0EO(logN).\n    int\
    \ most_left(const std::function<bool(const S &)> &jud, int r) const {\n      \
    \  assert(jud(identity()) == true);\n        assert(0 <= r and r <= size());\n\
    \        if(r == 0) return 0;\n        S val = identity();\n        r += m_n;\n\
    \        do {\n            r--;\n            while(r > 1 and r & 1) r >>= 1;\n\
    \            S &&tmp = m_op(m_tree[r], val);\n            if(!jud(tmp)) {\n  \
    \              while(r < m_n) {\n                    r = (r << 1) | 1;\n     \
    \               S &&tmp2 = m_op(m_tree[r], val);\n                    if(jud(tmp2))\
    \ val = tmp2, r--;\n                }\n                return r - m_n + 1;\n \
    \           }\n            val = tmp;\n        } while((r & -r) != r);  // (x&-x)==x\
    \ \u306E\u3068\u304D\uFF0Cx\u306F2\u306E\u968E\u4E57\u6570\uFF0E\n        return\
    \ 0;\n    }\n    void reset() { std::fill(m_tree.begin(), m_tree.end(), identity());\
    \ }\n\n    friend std::ostream &operator<<(std::ostream &os, const SegmentTree\
    \ &segtree) {\n        int l = 1, r = 2;\n        while(l < 2 * segtree.m_n) {\n\
    \            os << (l == 1 ? \"[\" : \" \");\n            for(int i = l; i < r;\
    \ ++i) os << (i == l ? \"[\" : \" \") << segtree.m_tree[i];\n            os <<\
    \ \"]\";\n            l <<= 1, r <<= 1;\n        }\n        os << \"]\";\n   \
    \     return os;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 7 \"test/aoj-DSL_2_A.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ T = int;\n    const T e = (1 << 31) - 1;\n    auto op = [](T a, T b) -> T {\
    \ return std::min(a, b); };\n    algorithm::SegmentTree<T> segtree(op, e, n);\n\
    \    while(q--) {\n        int com;\n        int x;\n        int y;\n        std::cin\
    \ >> com >> x >> y;\n\n        if(com == 0) segtree.set(x, y);\n        else std::cout\
    \ << segtree.prod(x, y + 1) << std::endl;\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A\"\
    \n\n#include <algorithm>\n#include <iostream>\n\n#include \"../src/DataStructure/segment_tree.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    using\
    \ T = int;\n    const T e = (1 << 31) - 1;\n    auto op = [](T a, T b) -> T {\
    \ return std::min(a, b); };\n    algorithm::SegmentTree<T> segtree(op, e, n);\n\
    \    while(q--) {\n        int com;\n        int x;\n        int y;\n        std::cin\
    \ >> com >> x >> y;\n\n        if(com == 0) segtree.set(x, y);\n        else std::cout\
    \ << segtree.prod(x, y + 1) << std::endl;\n    }\n}\n"
  dependsOn:
  - src/DataStructure/segment_tree.hpp
  isVerificationFile: true
  path: test/aoj-DSL_2_A.test.cpp
  requiredBy: []
  timestamp: '2023-08-28 13:53:45+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_2_A.test.cpp
- /verify/test/aoj-DSL_2_A.test.cpp.html
title: test/aoj-DSL_2_A.test.cpp
---