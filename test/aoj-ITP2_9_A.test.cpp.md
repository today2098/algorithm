---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/avl_tree.hpp
    title: "AVL\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/9/ITP2_9_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/9/ITP2_9_A
  bundledCode: "#line 1 \"test/aoj-ITP2_9_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/9/ITP2_9_A\"\
    \n\n#include <iostream>\n\n#line 1 \"src/DataStructure/avl_tree.hpp\"\n\n\n\n\
    /**\n * @brief AVL\u6728\n * @docs docs/DataStructure/avl_tree.md\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstddef>\n#line\
    \ 14 \"src/DataStructure/avl_tree.hpp\"\n#include <iterator>\n\nnamespace algorithm\
    \ {\n\ntemplate <typename T>\nclass AVL {\npublic:\n    using value_type = T;\n\
    \    using size_type = ssize_t;\n\nprivate:\n    struct Node {\n        T value;\n\
    \        size_type height;\n        Node *children[2];\n        Node *neighbors[2];\n\
    \        Node() : Node(0, nullptr, nullptr) {}\n        explicit Node(T value_,\
    \ Node *pre, Node *next) : value(value_), height(1), children{nullptr, nullptr},\
    \ neighbors{pre, next} {}\n    };\n\n    class Iterator : public std::iterator<std::bidirectional_iterator_tag,\
    \ T> {\n        friend class AVL;\n\n    public:\n        using difference_type\
    \ = std::ptrdiff_t;\n        using value_type = T;\n        using pointer = T\
    \ *;\n        using reference = T &;\n        using iterator_category = std::bidirectional_iterator_tag;\n\
    \n    private:\n        Node *p;\n\n    public:\n        Iterator() : p(nullptr)\
    \ {}\n        Iterator(Node *p_) : p(p_) {}\n        Iterator(const Iterator &iter)\
    \ : p(iter.p) {}\n\n        const T &operator*() { return p->value; };\n     \
    \   Iterator &operator++() {\n            p = p->neighbors[1];\n            return\
    \ *this;\n        }\n        Iterator &operator--() {\n            p = p->neighbors[0];\n\
    \            return *this;\n        }\n        Iterator operator++(int) {\n  \
    \          Iterator res = *this;\n            ++(*this);\n            return res;\n\
    \        }\n        Iterator operator--(int) {\n            Iterator res = *this;\n\
    \            --(*this);\n            return res;\n        }\n        bool operator==(const\
    \ Iterator &iter) { return p == iter.p; }\n        bool operator!=(const Iterator\
    \ &iter) { return p != iter.p; }\n    };\n\npublic:\n    using const_iterator\
    \ = Iterator;\n    using iterator = const_iterator;\n\nprivate:\n    size_type\
    \ m_sz;  // m_sz:=(\u8981\u7D20\u6570).\n    Node *m_root;    // m_root:=(\u6839\
    \u306E\u30DD\u30A4\u30F3\u30BF).\n    const_iterator m_begin, m_end;\n\n    size_type\
    \ calc_height(Node *node) const {\n        if(!node) return 0;\n        size_type\
    \ res = 1;\n        res = std::max(res, (node->children[0] ? node->children[0]->height\
    \ : 0) + 1);\n        res = std::max(res, (node->children[1] ? node->children[1]->height\
    \ : 0) + 1);\n        return res;\n    }\n    size_type deviation(Node *node)\
    \ const {\n        assert(node);\n        size_type l = (node->children[0] ? node->children[0]->height\
    \ : 0);\n        size_type r = (node->children[1] ? node->children[1]->height\
    \ : 0);\n        return l - r;\n    }\n    void rotate(Node **node, bool is_right)\
    \ {\n        assert(*node);\n        int l = (is_right ? 0 : 1);\n        int\
    \ r = 1 - l;\n        assert((*node)->children[l]);\n        Node *left = (*node)->children[l];\n\
    \        (*node)->children[l] = left->children[r];\n        (*node)->height =\
    \ calc_height(*node);\n        left->children[r] = *node;\n        left->height\
    \ = calc_height(left);\n        *node = left;\n    }\n    void modify_tree(Node\
    \ **node) {\n        assert(*node);\n        size_type bias = deviation(*node);\n\
    \        assert(std::abs(bias) <= 2);\n        if(std::abs(bias) <= 1) return;\n\
    \        bool is_right = (bias >= 0);\n        int l = (is_right ? 0 : 1);\n \
    \       size_type bias2 = deviation((*node)->children[l]);\n        assert(std::abs(bias2)\
    \ <= 1);\n        if(bias2 == (is_right ? -1 : 1)) rotate(&(*node)->children[l],\
    \ !is_right);\n        rotate(node, is_right);\n    }\n    bool add(Node **node,\
    \ const T &value, Node *neighbors[2]) {\n        if(!(*node)) {\n            *node\
    \ = new Node(value, neighbors[0], neighbors[1]);\n            neighbors[0]->neighbors[1]\
    \ = neighbors[1]->neighbors[0] = *node;\n            m_sz++;\n            return\
    \ true;\n        }\n        if(value == (*node)->value) return false;\n      \
    \  int l = (value < (*node)->value ? 0 : 1);\n        int r = 1 - l;\n       \
    \ neighbors[r] = *node;\n        auto res = add(&(*node)->children[l], value,\
    \ neighbors);\n        if(res) {\n            (*node)->height = calc_height(*node);\n\
    \            modify_tree(node);\n        }\n        return res;\n    }\n    bool\
    \ sub(Node **node, const T &value) {\n        if(!(*node)) return false;\n   \
    \     if(value == (*node)->value) {\n            if((*node)->height == 1) {\n\
    \                (*node)->neighbors[0]->neighbors[1] = (*node)->neighbors[1];\n\
    \                (*node)->neighbors[1]->neighbors[0] = (*node)->neighbors[0];\n\
    \                delete *node;\n                *node = nullptr;\n           \
    \     m_sz--;\n                return true;\n            }\n            int l\
    \ = ((*node)->children[0] ? 0 : 1);\n            Node *next_node = (*node)->neighbors[l];\n\
    \            (*node)->value = next_node->value;\n            sub(&(*node)->children[l],\
    \ (*node)->value);\n            (*node)->height = calc_height(*node);\n      \
    \      modify_tree(node);\n            return true;\n        }\n        int l\
    \ = (value < (*node)->value ? 0 : 1);\n        auto res = sub(&(*node)->children[l],\
    \ value);\n        if(res) {\n            (*node)->height = calc_height(*node);\n\
    \            modify_tree(node);\n        }\n        return res;\n    }\n    const_iterator\
    \ find(Node *node, const T &value) const {\n        if(!node) return cend();\n\
    \        if(node->value == value) return const_iterator(node);\n        if(value\
    \ < node->value) return find(node->children[0], value);\n        return find(node->children[1],\
    \ value);\n    }\n    const_iterator lower_bound(Node *node, const T &value) const\
    \ {\n        assert(node);\n        if(value < node->value) {\n            if(!node->children[0])\
    \ return const_iterator(node);\n            return lower_bound(node->children[0],\
    \ value);\n        }\n        if(node->value == value) return const_iterator(node);\n\
    \        if(!node->children[1]) return const_iterator(node->neighbors[1]);\n \
    \       return lower_bound(node->children[1], value);\n    }\n    const_iterator\
    \ upper_bound(Node *node, const T &value) const {\n        assert(node);\n   \
    \     if(value < node->value) {\n            if(!node->children[0]) return const_iterator(node);\n\
    \            return upper_bound(node->children[0], value);\n        }\n      \
    \  if(!node->children[1]) return const_iterator(node->neighbors[1]);\n       \
    \ return upper_bound(node->children[1], value);\n    }\n\npublic:\n    AVL() :\
    \ m_sz(0), m_root(nullptr), m_begin(new Node()), m_end(new Node()) {\n       \
    \ m_begin.p->neighbors[1] = m_end.p;\n    }\n\n    size_type size() const { return\
    \ m_sz; }\n    iterator begin() const { return cbegin(); }\n    iterator end()\
    \ const { return cend(); }\n    const_iterator cbegin() const {\n        const_iterator\
    \ iter = m_begin;\n        return ++iter;\n    }\n    const_iterator cend() const\
    \ { return m_end; }\n    bool insert(const T &value) {\n        Node *neighbors[2]\
    \ = {m_begin.p, m_end.p};\n        return add(&m_root, value, neighbors);\n  \
    \  }\n    bool erase(const T &value) { return sub(&m_root, value); }\n    const_iterator\
    \ find(const T &value) const { return find(m_root, value); }\n    const_iterator\
    \ lower_bound(const T &value) const {\n        if(!m_root) return cbegin();\n\
    \        return lower_bound(m_root, value);\n    }\n    const_iterator upper_bound(const\
    \ T &value) const {\n        if(!m_root) return cbegin();\n        return upper_bound(m_root,\
    \ value);\n    }\n};\n\n}  // namespace algorithm\n\n\n#line 6 \"test/aoj-ITP2_9_A.test.cpp\"\
    \n\nint main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::AVL<int> avl;\n\
    \    for(int i = 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\n\
    \        avl.insert(a);\n    }\n\n    int m;\n    std::cin >> m;\n\n    for(int\
    \ i = 0; i < m; ++i) {\n        int b;\n        std::cin >> b;\n\n        avl.insert(b);\n\
    \    }\n\n    for(auto elem : avl) std::cout << elem << \"\\n\";\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/lesson/8/ITP2/9/ITP2_9_A\"\
    \n\n#include <iostream>\n\n#include \"../src/DataStructure/avl_tree.hpp\"\n\n\
    int main() {\n    int n;\n    std::cin >> n;\n\n    algorithm::AVL<int> avl;\n\
    \    for(int i = 0; i < n; ++i) {\n        int a;\n        std::cin >> a;\n\n\
    \        avl.insert(a);\n    }\n\n    int m;\n    std::cin >> m;\n\n    for(int\
    \ i = 0; i < m; ++i) {\n        int b;\n        std::cin >> b;\n\n        avl.insert(b);\n\
    \    }\n\n    for(auto elem : avl) std::cout << elem << \"\\n\";\n}\n"
  dependsOn:
  - src/DataStructure/avl_tree.hpp
  isVerificationFile: true
  path: test/aoj-ITP2_9_A.test.cpp
  requiredBy: []
  timestamp: '2024-06-09 15:36:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP2_9_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP2_9_A.test.cpp
- /verify/test/aoj-ITP2_9_A.test.cpp.html
title: test/aoj-ITP2_9_A.test.cpp
---
