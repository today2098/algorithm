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
    - "https://naskya.net/post/0002/\uFF08\u53C2\u71672023.3.1\uFF09\uFF0E"
    - "https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb\uFF08\u53C2\u71672023.3.1\uFF09\
      \uFF0E"
    - "https://qiita.com/terukazu/items/e257c05a7b191d32c577\uFF08\u53C2\u71672023.3.1\uFF09\
      \uFF0E"
  bundledCode: "#line 1 \"src/Utils/debug.hpp\"\n\n\n\n#include <iostream>\n#include\
    \ <string>\n#include <type_traits>\n#include <utility>\n\nnamespace algorithm\
    \ {\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace debug {\n\nstruct has_iterator_impl\
    \ {\n    template <class T>\n    static std::true_type check(typename T::iterator\
    \ *);\n\n    template <class T>\n    static std::false_type check(...);\n};\n\n\
    template <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration\nvoid print(const std::string &s);\ntemplate\
    \ <typename T, typename U>\nvoid print(const std::pair<T, U> &p);\ntemplate <class\
    \ T, std::size_t... Idx>\nvoid print_tuple(const T &t, std::index_sequence<Idx...>);\n\
    template <typename... T>\nvoid print(const std::tuple<T...> &t);\ntemplate <typename\
    \ T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int l, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { std::cerr << s; }\n\ntemplate\
    \ <typename T, typename U>\nvoid print(const std::pair<T, U> &p) {\n    std::cerr\
    \ << \"{\";\n    print(p.first);\n    std::cerr << \", \";\n    print(p.second);\n\
    \    std::cerr << \"}\";\n}\n\ntemplate <class T, std::size_t... Idx>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idx...>) {\n    std::cerr << \"{\";\n    ((std::cerr\
    \ << (Idx == 0 ? \"\" : \", \"), print(std::get<Idx>(t))), ...);\n    std::cerr\
    \ << \"}\";\n}\n\ntemplate <typename... T>\nvoid print(const std::tuple<T...>\
    \ &t) {\n    print_tuple(t, std::make_index_sequence<sizeof...(T)>());\n}\n\n\
    template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>\n\
    void print(const T &v) {\n    std::cerr << \"[\";\n    for(auto itr = std::cbegin(v);\
    \ itr != std::cend(v); ++itr) {\n        if(itr != std::cbegin(v)) std::cerr <<\
    \ \" \";\n        print(*itr);\n    }\n    std::cerr << \"]\";\n}\n\ntemplate\
    \ <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>\n\
    void print(const T &elem) { std::cerr << elem; }\n\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int l, std::string_view context, T &&first, Args\
    \ &&...args) {\n    constexpr const char *open_bracket = (sizeof...(args) == 0\
    \ ? \"\" : \"(\");\n    constexpr const char *close_bracket = (sizeof...(args)\
    \ == 0 ? \"\" : \")\");\n    std::cerr << \"[L\" << l << \"] \" << open_bracket\
    \ << context << close_bracket << \": \" << open_bracket;\n    print(std::forward<T>(first));\n\
    \    ((std::cerr << \", \", print(std::forward<Args>(args))), ...);\n    std::cerr\
    \ << close_bracket << std::endl;\n}\n\n}  // namespace debug\n\n#else\n\n#define\
    \ debug(...) static_cast<void>(0)\n\n#endif\n\n}  // namespace algorithm\n\n\n\
    \n/*\n\u53C2\u8003\u6587\u732E\uFF1A\n- \u7AF6\u6280\u30D7\u30ED\u30B0\u30E9\u30DF\
    \u30F3\u30B0\u3067 print \u30C7\u30D0\u30C3\u30B0\uFF0Chttps://naskya.net/post/0002/\uFF08\
    \u53C2\u71672023.3.1\uFF09\uFF0E\n- EnumHack, C++\u30E1\u30BF\u95A2\u6570\u306E\
    \u307E\u3068\u3081\uFF0CQiita, https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb\uFF08\
    \u53C2\u71672023.3.1\uFF09\uFF0E\n- terukazu, \u7279\u5B9A\u306E\u30E1\u30F3\u30D0\
    \u95A2\u6570\u6709\u7121\u3067\u3001\u547C\u3073\u51FA\u3059\u95A2\u6570\u3092\
    \u5909\u3048\u305F\u3044\uFF0CQiita, https://qiita.com/terukazu/items/e257c05a7b191d32c577\uFF08\
    \u53C2\u71672023.3.1\uFF09\uFF0E\n*/\n"
  code: "#ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#include <iostream>\n\
    #include <string>\n#include <type_traits>\n#include <utility>\n\nnamespace algorithm\
    \ {\n\n// #define DEBUG\n\n#ifdef DEBUG\n\n#define debug(...) debug::debug_internal(__LINE__,\
    \ #__VA_ARGS__, __VA_ARGS__)\n\nnamespace debug {\n\nstruct has_iterator_impl\
    \ {\n    template <class T>\n    static std::true_type check(typename T::iterator\
    \ *);\n\n    template <class T>\n    static std::false_type check(...);\n};\n\n\
    template <class T>\nclass has_iterator : public decltype(has_iterator_impl::check<T>(nullptr))\
    \ {};\n\n// Prototype declaration\nvoid print(const std::string &s);\ntemplate\
    \ <typename T, typename U>\nvoid print(const std::pair<T, U> &p);\ntemplate <class\
    \ T, std::size_t... Idx>\nvoid print_tuple(const T &t, std::index_sequence<Idx...>);\n\
    template <typename... T>\nvoid print(const std::tuple<T...> &t);\ntemplate <typename\
    \ T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>\nvoid print(const\
    \ T &v);\ntemplate <typename T, typename std::enable_if_t<!has_iterator<T>::value,\
    \ bool> = false>\nvoid print(const T &elem);\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int l, std::string_view context, T &&first, Args\
    \ &&...args);\n\nvoid print(const std::string &s) { std::cerr << s; }\n\ntemplate\
    \ <typename T, typename U>\nvoid print(const std::pair<T, U> &p) {\n    std::cerr\
    \ << \"{\";\n    print(p.first);\n    std::cerr << \", \";\n    print(p.second);\n\
    \    std::cerr << \"}\";\n}\n\ntemplate <class T, std::size_t... Idx>\nvoid print_tuple(const\
    \ T &t, std::index_sequence<Idx...>) {\n    std::cerr << \"{\";\n    ((std::cerr\
    \ << (Idx == 0 ? \"\" : \", \"), print(std::get<Idx>(t))), ...);\n    std::cerr\
    \ << \"}\";\n}\n\ntemplate <typename... T>\nvoid print(const std::tuple<T...>\
    \ &t) {\n    print_tuple(t, std::make_index_sequence<sizeof...(T)>());\n}\n\n\
    template <class T, typename std::enable_if_t<has_iterator<T>::value, bool> = false>\n\
    void print(const T &v) {\n    std::cerr << \"[\";\n    for(auto itr = std::cbegin(v);\
    \ itr != std::cend(v); ++itr) {\n        if(itr != std::cbegin(v)) std::cerr <<\
    \ \" \";\n        print(*itr);\n    }\n    std::cerr << \"]\";\n}\n\ntemplate\
    \ <typename T, typename std::enable_if_t<!has_iterator<T>::value, bool> = false>\n\
    void print(const T &elem) { std::cerr << elem; }\n\ntemplate <typename T, typename...\
    \ Args>\nvoid debug_internal(int l, std::string_view context, T &&first, Args\
    \ &&...args) {\n    constexpr const char *open_bracket = (sizeof...(args) == 0\
    \ ? \"\" : \"(\");\n    constexpr const char *close_bracket = (sizeof...(args)\
    \ == 0 ? \"\" : \")\");\n    std::cerr << \"[L\" << l << \"] \" << open_bracket\
    \ << context << close_bracket << \": \" << open_bracket;\n    print(std::forward<T>(first));\n\
    \    ((std::cerr << \", \", print(std::forward<Args>(args))), ...);\n    std::cerr\
    \ << close_bracket << std::endl;\n}\n\n}  // namespace debug\n\n#else\n\n#define\
    \ debug(...) static_cast<void>(0)\n\n#endif\n\n}  // namespace algorithm\n\n#endif\n\
    \n/*\n\u53C2\u8003\u6587\u732E\uFF1A\n- \u7AF6\u6280\u30D7\u30ED\u30B0\u30E9\u30DF\
    \u30F3\u30B0\u3067 print \u30C7\u30D0\u30C3\u30B0\uFF0Chttps://naskya.net/post/0002/\uFF08\
    \u53C2\u71672023.3.1\uFF09\uFF0E\n- EnumHack, C++\u30E1\u30BF\u95A2\u6570\u306E\
    \u307E\u3068\u3081\uFF0CQiita, https://qiita.com/_EnumHack/items/ee2141ad47915c55d9cb\uFF08\
    \u53C2\u71672023.3.1\uFF09\uFF0E\n- terukazu, \u7279\u5B9A\u306E\u30E1\u30F3\u30D0\
    \u95A2\u6570\u6709\u7121\u3067\u3001\u547C\u3073\u51FA\u3059\u95A2\u6570\u3092\
    \u5909\u3048\u305F\u3044\uFF0CQiita, https://qiita.com/terukazu/items/e257c05a7b191d32c577\uFF08\
    \u53C2\u71672023.3.1\uFF09\uFF0E\n*/\n"
  dependsOn: []
  isVerificationFile: false
  path: src/Utils/debug.hpp
  requiredBy: []
  timestamp: '2023-08-19 16:15:46+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/Utils/debug.hpp
layout: document
redirect_from:
- /library/src/Utils/debug.hpp
- /library/src/Utils/debug.hpp.html
title: src/Utils/debug.hpp
---
