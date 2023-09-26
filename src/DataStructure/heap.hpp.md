---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-ALDS1_9_C.test.cpp
    title: test/aoj-ALDS1_9_C.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/heap.md
    document_title: "\u4E8C\u5206\u30D2\u30FC\u30D7"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/heap.hpp\"\n\n\n\n/**\n * @brief \u4E8C\
    \u5206\u30D2\u30FC\u30D7\n * @docs docs/DataStructure/heap.md\n */\n\n#include\
    \ <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\n\
    namespace algorithm {\n\n// \u4E8C\u5206\u30D2\u30FC\u30D7\uFF0E\ntemplate <typename\
    \ T>\nclass Heap {\n    using Comp = std::function<bool(const T &, const T &)>;\n\
    \n    Comp m_comp;            // bool m_comp(T,T):=(\u6BD4\u8F03\u6F14\u7B97\u5B50\
    ).\n    std::vector<T> m_tree;  // m_tree[]:=(\u4E8C\u5206\u6728). 1-based index.\n\
    \n    void shift_up(int k) {\n        while(true) {\n            if(k == 1) break;\n\
    \            int par = k >> 1;\n            if(m_comp(m_tree[par], m_tree[k]))\
    \ break;\n            std::swap(m_tree[par], m_tree[k]);\n            k = par;\n\
    \        }\n    }\n    void shift_down(int k) {\n        while(true) {\n     \
    \       int l = k << 1, r = k << 1 | 1;\n            if(size() < l) break;\n \
    \           if(size() < r or m_comp(m_tree[l], m_tree[r])) {\n               \
    \ if(m_comp(m_tree[k], m_tree[l])) break;\n                std::swap(m_tree[k],\
    \ m_tree[l]);\n                k = l;\n            } else {\n                if(m_comp(m_tree[k],\
    \ m_tree[r])) break;\n                std::swap(m_tree[k], m_tree[r]);\n     \
    \           k = r;\n            }\n        }\n    }\n    void heap_sort() {\n\
    \        for(int i = 2; i <= size(); ++i) shift_up(i);\n    }\n\npublic:\n   \
    \ // constructor. O(N*logN).\n    Heap() : Heap([](const T &a, const T &b) ->\
    \ bool { return a > b; }, std::vector<T>(0)) {}\n    explicit Heap(const Comp\
    \ &comp) : Heap(comp, std::vector<T>(0)) {}\n    explicit Heap(const std::vector<T>\
    \ &v) : Heap([](const T &a, const T &b) -> bool { return a > b; }, v) {}\n   \
    \ explicit Heap(const Comp &comp, const std::vector<T> &v) : m_comp(comp), m_tree(v.size()\
    \ + 1) {\n        if(size() > 0) {\n            std::copy(v.begin(), v.end(),\
    \ m_tree.begin() + 1);\n            heap_sort();\n        }\n    }\n    ~Heap()\
    \ {\n        std::vector<T>().swap(m_tree);\n    }\n\n    // \u8981\u7D20\u304C\
    \u7A7A\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const { return\
    \ size() == 0; }\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ int size() const { return m_tree.size() - 1; }\n    // \u8981\u7D20\u53C2\u7167\
    \uFF0EO(1).\n    T top() const {\n        assert(!empty());\n        return m_tree[1];\n\
    \    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const T &a)\
    \ {\n        m_tree.push_back(a);\n        shift_up(size());\n    }\n    // \u8981\
    \u7D20\u524A\u9664\uFF0EO(logN).\n    void pop() {\n        assert(!empty());\n\
    \        m_tree[1] = m_tree[size()];\n        m_tree.pop_back();\n        if(!empty())\
    \ shift_down(1);\n    }\n    // \u30D2\u30FC\u30D7\u30BD\u30FC\u30C8\uFF0EO(N*logN).\n\
    \    void heap_sort(const Comp &comp) {\n        m_comp = comp;\n        heap_sort();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_HEAP_HPP\n#define ALGORITHM_HEAP_HPP 1\n\n/**\n * @brief\
    \ \u4E8C\u5206\u30D2\u30FC\u30D7\n * @docs docs/DataStructure/heap.md\n */\n\n\
    #include <cassert>\n#include <functional>\n#include <utility>\n#include <vector>\n\
    \nnamespace algorithm {\n\n// \u4E8C\u5206\u30D2\u30FC\u30D7\uFF0E\ntemplate <typename\
    \ T>\nclass Heap {\n    using Comp = std::function<bool(const T &, const T &)>;\n\
    \n    Comp m_comp;            // bool m_comp(T,T):=(\u6BD4\u8F03\u6F14\u7B97\u5B50\
    ).\n    std::vector<T> m_tree;  // m_tree[]:=(\u4E8C\u5206\u6728). 1-based index.\n\
    \n    void shift_up(int k) {\n        while(true) {\n            if(k == 1) break;\n\
    \            int par = k >> 1;\n            if(m_comp(m_tree[par], m_tree[k]))\
    \ break;\n            std::swap(m_tree[par], m_tree[k]);\n            k = par;\n\
    \        }\n    }\n    void shift_down(int k) {\n        while(true) {\n     \
    \       int l = k << 1, r = k << 1 | 1;\n            if(size() < l) break;\n \
    \           if(size() < r or m_comp(m_tree[l], m_tree[r])) {\n               \
    \ if(m_comp(m_tree[k], m_tree[l])) break;\n                std::swap(m_tree[k],\
    \ m_tree[l]);\n                k = l;\n            } else {\n                if(m_comp(m_tree[k],\
    \ m_tree[r])) break;\n                std::swap(m_tree[k], m_tree[r]);\n     \
    \           k = r;\n            }\n        }\n    }\n    void heap_sort() {\n\
    \        for(int i = 2; i <= size(); ++i) shift_up(i);\n    }\n\npublic:\n   \
    \ // constructor. O(N*logN).\n    Heap() : Heap([](const T &a, const T &b) ->\
    \ bool { return a > b; }, std::vector<T>(0)) {}\n    explicit Heap(const Comp\
    \ &comp) : Heap(comp, std::vector<T>(0)) {}\n    explicit Heap(const std::vector<T>\
    \ &v) : Heap([](const T &a, const T &b) -> bool { return a > b; }, v) {}\n   \
    \ explicit Heap(const Comp &comp, const std::vector<T> &v) : m_comp(comp), m_tree(v.size()\
    \ + 1) {\n        if(size() > 0) {\n            std::copy(v.begin(), v.end(),\
    \ m_tree.begin() + 1);\n            heap_sort();\n        }\n    }\n    ~Heap()\
    \ {\n        std::vector<T>().swap(m_tree);\n    }\n\n    // \u8981\u7D20\u304C\
    \u7A7A\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const { return\
    \ size() == 0; }\n    // \u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n   \
    \ int size() const { return m_tree.size() - 1; }\n    // \u8981\u7D20\u53C2\u7167\
    \uFF0EO(1).\n    T top() const {\n        assert(!empty());\n        return m_tree[1];\n\
    \    }\n    // \u8981\u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const T &a)\
    \ {\n        m_tree.push_back(a);\n        shift_up(size());\n    }\n    // \u8981\
    \u7D20\u524A\u9664\uFF0EO(logN).\n    void pop() {\n        assert(!empty());\n\
    \        m_tree[1] = m_tree[size()];\n        m_tree.pop_back();\n        if(!empty())\
    \ shift_down(1);\n    }\n    // \u30D2\u30FC\u30D7\u30BD\u30FC\u30C8\uFF0EO(N*logN).\n\
    \    void heap_sort(const Comp &comp) {\n        m_comp = comp;\n        heap_sort();\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/heap.hpp
  requiredBy: []
  timestamp: '2023-09-26 16:38:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-ALDS1_9_C.test.cpp
documentation_of: src/DataStructure/heap.hpp
layout: document
redirect_from:
- /library/src/DataStructure/heap.hpp
- /library/src/DataStructure/heap.hpp.html
title: "\u4E8C\u5206\u30D2\u30FC\u30D7"
---
## 概要

二分木を用いたヒープ．
基本的な機能は 'std::priority_queue' と同じ．

要素の最大値（最小値）の取得を $\mathcal{O}(1)$ ，要素の挿入を $\mathcal{O}(\log N)$ ，最大値（最小値）の要素の削除を $\mathcal{O}(\log N)$ で行う． 

実装では二分木を用いて要素を管理しており，親の要素は子の要素より常に大きい（小さい）か等しいようにしている．


## 参考文献

1. "ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/ヒープ>.
1. "二分ヒープ". Wikipedia. <https://ja.wikipedia.org/wiki/二分ヒープ>.
