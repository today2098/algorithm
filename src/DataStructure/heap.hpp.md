---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/DataStructure/heap.hpp\"\n\n\n\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\
    \u5206\u30D2\u30FC\u30D7\uFF0E\ntemplate <typename T>\nclass Heap {\n    using\
    \ F = std::function<bool(T &, T &)>;\n\n    F m_comp;               // bool m_comp(T&,T&):=(\u6BD4\
    \u8F03\u6F14\u7B97\u95A2\u6570).\n    int m_sz;               // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<T> m_tree;  // m_tree[]:=(\u4E8C\u5206\u6728).\
    \ 1-based index.\n\n    int shift_up(int k) {\n        assert(1 <= k and k <=\
    \ size());\n        if(k == 1) return 1;\n        int par = k / 2;\n        if(m_comp(m_tree[par],\
    \ m_tree[k])) return k;\n        std::swap(m_tree[par], m_tree[k]);\n        return\
    \ par;\n    }\n    void all_shift_up(int k) {\n        while(1) {\n          \
    \  int next = shift_up(k);\n            if(next == k) return;\n            k =\
    \ next;\n        }\n    }\n    int shift_down(int k) {\n        assert(1 <= k\
    \ and k <= size());\n        if(k > size() / 2) return k;\n        int l = 2 *\
    \ k, r = 2 * k + 1;\n        if(r > size() or m_comp(m_tree[l], m_tree[r])) {\n\
    \            if(m_comp(m_tree[k], m_tree[l])) return k;\n            std::swap(m_tree[k],\
    \ m_tree[l]);\n            return l;\n        } else {\n            if(m_comp(m_tree[k],\
    \ m_tree[r])) return k;\n            std::swap(m_tree[k], m_tree[r]);\n      \
    \      return r;\n        }\n    }\n    void all_shift_down(int k) {\n       \
    \ while(1) {\n            int next = shift_down(k);\n            if(next == k)\
    \ return;\n            k = next;\n        }\n    }\n    void heap_sort() {\n \
    \       int k = size() / 2;\n        for(int i = k; i >= 1; --i) all_shift_down(i);\n\
    \    }\n\npublic:\n    // constructor. O(N*logN).\n    Heap() : Heap([](const\
    \ T &a, const T &b) -> bool { return a > b; }, std::vector<T>(0)) {}\n    explicit\
    \ Heap(const F &comp) : Heap(comp, std::vector<T>(0)) {}\n    explicit Heap(const\
    \ std::vector<T> &v) : Heap([](const T &a, const T &b) -> bool { return a > b;\
    \ }, v) {}\n    explicit Heap(const F &comp, const std::vector<T> &v) : m_comp(comp),\
    \ m_sz(v.size()), m_tree(v.size() + 1) {\n        if(size() > 0) {\n         \
    \   std::copy(v.begin(), v.end(), m_tree.begin() + 1);\n            heap_sort();\n\
    \        }\n    }\n    ~Heap() {\n        std::vector<T>().swap(m_tree);\n   \
    \ }\n\n    bool empty() const { return size() == 0; }\n    int size() const {\
    \ return m_sz; }\n    // \u8981\u7D20\u53C2\u7167\uFF0EO(1).\n    T top() const\
    \ {\n        assert(!empty());\n        return m_tree[1];\n    }\n    // \u8981\
    \u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const T &a) {\n        m_tree.push_back(a);\n\
    \        m_sz++;\n        all_shift_up(size());\n    }\n    // \u8981\u7D20\u524A\
    \u9664\uFF0EO(logN).\n    T pop() {\n        assert(!empty());\n        T res\
    \ = m_tree[1];\n        m_tree[1] = m_tree[size()];\n        m_tree.pop_back();\n\
    \        m_sz--;\n        if(size() > 0) all_shift_down(1);\n        return res;\n\
    \    }\n    // \u30D2\u30FC\u30D7\u30BD\u30FC\u30C8\uFF0EO(N*logN).\n    void\
    \ heap_sort(const F &comp) {\n        m_comp = comp;\n        heap_sort();\n \
    \   }\n};\n\n}  // namespace algorithm\n\n\n"
  code: "#ifndef ALGORITHM_HEAP_HPP\n#define ALGORITHM_HEAP_HPP 1\n\n#include <cassert>\n\
    #include <functional>\n#include <vector>\n\nnamespace algorithm {\n\n// \u4E8C\
    \u5206\u30D2\u30FC\u30D7\uFF0E\ntemplate <typename T>\nclass Heap {\n    using\
    \ F = std::function<bool(T &, T &)>;\n\n    F m_comp;               // bool m_comp(T&,T&):=(\u6BD4\
    \u8F03\u6F14\u7B97\u95A2\u6570).\n    int m_sz;               // m_sz:=(\u8981\
    \u7D20\u6570).\n    std::vector<T> m_tree;  // m_tree[]:=(\u4E8C\u5206\u6728).\
    \ 1-based index.\n\n    int shift_up(int k) {\n        assert(1 <= k and k <=\
    \ size());\n        if(k == 1) return 1;\n        int par = k / 2;\n        if(m_comp(m_tree[par],\
    \ m_tree[k])) return k;\n        std::swap(m_tree[par], m_tree[k]);\n        return\
    \ par;\n    }\n    void all_shift_up(int k) {\n        while(1) {\n          \
    \  int next = shift_up(k);\n            if(next == k) return;\n            k =\
    \ next;\n        }\n    }\n    int shift_down(int k) {\n        assert(1 <= k\
    \ and k <= size());\n        if(k > size() / 2) return k;\n        int l = 2 *\
    \ k, r = 2 * k + 1;\n        if(r > size() or m_comp(m_tree[l], m_tree[r])) {\n\
    \            if(m_comp(m_tree[k], m_tree[l])) return k;\n            std::swap(m_tree[k],\
    \ m_tree[l]);\n            return l;\n        } else {\n            if(m_comp(m_tree[k],\
    \ m_tree[r])) return k;\n            std::swap(m_tree[k], m_tree[r]);\n      \
    \      return r;\n        }\n    }\n    void all_shift_down(int k) {\n       \
    \ while(1) {\n            int next = shift_down(k);\n            if(next == k)\
    \ return;\n            k = next;\n        }\n    }\n    void heap_sort() {\n \
    \       int k = size() / 2;\n        for(int i = k; i >= 1; --i) all_shift_down(i);\n\
    \    }\n\npublic:\n    // constructor. O(N*logN).\n    Heap() : Heap([](const\
    \ T &a, const T &b) -> bool { return a > b; }, std::vector<T>(0)) {}\n    explicit\
    \ Heap(const F &comp) : Heap(comp, std::vector<T>(0)) {}\n    explicit Heap(const\
    \ std::vector<T> &v) : Heap([](const T &a, const T &b) -> bool { return a > b;\
    \ }, v) {}\n    explicit Heap(const F &comp, const std::vector<T> &v) : m_comp(comp),\
    \ m_sz(v.size()), m_tree(v.size() + 1) {\n        if(size() > 0) {\n         \
    \   std::copy(v.begin(), v.end(), m_tree.begin() + 1);\n            heap_sort();\n\
    \        }\n    }\n    ~Heap() {\n        std::vector<T>().swap(m_tree);\n   \
    \ }\n\n    bool empty() const { return size() == 0; }\n    int size() const {\
    \ return m_sz; }\n    // \u8981\u7D20\u53C2\u7167\uFF0EO(1).\n    T top() const\
    \ {\n        assert(!empty());\n        return m_tree[1];\n    }\n    // \u8981\
    \u7D20\u8FFD\u52A0\uFF0EO(logN).\n    void push(const T &a) {\n        m_tree.push_back(a);\n\
    \        m_sz++;\n        all_shift_up(size());\n    }\n    // \u8981\u7D20\u524A\
    \u9664\uFF0EO(logN).\n    T pop() {\n        assert(!empty());\n        T res\
    \ = m_tree[1];\n        m_tree[1] = m_tree[size()];\n        m_tree.pop_back();\n\
    \        m_sz--;\n        if(size() > 0) all_shift_down(1);\n        return res;\n\
    \    }\n    // \u30D2\u30FC\u30D7\u30BD\u30FC\u30C8\uFF0EO(N*logN).\n    void\
    \ heap_sort(const F &comp) {\n        m_comp = comp;\n        heap_sort();\n \
    \   }\n};\n\n}  // namespace algorithm\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/heap.hpp
  requiredBy: []
  timestamp: '2023-04-06 22:36:11+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/heap.hpp
layout: document
redirect_from:
- /library/src/DataStructure/heap.hpp
- /library/src/DataStructure/heap.hpp.html
title: src/DataStructure/heap.hpp
---
