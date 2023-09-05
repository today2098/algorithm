---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj-3110.test.cpp
    title: test/aoj-3110.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/Utils/debug.md
    links: []
  bundledCode: "#line 1 \"src/Utils/debug.hpp\"\n/**\n * @docs docs/Utils/debug.md\n\
    \ */\n\n#ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#include\
    \ <iostream>\n#include <iterator>\n#include <queue>\n#include <stack>\n#include\
    \ <string>\n#include <string_view>\n#include <tuple>\n#include <type_traits>\n\
    #include <utility>\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::cerr;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(const\
    \ std::string_view &s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p);\ntemplate <class T, std::size_t... Idx>\nvoid print_tuple(const T &t,\
    \ std::index_sequence<Idx...>);\ntemplate <typename... T>\nvoid print(const std::tuple<T...>\
    \ &t);\ntemplate <typename... T>\nvoid print(const std::stack<T...> &st);\ntemplate\
    \ <typename... T>\nvoid print(const std::queue<T...> &que);\ntemplate <typename...\
    \ T>\nvoid print(const std::priority_queue<T...> &pque);\ntemplate <typename T,\
    \ typename std::enable_if_t<has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(const\
    \ std::string_view &s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid\
    \ print(const std::pair<T, U> &p) {\n    os << \"{\";\n    print(p.first);\n \
    \   os << \", \";\n    print(p.second);\n    os << \"}\";\n}\n\ntemplate <class\
    \ T, std::size_t... Idx>\nvoid print_tuple(const T &t, std::index_sequence<Idx...>)\
    \ {\n    os << \"{\";\n    ((os << (Idx == 0 ? \"\" : \", \"), print(std::get<Idx>(t))),\
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
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n"
  code: "/**\n * @docs docs/Utils/debug.md\n */\n\n#ifndef ALGORITHM_DEBUG_HPP\n#define\
    \ ALGORITHM_DEBUG_HPP 1\n\n#include <iostream>\n#include <iterator>\n#include\
    \ <queue>\n#include <stack>\n#include <string>\n#include <string_view>\n#include\
    \ <tuple>\n#include <type_traits>\n#include <utility>\n\n// #define DEBUG\n\n\
    #ifdef DEBUG\n\n#define debug(...) algorithm::debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace algorithm {\n\nnamespace debug {\n\n\
    constexpr std::ostream &os = std::cerr;\n\nstruct has_iterator_impl {\n    template\
    \ <class T>\n    static constexpr std::true_type check(typename T::iterator *);\n\
    \n    template <class T>\n    static constexpr std::false_type check(...);\n};\n\
    \ntemplate <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration.\nvoid print(const std::string &s);\nvoid print(const\
    \ std::string_view &s);\ntemplate <typename T, typename U>\nvoid print(const std::pair<T,\
    \ U> &p);\ntemplate <class T, std::size_t... Idx>\nvoid print_tuple(const T &t,\
    \ std::index_sequence<Idx...>);\ntemplate <typename... T>\nvoid print(const std::tuple<T...>\
    \ &t);\ntemplate <typename... T>\nvoid print(const std::stack<T...> &st);\ntemplate\
    \ <typename... T>\nvoid print(const std::queue<T...> &que);\ntemplate <typename...\
    \ T>\nvoid print(const std::priority_queue<T...> &pque);\ntemplate <typename T,\
    \ typename std::enable_if_t<has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int line, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { os << s; }\n\nvoid print(const\
    \ std::string_view &s) { os << s; }\n\ntemplate <typename T, typename U>\nvoid\
    \ print(const std::pair<T, U> &p) {\n    os << \"{\";\n    print(p.first);\n \
    \   os << \", \";\n    print(p.second);\n    os << \"}\";\n}\n\ntemplate <class\
    \ T, std::size_t... Idx>\nvoid print_tuple(const T &t, std::index_sequence<Idx...>)\
    \ {\n    os << \"{\";\n    ((os << (Idx == 0 ? \"\" : \", \"), print(std::get<Idx>(t))),\
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
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Utils/debug.hpp
  requiredBy: []
  timestamp: '2023-09-05 19:21:40+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj-3110.test.cpp
documentation_of: src/Utils/debug.hpp
layout: document
redirect_from:
- /library/src/Utils/debug.hpp
- /library/src/Utils/debug.hpp.html
title: src/Utils/debug.hpp
---
## 概要

ローカル環境のみで実行される debug マクロ関数．
引数にある変数，オブジェクトを標準エラー出力 (`std::cerr`) に出力する．

対応している変数，オブジェクトは次の通り．

- スカラー型の変数
- 出力演算子が定義されているクラスのオブジェクト
- iterator が実装されているクラス（STL のコンテナクラスなど）のオブジェクト
- `std::string`, `std::string_view`, `std::pair`, `std::tuple`, `std::stack`, `std::queue`, `std::priority_queue`

使用する際は，コンパイル時に「`-D=DEBUG`」と指定する．

使用例は次の通り．
変数名とその値，行番号を対応させて出力する．
また可変長引数にも対応している．

```main.cpp
int a = 0;
double b = 3.14;
std::string s = "Hello, world!";
std::pair<int, double> p({1, 1.41});
std::vector<int> v({1, 1, 2, 3, 5});

debug(a, b, s);
debug(p);
debug(v);
`````

```bash
$ g++ main.cpp -std=c++17 -D=DEBUG -o debug.out
$ ./debug
[L50] (a, b, s): (0, 3.14, Hello, world!)
[L51] p: {1, 1.41}
[L52] v: [1 1 2 3 5]
``````


## 参考文献

- "SFINAE". Wikipedia. <https://ja.wikipedia.org/wiki/SFINAE>.
- _EnumHack. "C++メタ関数のまとめ". Qiita. <https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb>.
- terukazu. "特定のメンバ関数有無で、呼び出す関数を変えたい". Qiita. <https://qiita.com/terukazu/items/e257c05a7b191d32c577>.
- "競技プログラミングで print デバッグ". <https://naskya.net/post/0002/>.
- rsk0315_h4x. X (Twitter). <https://twitter.com/rsk0315_h4x/status/1522810205029167105>.
- raclamusi. X (Twitter). <https://twitter.com/raclamusi/status/1522862497463631872>.
