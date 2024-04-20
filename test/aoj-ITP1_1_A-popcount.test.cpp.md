---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Others/popcount.hpp
    title: Population Count (Popcount)
  - icon: ':heavy_check_mark:'
    path: src/Utils/debug.hpp
    title: "\u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A
  bundledCode: "#line 1 \"test/aoj-ITP1_1_A-popcount.test.cpp\"\n#define PROBLEM \"\
    https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n#include <cassert>\n#include\
    \ <iostream>\n#include <limits>\n#include <random>\n\n#line 1 \"src/Others/popcount.hpp\"\
    \n\n\n\n/**\n * @brief Population Count (Popcount)\n * @docs docs/Others/popcount.md\n\
    \ */\n\n#include <cstdint>\n\nnamespace algorithm {\n\nint popcount32(uint32_t\
    \ n) {\n    constexpr uint32_t masks[5] = {0x55555555U, 0x33333333U, 0x0f0f0f0fU,\
    \ 0x00ff00ffU, 0x0000ffffU};\n    for(int i = 0; i < 5; ++i) n = (n & masks[i])\
    \ + ((n >> (1 << i)) & masks[i]);\n    return n;\n}\n\nint popcount64(uint64_t\
    \ n) {\n    constexpr uint64_t masks[6] = {0x5555555555555555ULL, 0x3333333333333333ULL,\
    \ 0x0f0f0f0f0f0f0f0fULL,\n                                   0x00ff00ff00ff00ffULL,\
    \ 0x0000ffff0000ffffULL, 0x00000000ffffffffULL};\n    for(int i = 0; i < 6; ++i)\
    \ n = (n & masks[i]) + ((n >> (1 << i)) & masks[i]);\n    return n;\n}\n\n}  //\
    \ namespace algorithm\n\n\n#line 1 \"src/Utils/debug.hpp\"\n\n\n\n/**\n * @brief\
    \ \u30C7\u30D0\u30C3\u30B0\u7528\u95A2\u6570\u5F62\u5F0F\u30DE\u30AF\u30ED\n *\
    \ @docs docs/Utils/debug.md\n */\n\n#line 10 \"src/Utils/debug.hpp\"\n#include\
    \ <iterator>\n#include <queue>\n#include <stack>\n#include <string>\n#include\
    \ <string_view>\n#include <tuple>\n#include <type_traits>\n#include <utility>\n\
    \n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::cerr;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(std::string_view\
    \ s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T, U> &p);\n\
    template <class T, std::size_t... Idxes>\nvoid print_tuple(const T &t, std::index_sequence<Idxes...>);\n\
    template <typename... Ts>\nvoid print(const std::tuple<Ts...> &t);\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st);\ntemplate <typename... Ts>\nvoid\
    \ print(const std::queue<Ts...> &que);\ntemplate <typename... Ts>\nvoid print(const\
    \ std::priority_queue<Ts...> &pque);\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(std::string_view\
    \ s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p) {\n    os << \"{\";\n    print(p.first);\n    os << \", \";\n    print(p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <class T, std::size_t... Idxes>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idxes...>) {\n    os << \"{\";\n    ((os << (Idxes\
    \ == 0 ? \"\" : \", \"), print(std::get<Idxes>(t))), ...);\n    os << \"}\";\n\
    }\n\ntemplate <typename... Ts>\nvoid print(const std::tuple<Ts...> &t) {\n   \
    \ print_tuple(t, std::make_index_sequence<sizeof...(Ts)>());\n}\n\ntemplate <typename...\
    \ Ts>\nvoid print(const std::stack<Ts...> &st) {\n    std::stack<Ts...> tmp =\
    \ st;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <typename... Ts>\nvoid print(const std::queue<Ts...> &que)\
    \ {\n    std::queue<Ts...> tmp = que;\n    os << \"[\";\n    while(!tmp.empty())\
    \ {\n        print(tmp.front());\n        tmp.pop();\n        if(!tmp.empty())\
    \ os << \" \";\n    }\n    os << \"]\";\n}\n\ntemplate <typename... Ts>\nvoid\
    \ print(const std::priority_queue<Ts...> &pque) {\n    std::priority_queue<Ts...>\
    \ tmp = pque;\n    os << \"[\";\n    while(!tmp.empty()) {\n        print(tmp.top());\n\
    \        tmp.pop();\n        if(!tmp.empty()) os << \" \";\n    }\n    os << \"\
    ]\";\n}\n\ntemplate <class T, typename std::enable_if_t<has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &v) {\n    os << \"[\";\n    for(auto itr\
    \ = std::cbegin(v); itr != std::cend(v); ++itr) {\n        if(itr != std::cbegin(v))\
    \ os << \" \";\n        print(*itr);\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &elem) { os << elem; }\n\ntemplate <typename T, typename... Args>\nvoid debug_internal(int\
    \ line, std::string_view context, T &&first, Args &&...args) {\n    constexpr\
    \ const char *open_bracket = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr\
    \ const char *close_bracket = (sizeof...(args) == 0 ? \"\" : \")\");\n    os <<\
    \ \"[L\" << line << \"] \" << open_bracket << context << close_bracket << \":\
    \ \" << open_bracket;\n    print(std::forward<T>(first));\n    ((os << \", \"\
    , print(std::forward<Args>(args))), ...);\n    os << close_bracket << std::endl;\n\
    }\n\n}  // namespace debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...)\
    \ static_cast<void>(0)\n\n#endif\n\n\n#line 10 \"test/aoj-ITP1_1_A-popcount.test.cpp\"\
    \n\ntemplate <typename Type>\nint naive_popcount(Type n) {\n    int res = 0;\n\
    \    while(n) {\n        res++;\n        n &= n - 1;\n    }\n    return res;\n\
    }\n\nint main() {\n    std::random_device seed;\n    std::mt19937_64 rng(seed());\n\
    \n    for(int i = 0; i < 32; ++i) {\n        uint32_t target = 1U << i;\n    \
    \    debug(target);\n        assert(algorithm::popcount32(target) == naive_popcount(target));\n\
    \    }\n    assert(algorithm::popcount32(-1) == naive_popcount<uint32_t>(-1));\n\
    \n    std::uniform_int_distribution<int> uniform32(std::numeric_limits<int>::min(),\n\
    \                                                 std::numeric_limits<int>::max());\n\
    \    for(int i = 0; i < 100; ++i) {\n        int target = uniform32(rng);\n  \
    \      debug(i, target);\n        assert(algorithm::popcount32(target) == naive_popcount<uint32_t>(target));\n\
    \    }\n\n    for(int i = 0; i < 64; ++i) {\n        uint64_t target = 1ULL <<\
    \ i;\n        debug(target);\n        assert(algorithm::popcount64(target) ==\
    \ naive_popcount(target));\n    }\n    assert(algorithm::popcount64(-1LL) == naive_popcount<uint64_t>(-1LL));\n\
    \n    std::uniform_int_distribution<long long> uniform64(std::numeric_limits<long\
    \ long>::min(),\n                                                       std::numeric_limits<long\
    \ long>::max());\n    for(int i = 0; i < 100; ++i) {\n        long long target\
    \ = uniform64(rng);\n        debug(i, target);\n        assert(algorithm::popcount64(target)\
    \ == naive_popcount<uint64_t>(target));\n    }\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_1_A\"\n\n\
    #include <cassert>\n#include <iostream>\n#include <limits>\n#include <random>\n\
    \n#include \"../src/Others/popcount.hpp\"\n#include \"../src/Utils/debug.hpp\"\
    \n\ntemplate <typename Type>\nint naive_popcount(Type n) {\n    int res = 0;\n\
    \    while(n) {\n        res++;\n        n &= n - 1;\n    }\n    return res;\n\
    }\n\nint main() {\n    std::random_device seed;\n    std::mt19937_64 rng(seed());\n\
    \n    for(int i = 0; i < 32; ++i) {\n        uint32_t target = 1U << i;\n    \
    \    debug(target);\n        assert(algorithm::popcount32(target) == naive_popcount(target));\n\
    \    }\n    assert(algorithm::popcount32(-1) == naive_popcount<uint32_t>(-1));\n\
    \n    std::uniform_int_distribution<int> uniform32(std::numeric_limits<int>::min(),\n\
    \                                                 std::numeric_limits<int>::max());\n\
    \    for(int i = 0; i < 100; ++i) {\n        int target = uniform32(rng);\n  \
    \      debug(i, target);\n        assert(algorithm::popcount32(target) == naive_popcount<uint32_t>(target));\n\
    \    }\n\n    for(int i = 0; i < 64; ++i) {\n        uint64_t target = 1ULL <<\
    \ i;\n        debug(target);\n        assert(algorithm::popcount64(target) ==\
    \ naive_popcount(target));\n    }\n    assert(algorithm::popcount64(-1LL) == naive_popcount<uint64_t>(-1LL));\n\
    \n    std::uniform_int_distribution<long long> uniform64(std::numeric_limits<long\
    \ long>::min(),\n                                                       std::numeric_limits<long\
    \ long>::max());\n    for(int i = 0; i < 100; ++i) {\n        long long target\
    \ = uniform64(rng);\n        debug(i, target);\n        assert(algorithm::popcount64(target)\
    \ == naive_popcount<uint64_t>(target));\n    }\n\n    std::cout << \"Hello World\"\
    \ << std::endl;\n}\n"
  dependsOn:
  - src/Others/popcount.hpp
  - src/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-ITP1_1_A-popcount.test.cpp
  requiredBy: []
  timestamp: '2024-04-20 09:48:49+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-ITP1_1_A-popcount.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-ITP1_1_A-popcount.test.cpp
- /verify/test/aoj-ITP1_1_A-popcount.test.cpp.html
title: test/aoj-ITP1_1_A-popcount.test.cpp
---
