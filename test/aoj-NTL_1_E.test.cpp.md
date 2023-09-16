---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/Math/NumberTheory/extgcd.hpp
    title: "\u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5"
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E
  bundledCode: "#line 1 \"test/aoj-NTL_1_E.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n\n#include <iostream>\n\n#line 1 \"src/Math/NumberTheory/extgcd.hpp\"\n\n\n\n\
    /**\n * @brief \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\
    \u6CD5\n * @docs docs/Math/NumberTheory/extgcd.md\n */\n\nnamespace algorithm\
    \ {\n\n// \u62E1\u5F35\u30E6\u30FC\u30AF\u30EA\u30C3\u30C9\u306E\u4E92\u9664\u6CD5\
    \uFF0E\n// ax+by=gcd(a,b) \u3092\u6E80\u305F\u3059\u6574\u6570\u306E\u7D44(x,y)\u3092\
    \u6C42\u3081\uFF0Cgcd(a,b)\u3092\u8FD4\u3059\uFF0EO(logN).\ntemplate <typename\
    \ Type>\nType extgcd(Type a, Type b, Type &x, Type &y) {\n    if(b == 0) {\n \
    \       x = 1, y = 0;\n        return a;\n    }\n    Type d = extgcd(b, a % b,\
    \ y, x);\n    y -= a / b * x;\n    return d;\n}\n\n}  // namespace algorithm\n\
    \n\n#line 1 \"src/Utils/debug.hpp\"\n/**\n * @docs docs/Utils/debug.md\n */\n\n\
    #ifndef ALGORITHM_DEBUG_HPP\n#define ALGORITHM_DEBUG_HPP 1\n\n#line 9 \"src/Utils/debug.hpp\"\
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
    \ static_cast<void>(0)\n\n#endif\n\n#endif\n#line 7 \"test/aoj-NTL_1_E.test.cpp\"\
    \n\nint main() {\n    int a, b;\n    std::cin >> a >> b;\n\n    int x, y;\n  \
    \  algorithm::extgcd(a, b, x, y);\n    debug(a * x + b * y);\n\n    std::cout\
    \ << x << \" \" << y << std::endl;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/all/NTL_1_E\"\
    \n\n#include <iostream>\n\n#include \"../src/Math/NumberTheory/extgcd.hpp\"\n\
    #include \"../src/Utils/debug.hpp\"\n\nint main() {\n    int a, b;\n    std::cin\
    \ >> a >> b;\n\n    int x, y;\n    algorithm::extgcd(a, b, x, y);\n    debug(a\
    \ * x + b * y);\n\n    std::cout << x << \" \" << y << std::endl;\n}\n"
  dependsOn:
  - src/Math/NumberTheory/extgcd.hpp
  - src/Utils/debug.hpp
  isVerificationFile: true
  path: test/aoj-NTL_1_E.test.cpp
  requiredBy: []
  timestamp: '2023-09-16 12:49:54+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj-NTL_1_E.test.cpp
layout: document
redirect_from:
- /verify/test/aoj-NTL_1_E.test.cpp
- /verify/test/aoj-NTL_1_E.test.cpp.html
title: test/aoj-NTL_1_E.test.cpp
---
