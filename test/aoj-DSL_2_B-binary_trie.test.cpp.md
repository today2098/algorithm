---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/binary_trie.hpp
    title: "Binary Trie\u6728"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B
  bundledCode: "#line 1 \"test/aoj-DSL_2_B-binary_trie.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n\n#include <iostream>\n\
    \n#line 1 \"src/DataStructure/binary_trie.hpp\"\n\n\n\n/**\n * @brief Binary Trie\u6728\
    \n * @docs docs/DataStructure/binary_trie.md\n */\n\n#include <bitset>\n#include\
    \ <cassert>\n#include <cstdint>\n\nnamespace algorithm {\n\n// \u975E\u8CA0\u6574\
    \u6570\u3092\u8981\u7D20\u5024\u3068\u3059\u308B\u591A\u91CD\u96C6\u5408\uFF0E\
    \ntemplate <size_t B = 32>  // B:\u30D3\u30C3\u30C8\u9577.\nclass BinaryTrie {\n\
    public:\n    using size_type = uint64_t;\n\nprivate:\n    struct Node {\n    \
    \    size_type cnt;  // cnt:=(\u81EA\u8EAB\u3092\u6839\u3068\u3059\u308B\u90E8\
    \u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\u7D20\u6570).\n        Node *ch[2];\
    \    // ch[]:=(\u5B50\u306E\u30DD\u30A4\u30F3\u30BF).\n        Node() : cnt(0)\
    \ {\n            ch[0] = ch[1] = nullptr;\n        }\n    };\n\n    Node *m_root;\
    \           // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n    std::bitset<B>\
    \ m_bias;  // m_bias:=(xor\u306E\u64CD\u4F5C\u3092\u884C\u3046\u5024).\n\n   \
    \ Node *find(const std::bitset<B> &x) const {\n        if(m_root == nullptr) return\
    \ nullptr;\n        Node *p = m_root;\n        for(int i = B - 1; i >= 0; --i)\
    \ {\n            p = p->ch[x[i] ^ m_bias[i]];\n            if(p == nullptr) return\
    \ nullptr;\n        }\n        return p;\n    }\n    Node *add(Node *p, const\
    \ std::bitset<B> &x, size_type cnt, int shift = B - 1) {  // Top down.\n     \
    \   if(p == nullptr) p = new Node;\n        p->cnt += cnt;\n        if(shift >=\
    \ 0) {\n            bool bit = x[shift] ^ m_bias[shift];\n            p->ch[bit]\
    \ = add(p->ch[bit], x, cnt, shift - 1);\n        }\n        return p;\n    }\n\
    \    Node *sub(Node *p, const std::bitset<B> &x, size_type cnt, int shift = B\
    \ - 1) {  // Bottom up.\n        assert(p and p->cnt >= cnt);\n        if(shift\
    \ >= 0) {\n            bool bit = x[shift] ^ m_bias[shift];\n            p->ch[bit]\
    \ = sub(p->ch[bit], x, cnt, shift - 1);\n        }\n        p->cnt -= cnt;\n \
    \       if(p->cnt == 0) {\n            delete p;\n            p = nullptr;\n \
    \       }\n        return p;\n    }\n    std::bitset<B> get(Node *p, size_type\
    \ k, int shift = B - 1) const {\n        assert(p);\n        if(shift < 0) return\
    \ 0;\n        bool bit = m_bias[shift];\n        size_type m = (p->ch[bit] ? p->ch[bit]->cnt\
    \ : 0);\n        if(k < m) return get(p->ch[bit], k, shift - 1);\n        return\
    \ std::bitset<B>(0).set(shift) | get(p->ch[!bit], k - m, shift - 1);\n    }\n\
    \    size_type get_lower(Node *p, const std::bitset<B> &x, int shift = B - 1)\
    \ const {\n        if(p == nullptr or shift < 0) return 0;\n        bool bit =\
    \ x[shift] ^ m_bias[shift];\n        return (x[shift] and p->ch[!bit] ? p->ch[!bit]->cnt\
    \ : 0) + get_lower(p->ch[bit], x, shift - 1);\n    }\n    size_type get_upper(Node\
    \ *p, const std::bitset<B> &x, int shift = B - 1) const {\n        if(p == nullptr)\
    \ return 0;\n        if(shift < 0) return p->cnt;\n        bool bit = x[shift]\
    \ ^ m_bias[shift];\n        return (x[shift] and p->ch[!bit] ? p->ch[!bit]->cnt\
    \ : 0) + get_upper(p->ch[bit], x, shift - 1);\n    }\n    Node *dfs_clear(Node\
    \ *p) {\n        if(p == nullptr) return nullptr;\n        for(bool bit : {0,\
    \ 1}) p->ch[bit] = dfs_clear(p->ch[bit]);\n        delete p;\n        return p\
    \ = nullptr;\n    }\n    void dfs_print(std::ostream &os, Node *p, std::bitset<B>\
    \ &x, int &cnt, int shift = B - 1) const {\n        if(shift < 0) {\n        \
    \    os << (cnt == 0 ? \"\" : \"\\n \") << \"{\" << x << \" (\" << x.to_ullong()\
    \ << \"), \" << p->cnt << \"}\";\n            cnt++;\n            return;\n  \
    \      }\n        for(bool bit : {0, 1}) {\n            x[shift] = bit;\n    \
    \        bit ^= m_bias[shift];\n            if(p->ch[bit]) dfs_print(os, p->ch[bit],\
    \ x, cnt, shift - 1);\n        }\n    }\n\npublic:\n    BinaryTrie() : m_root(nullptr),\
    \ m_bias(0) {}\n    ~BinaryTrie() {\n        clear();\n    }\n\n    std::bitset<B>\
    \ operator[](size_type k) const { return kth_element(k); }\n\n    // \u8981\u7D20\
    \u304C\u7A7A\u304B\u3069\u3046\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool\
    \ empty() const { return m_root == nullptr; }\n    // \u5168\u8981\u7D20\u6570\
    \u3092\u8FD4\u3059\uFF0EO(1).\n    size_type size() const { return (m_root ? m_root->cnt\
    \ : 0); }\n    // \u5024x\u306E\u8981\u7D20\u304C\u591A\u91CD\u96C6\u5408\u306B\
    \u542B\u307E\u308C\u308B\u304B\u5224\u5B9A\u3059\u308B\uFF0EO(B).\n    bool exist(const\
    \ std::bitset<B> &x) const { return find(x); }\n    // \u5024x\u306E\u8981\u7D20\
    \u6570\u3092\u8FD4\u3059\uFF0EO(B).\n    size_type count(const std::bitset<B>\
    \ &x) const {\n        Node *p = find(x);\n        return (p ? p->cnt : 0);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u306B\u5024x\u306E\u8981\u7D20\u3092\u8FFD\
    \u52A0\u3059\u308B\uFF0EO(B).\n    void insert(const std::bitset<B> &x, size_type\
    \ cnt = 1) {\n        if(cnt == 0) return;\n        m_root = add(m_root, x, cnt);\n\
    \    }\n    // \u591A\u91CD\u96C6\u5408\u304B\u3089\u5024x\u306E\u8981\u7D20\u3092\
    \u524A\u9664\u3059\u308B\uFF0EO(B).\n    void erase(const std::bitset<B> &x, size_type\
    \ cnt = 1) {\n        assert(count(x) >= cnt);\n        if(cnt == 0) return;\n\
    \        m_root = sub(m_root, x, cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\
    \u5185\u3067\u6700\u5C0F\u306E\u8981\u7D20\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(B).\n    std::bitset<B> min_element() const { return kth_element(0); }\n\
    \    // \u591A\u91CD\u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u8981\u7D20\u5024\
    \u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    std::bitset<B> max_element() const\
    \ { return kth_element(size() - 1); }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067\
    k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u5024\u3092\u53D6\u5F97\u3059\
    \u308B\uFF0E0-based index. O(B).\n    std::bitset<B> kth_element(size_type k)\
    \ const {\n        assert(0 <= k and k < size());\n        return get(m_root,\
    \ k);\n    }\n    // \u96C6\u5408\u5185\u3067\u5024x\u4EE5\u4E0A\u3067\u3042\u308B\
    \u6700\u5C0F\u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0E\
    O(B).\n    size_type lower_bound(const std::bitset<B> &x) const { return get_lower(m_root,\
    \ x); }\n    // \u96C6\u5408\u5185\u3067\u5024x\u3088\u308A\u5927\u304D\u3044\u6700\
    \u5C0F\u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n\
    \    size_type upper_bound(const std::bitset<B> &x) const { return get_upper(m_root,\
    \ x); }\n    // \u5168\u8981\u7D20\u5024\u306Bxor\u306E\u64CD\u4F5C\u3092\u884C\
    \u3046\uFF0EO(1).\n    void operator_xor(const std::bitset<B> &x) { m_bias ^=\
    \ x; }\n    // xor\u306E\u64CD\u4F5C\u3092\u3059\u308B\u5024\u3092\u8FD4\u3059\
    \uFF0EO(1).\n    std::bitset<B> xor_value() const { return m_bias; }\n    // \u5168\
    \u8981\u7D20\u3092\u524A\u9664\u3059\u308B\uFF0E\n    void clear() { m_root =\
    \ dfs_clear(m_root); }\n\n    friend std::ostream &operator<<(std::ostream &os,\
    \ const BinaryTrie &ob) {\n        std::bitset<B> x(0);\n        int cnt = 0;\n\
    \        os << \"[\";\n        if(ob.m_root) ob.dfs_print(os, ob.m_root, x, cnt);\n\
    \        os << \"]\";\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\
    \n\n#line 6 \"test/aoj-DSL_2_B-binary_trie.test.cpp\"\n\nint main() {\n    int\
    \ n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::BinaryTrie<20> trie;\n\
    \    while(q--) {\n        int com;\n        int x;\n        int y;\n        std::cin\
    \ >> com >> x >> y;\n\n        if(com == 0) trie.insert(x, y);\n        else std::cout\
    \ << trie.upper_bound(y) - trie.lower_bound(x) << \"\\n\";\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B\"\n\n\
    #include <iostream>\n\n#include \"../src/DataStructure/binary_trie.hpp\"\n\nint\
    \ main() {\n    int n;\n    int q;\n    std::cin >> n >> q;\n\n    algorithm::BinaryTrie<20>\
    \ trie;\n    while(q--) {\n        int com;\n        int x;\n        int y;\n\
    \        std::cin >> com >> x >> y;\n\n        if(com == 0) trie.insert(x, y);\n\
    \        else std::cout << trie.upper_bound(y) - trie.lower_bound(x) << \"\\n\"\
    ;\n    }\n}\n"
  dependsOn:
  - src/DataStructure/binary_trie.hpp
  isVerificationFile: true
  path: test/aoj-DSL_2_B-binary_trie.test.cpp
  requiredBy: []
  timestamp: '2023-09-21 22:03:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-DSL_2_B-binary_trie.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-DSL_2_B-binary_trie.test.cpp
- /verify/test/aoj-DSL_2_B-binary_trie.test.cpp.html
title: test/aoj-DSL_2_B-binary_trie.test.cpp
---
