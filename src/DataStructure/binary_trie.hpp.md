---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - "https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\uFF08\u53C2\u7167\
      2022.9.11\uFF09\uFF0E"
  bundledCode: "#line 1 \"src/DataStructure/binary_trie.hpp\"\n\n\n\n#include <bitset>\n\
    #include <cassert>\n#include <vector>\n\nnamespace algorithm {\n\n// \u975E\u8CA0\
    \u6574\u6570\u5024\u3092\u6271\u3046Trie\u6728\uFF0E\ntemplate <typename T = unsigned,\
    \ int B = 32, typename U = int>  // T:\u975E\u8CA0\u6574\u6570\u5024\u306E\u578B\
    , B:\u30D3\u30C3\u30C8\u9577, U:\u30B5\u30A4\u30BA\u306E\u578B.\nclass BinaryTrie\
    \ {\n    struct Node {\n        U cnt;        // cnt:=(\u81EA\u8EAB\u3092\u6839\
    \u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\
    \u6570).\n        Node *ch[2];  // ch[]:=(\u5B50\u306E\u30DD\u30A4\u30F3\u30BF\
    ). \u4E8C\u5206\u6728\uFF0E\n        Node() : cnt(0), ch({nullptr, nullptr}) {}\n\
    \    };\n\n    Node *root;  // root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n\
    \n    void delete_subtree(Node *rt) {\n        if(rt == nullptr) return;\n   \
    \     for(bool bit : {0, 1}) {\n            delete_subtree(rt->ch[bit]);\n   \
    \         rt->ch[bit] = nullptr;\n        }\n        delete rt;\n        rt =\
    \ nullptr;\n    }\n    Node *add(Node *p, T x, U cnt, int shift = B - 1) {  //\
    \ Top down.\n        if(p == nullptr) p = new Node;\n        p->cnt += cnt;\n\
    \        if(shift < 0) return p;\n        bool bit = (x >> shift) & (T)1;\n  \
    \      p->ch[bit] = add(p->ch[bit], x, cnt, shift - 1);\n        return p;\n \
    \   }\n    Node *sub(Node *p, T x, U cnt, int shift = B - 1) {  // Top down.\n\
    \        assert(p != nullptr and p->cnt >= cnt);\n        p->cnt -= cnt;\n   \
    \     if(p->cnt == 0) {\n            delete_subtree(p);\n            return p\
    \ = nullptr;\n        }\n        if(shift < 0) return p;\n        bool bit = (x\
    \ >> shift) & (T)1;\n        p->ch[bit] = sub(p->ch[bit], x, cnt, shift - 1);\n\
    \        return p;\n    }\n    T get_min(Node *p, T bias = 0, int shift = B -\
    \ 1) const {\n        assert(p != nullptr);\n        if(shift < 0) return 0;\n\
    \        bool bit = (bias >> shift) & (T)1;\n        if(p->ch[bit] == nullptr)\
    \ bit = !bit;\n        return get_min(p->ch[bit], bias, shift - 1) | ((T)bit <<\
    \ shift);\n    }\n    T get(Node *p, U k, T bias = 0, int shift = B - 1) const\
    \ {\n        assert(p != nullptr);\n        if(shift < 0) return 0;\n        bool\
    \ bit = (bias >> shift) & (T)1;\n        U m = (p->ch[bit] == nullptr ? 0 : p->ch[bit]->cnt);\n\
    \        if(k < m) {\n            return get(p->ch[bit], k, bias, shift - 1) |\
    \ ((T)bit << shift);\n        } else {\n            bit = !bit;\n            return\
    \ get(p->ch[bit], k - m, bias, shift - 1) | ((T)bit << shift);\n        }\n  \
    \  }\n    U get_lower(Node *p, T x, int shift = B - 1) const {\n        if(p ==\
    \ nullptr or shift < 0) return 0;\n        bool bit = (x >> shift) & (T)1;\n \
    \       return ((bit and p->ch[0] != nullptr) ? p->ch[0]->cnt : 0) + get_lower(p->ch[bit],\
    \ x, shift - 1);\n    }\n    void dfs(std::ostream &os, Node *p, std::bitset<B>\
    \ &bits, int shift = B - 1) const {\n        if(shift < 0) {\n            os <<\
    \ \"[\" << bits << \"] (num: \" << (T)bits.to_ullong() << \", cnt: \" << p->cnt\
    \ << \")\\n\";\n            return;\n        }\n        for(bool bit : {0, 1})\
    \ {\n            if(p->ch[bit] != nullptr) {\n                bits.set(shift,\
    \ bit);\n                dfs(os, p->ch[bit], bits, shift - 1);\n            }\n\
    \        }\n    }\n\npublic:\n    BinaryTrie() : root(nullptr) {\n        static_assert(B\
    \ >= 1);\n    }\n    ~BinaryTrie() {\n        clear();\n    }\n\n    // \u96C6\
    \u5408\u5185\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    T operator[](U k) const {\n        assert(0 <= k\
    \ and k < size());\n        return get(root, k);\n    }\n\n    // \u8981\u7D20\
    \u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool\
    \ empty() const { return root == nullptr; }\n    // \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0EO(1).\n    U size() const { return (root == nullptr ? 0 : root->cnt);\
    \ }\n    // \u5024x\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(B).\n   \
    \ U count(T x) const {\n        if(root == nullptr) return 0;\n        Node *p\
    \ = root;\n        for(int i = B - 1; i >= 0; --i) {\n            p = p->ch[(x\
    \ >> i) & (T)1];\n            if(p == nullptr) return 0;\n        }\n        return\
    \ p->cnt;\n    }\n    // \u96C6\u5408\u306B\u5024x\u3092\u8FFD\u52A0\u3059\u308B\
    \uFF0EO(B).\n    void insert(T x, U cnt = 1) { root = add(root, x, cnt); }\n \
    \   // \u96C6\u5408\u304B\u3089\u5024x\u3092\u524A\u9664\u3059\u308B\uFF0EO(B).\n\
    \    void erase(T x, U cnt = 1) {\n        assert(count(x) >= cnt);\n        root\
    \ = sub(root, x, cnt);\n    }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3068XOR\u3057\
    \u305F\u3068\u304D\u306B\u6700\u5C0F\u3068\u306A\u308B\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    T min_element(T x = 0) const { return get_min(root,\
    \ x); }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3068XOR\u3057\u305F\u3068\u304D\
    \u306B\u6700\u5927\u3068\u306A\u308B\u5024\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    O(B).\n    T max_element(T x = 0) const { return get_min(root, ~x); }\n    //\
    \ \u96C6\u5408\u5185\u3067\u5024x\u3068XOR\u3057\u305F\u3068\u304D\u306Bk\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n\
    \    T kth_element(U k, T x = 0) const {\n        assert(0 <= k and k < size());\n\
    \        return get(root, k, x);\n    }\n    // \u96C6\u5408\u5185\u3067\u5024\
    x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    U lower_bound(T x) const { return get_lower(root,\
    \ x); }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3088\u308A\u5927\u304D\u3044\u6700\
    \u5C0F\u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n\
    \    U upper_bound(T x) const { return get_lower(root, x + 1); }\n    // \u5168\
    \u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0E\n    void clear() {\n       \
    \ delete_subtree(root);\n        root = nullptr;\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const BinaryTrie &ob) {\n        if(ob.empty())\
    \ return os;\n        std::bitset<B> bits(0);\n        ob.dfs(os, ob.root, bits);\n\
    \    }\n};\n\n}  // namespace algorithm\n\n\n\n/*\n\u53C2\u8003\u6587\u732E\n\
    - kazuma\uFF0C\u975E\u8CA0\u6574\u6570\u5024\u3092\u6271\u3046Trie\u306B\u3064\
    \u3044\u3066\uFF0CHatena Blog, https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\uFF08\
    \u53C2\u71672022.9.11\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_BINARY_TRIE_HPP\n#define ALGORITHM_BINARY_TRIE_HPP 1\n\n\
    #include <bitset>\n#include <cassert>\n#include <vector>\n\nnamespace algorithm\
    \ {\n\n// \u975E\u8CA0\u6574\u6570\u5024\u3092\u6271\u3046Trie\u6728\uFF0E\ntemplate\
    \ <typename T = unsigned, int B = 32, typename U = int>  // T:\u975E\u8CA0\u6574\
    \u6570\u5024\u306E\u578B, B:\u30D3\u30C3\u30C8\u9577, U:\u30B5\u30A4\u30BA\u306E\
    \u578B.\nclass BinaryTrie {\n    struct Node {\n        U cnt;        // cnt:=(\u81EA\
    \u8EAB\u3092\u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\
    \u308B\u8981\u7D20\u6570).\n        Node *ch[2];  // ch[]:=(\u5B50\u306E\u30DD\
    \u30A4\u30F3\u30BF). \u4E8C\u5206\u6728\uFF0E\n        Node() : cnt(0), ch({nullptr,\
    \ nullptr}) {}\n    };\n\n    Node *root;  // root:=(\u6839\u306E\u30DD\u30A4\u30F3\
    \u30BF).\n\n    void delete_subtree(Node *rt) {\n        if(rt == nullptr) return;\n\
    \        for(bool bit : {0, 1}) {\n            delete_subtree(rt->ch[bit]);\n\
    \            rt->ch[bit] = nullptr;\n        }\n        delete rt;\n        rt\
    \ = nullptr;\n    }\n    Node *add(Node *p, T x, U cnt, int shift = B - 1) { \
    \ // Top down.\n        if(p == nullptr) p = new Node;\n        p->cnt += cnt;\n\
    \        if(shift < 0) return p;\n        bool bit = (x >> shift) & (T)1;\n  \
    \      p->ch[bit] = add(p->ch[bit], x, cnt, shift - 1);\n        return p;\n \
    \   }\n    Node *sub(Node *p, T x, U cnt, int shift = B - 1) {  // Top down.\n\
    \        assert(p != nullptr and p->cnt >= cnt);\n        p->cnt -= cnt;\n   \
    \     if(p->cnt == 0) {\n            delete_subtree(p);\n            return p\
    \ = nullptr;\n        }\n        if(shift < 0) return p;\n        bool bit = (x\
    \ >> shift) & (T)1;\n        p->ch[bit] = sub(p->ch[bit], x, cnt, shift - 1);\n\
    \        return p;\n    }\n    T get_min(Node *p, T bias = 0, int shift = B -\
    \ 1) const {\n        assert(p != nullptr);\n        if(shift < 0) return 0;\n\
    \        bool bit = (bias >> shift) & (T)1;\n        if(p->ch[bit] == nullptr)\
    \ bit = !bit;\n        return get_min(p->ch[bit], bias, shift - 1) | ((T)bit <<\
    \ shift);\n    }\n    T get(Node *p, U k, T bias = 0, int shift = B - 1) const\
    \ {\n        assert(p != nullptr);\n        if(shift < 0) return 0;\n        bool\
    \ bit = (bias >> shift) & (T)1;\n        U m = (p->ch[bit] == nullptr ? 0 : p->ch[bit]->cnt);\n\
    \        if(k < m) {\n            return get(p->ch[bit], k, bias, shift - 1) |\
    \ ((T)bit << shift);\n        } else {\n            bit = !bit;\n            return\
    \ get(p->ch[bit], k - m, bias, shift - 1) | ((T)bit << shift);\n        }\n  \
    \  }\n    U get_lower(Node *p, T x, int shift = B - 1) const {\n        if(p ==\
    \ nullptr or shift < 0) return 0;\n        bool bit = (x >> shift) & (T)1;\n \
    \       return ((bit and p->ch[0] != nullptr) ? p->ch[0]->cnt : 0) + get_lower(p->ch[bit],\
    \ x, shift - 1);\n    }\n    void dfs(std::ostream &os, Node *p, std::bitset<B>\
    \ &bits, int shift = B - 1) const {\n        if(shift < 0) {\n            os <<\
    \ \"[\" << bits << \"] (num: \" << (T)bits.to_ullong() << \", cnt: \" << p->cnt\
    \ << \")\\n\";\n            return;\n        }\n        for(bool bit : {0, 1})\
    \ {\n            if(p->ch[bit] != nullptr) {\n                bits.set(shift,\
    \ bit);\n                dfs(os, p->ch[bit], bits, shift - 1);\n            }\n\
    \        }\n    }\n\npublic:\n    BinaryTrie() : root(nullptr) {\n        static_assert(B\
    \ >= 1);\n    }\n    ~BinaryTrie() {\n        clear();\n    }\n\n    // \u96C6\
    \u5408\u5185\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    T operator[](U k) const {\n        assert(0 <= k\
    \ and k < size());\n        return get(root, k);\n    }\n\n    // \u8981\u7D20\
    \u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool\
    \ empty() const { return root == nullptr; }\n    // \u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0EO(1).\n    U size() const { return (root == nullptr ? 0 : root->cnt);\
    \ }\n    // \u5024x\u306E\u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(B).\n   \
    \ U count(T x) const {\n        if(root == nullptr) return 0;\n        Node *p\
    \ = root;\n        for(int i = B - 1; i >= 0; --i) {\n            p = p->ch[(x\
    \ >> i) & (T)1];\n            if(p == nullptr) return 0;\n        }\n        return\
    \ p->cnt;\n    }\n    // \u96C6\u5408\u306B\u5024x\u3092\u8FFD\u52A0\u3059\u308B\
    \uFF0EO(B).\n    void insert(T x, U cnt = 1) { root = add(root, x, cnt); }\n \
    \   // \u96C6\u5408\u304B\u3089\u5024x\u3092\u524A\u9664\u3059\u308B\uFF0EO(B).\n\
    \    void erase(T x, U cnt = 1) {\n        assert(count(x) >= cnt);\n        root\
    \ = sub(root, x, cnt);\n    }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3068XOR\u3057\
    \u305F\u3068\u304D\u306B\u6700\u5C0F\u3068\u306A\u308B\u5024\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    T min_element(T x = 0) const { return get_min(root,\
    \ x); }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3068XOR\u3057\u305F\u3068\u304D\
    \u306B\u6700\u5927\u3068\u306A\u308B\u5024\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    O(B).\n    T max_element(T x = 0) const { return get_min(root, ~x); }\n    //\
    \ \u96C6\u5408\u5185\u3067\u5024x\u3068XOR\u3057\u305F\u3068\u304D\u306Bk\u756A\
    \u76EE\u306B\u5C0F\u3055\u3044\u5024\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n\
    \    T kth_element(U k, T x = 0) const {\n        assert(0 <= k and k < size());\n\
    \        return get(root, k, x);\n    }\n    // \u96C6\u5408\u5185\u3067\u5024\
    x\u4EE5\u4E0A\u306E\u6700\u5C0F\u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\
    \u3059\u308B\uFF0EO(B).\n    U lower_bound(T x) const { return get_lower(root,\
    \ x); }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3088\u308A\u5927\u304D\u3044\u6700\
    \u5C0F\u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n\
    \    U upper_bound(T x) const { return get_lower(root, x + 1); }\n    // \u5168\
    \u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0E\n    void clear() {\n       \
    \ delete_subtree(root);\n        root = nullptr;\n    }\n\n    friend std::ostream\
    \ &operator<<(std::ostream &os, const BinaryTrie &ob) {\n        if(ob.empty())\
    \ return os;\n        std::bitset<B> bits(0);\n        ob.dfs(os, ob.root, bits);\n\
    \    }\n};\n\n}  // namespace algorithm\n\n#endif\n\n/*\n\u53C2\u8003\u6587\u732E\
    \n- kazuma\uFF0C\u975E\u8CA0\u6574\u6570\u5024\u3092\u6271\u3046Trie\u306B\u3064\
    \u3044\u3066\uFF0CHatena Blog, https://kazuma8128.hatenablog.com/entry/2018/05/06/022654\uFF08\
    \u53C2\u71672022.9.11\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/DataStructure/binary_trie.hpp
  requiredBy: []
  timestamp: '2023-01-26 00:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/DataStructure/binary_trie.hpp
layout: document
redirect_from:
- /library/src/DataStructure/binary_trie.hpp
- /library/src/DataStructure/binary_trie.hpp.html
title: src/DataStructure/binary_trie.hpp
---
