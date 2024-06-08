---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/DataStructure/avl_tree.md
    document_title: "AVL\u6728"
    links: []
  bundledCode: "#line 1 \"src/DataStructure/avl_tree.hpp\"\n\n\n\n/**\n * @brief AVL\u6728\
    \n * @docs docs/DataStructure/avl_tree.md\n */\n\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <cstdint>\n#include <iostream>\n\nnamespace\
    \ algorithm {\n\ntemplate <typename T>\nclass AVL {\npublic:\n    using value_type\
    \ = T;\n    using size_type = int32_t;\n\nprivate:\n    struct Node {\n      \
    \  T value;\n        size_type height;\n        Node *children[2];\n        explicit\
    \ Node(T value_) : value(value_), height(1), children{nullptr, nullptr} {}\n \
    \   };\n\n    size_type m_sz;  // m_sz:=(\u8981\u7D20\u6570).\n    Node *m_root;\
    \    // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\n    size_type calc_height(Node\
    \ *node) const {\n        if(!node) return 0;\n        size_type res = 1;\n  \
    \      res = std::max(res, (node->children[0] ? node->children[0]->height : 0)\
    \ + 1);\n        res = std::max(res, (node->children[1] ? node->children[1]->height\
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
    \ T value, bool enable_duplication) {\n        if(!(*node)) {\n            *node\
    \ = new Node(value);\n            m_sz++;\n            return true;\n        }\n\
    \        if(value == (*node)->value and !enable_duplication) return false;\n \
    \       int l = (value < (*node)->value ? 0 : 1);\n        auto res = add(&(*node)->children[l],\
    \ value, enable_duplication);\n        if(res) {\n            (*node)->height\
    \ = calc_height(*node);\n            modify_tree(node);\n        }\n        return\
    \ res;\n    }\n    bool sub(Node **node, T value) {\n        if(!(*node)) return\
    \ false;\n        if(value == (*node)->value) {\n            if((*node)->height\
    \ == 1) {\n                delete *node;\n                *node = nullptr;\n \
    \               m_sz--;\n                return true;\n            }\n       \
    \     int l = ((*node)->children[0] ? 0 : 1);\n            int r = 1 - l;\n  \
    \          Node *next_node = (*node)->children[l];\n            while(next_node->children[r])\
    \ next_node = next_node->children[r];\n            (*node)->value = next_node->value;\n\
    \            sub(&(*node)->children[l], (*node)->value);\n            (*node)->height\
    \ = calc_height(*node);\n            modify_tree(node);\n            return true;\n\
    \        }\n        int l = (value < (*node)->value ? 0 : 1);\n        auto res\
    \ = sub(&(*node)->children[l], value);\n        if(res) {\n            (*node)->height\
    \ = calc_height(*node);\n            modify_tree(node);\n        }\n        return\
    \ res;\n    }\n    bool find(Node *node, T value) const {\n        if(!node) return\
    \ false;\n        if(node->value == value) return true;\n        if(value < node->value)\
    \ return find(node->children[0], value);\n        return find(node->children[1],\
    \ value);\n    }\n    void print(std::ostream &os, Node *node, bool &first) const\
    \ {\n        if(!node) return;\n        print(os, node->children[0], first);\n\
    \        os << (first ? \"\" : \" \") << node->value << \"-\" << node->height;\n\
    \        first = false;\n        print(os, node->children[1], first);\n    }\n\
    \npublic:\n    AVL() : m_sz(0), m_root(nullptr) {}\n\n    size_type size() const\
    \ { return m_sz; }\n    bool add(T value, bool enable_duplication = false) { return\
    \ add(&m_root, value, enable_duplication); }\n    bool sub(T value) { return sub(&m_root,\
    \ value); }\n    bool find(T value) const { return find(m_root, value); }\n  \
    \  void print(std::ostream &os) const {\n        bool first = true;\n        os\
    \ << \"[\";\n        print(os, m_root, first);\n        os << \"]\";\n    }\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const AVL &ob) {\n    \
    \    ob.print(os);\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n"
  code: "#ifndef ALGORITHM_AVL_TREE_HPP\n#define ALGORITHM_AVL_TREE_HPP 1\n\n/**\n\
    \ * @brief AVL\u6728\n * @docs docs/DataStructure/avl_tree.md\n */\n\n#include\
    \ <algorithm>\n#include <cassert>\n#include <cmath>\n#include <cstdint>\n#include\
    \ <iostream>\n\nnamespace algorithm {\n\ntemplate <typename T>\nclass AVL {\n\
    public:\n    using value_type = T;\n    using size_type = int32_t;\n\nprivate:\n\
    \    struct Node {\n        T value;\n        size_type height;\n        Node\
    \ *children[2];\n        explicit Node(T value_) : value(value_), height(1), children{nullptr,\
    \ nullptr} {}\n    };\n\n    size_type m_sz;  // m_sz:=(\u8981\u7D20\u6570).\n\
    \    Node *m_root;    // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\n \
    \   size_type calc_height(Node *node) const {\n        if(!node) return 0;\n \
    \       size_type res = 1;\n        res = std::max(res, (node->children[0] ? node->children[0]->height\
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
    \ T value, bool enable_duplication) {\n        if(!(*node)) {\n            *node\
    \ = new Node(value);\n            m_sz++;\n            return true;\n        }\n\
    \        if(value == (*node)->value and !enable_duplication) return false;\n \
    \       int l = (value < (*node)->value ? 0 : 1);\n        auto res = add(&(*node)->children[l],\
    \ value, enable_duplication);\n        if(res) {\n            (*node)->height\
    \ = calc_height(*node);\n            modify_tree(node);\n        }\n        return\
    \ res;\n    }\n    bool sub(Node **node, T value) {\n        if(!(*node)) return\
    \ false;\n        if(value == (*node)->value) {\n            if((*node)->height\
    \ == 1) {\n                delete *node;\n                *node = nullptr;\n \
    \               m_sz--;\n                return true;\n            }\n       \
    \     int l = ((*node)->children[0] ? 0 : 1);\n            int r = 1 - l;\n  \
    \          Node *next_node = (*node)->children[l];\n            while(next_node->children[r])\
    \ next_node = next_node->children[r];\n            (*node)->value = next_node->value;\n\
    \            sub(&(*node)->children[l], (*node)->value);\n            (*node)->height\
    \ = calc_height(*node);\n            modify_tree(node);\n            return true;\n\
    \        }\n        int l = (value < (*node)->value ? 0 : 1);\n        auto res\
    \ = sub(&(*node)->children[l], value);\n        if(res) {\n            (*node)->height\
    \ = calc_height(*node);\n            modify_tree(node);\n        }\n        return\
    \ res;\n    }\n    bool find(Node *node, T value) const {\n        if(!node) return\
    \ false;\n        if(node->value == value) return true;\n        if(value < node->value)\
    \ return find(node->children[0], value);\n        return find(node->children[1],\
    \ value);\n    }\n    void print(std::ostream &os, Node *node, bool &first) const\
    \ {\n        if(!node) return;\n        print(os, node->children[0], first);\n\
    \        os << (first ? \"\" : \" \") << node->value << \"-\" << node->height;\n\
    \        first = false;\n        print(os, node->children[1], first);\n    }\n\
    \npublic:\n    AVL() : m_sz(0), m_root(nullptr) {}\n\n    size_type size() const\
    \ { return m_sz; }\n    bool add(T value, bool enable_duplication = false) { return\
    \ add(&m_root, value, enable_duplication); }\n    bool sub(T value) { return sub(&m_root,\
    \ value); }\n    bool find(T value) const { return find(m_root, value); }\n  \
    \  void print(std::ostream &os) const {\n        bool first = true;\n        os\
    \ << \"[\";\n        print(os, m_root, first);\n        os << \"]\";\n    }\n\n\
    \    friend std::ostream &operator<<(std::ostream &os, const AVL &ob) {\n    \
    \    ob.print(os);\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\
    \n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/avl_tree.hpp
  requiredBy: []
  timestamp: '2024-06-09 03:42:10+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/avl_tree.hpp
layout: document
redirect_from:
- /library/src/DataStructure/avl_tree.hpp
- /library/src/DataStructure/avl_tree.hpp.html
title: "AVL\u6728"
---
## 概要

AVL tree (Adelson-Velskii and Landis' tree) とは，最初に考案された平行二分探索木である．
名前は，1962年に論文を発表したソ連の数学者である Georgy Adelson-Velsky と Evgenii Landis にちなむ．


## 参考文献

1. "AVL木". Wikipedia. <https://ja.wikipedia.org/wiki/AVL木>.
1. mikecat_mixc. "AVL木の回転(要素の挿入や削除のしかた)". Qiita. <https://qiita.com/mikecat_mixc/items/e9f8248de2ae7f7a0a29>.
1. "【C言語】AVL 木（平衡２分探索木）の解説と実装". だえうホームページ. <https://daeudaeu.com/avl_tree/>.
