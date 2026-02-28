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
  bundledCode: "#line 1 \"algorithm/utils/debug.hpp\"\n\n\n\n#include <chrono>\n#include\
    \ <concepts>\n#include <initializer_list>\n#include <iomanip>\n#include <iostream>\n\
    #include <queue>\n#include <ranges>\n#include <stack>\n#include <string>\n#include\
    \ <string_view>\n#include <tuple>\n#include <utility>\n\n#ifdef DEBUG\n\n#define\
    \ debug(...) algorithm::debug::debug_internal(std::clog, __LINE__ __VA_OPT__(,\
    \ #__VA_ARGS__, __VA_ARGS__))\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    // Forward declaration.\n\ntemplate <typename C, typename Tr, typename Type>\n\
    void print(std::basic_ostream<C, Tr> &, const Type &);\n\ntemplate <typename C,\
    \ typename Tr, std::ranges::input_range R>\n    requires(!std::convertible_to<R,\
    \ const char *>)\nvoid print(std::basic_ostream<C, Tr> &, const R &);\n\ntemplate\
    \ <typename C, typename Tr>\nvoid print(std::basic_ostream<C, Tr> &, const char\
    \ *);\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, const std::basic_string<Types...> &);\n\ntemplate <typename C, typename\
    \ Tr, typename... Types>\nvoid print(std::basic_ostream<C, Tr> &, std::basic_string_view<Types...>);\n\
    \ntemplate <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, std::stack<Types...>);\n\ntemplate <typename C, typename Tr, typename...\
    \ Types>\nvoid print(std::basic_ostream<C, Tr> &, std::queue<Types...>);\n\ntemplate\
    \ <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, std::priority_queue<Types...>);\n\ntemplate <typename C, typename Tr,\
    \ typename T, typename U>\nvoid print(std::basic_ostream<C, Tr> &, const std::pair<T,\
    \ U> &);\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, const std::tuple<Types...> &);\n\ntemplate <typename C, typename Tr,\
    \ typename... Types, std::size_t... Idxes>\nvoid print_tuple(std::basic_ostream<C,\
    \ Tr> &, const std::tuple<Types...> &, std::index_sequence<Idxes...>);\n\ntemplate\
    \ <typename C, typename Tr, typename Type>\nvoid print(std::basic_ostream<C, Tr>\
    \ &, const std::initializer_list<Type> &);\n\n// Implementation.\n\nauto elapsed()\
    \ {\n    static const auto start = std::chrono::system_clock::now();\n    return\
    \ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()\
    \ - start).count();\n}\n\ntemplate <typename C, typename Tr, typename Type, typename...\
    \ Args>\nvoid debug_internal(std::basic_ostream<C, Tr> &os, int line, std::string_view\
    \ context, Type &&first, Args &&...args) {\n    constexpr const char *open_bracket\
    \ = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr const char *close_bracket\
    \ = (sizeof...(args) == 0 ? \"\" : \")\");\n    os << \"(\" << std::setw(8) <<\
    \ elapsed() << \") [L\" << line << \"] \" << open_bracket << context << close_bracket\
    \ << \": \" << open_bracket;\n    print(os, std::forward<Type>(first));\n    ((os\
    \ << \", \", print(os, std::forward<Args>(args))), ...);\n    os << close_bracket\
    \ << std::endl;\n}\n\ntemplate <typename C, typename Tr>\nvoid debug_internal(std::basic_ostream<C,\
    \ Tr> &os, int line) {\n    os << \"(\" << std::setw(8) << elapsed() << \") [L\"\
    \ << line << \"] (empty)\" << std::endl;\n}\n\ntemplate <typename C, typename\
    \ Tr, typename Type>\nvoid print(std::basic_ostream<C, Tr> &os, const Type &a)\
    \ {\n    os << a;\n}\n\ntemplate <typename C, typename Tr, std::ranges::input_range\
    \ R>\n    requires(!std::convertible_to<R, const char *>)\nvoid print(std::basic_ostream<C,\
    \ Tr> &os, const R &r) {\n    os << \"[\";\n    auto iter = std::ranges::cbegin(r);\n\
    \    const auto end = std::ranges::cend(r);\n    if(iter != end) {\n        print(os,\
    \ *iter++);\n        while(iter != end) {\n            os << \" \";\n        \
    \    print(os, *iter++);\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ C, typename Tr>\nvoid print(std::basic_ostream<C, Tr> &os, const char *s) {\n\
    \    os << s;\n}\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, const std::basic_string<Types...> &s) {\n\
    \    os << s;\n}\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, std::basic_string_view<Types...> sv) {\n\
    \    os << sv;\n}\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, std::stack<Types...> st) {\n    os << \"\
    [\";\n    if(!st.empty()) {\n        print(os, st.top());\n        st.pop();\n\
    \        for(; !st.empty(); st.pop()) {\n            os << \" \";\n          \
    \  print(os, st.top());\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C, Tr> &os,\
    \ std::queue<Types...> que) {\n    os << \"[\";\n    if(!que.empty()) {\n    \
    \    print(os, que.front());\n        que.pop();\n        for(; !que.empty();\
    \ que.pop()) {\n            os << \" \";\n            print(os, que.front());\n\
    \        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename C, typename Tr, typename...\
    \ Types>\nvoid print(std::basic_ostream<C, Tr> &os, std::priority_queue<Types...>\
    \ pque) {\n    os << \"[\";\n    if(!pque.empty()) {\n        print(os, pque.top());\n\
    \        pque.pop();\n        for(; !pque.empty(); pque.pop()) {\n           \
    \ os << \" \";\n            print(os, pque.top());\n        }\n    }\n    os <<\
    \ \"]\";\n}\n\ntemplate <typename C, typename Tr, typename T, typename U>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, const std::pair<T, U> &p) {\n    os <<\
    \ \"{\";\n    print(os, p.first);\n    os << \", \";\n    print(os, p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <typename C, typename Tr, typename... Types>\n\
    void print(std::basic_ostream<C, Tr> &os, const std::tuple<Types...> &t) {\n \
    \   print_tuple(os, t, std::make_index_sequence<sizeof...(Types)>());\n}\n\ntemplate\
    \ <typename C, typename Tr, typename... Types, std::size_t... Idxes>\nvoid print_tuple(std::basic_ostream<C,\
    \ Tr> &os, const std::tuple<Types...> &t, std::index_sequence<Idxes...>) {\n \
    \   os << \"{\";\n    ((os << (Idxes == 0 ? \"\" : \", \"), print(os, std::get<Idxes>(t))),\
    \ ...);\n    os << \"}\";\n}\n\ntemplate <typename C, typename Tr, typename Type>\n\
    void print(std::basic_ostream<C, Tr> &os, const std::initializer_list<Type> &il)\
    \ {\n    print(os, std::ranges::subrange(il.begin(), il.end()));\n}\n\n}  // namespace\
    \ debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...) static_cast<void>(0)\n\
    \n#endif\n\n\n"
  code: "#ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#include <chrono>\n\
    #include <concepts>\n#include <initializer_list>\n#include <iomanip>\n#include\
    \ <iostream>\n#include <queue>\n#include <ranges>\n#include <stack>\n#include\
    \ <string>\n#include <string_view>\n#include <tuple>\n#include <utility>\n\n#ifdef\
    \ DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(std::clog, __LINE__\
    \ __VA_OPT__(, #__VA_ARGS__, __VA_ARGS__))\n\nnamespace algorithm {\n\nnamespace\
    \ debug {\n\n// Forward declaration.\n\ntemplate <typename C, typename Tr, typename\
    \ Type>\nvoid print(std::basic_ostream<C, Tr> &, const Type &);\n\ntemplate <typename\
    \ C, typename Tr, std::ranges::input_range R>\n    requires(!std::convertible_to<R,\
    \ const char *>)\nvoid print(std::basic_ostream<C, Tr> &, const R &);\n\ntemplate\
    \ <typename C, typename Tr>\nvoid print(std::basic_ostream<C, Tr> &, const char\
    \ *);\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, const std::basic_string<Types...> &);\n\ntemplate <typename C, typename\
    \ Tr, typename... Types>\nvoid print(std::basic_ostream<C, Tr> &, std::basic_string_view<Types...>);\n\
    \ntemplate <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, std::stack<Types...>);\n\ntemplate <typename C, typename Tr, typename...\
    \ Types>\nvoid print(std::basic_ostream<C, Tr> &, std::queue<Types...>);\n\ntemplate\
    \ <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, std::priority_queue<Types...>);\n\ntemplate <typename C, typename Tr,\
    \ typename T, typename U>\nvoid print(std::basic_ostream<C, Tr> &, const std::pair<T,\
    \ U> &);\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C,\
    \ Tr> &, const std::tuple<Types...> &);\n\ntemplate <typename C, typename Tr,\
    \ typename... Types, std::size_t... Idxes>\nvoid print_tuple(std::basic_ostream<C,\
    \ Tr> &, const std::tuple<Types...> &, std::index_sequence<Idxes...>);\n\ntemplate\
    \ <typename C, typename Tr, typename Type>\nvoid print(std::basic_ostream<C, Tr>\
    \ &, const std::initializer_list<Type> &);\n\n// Implementation.\n\nauto elapsed()\
    \ {\n    static const auto start = std::chrono::system_clock::now();\n    return\
    \ std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now()\
    \ - start).count();\n}\n\ntemplate <typename C, typename Tr, typename Type, typename...\
    \ Args>\nvoid debug_internal(std::basic_ostream<C, Tr> &os, int line, std::string_view\
    \ context, Type &&first, Args &&...args) {\n    constexpr const char *open_bracket\
    \ = (sizeof...(args) == 0 ? \"\" : \"(\");\n    constexpr const char *close_bracket\
    \ = (sizeof...(args) == 0 ? \"\" : \")\");\n    os << \"(\" << std::setw(8) <<\
    \ elapsed() << \") [L\" << line << \"] \" << open_bracket << context << close_bracket\
    \ << \": \" << open_bracket;\n    print(os, std::forward<Type>(first));\n    ((os\
    \ << \", \", print(os, std::forward<Args>(args))), ...);\n    os << close_bracket\
    \ << std::endl;\n}\n\ntemplate <typename C, typename Tr>\nvoid debug_internal(std::basic_ostream<C,\
    \ Tr> &os, int line) {\n    os << \"(\" << std::setw(8) << elapsed() << \") [L\"\
    \ << line << \"] (empty)\" << std::endl;\n}\n\ntemplate <typename C, typename\
    \ Tr, typename Type>\nvoid print(std::basic_ostream<C, Tr> &os, const Type &a)\
    \ {\n    os << a;\n}\n\ntemplate <typename C, typename Tr, std::ranges::input_range\
    \ R>\n    requires(!std::convertible_to<R, const char *>)\nvoid print(std::basic_ostream<C,\
    \ Tr> &os, const R &r) {\n    os << \"[\";\n    auto iter = std::ranges::cbegin(r);\n\
    \    const auto end = std::ranges::cend(r);\n    if(iter != end) {\n        print(os,\
    \ *iter++);\n        while(iter != end) {\n            os << \" \";\n        \
    \    print(os, *iter++);\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ C, typename Tr>\nvoid print(std::basic_ostream<C, Tr> &os, const char *s) {\n\
    \    os << s;\n}\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, const std::basic_string<Types...> &s) {\n\
    \    os << s;\n}\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, std::basic_string_view<Types...> sv) {\n\
    \    os << sv;\n}\n\ntemplate <typename C, typename Tr, typename... Types>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, std::stack<Types...> st) {\n    os << \"\
    [\";\n    if(!st.empty()) {\n        print(os, st.top());\n        st.pop();\n\
    \        for(; !st.empty(); st.pop()) {\n            os << \" \";\n          \
    \  print(os, st.top());\n        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename\
    \ C, typename Tr, typename... Types>\nvoid print(std::basic_ostream<C, Tr> &os,\
    \ std::queue<Types...> que) {\n    os << \"[\";\n    if(!que.empty()) {\n    \
    \    print(os, que.front());\n        que.pop();\n        for(; !que.empty();\
    \ que.pop()) {\n            os << \" \";\n            print(os, que.front());\n\
    \        }\n    }\n    os << \"]\";\n}\n\ntemplate <typename C, typename Tr, typename...\
    \ Types>\nvoid print(std::basic_ostream<C, Tr> &os, std::priority_queue<Types...>\
    \ pque) {\n    os << \"[\";\n    if(!pque.empty()) {\n        print(os, pque.top());\n\
    \        pque.pop();\n        for(; !pque.empty(); pque.pop()) {\n           \
    \ os << \" \";\n            print(os, pque.top());\n        }\n    }\n    os <<\
    \ \"]\";\n}\n\ntemplate <typename C, typename Tr, typename T, typename U>\nvoid\
    \ print(std::basic_ostream<C, Tr> &os, const std::pair<T, U> &p) {\n    os <<\
    \ \"{\";\n    print(os, p.first);\n    os << \", \";\n    print(os, p.second);\n\
    \    os << \"}\";\n}\n\ntemplate <typename C, typename Tr, typename... Types>\n\
    void print(std::basic_ostream<C, Tr> &os, const std::tuple<Types...> &t) {\n \
    \   print_tuple(os, t, std::make_index_sequence<sizeof...(Types)>());\n}\n\ntemplate\
    \ <typename C, typename Tr, typename... Types, std::size_t... Idxes>\nvoid print_tuple(std::basic_ostream<C,\
    \ Tr> &os, const std::tuple<Types...> &t, std::index_sequence<Idxes...>) {\n \
    \   os << \"{\";\n    ((os << (Idxes == 0 ? \"\" : \", \"), print(os, std::get<Idxes>(t))),\
    \ ...);\n    os << \"}\";\n}\n\ntemplate <typename C, typename Tr, typename Type>\n\
    void print(std::basic_ostream<C, Tr> &os, const std::initializer_list<Type> &il)\
    \ {\n    print(os, std::ranges::subrange(il.begin(), il.end()));\n}\n\n}  // namespace\
    \ debug\n\n}  // namespace algorithm\n\n#else\n\n#define debug(...) static_cast<void>(0)\n\
    \n#endif\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/utils/debug.hpp
  requiredBy: []
  timestamp: '2026-02-28 07:31:45+00:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: algorithm/utils/debug.hpp
layout: document
title: "\u30C7\u30D0\u30C3\u30B0\u30DE\u30AF\u30ED"
---


## 概要

ローカル環境でのみ実行されるデバッグ用の関数形式マクロ．

引数にある値を，経過時間（マイクロ秒）と行番号，引数名と共に，標準エラー出力 (`std::clog`) に出力する．
可変長引数に対応しており，複数の値を同時に出力することができる．

引数として使用できるものは次の通り．

- リテラル値
- スカラー型の変数
- `std::string`, `std::string_view`, `std::stack`, `std::queue`, `std::priority_queue`, `std::pair`, `std::tuple` のオブジェクト
- `std::ranges::input_range` のコンセプトを満たすオブジェクト（STL のコンテナクラスなど）
- 出力演算子が定義されているクラスのオブジェクト

使用する際は，コンパイル時に「`-D=DEBUG`」とオプション指定する．

### 使用例

```cpp
int a = 0;
double b = 3.14;
std::string s = "Hello, world!";
std::pair<int, double> p({1, 1.41});
std::vector<int> v({1, 1, 2, 3, 5});

debug('i', -1LL);
debug(a, b);
debug(s);
debug(p);
debug(v);
debug();
```

```bash
$ g++ -D=DEBUG -std=gnu++23 main.cpp -o debug.out
$ ./debug.out
(       0) [L52] ('i', -1LL): (i, -1)
(      33) [L53] (a, b): (0, 3.14)
(      67) [L54] s: Hello, world!
(      83) [L55] p: {1, 1.41}
(     151) [L56] v: [1 1 2 3 5]
(     160) [L57] (empty)
```

## 参考

1. "SFINAE". Wikipedia. <https://ja.wikipedia.org/wiki/SFINAE>.
1. "任意の式によるSFINAE [N2634]". cpprefjp. <https://cpprefjp.github.io/index.html>.
1. _EnumHack. "C++メタ関数のまとめ". Qiita. <https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb>.
1. terukazu. "特定のメンバ関数有無で、呼び出す関数を変えたい". Qiita. <https://qiita.com/terukazu/items/e257c05a7b191d32c577>.
1. "競技プログラミングで print デバッグ". <https://naskya.net/post/0002/>.
1. rsk0315_h4x. X (Twitter). <https://twitter.com/rsk0315_h4x/status/1522810205029167105>.
1. raclamusi. X (Twitter). <https://twitter.com/raclamusi/status/1522862497463631872>.
