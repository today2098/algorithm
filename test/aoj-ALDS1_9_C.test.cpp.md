---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/heap.hpp
    title: "\u4E8C\u5206\u30D2\u30FC\u30D7"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_9_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_9_C
  bundledCode: "#line 1 \"test/aoj-ALDS1_9_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#line 1 \"src/DataStructure/heap.hpp\"\
    \n\n\n\n/**\n * @brief \u4E8C\u5206\u30D2\u30FC\u30D7\n * @docs docs/DataStructure/heap.md\n\
    \ */\n\n#include <cassert>\n#include <functional>\n#include <utility>\n#include\
    \ <vector>\n\nnamespace algorithm {\n\n// \u4E8C\u5206\u30D2\u30FC\u30D7\uFF0E\
    \ntemplate <typename T>\nclass Heap {\n    using Comp = std::function<bool(const\
    \ T &, const T &)>;\n\n    Comp m_comp;            // bool m_comp(T,T):=(\u6BD4\
    \u8F03\u6F14\u7B97\u5B50).\n    std::vector<T> m_tree;  // m_tree[]:=(\u4E8C\u5206\
    \u6728). 1-based index.\n\n    void shift_up(int k) {\n        while(true) {\n\
    \            if(k == 1) break;\n            int par = k >> 1;\n            if(m_comp(m_tree[par],\
    \ m_tree[k])) break;\n            std::swap(m_tree[par], m_tree[k]);\n       \
    \     k = par;\n        }\n    }\n    void shift_down(int k) {\n        while(true)\
    \ {\n            int l = k << 1, r = k << 1 | 1;\n            if(size() < l) break;\n\
    \            if(size() < r or m_comp(m_tree[l], m_tree[r])) {\n              \
    \  if(m_comp(m_tree[k], m_tree[l])) break;\n                std::swap(m_tree[k],\
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
    \    }\n};\n\n}  // namespace algorithm\n\n\n#line 7 \"test/aoj-ALDS1_9_C.test.cpp\"\
    \n\nint main() {\n    algorithm::Heap<int> heap;\n\n    while(true) {\n      \
    \  std::string op;\n        std::cin >> op;\n\n        if(op == \"end\") break;\n\
    \        if(op == \"insert\") {\n            int k;\n            std::cin >> k;\n\
    \n            heap.push(k);\n        } else {\n            std::cout << heap.top()\
    \ << \"\\n\";\n            heap.pop();\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/all/ALDS1_9_C\"\
    \n\n#include <iostream>\n#include <string>\n\n#include \"../src/DataStructure/heap.hpp\"\
    \n\nint main() {\n    algorithm::Heap<int> heap;\n\n    while(true) {\n      \
    \  std::string op;\n        std::cin >> op;\n\n        if(op == \"end\") break;\n\
    \        if(op == \"insert\") {\n            int k;\n            std::cin >> k;\n\
    \n            heap.push(k);\n        } else {\n            std::cout << heap.top()\
    \ << \"\\n\";\n            heap.pop();\n        }\n    }\n}\n"
  dependsOn:
  - src/DataStructure/heap.hpp
  isVerificationFile: true
  path: test/aoj-ALDS1_9_C.test.cpp
  requiredBy: []
  timestamp: '2023-09-26 16:38:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ALDS1_9_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ALDS1_9_C.test.cpp
- /verify/test/aoj-ALDS1_9_C.test.cpp.html
title: test/aoj-ALDS1_9_C.test.cpp
---
