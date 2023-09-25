---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/UnionFind/potentialized_union_find.hpp
    title: "\u91CD\u307F\u4ED8\u304DUnion-Find"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B
  bundledCode: "#line 1 \"test/aoj-DSL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n\n#include <iostream>\n\n#line 1 \"src/DataStructure/UnionFind/potentialized_union_find.hpp\"\
    \n\n\n\n/**\n * @brief \u91CD\u307F\u4ED8\u304DUnion-Find\n * @docs docs/DataStructure/UnionFind/potentialized_union_find.md\n\
    \ */\n\n#include <algorithm>\n#include <cassert>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u91CD\u307F\u4ED8\u304DUnion-Find\uFF0E\
    \ntemplate <typename T>  // T:Type of potential.\nclass PotentializedUnionFind\
    \ {\n    int m_vn;  // m_vn:=(\u8981\u7D20\u6570).\n    int m_gn;  // m_gn:=(\u30B0\
    \u30EB\u30FC\u30D7\u6570).\n    // m_par[x]:=(\u8981\u7D20x\u306E\u89AA\u756A\u53F7\
    ). 0\u672A\u6E80\u306E\u5834\u5408\uFF0Cx\u306F\u6839\u3067\u3042\u308A\uFF0C\u5024\
    \u306E\u7D76\u5BFE\u5024\u306F\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\
    \u30B5\u30A4\u30BA\u3092\u8868\u3059\uFF0E\n    std::vector<int> m_par;\n    std::vector<T>\
    \ m_p;  // m_p[x]:=(\u8981\u7D20x\u306E\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB).\n\
    \npublic:\n    PotentializedUnionFind() : PotentializedUnionFind(0) {}\n    explicit\
    \ PotentializedUnionFind(size_t vn) : m_vn(vn), m_gn(vn), m_par(vn, -1), m_p(vn,\
    \ 0) {}\n\n    // \u8981\u7D20\u306E\u7DCF\u6570\u3092\u8FD4\u3059\uFF0E\n   \
    \ int vn() const { return m_vn; };\n    // \u30B0\u30EB\u30FC\u30D7\u6570\u3092\
    \u8FD4\u3059\uFF0E\n    int gn() const { return m_gn; };\n    // \u8981\u7D20\
    x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\uFF08\u6839\u4ED8\u304D\u6728\
    \uFF09\u306E\u6839\u756A\u53F7\u3092\u8FD4\u3059\uFF0EO(\u03B1(N)).\n    int root(int\
    \ x) {\n        assert(0 <= x and x < vn());\n        if(m_par[x] < 0) return\
    \ x;\n        int res = root(m_par[x]);  // \u7D4C\u8DEF\u5727\u7E2E\uFF0E\n \
    \       m_p[x] += m_p[m_par[x]];\n        return m_par[x] = res;\n    }\n    //\
    \ \u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u306E\u30B5\u30A4\
    \u30BA\u3092\u8FD4\u3059\uFF0E\n    int size(int x) {\n        assert(0 <= x and\
    \ x < vn());\n        return -m_par[root(x)];\n    }\n    // \u8981\u7D20x\u306E\
    \u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\u8FD4\u3059\uFF0E\n    T potential(int\
    \ x) {\n        assert(0 <= x and x < vn());\n        root(x);\n        return\
    \ m_p[x];\n    }\n    // \u8981\u7D20x, y\u304C\u540C\u3058\u30B0\u30EB\u30FC\u30D7\
    \u306B\u5C5E\u3059\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0E\n    bool is_same(int\
    \ x, int y) {\n        assert(0 <= x and x < vn());\n        assert(0 <= y and\
    \ y < vn());\n        return root(x) == root(y);\n    }\n    // \u8981\u7D20x\u306B\
    \u5BFE\u3059\u308By\u306E\u76F8\u5BFE\u30DD\u30C6\u30F3\u30B7\u30E3\u30EB\u3092\
    \u8FD4\u3059\uFF0E\n    T difference(int x, int y) {\n        assert(0 <= x and\
    \ x < vn());\n        assert(0 <= y and y < vn());\n        return potential(y)\
    \ - potential(x);\n    }\n    // difference(x,y)==d \u3068\u306A\u308B\u3088\u3046\
    \u306B\uFF0C\u8981\u7D20x\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\
    \u8981\u7D20y\u304C\u5C5E\u3059\u308B\u30B0\u30EB\u30FC\u30D7\u3068\u3092\u4F75\
    \u5408\u3059\u308B\uFF0E\n    bool unite(int x, int y, T d) {\n        assert(0\
    \ <= x and x < vn());\n        assert(0 <= y and y < vn());\n        d = d + potential(x)\
    \ - potential(y);\n        x = root(x), y = root(y);\n        if(x == y) return\
    \ false;  // Do nothing.\n        if(size(x) < size(y)) {   // Merge technique\
    \ (union by size).\n            std::swap(x, y);\n            d = -d;\n      \
    \  }\n        m_par[x] += m_par[y];\n        m_par[y] = x;\n        m_p[y] = d;\n\
    \        m_gn--;\n        return true;\n    }\n    void reset() {\n        m_gn\
    \ = vn();\n        std::fill(m_par.begin(), m_par.end(), -1);\n        std::fill(m_p.begin(),\
    \ m_p.end(), 0);\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"test/aoj-DSL_1_B.test.cpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::PotentializedUnionFind<int>\
    \ uf(n);\n    while(q--) {\n        int t;\n        std::cin >> t;\n\n       \
    \ if(t == 0) {\n            int x, y;\n            int z;\n            std::cin\
    \ >> x >> y >> z;\n\n            uf.unite(x, y, z);\n        } else {\n      \
    \      int x, y;\n            std::cin >> x >> y;\n\n            if(uf.is_same(x,\
    \ y)) std::cout << uf.difference(x, y) << std::endl;\n            else std::cout\
    \ << '?' << std::endl;\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_1_B\"\
    \n\n#include <iostream>\n\n#include \"../src/DataStructure/UnionFind/potentialized_union_find.hpp\"\
    \n\nint main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::PotentializedUnionFind<int>\
    \ uf(n);\n    while(q--) {\n        int t;\n        std::cin >> t;\n\n       \
    \ if(t == 0) {\n            int x, y;\n            int z;\n            std::cin\
    \ >> x >> y >> z;\n\n            uf.unite(x, y, z);\n        } else {\n      \
    \      int x, y;\n            std::cin >> x >> y;\n\n            if(uf.is_same(x,\
    \ y)) std::cout << uf.difference(x, y) << std::endl;\n            else std::cout\
    \ << '?' << std::endl;\n        }\n    }\n}\n"
  dependsOn:
  - src/DataStructure/UnionFind/potentialized_union_find.hpp
  isVerificationFile: true
  path: test/aoj-DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 12:03:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_1_B.test.cpp
- /verify/test/aoj-DSL_1_B.test.cpp.html
title: test/aoj-DSL_1_B.test.cpp
---