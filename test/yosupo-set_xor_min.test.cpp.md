---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/DataStructure/binary_trie.hpp
    title: "Binary Trie\u6728"
  - icon: ':heavy_check_mark:'
    path: src/Utils/debug.hpp
    title: src/Utils/debug.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/set_xor_min
    links:
    - https://judge.yosupo.jp/problem/set_xor_min
  bundledCode: "#line 1 \"test/yosupo-set_xor_min.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\
    \n\n#include <iostream>\n\n#line 1 \"src/DataStructure/binary_trie.hpp\"\n\n\n\
    \n/**\n * @brief Binary Trie\u6728\n * @docs docs/DataStructure/binary_trie.md\n\
    \ */\n\n#include <bitset>\n#include <cassert>\n#include <cstdint>\n\nnamespace\
    \ algorithm {\n\n// \u975E\u8CA0\u6574\u6570\u3092\u8981\u7D20\u5024\u3068\u3059\
    \u308B\u591A\u91CD\u96C6\u5408\uFF0E\ntemplate <int B = 32>  // B:\u30D3\u30C3\
    \u30C8\u9577.\nclass BinaryTrie {\npublic:\n    using size_type = uint64_t;\n\n\
    private:\n    struct Node {\n        size_type cnt;  // cnt:=(\u81EA\u8EAB\u3092\
    \u6839\u3068\u3059\u308B\u90E8\u5206\u6728\u306B\u542B\u307E\u308C\u308B\u8981\
    \u7D20\u6570).\n        Node *ch[2];    // ch[]:=(\u5B50\u306E\u30DD\u30A4\u30F3\
    \u30BF).\n        Node() : cnt(0), ch({nullptr, nullptr}) {}\n    };\n\n    Node\
    \ *m_root;           // m_root:=(\u6839\u306E\u30DD\u30A4\u30F3\u30BF).\n    std::bitset<B>\
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
    \       }\n        return p;\n    }\n    std::bitset<B> get_min(Node *p, int shift\
    \ = B - 1) const {\n        assert(p);\n        if(shift < 0) return 0;\n    \
    \    bool bit = m_bias[shift];\n        if(p->ch[bit]) return get_min(p->ch[bit],\
    \ shift - 1);\n        return std::bitset<B>(1) << shift | get_min(p->ch[!bit],\
    \ shift - 1);\n    }\n    std::bitset<B> get(Node *p, size_type k, int shift =\
    \ B - 1) const {\n        assert(p);\n        if(shift < 0) return 0;\n      \
    \  bool bit = m_bias[shift];\n        size_type m = (p->ch[bit] ? p->ch[bit]->cnt\
    \ : 0);\n        if(k < m) return get(p->ch[bit], k, shift - 1);\n        return\
    \ std::bitset<B>(1) << shift | get(p->ch[!bit], k - m, shift - 1);\n    }\n  \
    \  size_type get_lower(Node *p, const std::bitset<B> &x, int shift = B - 1) const\
    \ {\n        if(p == nullptr or shift < 0) return 0;\n        bool bit = x[shift]\
    \ ^ m_bias[shift];\n        return (x[shift] and p->ch[!bit] ? p->ch[!bit]->cnt\
    \ : 0) + get_lower(p->ch[bit], x, shift - 1);\n    }\n    size_type get_upper(Node\
    \ *p, const std::bitset<B> &x, int shift = B - 1) const {\n        if(p == nullptr)\
    \ return 0;\n        if(shift < 0) return p->cnt;\n        bool bit = x[shift]\
    \ ^ m_bias[shift];\n        return (x[shift] and p->ch[!bit] ? p->ch[!bit]->cnt\
    \ : 0) + get_upper(p->ch[bit], x, shift - 1);\n    }\n    Node *clear_dfs(Node\
    \ *p) {\n        if(p == nullptr) return nullptr;\n        for(bool bit : {0,\
    \ 1}) p->ch[bit] = clear_dfs(p->ch[bit]);\n        delete p;\n        return p\
    \ = nullptr;\n    }\n    void print_dfs(std::ostream &os, Node *p, std::bitset<B>\
    \ &x, int &cnt, int shift = B - 1) const {\n        if(shift < 0) {\n        \
    \    os << (cnt == 0 ? \"\" : \"\\n \") << \"{\" << x << \", \" << x.to_ullong()\
    \ << \", (\" << p->cnt << \")}\";\n            cnt++;\n            return;\n \
    \       }\n        for(bool bit : {0, 1}) {\n            x[shift] = bit;\n   \
    \         bit ^= m_bias[shift];\n            if(p->ch[bit]) print_dfs(os, p->ch[bit],\
    \ x, cnt, shift - 1);\n        }\n    }\n\npublic:\n    BinaryTrie() : m_root(nullptr),\
    \ m_bias(0) {\n        static_assert(B >= 0);\n    }\n    ~BinaryTrie() {\n  \
    \      clear();\n    }\n\n    // \u8981\u7D20\u304C\u7A7A\u304B\u3069\u3046\u304B\
    \u5224\u5B9A\u3059\u308B\uFF0EO(1).\n    bool empty() const { return m_root ==\
    \ nullptr; }\n    // \u5168\u8981\u7D20\u6570\u3092\u8FD4\u3059\uFF0EO(1).\n \
    \   size_type size() const { return (m_root ? m_root->cnt : 0); }\n    // \u5024\
    x\u306E\u8981\u7D20\u304C\u591A\u91CD\u96C6\u5408\u306B\u542B\u307E\u308C\u308B\
    \u304B\u5224\u5B9A\u3059\u308B\uFF0EO(B).\n    bool exist(const std::bitset<B>\
    \ &x) const { return find(x); }\n    // \u5024x\u306E\u8981\u7D20\u6570\u3092\u8FD4\
    \u3059\uFF0EO(B).\n    size_type count(const std::bitset<B> &x) const {\n    \
    \    Node *p = find(x);\n        return (p ? p->cnt : 0);\n    }\n    // \u591A\
    \u91CD\u96C6\u5408\u306B\u5024x\u306E\u8981\u7D20\u3092\u8FFD\u52A0\u3059\u308B\
    \uFF0EO(B).\n    void insert(const std::bitset<B> &x, size_type cnt = 1) {\n \
    \       if(cnt == 0) return;\n        m_root = add(m_root, x, cnt);\n    }\n \
    \   // \u591A\u91CD\u96C6\u5408\u304B\u3089\u5024x\u306E\u8981\u7D20\u3092\u524A\
    \u9664\u3059\u308B\uFF0EO(B).\n    void erase(const std::bitset<B> &x, size_type\
    \ cnt = 1) {\n        assert(count(x) >= cnt);\n        if(cnt == 0) return;\n\
    \        m_root = sub(m_root, x, cnt);\n    }\n    // \u591A\u91CD\u96C6\u5408\
    \u5185\u3067\u6700\u5C0F\u306E\u8981\u7D20\u5024\u3092\u53D6\u5F97\u3059\u308B\
    \uFF0EO(B).\n    std::bitset<B> min_element() const { return get_min(m_root);\
    \ }\n    // \u591A\u91CD\u96C6\u5408\u5185\u3067\u6700\u5927\u306E\u8981\u7D20\
    \u5024\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    std::bitset<B> max_element()\
    \ {\n        m_bias = ~m_bias;\n        std::bitset<B> &&res = ~min_element();\n\
    \        m_bias = ~m_bias;\n        return res;\n    }\n    // \u591A\u91CD\u96C6\
    \u5408\u5185\u3067k\u756A\u76EE\u306B\u5C0F\u3055\u3044\u8981\u7D20\u5024\u3092\
    \u53D6\u5F97\u3059\u308B\uFF0E0-based index. O(B).\n    std::bitset<B> kth_element(size_type\
    \ k) const {\n        assert(0 <= k and k < size());\n        return get(m_root,\
    \ k);\n    }\n    // \u96C6\u5408\u5185\u3067\u5024x\u4EE5\u4E0A\u306E\u6700\u5C0F\
    \u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    size_type\
    \ lower_bound(const std::bitset<B> &x) const { return get_lower(m_root, x); }\n\
    \    // \u96C6\u5408\u5185\u3067\u5024x\u3088\u308A\u5927\u304D\u3044\u6700\u5C0F\
    \u306E\u8981\u7D20\u756A\u53F7\u3092\u53D6\u5F97\u3059\u308B\uFF0EO(B).\n    size_type\
    \ upper_bound(const std::bitset<B> &x) const { return get_upper(m_root, x); }\n\
    \    // \u5168\u8981\u7D20\u5024\u306Bxor\u306E\u64CD\u4F5C\u3092\u884C\u3046\uFF0E\
    O(1).\n    void operator_xor(const std::bitset<B> &x) { m_bias ^= x; }\n    //\
    \ xor\u306E\u64CD\u4F5C\u3092\u3059\u308B\u5024\u3092\u8FD4\u3059\uFF0EO(1).\n\
    \    std::bitset<B> xor_value() const { return m_bias; }\n    // \u5168\u8981\u7D20\
    \u3092\u524A\u9664\u3059\u308B\uFF0E\n    void clear() { m_root = clear_dfs(m_root);\
    \ }\n\n    friend std::ostream &operator<<(std::ostream &os, const BinaryTrie\
    \ &ob) {\n        std::bitset<B> x(0);\n        int cnt = 0;\n        os << \"\
    [\";\n        if(ob.m_root) ob.print_dfs(os, ob.m_root, x, cnt);\n        os <<\
    \ \"]\";\n        return os;\n    }\n};\n\n}  // namespace algorithm\n\n\n#line\
    \ 1 \"src/Utils/debug.hpp\"\n/**\n * @docs docs/Utils/debug.md\n */\n\n#ifndef\
    \ ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#line 9 \"src/Utils/debug.hpp\"\
    \n#include <iterator>\n#include <queue>\n#include <stack>\n#include <string>\n\
    #include <string_view>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    \n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::cerr;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(const\
    \ std::string_view &s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p);\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const T\
    \ &t, std::index_sequence<Idxes...>);\ntemplate <typename... T>\nvoid print(const\
    \ std::tuple<T...> &t);\ntemplate <typename... T>\nvoid print(const std::stack<T...>\
    \ &st);\ntemplate <typename... T>\nvoid print(const std::queue<T...> &que);\n\
    template <typename... T>\nvoid print(const std::priority_queue<T...> &pque);\n\
    template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>\n\
    void print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(const\
    \ std::string_view &s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid\
    \ print(const std::pair<T, U> &p) {\n    os << \"{\";\n    print(p.first);\n \
    \   os << \", \";\n    print(p.second);\n    os << \"}\";\n}\n\ntemplate <class\
    \ T, std::size_t... Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>)\
    \ {\n    os << \"{\";\n    ((os << (Idxes == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))),\
    \ ...);\n    os << \"}\";\n}\n\ntemplate <typename... T>\nvoid print(const std::tuple<T...>\
    \ &t) {\n    print_tuple(t, std::make_index_sequence<sizeof...(T)>());\n}\n\n\
    template <typename... T>\nvoid print(const std::stack<T...> &st) {\n    std::stack<T...>\
    \ tmp = st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... T>\nvoid print(const std::queue<T...> &que) {\n\
    \    std::queue<T...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty()) {\n\
    \        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty()) os\
    \ << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... T>\nvoid print(const\
    \ std::priority_queue<T...> &pque) {\n    std::priority_queue<T...> tmp = pque;\n\
    \    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n    \
    \    tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"]\"\
    ;\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value, bool>\
    \ = false>\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr = std::cbegin(v);\
    \ itr != std::cend(v); ++itr) {\n        if(itr != std::cbegin(v)) os << \" \"\
    ;\n        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename T, typename\
    \ std::enable_if_t<!has_iterator<T>::value, bool> = false>\nvoid print(const T\
    \ &elem) { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n#line 7 \"test/yosupo-set_xor_min.test.cpp\"\
    \n\nint main() {\n    int q;\n    std::cin >> q;\n\n    algorithm::BinaryTrie<30>\
    \ trie;\n    while(q--) {\n        int t;\n        int x;\n        std::cin >>\
    \ t >> x;\n\n        if(t == 0) {\n            if(!trie.exist(x)) trie.insert(x);\n\
    \        } else if(t == 1) {\n            if(trie.exist(x)) trie.erase(x);\n \
    \       } else {\n            debug(trie);\n            trie.operator_xor(x);\n\
    \            debug(trie);\n            std::cout << trie.min_element().to_ulong()\
    \ << \"\\n\";\n            trie.operator_xor(x);\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/set_xor_min\"\n\n#include\
    \ <iostream>\n\n#include \"../src/DataStructure/binary_trie.hpp\"\n#include \"\
    ../src/Utils/debug.hpp\"\n\nint main() {\n    int q;\n    std::cin >> q;\n\n \
    \   algorithm::BinaryTrie<30> trie;\n    while(q--) {\n        int t;\n      \
    \  int x;\n        std::cin >> t >> x;\n\n        if(t == 0) {\n            if(!trie.exist(x))\
    \ trie.insert(x);\n        } else if(t == 1) {\n            if(trie.exist(x))\
    \ trie.erase(x);\n        } else {\n            debug(trie);\n            trie.operator_xor(x);\n\
    \            debug(trie);\n            std::cout << trie.min_element().to_ulong()\
    \ << \"\\n\";\n            trie.operator_xor(x);\n        }\n    }\n}\n"
  dependsOn:
  - src/DataStructure/binary_trie.hpp
  - src/Utils/debug.hpp
  isVerificationFile: true
  path: test/yosupo-set_xor_min.test.cpp
  requiredBy: []
  timestamp: '2023-09-21 06:54:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo-set_xor_min.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo-set_xor_min.test.cpp
- /verify/test/yosupo-set_xor_min.test.cpp.html
title: test/yosupo-set_xor_min.test.cpp
---
